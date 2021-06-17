function addTogether(...args) {
    //Check argument
    if (args.some(type => typeof(type) != "number")) {
      return undefined;
    }
    //All inputs are valid numbers
    if (args.length == 2) {
      return args[0] + args[1];
    }
    return function sum(num1) {
        return typeof(num1) != "number" ? undefined : num1 + args[0];
      };
  }
  
  console.log(addTogether(2)("3"));