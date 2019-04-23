#ifndef OUTPUT_H
#define OUTPUT_H
#include<string>
#include<Line.h>


class Output
{
public:
    Output();
    virtual ~Output();
    void makeLine(Line l);
    void writeLine(std::string line);
protected:

private:
    string outline, label, opCode, operand, comment, address, prevAddress;
    string errorMessage;
    unsigned int expsize;
    bool iscomment, isErrors;
};

#endif // OUTPUT_H
