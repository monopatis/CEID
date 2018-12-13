%{
#include <stdio.h>
#include <stdlib.h>
#include "2012.tab.h"

#define YYSTYPE char const *

extern int line_no;
extern char txt;
extern char *line;
void ERROR(const char msg[]);

%}

%%
\n.* { /* Prin kanoyme otidhpote swzoyme thn trexoysa grammh keimenoy, gia ta mhnymata lathoys */
  if (line != NULL)
    free(line);
  line = strdup(yytext);
  ++line_no; /* Gia na kseroyme se poia grammh eimaste. */
  yyless(1); /* Stelnoyme pisw sto lex ola ektos toy /n */
}
"program" {return PROGRAM;}
";" {return SEM;}
"var" {return VAR;}
"integer" {return INTT;}
"boolean" {return BOO;}
"procedure" {return PROCEDURE;}
"function" {return FUN;}
"if" {return IFF;}
"then" {return THENN;}
"else" {return ELSEE;}
"while" {return WHILEE;}
"do" {return DOO;}
"begin" {return BEGINN;}
"end" {return ENDD;}
":=" {return ASS;}
":" {return PANKAT;}
"." {return FSTOP;}
"," {return COMMA;}
"(" {return LPAR;}
")" {return RPAR;}

"and" {return ANDD;}
"or" {return ORR;}
"not" {return NOTT;}

"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MULT;}
"div" {return DIVV;}
"mod" {return MODD;}
"=" {return EQUAL;}
"<>" {return DIFF;}
"<" {return SM;}
">" {return BIG;}
"<=" {return SMEQ;}
">=" {return BEQ;}
[0-9]+  {return NUMBER;}
[a-zA-Z][a-zA-Z0-9]*  {return ID;}
%%

int yywrap(void) {return 1;}
