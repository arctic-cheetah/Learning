# Input sequence
test_sequence = "ACAACATACAAAGGGCCACAGATACATCAAAAAATGCTCAACATCACTATTTGTCAGGGAAGTACTAATTAAAACCAAAATGAGATGTCCCCTCAAACCTGTTAGAATGGCTATTATCAAAAAGATGAAAGATAGCAACTATCAGAGAGGATGATAGAAAAGGGAACCCTTGCATCATGTACAAATTAAAAATAGAACTATCACATGATCCAAGAATCCTACTTCTGGGTATATAGCCAAAGGAATTGAAATCAATATGTCAAAGGGATATCTGCACTCCTATGTTATTGCAGCATGTTCACAATGGCCAAGATATAGAATCAACCTAACTGTTCATAGACAGATGAATGGATAAATGAAATGTGATATGGAAAATTATTCAGCCTTAAAAACAGTAGGAAATTCTGTCATTTGAGACAACGTGGATGAACCTAGAGGACATTAAGCTAAGTGAAATAAGCTAGACACAGAAAGACAAATATTGCATGATCTCACTTAGAATCTAAAAAATCTGAACTCATAGAAGCAGAGAATAGTATGATGGTTACTAGGGTTATCTGGCAGGGAGAGGATGAGGAAATGGGACATTGTTAATAAAAGGAAAAAAATTCAATTAGTAGG"


def length(string):
    length = 0
    thymineCount = 0
    adenineCount = 0
    guanineCount = 0
    cytosineCount = 0
    for i in string:
        if i == "T":
            thymineCount +=1
        elif i == "A":
            adenineCount +=1
        elif i == "G":
            guanineCount +=1
        elif i == "C":
            cytosineCount +=1


        length +=1
    
    return [length, thymineCount, adenineCount, guanineCount, cytosineCount]

def print_dna_list(info):
    print("DNA length: %d" % info[0])
    print("Thymine: %d" % info[1])
    print("Adenine: %d" % info[2])
    print("Guanine: %d" % info[3])
    print("Cytosine: %d" % info[4])


# Print your result.
print_dna_list( length(test_sequence) )