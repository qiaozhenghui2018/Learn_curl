HOME := $(pwd)

Object := NumberToBinary.o

#Source := *.c

Include := Environment.h

vpath %.c $(HOME)/Source
vpath %.h $(HOME)/Source

Target : $(Object)
	cc -o Target $(Object)

$(Object): NumberToBinary.c $(Include)
	cc -c NumberToBinary.c


clean : 
	rm Target $(Object)
