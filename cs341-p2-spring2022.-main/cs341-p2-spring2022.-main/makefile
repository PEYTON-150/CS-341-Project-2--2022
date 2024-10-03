
bruh2: driver.cpp card.o standarddeck.o nonstandarddeck.o deck.o
		g++ -o bruh2 driver.cpp card.o standarddeck.o deck.o nonstandarddeck.o

bruh: simplifiedwardriver.cpp card.o standarddeck.o nonstandarddeck.o deck.o
	g++ -o bruh simplifiedwardriver.cpp card.o standarddeck.o deck.o nonstandarddeck.o

standarddeck.o: card.o standarddeck.h deck.o
		g++ -c standarddeck.cpp card.o

nonstandarddeck.o: card.o nonstandarddeck.h deck.o
				g++ -c nonstandarddeck.cpp card.o

card.o: card.cpp card.h
	g++ -c card.cpp

deck.o: deck.cpp deck.h
	g++ -c deck.cpp

clean:
	rm -rf *.o bruh
	rm -rf *.o bruh2
