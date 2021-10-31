//File to hold functions for this program
#include <iostream>
#include <string>
#include <cmath>
#include "Input_Validation_Extended.h"

using namespace std; 

//Prototypes
void showMenu();
void menuOption(string);
void veloCalc();
void accelCalc();
void motionMenu();
void maCalc();
void msCalc();
void mv2Calc();
void mvCalc();
void motionChoice();
void motionCalc();
void newtSecond();
void weightCalc();
void momenCalc();


//Definitions
void menuOption()
  {
    string color = "\x1b[" + to_string(32) + ";1m";
    string reset = "\x1b[0m";
    char menuChoice;
    
    do
    {

      showMenu(); //show menu options for calculations
      
      cout << "Please select a calculation (e or E to exit): ";
      cout << color;
      menuChoice=validateChar(menuChoice);
      cout << reset;
      if (menuChoice == '1')
      {
      veloCalc();
      }
      else if (menuChoice == '2')
      {
      accelCalc();
      }
      else if (menuChoice == '3')
      {
      motionCalc();
      }
      else if (menuChoice == '4')
      {
      newtSecond();
      }
      else if (menuChoice == '5')
      {
        weightCalc();
      }
      else if (menuChoice == '6')
      {
        momenCalc();
      }
      else if (menuChoice == 'E' || menuChoice == 'e')
      {
        cout << "Exit...";
      }
      else
      {
        cout << "Error-Invalid input: Please try again!\n";
        cout << "Choose a calculation: "; 
        
      }
    }while(menuChoice != 'E' && menuChoice != 'e'); //DeMorgan's Law!!!
  }
 
 void showMenu()
  {
    cout << "\nChoose the calculaion you would like to perform: " << endl;
    cout << "************************************************" << endl; 

    cout << "1. Velocity\n";
    cout << "2. Acceleration\n";
    cout << "3. Motion\n";
    cout << "4. Newton's Second Law\n";
    cout << "5. Weight\n";
    cout << "6. Momentum\n";
    cout << "e. exit\n"; 


  }


void veloCalc()
  {
    double ds;
    string dsUnits;
    double dt;
    string dtUnits;

    cout << "Please enter the units for your calculation: \n";
    cout << "Unit for Distance: "; 
    dsUnits=validateString(dsUnits); 
    cout << endl << "Unit for Time: ";
    dtUnits=validateString(dtUnits); 


    cout << "Please enter the value for Distance: ";
    ds=validateDouble(ds);
    cout << "Please enter the value for Time: ";
    dt=validateDouble(dt);

    double v = ds / dt;

    cout << ds << " / " << dt << " = " << v << dsUnits << "/" << dtUnits << endl;
  }

void accelCalc()
  { 
    double dv;
    string vUnits;
    double dvi;
    
    double dt;
    string dtUnits;

    cout << "Please enter the units for your calculation: \n";
    cout << "Unit for Velocity: "; 
    vUnits=validateString(vUnits);
    cout << endl << "Unit for Time: ";
    dtUnits=validateString(dtUnits);

    cout << "Please enter the value for Initial Velocity: ";
    dvi=validateDouble(dvi);
    cout << "Please enter the value for Velocity: ";
    dv=validateDouble(dv);
    cout << "Please enter the value for Time: ";
    dt=validateDouble(dt);


    double A = (dv-dvi) / dt;

    cout << dv - dvi << " / " << dt << " = " << A << vUnits << "/" << dtUnits << " ";
  }

void maCalc()
  {
    double vi;
    string viUnits;
    double a;
    string aUnits;
    double t; 
    string tUnits;

      cout << "Please enter Initial Velocity Units: ";
        viUnits=validateString(viUnits);

      cout << "Please enter Acceleration Units: ";
        aUnits=validateString(aUnits);

      cout << "Please enter time units: ";
        tUnits=validateString(tUnits);

      cout << "Please enter the velocity at t=0: ";
      vi=validateDouble(vi);
      cout << endl << "Please enter the acceleration value: ";
      a=validateDouble(a);
      cout << endl << "Please enter the time value: ";
      t=validateDouble(t);

    double v = vi + (a)*(t);

    cout << "Velocity is " << v << viUnits; 

  }

void msCalc()
  {
    double initPosit; 
    double initVelo;
    double time;
    double accel;

    cout << "Please enter the value for Initial Position: ";
    initPosit=validateDouble(initPosit);
    cout << "Please enter the value for Initial Velocity: ";
    initVelo=validateDouble(initVelo);

    cout << "Please enter the value for Time: ";
    time=validateDouble(time);

    cout << "Please enter the value for Acceleration: ";
    accel=validateDouble(accel);

    double posit = initPosit + (initVelo*time) + (accel*time*time)/2;

    cout << "Final Position is " << posit;
  }

