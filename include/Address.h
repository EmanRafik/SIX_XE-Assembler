#include<string>
#ifndef ADDRESS_H
#define ADDRESS_H

using namespace std;

class Address
{
    public:
        Address(std::string opCode, std::string operand);
        virtual ~Address();
        std::string getAddress();
        void updateCounter();
        void startCounter();

    protected:

    private:
        string opCode, operand, address;
        int counAdd;
};

#endif // ADDRESS_H
