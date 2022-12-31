#include <iostream>
#include <math.h>

// DEFINE ABSTRACT BASE CLASS Func HERE
class Func {
public:
	virtual double feval(double x) = 0;
};

// DEFINE DERIVED CLASS Cubic HERE
class Cubic : public Func {
public:
	Cubic(double inputa, double inputb, double inputc,double inputd){ // constructs Cubic with input variables assigned to a,b,c,d
		a = inputa;
		b = inputb;
		c = inputc;
		d = inputd;
	}
	double feval(double x){
		double output = 0;
		output = a*x*x*x + b*x*x + c*x + d; // evaluate ax3 + bx2 + cx + d 
		return output;
	}
private:
	double a;
	double b;
	double c;
	double d;
};

class Integrator {
  public:
    Integrator(Func* f);
    void SetFunc(Func* f);
    double Integrate(double a, double b);

  private:
    Func* fn;
};

void Integrator::SetFunc(Func* f)
{
  fn=f;
}

Integrator::Integrator(Func* f)
{
  fn=f;
}

double Integrator::Integrate(double a, double b) {
  double val=0.0;
  double step = 0.001; // set step for integration to be 0.001
  for (double x=a; x<=b; x+=0.001) {
    val += step*fn->feval(x);
  }
  return val;
}


int main()
{
  // Declare Func object(s) of derived class Cubic
  Cubic c1(3,2,4,1);
  Cubic c2(1,-1,6,1);

  // Create integrator object
  Integrator myintegrator(&c1);

  // Work out integral of 3x^3 + 2x^2 + 4x + 1 between 0 and 1 and print it
  std::cout << myintegrator.Integrate(0.0, 1.0) << std::endl;

  // Change the function to integrate to the polynomial x^3 - x^2 + 6x + 1 and work it out
  myintegrator.SetFunc(&c2);
  std::cout << myintegrator.Integrate(0.0, 1.0) << std::endl;
}
