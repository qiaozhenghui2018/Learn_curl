import pickle

storeinfo = r'D:\python\storeinfo'
shoplist = ['apple', 'branana', 'orange']

f = open(storeinfo, 'wb')

pickle.dump(shoplist, f)

f.close()

del shoplist

f = open(storeinfo, 'rb')
shoplist_new = pickle.load(f)

print("new shoplist is", shoplist_new)
