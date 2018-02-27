#include <windows.h>
#include "classFileToProject.h"
#include <string.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;


void gotoxy(int x, int y) {
	COORD c;
	c.X = x-1;
	c.Y = y-1;
	SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), c);
}
void Car::setCarBrand (char *carBrand) {
    strcpy(this->carBrand,carBrand);
}

char *Car::getCarBrand () {
    return carBrand;
}

void Car::setCarModel (char *carModel) {
    strcpy(this->carModel,carModel);
}

char *Car::getCarModel () {
    return carModel;
}

void Car::setCarColor (char *carColor) {
    strcpy(this->carColor,carColor);
}
char *Car::getCarColor() {
    return carColor;
}

void Car::setAverageFuelConsumption (float averageFuelConsumption) {
    this->averageFuelConsumption = averageFuelConsumption;
}
float Car::getAverageFuelConsumption() {
    return averageFuelConsumption;
}

void Car::setHorsePowerOfCar (int horsePowerOfCar) {
    this->horsePowerOfCar = horsePowerOfCar;
}
int Car::getHorsePowerOfCar () {
    return horsePowerOfCar;
}

void Car::setYearOfTheCar (int yearOfTheCar) {
    this->yearOfTheCar=yearOfTheCar;
}
int Car::getYearOfTheCar () {
    return yearOfTheCar;
}

void Car::loadDataAboutCar (char *carBrand, char *carModel, char *carColor, float averageFuelConsumption, int horsePowerOfCar, int yearOfTheCar) {
    strcpy(this->carBrand,carBrand);
    strcpy(this->carModel,carModel);
    strcpy(this->carColor,carColor);
    this->averageFuelConsumption = averageFuelConsumption;
    this->horsePowerOfCar = horsePowerOfCar;
    this->yearOfTheCar = yearOfTheCar;
}

void Car::printDataAboutCar () {
    cout<<carBrand<<"    "<<carModel<<"    "<<carColor<<"   "<<averageFuelConsumption<<"    "<<horsePowerOfCar<<"   "<<yearOfTheCar<<endl;
}

void Car::printXYDataAboutCar () {
    gotoxy(50,5); cout<<"Marka : "<<carBrand;
    gotoxy(50,6);  cout<<"Model samochodu : "<<carModel;
    gotoxy(50,7);  cout<<"Kolor karoserii : "<<carColor;
    gotoxy(50,8);  cout<<"Moc silnika : "<<horsePowerOfCar<<"KM";
    gotoxy(50,9);  cout<<"Rok produkcji : "<<yearOfTheCar<<"r.";
    gotoxy(50,10);  cout<<"Spalanie : "<<averageFuelConsumption<<" l/100km";
}

void BaseOfCars::printAllDataAboutCar () {
    for (int i = 0; i < sizeOfCarTable; i++ ) {
        gotoxy(50,7+i); cout<<i<<".\t"<<baseOfCars[i].getCarBrand()<<"\t\t"<<baseOfCars[i].getYearOfTheCar();
    }

}

void Car::clearDataAbaoutCar () {
    strcpy(this->carBrand,"none");
    strcpy(this->carModel,"none");
    strcpy(this->carColor,"none");
    averageFuelConsumption=0;
    horsePowerOfCar=0;
    yearOfTheCar=0;
}

Car::Car () {
    strcpy(this->carBrand,"none");
    strcpy(this->carModel,"none");
    strcpy(this->carColor,"none");
    averageFuelConsumption=0;
    horsePowerOfCar=0;
    yearOfTheCar=0;
}

BaseOfCars::BaseOfCars (int size) {
    sizeOfCarTable = size;
    searchedTable= new Car [ sizeOfCarTable ];
    baseOfCars = new Car [ sizeOfCarTable ];
    for(int i = 0; i < sizeOfCarTable; i++) {
        baseOfCars[i].clearDataAbaoutCar();
        searchedTable[i].clearDataAbaoutCar();
    }
    currentPosition = 0;
}


void BaseOfCars::setCurrentPointPosition (int currentPosition) {
    this->currentPosition=currentPosition;
}

int BaseOfCars::getSizeOfCarTable () {
    return sizeOfCarTable;
}
void BaseOfCars::setSizeOfCarTable (int sizeOfCarTable) {
    this->sizeOfCarTable=sizeOfCarTable;
}
void BaseOfCars::setSizeOfSearchTable (int sizeOfSearchTable) {
    this->sizeOfSearchTable=sizeOfSearchTable;
}
int BaseOfCars::getSizeOfSearchTable () {
    return sizeOfSearchTable;
}

