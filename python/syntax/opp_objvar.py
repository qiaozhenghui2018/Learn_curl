class robot:

    number = 0

    def __init__(self, name):

        self.name = name

        robot.number += 1

        print("creating reboot", self.name, "number is", robot.number)

    def say_hi(self):

        print(self.name, " say hi")

    def die(self):
        print(self.name, " will be destoryed")

        robot.number -= 1

        print("rm reboot", self.name, "number is", robot.number)

    @classmethod
    def howmany(cls):
        print("we have", robot.number, " robots")

r1 = robot('one')
r1.say_hi()

r2 = robot('two')
r2.say_hi()

robot.howmany()

r1.die()
r2.die()

robot.howmany()
