function titleCase(str) {
    return str.toLowerCase().replace(/(^|\s)\S/g, (c) => c.toUpperCase());
}
  
console.log(titleCase("I'm a little tea pot"));