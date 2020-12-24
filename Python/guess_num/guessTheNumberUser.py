import random
import time
import sys

#Ask if the user wants a hint
def getUserHint():
    print("Would you like hints? Y or N")
    prompt = input()

    if (prompt == 'Y'):
        return True

    #Perform error checking
    elif(prompt == 'N'):
        return False
    else:
        print("Please enter Y or N")
        return getUserHint()

def getNumUser():
    print("Enter a random number:")
    return input()

def main():

    print("Welcome user!")
    isHint = getUserHint()

    #Fetch a random number from the user
    myRandomInt = int(getNumUser())

    isCorrect = False
    while (not isCorrect):
        print("Enter an integer")
        try:
            num = input()
            num = int(num)
            if (num == myRandomInt):
                isCorrect = True
                print("Success! You win")
                exit()
            else:
                print("Incorrect, try again")
                print("")
            
            if(isHint):
                #check if the number is higher or lower
                if((num - myRandomInt) <= 10):
                    print("Very Close!")
                elif((num - myRandomInt) <= 30):
                    print("Close!")
                elif (num > myRandomInt):
                    print("Guess Lower")
                else:
                    print("Guess Higher")
        except:
            print(sys.exc_info())
            print("The number was ", myRandomInt)
            exit()


if __name__ == "__main__":
    main()

