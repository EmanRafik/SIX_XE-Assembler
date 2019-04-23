#include "Parser.h"
#include "Line.h"
#include<regex>
#include<string>
#include <iostream>
#include"Address.h"
#include "OperationCodes.h"

using namespace std;
using namespace std::regex_constants;

/*string Parser::opCodes[] = {"ADD", "ADDF", "ADDR", "AND", "CLEAR", "COMP", "COMPF", "COMPR","DIV","DIVF","DIVR",
            "J","JEQ","JLT","JGT","JSUB","LDA","LDB","LDCH","LDF","LDL","LDS","LDT","LDT","LDX","LPS","MUL","MULF",
            "MULR","OR","RD","RMO","SHIFTL","SHIFTR","SSK","STA","STB","STCH","STF","STI","STL","STS","STSW",
            "STT","STX","SUB","SUBF","SUBR","SVC","TD","TIX","TIXR","WD"};*/
string Parser:: noOperanCodes[] = {"FIX","FLOAT","HIO","NORM","RSUB","SIO","TIO"};

Parser::Parser()
{
    //ctor
}
Parser::~Parser()
{
    //dtor
}

void Parser::parseStart(std::string line)
{
    l.setInput(line);
    int i = 0;
    string word;
    std::smatch m;
    std::regex e("\\s+", ECMAScript | icase);
    while(std::regex_search(line,m,e))
    {
        int x = m.position();
        if (x != 0)
        {
            word = line.substr(0,x);
            string s = word;
            std::transform(s.begin(), s.end(), s.begin(), ::toupper);
            switch (i)
            {
            case 0:
                if (s == "START")
                {
                    i = 1;
                    l.setOpCode(word);
                }
                else
                {
                    l.setLabel(word);
                }
                break;
            case 1:
                if (s != "START")
                {
                    l.setErrorMessage("Undefined Start Format ..");
                    return;
                }
                l.setOpCode("START");
                break;
            case 2:
                std::smatch m1;
                std::regex e1("[0-9A-F]+", ECMAScript | icase);
                if (std::regex_search(word,m1,e1))
                {
                    int x = m1.length();
                    int y = word.length();
                    if(x==y && x <= 4) {
                        l.setOperand(word);
                        Address address(l.getOpCode(),l.getOperand());
                        address.startCounter();
                        l.setLocationCounter(address.getAddress());
                    } else {
                        l.setComment(word);
                        Address address(l.getOpCode(),"0000");
                        address.startCounter();
                        l.setLocationCounter(address.getAddress());
                        return;
                    }
                } else {
                    l.setLocationCounter("0000");
                    l.setComment(word);
                    Address address(l.getOpCode(),"0000");
                    address.startCounter();
                    l.setLocationCounter(address.getAddress());
                    return;
                }
                break;
            }
            i++;
        }
        line = m.suffix().str();
    }
    if (line.length() > 0)
    {
        l.setComment(word);
    }
}

void Parser::parseEnd(std::string line)
{
    l.setInput(line);
    bool flag = true;
    string word;
    std::smatch m;
    std::regex e("\\s+", ECMAScript | icase);
    while(std::regex_search(line,m,e))
    {
        int x = m.position();
        if (x != 0)
        {
            word = line.substr(0,x);
            string s = word;
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            if (flag)
            {
                if (s != "end")
                {
                    l.setErrorMessage("Undefined End Format ..");
                    return;
                }
                flag = false;
            }
            else
            {
                if (s.length() >= 4)
                {
                    for (unsigned int i = 0; i < s.length(); i++)
                    {
                        if ((s.at(i) < '0' || s.at(i) > '9')&& s.at(i) != 'A' && s.at(i) != 'B' &&s.at(i) != 'C' &&s.at(i) != 'D' &&s.at(i) != 'E' &&s.at(i) != 'F')
                        {
                            l.setComment(word);
                            return;
                        }
                    }
                    l.setOpCode(word);
                    //initialize start
                }
                else
                {
                    l.setComment(word);
                    return;
                }
            }
        }
        line = m.suffix().str();
        if (line.length() > 0)
        {
            l.setComment(line);
        }
    }
}

void Parser::parseLine(std::string line)
{
    l.setInput(line);
    if (line.at(0) == '.')
    {
        l.setComment(line);
        l.setCommentLine(true);
        return;
    }
    int i = 0;
    string word;
    std::smatch m;
    std::regex e("\\s+", ECMAScript | icase);
    while(std::regex_search(line,m,e))
    {
        int x = m.position();
        if (x != 0)
        {
            word = line.substr(0,x);
            i = classify(word, i);
        }
        line = m.suffix().str();
        int len = line.length();
        if (i == 3)
        {
            if (len != 0)
            {
                cout << "comment " << line << "\n";
                l.setComment(line);
            }
            break;
        }
        if (i == -1)
        {
            return;
        }
    }
    if (i < 3)
    {
        classify(line,i);
    }
    //operand not string
    //  address = updateCounter(opcode, operand);
    //addlabel(l.getLabel(), l.getLocationCounter());
   /* if (l.symbolicOperand()) {
        addSymbolicOperand(l.getOperand(), l.getLocationCounter());
    }

    //write(address, label, opCode, operand, comment);
    /*if (error)
    write(error);*/
}

bool Parser::opCode(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    OperationCodes operationCodes;
    map<string, string> codeMap = operationCodes.getMap();
    map<string,string>::iterator it = codeMap.find(s);
    if(it != codeMap.end())
    {
        return true;
    }

    return false;
}

bool Parser::noOperand(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    for (int i = 0; i < 20; i++)
    {
        //if (s == noOperandCodes[i])
        //{
            return true;
        //}
    }
    return false;
}

int Parser::classify(std::string word, int i)
{
    switch (i)
    {
    case 0:
        if(opCode(word))
        {
            i = 1;
            cout << "opCode " << word << "\n";
            l.setOpCode(word);
        }
        else if (noOperand(word))
        {
            i = 2;
            cout << "opCode " << word << "\n";
            l.setOpCode(word);
        }
        else
        {
            cout << "label " << word << "\n";
            l.setLabel(word);
        }
        break;
    case 1:
        if(opCode(word))
        {
            cout << "opCode " << word << "\n";
            l.setOpCode(word);
        }
        else if (noOperand(word))
        {
            cout << "opCode " << word << "\n";
            l.setOpCode(word);
            i = 2;
        }
        else
        {
            l.setErrorMessage("Undefined opCode ..");
            return -1;
        }
        break;
    case 2:
        cout << "operand " << word << "\n";
        l.setOperand(word);
        break;
    }
    i++;
    return i;
}
