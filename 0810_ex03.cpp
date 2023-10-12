#include <iostream>
#include <clocale>
#include <windows.h>

/*
Desenvolver um programa em C++ para carregar um array com 5 notas (entre 0 e 20). Criar uma menu com a opção de
recolha e opção para listar.
*/

using namespace std; // declarar o namespace std

int notas[5]; // array definido globalmente
int escolha;

void menu();
void recolha();
void mostrar();


int main(){
    setlocale(LC_ALL,"Portuguese");
    menu();
    return 0;
}

void menu(){
    system("cls");
    cout<<"/*** Notas de Alunos ***/"<<endl<<endl;
    cout<<"1-Recolha de notas"<<endl;
    cout<<"2-Listagem de notas"<<endl;
    cout<<"9-Sair"<<endl<<endl;
    cout<<"Digite a sua escolha:";
    cin>>escolha;
    switch(escolha){
        case 1:
            recolha();
            menu();
        case 2:
            mostrar();
            menu();
        case 9:
            cout<<"Fim do programa."<<endl;
            Sleep(2000);
            break;
        default:
            cout<<endl<<"Opcao inválida."<<endl;
            Sleep(2000);
            menu();
    }
}

void recolha(){
    system("cls");
    cout<<"/*** Recolha de notas ***/"<<endl;
    for(int i=0;i<5;i++){
        do{
            cout<<endl<<"Digite a "<<(i+1)<<"ª nota entre 0 e 20:";
            cin>>notas[i];
            if(notas[i]<0 || notas[i]>20) cout<<endl<<"Nota inválida!!!";
        }while(notas[i]<0 || notas[i]>20);    
    }    
    cout<<endl<<"Recolha efetuada. Aguarde para voltar ao menu."<<endl;
    Sleep(2000);
}
void mostrar(){
    system("cls");
    cout<<"/*** listagem de notas ***/"<<endl;
    for(int i=0;i<5;i++){
      cout<<notas[i]<<" / ";
    }    
    cout<<endl<<"Fim da listagem. Aguarde para voltar ao menu."<<endl;
    Sleep(2000);
}