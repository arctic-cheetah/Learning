//A program to add an 'ay' suffix to the word

function translatePigLatin(str) {
    //Copy the string
    let pig_str = str.slice(0);
    let only_consonant = new RegExp("[^aeiou]{" + str.length + "}");
    let first_part_cons = /^[^aeiou]+/;
    //Is the first letter a vowel?
    if (/^[aeiou]/.test(str)) {
      return pig_str + "way";
    }
  
    //Does the entire word consists only of consonants
    else if (only_consonant.test(str)) {
      return pig_str + "ay";
    }
  
    //Separate the first part of the consonant (S) from the rest of the string. 
    let first_part = pig_str.match(first_part_cons);
    let second_part = pig_str.split(first_part_cons)[1];
    first_part = first_part[0];
    
    //concatenate S with "ay" 
    first_part = first_part + "ay";
    //concatentate the rest of the string with S
    pig_str = second_part + first_part;
  
    return pig_str;
  }
  
  console.log(translatePigLatin("paragraphs"));