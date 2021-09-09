//Make a program to send COVID data to your phone every day
const accountSid = process.env.TWILIO_ACCOUNT_SID;
const authToken = process.env.TWILIO_AUTH_TOKEN;
const sender_num = "+17028723457";
const receiver_num = "";
// const client = require("twilio")(
//   "",
//   ""
// );
const yesterday_offset = 1000*60*60*24 //milliseconds,secs,mins,day

const http = require("http");
//Use local host
const host = "127.0.0.1";
//Port 3000 is vacant
const port = 3000;

let fetch = require("node-fetch");
const requestOptions = {
  method: "GET",
  redirect: "follow",
};

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
      to: receiver_num,
    })
    .then((message) => console.log(message.sid));
}

//Process COVID data
//And return the number of new cases in each state

//WARNING!
//This api can release a bug if the data is fetched during 12AM - 6AM.
//Since we assume that the data for today is ready, the API will only return the cases from yesterday.
//We should take care on the usage of this data

//BUG, If we fetch data at the beginning of the month, then getDate() - 2 will be negative!

//Store the states in an array
const states = [
  "South Australia",
  "Victoria",
  "Australian Capital Territory",
  "Tasmania",
  "Queensland",
  "Western Australia",
  "Northern Territory",
  "New South Wales",
];

function sort_data(today_data, date) {

  let json_data = JSON.parse(today_data);
  //Find the new cases for the current day by subtracting today's cases from yesterday's
  let case_today = states.map((state) => {
    //Remember to compare lowercase
    let curr_state = json_data.filter(
      (curr_data) => curr_data.Province == state
    );
    //console.log(curr_state);
    //ES5 way of creating an object with a key that is a variable
    //let obj = {}
    //obj[state] = curr_state[1].Confirmed - curr_state[0].Confirmed

    //ES6 way of creating an object with a key that is a variable
    return { [state]: curr_state[1].Confirmed - curr_state[0].Confirmed };
  });


  //Categorise data into states
  //Add the date
  case_today.unshift("Cases during: " + String(date));
  //console.log(case_today);
  //Need to Stringify the data
  case_today.unshift("Covid cases during: " + String(date) + ":");
  let formatted_data = JSON.stringify(case_today).replace(/["{}\[\]]+/g, " ");
  console.log(formatted_data);
  send_sms(formatted_data);
}
let fetch_covid_data = () => {
  //Get the current date in ms

  //If data requires fetching from last month, two API calls are needed

  //Need to fetch today's and yesterday's data
  let curr_date = Date.now() - yesterday_offset;
  //we are guaranteed to get
  let yester_date = curr_date - 2*yesterday_offset;

  curr_date = new Date(curr_date);
  yester_date = new Date(yester_date);

  let url = `https://api.covid19api.com/live/country/australia?from=${yester_date.getFullYear()}-${yester_date.getMonth() + 1}-${yester_date.getDate()}T00:00:00Z&to=${curr_date.getFullYear()}-${curr_date.getMonth() + 1}-${curr_date.getDate()}T00:00:00Z`;
  //Must save data somewhere
  console.log(url);
  fetch(url, requestOptions)
    .then(response => response.text()) 
    .then(result => {sort_data(result, curr_date)})
    .catch(error => console.log(error))
  //do error checking
};

////////////////////////////////////////////////

//Test 1: Send an data every 5 minutes

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

