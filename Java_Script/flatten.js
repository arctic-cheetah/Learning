
function match_type (type) {
    if (type == "string" || type == "number") {
      return true;
    }
    return false
  }
  
  function steamrollArray(arr) {
    let flat_arr = [];
    //Find all the numbers in the arr by looking at each level
    function flatten(arr) 
    {
      //Base case:
      for (let i = 0; i < arr.length; i +=1) 
      {
        //Don't add empty set
        if (arr[i] !== []) 
        {
          //Check the type before recursing
          if (typeof(arr[i]) !== "string") {
            flatten(arr[i]);
          }
          //Add only if the arr[i] has a data_type
          if (match_type(typeof(arr[i])) || JSON.stringify(arr[i]) === "{}") 
          {
            flat_arr.push(arr[i]);
          }
        }
      }
    }
    flatten(arr);
    console.log(flat_arr);
  
    return flat_arr;
  }
  //Works for integers
  steamrollArray([1, {}, [3, [[4]]]]);