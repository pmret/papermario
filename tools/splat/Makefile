UTIL_DIR := util

default: all

all: Yay0decompress

Yay0decompress:
	gcc $(UTIL_DIR)/n64/Yay0decompress.c -fPIC -shared -O0 -o $(UTIL_DIR)/n64/Yay0decompress

clean:
	rm -f $(UTIL_DIR)/n64/Yay0decompress
