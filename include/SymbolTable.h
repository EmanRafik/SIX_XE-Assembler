#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <iostream>
#include<map>
#include <string>
using namespace std;
class SymbolTable
{
public:
    SymbolTable();
    string addlabel(string symbol, string address);
    string addequ(string symbol, string operand);
    map<string, string*> GetSymTab();
protected:

private:
    bool checkValidLabel(string symbol);
    string checkEquOperand(string operand);
    string checkExpressionOperand(string operand);
    bool isMnemonic(string symbol);
    string generateError(string symbol, string address);
    map<string, string*>symTab;
};

#endif // SYMBOLTABLE_H
