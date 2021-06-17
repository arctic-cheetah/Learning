//A program to repeat the string x number of times
//Recursively
function repeatStringNumTimes(str, num) {
    //Base case;
    if (num <= 0) {
      return "";
    }
    return str.concat(repeatStringNumTimes(str, num - 1)); 
  }
  
  console.log(repeatStringNumTimes("abc", 3));

//Very compact notation below
  /*
  function repeatStringNumTimes(str, num) {
  return (num > 0) ? str.concat(repeatStringNumTimes(str, num - 1)) : ""; 
}

  */