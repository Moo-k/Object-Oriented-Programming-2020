output: soldier.o man.o specialist.o officer.o general.o main.o
	g++ soldier.o man.o specialist.o officer.o general.o main.o -o output

soldier.o: soldier.cpp soldier.h
	g++ -c soldier.cpp

man.o: man.cpp man.h
	g++ -c man.cpp

specialist.o: specialist.cpp specialist.h
	g++ -c specialist.cpp

officer.o: officer.cpp officer.h
	g++ -c officer.cpp

general.o: general.cpp general.h
	g++ -c general.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o output
