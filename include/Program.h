#ifndef PROGRAM_H
#define PROGRAM_H
#include<string>
#include<Address.h>
#include<Output.h>
#include<SymbolTable.h>
#include<Parser.h>
#include"LiteralTable.h"

using namespace std;

class Program
{
public:
    static Program *getInstance();
    virtual ~Program();
    void pass1();
    void setName(string name);
    void setstartingAdddress(string startingAdddress);
    void setLength(string Length);
    string getName();
    string getStartingAddress();
    string getLength();
    Address getAddressManager();
    Output getOutputManager();
    LiteralTable getLiteralTableManeger();

protected:

private:
    Program();
    static Program *instance;
    string name, startingAdddress, length;
    Address address;
    Output output;
    LiteralTable literalTable;
};

#endif // PROGRAM_H
