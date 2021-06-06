function sumFibs(num) {
    //Base case
    
    return sumFibo(1, 1, num);
  }
  
  function sumFibo(curr, prev, limit) {
    //Stop and only return odd if limit is surpassed
    if (curr > limit) {
      return (prev & 1) ? prev : 0;
    }
    //Sum the curr odd num of the fibonacci series
    return sumFibo((prev + curr), curr, limit)+((prev & 1) ? prev : 0);
  }
  
  console.log(sumFibs(75024));