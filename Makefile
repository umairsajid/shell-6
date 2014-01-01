# See http://stackoverflow.com/questions/3355298/unistd-h-and-c99-on-linux
# to understand why _XOPEN_SOURCE is set to 500

compile:
	gcc -std=c99 -Wall shell.c -o shell -lreadline -D_XOPEN_SOURCE=500
