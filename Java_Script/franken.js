function frankenSplice(arr1, arr2, n) {
    let spliced_arr = arr2.slice();
    spliced_arr.splice(n, 0, ...arr1)
    return spliced_arr;
  }
  
  console.log(frankenSplice([1, 2, 3], [4, 5], 1));