all: bison flex gcc
bison: 2012.y
	bison -d 2012.y
flex: 2012.l
	flex 2012.l
gcc: 2012.tab.c 2012.tab.h lex.yy.c
	gcc 2012.tab.c lex.yy.c -o myParser.exe
clean:
	rm -f 2012.tab.c 2012.tab.h lex.yy.c myParser.exe output
