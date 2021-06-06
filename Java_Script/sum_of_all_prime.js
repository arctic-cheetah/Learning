//A prime number is a number that is only divisible by 1 and itself
function sumPrimes(num) {
    //Base case, smallest prime- which is two, has been reached
    if (num <= 2) {
      return 2;
    }
    let prime = true;
    //if the curr number is a prime, add to the sum
    for (let i = 1; i <= num; i +=1) {
      if ((num % i == 0) && i !== 1 && i !== num) {
        prime = false;
        break;
      }
    }
    //Return 0 otherwise
    return (prime ? num : 0) + sumPrimes(num -=1);
  }
  
  console.log(sumPrimes(977));