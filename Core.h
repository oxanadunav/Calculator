#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <queue>

class Core
{
private:
    std::queue<int> operations;
    std::queue<double> operands;
    int operation;
    double operand;    
    double result;
    bool operatorClicked;

public:
    Core();
    static Core *inst;
    static Core* getInstance();

    void pushOperation(int operation);
    void pushOperand(double operand);
    double getResult();
    void setOperatorClicked(bool operatorClicked);
    void calculate(double operand, int operation);
    void clear();
};

#endif // CONTROLLER_H
