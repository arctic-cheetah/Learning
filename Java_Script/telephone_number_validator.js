
let valid_regex = [
    /*Area code (5)*/
    /^(\d{3}\-\d{3}\-\d{4})/, /^(\(\d{3}\)\d{3}-\d{4})/g, 
    /^(\(\d{3}\) \d{3}-\d{4})/g, /\d{3} \d{3} \d{4}/g, /^(\d{10}(?!\d))/g,
    /*National code here (5)*/
    /1 \d{3}-\d{3}-\d{4}/g, /1 \(\d{3}\)\d{3}-\d{4}/g, /^1 \(\d{3}\) \d{3}-\d{4}/g,
     /1 \d{3} \d{3} \d{4}/g , /1\(\d{3}\)\d{3}-\d{4}/g];
    
    //Recursively check each condition invalid_area_num_regex
    function check_num (str, i) {
      //Base case
      if (i === valid_regex.length - 1) {
        return Boolean(str.match(valid_regex[i]));
      }
      return Boolean(str.match(valid_regex[i])) || Boolean(check_num(str, i+1));
    }
    
    function telephoneCheck(str) {
      return check_num(str, 0);
    }
    
    console.log("-1 (757) 622-7382".match(valid_regex[7]));
    
    //console.log(telephoneCheck("27576227382"));
    //console.log(telephoneCheck("5555555555"));
    console.log(telephoneCheck("555-555-5555"));