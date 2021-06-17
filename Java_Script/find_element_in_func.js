function findElement(arr, func) {
    let i = 0;
    let func_is_true = false;
    while (i < arr.length) {
      if (func(arr[i])) {
        func_is_true = true;
        break;
      }
      i +=1;
    }
  
    return func_is_true ? arr[i] : undefined;
  }
  
  console.log(findElement([1, 3, 5, 8, 9, 10], function(num) { return num % 2 === 0; }));