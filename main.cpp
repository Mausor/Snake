#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;
int Speed = 20;
int *w_Speed = &Speed;
int WyborLatwy = 000003;
int *w_Latwy = &WyborLatwy;
int WyborSredni = 000001;
int *w_Sredni = &WyborSredni;
int WyborTrudny = 000001;
int *w_Trudny = &WyborTrudny;
int KolorMapy = 13;
int *w_KolorMapy = &KolorMapy;
int KolorWeza = 15;
int *w_KolorWeza = &KolorWeza;
int KolorNagrody = 14;
int *w_KolorNagrody = &KolorNagrody;
int Wynik = 0;
int *w_Wynik = &Wynik;

void printBoard(char plansza[13][25], int x_prize, int y_prize);
void printVector(vector<int> snake);
int zakresRand(int minimum, int maksimum);
int ekranStartowy();
void wejscieMenu();
void Kastomizacja(int poziom);

void PoziomTrudnosci_Latwy(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Latwy*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"      |   |   |   |  "<<endl;
    cout<<"|   |   |         ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | *w_Sredni | FOREGROUND_INTENSITY);
    cout<<"Sredni";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"        |   |   |   |"<<endl;
    cout<<"  |   |   |       ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | *w_Trudny | FOREGROUND_INTENSITY);
    cout<<"Trudny";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"      |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void PoziomTrudnosci_Sredni(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | *w_Latwy | FOREGROUND_INTENSITY);
    cout<<" Latwy ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"      |   |   |   |  "<<endl;
    cout<<"|   |   |        ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Sredni*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"       |   |   |   |"<<endl;
    cout<<"  |   |   |       ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | *w_Trudny | FOREGROUND_INTENSITY);
    cout<<"Trudny";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"      |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;

}
void PoziomTrudnosci_Trudny(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | *w_Latwy | FOREGROUND_INTENSITY);
    cout<<" Latwy ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"      |   |   |   |  "<<endl;
    cout<<"|   |   |         ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | *w_Sredni | FOREGROUND_INTENSITY);
    cout<<"Sredni";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"        |   |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Trudny*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"     |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void PoziomTrudnosci(){
    int wybor = 1;
    PoziomTrudnosci_Latwy();
    char unsigned znak1;
    while(znak1 != 13){
        int znak1 = getch();
        if(znak1 == 13){
            break;
        }
        if(znak1 == 72){
                wybor--;
                if(wybor<1){
                    wybor++;
                }
        }
        else if(znak1 == 80){
                wybor++;
                if(wybor>3){
                    wybor--;
                }
        }
        if(wybor == 1){
            system("cls");
            PoziomTrudnosci_Latwy();
        }
        else if( wybor == 2){
            system("cls");
            PoziomTrudnosci_Sredni();
        }
        else if(wybor == 3){
            system("cls");
            PoziomTrudnosci_Trudny();
        }
    }

     if(wybor == 1){
        system("cls");
        *w_Latwy = 000003;
        *w_Sredni = 000001;
        *w_Trudny = 000001;
        *w_Speed = 20;
        wejscieMenu();
    }
    else if(wybor == 2){
            system("cls");
            *w_Latwy = 000001;
            *w_Sredni = 000003;
            *w_Trudny = 000001;
            *w_Speed = 5;
            wejscieMenu();
    }
    else if(wybor == 3){
            system("cls");
            *w_Latwy = 000001;
            *w_Sredni = 000001;
            *w_Trudny = 000003;
            *w_Speed = 2;
        wejscieMenu();

    }



}

