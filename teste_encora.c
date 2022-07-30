#include <stdio.h>
#include <stdbool.h>

struct Set{
    
    int **x;
    int length;
    
};

struct Set;

struct Set coins; //declaracao do set aqui para que as demais funções padrões do set possam acesselo sem que tenha que envialo como parametro.
                // acredito que a melhor opção seria mandar o set como parametro, mas considerando a estrutura fiz como variavel global 

int cents(int number)
{
    if(number - 1 > 0) return 1;
    return 0;
}

int nickels(int number)
{
    if(number - 5 > 0) return 1;
    return 0;
}

int dimes(int number)
{
    if(number - 10 > 0) return 1;
    return 0;
}

int quarters(int number)
{
    if(number - 25 > 0)return 1;
    return 0;

}

/// e e um vetor de 4 casas [cents,nickels,dimes,quarters]
bool makeChange(int number,int e[]) ///considerando 25,10,5 e 1 de que maneiras diferentes podemos devolver esse dinheiro;
{
    int aux = number;
    bool result;
    
    if(number == 0)
    {
        if(!contains(e))
        {
            add(e);
            return 1;
        }
        return  0;
    }
    
    if(cents(number))
    {
        aux = number - 1;
        e [0] = e[0] + 1;
        result = makeChange(aux,e);
        
        if(result) makeChange(aux,e);
    }
    else if(nickels(number))
    {
        aux = number - 5;
        e[1]= e[1] + 1;
        result = makeChange(aux,e);
        if(result) makeChange(aux,e);
    }
    else if(dimes(number))
    {
        aux = number - 10;
        e[2] = e[2] + 1;
        result = makeChange(aux,e);
        if(result) makeChange(aux,e);
    }else if(quarters(number))
    {
        aux = number - 25;
        e[3] = e[3] + 1;
        result =makeChange(aux,e);
        if(result) makeChange(aux,e);
    }
    
    return 0;
}

int main()
{
    
    //declaracao do set como variavel global para que as demais funções padrões do set possam acesselo sem que tenha que envialo como parametro.
    // acredito que a melhor opção seria mandar o set como parametro, mas considerando a estrutura fiz como variavel global 
   
    
    int e[4] = {0}; // posicao 0 = moedas de 1 centavo / posicao 1 = moedas de 5 centavos/ posicao 2 = moedas de 10 centavo / posicao 3 = moedas de 25 centavos
    
    int number;
    
    printf("input your number:");
    scanf("%d",&number);
    
    makeChange(number,e);
    
    int *result;
    
    result = toArray();
    
    printf("["); 
    for(int i = 0; i < sizeof(result)/sizeof(int); i++)
    {
        printf("%d, ",result[i]);
    }

    return 0;
}
