%{
  #include <string>
  #include <vector>
  using namespace std;
  #include "parser_gen.tab.h"
  int yyerror(char *s);
%}

DIGITS    [0-9]+
LETTERS   [a-xA-Z]+
ID        id[A-Z][a-z]*
CHARS     \".+\"
COMMENTS  \/\/.*

%%

[ \t]+      { /*ignore whitespace */ }
\n          { /* printf("NEWLINE\n"); */ yylineno++; }
int         { yylval.letters = new string(yytext); return INT; }
char        { yylval.letters = new string(yytext); return CHAR; }
return      { yylval.letters = new string(yytext); return RETURN; }
if          { yylval.letters = new string(yytext); return IF; }
else        { yylval.letters = new string(yytext); return ELSE; }
while       { yylval.letters = new string(yytext); return WHILE; }
break       { yylval.letters = new string(yytext); return BREAK; }
print       { yylval.letters = new string(yytext); return PRINT; }
read        { yylval.letters = new string(yytext); return READ; }

"+"         { /* printf("PLUS: %s\n", yytext); */ yylval.letters = new string(yytext); return PLUS; }
"-"         { /* printf("MINUS: %s\n", yytext); */ yylval.letters = new string(yytext); return MINUS; }
"!"         { /* printf("NOT: %s\n", yytext); */ yylval.letters = new string(yytext); return NOT; }
"="         { /* printf("ASSIGN: %s\n", yytext); */ yylval.letters = new string(yytext); return ASSIGN; }
"*"         { /* printf("MULTIPLY: %s\n", yytext); */ yylval.letters = new string(yytext); return MULT; }
"/"         { /* printf("DIVIDE: %s\n", yytext); */ yylval.letters = new string(yytext); return DIVIDE; }
"=="        { /* printf("EQ: %s\n", yytext); */ yylval.letters = new string(yytext); return EQ; }
"!="        { /* printf("NE: %s\n", yytext); */ yylval.letters = new string(yytext); return NE; }
"<"         { /* printf("LT: %s\n", yytext); */ yylval.letters = new string(yytext); return LT; }
"<="        { /* printf("LE: %s\n", yytext); */ yylval.letters = new string(yytext); return LE; }
">"         { /* printf("GT: %s\n", yytext); */ yylval.letters = new string(yytext); return GT; }
">="        { /* printf("GE: %s\n", yytext); */ yylval.letters = new string(yytext); return GE; }
"&&"        { /* printf("AND: %s\n", yytext); */ yylval.letters = new string(yytext); return AND; }
"||"        { /* printf("OR: %s\n", yytext); */ yylval.letters = new string(yytext); return OR; }
"("         { /* left parenthesis */ /* printf("LP: %s\n", yytext); */ yylval.letters = new string(yytext); return LP; }
")"         { /* printf("RP: %s\n", yytext); */ yylval.letters = new string(yytext); return RP; }
"{"         { /* left bracket */ /* printf("LB: %s\n", yytext); */ yylval.letters = new string(yytext); return LB; }
"}"         { /* printf("RB: %s\n", yytext); */ yylval.letters = new string(yytext); return RB; }
"["         { /* left square bracket */ /* printf("LS: %s\n", yytext); */ yylval.letters = new string(yytext); return LS; }
"]"         { /* printf("RS: %s\n", yytext); */ yylval.letters = new string(yytext); return RS; }
";"         { /* printf("SEMICOLON: %s\n", yytext); */ yylval.letters = new string(yytext); return SEMI; }
","         { /* printf("COMMA: %s\n", yytext); */ yylval.letters = new string(yytext); return COMMA; }
{ID}        { /* id */ /* printf("ID: %s\n", yytext); */ yylval.letters = new string(yytext); return ID; }
{CHARS}     { /* characters */ /* printf("CHARS: %s\n", yytext); */ yylval.letters = new string(yytext); return CHARS; }
{COMMENTS}  { /* do nothing */ }
{DIGITS}    { /* printf("DIGITS: %s\n", yytext);*/ yylval.letters = new string(yytext); yylval.letters = new string(yytext); return DIGITS; }
.           { yylval.letters = new string(yytext); return yytext[0]; }
%%

int yywrap(void) {
  return 1;
}
