function pairElement(str) {
    let dna_pair = [...str];
    for (let i = 0; i < str.length; i +=1) {
      dna_pair[i] = Array.from(dna_pair[i]); 
      
      if (dna_pair[i][0] === 'A') {
        dna_pair[i].push('T');
      }
      else if (dna_pair[i][0] === 'T') {
        dna_pair[i].push('A');
      }
      else if (dna_pair[i][0] === 'G') {
        dna_pair[i].push('C');
      }
      else if (dna_pair[i][0] === 'C') {
        dna_pair[i].push('G');
      }
    }
    return dna_pair;
  }
  
  console.log(pairElement("ATG"));