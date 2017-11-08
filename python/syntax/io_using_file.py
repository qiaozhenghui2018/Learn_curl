

txt = '''adbc \ 
1 
2
3
4
5
6'''
f = open(r'D:\python\test.txt', 'w')

f.write(txt)

f.close()

f = open(r'D:\python\test.txt', 'r')

while True:
    line = f.readline()

    if len(line) == 0:
        break

    print(line, end='')

f.close()