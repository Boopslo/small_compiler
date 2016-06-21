#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <ctype.h>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

typedef struct {
    string type;
    string reg;
    string value;
    bool isArray;
} attribute;

// use map to store registers; 1 -> used, 0 -> unused
map <string, int> mips_reg, temp_reg;
typedef vector<string> Code_frag;
// map: <id, attribute> for variables
map <string, attribute> variables;
// vector to store vars and its stack position offset
typedef map <string, int> Stack;
vector<Stack> scopes;
vector<string> operators;

string getTempReg();

// new scope
void newScope() {
    Stack *sta = new Stack();
    scopes.push_back(*sta);
}

void exitScope() {
    scopes.pop_back();
}

/* initialize maps to represent status of MIPS registers */
void initialize() {
    // zero means not in use of that register
    newScope();
    mips_reg["v0"] = 0;
    mips_reg["v1"] = 0;
    mips_reg["a0"] = 0;
    mips_reg["a1"] = 0;
    mips_reg["a2"] = 0;
    mips_reg["a3"] = 0;
    mips_reg["t0"] = 0;
    mips_reg["t1"] = 0;
    mips_reg["t2"] = 0;
    mips_reg["t3"] = 0;
    mips_reg["t4"] = 0;
    mips_reg["t5"] = 0;
    mips_reg["t6"] = 0;
    mips_reg["t7"] = 0;
    mips_reg["t8"] = 0;
    mips_reg["t9"] = 0;
    mips_reg["s0"] = 0;
    mips_reg["s1"] = 0;
    mips_reg["s2"] = 0;
    mips_reg["s3"] = 0;
    mips_reg["s4"] = 0;
    mips_reg["s5"] = 0;
    mips_reg["s6"] = 0;
    mips_reg["s7"] = 0;
    // initialize the vector of op
    operators.push_back("+");
    operators.push_back("-");
    operators.push_back("*");
    operators.push_back("/");
    operators.push_back("==");
    operators.push_back("!=");
    operators.push_back("<");
    operators.push_back("<=");
    operators.push_back(">");
    operators.push_back(">=");
    operators.push_back("&&");
    operators.push_back("||");
}

void createId(string name, string vartype, string varreg, string varvalue, bool varArray) {
    // so you have to know if id is a variable id | function id
    // temp struct
    attribute tempattr;
    if (vartype.size() != 0) {
        tempattr.type = vartype;
    }
    if (varreg.size() != 0) {
        tempattr.reg = varreg;
    }
    if (varvalue.size() != 0) {
        tempattr.value = varvalue;
    }
    tempattr.isArray = varArray;
    string tempname = name;
    // insert new elements into map of variables
    variables.insert(pair<string, attribute>(tempname, tempattr));
}

int checkIfArray(string idname) {
    if (variables.find(idname) != variables.end()) {
        // if found the id
        return variables[idname].isArray == true ? 1 : 0;
    } else {
        // default is not an array
        return 0;
    }
}

string getVarRegister(string varname) {
    // variables stored in register
    // attribute tempattr;
    if (variables.find(varname) != variables.end()){
        return variables[varname].reg;
    } else {
        return getTempReg();
    }
}

// store into scope
void addToScope(string name, int offset) {
    int s = scopes.size() - 1;
    scopes[s][name] = offset;
}

int getOffset(string instruct) {
    for (int i = 0; i<scopes.size(); i++) {
        // if the instruction exists
        if (scopes[i].count(instruct) > 0) {
            return scopes[i][instruct];
        }
    }
}

string getSubArg() {
    string prefix = "a";
    string total = "";
    for(int i=0; i< 4; i++) {
        string temp = to_string(i);
        total = prefix + temp;
        // if the register is not used, set used then return
        if(mips_reg[total] == 0) {
            mips_reg[total] = 1;
            return total;
        }
    }
}

// get which register is available for use
string getTempReg() {
    string prefix = "t";
    string total = "";
    for(int i=0; i< 10; i++) {
        string temp = to_string(i);
        total = prefix + temp;
        // if the register is not used, set used then return
        if(mips_reg[total] == 0) {
            mips_reg[total] = 1;
            return total;
        }
    }
}

string getSavedReg() {
    string prefix = "s";
    string total = "";
    for(int i=0; i< 8; i++) {
        string temp = to_string(i);
        total = prefix + temp;
        // if the register is not used, set used then return
        if(mips_reg[total] == 0) {
            mips_reg[total] = 1;
            return total;
        }
    }
}

// clean the Subroutine Args status to unused
void cleanAllSubArg() {
    mips_reg["a0"] = 0;
    mips_reg["a1"] = 0;
    mips_reg["a2"] = 0;
    mips_reg["a3"] = 0;
}

void cleanSingleRegister(string reg) {
    if(mips_reg[reg] == 1) {
        mips_reg[reg] = 0;
    }
}

void cleanAllTempReg() {
    mips_reg["t0"] = 0;
    mips_reg["t1"] = 0;
    mips_reg["t2"] = 0;
    mips_reg["t3"] = 0;
    mips_reg["t4"] = 0;
    mips_reg["t5"] = 0;
    mips_reg["t6"] = 0;
    mips_reg["t7"] = 0;
    mips_reg["t8"] = 0;
    mips_reg["t9"] = 0;
}

// clean saved registers
void cleanAllSavedReg() {
    mips_reg["s0"] = 0;
    mips_reg["s1"] = 0;
    mips_reg["s2"] = 0;
    mips_reg["s3"] = 0;
    mips_reg["s4"] = 0;
    mips_reg["s5"] = 0;
    mips_reg["s6"] = 0;
    mips_reg["s7"] = 0;
}

string correspondOp(string inputOp) {
    if(inputOp.compare("+") == 0) {
        return "\tadd $";
    } else if(inputOp.compare("-") == 0) {
        return "\tsub $";
    } else if(inputOp.compare("*") == 0) {
        return "\tmul $";
    } else if(inputOp.compare("/") == 0) {
        return "\tdiv $";
    } else if(inputOp.compare("==") == 0) {
        return "\tseq $";
    } else if(inputOp.compare("!=") == 0) {
        return "\tsne $";
    } else if(inputOp.compare("<") == 0) {
        return "\tslt $";
    } else if(inputOp.compare("<=") == 0) {
        return "\tlte $";
    } else if(inputOp.compare(">") == 0) {
        return "\tlgt $";
    } else if(inputOp.compare(">=") == 0) {
        return "\tlge $";
    } else if(inputOp.compare("&&") == 0) {
        return "\tand $";
    } else if(inputOp.compare("||") == 0) {
        return "\tor $";
    } else {
        return "";
    }
}
