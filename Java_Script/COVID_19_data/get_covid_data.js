let fetch = require("node-fetch");
const requestOptions = {
    method : "GET",
    redirect : "follow"
}
//Get the current date
let curr_date = new Date();

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
    case_today.unshift("Cases during: " + String(curr_date) + "\n");
    let formatted_data = JSON.stringify(case_today).replace(/["{}\[\]]+/g, " ");
    console.log(formatted_data);
}
let fetch_covid_data = () => {
    return fetch(url, requestOptions)
    .then(response => response.text())
    .then(result => sort_data(result))
    .catch(error => console.log(error));
}

fetch_covid_data();

