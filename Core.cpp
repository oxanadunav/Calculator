#include "Core.h"
#include <iostream>
#include <math.h>
using namespace std;

Core* Core::inst = NULL;

Core::Core() {}

Core* Core::getInstance() {
    if(!inst){
        inst = new Core();
    }
    return inst;
}

void Core::pushOperation(int operation) {
    this->operations.push(operation);
}

void Core::pushOperand(double operand) {
    this->operands.push(operand);
}

double Core::getResult() {
    return this->result;
}

void Core::setOperatorClicked(bool operatorClicked) {
    this->operatorClicked = operatorClicked;
}

void Core::calculate(double operand, int operation) {

    if(!operatorClicked){
        if(operation != operations.front()){
            operations.pop();
            operations.push(operation);
        }
        return;
    }

    if(operation != 5){
        operations.push(operation);
    }

    operatorClicked = false;
    operands.push(operand);
    result = operands.front();

    if(operands.size() == 2){
        result = operands.front();
        operands.pop();
        this->operation = operations.front();
        operations.pop();

        switch(this->operation){
            case 0: {
                result += operands.front();
                break;
            }

            case 1: {
                result -= operands.front();
                break;
            }
            case 2: {
                result *= operands.front();
                break;
            }
            case 3: {
                result /= operands.front();
                break;
            }

            default: {
                break;
            }
        }

        operands.pop();
        operands.push(result);
    }
}

void Core::clear() {
    operands = queue<double>();
    operations = queue<int>();
    result = 0;
    operand = 0;
    cout << operands.size();
}
