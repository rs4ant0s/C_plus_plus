#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring> 
//#include <windows.h>

using namespace std;

void gotoxy(int x, int y);
void layout();
void erase_eol(int x, int y);

int modelo,linha,nenc=0,detalhe=0,opcao;
string modelos[4]= {"Pequeno","Médio","Grande","Muito Grande"};
float precos[4]={8,10,12,15};
int modelo_qtd[4][2];
float total=0;
bool existe=false;
bool volta_menu=false;

int main(){
    setlocale(LC_ALL,"Portuguese");
    layout();
    linha=5;

    while(true){
        do{
            existe=false;
            gotoxy(2,linha);
            cin>>modelo;
            if(modelo<1 || modelo>4){
                gotoxy(55,linha);
                cout<<"Número de modelo inexistente. Digite 1, 2, 3 ou 4.";
            }
        }while(modelo<1 || modelo>4);
        // eliminar a linha caso exista erro no nº do modelo
        erase_eol(55,linha);
        gotoxy(2,linha);
        cout<<modelo;
        gotoxy(11,linha);
        cout<<modelos[modelo-1];
        gotoxy(39,linha);
        cout<<precos[modelo-1];
        // ver se o modelo j� existe na encomenda
        for(int i=0;i<4;i++){
            if(modelo_qtd[i][0]==modelo){
                gotoxy(55,linha);
                cout<<"Modelo já existe na encomenda.";
                cout.flush();//limpar o buffer de saida para a msg aparecer 
                //Sleep(3000);
                sleep(3); 
                // apagar a linha da consola
                erase_eol(0,linha);
                existe=true;
                break;
            }
        }

        if(!existe){
            // procurar a 1ª posiçãoo livre da matriz modelos_qtd
            for(int i=0;i<4; i++) {
                if(modelo_qtd[i][0]==0) {
                    modelo_qtd[i][0]=modelo;
                    do{
                        gotoxy(27,linha);
                        cin>>modelo_qtd[i][1];
                        if(modelo_qtd[i][1]<=0){
                            gotoxy(55,linha);
                            cout<<"A quantidade deve ser superior a 0.";
                        }
                    }while(modelo_qtd[i][1]<=0);

                    erase_eol(55,linha);
                    gotoxy(48,linha);
                    cout<<(modelo_qtd[i][1]*precos[modelo-1]);
                    total+=modelo_qtd[i][1]*precos[modelo_qtd[i][0]-1];
                    // apresentar o total
                    gotoxy(48,10);
                    cout<<total;
                    linha++;
                    detalhe++;
                    break;
                }
            }
        }
         // apresentar o total por linha
        if(detalhe>=4){
            gotoxy(0,13);
            cout<<"Validação da encomenda Ok!";

            // Menu de escolha para nova encomenda, alterar a atual (quantidade), salvar ou terminar o programa
            gotoxy(0,15);
            cout<<"1-Nova Encomenda";
            gotoxy(0,16);
            cout<<"2-Alterar Atual(quantidade)";
            gotoxy(0,17);
            cout<<"3-Guardar Encomenda";
            gotoxy(0,18);
            cout<<"4-Terminar o programa.";
            gotoxy(0,20);
            cout<<"Digite a sua opção:";
            cin>>opcao;

            switch(opcao){
                case 1:
                    layout();
                    break;
                case 2:{
                    int modeloAlterar;
                    gotoxy(0,22);
                    cout<<"Digite o número do modelo para alterar a quantidade: ";
                    cin>>modeloAlterar;
                    for(int i=0;i<4;i++){
                        if(modelo_qtd[i][0]==modeloAlterar){
                            gotoxy(27,i+5);
                            cin>>modelo_qtd[i][1];
                            gotoxy(48,i+5);
                            cout<<(modelo_qtd[i][1]*precos[modeloAlterar-1]);
                            total+=(modelo_qtd[i][1]-modelo_qtd[i][0])*precos[modeloAlterar-1];
                            gotoxy(48, 10);
                            cout << total;
                            // Adiciona uma mensagem de sucesso
                            gotoxy(0, 24);
                            cout << "Quantidade alterada com sucesso.";
                            cout.flush();//limpar o buffer de saida para a msg aparecer 
                            //Sleep(2000);
                            sleep(2); // Pausa por 2 segundos para mostrar a mensagem
                            gotoxy(0,24);
                            erase_eol(0,24); // Limpa a linha da mensagem
                            break;
                        }
                    }
                     // Adiciona uma pausa antes de limpar a tela e continuar
                    //Sleep(1000);
                    sleep(1);
                    // Limpa a tela e continua no loop
                    //Sleep(2000);
                    system("clear");
                    layout();
                }
                break;
                case 3:
                    gotoxy(0,22);
                    cout<<"Encomenda guardada com sucesso!";
                    cout.flush();//limpar o buffer de saida para a msg aparecer 
                    // Exibir informações da encomenda
                    gotoxy(0,24);
                    cout<<"Detalhes da Encomenda:";
                    cout.flush();//limpar o buffer de saida para a msg aparecer 

                    for(int i=0;i<4;i++){
                        if(modelo_qtd[i][0]!=0){
                            gotoxy(0,25+i);
                            cout<<"\tModelo: "<<modelos[modelo_qtd[i][0]-1]<<"\tQuantidade: "<<modelo_qtd[i][1]<<"\tTotal: "<<modelo_qtd[i][1]*precos[modelo_qtd[i][0]-1];
                            cout.flush();//limpar o buffer de saida para a msg aparecer 
                        }
                    }
                 
                    sleep(5); // Pausa por 5 segundos para mostrar a mensagem
                    gotoxy(0, 22);
                    erase_eol(0, 22); // Limpa a linha da mensagem
                    // Retorna ao menu principal
                    layout();
                    break;
                case 4:
                    gotoxy(0,22);
                    cout<<"Fim do programa.";
                    exit(0);
            }
        }
    }
    return 0;
}
/*void gotoxy(int x, int y){
    COORD point;
    point.X=x; point.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),point);
}
*/
void gotoxy(int x, int y){
    cout<<"\033["<<y<<";"<<x<<"H";
}

void layout(){
    //system("cls");
    system("clear");
    gotoxy(0,0);
    cout<<"Encomenda Nº";
    nenc++;
    gotoxy(13,0);
    cout<<nenc;
    gotoxy(0,1);
    cout<<"Produto X";
    gotoxy(0,3);
    cout<<"Modelo     Descrição    Quantidade    Preço    Total";
    gotoxy(0,4);
    cout<<"----------------------------------------------------";
    gotoxy(0,9);
    cout<<"----------------------------------------------------";
    gotoxy(40,10);
    cout<<"Total";
    total=0;
    linha=5;
    detalhe=0;
    existe=false;
    // limpar a matriz dos modelos_qtd
    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            modelo_qtd[i][j]=0;
        }
    }
}

void erase_eol(int x, int y){
    for(int i=x;i<120;i++) {
        gotoxy(i,y);
        cout<<" ";
    }
}
