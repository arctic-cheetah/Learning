const redSlider = document.getElementById("red-slider");
const greenSlider = document.getElementById("green-slider");
const blueSlider = document.getElementById("blue-slider");
const info  = document.querySelectorAll(".info-num");
const body = document.querySelector(".main");

var red_val = 0;
var green_val = 0;
var blue_val = 0;

redSlider.oninput = function () {
    red_val = this.value;
    const min = this.min ? this.min : 0;
    const max = this.max ? this.max : 0;
    const offset = Number((red_val - min) * 100 / (max - min));
    //Move the indicator
    info[0].innerText = red_val;
    let parent = info[0].parentElement;
    parent.style.left = `calc(${offset}% + ${1 - offset*.26}px)`;
    body.style.backgroundColor = `rgb(${red_val}, ${green_val}, ${blue_val})`;

};

greenSlider.oninput = function () {
    green_val = this.value;
    const min = this.min ? this.min : 0;
    const max = this.max ? this.max : 0;
    const offset = Number((green_val - min) * 100 / (max - min));
    //Move the indicator
    info[1].innerText = green_val;
    let parent = info[1].parentElement;
    parent.style.left = `calc(${offset}% + ${1 - offset*.26}px)`;
    body.style.backgroundColor = `rgb(${red_val}, ${green_val}, ${blue_val})`;
};

blueSlider.oninput = function () {
    blue_val = this.value;
    const min = this.min ? this.min : 0;
    const max = this.max ? this.max : 0;
    const offset = Number((blue_val - min) * 100 / (max - min));
    //Move the indicator
    info[2].innerText = blue_val;
    let parent = info[2].parentElement;
    parent.style.left = `calc(${offset}% + ${1 - offset*.26}px)`;
    body.style.backgroundColor = `rgb(${red_val}, ${green_val}, ${blue_val})`;
};





























// body.addEventListener("click", (e) => {
//     let elem = e.target;
//     if (elem.classList[0]== "slider") {
//         let info = elem.previousElementSibling.firstElementChild;
//         info.innerText = slider_val;
//     }
// });
