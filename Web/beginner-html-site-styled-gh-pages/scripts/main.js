/*
const myHeading = document.querySelector("h1");
myHeading.textContent = "Hello World!";
*/
let myImage = document.querySelector("img");

myImage.onclick = function() {
    let src = myImage.getAttribute("src");
    console.log(src);
    if (src === "images/firefox-icon.png") {
        myImage.setAttribute("src", "images/b-collie.jpeg");
    }
    else {
        myImage.setAttribute("src", "images/firefox-icon.png");
    }
}

let myButton = document.querySelector("Button");
let myHeading = document.querySelector("h1");

function setUserName() {
    let myName = prompt("Please enter your name");
    localStorage.setItem("name", myName);
    myHeading.textContent = "Hello " + myName + "!";
}

if (!localStorage.getItem("name")) {
    setUserName();
}
else {
    let storedName = localStorage.getItem("name");
    myHeading.textContent = "Hello " + storedName + "!";
} 


myButton.onclick = function() {setUserName()};