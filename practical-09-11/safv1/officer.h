#ifndef OFFICER_H // officer (2lt,lta,cpt,maj,ltc,col)
#define OFFICER_H
#include <string>
using namespace std;
#include "soldier.h"

class officer : public soldier{
public:
    officer();
    officer(string inputName, int inputNRIC, string inputRank, int inputHeight);
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
    ~officer();
};

#endif