void mv2Calc()
  {
    double initVelo;
    double accel;
    double posit;
    double initPosit;

    cout << "Please enter value for Initial Velocity: ";
      initVelo=validateDouble(initVelo);
    cout << "Please enter value for Acceleration: ";
      accel=validateDouble(accel);
    cout << "Please enter value for Position: ";
      posit=validateDouble(posit);
    cout << "Please enter value for Initial Position: ";
      initPosit=validateDouble(initPosit);

    double veloSquare = initVelo*initVelo + (2*accel)*(posit-initPosit);

    cout << "Velocity equals " << sqrt(veloSquare);
  }

void mvCalc()
  {
    double velo;
    double initVelo;
    
    cout << "Please enter the Value for Velocity: ";
    velo=validateDouble(velo);
    cout << "Please enter the Value for Initial Velocity: ";
    initVelo=validateDouble(initVelo);

    double veloAvg = (velo + initVelo) / 2;

    cout << "Average Velocity = " << veloAvg;

  }

void motionMenu()
  {
    cout << "\nWhich motion calculation would you like to perform?:\n";
    cout << "****************************************************\n";
    cout << "1. Ma: solve for V\n";
    cout << "2. Ms: solve for s\n";
    cout << "3. Mv2: solve for v^2\n";
    cout << "4. Mv: solve for v_bar\n";
  }
void motionCalc()
  {
    char choice;

    do
    {
          motionMenu();  //Dr_T Edit
        
          cout << "Please select a calculation (e or E to exit): "; //Dr_T edit
          choice=validateChar(choice);
          if (choice == '1')
          {
            maCalc();
          }
          else if (choice == '2')
          {
            msCalc();
          }
          else if (choice == '3')
          {
            mv2Calc();
          }
          else if (choice == '4')
          {
            mvCalc();
          }
          else if(choice == 'E' || choice == 'e' ) //Dr_T edit
          {
            cout << "Exit..."; 
          }
            else
          {
            
              cout << "Error: Invalid response, please try again\n";
              cout << "Choose a calculation: "; 
              choice = validateChar(choice);    
          }
    }while(choice != 'E' && choice != 'e'); //DeMorgan's Law!!! 
  }
void newtSecond()
  {
    string mUnit;
    double mass;
    string aUnit;
    double accel;

    cout << "Please enter the unit for Mass: ";
    mUnit=validateString(mUnit);
    cout << "Mass unit is " << mUnit << endl;

    cout << "Please enter the unit for Acceleration: ";
    aUnit=validateString(aUnit);
    cout << "Acceleration unit is: " << aUnit << endl;

    cout << "Please enter the value for Mass: ";
    mass=validateDouble(mass);
    cout <<"Mass = " << mass << mUnit << endl;

    cout << "Please enter the value for Acceleration: ";
    accel=validateDouble(accel);
    cout << "Acceleration = " << accel << aUnit << endl;

    double force = (mass * accel);

    cout << "Force = " << mass << mUnit << " * " << accel << aUnit << endl;
    cout << "Force = " << force;
  }

void weightCalc()
  {
    double mass;
  double gravity = 9.81;

  cout << "Please enter the mass of the object: ";
  mass=validateDouble(mass);
  cout << "Mass is " << mass << endl;

  cout << "Acceleration due to Gravity (g) is 9.81 m/s^2" << endl;

  cout << "Weight = " << mass << " * " << gravity << endl;

  double w = (mass*gravity);

  cout << "Weight = " << w;

  }

void momenCalc()
  {
  string massUnits;
  double mass;
  string veloUnits;
  double velocity;

  cout << "Momentum = Mass * Velocity " << endl;
  cout << "Please enter units for Mass: ";
  massUnits=validateString(massUnits);
  cout << "Mass is in " << massUnits << endl;
  cout << "Please enter the value for Mass: ";
  mass=validateDouble(mass);
  cout << "Mass is " << mass << massUnits << endl;

  cout << "Please enter units for Velocity: ";
  veloUnits=validateString(veloUnits);
  cout << "Velocity is in " << veloUnits << endl;
  cout << "Please enter the value for Velocity: ";
  velocity=validateDouble(velocity); 
  cout << "Mass is " << mass << massUnits << endl;

  double p = (mass*velocity);
  cout << "Momentum = " << mass << " * " << velocity << endl;
  cout << "Momentum = " << p;
  }
