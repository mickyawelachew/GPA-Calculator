//Micky Awelachew-Yirga
//gpa.cpp
//3/7/2025

//Purpose: it calculates the GPA of college students more accurately by using
//their percentage grade rather than using the leter grade.

//It's main objective is to improve accuracy and prevent the loss of GPA points
//which can accumulate in the end.

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


int main(){

  int classes = 0, credits = 0;
  double percentage = 0.000;
  cout << "\n\n-------------- GPA Calculator --------------\n\n";
  cout << endl << "How many classes are you calculating for?: ";
  cin >> classes;
  int fcredits[100];
  double fpercentage[100];
  double calc1[100];

  cout << endl << "--> Example percentage input:\n    if you get 92%, enter 0.92.";
  for (int i = 0; i < classes; i++){
    cout << endl  << endl << "Enter your percentage grade for class " << i+1  << ": ";
    cin >> percentage;//data inputs
    if (percentage > 2){
      percentage /= 100.00;
    }
    fpercentage[i] += static_cast<double>(percentage);
    cout << "How much credits was this class?: ";
    cin >> credits;//data inputs
    fcredits[i] += credits;
    calc1[i] = fpercentage[i] * fcredits[i];
  }

  double b = 0.000, c = 0.000, gpa = 0.000;
  for (int i = 0; i < classes; i++){
    b += calc1[i];
  }
  for (int i = 0; i < classes; i++){
    c += fcredits[i];

  }

  //data processing
  gpa = (b / c);
  gpa *= 4;

  //data outputs
  cout << endl << endl << setw(28) << right << "You have a GPA of: " << fixed
       << setprecision(3) << gpa <<  " !!" << endl << endl;
  cout << "--------------------------------------------\n\n\n";

}