void BaseOfCars::addDataAboutCars (int currentPosition, int sizeOfCarTable, char *carBrand, char *carModel, char *carColor, float averageFuelConsumption, int horsePowerOfCar, int yearOfTheCar) {
    if ( currentPosition < sizeOfCarTable-1 ) {
        baseOfCars [currentPosition].loadDataAboutCar (carBrand, carModel, carColor, averageFuelConsumption, horsePowerOfCar, yearOfTheCar);
        setCurrentPointPosition(++currentPosition);
    }
    else
        baseOfCars [currentPosition].loadDataAboutCar (carBrand, carModel, carColor, averageFuelConsumption, horsePowerOfCar, yearOfTheCar);
}


void BaseOfCars::deleteDataAboutCars () {
    for (int i = 0; i < sizeOfCarTable; i++)
        baseOfCars[i].clearDataAbaoutCar();
    currentPosition = 0;
    setCurrentPointPosition (0);
}

void BaseOfCars::showCarAtPointedPosition (int currentPosition) {
    baseOfCars[currentPosition].printXYDataAboutCar();
    printBase (currentPosition) ;

}

void BaseOfCars::showCarAtPreviousPosition(int currentPosition){
    if (0 < currentPosition) {
        setCurrentPointPosition(--currentPosition);
        showCarAtPointedPosition(getCurrentPointPosition());
    }
    else if ( 0 == currentPosition ) {
        setCurrentPointPosition(getSizeOfCarTable()-1);
        showCarAtPointedPosition(getCurrentPointPosition());
    }
}

void BaseOfCars::showCarAtNextPosition(int currentPosition, int sizeOfCarTable) {
    if ( currentPosition < sizeOfCarTable-1 && currentPosition >= 0){
        setCurrentPointPosition(++currentPosition);
        showCarAtPointedPosition(getCurrentPointPosition());
    }
    else if ( sizeOfCarTable-1 == currentPosition ) {
        setCurrentPointPosition(0);
        showCarAtPointedPosition(getCurrentPointPosition());

    }
}

int BaseOfCars::getCurrentPointPosition () {
    return currentPosition;
}


bool BaseOfCars::writeDataToFile_txt () {
    if ((zp=fopen("DataCarFile_txt", "wb")) == NULL) {
        fclose(zp);
        return 0;
    }
    fwrite(&sizeOfCarTable, sizeof(sizeOfCarTable), 1, zp);
    fwrite(&currentPosition, sizeof(currentPosition), 1, zp);
    for ( int i=0 ; i<sizeOfCarTable ; i++ )
        fwrite(&baseOfCars[i], sizeof(baseOfCars[i]), 1, zp);
    fclose(zp);
    return 1;
}
bool BaseOfCars::writeDataFromFile_txt () {
    if ((zp=fopen("DataCarFile_txt", "rb")) == NULL) {
        fclose(zp);
        return 0;
    }
    fread(&sizeOfCarTable, sizeof(sizeOfCarTable), 1, zp);
    fread(&currentPosition, sizeof(currentPosition), 1, zp);
    for ( int i=0 ; i<sizeOfCarTable ; i++ )
        fread(&baseOfCars[i], sizeof(baseOfCars[i]), 1, zp);
    fclose(zp);
    currentPosition = 0;
    return 1;
}

void BaseOfCars::deleteCarAtCurrentPosition (int sizeOfCarTable, int currnetPosition) {
    if( sizeOfCarTable > 0 && currnetPosition >= 0) {
        for ( int i = currnetPosition; i < sizeOfCarTable-1; i++ )
            baseOfCars[i]=baseOfCars[i+1];
        setSizeOfCarTable(--sizeOfCarTable);
        if ( currnetPosition > 0 )
            setCurrentPointPosition(--currentPosition);
    }
    else if ( sizeOfCarTable == 0 ) {
            currentPosition =  -1; // -1 oznacza pusta tablice
            sizeOfCarTable = 0;
    }
}


int BaseOfCars::checkIntroduceNumber (int fromNumber, int toNumber,int whatToCheck) {

    cin>>whatToCheck;
    cin.ignore();
    if(whatToCheck >= fromNumber && whatToCheck <= toNumber)
        return whatToCheck;
    return 0;
}

char* BaseOfCars::checkIntroduceString (int fromNumber, int toNumber,char *whatToCheck) {

    cin>>whatToCheck;
    cin.ignore();
    if( strlen(whatToCheck) >= fromNumber && strlen(whatToCheck) <= toNumber)
        return whatToCheck;
    return "NULL";
}

