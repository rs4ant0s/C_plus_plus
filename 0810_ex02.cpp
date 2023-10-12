#include <iostream>
#include <clocale>

using namespace std; // declarar o namespace std

int main(){
    setlocale(LC_ALL,"Portuguese");
    char nome[30];
    char apelido[30];
    cout<<"Digite o seu nome:"; // cout - intrução para escrita existente no namespace std
    gets(nome); // função para ler uma string
    cout<<"Digite o seu apelido:"; // cout - intrução para escrita existente no namespace std
    gets(apelido); // função para ler uma string  
    cout<<"O nome inserido foi "<<nome<<endl;  
    cout<<"O apelido inserido foi "<<apelido<<endl;
    cout<<"O seu apelido nome é "<<apelido<<", "<<nome;
    return 0;
}