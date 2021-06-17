//Truncate a string

function truncateString(str, num) {
    //Consider cases
    //Num is greater than str.length
    //Num === str.length
    //Return str
    if (num >= str.length) {
      return str;
    }
  
    //Num is smaller than str.length. So truncate it.
    return str.slice(0, num) + "...";
  }
  
  console.log(truncateString("A-", 1));