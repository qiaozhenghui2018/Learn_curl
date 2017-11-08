class persson:

    def __init__(self, name):
        print("persson initing...")
        self.name = name

    def say_hi(self):
        print("hello, this is my first class")

    a = 36

p = persson('joe')

p.say_hi()

print("p.name=", p.name)