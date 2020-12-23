import os
import os.path

#TODO:
#Replace all special characters with the desired character
#This program assumes that file has an extension name

#Check if the character is an alphabet
def isAlpha (s):
    if ( ('a' <= s and s <= 'z') or ('A' <= s and s <= 'Z')):
        return True
    else:
        return False

#Fetch the last dot
def lastFullStop (fileName):
    end = len(fileName) - 1
    while (end >= 0):
        if (fileName[end] == '.'):
            return end
        end -=1
    #did not find last dot
    #This may be a bug
    if (end == -1):
        return 0

def main():
    #Fetch the desired character
    print("Enter a desired character")
    myChar = input()

    if (len(myChar) != 1): 
        print("Must only enter one character")
        exit()


    #Get a directory from the user
    print("Enter a directory")
    myDir = input()

    dir = os.scandir(myDir)
    #A temporary string variable to form a list
    joinString = ""
    #Check for alphabet
    for file in dir:
        fileName = list(file.name)
        oldFileName = file.name
        #replace all non-alphabet characters
        i = 0
        #Find the index of the last dot
        while(i < len(fileName) and i < lastFullStop(fileName)):
            s = fileName[i]
            if (not isAlpha(s)):
                fileName[i] = myChar
            i +=1
        fileName = joinString.join(fileName)
        print(fileName)
        dirPath = os.getcwd() + "/" + myDir +  "/"
        os.renames(oldFileName, fileName)

    #Do not delete the extension name
    #save resources
    os.scandir(myDir)

#execute main down here
if __name__ == "__main__":
    main()

    
