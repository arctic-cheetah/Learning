
function truthCheck(collection, pre) {
    //Go through each element in the collection
    for (let i = 0; i < collection.length; i +=1) {
      if(Boolean(collection[i][pre]) == false) return false;
    }
    //Return false if there exists an element that does not contain pre
    return true;
  }
  
  console.log(truthCheck([{"name": "Pete", "onBoat": true}, {"name": "Repeat", "onBoat": true, "alias": "Repete"}, {"name": "FastForward", "onBoat": true}], "onBoat"));