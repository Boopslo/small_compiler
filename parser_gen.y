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
%token RETURN IF ELSE WHILE BREAK PRINT READ SEMI COMMA ASSIGN LP RP LB RB LS RS


%type <letters> DIGITS ID CHARS
%type <letters> INT CHAR
%type <letters> RETURN IF ELSE WHILE BREAK PRINT READ SEMI COMMA
%type <letters> Type BinaryOp Expr Node Operation

%type <code> Program DeclList _DeclList VarDecl FunDecl VarDeclList ParamDeclList ParamDeclListTail ParamDecl
%type <code> Block StmtList Stmt ExprList

%left <letters> AND OR
%left <letters> EQ NE LT GT LE GE
%left <letters> PLUS MINUS
%left <letters> MULT DIVIDE
%left <letters> NEG NOT

%%

Program : DeclList {
            printf("Program -> DeclList\n");
            // add to end of stack
            /*instruction.insert(instruction.end(), $1->begin(), $1->end());*/
          }
        ;

DeclList : _DeclList DeclList {
              printf("DeclList -> _DeclList DeclList\n");
              /*instruction.insert(instruction.end(), $1->begin(), $1->end());*/
           }
         | /* epsilon */ {}
         ;

_DeclList : Type ID SEMI {
              printf("_DeclList -> Type ID Decl\n");
              stack_top += 4;
              addToScope(*$2, stack_top);
            }
          | Type ID LS DIGITS RS SEMI {
              printf("_DeclList -> Type ID [DIGITS];\n");
              // array declaration
              stack_top += ( 4 * atoi((*$4).c_str()) );
              addToScope(*$2, stack_top);
            }
          | Type ID FunDecl {
              printf("_DeclList -> Type ID FunDecl\n");
              // TODO
            }
          ;

VarDecl : Type ID SEMI {
            printf("VarDecl -> Type ID;\n");
            stack_top += 4;
            addToScope(*$2, stack_top);
            printf("id added: %s\n", (*$2).c_str());
            // keep track of the attributes of the var
            /* createId(name, type, register, value, isArray); */
            /* createId($2, $1, tempreg, "", false); */
          }
        | Type ID LS DIGITS RS SEMI {
            printf("VarDecl -> Type ID [ DIGITS ] ;");
            stack_top += ( 4 * atoi((*$4).c_str()) );
            addToScope(*$2, stack_top);
            // createId($2, $1, "", "", true);
          }
        ;

FunDecl : LP ParamDeclList RP Block {
          }
        ;

VarDeclList : VarDecl VarDeclList {
                printf("VarDeclList -> VarDecl VarDeclList\n");
                $2->insert($2->end(), $1->begin(), $1->end());
                $$ = $2;
              }
            | VarDecl {
                printf("VarDeclList -> VarDecl\n");
                /* new variable declaration */
                code_section = new Code_frag();
                $$ = code_section;
              }
            ;

ParamDeclList : ParamDeclListTail {
                  printf("ParamDeclList -> ParamDeclListTail\n");
                  $$ = $1;
                }
              | /* epsilon */ {}
              ;

ParamDeclListTail : ParamDecl COMMA ParamDeclListTail {
                      printf("ParamDeclListTail -> ParamDecl ParamDeclListTail\n");
                    }
                  | ParamDecl {
                      printf("ParamDeclListTail -> ParamDecl\n");
                      code_section = new Code_frag();
                      code_section->insert(code_section->end(), $1->begin(), $1->end());
                      $$ = code_section;
                  }
                  ;

ParamDecl : Type ID {
              printf("ParamDecl -> Type ID\n");
              newScope();
              parameter_count = parameter_count + 1;
              /* 4 bytes for storing and parameter */
              stack_top = stack_top + 4;
              addToScope(*$2, stack_top);
            }
          | Type ID LS RS {
              printf("ParamDecl -> Type ID []");
              newScope();
              parameter_count = parameter_count + 1;
              stack_top = stack_top + 4;
              addToScope(*$2, stack_top);
          }
          ;

Block : LB VarDeclList StmtList RB {
          printf("Block -> { VarDeclList StmtList }\n");
          // TODO
        }
      | LB StmtList RB {
          printf("Block -> {StmtList}\n");
          // TODO
        }
      ;

Type : INT {
          printf("Type -> int\t");
       }
     | CHAR {
          printf("Type -> char\t");
       }
     ;

