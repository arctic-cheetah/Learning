//A program to repeat the string x number of times

function repeatStringNumTimes(str, num) {
    let str_dup = "";
    while (num > 0) {
      str_dup += str;
      num -=1;
    }
    return str_dup;
  }
  
  console.log(repeatStringNumTimes("abc", 3));