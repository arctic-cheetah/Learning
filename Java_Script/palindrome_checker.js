function palindrome(str) {
    let check_str = str.slice();
    //To remove all non-alphanumeric char
    //Convert to lower case
    //Split char into array
    check_str = check_str.replace(/[^A-Za-z0-9]/g, '').toLowerCase().split("");
    console.log(check_str);
  
    let end = check_str.length - 1;
    let start = 0;
    
    while (start < end) {
      if (check_str[start] !== check_str[end]) {
        return false;
      }
      end -=1;
      start +=1;
    }
  
    return true;
  }
  
  
  
  console.log(palindrome("1 eye for of 1 eye."));