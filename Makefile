run: main
	./main

main: base64.c base64.h main.c
	gcc *c -o main

clean:
	rm main
