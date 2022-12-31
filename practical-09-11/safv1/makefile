output: main.o soldier.o man.o specialist.o officer.o general.o
	g++ main.o soldier.o man.o specialist.o officer.o general.o -o output

main.o: main.cpp
	g++ -c main.cpp

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

clean:
	rm *.o output
