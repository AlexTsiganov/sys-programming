binary: lab5static.a
	gcc -g lab5testLib.c lab5static.so
	export LD_LIBRARY_PATH=/home/alex/Dropbox/политех/Системное\ программирование/Л.\ р.\ №\ 5/Linux:$LD_LIBRARY_PATH

lab5static.a: lab5static.o 
	gcc -shared -o lab5static.so lab5static.o

lab5static.o: lab5static.c
	gcc -c -g -fPIC lab5static.c

clean:
	rm -f *.o *.a binary 
