//A program to repeat the string x number of times

function repeatStringNumTimes(str, num) {
    //If num is less than 0
    if (num <= 0) {
      return "";
    }
    //Deconstruct the string
    str = [...str];
    let str_cpy = [];
    //Duplicate the string num times
    for (let k = 0; k < num; k +=1) {
      for (let i = 0; i < str.length; i +=1) {
        str_cpy.push(str[i]);
      }
    }
      
    return str_cpy.join("");
  }
  
  console.log(repeatStringNumTimes("abc", 3));