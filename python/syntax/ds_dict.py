email = {
    'joe':'joe@163.com',
    'qiao':'qiao@163.com',
    'hua':'hua@163.com'
}

print("joe's email is", email['joe'])

print("email number is ", len(email))

email.__delitem__('hua')

print("email number is ", len(email))

email['qiaozhenghui'] = 'qiaozhenghui@163.com'

print("email number is ", len(email))

if email.__contains__('joe'):
    print(email['joe'])
else:
    print("joe is not in email")

if email.__contains__('hua'):
    print(email['hua'])
else:
    print("hua is not in email")

print("all items in email dict:")
for name, address in email.items():
    print("{}'s email is {}".format(name, address))

print("ending")