const menu = [
  {
    id: 1,
    title: "buttermilk pancakes",
    category: "breakfast",
    price: 15.99,
    img: "./images/item-1.jpeg",
    desc: `I'm baby woke mlkshk wolf bitters live-edge blue bottle, hammock freegan copper mug whatever cold-pressed `,
  },
  {
    id: 2,
    title: "diner double",
    category: "lunch",
    price: 13.99,
    img: "./images/item-2.jpeg",
    desc: `vaporware iPhone mumblecore selvage raw denim slow-carb leggings gochujang helvetica man braid jianbing. Marfa thundercats `,
  },
  {
    id: 3,
    title: "godzilla milkshake",
    category: "shakes",
    price: 6.99,
    img: "./images/item-3.jpeg",
    desc: `ombucha chillwave fanny pack 3 wolf moon street art photo booth before they sold out organic viral.`,
  },
  {
    id: 4,
    title: "country delight",
    category: "breakfast",
    price: 20.99,
    img: "./images/item-4.jpeg",
    desc: `Shabby chic keffiyeh neutra snackwave pork belly shoreditch. Prism austin mlkshk truffaut, `,
  },
  {
    id: 5,
    title: "egg attack",
    category: "lunch",
    price: 22.99,
    img: "./images/item-5.jpeg",
    desc: `franzen vegan pabst bicycle rights kickstarter pinterest meditation farm-to-table 90's pop-up `,
  },
  {
    id: 6,
    title: "oreo dream",
    category: "shakes",
    price: 18.99,
    img: "./images/item-6.jpeg",
    desc: `Portland chicharrones ethical edison bulb, palo santo craft beer chia heirloom iPhone everyday`,
  },
  {
    id: 7,
    title: "bacon overflow",
    category: "breakfast",
    price: 8.99,
    img: "./images/item-7.jpeg",
    desc: `carry jianbing normcore freegan. Viral single-origin coffee live-edge, pork belly cloud bread iceland put a bird `,
  },
  {
    id: 8,
    title: "american classic",
    category: "lunch",
    price: 12.99,
    img: "./images/item-8.jpeg",
    desc: `on it tumblr kickstarter thundercats migas everyday carry squid palo santo leggings. Food truck truffaut  `,
  },
  {
    id: 9,
    title: "quarantine buddy",
    category: "shakes",
    price: 16.99,
    img: "./images/item-9.jpeg",
    desc: `skateboard fam synth authentic semiotics. Live-edge lyft af, edison bulb yuccie crucifix microdosing.`,
  },
  {
    id: 10,
    title: "steak dinner",
    category: "dinner",
    price: 30.99,
    img: "./images/item-10.jpeg",
    desc: `skateboard fam synth authentic semiotics. Live-edge lyft af, edison bulb yuccie crucifix microdosing.`,
  }
];

const sectionCenter = document.querySelector(".section-center");
const btnContainer = document.querySelector(".btn-container");

//Updates the DOM once the content has loaded
window.addEventListener("DOMContentLoaded", function() {
  displayMenuItems(menu);
  let category = getNewCategory(menu);
  makeNewCategory(category);
  const filterBtns = document.querySelectorAll(".filter-btn");
  //console.log(filterBtns);
  filter_menu(filterBtns);
});


//Pt3 solution: updating the menu to fit different categories
//Identify unique categories, including the all category
function getNewCategory() {
  
  //My solution
  // let category = ["all"];
  // menu.forEach(function (item) {
  //   if (!category.includes(item.category)) {
  //     category.push(item.category);
  //   }
  // });
  
  //Alternate solution
  let category = menu.reduce(function (values, acc) {
    if (!values.includes(acc.category)) {
      values.push(acc.category);
    }
    return values;
  }, ["all"])
  
  return category;
}
//Make buttons for all categories
function makeNewCategory(category) {
  let filterBtns = category.map(function(item) {
    return `<button class="filter-btn" type="button" data-food="${item}">${item}</button>`;
  });
  filterBtns = filterBtns.join("");
  btnContainer.innerHTML = filterBtns;
  
}

//Create html tag to with each category

//A function to display the menu items
function displayMenuItems(menuItems) {
  let displayMenu = menuItems.map(function(item) {
    return `<article class="menu-item">
    <img src="${item.img}" class="photo" alt="${item.title}">
    <div class="item-info">
      <header>
        <h4 class="menu-name">${item.title}</h4>
        <h4 class="price">${item.price}</h4>
      </header>
      <p class="item-text">${item.desc}
      </p>
    </div>
  </article>`;
  });
  displayMenu = displayMenu.join("");
  sectionCenter.innerHTML = displayMenu;
}

//My custom solution to pt2 of the menu filter
function filter_menu (filterBtns) {
  filterBtns.forEach((curr_btn) => {
    curr_btn.addEventListener("click", function() {
      category = curr_btn.innerText.toLowerCase();
      //Filter the menu
      let menu_filtered = menu.filter((item) => { 
        if(item.category === category) {
          return true;
        }
        else if (category === "all"){
          return true;
        }
        return false;
      });
      displayMenuItems(menu_filtered);
    });
  });
}
  


