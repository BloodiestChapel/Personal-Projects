# This is a standard HelloWorld program.
# It is meant for practice.

import datetime

print('Hello World!')
print('What is your name?')

myName = input()
myNameLen = len(myName)

print('It is good to meet you, ' + myName)
print('Your name is ' + str(myNameLen) + ' characters long.')


print('What is your age?')

date = datetime.datetime.now()
myAge = input()
birthYear = int(date.year) - int(myAge) - 1

print('You were born, at least, in ' + str(birthYear))