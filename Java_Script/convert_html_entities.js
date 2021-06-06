function convertHTML(str) {
    let html_str = str.slice(0);
    //Hash table for chars
    let html_entities = {
      '&' : "&amp;",
      '<' : "&lt;",
      '>' : "&gt;",
      '"' : "&quot;",
      "'" : "&apos;"
    }
    //Find desired char
    for (let x in html_entities) {
      //Create a regex
      let insert_entity = new RegExp(x, 'g');
      //Replace with html entity
      html_str = html_str.replace(insert_entity, html_entities[x]);
    }
    
    return html_str;
  }
  
  convertHTML("Hamburgers < Pizza < Tacos");
  convertHTML('Stuff in "quotation marks"');
  convertHTML("Schindler's List");

/*
function convertHTML(str) {
  // Use Object Lookup to declare as many HTML entities as needed.
  const htmlEntities = {
    "&": "&amp;",
    "<": "&lt;",
    ">": "&gt;",
    '"': "&quot;",
    "'": "&apos;"
  };
  // Using a regex, replace characters with it's corresponding html entity
  return str.replace(/([&<>\"'])/g, match => htmlEntities[match]);
}
*/
