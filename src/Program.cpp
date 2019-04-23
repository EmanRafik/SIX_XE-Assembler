#include "Program.h"
#include <iostream>
#include<fstream>
#include"Line.h"
#include"Parser.h"
#include<regex>
#include"Address.h"

using namespace std;
using namespace std::regex_constants;

Program::Program()
{
    //ctor
}

Program::~Program()
{
    //dtor
}

/*static Program::Program *getInstance()
{
    if (!this->instance)
    {
        instance = new Program();
    }
    return this->instance;
}
*/
void Program::pass1()
{
    bool endFlag;
    string path;
    cout << "Enter Source File Path:\n";
    cin >> path;
    ifstream input;
    input.open(path);
    string line;
    getline(input, line);
    while (line.at(0) == '.') {
        Line l;
        l.setCommentLine(true);
        l.setComment(line);
        l.write();
        getline(input, line);
    }
    std::smatch m;
    std::regex e("start", ECMAScript | icase);
    if(std::regex_search(line,m,e))
    {
       Parser p;
       p.parseStart(line);
    } else {
        Address address("start","0000");
        address.startCounter();
        Parser p;
        p.parseLine(line);
    }
    while (getline(input, line))
    {
        std::smatch m;
        std::regex e("\tend", ECMAScript | icase);
        if(std::regex_search(line,m,e))
        {
            if (m.position() == 0) {
                Parser p;
                p.parseEnd(line);
                //symtTabError();
                endFlag=true;
                while (getline(input, line)) {
                    //write
                }
            } else {
                Parser p;
            p.parseLine(line);
            }
        } else {
            Parser p;
            p.parseLine(line);
        }
    }
    if (!endFlag) {
        //no end ... error*/
    }
}

void Program::setName(string name) {}
void Program::setstartingAdddress(string startingAdddress) {}
void Program::setLength(string Length) {}
string Program::getName() {
    return this->name;
}
string Program::getStartingAddress() {
    return this->startingAdddress;
}
string Program::getLength() {
    return this->length;
}
