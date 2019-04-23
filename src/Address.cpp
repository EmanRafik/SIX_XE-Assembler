#include <iostream>
//to use stringstream
#include <sstream>
//convert lowercase
#include <algorithm>
#include <string>
#include "Address.h"

using namespace std;

Address::Address(string opCode, string operand)
{
    //ctor
    this->opCode = opCode;
    this->operand = operand;
    this->address = "";
    this->counAdd = -1;
}

Address::~Address()
{
    //dtor
}


string Address::getAddress(){
    return this->address;
}

void Address::startCounter() {
    std::stringstream str;
    str << this->operand;
    str >> std::hex >> counAdd;
    std::stringstream ss;
    ss << std::hex << counAdd;
    address = ss.str();
}

void Address::updateCounter() {
    if (counAdd != -1) {
    std::transform(opCode.begin(), opCode.end(), opCode.begin(), ::tolower);
    std::stringstream str;
    str << this->operand;
    if (opCode.find('+') != std::string::npos) {
        counAdd = counAdd + 4;
    } else if (opCode.compare("resb") == 0 ) {
        int n = 0;
        str >> n;
        counAdd = counAdd + n;
    } else if (opCode.compare("resw") == 0 ) {
        int n = 0;
        str >> n;
        counAdd = counAdd + n * 3;
    } else if (opCode.compare("byte") == 0 ) {
        counAdd = counAdd + operand.length() - 3;
    } else if (opCode.compare("rmo") == 0) {
        counAdd = counAdd + 2;
    } else if ((opCode.find("add")|opCode.find("sub")|
               opCode.find("mul")|opCode.find("div")) &&
               opCode.length() == 4) {
        counAdd = counAdd + 2;
    } else if (opCode.find("tix") &&
               opCode.length() == 4) {
        counAdd = counAdd + 2;
    } else if (opCode.find("comp") &&
               opCode.length() == 5) {
        counAdd = counAdd + 2;
    } else {
        counAdd = counAdd + 3;
    }

    std::stringstream ss;
    ss << std::hex << counAdd;
    address = ss.str();
    std::cout << counAdd << " ==> " << address << std::endl;
    }
}
