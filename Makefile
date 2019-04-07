
GameOfLife: main.o arguments.o loading.o generation.o cell.o neighbourhood.o rules.o saving_txt.o saving_png.o
	gcc main.o arguments.o loading.o generation.o cell.o neighbourhood.o rules.o saving_txt.o saving_png.o -o GameOfLife -lpng

main.o: main.c
	gcc -c main.c -lpng

arguments.o: arguments.c arguments.h
	gcc -c arguments.c

loading.o: loading.c loading.h
	gcc -c loading.c

generation.o: generation.c generation.h
	gcc -c generation.c

cell.o: cell.c cell.h
	gcc -c cell.c

neighbourhood.o: neighbourhood.c neighbourhood.h
	gcc -c neighbourhood.c

rules.o: rules.c rules.h
	gcc -c rules.c

saving_txt.o: saving_txt.c saving_txt.h
	gcc -c saving_txt.c

saving_png.o: saving_png.c saving_png.h
	gcc -c saving_png.c -lpng

clean:
	rm *.o GameOfLife



