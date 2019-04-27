#ifndef LITERALTABLE_H
#define LITERALTABLE_H
#include <string>
#include<map>
#include <iostream>


class LiteralTable
{
    public:
        LiteralTable();
        virtual ~LiteralTable();
        void addLiteral(std::string literal);
        std::string setLiterals(std::string address);
        std::string getLiterals();
        std::string literals;

    protected:

    private:
        std::map <std::string ,std::string*> litTbl;
        std::string ASCIItoHEX(std::string ascii);
};

#endif // LITERALTABLE_H
