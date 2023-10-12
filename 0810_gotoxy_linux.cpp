#include <iostream>
#include <cstdlib>

using namespace std;

void gotoxy(int coluna, int linha);

int main() {
    gotoxy(5, 10);
    cout << "Estou na coluna 5 e linha 10";
    gotoxy(15, 15);
    cout << "Estou na coluna 15 e linha 15";
    return 0;
}

void gotoxy(int coluna, int linha) {
    // ANSI escape codes for moving the cursor
    cout << "\033[" << linha << ";" << coluna << "H";
}