StmtList : Stmt StmtList {
              printf("StmtList -> Stmt StmtList\n");
              $2->insert($2->end(), $1->begin(), $1->end());
              $$ = $2;
           }
         | Stmt {
              printf("StmtList -> Stmt\n");
              code_section = new Code_frag();
              /* add a new Stmt */
              code_section->insert(code_section->end(), $1->begin(), $1->end());
              $$ = code_section;
           }
         ;

Stmt : SEMI { /* don't need to do anything for ';' */ }
     | Expr SEMI {
          printf("Stmt -> Expr ;\n");
          /* Stmt is assigned an Expr */
          code_section = new Code_frag();
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());
          /* clean the vector */
          code_expr.clear();
          $$ = code_section;
          cleanSingleRegister(*$1);
       }
     | RETURN Expr SEMI {
          printf("Stmt -> return Expr ;\n");
          code_section = new Code_frag();
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());
          /* always save Expr in saved register */
          /* clean the vector */
          code_expr.clear();
          $$ = code_section;
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
          /* // print out ID using temp register --> need to load the value
          // code_section = new Code_frag();
          // load register from variables:
          // tempreg = getVarRegister($2);
          // move before printing
          // string temp = "\tmove $a0, ";
          // temp = temp + tempreg;
          // code_section->push_back(temp); */
          printf("Stmt -> print ID;\n");
          tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string temp1 = "\tlw $";
          temp1 = temp1 + *reg_ptr;
          temp1 = temp1 + ", -";
          temp1 = temp1 + to_string(getOffset(*$2)) + "($fp)";
          // code_section->push_back(temp1);
          instruction.push_back(temp1);

          temp1 = "\tmove $a0, $" + *reg_ptr;
          // move to $a0 to print
          // code_section->push_back(temp1);
          instruction.push_back(temp1);

          // print id as string
          // code_section->push_back("\tli $v0, 1");
          // code_section->push_back("\tsyscall");
          instruction.push_back("\tli $v0, 1");
          instruction.push_back("\tsyscall");

          $$ = code_section;
          // make register unused again
          cleanSingleRegister(tempreg);
          cleanSingleRegister(*$2);
       }
     | READ ID SEMI {
          printf("Stmt -> read ID;\n");
          /* read ID --> need to write value only id for integers */
          code_section = new Code_frag();
          /* read out from reg */
          tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string prefix = "\tsw $v0, $";
          string action = prefix + to_string(getOffset(*$2)) + "($fp)";
          /*code_section->push_back("\tli $v0, 5");
          code_section->push_back("\tsyscall");
          code_section->push_back(action);
          code_section->insert(code_section->end(), code_expr.begin(), code_expr.end());*/

          instruction.push_back("\tli $v0, 5");
          instruction.push_back("\tsyscall");
          instruction.push_back(action);

          $$ = code_section;
          cleanSingleRegister(tempreg);
          cleanSingleRegister(*$2);
       }
     ;

ExprList : Expr {
              printf("ExprList -> Expr\n");
           }
         | ExprList COMMA Expr {
              /* ExprList, Expr .....  */
           }
         ;

Node : ID {
          printf("ID\t");
          tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string prefix = "\tlw $";
          string action = prefix + *reg_ptr + ", -" + to_string(getOffset(*$1)) + "($fp)";
          /*code_expr.push_back(action);*/
          instruction.push_back(action);
          $$ = reg_ptr;
       }
     | DIGITS {
          printf("num\t");
          tempreg = getTempReg();
          reg_ptr = new string(tempreg);
          string prefix = "\tli $";
          string action = prefix + *reg_ptr + ", $" + *$1;
          /*code_expr.push_back(action);*/
          instruction.push_back(action);
          $$ = $1;
       }
     ;

Expr : ID ASSIGN Expr {
          printf("Expr -> ID = Expr\n");
          string prefix = "\tsw $";
          /* get id offset in the stack and store the word in it */
          string action = prefix + *$3 + ", -" + to_string(getOffset(*$1)) + "($fp)";
          /*code_expr.push_back(action);*/
          instruction.push_back(action);
       }
     | ID LS Expr RS BinaryOp Expr {
          /* TODO: deal with Arrays */
          printf("Expr -> ID [Expr] BinaryOp Expr\n");
       }
     | ID LS Expr RS {
          /* TODO: deal with Arrays */
          printf("Expr -> ID [Expr]\n");
       }
     | ID LS Expr RS ASSIGN Expr {
          /* TODO: array... */
       }
     | ID LP ExprList RP {

       }
     | Operation
     ;

