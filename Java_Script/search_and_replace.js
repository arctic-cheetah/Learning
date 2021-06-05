function myReplace(str, before, after) {

    //Preserve the case of the first character from the original word
    //First char is uppercase
    if (/^[A-Z]/.test(before)) {
      //Make the replacement word have the first char upper case
      after = [...after];
      after[0] = after[0].toUpperCase();
      after = after.join("");
      console.log(after);
    }
    //Lowercase
    else {
      after = [...after];
      after[0] = after[0].toLowerCase();
      after = after.join("");
      console.log(after);
    }
    
    var regex = new RegExp(before);
    return str.replace(regex, after);
  }
  
  console.log(myReplace("A quick brown fox jumped over the lazy dog", "jumped", "Leaped"));