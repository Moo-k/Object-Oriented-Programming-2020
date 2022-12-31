#include <iostream>
using namespace std;
#include <string>
#include <vector>

int main(void){
	int ace[2] = {1,11};
	vector<int*> v;
	int *ptr = &ace[0];
	v.push_back(ptr);
	v.push_back(new int (10));
  vector<int> vsums;
  vsums.push_back(0);
	vector<int*> w;
	w.push_back(ptr);
	w.push_back(new int (11));
  vector<int> wsums;
  wsums.push_back(0);
  vector<int> tempsum;
  vector<int*> x;
  x.push_back(ptr);
  x.push_back(new int (6));
  x.push_back(ptr);
  vector<int> xsums;
  xsums.push_back(0);
  vector<int*> y;
  y.push_back(new int (3));
  y.push_back(new int (6));
  y.push_back(new int (7));
  vector<int> ysums;
  ysums.push_back(0);
  vector<int*> z;
  z.push_back(new int (10));
  z.push_back(new int (7));
  z.push_back(new int (4));
  z.push_back(ptr);
  vector<int> zsums;
  zsums.push_back(0);
////////////////////////////////////////
  for(int i = 0; i < v.size(); i++){
    if (*(v[i]) == 1){
      for (int j = 0; j < vsums.size(); j++){
        tempsum.push_back(vsums[j] + 1);
        tempsum.push_back(vsums[j] + 11);
      }
      for (int k = 0; k < tempsum.size(); k++){
        if (tempsum[k] > 21){
          tempsum[k] = 0;
        }
      }
      vsums = tempsum;
      tempsum.clear();
    } else{
      for (int j = 0 ; j < vsums.size(); j++){
        vsums[j] += *(v[i]);
      }
      for (int k = 0 ; k < vsums.size(); k++){
        if (vsums[k] > 21){
          vsums[k] = 0;
        }
      }
    }
  }
  cout << "vsums: " << endl;
  for (int i = 0; i < vsums.size(); i++){
    cout << vsums[i] << endl;
  }
//////////////////////////////////////////////////////////////
  for(int i = 0; i < w.size(); i++){
    if (*(w[i]) == 1){
      for (int j = 0; j < wsums.size(); j++){
        tempsum.push_back(wsums[j] + 1);
        tempsum.push_back(wsums[j] + 11);
      }
      for (int k = 0; k < tempsum.size(); k++){
        if (tempsum[k] > 21){
          tempsum[k] = 0;
        }
      }
      wsums = tempsum;
      tempsum.clear();
    } else{
      for (int j = 0 ; j < wsums.size(); j++){
        wsums[j] += *(w[i]);
      }
      for (int k = 0 ; k < wsums.size(); k++){
        if (wsums[k] > 21){
          wsums[k] = 0;
        }
      }
    }
  }
  cout << "wsums: " << endl;
  for (int i = 0; i < wsums.size(); i++){
    cout << wsums[i] << endl;
  }
/////////////////////////////////////////////////////////
  for(int i = 0; i < x.size(); i++){
    if (*(x[i]) == 1){
      for (int j = 0; j < xsums.size(); j++){
        tempsum.push_back(xsums[j] + 1);
        tempsum.push_back(xsums[j] + 11);
      }
      for (int k = 0; k < tempsum.size(); k++){
        if (tempsum[k] > 21){
          tempsum[k] = 0;
        }
      }
      xsums = tempsum;
      tempsum.clear();
    } else{
      for (int j = 0 ; j < xsums.size(); j++){
        xsums[j] += *(x[i]);
      }
      for (int k = 0 ; k < xsums.size(); k++){
        if (xsums[k] > 21){
          xsums[k] = 0;
        }
      }
    }
  }
  cout << "xsums: " << endl;
  for (int i = 0; i < xsums.size(); i++){
    cout << xsums[i] << endl;
  }
///////////////////////////////////////////////////
  for(int i = 0; i < y.size(); i++){
    if (*(y[i]) == 1){
      for (int j = 0; j < ysums.size(); j++){
        tempsum.push_back(vsums[j] + 1);
        tempsum.push_back(vsums[j] + 11);
      }
      for (int k = 0; k < tempsum.size(); k++){
        if (tempsum[k] > 21){
          tempsum[k] = 0;
        }
      }
      ysums = tempsum;
      tempsum.clear();
    } else{
      for (int j = 0 ; j < ysums.size(); j++){
        ysums[j] += *(y[i]);
      }
      for (int k = 0 ; k < ysums.size(); k++){
        if (ysums[k] > 21){
          ysums[k] = 0;
        }
      }
    }
  }
  cout << "ysums: " << endl;
  for (int i = 0; i < ysums.size(); i++){
    cout << ysums[i] << endl;
  }
////////////////////////////////////////////////////
  for(int i = 0; i < z.size(); i++){
    if (*(z[i]) == 1){
      for (int j = 0; j < zsums.size(); j++){
        tempsum.push_back(zsums[j] + 1);
        tempsum.push_back(zsums[j] + 11);
      }
      for (int k = 0; k < tempsum.size(); k++){
        if (tempsum[k] > 21){
          tempsum[k] = 0;
        }
      }
      zsums = tempsum;
      tempsum.clear();
    } else{
      for (int j = 0 ; j < zsums.size(); j++){
        zsums[j] += *(z[i]);
      }
      for (int k = 0 ; k < zsums.size(); k++){
        if (zsums[k] > 21){
          zsums[k] = 0;
        }
      }
    }
  }
  cout << "zsums: " << endl;
  for (int i = 0; i < zsums.size(); i++){
    cout << zsums[i] << endl;
  }
}