void Kastomizacja_KolorMapy(){

    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorMapy);
    cout<<"*Kolor Mapy*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"     |   |   |  "<<endl;
    cout<<"|   |   |         ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorWeza);
    cout<<"Kolor Weza";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"        |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorNagrody);
    cout<<"Kolor Nagrody";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"    |   |   |  "<<endl;
    cout<<"|   |   |   |       Cofnij          |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;

}
void Kastomizacja_KolorWeza(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorMapy);
    cout<<" Kolor Mapy ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"     |   |   |  "<<endl;
    cout<<"|   |   |        ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorWeza);
    cout<<"*Kolor Weza*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"       |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorNagrody);
    cout<<"Kolor Nagrody";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"    |   |   |  "<<endl;
    cout<<"|   |   |   |       Cofnij          |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void Kastomizacja_KolorNagrody(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorMapy);
    cout<<" Kolor Mapy ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"     |   |   |  "<<endl;
    cout<<"|   |   |         ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorWeza);
    cout<<"Kolor Weza";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"        |   |   |"<<endl;
    cout<<"  |   |   |     ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorNagrody);
    cout<<"*Kolor Nagrody*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"   |   |   |  "<<endl;
    cout<<"|   |   |   |       Cofnij          |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;

}
void Kastomizacja_Cofnij(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorMapy);
    cout<<" Kolor Mapy ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"     |   |   |  "<<endl;
    cout<<"|   |   |         ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorWeza);
    cout<<"Kolor Weza";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"        |   |   |"<<endl;
    cout<<"  |   |   |     ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorNagrody);
    cout<<" Kolor Nagrody ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"   |   |   |  "<<endl;
    cout<<"|   |   |   |      ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Cofnij*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"         |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void Kastomizacja_KolorMapy_ZmianaKoloru(){
    Kastomizacja_KolorMapy();
    char unsigned znak;
    znak = getch();
    while(znak != 13){
        int znak = getch();
        if(znak == 13 || znak == 80 || znak == 72){
            break;
        }
        if(znak == 75){
                (*w_KolorMapy)--;
                if((*w_KolorMapy)==1){
                    (*w_KolorMapy)++;
                }
                system("cls");
                Kastomizacja_KolorMapy();
        }
        else if(znak == 77){
                (*w_KolorMapy)++;
                if((*w_KolorMapy)==16){
                    (*w_KolorMapy)--;
                }
                system("cls");
                Kastomizacja_KolorMapy();

        }

    }
    system("cls");
    Kastomizacja(1);
}
void Kastomizacja_KolorWeza_ZmianaKoloru(){
    Kastomizacja_KolorWeza();
    char unsigned znak;
    znak = getch();
    while(znak != 13){
        int znak = getch();
        if(znak == 13 || znak == 80 || znak == 72){
            break;
        }
        if(znak == 75){
                (*w_KolorWeza)--;
                if((*w_KolorWeza)==1){
                    (*w_KolorWeza)++;
                }
                system("cls");
                Kastomizacja_KolorWeza();
        }
        else if(znak == 77){
                (*w_KolorWeza)++;
                if((*w_KolorWeza)==16){
                    (*w_KolorWeza)--;
                }
                system("cls");
                Kastomizacja_KolorWeza();

        }

    }
    system("cls");

    Kastomizacja(2);

}
void Kastomizacja_KolorNagrody_ZmianaKoloru(){
    Kastomizacja_KolorNagrody();
    char unsigned znak;
    znak = getch();
    while(znak != 13){
        int znak = getch();
        if(znak == 13 || znak == 80 || znak == 72){
            break;
        }
        if(znak == 75){
                (*w_KolorNagrody)--;
                if((*w_KolorNagrody)==1){
                    (*w_KolorNagrody)++;
                }
                system("cls");
                Kastomizacja_KolorNagrody();
        }
        else if(znak == 77){
                (*w_KolorNagrody)++;
                if((*w_KolorNagrody)==16){
                    (*w_KolorNagrody)--;
                }
                system("cls");
                Kastomizacja_KolorNagrody();

        }

    }
    system("cls");

    Kastomizacja(3);

}
void Kastomizacja(int poziom){
        int wybor;
        if(poziom == 1){
            Kastomizacja_KolorMapy();
            wybor = 1;
        }
        else if(poziom == 2){
            Kastomizacja_KolorWeza();
            wybor = 2;
        }
        else if(poziom == 3){
            Kastomizacja_KolorNagrody();
            wybor = 3;
        }

    char unsigned znak1;
    while(znak1 != 13){
        int znak1 = getch();
        if(znak1 == 13){
            break;
        }
        if(znak1 == 72){
                wybor--;
                if(wybor<1){
                    wybor++;
                }
        }
        else if(znak1 == 80){
                wybor++;
                if(wybor>4){
                    wybor--;
                }
        }
        if(wybor == 1){
            system("cls");
            Kastomizacja_KolorMapy();
        }
        else if( wybor == 2){
            system("cls");
            Kastomizacja_KolorWeza();
        }
        else if(wybor == 3){
            system("cls");
            Kastomizacja_KolorNagrody();
        }
        else if(wybor == 4){
            system("cls");
            Kastomizacja_Cofnij();

        }
    }
    if(wybor == 1){
            system("cls");
            Kastomizacja_KolorMapy_ZmianaKoloru();
        }
        else if( wybor == 2){
            system("cls");
            Kastomizacja_KolorWeza_ZmianaKoloru();
        }
        else if(wybor == 3){
            system("cls");
            Kastomizacja_KolorNagrody_ZmianaKoloru();
        }
        else if(wybor == 4){
            system("cls");
            wejscieMenu();

        }
}


