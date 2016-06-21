%{
  #include "headers.h"
  void yyerror(const char *);
  extern int yylex(void);
  extern int yylineno;
  extern FILE *yyin;
  fstream fp;
  vector<string> *code_section;
  vector<string> *save_section;
  string *op_ptr;
  string *temp_ptr;
  string *reg_ptr;
  vector<string> op_stack;
  string tempreg;
  map<string, attribute> *temp_var;
  int stack_top = 0;
  /* vector to print out */
  vector<string> instruction, code_expr;
  vector<string>:: iterator it;
  string kindOfOperator;
  int parameter_count = 0;
%}

%union{
  vector<string> *code;
  string *letters;
}

%token INT CHAR DIGITS ID CHARS
%token RETURN IF ELSE WHILE BREAK PRINT READ SEMI COMMA

%type <code> Program DeclList _DeclList Decl VarDecl _VarDecl FunDecl VarDeclList ParamDeclList ParamDeclListTail ParamDecl
%type <code> Block StmtList Stmt ExprList ExprIdTail ExprArrayTail _StmtList ExprListTail _ExprListTail
%type <letters> Type BinaryOp Expr _Expr

%type <letters> DIGITS ID CHARS
%type <letters> INT CHAR
%type <letters> RETURN IF ELSE WHILE BREAK PRINT READ SEMI COMMA

%left <letters> PLUS MINUS NOT ASSIGN MULT DIVIDE EQ NE LT GT LE GE AND OR LP RP LB RB LS RS NEG

%%

Program : DeclList {
            printf("Program -> DeclList\n");
            // it = instruction.end();
            // add to end of stack
            // instruction.insert(it, instruction.begin(), instruction.end());
          }
        ;

DeclList : _DeclList DeclList {
              printf("DeclList -> _DeclList DeclList\n");
              // it = instruction.end();
              // instruction.insert(it, $1->begin(), $1->end());
           }
         | /* epsilon */ {}
         ;

_DeclList : Type ID Decl {
              printf("_DeclList -> Type ID Decl\n");
              /*stack_top += 4;
              addToScope(*$2, stack_top);*/
            }
          ;

Decl : _VarDecl {
          printf("Decl -> _VarDecl\n");
       }
     | FunDecl {
          printf("Decl -> FunDecl\n");
       }
     ;

VarDecl : Type ID _VarDecl {
            printf("VarDecl -> Type ID ;\n");
            /*stack_top += 4;
            addToScope(*$2, stack_top);*/
            // keep track of the attributes of the var
            /* createId(name, type, register, value, isArray); */
            /* createId($2, $1, tempreg, "", false); */
          }
        ;

_VarDecl : SEMI{
              printf("_VarDecl -> ;\n");
           }
         | LS DIGITS RS SEMI {
           printf("_VarDecl -> [DIGITS];\n");
         }
         ;

FunDecl : LP ParamDeclList RP Block {
            printf("FunDecl -> ( ParamDeclList ) Block\n");
            // TODO: is it ParamDeclList or ParamDeclListTail should pass the ParamDeclList to Block
          }
        ;

VarDeclList : VarDecl VarDeclList {
                /* printf("VarDeclList -> VarDecl VarDeclList\n"); */
                /*$2->insert($2->end(), $1->begin(), $1->end());
                $$ = $2;*/
              }
            | {
              }
            ;

ParamDeclList : ParamDeclListTail {
                   printf("ParamDeclList -> ParamDeclListTail\n");
                  /*$$ = $1;*/
                }
              | /* epsilon */ {}
              ;

ParamDeclListTail : ParamDecl COMMA ParamDeclListTail {
                       printf("ParamDeclListTail -> ParamDecl ParamDeclListTail\n");
                      // don't need to do anything
                    }
                  | ParamDecl {
                      printf("ParamDeclListTail -> ParamDecl\n");
                      /*code_section = new Code_frag();
                      code_section->insert(code_section->end(), $1->begin(), $1->end());
                      $$ = code_section;*/
                  }
                  ;

ParamDecl : Type ID {
               printf("ParamDecl -> Type ID _ParamDecl\n");
              /*newScope();
              parameter_count = parameter_count + 1;*/
              /* 4 bytes for storing and parameter */
              /*stack_top = stack_top + 4;
              addToScope(*$2, stack_top);*/
              /* it doesn't matter what type of id it is -> var or array */
            }
          | Type ID LS RS {
               printf("ParamDecl -> Type ID []");
              /*newScope();
              parameter_count = parameter_count + 1;
              stack_top = stack_top + 4;
              addToScope(*$2, stack_top);*/
          }
          ;

Block : LB VarDeclList StmtList RB {
           printf("Block -> { VarDeclList StmtList }\n");
          // TODO
        }
      ;

Type : INT {
           printf("Type -> int\n");
       }
     | CHAR {
           printf("Type -> char\n");
       }
     ;

StmtList : Stmt _StmtList {
               printf("StmtList -> Stmt StmtList\n");
              /*$2->insert($2->end(), $1->begin(), $1->end());
              $$ = $2;*/
            }
         ;
_StmtList : {
              printf("_StmtList -> ;");
          }
          | StmtList {
            printf("_StmtList -> StmtList;");

          }
          ;

