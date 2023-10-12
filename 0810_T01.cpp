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
    int hp,mp,hd,md,hc,mc,situacao;
    system("cls");
    cout<<"Recolha de dados dos voos"<<endl;
    for(int i=0;i<3;i++){
        cout<<"Voo Nº"<<(i+1)<<endl;
        cout<<"Partida"<<endl;
        hp=validarhora(hp);
        mp=validarminuto(mp);
        cout<<"Duração"<<endl;
        hd=validarhora(hd);
        md=validarminuto(md);
        // validação dos dados ok!
        // calcular a chegada e verificar a situação (dia seguinte, ou próprio dia)
        hc=hp+hd;mc=mp+md;
        if(mc>59){
            hc++;mc-=60;
        }
        if(hc>23){
            hc-=24;situacao=1; //dia seguinte
        }
        else{
            situacao=0;
        }
        // armazenar os dados
        voo[i][0]=hp;voo[i][1]=mp;
        voo[i][2]=hd;voo[i][3]=md;
        voo[i][4]=hc;voo[i][5]=mc;voo[i][6]=situacao;
    }
    pausa();

}

void mostrar(){
    system("cls");
    cout<<endl<<"Listagem dos voos"<<endl;
    cout<<"Nº\tHP\tMP\tHD\tMD\tHC\tMC\tSituação"<<endl;
    for(int i=0;i<3;i++){
        cout<<(i+1);
        cout<<"\t"<<voo[i][0]<<"\t"<<voo[i][1]<<"\t"<<voo[i][2]<<"\t"<<voo[i][3]<<"\t"<<voo[i][4]<<"\t"<<voo[i][5];
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