void BaseOfCars::enterTheDataIntoTheDatabase () {

            system ("cls");
            gotoxy(45, 5); cout<<"Prosze o wprowadzenie danych auta do bazy: ";
            gotoxy(48, 6); cout<<"Marka auta : ";
            gotoxy(48,7); cout<<"Model auta : ";
            gotoxy(48,8);  cout<<"Kolor karoserii : ";
            gotoxy(48,9);  cout<<"Moc silnika (konie mechaniczne) : ";
            gotoxy(48,10);  cout<<"Rok produkcji : ";
            gotoxy(48,11);  cout<<"Srednie spalanie : ";

            gotoxy(48,6); cout<<"Marka auta : ";
            strcpy(this->carBrand,checkIntroduceString(3,10,carBrand));
                if( strcmp(carBrand, "NULL") == 0)
                    goto EndWhile;
            gotoxy(48,7); cout<<"Model auta : ";
            strcpy(this->carModel,checkIntroduceString(2,10,carModel));
                if( strcmp(carModel, "NULL") == 0)
                    goto EndWhile;
            gotoxy(48,8);  cout<<"Kolor karoserii : ";
            strcpy(this->carColor,checkIntroduceString(3,20,carColor));
                if( strcmp(carColor, "NULL") == 0)
                    goto EndWhile;
            cin.ignore();
            gotoxy(48,9);  cout<<"Moc silnika (konie mechaniczne) : ";
            horsePowerOfCar=checkIntroduceNumber(10,1000,horsePowerOfCar);
                if( horsePowerOfCar == 0 )
                    goto EndWhile;
            gotoxy(48,10);  cout<<"Rok produkcji : ";
            yearOfTheCar=checkIntroduceNumber(1950,2018,yearOfTheCar);
                if ( yearOfTheCar == 0 )
                    goto EndWhile;
            gotoxy(48,11);  cout<<"Srednie spalanie : ";
            averageFuelConsumption=checkIntroduceNumber(1,20,averageFuelConsumption);
                if ( averageFuelConsumption == 0 )
                    goto EndWhile;

            addDataAboutCars (getCurrentPointPosition(), getSizeOfCarTable(), carBrand, carModel, carColor, averageFuelConsumption, horsePowerOfCar, yearOfTheCar);

    EndWhile: ;
    system ("cls");
}

bool BaseOfCars::sortByYear(int l, int r)
{
	int left=l;
	int right=r;
	int x = baseOfCars[(l+r)/2].getYearOfTheCar();
	Car temp;
	do
    {
        while( baseOfCars[ left ].getYearOfTheCar() < x )
             left++;

        while( baseOfCars[ right ].getYearOfTheCar() > x )
             right--;

        if( left <= right ) {
            temp=baseOfCars[left];
            baseOfCars[left]=baseOfCars[right];
            baseOfCars[right]=temp;
            left++;
            right--;
        }
    } while( left <= right );

    if( l < right ) this->sortByYear( l, right );
    if( r> left ) this->sortByYear(left, r );
}

bool BaseOfCars::loadDataFromTheTxtFile( ) {

    fstream plik;
    plik.open("PLIK_WSADOWY.txt" , ios::in);

    int i = 0 ;

    if(plik.good() == true) {
        while( !plik.eof() ) {

            string carBrand;
            string carModel;
            string carColor;
            float averageFuelConsumption;
            int horsePowerOfCar;
            int yearOfTheCar;

            plik >> carBrand >> carModel >> carColor >> averageFuelConsumption >> horsePowerOfCar >> yearOfTheCar ;

            char *a = &carBrand[0u];
            char *b = &carModel[0u];
            char *c = &carColor[0u];

            baseOfCars[i].loadDataAboutCar(a, b, c, averageFuelConsumption, horsePowerOfCar, yearOfTheCar);
            i++;
        }
    }
    else
        return false;
    return true;
}



bool BaseOfCars::searchYear(int min, int max) {

    currentPositionOfSearchTable=0;
    sizeOfSearchTable=0;
    for(int i=0; i < getSizeOfCarTable()-1 ; i++)
     if(baseOfCars[i].getYearOfTheCar()>=min && baseOfCars[i].getYearOfTheCar()<=max) {
       searchedTable[sizeOfSearchTable]=baseOfCars[i];
       sizeOfSearchTable++;
     }
    if(sizeOfSearchTable!=0)
        return 1;
    return 0;
}

void BaseOfCars::printSearch (int currentPositionOfSearchTable) {

    for(int i=0; i < sizeOfSearchTable; i++) {
        if(i==currentPositionOfSearchTable) {
            gotoxy(48,12+i);
            cout<<"->"<<searchedTable[i].getCarBrand();
            gotoxy(60,12+i);
            cout<<searchedTable[i].getYearOfTheCar();
    }
    gotoxy(50,12+i);
    cout<<searchedTable[i].getCarBrand();
    gotoxy(60,12+i);
    cout<<searchedTable[i].getYearOfTheCar();
    }
}

