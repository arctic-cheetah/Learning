var Person = function(firstAndLast) {
    // Only change code below this line
    //Separate the first and last name
    let name = firstAndLast.split(" ");
  
    this.setFullName = function(firstAndLast) {
      name = firstAndLast.split(" ");
    }
    this.setFirstName = function(first) {
      name[0] = first;
    }
    this.setLastName = function(last) {
      name[1] = last;
    }
  
  
    // Complete the method below and implement the others similarly
    this.getFullName = function() {
      return name[0] + ' ' + name[1];
    };
    this.getFirstName = function() {
      return name[0];
    }
    this.getLastName = function() {
      return name[1];
    }
  
    return firstAndLast;
  };
  
  var bob = new Person('Bob Ross');
  console.log(Object.keys(bob).length);
  bob.setFirstName("Haskell")
  bob.setLastName("Curry")
  console.log(bob.getFullName());
  