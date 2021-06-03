function titleCase(str) {
    //Deconstruct into array
    let prev_space = false;
    str = [...str];
    //O(n)
    for (let i = 0; i < str.length; i +=1) {
      
      
  
      //All chars at the beginning of the word are capitalised 
      //Check the type of character
  
      //Beginning of the sentence, and lowercase
      if (i === 0 && ('a' <= str[i] && str[i] <= 'z')) {
        str[i] = String.fromCharCode(str[i].charCodeAt(0) - 32);
      }
      //prev_space -- Capitalise
      else if (prev_space && ('a' <= str[i] && str[i] <= 'z')) {
        str[i] = String.fromCharCode(str[i].charCodeAt(0) - 32);
      }
      //everything inside a word is lower case
      //And must be a letter
      else if (i != 0 && !prev_space && ('A' <= str[i] && str[i] <= 'Z'))   {
        str[i] = String.fromCharCode(str[i].charCodeAt(0) + 32);
      }
  
      //Check that prev space is true
      if (str[i] === ' ') {
        prev_space = true;
      }
      else {
        prev_space = false;
      }
      
    }
  
  
    return str.join("");
  }
  
  console.log(titleCase("sHoRt AnD sToUt"));