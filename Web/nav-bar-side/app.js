
const sideBar = document.querySelector(".sidebar");
const sideBarToggle = document.querySelector(".sidebar-toggle");
const closeBtn = document.querySelector(".close-btn");

sideBarToggle.addEventListener("click", function() {
    /*My solution
    if (sideBar.classList.contains("show-sidebar") ) {
        sideBar.classList.remove("show-sidebar");
    }
    else {
        sideBar.classList.add("show-sidebar");
    }
    */
    sideBar.classList.toggle("show-sidebar");
});

closeBtn.addEventListener("click", function() {
    sideBar.classList.toggle("show-sidebar");
});