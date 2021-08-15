//TO DO
//Make the background colour strobe colours
//

//Colour change
const body = document.querySelector(".root");
const change_quote = document.getElementById("new-quote");
const quote_box = document.getElementById("quote-box");
const share = document.querySelector(".share");

//Quote URL
const URL_quote = "https://api.quotable.io/random";

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
  fetch(URL_quote)
    .then((response) => response.json())
    .then((data) => {
      console.log(data);
      quote_box.firstElementChild.innerText = data.content;
      quote_box.children[1].innerText = data.author;
    });
}

change_quote.addEventListener("click", () => {
  change_colour();
  get_new_quote();
});