Stmt : SEMI { /* don't need to do anything for ';' */ }
     | Expr SEMI {
           printf("Stmt -> Expr ;\n");
          /* Stmt is assigned an Expr */
          /*code_section = new Code_frag();
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());*/
          /* clean the vector */
          /*code_expr.clear();
          $$ = code_section;*/
       }
     | RETURN Expr SEMI {
           printf("Stmt -> return Expr ;\n");
          /*code_section = new Code_frag();
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());*/
          /* always save Expr in saved register */
          /* clean the vector */
          /*code_expr.clear();
          $$ = code_section;*/
       }
     | BREAK SEMI {
          // TODO
           printf("Stmt -> break ;\n");
       }
     | IF LP Expr RP Stmt ELSE Stmt {
          // TODO
           printf("Stmt -> if (Expr) Stmt else Stmt\n");
       }
     | WHILE LP Expr RP Stmt {
          // TODO
           printf("Stmt -> while (Expr) Stmt\n");
       }
     | Block {
          // TODO
           printf("Stmt -> Block\n");
       }
     | PRINT ID SEMI {
          // print out ID using temp register --> need to load the value
          // code_section = new Code_frag();
          // load register from variables:
          // tempreg = getVarRegister($2);
          // move before printing
          // string temp = "\tmove $a0, ";
          // temp = temp + tempreg;
          // code_section->push_back(temp);
          printf("Stmt -> print ID;\n");
          /*tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string temp1 = "\tlw $";
          temp1 = temp1 + *reg_ptr;
          temp1 = temp1 + ", -";
          temp1 = temp1 + to_string(getOffset(*$2)) + "($fp)";
          code_section->push_back(temp1);
          temp1 = "\tmove $a0, $" + *reg_ptr;*/
          // move to $a0 to print
          /*code_section->push_back(temp1);*/
          // print id as string
          /*code_section->push_back("\tli $v0, 1");
          code_section->push_back("\tsyscall");
          $$ = code_section;
          // make register unused again
          cleanSingleRegister(tempreg);*/
       }
     | READ ID SEMI {
          /* read ID --> need to write value only id for integers */
          /*code_section = new Code_frag();*/
          /* read out from reg */
          /*tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string prefix = "\tsw $v0, $";
          string action = prefix + to_string(getOffset(*$2)) + "($fp)";
          code_section->push_back("\tli $v0, 5");
          code_section->push_back("\tsyscall");
          code_section->push_back(action);
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());
          $$ = code_section;
          cleanSingleRegister(tempreg);
          cleanSingleRegister(*$2);*/
          printf("Stmt -> read ID;\n");
       }
     ;

Expr : NOT Expr {
          printf("!Expr\n");
       }
     | MINUS Expr %prec NEG {
          printf("-Expr\n");
       }
     | DIGITS _Expr {
       printf("Expr -> DIGITS _Expr\n");
     }
     | LP Expr RP _Expr {
       printf("Expr -> (Expr) _Expr\n");
     }
     | ID ExprIdTail {
       printf("Expr -> ID ExprIdTail\n");
     }
     ;

ExprIdTail :
          _Expr {
              printf("ExprIdTail -> _Expr\n");
          }
          | LP ExprList RP _Expr {
            printf("ExprIdTail -> (ExprList) _Expr\n");
          }
          | LS Expr RS ExprArrayTail {
            printf("ExprIdTail -> [Expr] ExprArrayTail");
          }
          | ASSIGN Expr {
            printf("ExprIdTail -> = Expr\n");
          }
          ;

ExprArrayTail : _Expr {
                  printf("ExprArrayTail -> _Expr\n");
              }
              | ASSIGN Expr {
                printf("ExprArrayTail -> = Expr\n");

              }
              ;

ExprList : ExprListTail {
               printf("ExprList -> ExprListTail\n");
           }
           | {}
           ;

ExprListTail: Expr _ExprListTail {

              };

_ExprListTail: COMMA ExprListTail {

              }
              | {}
              ;

_Expr : BinaryOp Expr {
          printf("_Expr -> BinaryOp Expr\n");
      }
      | {}
      ;

BinaryOp : PLUS {
               printf(" + ");
              /* fp << "\tadd " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              // op_stack.push_back(*$1);
              /*kindOfOperator = "+";
              $$ = $1;*/
           }
         | MINUS {
              printf(" - ");
              /* fp << "\tsub " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "-";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | MULT {
               printf(" * ");
              /* fp << "\tmul " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "*";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | DIVIDE {
               printf(" / ");
              /* fp << "\tdiv " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "/";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | EQ {
               printf(" == ");
              /* fp << "\tseq " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "==";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | NE {
               printf(" != ");
              /* fp << "\tsne " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "!=";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | LT {
               printf(" < ");
              /* fp << "\tslt " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "<";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | LE {
               printf(" <= ");
              /* fp << "\tlte " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "<=";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | GT {
               printf(" > ");
              /* fp << "\tlgt " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = ">";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | GE {
               printf(" >= ");
              /* fp << "\tlge " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = ">=";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | AND {
               printf(" && ");
              /* fp << "\tand " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "&&";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         | OR {
               printf(" || "); 
              /* fp << "\tor " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              /*kindOfOperator = "||";*/
              // op_stack.push_back(*$1);
              /*$$ = $1;*/
           }
         ;

%%
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctype.h>

void yyerror(const char *err) {
  cout << "line " << yylineno << ": " << err << endl;
}

int main(int argc, char *argv[]) {
  yyin = fopen(argv[1], "r");
  FILE *fp = fopen("code_gen.s", "w");
  initialize();
  if(yyparse()) {
    fprintf(stderr, "parsing error!\n");
  } else {
    // can parse and print into .s
    /*for(int i=0;i<instruction.size();i++) {
      fprintf(fp, "%s\n", instruction[i].c_str());
    }*/
    printf("Parsing complete.\n");
  }
  fclose(yyin);
  fclose(fp);
  return 0;
}
