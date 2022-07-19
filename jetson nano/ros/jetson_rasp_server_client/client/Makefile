CC:=gcc

TARGET=client

OBJECT=$(TARGET).o 

LDFLAGS=-D_REENTRANT -pthread


$(TARGET):$(OBJECT)
	$(CC) -o $@ $(OBJECT) $(LDFLAGS)


%.o:%.c
	$(CC) -c -o $@ $<

clean:
	rm -f *.o $(TARGET)
