//using selectors inside the element
// traversing the dom


//Dom traversal solution
const questionBtn = document.querySelectorAll(".question-btn");
questionBtn.forEach(curr_q_btn => {
    curr_q_btn.addEventListener("click", (btn) => {
        const question = btn.currentTarget.parentElement.parentElement;
        question.classList.toggle("show-text");
    });
});



/*
//My solution
const question = document.querySelectorAll(".question");
question.forEach((curr_question) => {
    questionBtn = curr_question.querySelectorAll(".question-btn");

    //Get the plus and minus icons
    let plusBtn = questionBtn[0].querySelector(".plus-icon");
    let minusBtn = questionBtn[0].querySelector(".minus-icon");
    plusBtn.addEventListener("click", function() {
        curr_question.classList.add("show-text");
    });
    minusBtn.addEventListener("click", function() {
        curr_question.classList.remove("show-text");
    });
});
*/
