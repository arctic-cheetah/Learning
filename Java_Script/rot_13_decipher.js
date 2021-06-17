function rot13(str) {
    //Convert all strings to uppercase
    //Convert to an array
    let decode_str = [...str.toUpperCase()];
    console.log(decode_str);
  
    //Solve issue where subtract 13 and needs to shift to the end
    //Only convert alphanumerics
    for (let i = 0; i < decode_str.length; i +=1) {
      //exclude non_alphanumeric
      if (decode_str[i] !== '?' && decode_str[i] !== '!' 
         && decode_str[i] !== ' ' && decode_str[i] !== '.' 
         && decode_str[i] !== ',') 
         {
           //Convert to ASCII
           decode_str[i] = decode_str[i].charCodeAt(decode_str[i]) 
                           - 'A'.charCodeAt(0) - 13;
          //Wrap negative numbers
           if (decode_str[i] < 0) {
             decode_str[i] += 26;
           }
           //Return char code to positive numbers
           decode_str[i] += 'A'.charCodeAt(0);
           decode_str[i] = String.fromCharCode(decode_str[i]);
         }
    }
    decode_str = decode_str.join("");
  
    console.log(decode_str);
  
    return decode_str;
  }
  
  rot13("GUR DHVPX OEBJA SBK WHZCF BIRE GUR YNML QBT.");