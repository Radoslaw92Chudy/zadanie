PROG=benchmark


__start__: obj ${PROG} 
	./${PROG}

obj:
	mkdir obj

${PROG}: obj/main.o obj/dane.o obj/algorytm.o
	g++ -Wall -o ${PROG} obj/main.o obj/dane.o obj/algorytm.o 

obj/main.o: inc/algorytm.h src/main.cpp 
	g++ -c -Wall -pedantic -Iinc -o obj/main.o src/main.cpp

obj/algorytm.o: inc/dane.h inc/algorytm.h inc/stos.h inc/kolejka.h src/algorytm.cpp
	g++ -c -Wall -pedantic -Iinc -o obj/algorytm.o src/algorytm.cpp

obj/dane.o: inc/dane.h src/dane.cpp
	g++ -c -Wall -pedantic -Iinc -o obj/dane.o src/dane.cpp


#^^^^^^^^^^                                 ^^^^^^^^^^^^^^^#
# Powyzje  jest miejsce na wlasne wpisy dla nowych modulow #
############################################################

clean:
	rm -f ${PROG} obj/*


