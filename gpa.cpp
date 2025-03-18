//Micky Awelachew-Yirga
//gpa.cpp
//3/7/2025

//Purpose: it calculates the GPA of college students more accurately by using
//our percentage grade rather than using our letter grade.

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
  
  do{
    cout << endl << "How many classes are you calculating for?: ";
    cin >> classes;

    if (classes > 100){
      cout << endl;
      cerr << "Unfortunately, you cannot calculate your gpa for more than 100 ";
        cerr << "classes!!" << endl;
      cout << "Instead, you can calculate your gpa for the first half, then the"
              "second half, then finally add those up and divide it by 2" << endl;
    }
  
  while (classes <= 0){
    
    while (classes < 0){
      cout << endl;
      cerr << "Error!!" << endl;
      cerr << "You cannot have less than 0 classes!! Try again." << endl;
      cout << "How many classes are you calculating for?: ";
      cin >> classes;
    }
    
    if (classes == 0){
      char a;
      cout << endl;
      cerr << "You must have a class to calculate your gpa for!!" << endl;
      cout << "Enter Y if you want to try again or N to quit: ";
      cin >> a;
      
      while (a != 'Y' && a != 'y' && a != 'N' && a != 'n'){
        cout << endl;
        cerr << "Error!!" << endl;
        cerr << "You can only enter Y for yes or N for no!! Try again." << endl;
        cout << "Enter Y if you want to try again or N to quit";
        cin >> a;
      }
      
      if (a == 'Y' || a == 'y'){
        cout << endl;
        cout << "How many classes are you calculating for?: ";
        cin >> classes;
      }else if(a == 'N' || a == 'n'){
        return 0;
      }  
    }
  }
  }while (classes <= 0 || classes > 100);//end of do while loop
  
  int fcredits[100];
  double fpercentage[100];
  double calc1[100];

  cout << endl << "--> Example percentage input:\n    if you get 92%, enter 0.92.";

  //data inputs
  for (int i = 0; i < classes; i++){
    
    do {
      cout << endl  << endl << "Enter your percentage grade for class " << i+1  << ": ";
      cin >> percentage;
    
    while (percentage < -100){
      cout << endl;
      cerr << "Error!!" << endl;
      cerr << "Percentage cannot be less than -100!! Try again." << endl;
      cout << "Enter your percentage grade for class " << i + 1 << ": ";
      cin >> percentage;
    }
    
    while (percentage > 125){
      cout << endl;
      cerr << "Error!!" << endl;
      cerr << "Percentage cannot be greater than 125!! Try again." << endl;
      cout << "Enter your percentage grade for class " << i + 1 << ": ";
      cin >> percentage;
    }
    
    }while (percentage < -100 || percentage > 125);

    if (percentage > 1.25 || percentage < -1.25){
      percentage /= 100.00;
    }
    
    fpercentage[i] += static_cast<double>(percentage);
    cout << "How much credits was this class?: ";
    cin >> credits;//data inputs

    while (credits < 0){
      cout << endl;
      cerr << "Error!!" << endl;
      cerr << "You cannot input credits less than 0!! Try again." << endl;
      cout << "How much credits was this class?: ";
      cin >> credits;
    }
    
    fcredits[i] += credits;
    calc1[i] = fpercentage[i] * fcredits[i];
  }//end of for loop

  
  double b = 0.000, gpa = 0.000;
  int c = 0;
  for (int i = 0; i < classes; i++){
    b += calc1[i];
  }
  for (int i = 0; i < classes; i++){
    c += fcredits[i];
  }
  
  //data processing
  gpa = (b / (double) c);
  gpa *= 4;

  //data outputs
  cout << endl << endl << setw(28) << right << "You have a GPA of: " << fixed
       << setprecision(3) << gpa <<  " !!" << endl << endl;
  cout << "--------------------------------------------\n\n\n";

}


//I set the maximum percentage to 125% due to the scenario when a student has
//lots of bonus points.
