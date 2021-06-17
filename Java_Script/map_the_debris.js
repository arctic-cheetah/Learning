function orbitalPeriod(arr) {
    var GM = 398600.4418;
    var earthRadius = 6367.4447;
    let return_arr = [];
    for (let i = 0; i < arr.length; i+=1) {
      let orbital_period = Math.round(2.0 * Math.PI * 
                         Math.pow(earthRadius + arr[i]["avgAlt"], 1.5) 
                         / Math.sqrt(GM));
      return_arr.push({name : arr[i]["name"], orbitalPeriod : orbital_period});
    }
    
    
    return return_arr;
  }
  
  console.log(orbitalPeriod([{name : "sputnik", avgAlt : 35873.5553}]));
  console.log(orbitalPeriod([{name: "iss", avgAlt: 413.6}, {name: "hubble", avgAlt: 556.7}, {name: "moon", avgAlt: 378632.553}]));