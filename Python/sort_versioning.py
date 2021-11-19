#Given a list of version number (major.minor.revision) in strings
#The program will sort them in ascending order

#1)
#For each element in the list
#convert it to the Version data

#2)
#Design a class function to check whether the version is greater or smaller than 
#the current version
#Perform this check by comparing major, minor, rev

#3)
#Sort using a selection sort, in place. Perhaps improve afterward
#use a mapping from the list "ver"

#Constants
MISSING_NUM = "-1"

#########################################
#Functions:
def check_version(curr_elem):
    #Set any missing minor or rev to MISSING_NUM
    #Input is a list
    length = len(curr_elem)
    
    #Set minor and rev to -1
    if (length == 1):
        curr_elem.append(MISSING_NUM)
        curr_elem.append(MISSING_NUM)
    elif (length == 2):
        curr_elem.append(MISSING_NUM)

def version_is_greater(l, r):
    #Return true if the version on the left is greater than the right
    #Otherwise false
    #WARNING:
    #The same version number returns True

    #Check major
    if (l.major > r.major):
        return True
    elif (l.major < r.major):
        return False
    else:
        #Check minor
        if (l.minor > r.minor):
            return True
        elif (l.minor < r.minor):
            return False
        else:
            #Check revision
            if(l.rev > r.rev):
                return True
            elif(l.rev < r.rev):
                return False
            else:
                return True


class Version:
    #instantiate the object, with the strings, major, minor and revision
    def __init__(self, major, minor, rev):
        #Convert the major minor and rev into numbers
        self.major = int(major)
        self.minor = int(minor)
        self.rev = int(rev)
    
    #Print the version number
    def show_version(self):
        print("%i.%i.%i" % (self.major, self.minor, self.rev))


def solution(my_input):
    #1)
    #For each element in the list
    #convert it to the Version data
    #WARNING, input may omit minor or rev

    ver = []
    for i in my_input:
        #Split the string with delimiter "."
        curr_elem = i.split(".")
        #If minor or rev is missing. Set them to MISSING_NUM
        check_version(curr_elem)#Interesting, this a pass by reference

        #Append the version to the list
        ver.append(Version(curr_elem[0], curr_elem[1], curr_elem[2]))


    #3)
    #Sort using a insertion sort, in place. Perhaps improve afterward
    #use a mapping from the list "ver"
    arr_len = len(my_input)
    i = 0
    while i < (arr_len - 1):
        j = i + 1 
        while (j > 0 and version_is_greater(ver[j-1], ver[j])):
            #Swap
            temp_ver = ver[j-1]
            temp_list = my_input[j-1]

            ver[j-1] = ver[j]
            my_input[j-1] = my_input[j]

            my_input[j] = temp_list
            ver[j] = temp_ver
            j -=1

        i +=1

    return my_input


#Enter a list of version numbers
my_input = ["1.1.2", "1.0", "1.3.3", "1.0.12", "1.0.2"]
print(solution(my_input))
