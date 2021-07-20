import React from "react";

const Book = (props) => {
  const { title, author, img, info } = props.book;
  const onClickHandler = () => {
    alert(title);
  };
  const onMouseOver = (e) => {
    console.log(e.target);
  };
  return (
    <article className="book">
      <img src={img} alt="LED light bulb" />
      <h1 onClick={onClickHandler}>{title}</h1>
      <h4 onMouseOver={onMouseOver}>{author}</h4>
      {info}
    </article>
  );
};

export default Book;
