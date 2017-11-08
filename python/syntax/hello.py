# print("hello world")

# age = 24

# print("{0} is {1} years old when he start to learn python".format(name, age))
# print("{0} is learning python now".format(name))

# print("{} is {} years old when he start to learn python".format(name, age))
# print("{} is learning python now".format(name))

# print('a', end=';')
# print('b', end='-')
# print('c', end=']')

# print('\nwhat\'s your name? \" \\')

# print(r"newlines is indicated by \n")

# num = 24
# num_in = int(input('input the judge number:'))

# if num == num_in :
#    print("num={} equals num_in={}".format(num, num_in))
# elif num < num_in :
#    print("num={} behinds num_in={}".format(num, num_in))
# else:
#    print("num={} is larger than num_in={}".format(num, num_in))

flag = True
while flag:
    age = int(input("input your age:"))
    if age == 24:
        flag = False
    else:
        continue
else:
    print("exit the while")
print("ending")


def function(a, b):
    """this function return a-b"""
    return a - b


print(function.__doc__)
print("5-6={}".format(int(function(5, 6))))
