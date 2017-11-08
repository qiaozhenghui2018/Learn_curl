
x = 50
y = 50
print("x is ", x, "y is ", y)
def function():
    global x
    x = 20
    y = 20
    print("change x=", x, "y=", y)

function()

print("x is ", x, "y is ", y)