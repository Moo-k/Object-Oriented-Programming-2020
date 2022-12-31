#ifndef SPECIALIST_H // specialist (3sg,2sg,1sg,ssg,msg)
#define SPECIALIST_H
#include <string>
using namespace std;
#include "soldier.h"

class specialist : public soldier{
public:
    specialist();
    specialist(string inputName, int inputNRIC, string inputRank, int inputHeight);
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
    ~specialist();
};

#endif
