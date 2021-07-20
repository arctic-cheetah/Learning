import React from "react";
import ReactDom from "react-dom";

// JSX rules
// return single element
// div / section / article or fragment
// use camelCase for html attribute
// className instead of class
// close every element
// formatting

function Greeting() {
  return (
    <section>
      <Person />
      <Message />
    </section>
  );
}

const Person = () => {
  return <h4>What's up world</h4>;
};

const Message = () => {
  return <p>This is my paragraph</p>;
};

ReactDom.render(<Greeting />, document.getElementById("root"));
