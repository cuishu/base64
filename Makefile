example: example.o base64.o
	cc -o $@ $^

example.o: example.c base64.h
	cc -c -o $@ $<

base64.o: base64.c base64.h
	cc -c -o $@ $<

clean:
	rm *.o example
