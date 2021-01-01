
gene = "TCAGACTGGTGCCGTGGTGCTCTCGCCCGATGTGACGTCGACCGCCAGCGGCGCGATGACGCCGAGGATTTCCGTGATCGTTTCGGAGGGCACGCCGGCTGCGGTCAGCGCGTCGGCCAAGTGTCCGGCGACCAGGCTGAAGTGGTGCATGGTAATTCCGCGCCCCTGATGGACTTGCTTCATCGGCGCACCGGTATAGGGCTCGGGCCCGCCAAGCGCGGCCGCGAAAAACTCCACCTGCTTGCCCTTGAGGCGGCTCATGTTCGTACCGCTGAAGAAGGCCGATAGTTGGTCATCGGCAAGCACACGAACATAGAAGTCCTCGACGACGACTTCGATGGCCTCATGCCCGCCGATCTTGTCGTAGATGCTGATCGGCTCACGTTTGCGCAAGCGTGACAGTAGTCCCATTTTTATA"

#A function that finds the complement sequence of DNA. Assuming a template strand is used
def complement(seq):
    comp_seq=[]
    # Find complement sequence.
    for i in gene:
        if i == "A":
            comp_seq.append("T")
        elif i == "T":
            comp_seq.append("A")
        elif i == "G":
            comp_seq.append("C")
        elif i == "C":
            comp_seq.append("G")

    comp_seq.reverse()

    # Check if the strand is coding or template
    dna_string = ""
    dna_string = dna_string.join(comp_seq)
    
    if ( dna_string.find("TATAAA") == -1):
        print("The complement sequence is complementary strand")
        print("Enter the complementary strand")
        return 0
    else:
        print("The complement sequence is coding strand")
        #Replace T with U to get mRNA
        i = 0
        while i < len(comp_seq):
            if comp_seq[i] == "T":
                comp_seq[i] = "U"
            i +=1
    
    return comp_seq


print(complement(gene))