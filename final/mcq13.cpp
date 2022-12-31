#include <iostream>

class ParentClass {
    public:
        virtual void virtualFunction() { 
            std::cout << "ParentClass output" << std::endl; 
        }
};

class ChildClass: public ParentClass {
    public:
        void virtualFunction() { 
           std::cout << "ChildClass output" << std::endl; 
        }
};

int main()
{
    ParentClass* var1 = new ParentClass();
    ParentClass* var2 = new ChildClass();
    ChildClass* var3 = new ChildClass();

    var1->virtualFunction();
    var2->virtualFunction();
    var3->virtualFunction();
}
