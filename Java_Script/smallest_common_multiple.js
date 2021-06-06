//Check if a number is prime. Recursive
//Start is always 2
function is_prime (num, start) {
    //Base case
    if (num === start) {
      return true;
    }
    return ( (num % (start)!== 0)?true:false) && is_prime(num, start+1);
  }
  
  //Helper function
  
  //Use prime factorisation to find the LCM
  //Can assume positive integer
  function smallestCommons(arr) {
    //Make a hash table of numbers to quantity of numbers 
    let num_ran = {}
    //Get the range of numbers
    //Check for smallest number
    let min, max = 0;
    if (arr[0] < arr[1]) {
      min = arr[0];
      max = arr[1];
    }
    else {
      min = arr[1];
      max = arr[0];
    }
  
    //Initialise the table
    for (let i = min; i <= max; i+=1) 
    {
      //Set the quantity of nums needed for LCM to 0
      if (i === 1) 
      {
        continue;
      }
      num_ran[i] = {};
    }
  
    //Find all the prime factorisation in the range
    //Lemma: there will always be a factor less than the sqrt of a number, allowing us to find all factors
    for (let i = min; i <= max; i +=1) {
      if (i === 1) {
        continue;
      }
  
      for (let j = 2; j <= Math.floor(Math.sqrt(i)); j+=1) {
        let dividend = i;
        //Number is a divisor
        while (dividend % j === 0 && is_prime(j, 2)) {
          if (num_ran[i][j] === undefined) {
            num_ran[i][j] = 0;
            num_ran[i][j] +=1;
          } 
          else if (num_ran[i][j]) {
            num_ran[i][j] +=1;
          }
          dividend /= j;
        }
        //Once the dividend has been simplified to the smallest prime, add to the table
        if (dividend !== 1 && is_prime(dividend, 2)) {
          num_ran[i][dividend] = 1;
        }
      }
    }
    //console.log(num_ran);
    
    //Collect the largest powers of the factors in an hash table
    let lcm = {};
    for (let i in num_ran) {
  
      //An empty object is a prime
      if (Object.keys(num_ran[i]).length === 0) {
        lcm[i] = 1;
      }
      //Otherwise, need to extract prime with highest power
      for (let j in num_ran[i]) {
        if (lcm[j] === undefined) {
          lcm[j] = 0;
        }
        //Need to compare powers
        if (lcm[j] < num_ran[i][j]) {
          //console.log(num_ran[i][j]);
          lcm[j] = num_ran[i][j];
        }
      }
    }
    //console.log(lcm)
    //Multiply all the prime factorisations:
    let slcm = 1;
    for (let x in lcm) {
      slcm *= (Math.pow(x, lcm[x]));
    }
  
    
    console.log(slcm);
    
    return slcm;
  }
  
  
  
  
  smallestCommons([2, 10]);