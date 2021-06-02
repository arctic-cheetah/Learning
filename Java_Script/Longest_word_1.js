function findLongestWordLength(str) {
    let word = str.split(" ");
    let max_len = 0;
  
    var i = 0;
    while (i < word.length) {
      if (max_len < word[i].length) {
        max_len = word[i].length;
      }
      i +=1;
    }
    
  
    return max_len;
  }
  
  console.log(findLongestWordLength("The quick brown fox jumped over the lazy dog"));