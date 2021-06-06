function uniteUnique(arr) {
    //Join all the arrays
    arr = Array.from(arguments).flat(1);
    
    let union_arr = [];
    
    for (let i = 0; i < arr.length; i +=1) {
      //Number is not in the union. Add it
      if (!union_arr.some(num => (num === arr[i]))) {
        union_arr.push(arr[i]);
      }
    }
    console.log(union_arr);
  
    return union_arr;
  }
  
  uniteUnique([1, 3, 2], [5, 2, 1, 4], [2, 1]);