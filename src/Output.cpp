#include "Output.h"
#include<fstream>

Output::Output()
{
    //ctor
    this ->prevAddress = "";
    this -> outline = "";
    this -> expsize = 0;
}

Output::~Output()
{
    //dtor
}

void Output::makeLine(Line l)
{
    this -> outline = "";
    this -> address = l.getLocationCounter();
    this -> opCode = l.getOpCode();
    this -> label = l.getLabel();
    this -> operand = l.getOperand();
    this -> comment = l.getComment();
    this -> iscomment= l.isComment();
    this->isErrors = l.errorFound();
    if (iscomment)
    {
        outline = this ->prevAddress;
        expsize = 7;
        while (outline.size() < expsize)
        {
            outline = outline + " ";
        }
        outline = outline + comment;
    }
    else if(isErrors)
    {
        writeLine(l.getInput());
        writeLine(l.getErrorMessage());
    }
    else
    {
        this ->prevAddress = address;
        expsize = 7;
        outline = outline + address;
        while (outline.size() < expsize)
        {
            outline = outline + " ";
        }
        expsize = 7+9;
        outline = outline + label;
        while (outline.size() < expsize)
        {
            outline = outline + " ";
        }
        expsize = 7+17;
        outline = outline + opCode;
        while (outline.size() < expsize)
        {
            outline = outline +" ";
        }
        expsize = 7+35;
        outline = outline + operand;
        while (outline.size() < expsize)
        {
            outline = outline + " ";
        }
        outline = outline + comment;
    }
    writeLine(outline);
    /*if (Warning is true)
    {
        writeLine(l)
    }
    */
}
void Output::writeLine(std::string line)
{
    ofstream myfile;
    myfile.open ("example.txt");
    myfile << line;
    myfile << "\n";
    myfile.close();
}
