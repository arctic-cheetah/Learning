#A program to play hang man
import random
import wordList

#Initialises the beginning word
def initWord (wordLen):
    i = 0
    wordList = [None] * wordLen
    while (i < wordLen):
        wordList[i] = "_"
        i +=1
    return wordList

#Check for duplicate characters
def charCheck (guessWord, word, char):
    i = 0
    while (i < len(guessWord)):
        if (word[i] == char):
            guessWord[i] = char
        i +=1
    return guessWord

#Check if the user has completed the word
def hasCompletedWord (guessWord):
    i = 0
    while (i < len(guessWord)):
        if (guessWord[i] == "_"):
            return False
        i +=1
    return True

def showTrainMan (attempt):
    
    if (attempt == 0):
        print("__ __ __ __ __ You")
    elif (attempt == 1):
        print("## __ __ __ __ You")
    elif (attempt == 2):
        print("## ## __ __ __ You")
    elif (attempt == 3):
        print("## ## ## __ __ You")
    elif (attempt == 4):
        print("## ## ## ## __ You")
    elif (attempt == 5):
        print("## ## ## ## ## You")
    print("")
    

def main():
    #Ensure the random number is in the correct range
    myNum = random.randint(0, 0xffff)
    myNum = myNum % len(wordList.words)

    word = wordList.words[myNum]
    wordLen = len(word)
    guessWord = initWord(wordLen)

    print(guessWord)
    print("")

    #Number of attempts = 5
    attempt = 0
    win = False
    while (attempt <= 5):
        print("Enter a character: ", end = "")
        char = input()
        #May need to check that user entered correct data
        position = word.find(char)

        if (position != -1):
            #check for duplicate characters
            guessWord = charCheck(guessWord, word, char)
        else:
            attempt +=1
        
        print(guessWord)
        print("")

        #Check if all the characters have been revealed
        win = hasCompletedWord(guessWord)
        if (win):
            break
        showTrainMan(attempt)

    if (win):
        print("You win!")
    else:
        print("You lost!")

    print("The word was " + word)





if __name__ == "__main__":
    main()



