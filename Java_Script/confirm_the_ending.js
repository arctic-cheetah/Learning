//A function to check whether the target string 
//Is located at the end of the source string

function confirmEnding(str, target) {
    //Decompose str and target into an array
    str = [...str];
    target = [...target];
    //Check for every instance of target in the str
    //Case:
  
    //False
    //Does not find string
    //String is found in the middle or front
    var at_end = false;
    var has_found = false;
  
  
    let j = 0;
    for (let i = 0; i < str.length; i +=1) {
      
      //Matching chars, check for target string
      if (str[i] === target[j]) {
        has_found = true;
      }
      else {
        has_found = false;
        j = 0;
        //Check if there is a matching word because of repeated characters
        if (str[i] === target[j]) {
          has_found = true;
        }
      }
      //Increment to check target string
      if (has_found) {
        j +=1;
      }
  
      //True
      //String is found at the end
      //String is found at the end but also else where
      if ((j === target.length) && (i === str.length - 1) && has_found) {
        at_end = true;
      }
  
      //Did not find target at the end, reset 
      //
      else if ((j === target.length) && (i !== str.length - 1)) {
        //Not at end
        at_end = false;
        has_found = false;
        j = 0;
      }
    }
  
    return at_end ? true : false;
  }
  
  console.log(confirmEnding("Conor", "nor"));