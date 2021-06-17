var roman = {
    '1'   : 'I',
    '4'   : 'IV',
    '5'   : 'V',
    '9'   : 'IX',
    '10'  : 'X',
    '40'  : 'XL',
    '50'  : 'L',
    '90'  : 'XC',
    '100' : 'C',
    '400' : 'CD',
    '500' : 'D',
    '900' : 'CM',
    '1000': 'M'
  };
  //Helper function to get the roman numeral
  function get_roman_numeral (mult, base) {
    let return_str = "";
    for (mult; mult > 0; mult -=1) {
      return_str += roman[base];
    }
    return return_str;
  }
  
  function convertToRoman(num) {
    //Find the starting base:
    //Start from the thousands, then hundreds, then tens, and units
    let my_num = num;
    let pow = Math.floor(Math.log10(my_num));
    let base_num = Math.pow(10, pow);
    let roman_num = "";
    
    while (base_num > 0.1) {
      let mul = Math.floor(my_num / base_num);
  
      //console.log(mul);
      //console.log(base_num);
      //Only add the roman number if mul > 0
      if (mul !== 0) my_num -= mul * base_num;
  
  
      //Consider cases for concatenating roman numerals
      if (mul <= 3) {
        roman_num += get_roman_numeral(mul, base_num);
      }
      else if (mul === 4 || mul === 5) {
        roman_num += roman[mul * base_num];
      }
      else if (6 <= mul && mul <= 8) {
        roman_num += roman[5*base_num] + get_roman_numeral(mul -=5, base_num);
      }
      else if (mul === 9) {
        roman_num += roman[mul*base_num];
      }
  
      //console.log(my_num);
      base_num /= 10;
    }
    //console.log(roman_num);
    return roman_num;
  }
  
  convertToRoman(3999);