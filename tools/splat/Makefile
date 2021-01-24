UTIL_DIR := util

default: all

all: Yay0decompress

Yay0decompress:
	gcc $(UTIL_DIR)/Yay0decompress.c -fPIC -shared -O3 -o $(UTIL_DIR)/Yay0decompress

clean:
	rm -f $(UTIL_DIR)/Yay0decompress
