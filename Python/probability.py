###Finds the mean for consecutive integers
def main():
    set = []
    print("Enter a max number")
    max_num = int(input())

    print("Start from 0? Y or N")
    include_zero = input()
    i = 0
    if (include_zero == 'Y') :
        i = 0
    else :
        i = 1
    
    while (i <= max_num):
        set.append(i)
        i +=1
    print(set)


    ###Finds the expected value
    expected_value = 0
    i = 0
    while i < len(set):
        expected_value += set[i]
        i +=1
    print("The expected value is", expected_value / len(set))

if __name__ == "__main__":
    main()