#include "OperationCodes.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

string OperationCodes::assemblerDirectives[]={"EQU","ORG","BASE","NOBASE","LTORG","START","END"};
string OperationCodes::storageDirectives[]={"RESW","RESB","WORD","BYTE"};

OperationCodes::OperationCodes()
{
    //ctor
    this->myMap["rmo"] = "2";
    this->myMap["ldr"] = "3";
    this->myMap["str"] = "3";
    this->myMap["ldch"] = "3";
    this->myMap["stch"] = "3";
    this->myMap["add"] = "3";
    this->myMap["sub"] = "3";
    this->myMap["mul"] = "3";
    this->myMap["div"] = "3";
    this->myMap["addr"] = "2";
    this->myMap["subr"] = "2";
    this->myMap["mulr"] = "2";
    this->myMap["divr"] = "2";
    this->myMap["compr"] = "2";
    this->myMap["comp"] = "3";
    this->myMap["j"] = "3";
    this->myMap["jeq"] = "3";
    this->myMap["jlt"] = "3";
    this->myMap["jgt"] = "3";
    this->myMap["tix"] = "3";
    this->myMap["tixr"] = "1";
    this->myMap["jsub"] = "3";
    this->myMap["rsub"] = "";
    this->myMap["td"] = "3";
    this->myMap["rd"] = "3";
    this->myMap["wd"] = "3";
}

OperationCodes::~OperationCodes()
{
    //dtor
}

void OperationCodes::parsercheck(string format,string operand) {

}

map<string, string> OperationCodes::getMap(){
    //string n = myMap["wd"];
    return this->myMap;
}

bool OperationCodes::check(string opcode, string operand) {
    //parsercheck(string numberOfFormat, string operand)
    parsercheck(OperationCodes::getMap()[opcode], operand);
    return false;
}

