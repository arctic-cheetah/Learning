var slider = document.getElementById("myRange");
var output = document.getElementById("demo");
const btn  = document.querySelector(".selectBtn");
const sliderContainer = document.querySelector(".slide-container");


//Static
// sliderContainer.addEventListener("click", (e) => {
//     console.log(e.target);
//     const val = slider.value;
//     const min = slider.min ? slider.min : 0;
//     const max = slider.max ? slider.max : 0;
//     const offset = Number((val - min) * 100 / (max - min));

//     //Constants needed to ensure the button is on the centre
//     //Determine the constants by trial and error :(
//     output.style.left = `calc(${offset}% + ${1 - offset*.26}px)`;
// });



//Need to map the values

// Update the current slider value (each time you drag the slider handle)
slider.oninput = function() {
    const val = this.value;
    const min = this.min ? this.min : 0;
    const max = this.max ? this.max : 0;
    const offset = Number((val - min) * 100 / (max - min));

    btn.innerText = val;

    //Constants needed to ensure the button is on the centre
    //Determine the constants by trial and error :(
    output.style.left = `calc(${offset}% + ${1 - offset*.26}px)`;
}
