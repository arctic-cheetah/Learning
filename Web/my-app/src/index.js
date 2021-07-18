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
  return <h4>My world</h4>;
}

ReactDom.render(<Greeting />, document.getElementById("root"));
