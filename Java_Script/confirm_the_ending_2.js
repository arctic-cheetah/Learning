//A function to check whether the target string 
//Is located at the end of the source string
//Using Regex
function confirmEnding(str, target) {
    let regex = new RegExp(target + "$", "g");
    return regex.test(str);
}
  
console.log(confirmEnding("Connor", "onnor"));