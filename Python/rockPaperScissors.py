#A game to play rock paper scissors
import random

def main():
    print("Welcome to a game of rock, paper or scissors")
    endGame = False

    while (not endGame):
        randomInt = random.randint(-0xffff, 0xffff)
        answer = ""
        if (randomInt % 3 == 0):
            answer = "rock"
        elif (randomInt % 3 == 1):
            answer = "paper"
        else:
            answer = "scissors"

        print("Enter:")
        print("Rock")
        print("Paper")
        print("Scissors")
        print("")

        userInput = input()
        userInput = userInput.lower()
        print("You entered: " + userInput)
        if (userInput == answer):
            print("Draw!")
            endGame = False
        elif (userInput == "rock" and answer == "scissors"):
            print("You win!")
            endGame = True
        elif (userInput == "rock" and answer == "paper"):
            print("You Lose!")
            endGame = True
        elif (userInput == "paper" and answer == "scissors"):
            print("You Lose!")
            endGame = True
        elif (userInput == "paper" and answer == "rock"):
            print("You Win!")
            endGame = True
        elif (userInput == "scissors" and answer == "rock"):
            print("You Lose!")
            endGame = True
        elif (userInput == "scissors" and answer == "paper"):
            print("You Win!")
            endGame = True
        
        print("")
        print("The computer guessed " + answer + 
                " and you guessed " + userInput)


#run main
if __name__ == "__main__":
    main()
