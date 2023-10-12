#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstdlib>


using namespace std; // declarar o namespace std

void gotoxy(int coluna, int linha);


int main(){
    setlocale(LC_ALL,"Portuguese");
    gotoxy(5,10);cout<<"Estou na coluna 5 e linha 10";
    gotoxy(15,15);cout<<"Estou na coluna 15 e linha 15";
    return 0;
}

void gotoxy(int coluna, int linha){
    COORD point;
    point.X=coluna; point.Y=linha;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}