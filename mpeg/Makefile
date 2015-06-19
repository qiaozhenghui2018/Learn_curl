
TARGET=ts_read
PRJPATH=./

CFLAGS=-I $(PRJPATH)/include

SOURCE=$(PRJPATH)/src/*.c

TARGET:$(SOURCE)
	gcc $(CFLAGS) $(SOURCE) -o $(TARGET)

clean:
	-rm -f $(TARGET)
	-rm -f *.log
