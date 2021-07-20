import React from "react";
import ReactDom from "react-dom";

//CSS
import "./index.css";

import { books_obj } from "./books_obj.js";
import Book from "./book_component.js";
// Smliga's implementation

const books_arr = books_obj.map((book) => {
  //You can dereference via ...
  return <Book key={book.isbn} book={book}></Book>;
});

function BookList() {
  return <section className="bookList">{books_arr}</section>;
}

// const Book = () => {
//   return (
//     <article className="book">
//       <Img />
//       <Title />
//       <Author />
//     </article>
//   );
// };

// const Img = () => {
//   return (
//     <img
//       src="http://nilhcem.com/public/images/20171220/09_magicblue.jpg"
//       alt="LED light bulb"
//     />
//   );
// };

// const Title = () => {
//   return <h1>My light bulb</h1>;
// };

// const Author = () => {
//   return (
//     <h4 style={{ color: "#0D0D0D", fontSize: ".75rem", marginTop: ".25rem" }}>
//       The bubby
//     </h4>
//   );
// };

ReactDom.render(<BookList />, document.getElementById("root"));
