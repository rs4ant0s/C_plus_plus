#include <iostream>
#include <clocale>
#include <cstdio>
#include <cstdlib>



using namespace std; // declarar o namespace std

int voo[3][7]; // matriz definido globalmente
int escolha;
int coluna, linha;

void menu();
void recolha();
int validarhora(int hora,int coluna, int linha);
int validarminuto(int minuto,int coluna, int linha);
void pausa();
void mostrar();
void gotoxy(int coluna, int linha);

int main(){
    setlocale(LC_ALL,"Portuguese");
    menu();
    return 0;
}

void menu(){
    do{
    system("cls");
    cout<<"/*** Programa Voar ***/"<<endl<<endl;
    cout<<"1-Recolha de dados"<<endl;
    cout<<"2-Mostrar os dados com os tempos"<<endl;
    cout<<"3-Sair"<<endl<<endl;
    cout<<"Digite a sua escolha:";
    cin>>escolha;
    switch(escolha){
        case 1:
            recolha();
            break;
        case 2:
            mostrar();
            break;
        case 3:
            exit(0);
        default:
            cout<<endl<<"Opcao inv�lida."<<endl;
            pausa();
    }
    }while(escolha!=3);
}
void recolha(){
    system("cls");
    coluna=1;linha=1;
    gotoxy(coluna,linha);
    cout<<"Recolha de dados dos voos";
    linha+=2;
    gotoxy(coluna,linha);
    cout<<"N� HP MP HD MD";
    linha++;
    for(int i=0;i<3;i++){
        linha++;
        gotoxy(1,linha);cout<<(i+1);
        coluna=4;
        voo[i][0]=validarhora(voo[i][0],coluna,linha);
        coluna=7;
        voo[i][1]=validarminuto(voo[i][1],coluna,linha);
        coluna=10;
        voo[i][2]=validarhora(voo[i][2],coluna,linha);
        coluna=13;
        voo[i][3]=validarminuto(voo[i][3],coluna,linha);
        // valida��o dos dados ok!
        // calcular a chegada e verificar a situa��o (dia seguinte, ou pr�prio dia)
        voo[i][4]=voo[i][0]+voo[i][2];
        voo[i][5]=voo[i][1]+voo[i][3];
        if(voo[i][5]>59){
            voo[i][4]++;
            voo[i][5]-=60;
        }
        if(voo[i][4]>23){
            voo[i][4]-=24;
            voo[i][6]=1; //dia seguinte
        }
        else{
            voo[i][6]=0;
        }
    }
    pausa();

}

void mostrar(){
    system("cls");
    cout<<endl<<"Listagem dos voos"<<endl;
    cout<<"N�\tHP\tMP\tHD\tMD\tHC\tMC\tSitua��o"<<endl;
    for(int i=0;i<3;i++){
        cout<<(i+1);
        for(int j=0;j<6;j++){
            cout<<"\t"<<voo[i][j];
        }
        if(voo[i][6]==0){
            cout<<"\tPr�prio dia."<<endl;
        }
        else{
            cout<<"\tDia seguinte."<<endl;
        }
    }
    system("pause");
}

int validarhora(int hora,int coluna, int linha){
    do{
        gotoxy(coluna,linha);
        cin>>hora;
        if(hora<0 || hora>23){
            gotoxy(coluna+10,linha);
            cout<<"A hora n�o � v�lida !";
        } 
    }while(hora<0 || hora>23);
    gotoxy(coluna+10,linha);
    cout<<"                               ";
    return(hora);
}

int validarminuto(int minuto,int coluna, int linha){
    do{
        gotoxy(coluna,linha);
        cin>>minuto;
        if(minuto<0 || minuto>59){
            gotoxy(coluna+10,linha);
            cout<<endl<<"O minuto n�o � v�lido !";
        } 
    }while(minuto<0 || minuto>59);
    gotoxy(coluna+10,linha);
    cout<<endl<<"                                ";
    return(minuto);
}

void pausa(){
    cout<<endl<<"Aguarde 3 seg. sff."<<endl;
    Sleep(3000);
}
void gotoxy(int coluna, int linha){
    COORD point;
    point.X=coluna; point.Y=linha;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}