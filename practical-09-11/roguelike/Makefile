output: scroll.o skeleton.o zombie.o cell.o item.o elixir.o apple.o knife.o entity.o player.o arrow.o
	g++ scroll.o skeleton.o zombie.o cell.o item.o elixir.o apple.o knife.o entity.o player.o arrow.o -o output

zombie.o: zombie.cpp zombie.h
	g++ -c zombie.cpp

skeleton.o: skeleton.cpp skeleton.h
	g++ -c skeleton.cpp

scroll.o: scroll.cpp
	g++ -c scroll.cpp

cell.o: cell.cpp cell.h
	g++ -c cell.cpp

item.o: item.cpp item.h
	g++ -c item.cpp

elixir.o: elixir.cpp elixir.h
	g++ -c elixir.cpp

apple.o: apple.cpp apple.h
	g++ -c apple.cpp

knife.o: knife.cpp knife.h
	g++ -c knife.cpp

entity.o: entity.cpp entity.h
	g++ -c entity.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

arrow.o: arrow.cpp arrow.h
	g++ -c arrow.cpp

clean:
	rm *.o output