void Rozpocznij(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |    ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Rozpocznij*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"       |   |   |  "<<endl;
    cout<<"|   |   |          Menu             |   |   |"<<endl;
    cout<<"  |   |   |    Tabela wynikow     |   |   |  "<<endl;
    cout<<"|   |   |         Wyjscie       |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void Menu(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |     Rozpocznij        |   |   |  "<<endl;
    cout<<"|   |   |         ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Menu*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"            |   |   |"<<endl;
    cout<<"  |   |   |    Tabela wynikow     |   |   |  "<<endl;
    cout<<"|   |   |         Wyjscie       |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void TabelaWynikow(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |     Rozpocznij        |   |   |  "<<endl;
    cout<<"|   |   |          Menu             |   |   |"<<endl;
    cout<<"  |   |   |   ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Tabela wynikow*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"    |   |   |  "<<endl;
    cout<<"|   |   |         Wyjscie       |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void Wyjscie(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |     Rozpocznij        |   |   |  "<<endl;
    cout<<"|   |   |          Menu             |   |   |"<<endl;
    cout<<"  |   |   |    Tabela wynikow     |   |   |  "<<endl;
    cout<<"|   |   |        ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Wyjscie*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"      |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void wejscieMenu_PoziomTrudnosci(){

    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |     ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Poziom trudnosci*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"    |   |   |  "<<endl;
    cout<<"|   |   |      Kastomizacja         |   |   |"<<endl;
    cout<<"  |   |           Cofnij          |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;


}
void wejscieMenu_Kastomizacja(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |      Poziom trudnosci     |   |   |  "<<endl;
    cout<<"|   |   |     ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<"*Kastomizacja*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"        |   |   |"<<endl;
    cout<<"  |   |           Cofnij          |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
}
void wejscieMenu_Cofnij(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |      Poziom trudnosci     |   |   |  "<<endl;
    cout<<"|   |   |      Kastomizacja         |   |   |"<<endl;
    cout<<"  |   |          ";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003| FOREGROUND_INTENSITY);
    cout<<"*Cofnij*";
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000001 | FOREGROUND_INTENSITY);
    cout<<"         |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    cout<<"  |   |   |   |   |   |   |   |   |   |   |  "<<endl;
    cout<<"|   |   |   |   |   |   |   |   |   |   |   |"<<endl;
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
}
void wejscieMenu() {
    system("cls");
    int wybor = 1;
    wejscieMenu_PoziomTrudnosci();
    char unsigned znak1;
    while(znak1 != 13){
        int znak1 = getch();
        if(znak1 == 13){
            break;
        }
        if(znak1 == 72){
                wybor--;
                if(wybor<1){
                    wybor++;
                }
        }
        else if(znak1 == 80){
                wybor++;
                if(wybor>3){
                    wybor--;
                }
        }
        if(wybor == 1){
            system("cls");
            wejscieMenu_PoziomTrudnosci();
        }
        else if( wybor == 2){
            system("cls");
            wejscieMenu_Kastomizacja();
        }
        else if(wybor == 3){
            system("cls");
            wejscieMenu_Cofnij();
        }
    }
     if(wybor == 1){
        system("cls");
        PoziomTrudnosci();
    }
    else if(wybor == 2){
            system("cls");
            Kastomizacja(1);
    }
    else if(wybor == 3){
            system("cls");
        ekranStartowy();

    }
}
void wejscieTabelaWynikow(){
    fstream plik("wyniki.txt", ios::out | ios::in);
    if(!plik.is_open()){
            cout<<"E1"<<endl;
    }
    vector<int> wyniki;
    int a;
    while(plik>>a){
        wyniki.push_back(a);
    }

    for(vector<int>::iterator itr = wyniki.begin(); itr != wyniki.end(); ++itr){
        for(vector<int>::iterator it = wyniki.begin(); it != wyniki.end()-1;++it){
            if(*itr > *it){
                swap(*itr, *it);
            }
        }
    }

    vector<int>::iterator itr = wyniki.begin();
    for(int i=1;i<4;i++){
            cout<<i<<". "<<*itr<<endl;
            ++itr;

    }
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 000003 | FOREGROUND_INTENSITY);
    cout<<endl;
    cout<<"Powrot"<<endl;
    char unsigned znak;
    znak = getch();
        ekranStartowy();






}
int ekranStartowy(){


    system("cls");
    Rozpocznij();
    int wybor = 1;
    char unsigned znak1;
    while(znak1 != 13){
        int znak1 = getch();
        if(znak1 == 13){
            break;
        }
        if(znak1 == 72){
                wybor--;
                if(wybor<1){
                    wybor++;
                }
        }
        else if(znak1 == 80){
                wybor++;
                if(wybor>4){
                    wybor--;
                }
        }

        if(wybor == 1){
            system("cls");
            Rozpocznij();
        }
        else if( wybor == 2){
            system("cls");
            Menu();
        }
        else if(wybor == 3){
            system("cls");
            TabelaWynikow();
        }
        else if(wybor == 4){
            system("cls");
            Wyjscie();
        }

    }

    if(wybor == 1){
        system("cls");
        return 1;
    }
    else if(wybor == 2){
            system("cls");
            wejscieMenu();
    }
    else if(wybor == 3){
            system("cls");
            wejscieTabelaWynikow();

        return 0;
    }
    else if(wybor == 4){
            system("cls");
        cout<<"DO ZOBACZENIA!"<<endl;
        return 0;
    }

}

