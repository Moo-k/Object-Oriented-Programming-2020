#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std;

class animal{
public:
    animal(string n, int v);
    void set_volume(int v);
    int get_volume();
    void set_name(string n);
    virtual string get_name() = 0;
    int get_animalID();
private:
    int volume;
protected:
	string name;
	int animalID;
};

#endif
