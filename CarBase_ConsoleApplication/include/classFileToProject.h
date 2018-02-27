#include <windows.h>
#include <stdio.h>

#ifndef CLASSFILETOPROJECT_H
#define CLASSFILETOPROJECT_H
#include <string>
#include <fstream>

#define N 30

void displayStringSlowlyOnTheScreen (char *introducedStringConstant,
 char *introducedStringVariable, int howManyTimes,int x, int y, int displaySpeed, bool CLS);
bool youAreSureOfYourDecision (char *introducedString, bool CLS, int x, int y);
void gotoxy (int x, int y);
void printExit ();

class Car {
protected:
    char carBrand [N];
    char carModel [N];
    char carColor [N];
    float averageFuelConsumption;
    int horsePowerOfCar;
    int yearOfTheCar;


public:
    Car ();
    void setCarBrand (char *carBrand);
    char *getCarBrand ();
    void setCarModel (char *carModel);
    char *getCarModel ();
    void setCarColor (char *vehicleColor);
    char *getCarColor ();
    void setAverageFuelConsumption (float averageFuelConsumption);
    float getAverageFuelConsumption ();
    void setHorsePowerOfCar (int horsePowerOfCar);
    int getHorsePowerOfCar ();
    void setYearOfTheCar (int yearOfTheCar);
    int getYearOfTheCar ();

    void loadDataAboutCar (char *carBrand, char *carModel, char *carColor, float averageFuelConsumption, int horsePowerOfCar, int yearOfTheCar);
    void printDataAboutCar ();
    void printXYDataAboutCar ();
    void clearDataAbaoutCar ();
};
class BaseOfCars : public Car {
private:
    Car *baseOfCars;
    Car *searchedTable;
    int currentPosition;
    int sizeOfCarTable;
    int sizeOfSearchTable;
    int currentPositionOfSearchTable;
    FILE *zp;
public:
    BaseOfCars (int size);
    void addDataAboutCars (int currentPosition,int sizeOfCarTable, char *carBrand, char *carModel, char *carColor, float averageFuelConsumption, int horsePowerOfCar, int yearOfTheCar); //add and move next
    void deleteDataAboutCars ();

    int getSizeOfSearchTable ();
    void setSizeOfSearchTable (int sizeOfSearchTable);
    void showCarAtPointedPosition (int currentPosition);
    void showCarAtPreviousPosition(int currentPosition);
    void showCarAtNextPosition(int currentPosition,int introducedSizeOfCarTable);
    int getCurrentPointPosition ();
    void setCurrentPointPosition (int currentPosition);
    bool writeDataToFile_txt ();
    bool writeDataFromFile_txt ();
    void deleteCarAtCurrentPosition (int sizeOfCarTable, int currnetPosition);
    int getSizeOfCarTable ();
    void setSizeOfCarTable (int sizeOfCarTable);
    void printAllDataAboutCar ();
    void enterTheDataIntoTheDatabase ();
    bool sortByYear(int l, int r);
    bool searchBrand(char *keyword);
    bool loadDataFromTheTxtFile( );
    bool searchYear(int min, int max);
    void printSearch (int currentPositionOfSearchTable);
    void showCarAtNextPosition1() ;
    void showCarAtPreviousPosition1();
    void showCarAtPointedPosition1 (int currentPositionOfSearchTable) ;
    int getCurrentPositionOfSearchTable();
    void setCurrentPositionOfSearchTable(int currentPositionOfSearchTable);
    void printBase (int currentPositionOfSearchTable) ;
    int checkIntroduceNumber (int fromNumber, int toNumber,int whatToCheck);
    char* checkIntroduceString (int fromNumber, int toNumber,char *whatToCheck);
    void clearSearchTabel();

};

#endif // CLASSFILETOPROJECT_H
