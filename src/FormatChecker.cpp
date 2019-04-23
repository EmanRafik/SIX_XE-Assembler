#include "FormatChecker.h"
#include<regex>

using namespace std;
using namespace std::regex_constants;

FormatChecker::FormatChecker()
{
    //ctor
}

FormatChecker::~FormatChecker()
{
    //dtor
}

bool FormatChecker::formatTwo(string operand)
{
    std::smatch m;
    std::regex e("(A|X|B|T|S|L),(A|X|B|T|S|L)", ECMAScript | icase);
    if (std::regex_search(operand,m,e))
    {
        return true;
    }
    return false;
}
bool FormatChecker::formatThree(string operand)
{
    std::smatch m;
    /**check**/
    std::regex e("(C'[a-zA-Z]')|X'[A-F0-9]'", ECMAScript | icase);
    if (std::regex_search(operand,m,e))
    {
        int x = m.length();
        int y = operand.length();
        if(x==y)
        {
            return true;
        }
    }
    /**check immediate**/
    std::smatch m1;
    std::regex e1("((#)?(-)?[0-9]+)|((@)?[0-9A-F]+)|([0-9A-F]+(,X)?)", ECMAScript | icase);
    if (std::regex_search(operand,m1,e1))
    {
        int x = m1.length();
        int y = operand.length();
        if(x==y)
        {
            if (x <= 4)
                return true;
            if(x == 5 && operand.at(0) == '#' || operand.at(0) == '@')
                return true;
            if(x == 6 && operand.at(x-2)==',')
                return true;
            if (operand.at(0) == '#' || operand.at(0) == '@')
            {
                if (operand.at(1) >= '0' && operand.at(1) <= '9'){
                    return false;
                }
            }
            else if (operand.at(0) >= '0' && operand.at(0) <= '9')
            {
                return false;
            }
        }

    }
    std::smatch m2;
    std::regex e2("(\\w+(,X)?)|((#)\\w+)|((@)\\w+)", ECMAScript | icase);
    if (std::regex_search(operand,m2,e2))
    {
        int x = m2.length();
        int y = operand.length();
        if (x == y)
        {
            if (operand.at(0) == '#' || operand.at(0) == '@')
            {
                if (!(operand.at(1) >= 'a' && operand.at(1) <= 'z') && !(operand.at(1) >= 'A' && operand.at(1) <= 'Z')) {
                    return false;
                }
            }
            else if (!(operand.at(0) >= 'a' && operand.at(0) <= 'z') && !(operand.at(0) >= 'A' && operand.at(0) <= 'Z'))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool validLabel(string label) {
    std::smatch m;
    std::regex e("(([a-z]|[A-Z])\\w+", ECMAScript | icase);
    if (std::regex_search(label,m,e))
    {
        int x = m.length();
        int y = label.length();
        if (x==y) {
            return true;
        }
    }
    return false;
}
