
shoplist=['apple', 'mango', 'carrot', 'banana']

print('I have', len(shoplist), 'items to shopping:')

for item in shoplist:
    print(item, end=" ")
print()
shoplist.append('rice')
print("dding rice:")
for item in shoplist:
    print(item, end=" ")
print()
shoplist.sort()
print("sorted:")
for item in shoplist:
    print(item, end=" ")
print()
olditem=shoplist[0]

del shoplist[0]
print("del first:")
for item in shoplist:
    print(item, end=" ")
