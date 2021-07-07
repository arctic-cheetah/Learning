//Select items
const my_alert = document.querySelector(".alert");
const form = document.querySelector(".grocery-form");
const grocery = document.querySelector("#grocery");
const submitBtn = document.querySelector(".submit-btn");
const container = document.querySelector(".grocery-container");
const list = document.querySelector(".grocery-list");
const clearBtn = document.querySelector(".clear-btn");

//Edit items
let editElement;
let editFlag = false;
let editID = "";

///////////////////////////////////////////
//Functions

window.addEventListener("DOMContentLoaded", previousSession);

//Edit an item
function editItem(e) {
  //Set edit item
  editElement = e.currentTarget.parentElement.previousElementSibling;
  //Set item to form value
  grocery.value = editElement.innerHTML;
  editFlag = true;
  editID = editElement.dataset.id;
  submitBtn.textContent = "edit";
}

//Delete an item
function deleteItem(e) {
  let elem = e.currentTarget.parentElement.parentElement;
  const id = e.currentTarget.parentElement.previousElementSibling.dataset.id;
  displayAlert("Item removed", "danger");
  setBackToDefault();
  list.removeChild(elem);
  if (list.children.length == 0) {
    container.classList.remove("show-container");
  }
  removeFromLocalStorage(id);
}

//display alert
function displayAlert(text, action) {
  my_alert.textContent = text;
  my_alert.classList.add(`alert-${action}`);
  //remove alert
  setTimeout(() => {
    my_alert.textContent = "";
    my_alert.classList.remove(`alert-${action}`);
  }, 1000);
};

//Add an item
function addItem(id, value) {
  let template = document.createElement("template");
  template.innerHTML =   
  `<article class="grocery-item">
    <p class="title" data-id="${id}">${value}</p>
    <div class="btn-container">
      <button type="button" class="edit-btn">
        <i class="fas fa-edit"></i>
      </button>
      <button type="button" class="delete-btn">
        <i class="fas fa-trash"></i>
      </button>
    </div>
  </article>`;
  let new_item = template.content.lastChild;
  list.appendChild(new_item);
  container.classList.add("show-container");

  new_item.querySelector(".edit-btn").addEventListener("click", editItem);
  new_item.querySelector(".delete-btn").addEventListener("click", deleteItem);
}

function setBackToDefault() {
  grocery.value = "";
  editFlag = false;
  editID = "";
  //console.log("Set back to default");
}


//Remove all the items
function clearItems () {
  list.innerHTML = "";
  container.classList.remove("show-container");
  displayAlert("empty list", "danger");
  setBackToDefault();
  localStorage.clear();
}

//Modify the item
function modifyItem(e) {
  e.preventDefault();
  const value = grocery.value;
  const id = new Date().getTime().toString();
  
  //Add the item
  if (value && !editFlag){
    addItem(id, value);
    displayAlert(`${value} added!`, "success");
    addToLocalStorage(id, value);
    setBackToDefault();
  }
  //Edit the item
  else if(value && editFlag) {
    editElement.innerHTML = value;
    displayAlert("Value changed", "success");
    //Edit local storage
    editLocalStorage(editID, value);
    setBackToDefault();
  }
  else {
    alert("Please enter a value");
    displayAlert("Empty value", "danger");
  }
}


/////////////////////////////////////////
//Event listeners
//submit form
form.addEventListener("submit", modifyItem);
//Clear items
clearBtn.addEventListener("click", clearItems);
//Edit 

//TO DO, add local storage
//Local storage
// localStorage API
// setItem
// getItem
// removeItem

function addToLocalStorage(id, value) {
  localStorage.setItem(id, value);
}

function editLocalStorage(id, value) {
  localStorage.setItem(id, value);
}

function removeFromLocalStorage(id) {
  localStorage.removeItem(id);
}

//Reload any previous data
function previousSession() {
  let len = localStorage.length;
  for (let i = 0; i < len; i +=1) {
    //Get the key
    let id = localStorage.key(i);
    //Get the value
    let val = localStorage.getItem(id);
    //Add the grocery to the list
    addItem(id, val);
  }
}

//Setup items
