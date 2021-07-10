const prevBtn = document.querySelector(".prevBtn");
const nextBtn = document.querySelector(".nextBtn");
const slides = document.querySelectorAll(".slide");


//Remember! CSS styles are always inline in JS
slides.forEach((curr_slide, index) => {
    curr_slide.style.left = `${index * 100}%`;
});

prevBtn.style.display = "none";
let i = 0;

//subtract 100%
prevBtn.addEventListener("click", ()=>{
    i -=1;
    translate_image();
});
//add 100%
nextBtn.addEventListener("click", ()=>{
    i +=1;
    translate_image();
});


//Translates the image in the x axis
function translate_image() {
    //Linear slide show
    // if (i < 0) {
    //     i = 0;
    // }
    // else if (i >= slides.length) {
    //     i = slides.length - 1;
    // }

    //Wrapping slide show
    if (i < 0) {
        i = slides.length - 1;
    }
    i %= slides.length;


    slides.forEach((curr_slide) => {
        curr_slide.style.transform = `translateX(${-i * 100}%)`;
    });
}