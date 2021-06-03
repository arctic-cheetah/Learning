function titleCase(str) {
    //Take a word out
    //Separate by spaces
    let word = str.split(" ");
    for (let i = 0; i < word.length; i +=1) {
      word[i] = word[i].toLowerCase().replace(/^\w/g, (c) => c.toUpperCase() );
      console.log(word[i]);
    }
    
    return word.join(" ");
  }
  
  console.log(titleCase("I'm a little tea pot"));