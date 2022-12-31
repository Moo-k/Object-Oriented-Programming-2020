#ifndef MAN_H // man (pte,lcp,cpl)
#define MAN_H
#include <string>
using namespace std;
#include "soldier.h"

class man : public soldier{
public:
    man();
    man(string inputName, int inputNRIC, string inputRank, int inputHeight);
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
    string generateNametag();
    ~man();
};

#endif
