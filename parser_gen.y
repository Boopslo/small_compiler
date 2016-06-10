%{
  #include "headers.h"
  void yyerror(const char *);
  extern int yylex(void);
  extern int yylineno;
  extern FILE *yyin;
%}

%union{
  std::vector <std::string> *code;
  std::string *letters;
}

%token INT CHAR DIGITS ID CHARS
%token RETURN IF ELSE WHILE BREAK PRINT READ SEMI COMMA

%type <code> Program DeclList _DeclList Decl VarDecl _VarDecl FunDecl VarDeclList ParamDeclList ParamDeclListTail _ParamDeclListTail ParamDecl _ParamDecl
%type <code> Block Type StmtList _StmtList Stmt Expr ExprIdTail ExprArrayTail _Expr ExprList ExprListTail _ExprListTail
%type <code> UnaryOp BinaryOp

%type <letters> DIGITS ID CHARS
%type <letters> INT CHAR
%type <letters> RETURN IF ELSE WHILE BREAK PRINT READ SEMI COMMA

%left PLUS MINUS NOT ASSIGN MULT DIVIDE EQ NE LT GT LE GE AND OR LP RP LB RB LS RS

%%

Program           : DeclList { printf("Program -> DeclList\n"); }
                  ;
DeclList          : _DeclList DeclList { printf("DeclList -> _DeclList DeclList\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
_DeclList         : Type ID Decl { printf("_DeclList -> Type ID Decl\n"); }
                  ;
Decl              : _VarDecl { printf("Decl -> _VarDecl\n"); }
                  | FunDecl { printf("Decl -> FunDecl\n"); }
                  ;
VarDecl           : Type ID _VarDecl { printf("VarDecl -> Type ID _VarDecl\n"); }
                  ;
_VarDecl          : SEMI { printf(";\n"); }
                  | LS DIGITS RS SEMI { printf("_VarDecl -> [ DIGITS ] ;\n"); }
                  ;
FunDecl           : LP ParamDeclList RP Block { printf("FunDecl -> ( ParamDeclList ) Block\n"); }
                  ;
VarDeclList       : VarDecl VarDeclList { printf("VarDeclList -> VarDecl VarDeclList\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
ParamDeclList     : ParamDeclListTail { printf("ParamDeclList -> ParamDeclListTail\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
ParamDeclListTail : ParamDecl _ParamDeclListTail { printf("ParamDeclListTail -> ParamDecl _ParamDeclListTail\n"); }
                  ;
_ParamDeclListTail: COMMA ParamDeclListTail { printf("_ParamDeclListTail -> , ParamDeclListTail\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
ParamDecl         : Type ID _ParamDecl { printf("ParamDecl -> Type ID _ParamDecl\n"); }
                  ;
_ParamDecl        : LS RS { printf("_ParamDecl -> []\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
Block             : LB VarDeclList StmtList RB { printf("Block -> { VarDeclList StmtList }\n"); }
                  ;
Type              : INT { printf("Type -> int\n"); }
                  | CHAR { printf("Type -> char\n"); }
                  ;
StmtList          : Stmt _StmtList { printf("StmtList -> Stmt _StmtList\n"); }
                  ;
_StmtList         : StmtList { printf("_StmtList -> StmtList\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
Stmt              : SEMI { printf("Stmt -> ;\n"); }
                  | Expr SEMI { printf("Stmt -> Expr ;\n"); }
                  | RETURN Expr SEMI { printf("Stmt -> return Expr ;\n"); }
                  | BREAK SEMI { printf("Stmt -> break ;\n"); }
                  | IF LP Expr RP Stmt ELSE Stmt { printf("Stmt -> if (Expr) Stmt else Stmt\n"); }
                  | WHILE LP Expr RP Stmt { printf("Stmt -> while (Expr) Stmt\n"); }
                  | Block { printf("Stmt -> Block\n"); }
                  | PRINT ID SEMI { printf("Stmt -> print ID ;\n"); }
                  | READ ID SEMI { printf("Stmt -> read ID ;\n"); }
                  ;
Expr              : UnaryOp Expr { printf("Expr -> UnaryOp Expr\n"); }
                  | DIGITS _Expr { printf("Expr -> DIGITS _Expr\n"); }
                  | LP Expr RP _Expr { printf("Expr -> (Expr) _Expr\n"); }
                  | ID ExprIdTail { printf("Expr -> ID ExprIdTail\n"); }
                  | CHARS _Expr { printf("Expr -> CHARS _Expr\n"); }
                  ;
ExprIdTail        : _Expr { printf("ExprIdTail -> _Expr\n"); }
                  | LP ExprList RP _Expr { printf("ExprIdTail -> (ExprList) _Expr\n"); }
                  | LS Expr RS ExprArrayTail { printf("ExprIdTail -> [Expr] ExprArrayTail\n"); }
                  | ASSIGN Expr { printf("Expr -> = Expr\n"); }
                  ;
ExprArrayTail     : _Expr { printf("ExprArrayTail -> _Expr\n"); }
                  | ASSIGN Expr { printf("ExprArrayTail -> = Expr\n"); }
                  ;
_Expr             : BinaryOp Expr { printf("_Expr -> BinaryOp Expr\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
ExprList          : ExprListTail { printf("ExprList -> ExprListTail\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
ExprListTail      : Expr _ExprListTail { printf("ExprListTail -> Expr _ExprListTail\n"); }
                  ;
_ExprListTail     : COMMA ExprListTail { printf("_ExprListTail -> , ExprListTail\n"); }
                  | /* epsilon */ { printf("\t"); }
                  ;
UnaryOp           : MINUS { printf(" - "); }
                  | NOT { printf(" ! "); }
                  ;
BinaryOp          : PLUS { printf(" + "); }
                  | MINUS { printf(" - "); }
                  | MULT { printf(" * "); }
                  | DIVIDE { printf(" / "); }
                  | EQ { printf(" == "); }
                  | NE { printf(" != "); }
                  | LT { printf(" < "); }
                  | LE { printf(" <= "); }
                  | GT { printf(" > "); }
                  | GE { printf(" >= "); }
                  | AND { printf(" && "); }
                  | OR { printf(" || "); }
                  ;

%%

void yyerror(const char *err) {
  cout << "line " << yylineno << ": " << err << endl;
}

int main(int argc, char *argv[]) {
  yyin = fopen(argv[1], "r");
  yyparse();
  fclose(yyin);
  return 0;
}
