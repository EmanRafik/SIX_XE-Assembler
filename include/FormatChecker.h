#ifndef FORMATCHECKER_H
#define FORMATCHECKER_H
#include<string>
#include<regex>

using namespace std;
using namespace std::regex_constants;


class FormatChecker
{
    public:
        FormatChecker();
        virtual ~FormatChecker();
        bool formatTwo(string operand);
        bool formatThree(string operand);
        bool validLabel(string label);

    protected:

    private:
};

#endif // FORMATCHECKER_H
