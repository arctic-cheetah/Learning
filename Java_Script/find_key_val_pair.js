//A program that finds the key value pair of in an object--> Technically a hash table in disguise
function whatIsInAName(collection, source) {
    let arr = collection.slice();
    let keys = Object.keys(source);
    return arr.filter(function(obj) 
    {
      return keys.every(function(curr_key)
      {
        return (obj[curr_key] === source[curr_key]);
      })
    }); 
        
  
  }
  
  console.log(whatIsInAName([{ first: "Romeo", last: "Montague" }, { first: "Mercutio", last: null }, { first: "Tybalt", last: "Capulet" }], { last: "Capulet" }));