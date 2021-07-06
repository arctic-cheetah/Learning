const months = [
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December",
];
const weekdays = [
  "Sunday",
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday",
];

const giveaway = document.querySelector(".giveaway");
const deadline = document.querySelector(".deadline");
const item_time = document.querySelectorAll(".deadline-format h4");

//Change the giveaway date
//Set the giveway date here:
let futureDate = new Date(2021, 7, 6, 21, 0, 0);

const year = futureDate.getFullYear();
const mins = pad_leading_zero(futureDate.getMinutes());
const hrs = pad_leading_zero(futureDate.getHours());
const date = pad_leading_zero(futureDate.getDate());

const month = months[futureDate.getMonth()];
const day = weekdays[futureDate.getDay()];

//Format the minutes or hours with leading zeros
//if less than 10
function pad_leading_zero(num) {
  if (num < 10) {
    return String('0' + num);
  }
  return num;
}

//Set giveaway date
giveaway.innerText = `giveaway ends on ${hrs}:${mins} ${day},
${date} ${month} ${year}`
const futureTime = futureDate.getTime();


// //My solution
// //Calculate the future time
// //Future time in ms
// setInterval(() => {
//   const calc_time = futureTime - Date.now();

//   //Calculate the count down time
//   //1s = 1000ms
//   //1min = 60s
//   //1hr = 60min
//   //1day = 24*60*60*1000 (To days in ms)
  
//   let down_days = (calc_time / (24*60*60*1000));
//   console.log(calc_time);
//   //Get the fractional component
//   let down_hours = down_days - Math.floor(down_days);
//   down_hours = down_hours * 24;
//   let down_mins = down_hours - Math.floor(down_hours);
//   down_mins = down_mins * 60;
//   let down_secs = down_mins - Math.floor(down_mins);
//   down_secs = down_secs * 60;

//   //Check if the product has expired
//   if (calc_time < 0) {
//     deadline.innerHTML = `<h4>This giveaway has expired</h4>`;
//   }
//   else {
//     //Convert to whole numbers except for seconds, 
//     //because it needs to be rounded
//     down_days = pad_leading_zero(Math.floor(down_days));
//     down_hours = pad_leading_zero(Math.floor(down_hours));
//     down_mins = pad_leading_zero(Math.floor(down_mins));
//     down_secs = pad_leading_zero(Math.round(down_secs));

//     deadline.querySelector(".deadline-format .days").innerText = down_days;
//     deadline.querySelector(".deadline-format .hours").innerText = down_hours;
//     deadline.querySelector(".deadline-format .mins").innerText = down_mins;
//     deadline.querySelector(".deadline-format .secs").innerText = down_secs;
//   }
  

// }, 1000);

//Alternate refactored solution: Calculate the time till the deadline
function remaining_time () {
  const calc_time = futureTime - Date.now();
  

  //End giveway if expired
  if (calc_time < 0) {
    deadline.innerHTML = "<h4>This giveaway has expired</h4>";
  }
  else {
    //Get the time in ms
    // 1s = 1000ms
    // 1min = 60s
    // 1hr = 60mins
    // 1day= 24hrs

    //Convert into days
    let down_days = calc_time / (24*60*60*1000);
    let down_hours = (down_days * 24) % 24;
    let down_mins = (down_hours * 60) % 60;
    let down_secs = (down_mins * 60) % 60;

    down_days = pad_leading_zero(Math.floor(down_days));
    down_hours = pad_leading_zero(Math.floor(down_hours));
    down_mins = pad_leading_zero(Math.floor(down_mins));
    down_secs = pad_leading_zero(Math.round(down_secs));

    //Add necessary zero digit padding
    let arr_count_down = [down_days, down_hours, down_mins, down_secs];

    //Update the time
    item_time.forEach((item, index) => {
      item.innerText = arr_count_down[index];
    });
  }
  

}

setInterval(remaining_time, 1000);
