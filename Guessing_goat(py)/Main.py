import random
from Words import Word

while 1:

    max_num = int(input("\nChoose how much word you want to play with(2-30):"))
    min_num = 1
    random_num = (random.randint(min_num, max_num))
    w = Word(random_num,max_num)
    w.pri()
    guess_word = input("\n\nEnter your word:")

    i=0
    while guess_word != w.the_word():

        print("\nyour word is wrong")
        i= i+1
        print("\nDo you want to know the word and Quite??")
        c=input('Enter your choice (yes/no):')
        if c == 'yes' or c == 'Yes' or c =='YES':

            print(w.the_word())
            i = max_num
            break
        print("-------------------------------------------")
        guess_word = input("\n\nEnter another word again:")

    print('Your point is = '+str(max_num-i))
    print("\n\n Want to play again??")
    c = input('Enter your choice (yes/no):')
    if c == 'No' or c == 'no' or c == 'NO':
       break
