
def total(a=5, *number, **phonebook):
    print('a=', a)

    for i in number:
        print('item in number is ', i)
    for i, j in phonebook.items():
        print('item in phonebook is ', i, '=', j)

    return a

print('return =', total(10, 1, 2, 3, jack=123, john=456, inge=789))
