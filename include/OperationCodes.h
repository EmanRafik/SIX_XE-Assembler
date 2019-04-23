#ifndef OPERATIONCODES_H
#define OPERATIONCODES_H
#include <map>
#include <string>
#include <iostream>

using namespace std;

class OperationCodes
{
    public:
        OperationCodes();
        virtual ~OperationCodes();
        void geneError(std::string opcode, std::string operand, std::string address);
        bool check(std::string opcode, std::string operand);
        void parsercheck(std::string format, std::string operand);
        string[] getStorageDirectives();
        string[] getAssemblerDirectives();
        map<string, string> getMap();

    protected:

    private:
        map<string, string> myMap;
        static string storageDirectives[4];
        static string assemblerDirectives[7];
};

#endif // OPERATIONCODES_H
