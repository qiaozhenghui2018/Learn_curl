import sys
import os

print("the command line arguments are:")

for i in sys.argv:
    print(i)

print("the python PATH is", sys.path)

print("the current work dir is", os.getcwd())

print(os.__doc__)
print(sys.__doc__)