zoo = ('python', 'C', 'C++')

print("languages's numner in the zoo", len(zoo))

new_zoo = 'shell', 'asm', zoo

print("languages's number in the new zoo", len(new_zoo))

print("all languages in the new zoo are", new_zoo)

print("languages that from old are", new_zoo[2])

print("language that not familiar with is", new_zoo[2][2], "and learning is", new_zoo[2][0])
