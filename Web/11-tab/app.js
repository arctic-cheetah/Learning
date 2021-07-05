//TO DO: display different info based on the tab clicked

//Alternative solution, minimum DOM calls
const buttons = document.querySelectorAll(".tab-btn");
const about = document.querySelector(".about");
const articles = document.querySelectorAll(".content");

about.addEventListener("click", (e) => {
    let id = e.target.dataset.id;
    if (id) {
        buttons.forEach((curr_button) => {
            curr_button.classList.remove("active");
        });
        e.target.classList.add("active");

        articles.forEach((curr_article) => {
            curr_article.classList.remove("active");
            if (curr_article.id === id) {
                curr_article.classList.add("active");
            }
        });
    }
});

//My solution:
// const buttons = document.querySelectorAll(".tab-btn");
// console.log(buttons);
// buttons.forEach((this_button) => {

//     this_button.addEventListener("click", () => {
//         //Remove the previous active tab and content
//         let hide_button;
//         buttons.forEach((curr_button) => {
//             if (curr_button.classList.contains("active")) {
//                 hide_button = curr_button;
//             }
//         });
//         let hide_content = document.getElementById(hide_button.dataset.id);
//         hide_content.classList.remove("active");
//         hide_button.classList.remove("active");

//         //Show the clicked tab and the content in the tab active
//         let show_content = document.getElementById(this_button.dataset.id);
//         this_button.classList.add("active");
//         show_content.classList.add("active");
//     });
// }); 