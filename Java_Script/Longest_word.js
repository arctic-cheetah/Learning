//A program to find the longest word in a string

function findLongestWordLength(str) {
    //Counter
    let max_len = 0;
    let curr_word_len = 0;
  
    let i = 0;
    while (i < str.length) { 
      //Break the longest word_count if there is a whitespace
      if (str[i] == ' ') {
        curr_word_len = 0;
      }
      
      //Check if the max_len is smaller than the curr_word_len
      if (max_len < curr_word_len) {
        max_len = curr_word_len;
      }
      curr_word_len +=1;
      i +=1;
    }
    //
  
    return max_len;
  }
  
  console.log(findLongestWordLength("What is the average airspeed velocity of an unladen swallow"));