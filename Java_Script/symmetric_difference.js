function diffArray(arr1, arr2) {
    let diff_A = [];
    let diff_B = [];
    //Get the difference of  A = arr1 - arr2 and B = arr2 - arr1
    //Take the union of both. That will be our symmetric difference
  
    //A = arr1 - arr2
    for (let i = 0; i < arr1.length; i +=1) {
      if (arr2.indexOf(arr1[i]) === -1) {
        diff_A.push(arr1[i]);
      }
    }
  
    //B = arr2 - arr1
    for (let i = 0; i < arr2.length; i +=1) {
      if (arr1.indexOf(arr2[i]) === -1) {
        diff_B.push(arr2[i]);
      }
    }
  
    return diff_A.concat(diff_B);
  }
  
  console.log(diffArray([1, 2, 3, 5], [1, 2, 3, 4, 5]));