import math
#Check if a number is prime by searching for all numbers
#up to sqrt(n), if they divide into  val
def is_prime(val):
    #A prime is a number that is only divisible by one and itself
    i = 2.0
    while (i <= math.sqrt(val)):
        if (val % i  == 0):
            return False
        i +=1
    return True


def main():
    print("Enter the first number:")
    val1 = int(input())
    print("Enter the second number:")
    val2 = int(input())

    #Need to check if both numbers are prime
    if (is_prime(val1) and is_prime(val2)):
        print("gcd({val1},{val2}) = 1".format(val1=val1, val2=val2))
    #find the greater number, to divide the larger number
    else:
        max = 0
        i = 0
        if (val1 > val2):
            max = val1
            i = val2
        else:
            max = val2
            i = val1
        #Use the euclidean algorithm to find the gcd
        prev = 0
        while ((max % i)):
            #exit out of the loop is prev is the same as i.
            #This means the numbers are coprime
            if (prev == i):
                i = 1
                break
            prev = i
            i %=max
            

        print("gcd({val1},{val2}) = {num}".format(val1=val1, val2=val2, num=i))

if __name__ == "__main__":
    main()