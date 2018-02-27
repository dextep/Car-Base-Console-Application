#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "classFileToProject.h"

using namespace std;



int main() {
    char carColor[N], typedKeyOnTheKeyboardMenu,typedKeyOnTheKeyboardMenu1;
    int introducedSizeOfCarTable, horsePowerOfCar,introducedPointPosition, yearOfTheCar, makedDecision;
    float carMileage;
    BaseOfCars tableOfCars (100);




    gotoxy(40,8);cout<<"[1] POBIERZ BAZE Z PLIKU.";
    gotoxy(40,10);cout<<"[2] UTWORZ NOWA BAZE.";


    while(1){
        typedKeyOnTheKeyboardMenu=getch();
        switch (typedKeyOnTheKeyboardMenu) {

            case '1':
                displayStringSlowlyOnTheScreen({"POBIERANIE BAZY Z PLIKU "},{"..."},1,50,10,300,1);
                tableOfCars.setSizeOfCarTable(35);
                tableOfCars.loadDataFromTheTxtFile();
                system("CLS");
             goto EndWhile;

            case '2':
                system("CLS");
                gotoxy(40,10);cout<<"Prosze o podanie ilosci elementow tablicy : ";
                cin>>introducedSizeOfCarTable;
                cin.ignore();
                tableOfCars.setSizeOfCarTable(introducedSizeOfCarTable);
                system("CLS");
             goto EndWhile;
        }

    }
    EndWhile: ;


    do
    {
        gotoxy( 45, 2 );cout<<"**********************************************";
        gotoxy( 45, 3 );cout<<"   M E N U   B A Z Y   S A M O C H O D O W    ";
        gotoxy( 45, 4 );cout<<"**********************************************";
        gotoxy( 3, 5 );cout << "[1]\tDodaj auto do bazy o nr."<<tableOfCars.getCurrentPointPosition ();
        gotoxy( 3, 7 );cout<<"[2]\tPrzeszukaj baze samochodow.";
        gotoxy( 3, 9 );cout << "[3]\tSzybki podglad bazy.";
        gotoxy( 3, 11 );cout << "[4]\tSortowanie wedlug rocznika.";
        gotoxy( 3, 13 );cout << "[5]\tWyczysc baze.";
        gotoxy( 3, 15 );cout << "[6]\tZapis bazy.";
        gotoxy( 3, 17 );cout << "[7]\tOdczyt bazy.";
        gotoxy( 3, 19 );cout << "[8]\tWyszukaj samochod po marce.";
        gotoxy( 3, 21 );cout << "[9]\tWyszukaj samochod z rocznika.";
        gotoxy( 3, 23 );cout << "[0]\tWYJSCIE\n\n\n\n";

        typedKeyOnTheKeyboardMenu=getch();
        switch (typedKeyOnTheKeyboardMenu)
        {
            case '1':
                tableOfCars.enterTheDataIntoTheDatabase();
                break;
            case '2':
                system ("cls");

                gotoxy(25,3);cout<<"[s] poprzedni";gotoxy(45,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[f] usun";gotoxy(90,3);cout<<"[ESC] menu";
                tableOfCars.showCarAtPointedPosition(tableOfCars.getCurrentPointPosition());

                do {
                    typedKeyOnTheKeyboardMenu1=getch();
                    switch (typedKeyOnTheKeyboardMenu1) {

                        case 's':
                            system ("cls");
                            gotoxy(25,3);cout<<"[s] poprzedni";gotoxy(45,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[f] usun";gotoxy(90,3);cout<<"[ESC] menu";
                            tableOfCars.showCarAtPreviousPosition(tableOfCars.getCurrentPointPosition());

                         break;

                        case 'd':
                            system ("cls");
                            gotoxy(25,3);cout<<"[s] poprzedni";gotoxy(45,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[f] usun";gotoxy(90,3);cout<<"[ESC] menu";
                            tableOfCars.showCarAtNextPosition(tableOfCars.getCurrentPointPosition(), tableOfCars.getSizeOfCarTable());
                         break;

                        case 'f':
                            makedDecision = youAreSureOfYourDecision({"usuwanie aktualnego elementu"},1,50,13);
                            if( makedDecision == 1) {
                                tableOfCars.deleteCarAtCurrentPosition(tableOfCars.getSizeOfCarTable(), tableOfCars.getCurrentPointPosition());
                                 gotoxy(50,14);cout<<"Usuwanie elementu "<<tableOfCars.getCurrentPointPosition()+1<<" zakonczone powodzeniem."<<endl;
                                 break;
                            }
                            else if ( makedDecision == 0) {
                                gotoxy(50,14);cout<<"Usuwanie elementu "<<tableOfCars.getCurrentPointPosition()<<" anulowane."<<endl;
                                break;
                            }
                    }
                } while( getch() !=27  );


                system ("cls");
                break;



            case '3':

                do {
                    system ("cls");
                    tableOfCars.printAllDataAboutCar();
                    gotoxy(40,6); cout<<"Szybki podglad. Wprowadz numer bazy by wyswietlic : ";
                    cin>>introducedPointPosition;
                    cin.ignore();
                }
                while ( introducedPointPosition < 0 || introducedPointPosition > tableOfCars.getSizeOfCarTable()-1 );

                system ("cls");
                tableOfCars.showCarAtPointedPosition(introducedPointPosition);
                cin.ignore();
                system ("cls");

                break;


            case '4':
                tableOfCars.sortByYear(0,tableOfCars.getSizeOfCarTable()-1);
                displayStringSlowlyOnTheScreen({"SORTOWANIE BAZY"},{"..."},1,50,10,200,1);
                system ("cls");
                tableOfCars.printAllDataAboutCar();
                cin.ignore();
                system ("cls");
                break;


            case '5':
                makedDecision = youAreSureOfYourDecision({"wyczyscic baze"},1,40,9);
                if( makedDecision == 1) {
                        displayStringSlowlyOnTheScreen({"USUWANIE"},{"..."},3,50,10,200,1);
                        tableOfCars.deleteDataAboutCars();

                }
                else if ( makedDecision == 0)
                    displayStringSlowlyOnTheScreen({"USUWANIE ANULOWANE"},{""},0,50,10,0,1);

                system ("cls");
                break;


            case '6':
                makedDecision = youAreSureOfYourDecision ({"nadpisac baze"},1,40,9);
                if( makedDecision == 1) {
                    if(tableOfCars.writeDataToFile_txt() == 1)
                        displayStringSlowlyOnTheScreen({"ZAPISYWANIE BAZY"},{"..."},1,50,10,300,1);
                    else
                        cout<<"BLAD ZAPISU!"<<endl;
                }
                else if ( makedDecision == 0)
                    displayStringSlowlyOnTheScreen({"ZAPISYWANIE BAZY ANULOWANO"},{" "},1,50,10,900,1);
                system ("cls");
                break;

            case '7':
                makedDecision = youAreSureOfYourDecision ({"odczytac baze"},1,40,9);
                if( makedDecision == 1) {
                    if(tableOfCars.writeDataFromFile_txt() == 1)
                        displayStringSlowlyOnTheScreen({"ODCZYTYWANIE BAZY"},{"..."},1,50,10,300,1);
                    else
                        cout<<"BLAD ODCZYTU!"<<endl;
                }
                else if ( makedDecision == 0)
                    displayStringSlowlyOnTheScreen({"ODCZYT BAZY ANULOWANO"},{" "},1,50,10,900,1);
                system ("cls");
                break;

            case '0':
                printExit();
                return 0;
                break;

            case '8':
                char mark [N];
                cout<<"Wprowadz szukana marke : ";
                strcpy(mark,tableOfCars.checkIntroduceString(2,20,mark));
                if( strcmp(mark, "NULL") == 0){
                    system ("cls");
                    break;
                }
                system ("cls");
                if(tableOfCars.searchBrand(mark)==0){
                    displayStringSlowlyOnTheScreen({"BRAK SAMOCHODOW O PODANEJ MARCE "},{" "},1,50,10,900,1);
                    system ("cls");
                    break;
                }

                displayStringSlowlyOnTheScreen({"PRZESZUKIWANIE BAZY"},{"..."},1,50,10,300,1);
                system ("cls");
                gotoxy(45,3);cout<<"[s] poprzedni";gotoxy(60,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[ESC] menu";
                tableOfCars.showCarAtPointedPosition1(tableOfCars.getCurrentPositionOfSearchTable());
                do {
                    typedKeyOnTheKeyboardMenu1=getch();
                    switch (typedKeyOnTheKeyboardMenu1) {

                        case 's':
                            system ("cls");
                            gotoxy(45,3);cout<<"[s] poprzedni";gotoxy(60,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[ESC] menu";
                            tableOfCars.showCarAtPreviousPosition1();
                         break;

                        case 'd':
                            system ("cls");
                            gotoxy(45,3);cout<<"[s] poprzedni";gotoxy(60,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[ESC] menu";
                            tableOfCars.showCarAtNextPosition1();
                         break;


                    }
                } while( getch() !=27  );
                tableOfCars.clearSearchTabel();
                system ("cls");
                break;

            case '9':
                int mi,ma;
                cout<<"Od roku "; cin>>mi;
                if( mi < 1950 ) {
                    system ("cls");
                    break;
                }
                cout<<"Do roku: "; cin>>ma;
                if( ma > 2018 ) {
                    system ("cls");
                    break;
                }
                system ("cls");
                if(tableOfCars.searchYear(mi,ma)==0){
                    displayStringSlowlyOnTheScreen({"BRAK SAMOCHODOW Z WYBRANEGO ROCZNIKA"},{" "},1,50,10,900,1);
                    system ("cls");
                    break;
                }



                displayStringSlowlyOnTheScreen({"PRZESZUKIWANIE BAZY"},{"..."},1,50,10,300,1);
                system ("cls");
                gotoxy(45,3);cout<<"[s] poprzedni";gotoxy(60,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[ESC] menu";
                tableOfCars.showCarAtPointedPosition1(tableOfCars.getCurrentPositionOfSearchTable());

                do {
                    typedKeyOnTheKeyboardMenu1=getch();
                    switch (typedKeyOnTheKeyboardMenu1) {

                        case 's':
                            system ("cls");
                            gotoxy(45,3);cout<<"[s] poprzedni";gotoxy(60,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[ESC] menu";
                            tableOfCars.showCarAtPreviousPosition1();
                         break;

                        case 'd':
                            system ("cls");
                            gotoxy(45,3);cout<<"[s] poprzedni";gotoxy(60,3);cout<<"[d] nastepny";gotoxy(75,3);cout<<"[ESC] menu";
                            tableOfCars.showCarAtNextPosition1();
                         break;


                    }
                } while( getch() !=27  );
                tableOfCars.clearSearchTabel();
                system ("cls");
                break;

        }
    }
    while (typedKeyOnTheKeyboardMenu != 0 );
    return 0;
}
