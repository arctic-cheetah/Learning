//Make a program to send COVID data to your phone every day
const accountSid = process.env.TWILIO_ACCOUNT_SID;
const authToken = process.env.TWILIO_AUTH_TOKEN;
const sender_num = "+17028723457";
const receiver_num = "+61470130392";
const client = require('twilio')("AC4eb6d26fbccd8172be97d1fbff63ed3b", "94c7a82a5b1e3349d0c63b36abc89f74");

const http = require("http");
//Use local host
const host = "127.0.0.1";
//Port 3000 is vacant
const port = 3000;
const INTERVAL = 5*60*1000//24*60*60*1000;//Interval is every day


let fetch = require("node-fetch");
const requestOptions = {
    method : "GET",
    redirect : "follow"
}
//Get the current date
let curr_date = new Date();

////////////////////////////////////////
//Function definitions
function send_data(res) {
    res.statusCode = 200;
    res.setHeader("Content-Type", "text/plain");
    res.end("Toysky!" + Date.now);
}


//Send an sms
function send_sms(covid_data) {
    client.messages
    .create({
        body: covid_data,
        from: sender_num,
        to: receiver_num
    })
    .then(message => console.log(message.sid));
}

//Process COVID data
//And return the number of new cases in each state 

//WARNING!
//This api can release a bug if the data is fetched during 12AM - 6AM. 
//Since we assume that the data for today is ready, the API will only return the cases from yesterday.
//We should take care on the usage of this data
let url = `https://api.covid19api.com/live/country/australia/status/confirmed/date/${curr_date.getFullYear()}-${curr_date.getMonth() + 1}-${curr_date.getDate() - 3}`;

//Store the states in an array
const states = ["South Australia", "Victoria", "Australian Capital Territory", "Tasmania", "Queensland", "Western Australia", "Northern Territory", "New South Wales"];

function sort_data(data) {
    let json_data = JSON.parse(data);
    //console.log(json_data);
    //Find the new cases for the current day by subtracting today's cases from yesterday's
    let case_today = states.map(state => {
        //Remember to compare lowercase
        let curr_state = json_data.filter(curr_data => curr_data.Province == state);
        //console.log(curr_state);
        //ES5 way of creating an object with a key that is a variable
        //let obj = {}
        //obj[state] = curr_state[1].Confirmed - curr_state[0].Confirmed

        //ES6 way of creating an object with a key that is a variable
        return {[state] : curr_state[1].Confirmed - curr_state[0].Confirmed};
    });
    
    //Categorise data into states
    //Add the date
    case_today.unshift("Cases during: " + String(curr_date));
    //console.log(case_today);
    //Need to Stringify the data
    case_today.unshift("Covid cases during: " + String(curr_date) + ":");
    let formatted_data = JSON.stringify(case_today).replace(/["{}\[\]]+/g, " ");
    send_sms(formatted_data);
}
let fetch_covid_data = () => {
    return fetch(url, requestOptions)
    .then(response => response.text())
    .then(result => sort_data(result))
    .catch(error => console.log(error));
}


////////////////////////////////////////////////

//Test 1: Send an data every 5 minutes

//Test 2:

//Initialise the server
const server = http.createServer((req, res) => {
    send_data(res);
});
//Listen for clients
server.listen(port, host, () => {
    console.log("Server initialised!");
    fetch_covid_data();
    console.log("Data sent!");
});

setInterval(() => {
    fetch_covid_data();
    console.log("Data sent!");
}, INTERVAL);