void dodawaniePkt(){
    if((*w_Speed)==20){
        (*w_Wynik)+=10;
    }
    else if((*w_Speed)==5){
        (*w_Wynik)+=20;
    }
    else if((*w_Speed)==2){
        (*w_Wynik)+=30;
    }
}
void TabelaPoPrzegranej(){
    fstream plik("wyniki.txt", ios::out | ios::in);
    if(!plik.is_open()){
            cout<<"E1"<<endl;
    }
    vector<int> wyniki;
    int a;
    while(plik>>a){
        wyniki.push_back(a);
    }

    for(vector<int>::iterator itr = wyniki.begin(); itr != wyniki.end(); ++itr){
        for(vector<int>::iterator it = wyniki.begin(); it != wyniki.end()-1;++it){
            if(*itr > *it){
                swap(*itr, *it);
            }
        }
    }

    vector<int>::iterator itr = wyniki.begin();
    for(int i=1;i<4;i++){
            cout<<i<<". "<<*itr<<endl;
            ++itr;

    }

}

void Napis(){
    SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | 0001 | FOREGROUND_INTENSITY);
    cout<<"######### ##      #      #      #    # #########"<<endl;
    cout<<"#         # #     #     # #     #   #  #        "<<endl;
    cout<<"#         #  #    #    #   #    # ##   #        "<<endl;
    cout<<"######### #   #   #   #     #   ##     #####    "<<endl;
    cout<<"        # #    #  #   #######   # ##   #        "<<endl;
    cout<<"        # #     # #  #       #  #   #  #        "<<endl;
    cout<<"######### #      ## #         # #    # #########"<<endl;
    Sleep(400);

    cout<<endl;
    string napis = "Wcisnij ENTER...";
    for(int i=0;i<napis.size();i++){
        cout<<napis[i];
        Sleep(100);
    }
}
void Gra(){
    fstream plik ("wyniki.txt", ios::in | ios::out | ios::app);
    if(!plik.is_open()){
        cout<<"ERROR 1"<<endl;
    }
int x_prize = zakresRand(1,11);
    int y_prize = zakresRand(1,23);
    char plansza[13][25];
    for(int i=0;i<13;i++){
        for(int j=0;j<25;j++){
            if(i==0 || i==12 || j==0 || j==24){
                plansza[i][j]='@';
            }
            else{
                plansza[i][j]=' ';
            }
        }
    }
    char znak;
    vector<int> snake;
    int x=0;
    int y=12;
    for(int i=0;i<3;i++){
        x++;
        snake.push_back(x);
        snake.push_back(y);
        plansza[x][y]='o';
    }
    plansza[x_prize][y_prize]='$';

    printBoard(plansza,x_prize,y_prize);
    cout<<"Score: "<<*w_Wynik<<endl;
    //printVector(snake);
    znak = getch();
    while(1)
    {
        if(kbhit()){
            znak = getch();
        }
        if(znak == 's'){
                if(x== x_prize && y== y_prize) {
                x++;
                dodawaniePkt();
            if(x==12){
                x -=11;
            }
            snake.push_back(x);
            snake.push_back(y);
            plansza[x][y]='o';
            x_prize = zakresRand(1,11);
            y_prize = zakresRand(1,23);
            do
            {
                x_prize = zakresRand(1,11);
                y_prize = zakresRand(1,23);
            }while(plansza[x_prize][y_prize]!=' ');
            plansza[x_prize][y_prize]='$';
            }
            else{
             plansza[snake[0]][snake[1]]=' ';
            snake.erase(snake.begin());
            snake.erase(snake.begin());
            x++;
            if(x==12){
                x -=11;
            }
            snake.push_back(x);
            snake.push_back(y);
            plansza[x][y]='o';
            }

        }
        else if(znak == 'w'){
            if(x== x_prize && y== y_prize) {
                 x--;
                 dodawaniePkt();
            if(x==0){
                x += 11;
            }
            snake.push_back(x);
            snake.push_back(y);
            plansza[x][y]='o';
            x_prize = zakresRand(1,11);
            y_prize = zakresRand(1,23);
            do
            {
                x_prize = zakresRand(1,11);
                y_prize = zakresRand(1,23);
            }while(plansza[x_prize][y_prize]!=' ');
            plansza[x_prize][y_prize]='$';
            }
            else {
            plansza[snake[0]][snake[1]]=' ';
            snake.erase(snake.begin());
            snake.erase(snake.begin());
            x--;
            if(x==0){
                x += 11;
            }
            snake.push_back(x);
            snake.push_back(y);
            plansza[x][y]='o';
        }

        }
        else if(znak == 'a'){
                 if(x== x_prize && y== y_prize) {
                     y--;
                     dodawaniePkt();
            if(y==0){
                y +=23;
            }
            snake.push_back(x);
            snake.push_back(y);
            plansza[x][y]='o';
             x_prize = zakresRand(1,11);
            y_prize = zakresRand(1,23);
            do
            {
                x_prize = zakresRand(1,11);
                y_prize = zakresRand(1,23);
            }while(plansza[x_prize][y_prize]!=' ');
            plansza[x_prize][y_prize]='$';
                     }
            else {
                plansza[snake[0]][snake[1]]=' ';
            snake.erase(snake.begin());
            snake.erase(snake.begin());
            y--;
            if(y==0){
                y +=23;
            }
            snake.push_back(x);
            snake.push_back(y);
            plansza[x][y]='o';
            }

        }
        else if(znak == 'd'){
                if(x== x_prize && y== y_prize) {
                    y++;
                    dodawaniePkt();
            if(y==24){
                y -=23;
            }
            snake.push_back(x);
            snake.push_back(y);
            plansza[x][y]='o';
               x_prize = zakresRand(1,11);
            y_prize = zakresRand(1,23);
            do
            {
                x_prize = zakresRand(1,11);
                y_prize = zakresRand(1,23);
            }while(plansza[x_prize][y_prize]!=' ');
            plansza[x_prize][y_prize]='$';
            }
            else {
                plansza[snake[0]][snake[1]]=' ';
            snake.erase(snake.begin());
            snake.erase(snake.begin());
            y++;
            if(y==24){
                y -=23;
            }
            snake.push_back(x);
            snake.push_back(y);
            plansza[x][y]='o';
            }

        }
        Sleep(*w_Speed);
        system("cls");
        printBoard(plansza,x_prize,y_prize);
        cout<<"Score: "<<*w_Wynik<<endl;
        //printVector(snake);
         vector<int>::iterator itr = snake.end()-1;
        int g=0;
        for(vector<int>::iterator ii = snake.begin(); ii != snake.end()-2; ii +=2){
            if(*ii == *(itr-1) && *(ii+1) == *itr)
            {
                g++;
            }
            //cout<<*ii<<" "<<*(ii+1)<<" ";
        }
        //cout<<*(itr-1)<<" "<<*(itr)<<endl;
        if(g>0){
            break;
        }

    }
    system("cls");
    cout<<"You lose!"<<endl;
    cout<<"Score: "<<*w_Wynik<<endl;
    plik<<*w_Wynik<<endl;
    cout<<endl;
    TabelaPoPrzegranej();
    int q;
    cin>>q;

}

int main(){


    Napis();
    unsigned char znak3;
    znak3 = getch();
    if(ekranStartowy()==0){
        return 0;
    };
    Gra();



    return 0;
}

void printBoard(char plansza[13][25], int x_prize, int y_prize){
    for(int i=0;i<13;i++)
    {

        for(int j=0;j<25;j++)
        {
            if(i==0 || i==12 || j==0 || j==24){
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorMapy);
                cout<<plansza[i][j];
            }
            else if(i==x_prize && j==y_prize){
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorNagrody);
                cout<<plansza[i][j];
            }
            else
            {
                SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), *w_KolorWeza);
                cout<<plansza[i][j];
            }

        }

        cout<<endl;
    }
}
void printVector(vector<int> snake){
    for(vector<int>::iterator itr = snake.begin(); itr != snake.end(); ++itr){
        cout<<*itr<<" ";
    }
    cout<<endl;

}
int zakresRand(int minimum, int maksimum){
    return rand()% (maksimum - minimum + 1) + minimum;
}