void BaseOfCars::printBase (int currentPositionOfSearchTable) {

    for(int i=0; i < sizeOfCarTable; i++) {
        if(i==currentPositionOfSearchTable) {
            gotoxy(48,12+i);
            cout<<"->"<<baseOfCars[i].getCarBrand();
            gotoxy(60,12+i);
            cout<<baseOfCars[i].getYearOfTheCar();
    }
    gotoxy(50,12+i);
    cout<<baseOfCars[i].getCarBrand();
    gotoxy(60,12+i);
    cout<<baseOfCars[i].getYearOfTheCar();
    }
}



void BaseOfCars::showCarAtPointedPosition1 (int currentPositionOfSearchTable) {
    if(currentPositionOfSearchTable==-1)
        goto End;
    searchedTable[getCurrentPositionOfSearchTable()].printXYDataAboutCar();
    printSearch(currentPositionOfSearchTable);
    End: ;

}

void BaseOfCars::showCarAtPreviousPosition1(){
    if( currentPositionOfSearchTable > 0) {
            currentPositionOfSearchTable--;
            showCarAtPointedPosition1(currentPositionOfSearchTable);
    }
    else if ( currentPositionOfSearchTable == 0) {
        currentPositionOfSearchTable = sizeOfSearchTable-1;
        showCarAtPointedPosition1(currentPositionOfSearchTable);
    }
}


void BaseOfCars::showCarAtNextPosition1() {
    if ( currentPositionOfSearchTable < sizeOfSearchTable-1 ) {
        currentPositionOfSearchTable++;
        showCarAtPointedPosition1(currentPositionOfSearchTable);
    }
    else if ( currentPositionOfSearchTable == sizeOfSearchTable-1 ) {
        currentPositionOfSearchTable = 0;
        showCarAtPointedPosition1(currentPositionOfSearchTable);
    }


}

    int BaseOfCars::getCurrentPositionOfSearchTable() {
        return currentPositionOfSearchTable;

    }
    void BaseOfCars::setCurrentPositionOfSearchTable(int currentPositionOfSearchTable) {
        this->currentPositionOfSearchTable=currentPositionOfSearchTable;

    }

bool BaseOfCars::searchBrand(char *keyword) {

    currentPositionOfSearchTable=0;
  	sizeOfSearchTable=0;

  	for(int i=0; i < getSizeOfCarTable(); i++) {
	  if( strcmp ( keyword, baseOfCars[i].getCarBrand() ) == 0) {
        searchedTable[sizeOfSearchTable] = baseOfCars[i];
	  	sizeOfSearchTable++;
	  }
	}
    if(sizeOfSearchTable!=0)
        return 1;
    return 0;
  }

void BaseOfCars::clearSearchTabel() {

    for(int i = 0; i < sizeOfSearchTable; i++)
        searchedTable[i].clearDataAbaoutCar();

}

bool youAreSureOfYourDecision (char *introducedString, bool CLS, int x, int y) {
    if(1==CLS)
        system("cls");
    char typedKeyOnTheKeyboardDecision = '\0';
    gotoxy(x,y); cout<<"Czy na pewno chcesz "<<introducedString<<" ?\t[T]ak lub [N]ie.\n";
    typedKeyOnTheKeyboardDecision=getch();
    do {
        if(typedKeyOnTheKeyboardDecision=='t' || typedKeyOnTheKeyboardDecision=='T') {
            return 1;
            break;
        }
        else if (typedKeyOnTheKeyboardDecision=='n' || typedKeyOnTheKeyboardDecision=='N') {
            return 0;
            break;
        }
        gotoxy(x,y); cout<<"Niepoprwana decyzja. Prosze o wybranie [T]ak lub [N]ie.                                            \n";
        typedKeyOnTheKeyboardDecision=getch();
    }while ( typedKeyOnTheKeyboardDecision != 'n' && typedKeyOnTheKeyboardDecision != 'N' );

    return 0;
}

void displayStringSlowlyOnTheScreen (char *introducedStringConstant,
 char *introducedStringVariable, int howManyTimes,int x, int y, int displaySpeed,bool CLS) {

    int introducedStringLenght = strlen(introducedStringVariable);
    if(1==CLS)
        system("cls");
    for (int i = 0; i < howManyTimes; i++){
    gotoxy(x,y);
    cout<<introducedStringConstant<<"                                                                              ";
    gotoxy(x,y);
    cout<<introducedStringConstant;
        for (int j = 0; j < introducedStringLenght; j++) {
            cout<<introducedStringVariable[j];
            Sleep(displaySpeed);
        }
    }
}

void printExit () {
    displayStringSlowlyOnTheScreen({""},{"Mozna teraz bezpiecznie"},1,50,10,20,1);
    displayStringSlowlyOnTheScreen({""},{"wylaczyc komputer"},1,52,11,20,0);
    displayStringSlowlyOnTheScreen({""},{"..."},3,69,11,500,0);
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
}