Operation : Node { $$ = $1; }
          | LP Expr RP  {
                printf("Operation -> (Operation)\n");
                $$ = $2;
            }
          | Operation BinaryOp Operation {
              printf("Operation -> Operation BinaryOp Operation\n");
              string arithmetic_prefix = correspondOp(*$2);
              // result stored in operation ($3)
              string action = "";
              if(kindOfOperator.compare("==") == 0 || kindOfOperator.compare("!=") == 0 | kindOfOperator.compare("<") == 0 | kindOfOperator.compare("<=") == 0 | kindOfOperator.compare(">") == 0 | kindOfOperator.compare(">=") == 0 | kindOfOperator.compare("&&") == 0 | kindOfOperator.compare("||") == 0) {
                  // have to store value into new register if using ==, !=, <, <=, >, >=, &&, ||
                  tempreg = getTempReg();
                  reg_ptr = new string(tempreg);
                  action = arithmetic_prefix + *reg_ptr + ", $" + *$1 + ", $" + *$3;
                  /*code_expr.push_back(action);*/
                  instruction.push_back(action);
                  $$ = reg_ptr;
               } else {
                  action = arithmetic_prefix + *$1 + ", $" + *$1 + ", $" + *$3;
                  /*code_expr.push_back(action);*/
                  instruction.push_back(action);
                  $$ = $1;
               }
               cleanSingleRegister(*$3);
            }
          | MINUS Operation %prec NEG {
               printf("-Operation");
               /* this should be NEG token */
               string a = "\tneg ";
               string action = a + *$2 + ", $" + *$2;
               /*code_expr.push_back(action);*/
               instruction.push_back(action);
               $$ = $2;
               // return $2 back
            }
          | NOT Operation {
               printf("!Operation\n");
               /* printf(" ! "); */
               string a = "\tnot $";
               /* not command */
               string action = a + *$2 + ", $" + *$2;
               /*code_expr.push_back(action);*/
               instruction.push_back(action);
               $$ = $2;
            }
          ;

BinaryOp : PLUS {
              /* printf(" + "); */
              /* fp << "\tadd " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              // op_stack.push_back(*$1);
              kindOfOperator = "+";
              $$ = $1;
           }
         | MINUS {
              printf(" - ");
              /* fp << "\tsub " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "-";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | MULT {
              /* printf(" * "); */
              /* fp << "\tmul " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "*";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | DIVIDE {
              /* printf(" / "); */
              /* fp << "\tdiv " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "/";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | EQ {
              /* printf(" == "); */
              /* fp << "\tseq " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "==";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | NE {
              /* printf(" != "); */
              /* fp << "\tsne " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "!=";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | LT {
              /* printf(" < "); */
              /* fp << "\tslt " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "<";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | LE {
              /* printf(" <= "); */
              /* fp << "\tlte " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "<=";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | GT {
              /* printf(" > "); */
              /* fp << "\tlgt " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = ">";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | GE {
              /* printf(" >= "); */
              /* fp << "\tlge " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = ">=";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | AND {
              /* printf(" && "); */
              /* fp << "\tand " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "&&";
              // op_stack.push_back(*$1);
              $$ = $1;
           }
         | OR {
              /* printf(" || "); */
              /* fp << "\tor " << "$t0, " << "$t1, " << "$t2"; */
              /* track the operator */
              kindOfOperator = "||";
              // op_stack.push_back(*$1);
              $$ = $1;
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
  cout << "line " << yylineno << ": " << err << "token: " << &yylex << endl;
}

int main(int argc, char *argv[]) {
  yyin = fopen(argv[1], "r");
  //FILE *fp = fopen("code_gen.s", "w");
  ofstream fp("code_gen.s", ios::out);
  initialize();
  if(yyparse()) {
    fprintf(stderr, "parsing error!\n");
  } else {
    // can parse and print into .s
    fp << "main:" << endl;
    for(int i = 0; i< instruction.size(); i++) {
      fp << instruction[i] << endl;
    }
  }
  fclose(yyin);
  fp.close();
  return 0;
}
