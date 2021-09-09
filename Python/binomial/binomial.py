#A program that prints the binomial triangle
#By indexing the row and column
#A tuple that represents the combinations and a dictionary can be used

binom = {}
def binom_triangle():
    for i in range(0, 1000):
        for j in range(0, i+1):
            if (j == 0 or j == i):
                binom[(i, j)] = 1
            else:
                binom[(i,j)] = binom[(i-1, j)] + binom[(i-1, j-1)]

#Now to calculate the probability

def calculate_probability(p, k):
    probs = 0
    for x in range(0, k):
        probs += binom[(x + k - 1, k-1)] * (1-p)**x
    probs *= (p**k)
    return probs


def main():
    #print all the data sets into a file
    print("Caluclating!")
    binom_triangle()
    f = open("binom_data.csv", "w")
    f.write("probability_of_a_match,number_of_rounds,probability_of_win\n")
    for probs_win in range(1, 100+1):
        for i in range(1, 100+1):
            curr_prob = calculate_probability(probs_win/100, i)
            data = "{},{},{}\n".format(probs_win/100, i, curr_prob)
            f.write(data)

    f.close()


if __name__ == "__main__":
    main()