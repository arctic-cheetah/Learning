//TO DO
//Add quote to twitter link

//Colour change
const body = document.querySelector(".root");
const change_quote = document.getElementById("new-quote");
const quote_box = document.getElementById("quote-box");
const share = document.querySelector(".share");

//Quote URL
const URL_quote = "https://api.quotable.io/random";

//Execution
get_new_quote();

///////////////////////////////////////////////////////
//Function Defintions

//Change the colour of the required elements after a click
function change_colour() {
  let colour = [0, 0, 0, 0];
  for (let i = 0; i < 4; i += 1) {
    //Any RGB value is between 0 - 256
    if (i < 3) {
      colour[i] = Math.random() * 256;
    }
    //Alpha value
    else {
      colour[i] = Math.random();
    }
  }

  //Convert array to string
  let rgba_val = `rgb(${colour[0]}, ${colour[1]}, ${colour[2]}, ${colour[3]})`;
  let rgba_val_darker = `rgb(${colour[0]}, ${colour[1]}, ${colour[2]}, ${
    colour[3] + 1
  })`;
  //Apply colour to all style
  body.style.backgroundColor = rgba_val;
  change_quote.style.backgroundColor = rgba_val;
  change_quote.style.border = `2px solid ${rgba_val}`;
  share.firstElementChild.style.backgroundColor = rgba_val;
  share.lastElementChild.style.backgroundColor = rgba_val;
}

function get_new_quote() {
  change_colour();
  fetch(URL_quote)
    .then((response) => {
      if (200 <= response && response < 300) {
        throw new Error(response.status);
      }
      return response.json();
    })
    .then((data) => {
      transition_text(data);
    })
    .catch((e) => {
      console.log("Error " + e.message);
    });
}

function transition_text(data) {
  //Animate the change in text
  $("#text").animate({ opacity: 0 }, 500, function () {
    $(this).animate({ opacity: 1 }, 500);
    $(this).html(data.content);
  });
  $("#author").animate({ opacity: 0 }, 500, function () {
    $(this).animate({ opacity: 1 }, 500);
    $(this).html(data.author);
  });
}

$(document).ready(function () {
  $("#new-quote").on("click", get_new_quote);
});
