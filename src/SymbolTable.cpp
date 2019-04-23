#include "SymbolTable.h"
#include <iostream>
#include <string>
#include <map>
#include<cctype>
using namespace std;
SymbolTable::SymbolTable()
{
    //ctor
}
map<string, string*> SymbolTable::GetSymTab()
{
    return symTab;
}
string SymbolTable::generateError(string symbol, string address)
{
    return "symbol '" + symbol +"' is already defined";
}
bool SymbolTable::isMnemonic(string symbol)
{
    // check opTab
    return false;
}
bool SymbolTable::checkValidLabel(string symbol)
{
    if(isdigit(symbol[0]))
    {
        return false;
    }
    else if (isMnemonic(symbol))
    {
        return false;
        //contain special characters
    }
    else if(symbol.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_") != std::string::npos)
    {
        return false;
    }
    return true;
}
string SymbolTable::addlabel(string symbol, string address)
{
    string message = "";
    map<string, string*>::iterator i = symTab.find(symbol);
    if(!checkValidLabel(symbol))
    {
        message = "Invalid Label Name";
        return message;
    }
    else if(i == symTab.end())  //label not found
    {
        string* s = new string[3] {address,"R","NoError"};
        symTab[symbol] = s;
    }
    else
    {
        symTab[symbol] = new string[3] {i->second[0],"R","Error"};;
        message = generateError(symbol, address);
    }
    return message;
}
string SymbolTable::addequ(string symbol,string operand)
{
    string p = checkEquOperand(operand);
    if(p != "invalid operand")
    {
        string* s = new string[3] {p,"A","NoError"};
        symTab[symbol] = s;
        return "";
    }
    else return "Invalid expression in operand";
}
string SymbolTable::checkEquOperand(string operand)
{
    if(operand.find_first_not_of("0123456789") == std::string::npos) //not symbolic operand
    {
        return operand;
    }
    map<string, string*>::iterator i = symTab.find(operand);
    if(i != symTab.end()) //symbol found
    {
        return i->second[0]; //return symbol address
    }
    else
    {
        return checkExpressionOperand(operand);
    }

}
string SymbolTable::checkExpressionOperand(string operand)
{
    //return "invalid operand" if invalid
    return "";
}
