playpal2rgb: playpal2rgb.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -vf *.o playpal2rgb
