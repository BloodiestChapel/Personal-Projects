# Guessing game
# Create a random number between 1 & 99
# If user is below the number, let them know
# If user is above the number, let them know
# If user is correct, they win

import random

secretNumber = random.randint(1, 99)

# You only get 7 guesses
for guessesTaken in range(1, 7):

    # Begin for statement
    print('What number am I thinking of..?')
    guess = int(input())

    if guess < secretNumber:
        print('Too low. Try again.')

    elif guess > secretNumber:
        print('Too high. Try again.')

    else:
        break
    # End for statement

if guess == secretNumber:
    print('Correct. You won in ' + str(guessesTaken) + ' moves.')
else:
    print('You have failed. The number I was thinking of was ' + str(secretNumber))
    print('You were ' + str(secretNumber - guess) + ' away from the answer.')