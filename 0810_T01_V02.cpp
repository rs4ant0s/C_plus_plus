#include <iostream>
#include <clocale>
#include <cstdio>
#include <windows.h>


using namespace std; // declarar o namespace std

int voo[3][7]; // matriz definido globalmente
int escolha;

void menu();
void recolha();
int validarhora(int hora);
int validarminuto(int minuto);
void pausa();
void mostrar();

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
            cout<<endl<<"Opcao inválida."<<endl;
            pausa();
    }
    }while(escolha!=3);
}
void recolha(){
    system("cls");
    cout<<"Recolha de dados dos voos"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Voo Nº"<<(i+1)<<endl;
        cout<<"Partida"<<endl;
        voo[i][0]=validarhora(voo[i][0]);
        voo[i][1]=validarminuto(voo[i][1]);
        cout<<"Duração"<<endl;
        voo[i][2]=validarhora(voo[i][2]);
        voo[i][3]=validarminuto(voo[i][3]);
        // validação dos dados ok!
        // calcular a chegada e verificar a situação (dia seguinte, ou próprio dia)
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
    cout<<"Nº\tHP\tMP\tHD\tMD\tHC\tMC\tSituação"<<endl;
    for(int i=0;i<3;i++){
        cout<<(i+1);
        for(int j=0;j<6;j++){
            cout<<"\t"<<voo[i][j];
        }
        if(voo[i][6]==0){
            cout<<"\tPróprio dia."<<endl;
        }
        else{
            cout<<"\tDia seguinte."<<endl;
        }
    }
    system("pause");
}

int validarhora(int hora){
    do{
        cout<<"Digite a hora entre 0 e 23:";
        cin>>hora;
        if(hora<0 || hora>23) cout<<endl<<"A hora não é válida !";
    }while(hora<0 || hora>23);
    return(hora);
}

int validarminuto(int minuto){
    do{
        cout<<"Digite os minutos entre 0 e 59:";
        cin>>minuto;
        if(minuto<0 || minuto>59) cout<<endl<<"O minuto não é válido !";
    }while(minuto<0 || minuto>59);
    return(minuto);
}

void pausa(){
    cout<<endl<<"Aguarde 3 seg. sff."<<endl;
    Sleep(3000);
}