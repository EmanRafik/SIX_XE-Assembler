#include<string>
#ifndef LINE_H
#define LINE_H

using namespace std;

class Line
{
    public:
        Line();
        virtual ~Line();
        void setLabel(string label);
        void setOpCode(string opCode);
        void setOperand(string operand);
        void setComment(string comment);
        void setLocationCounter(string locationCounter);
        void setErrorMessage(string errorMessage);
        void setInput(string input);
        void setCommentLine(bool commentLine);
        string getLabel();
        string getOpCode();
        string getOperand();
        string getComment();
        string getLocationCounter();
        string getErrorMessage();
        string getInput();
        void write();
        bool errorFound();
        bool symbolicOperand();
        bool isComment();

    protected:

    private:
        string label, opCode, operand, comment, locationCounter;
        string errorMessage,input;
        bool commentLine, error, symbol;
};

#endif // LINE_H
