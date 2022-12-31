#ifndef SOLDIER_H // abstract class
#define SOLDIER_H
#include <string>
using namespace std;

class soldier{
public:
    soldier();
    virtual void setNRIC(int inputNRIC);
    virtual int getNRIC();
    virtual void setName(string inputName);
    virtual string getName();
    virtual void setRank(string inputRank);
    virtual string getRank();
    virtual int getRankNumber();
    virtual void setPay(int inputPay);
    virtual int getPay();
    virtual void setHeight(int inputHeight);
    virtual int getHeight();
    virtual void printParade();
    virtual string generateNametag();

    int NRIC;
    string name;
    string rank;
    int rankNumber;
    int pay;
    int height;
    ~soldier();
};

#endif
