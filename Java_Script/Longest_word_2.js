function findLongestWordLength(str) {
  let word = str.split(" ");

  //Base case, only one word in the array-- return the length
  if (word.length === 1) {
    return word[0].length;
  }
  
  //Compare the length of the other words  

  return Math.max(word[0].length, findLongestWordLength(word.slice(1).join(" ")));
}

console.log(findLongestWordLength("Google do a barrel roll"));