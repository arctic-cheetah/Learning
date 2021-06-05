
function spinalCase(str) {
    //Copy the str
    
    let spinal_str = str.slice(0);
    
    //Split the string into an array of words
    //Case:
    //Split before capital letter
    //Split if there is a non_alphanumeric special character
    spinal_str = spinal_str.split(/([A-Z][a-z]+|\s|[-_])/g);
    //Remove all empty strings,
    spinal_str = spinal_str.filter(word => !/([_-]|\s)/g.test(word) && word !== '');
    spinal_str = spinal_str.join('-').toLowerCase();
  
    console.log(spinal_str);
    return spinal_str;
  }
  
  
  
  spinalCase("AllThe-small Things");