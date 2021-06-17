//A very bad cash register

let currency = {
    "ONE HUNDRED" : 100.0,
    "TWENTY"      : 20.0,
    "TEN"         : 10.0,
    "FIVE"        : 5.0,
    "ONE"         : 1.0,
    "QUARTER"     : 0.25,
    "DIME"        : 0.1,
    "NICKEL"      : 0.05,
    "PENNY"       : 0.01,
  }
  
  //Check if the cid is empty and should be closed
  function is_cash_id_empty(cid) {
    for (let i = 0; i < cid.length; i +=1) {
      if (cid[i][1] !== 0) {
        return false;
      }
    }
    return true;
  }
  
  function checkCashRegister(price, cash, cid) {
    
    //Find the change required.
    let change = cash - price;
    let return_change = {status : "", change : []};
    //Separate the change into tens of dollars, dollars and tens of cents then cents
  
    let j = cid.length - 1;
    //Start from the larget unit of currency, and go downwards.
    for (let i in currency) {
      let quantity_int;
      //Need to account for approximation errors.
      if (i === "PENNY") {
        quantity_int = Math.ceil(change / currency[i]);
      }
      else {
        quantity_int = Math.floor(change / currency[i]);  
      }
      
      //Need to return integers 
      if (quantity_int > 0) {
        console.log(quantity_int);
        //Find the possible quantity of unit of currency 
        //that can needed to provide that change
        let physical_change = cid[j][1] / currency[i];
        physical_change = physical_change > quantity_int ? quantity_int : physical_change;
        if (physical_change != 0) {
          cid[j][1] -= physical_change * currency[i];
          return_change.change.push( [i ,(physical_change * currency[i])] );
          change -= physical_change * currency[i];
        }
        
      }
      //Count down
      j -=1;
    }
    
    //Round down approximation errors
    if (change < 1E-4) {
      change = 0;
    }
    
    
    //Check that the CID contains the cash
    if (change !== 0) {
      console.log(return_change);
      return {status: "INSUFFICIENT_FUNDS", change: []};
    }
    //If CID is not zero, then return the change
    if (is_cash_id_empty(cid) === false) {
      return_change.status = "OPEN";
      console.log(return_change);
      return return_change;
    }
    //If closed at other currency units higher than it
    return_change.status = "CLOSED";
    for (let i = 0; i < return_change.change.length; i +=1) {
      if (return_change.change[i][1] > 0) {
        cid[i][1] = return_change.change[i][1];
      }
    }
    return_change.change = cid;
    console.log(return_change);
    return return_change;
  }
  /*
  checkCashRegister(19.5, 20, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]]);
  
  checkCashRegister(3.26, 100, [["PENNY", 1.01], ["NICKEL", 2.05], ["DIME", 3.1], ["QUARTER", 4.25], ["ONE", 90], ["FIVE", 55], ["TEN", 20], ["TWENTY", 60], ["ONE HUNDRED", 100]])
  */
  checkCashRegister(19.5, 20, [["PENNY", 0.5], ["NICKEL", 0], ["DIME", 0], ["QUARTER", 0], ["ONE", 0], ["FIVE", 0], ["TEN", 0], ["TWENTY", 0], ["ONE HUNDRED", 0]])