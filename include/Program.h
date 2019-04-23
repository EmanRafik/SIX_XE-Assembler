#ifndef PROGRAM_H
#define PROGRAM_H
#include<string>

using namespace std;

class Program
{
public:
    virtual ~Program();
    void pass1();
    static Program *getInstance()
    {
        if (!instance)
        {
            instance = new Program();
        }
        return instance;
    }

    void setName(string name);
    void setstartingAdddress(string startingAdddress);
    void setLength(string Length);
    string getName();
    string getStartingAddress();
    string getLength();

protected:

private:
    Program();
    static Program *instance;
    string name, startingAdddress, length;
};

#endif // PROGRAM_H
