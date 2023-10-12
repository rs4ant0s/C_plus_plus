#include <iostream>
#include <clocale>
#include <cstdio>

int main(){
    setlocale(LC_ALL,"Portuguese");
    char nome[30];
    char apelido[30];
    std::cout<<"Digite o seu nome:"; // cout - intru��o para escrita existente no namespace std
    gets(nome); // fun��o para ler uma string
    std::cout<<"Digite o seu apelido:"; // cout - intru��o para escrita existente no namespace std
    gets(apelido); // fun��o para ler uma string  
    std::cout<<"O nome inserido foi "<<nome<<std::endl;  
    std::cout<<"O apelido inserido foi "<<apelido<<std::endl;
    std::cout<<"O seu apelido nome � "<<apelido<<", "<<nome;
    return 0;
}