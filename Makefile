CC = cc -Wall -c -o
LD = cc -Wall -o
 
example: example.o base64.o
	$(LD) $@ $^

example.o: example.c base64.h
	$(CC) $@ $<

base64.o: base64.c base64.h
	$(CC) $@ $<

clean:
	rm *.o example
