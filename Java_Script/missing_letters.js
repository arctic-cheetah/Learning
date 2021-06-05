//Find the missing letter in the passed letter range and return it.

function fearNotLetter(str) {
    //Convert str to lower case
    //We can probably assume that the letter range is ordered
  
    //Get max and min of letters in ascii code
    let min = str.charCodeAt(0);
    
    let max = str.charCodeAt(str.length - 1);
    //Go through the array and return the missing letter
    let j = 0;
    for (let i = min; i <= max; i +=1) {
      if (str.charAt(j) !== String.fromCharCode(i)) {
        return String.fromCharCode(i);
      }
      j +=1;
    }
  
    //Otherwise, returned undefined
    return undefined;
  }
  
  console.log(fearNotLetter("abce"));