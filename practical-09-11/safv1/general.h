#ifndef GENERAL_H // general (bg,mg,lg)
#define GENERAL_H
#include <string>
using namespace std;
#include "soldier.h"

class general : public soldier{
public:
    general();
    general(string inputName, int inputNRIC, string inputRank, int inputHeight);
    void setNRIC(int inputNRIC);
    int getNRIC();
    void setName(string inputName);
    string getName();
    void setRank(string inputRank);
    string getRank();
    int getRankNumber();
    void setPay(int inputPay);
    int getPay();
    void setHeight(int inputHeight);
    int getHeight();
    void printParade();
    ~general();
};

#endif
