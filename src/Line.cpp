#include "Line.h"
#include "Parser.h"
#include<string>

using namespace std;

Line::Line()
{
    //ctor
    this->label = "";
    this->opCode = "";
    this->operand = "";
    this->comment = "";
}

Line::~Line()
{
    //dtor
}

void Line::setLabel(string label) {
    this->label = label;
}

void Line::setOpCode(string opCode) {
    this->opCode = opCode;
}

void Line::setOperand(string operand) {
    this->operand = operand;
}

void Line::setComment(string comment){
    this->comment = comment;
}

void Line::setLocationCounter(string locationCounter){
    this->locationCounter = locationCounter;
}

void Line::setErrorMessage(string errorMessage){
    this->errorMessage = errorMessage;
}
void Line::setInput(string input) {
    this->input = input;
}
void Line::setCommentLine(bool commentLine) {
    this->commentLine = commentLine;
}

string Line::getLabel(){
    return this->label;
}

string Line::getOpCode(){
    return this->opCode;
}

string Line::getOperand(){
    return this->operand;
}

string Line::getComment(){
    return this->comment;
}

string Line::getLocationCounter(){
    return this->locationCounter;
}

string Line::getErrorMessage(){
    return this->errorMessage;
}
string Line::getInput() {
    return this->input;
}
bool Line::isComment() {
    return this->commentLine;
}
bool Line::errorFound() {
    return this->error;
}
bool Line::symbolicOperand() {
    return this->symbol;
}
void Line::write() {
}
