//Freecodecamp
//Write a function that splits an array (first argument) into groups the length of size (second argument) and returns them as a two-dimensional array.

function chunkArrayInGroups(arr, size) {
    let result_arr = [];
    let add_arr = [];
    let i = 0;
    while (i < arr.length) {
      //Reset 
      if (i % size === 0 && i != 0) {
        result_arr.push(add_arr);
        add_arr = [];
      }
      add_arr.push(arr[i]);
      i +=1;
    }
  
    //If there are still elements,
    //Add them to the result
    result_arr.push(add_arr);
    
    return result_arr;
  }
  
  console.log(chunkArrayInGroups(["a", "b", "c", "d"], 2));