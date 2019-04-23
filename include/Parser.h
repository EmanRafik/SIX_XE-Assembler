#include<string>
#include"Line.h"
#ifndef PARSER_H
#define PARSER_H

using namespace std;
//using namespace std::regex_constants;

class Parser
{
    public:
        Parser();
        virtual ~Parser();
        void parseLine(std::string line);
        void parseStart(std::string line);
        void parseEnd(std::string line);
        bool opCode(std::string s);
        bool noOperand(std::string s);
        int classify(std::string word, int i);

    protected:

    private:
        static string opCodes[51];
        static string noOperanCodes[7];
        Line l;
};

#endif // PARSER_H
