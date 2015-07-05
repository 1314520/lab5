main5:main5.cpp lab5.h lab5.o
	g++ -o lab5 main5.cpp lab5.o

lab5.o:lab5.cpp lab5.h
	g++ -c lab5.cpp lab5.h



clean:
	rm -rf *.o
