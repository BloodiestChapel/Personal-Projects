def multOf(k, j):
    if k % j == 0:
        return True
    else:
        return False

number = 1

while (number <= 100):
    if multOf(number, 7) & multOf(number, 5):
        print("FizzBuzz")
        number += 1

    elif multOf(number, 5):
        print("Fizz")
        number += 1

    elif multOf(number, 7):
        print("Buzz")
        number += 1
    
    else:
        print(number)
        number += 1