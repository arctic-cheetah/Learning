function binaryAgent(arr) {
    //Need to split the binary string into an array
    let bin_str = arr.split(" ");
    //Convert binary string into numbers
    for (let i = 0; i < bin_str.length; i +=1) {
      bin_str[i] = parseInt(bin_str[i], 2);
    }
    //console.log(bin_str);
    //Convert to number to ASCII char
    for (let i = 0; i < bin_str.length; i +=1) {
      bin_str[i] = String.fromCharCode(bin_str[i]);
    }
    //Create string 
    let str = "";
    console.log(str = bin_str.reduce((accum, curr_val) => accum + curr_val));
    return str;
  }
  
  binaryAgent("01000001 01110010 01100101 01101110 00100111 01110100 00100000 01100010 01101111 01101110 01100110 01101001 01110010 01100101 01110011 00100000 01100110 01110101 01101110 00100001 00111111");
  binaryAgent("01001001 00100000 01101100 01101111 01110110 01100101 00100000 01000110 01110010 01100101 01100101 01000011 01101111 01100100 01100101 01000011 01100001 01101101 01110000 00100001")