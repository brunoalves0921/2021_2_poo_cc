#include <iostream>
#include <vector>

//BUSCA-----------------------------------------------------------------------------------------------------------------

//01 - Existe
void EXISTE(std::vector<int> VETOR){
    int x = 0;
    std::cout << "Digite o numero que deseja achar: \n";
    std::cin >> x;
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] == x){
            std::cout << "Existe pelo menos uma pessoa com o valor " << x <<" na fila\n";
            return;
        }
    }
    std::cout << "Nao existe ninguem na fila com este numero";
}
//02 - CONTAR
void CONTAR(std::vector<int> VETOR){
    int x = 0;
    int repete = 0;
    std::cout << "Digite o numero que deseja achar: \n";
    std::cin >> x;
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] == x)
            repete++;
    }
    if(repete != 0)
        std::cout << "Este numero se repete " << repete <<" vez(es)\n";
    else
        std::cout << "Nao existe ninguem na fila com este numero";    
}
//03 - PROCURAR_VALOR
void PROCURAR_VALOR(std::vector<int> VETOR){
    int x = 0;
    int lugar_fila = 0;
    std::cout << "Digite o numero que deseja achar: \n";
    std::cin >> x;
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] != x)
            lugar_fila++;
        if(VETOR[i] == x) {
            std::cout << "Este numero aparece em " << lugar_fila <<" lugar na fila\n";
            return;
        }
    }
    std::cout << "Nao existe ninguem na fila com este numero"; 
}
//04 - PROCURAR_VALOR_APOS
void PROCURAR_VALOR_APOS(std::vector<int> VETOR){
    int x = 0;
    unsigned int i = 0;
    std::cout << "Digite o numero que deseja achar: \n";
    std::cin >> x;
    std::cout << "Digite o lugar da fila em que deseja comecar: \n";
    std::cin >> i;

    while(i < VETOR.size()) {
        if(VETOR[i] == x) {
            std::cout << "Este numero aparece na posicao " << i << "\n";
            return;
        }
        i++;
    }
    std::cout << "Nao existe ninguem na fila com este numero"; 
}

//MELHOR CASO-----------------------------------------------------------------------------------------------------------

//PROCURAR_MENOR
void PROCURAR_MENOR(std::vector<int> VETOR){

    int menor = VETOR[0];

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < 0)
            VETOR[i] = VETOR[i] * -1;
        if(VETOR[i] < menor)
            menor = VETOR[i];
    }
    std::cout << "O menor valor da lista eh: " << menor << "\n";
}
//PROCURAR_MAIOR
void PROCURAR_MAIOR(std::vector<int> VETOR){

    int maior = VETOR[0];

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < 0)
            VETOR[i] = VETOR[i] * -1;
        if(VETOR[i] > maior)
            maior = VETOR[i];
    }
    std::cout << "O maior valor da lista eh: " << maior << "\n";
}
//PROCURAR MENOR POS
void PROCURAR_MENOR_POS(std::vector<int> VETOR){

    int menor = VETOR[0];

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < 0)
            VETOR[i] = VETOR[i] * -1;

        if(VETOR[i] < menor)
            menor = VETOR[i];
    }
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] == menor){
            std::cout << "A posicao do menor valor eh: " << i << "\n";
            return;
        }
    }
    
}
//PROCURAR MENOR POS APOS
void PROCURAR_MENOR_POS_APOS(std::vector<int> VETOR){

    int menor = VETOR[0];

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < 0)
            VETOR[i] = VETOR[i] * -1;

        if(VETOR[i] < menor)
            menor = VETOR[i];
    }

    unsigned int i = 0;
    std::cout << "Digite o lugar da fila em que deseja comecar: \n";
    std::cin >> i;
    
    while ( i < VETOR.size()) {
        if(VETOR[i] == menor){
            std::cout << "A posicao do menor valor eh: " << i << "\n";
            return;
        }
    i++;
    }
}
//PROCURAR MELHOR SE
void PROCURAR_MELHOR_SE(std::vector<int> VETOR){

    int menor = 999999;
    int pos = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < menor && VETOR[i] > 0){
            menor = VETOR[i];
            pos = i;
        }
    }
            std::cout << "A posicao do homem mais calmo eh: " << pos << "\n";
}

//CONTAGEM--------------------------------------------------------------------------------------------------------------

//CALCULAR STRESS MEDIO
void CALCULAR_STRESS_MEDIO(std::vector<int> VETOR){

    float media = 0;

    for(unsigned int i = 0; i < VETOR.size(); i++){
        if(VETOR[i] < 0)
            media = media - VETOR[i];
        else
            media = media + VETOR[i];
    }
    std::cout << "A media de stress na fila eh de: " << media / (VETOR.size()) <<"\n";
}
//MAIS HOMENS OU MULHERES
void MAIS_HOMENS_OU_MULHERES(std::vector<int> VETOR){

    int homens = 0;
    int mulheres = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < 0)
            mulheres++;
        else
            homens++;
    }
    if(mulheres > homens)
        std::cout << "Existem mais mulheres na fila do que homens";
    else if(mulheres == homens)
        std::cout << "A quantidade de homens e mulheres na fila sao iguais";
    else
        std::cout << "Existem mais homens na fila do que mulheres";
}
//QUAL METADE EH MAIS ESTRESSADA
void QUAL_METADE_EH_MAIS_ESTRESSADA(std::vector<int> VETOR){

unsigned int meio = VETOR.size()/2;
int metade_direita = 0;
int metade_esquerda = 0;

    for(unsigned int i = 0; i < VETOR.size(); i++){
        if (VETOR[i] < 0)
            VETOR[i] = VETOR[i] * -1;
    } 
    if (VETOR.size()%2 == 0) {
        for(unsigned int i = 0; i < meio; i++){
                metade_esquerda = metade_esquerda + VETOR[i];
        }  
        for(unsigned int i = meio; i < VETOR.size(); i++){
            metade_direita = metade_direita + VETOR[i];
        }
    }
    else {
        for(unsigned int i = 0; i < meio + 1; i++){
                metade_esquerda = metade_esquerda + VETOR[i];
        }  
        for(unsigned int i = meio; i < VETOR.size(); i++){
            metade_direita = metade_direita + VETOR[i];
        }
    }
    if (metade_direita > metade_esquerda)
        std::cout << "A metade da direita esta mais estressada";
    else if (metade_direita == metade_esquerda)
        std::cout << "As duas metades estao estressadas igualmente";
    else
        std::cout << "A metade da esquerda esta mais estressada";
}
//HOMENS SAO MAIS ESTRESSADOS QUE MULHERES
void HOMENS_SAO_MAIS_ESTRESSADOS_QUE_MULHERES(std::vector<int> VETOR){

    int homens = 0;
    int mulheres = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < 0)
            mulheres = mulheres + VETOR[i] * -1;
        else
            homens = homens + VETOR[i];
    }
    if(mulheres > homens)
        std::cout << "As mulheres estao mais estressadas que os homens";
    else if(mulheres == homens)
        std::cout << "Os homens e mulheres estao estressados igualmente";
    else
        std::cout << "Os homens estao mais estressados que as mulheres";
}
int main(){

    int exit = 999;
    int aux = 0;
    
    std::vector<int> VETOR{};
    std::cin >> aux;

    while(aux != exit){
        VETOR.push_back(aux);
        std::cin >> aux;
    }

    CALCULAR_STRESS_MEDIO(VETOR);

}