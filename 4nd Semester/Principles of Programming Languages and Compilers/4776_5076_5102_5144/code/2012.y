%{
	
	/*kathe stoixeio 8a einai sindedemeno ena char*/
	#define YYSTYPE char const*

 	 
        #include <stdio.h>
        #include <ctype.h>
	int j=0;
	int ag=0;
	int i;
	char * line = NULL;
	int line_no = 1;
	char txt;
	void yyerror(char const*);
	extern char *yytext;
	extern int yylex();
	FILE *yyin, *yyout;

/* Posa sfalmata eginan */
int errors = 0;

%}

%token PROGRAM
%token SEM
%token VAR
%token INTT
%token BOO
%token PROCEDURE
%token FUN
%token IFF
%token THENN
%token ELSEE
%token WHILEE
%token DOO
%token BEGINN
%token ENDD
%token ASS
%token PANKAT
%token FSTOP
%token COMMA
%token LPAR
%token RPAR
%token ANDD
%token ORR
%token NOTT
%token PLUS
%token MINUS
%token MULT
%token DIVV
%token MODD
%token EQUAL
%token DIFF
%token SM
%token BIG
%token SMEQ
%token BEQ
%token ID
%token NUMBER




%% 

/*grammar rules*/
prog: PROGRAM id sem block FSTOP;
block: K compoundstatement;
K: localdefinition K | ;
localdefinition: variabledefinition | proceduredefinition |
functiondefinition ;
variabledefinition: VAR L ;
L: defsomevariables sem L |;
defsomevariables: id M PANKAT datatype;
M: COMMA id M | ;
proceduredefinition: procedureheader block sem;
procedureheader: PROCEDURE id formalparameters sem;
functiondefinition: functionheader block sem;
functionheader: FUN ID formalparameters PANKAT datatype sem;
formalparameters: LPAR formalparameter N RPAR | ;
N: sem formalparameter N | ;
formalparameter: id M PANKAT datatype;
datatype: INTT | BOO;
statement: assignment | ifstatement | whilestatement | procfunccall | compoundstatement;
assignment: id ASS expression ;
ifstatement: IFF expression THENN statement P;
P: ELSEE statement | ;
whilestatement: WHILEE expression DOO statement;
procfunccall: id LPAR actualparameters RPAR ;
actualparameters: expression R |;
R: COMMA expression R | ;
compoundstatement: BEGINN statement S ENDD ;
S:  sem statement S | ;
expression: unaryoperation expression A | procfunccall A | LPAR expression RPAR A | NUMBER A | id A ;
A: binaryoperation A expression | ;
binaryoperation: EQUAL | DIFF | ORR | ANDD | SM | BIG | BEQ | SMEQ | PLUS | MINUS | MULT | DIVV | MODD ;
unaryoperation: PLUS | MINUS | NOTT ;
sem: SEM ;
id: ID ;

%%
int main(int argc, char **argv){
	//elegxoume an exoume 2o orisma, dld an dothike onoma arxeiou buz
	if(argc==2)
		yyin = fopen( argv[1], "r" );
	else
		yyin = stdin;
	yyout = fopen ( "output", "w" );
	yyparse ();
	if(errors==0)
	    printf("Den yphrxe lathos sto arxeio: %s.\n", argv[1]);
	return 0;
}

void yyerror(char const *s)          
{
  printf("line: %d, %s\n", line_no, s);
  printf("%s\n", line);
  errors++;
}
