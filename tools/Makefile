default: all

all: Yay0compress
	make -C n64splat

Yay0compress:
	gcc Yay0compress.c -O3 -o Yay0compress

clean:
	rm -f Yay0compress
	make clean -C n64splat
