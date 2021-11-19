#A program to find the mean, mode and median 
#Inputs are the number of elements
#And space separated values
import functools
#Find the arithmetic mean
def mean(arr, num_elem):
  avg = functools.reduce(lambda x,y : x + y, arr) / num_elem
  print(avg)

#Find the median
#Sort, then fetch the middle elem.
#Even number of elements => take the mean of both middle values
#Odd number of elements => Easy
#This breaks if there are zero elements!
def median(arr, num_elem):
  if (num_elem & 1):
    print(arr[int(num_elem/2)])
  else:
    upper = int(num_elem/2)
    lower = upper - 1
    middle = (arr[upper] + arr[lower])/2
    print(middle)
  

#Find the mode
#After sorting, create a hash table that stores the quantity of numbers seen
#This will ensure the algorithm goes through the list only once
#since it is in ascending order 

def mode(arr):
  freq = {}
  #This stores the value of the highest frequency
  #By default, if all elements are unique, the mode is the smallest value
  highest_freq = arr[0]
  curr_count_freq = 0;
  for x in arr:
    #Search if the value exists in the hash table
    does_not_exist = True
    for a in freq:
      #increment the frequency of the value
      if (x == a):
        does_not_exist = False
        num_val = freq[x] + 1
        freq.update({x : num_val})
        if (curr_count_freq < num_val):
          curr_count_freq = num_val
          highest_freq = x
    #Add the value to the hash table if it wasn't found
    if (does_not_exist):
      freq.update({x : 1})
  
  #print the most frequent value.
  print(highest_freq)
    
    
  
  
#################################################################

# Enter your code here. Read input from STDIN. Print output to STDOUT
num_elem = int(input())

arr = input()
arr = arr.split(" ")


#Typecast each string into an integer
i = 0
for x in arr:
  arr[i] = int(x)
  i +=1

arr.sort()
  
mean(arr, num_elem)
median(arr, num_elem)
mode(arr)

















