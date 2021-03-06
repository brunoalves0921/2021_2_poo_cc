#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>   

void PRINTAR(std::vector<int>& VETOR) {
    std::cout << "[ ";
    if(VETOR.size() != 0){
        std::cout << VETOR[0];
    }

    for (unsigned int i = 1; i < VETOR.size(); i++) {
        std::cout << ", " << VETOR[i];
    }
    std::cout << " ]\n";
}
void TROCAR(int& a, int& b) {
    int aux = a;
    a = b;
    b = aux;
}
//BUSCA-----------------------------------------------------------------------------------------------------------------

//01 - Existe
bool EXISTE(std::vector<int>& VETOR, int a, int& pos) {
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] == a){
            pos = i;
            return true;
        }
    }
    return false;
}
//02 - CONTAR
void CONTAR(std::vector<int>& VETOR) {
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
        std::cout << "Nao existe ninguem na fila com este nivel de estresse\n";    
}
//03 - PROCURAR_VALOR
void PROCURAR_VALOR(std::vector<int>& VETOR) {
    int x = 0;
    int lugar_fila = 0;
    std::cout << "Digite o numero que deseja achar: \n";
    std::cin >> x;
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] != x)
            lugar_fila++;
        if(VETOR[i] == x) {
            std::cout << "Este numero aparece em " << lugar_fila + 1 <<"º lugar na fila da esquerda para direita\n";
            return;
        }
    }
    std::cout << "Nao existe ninguem na fila com este nivel de estresse"; 
}
//04 - PROCURAR_VALOR_APOS
void PROCURAR_VALOR_APOS(std::vector<int>& VETOR) {
    int x = 0;
    unsigned int i = 0;
    std::cout << "Digite o numero que deseja achar: \n";
    std::cin >> x;
    std::cout << "Digite o lugar da fila em que deseja comecar: \n";
    std::cin >> i;

    while(i < VETOR.size()) {
        if(VETOR[i] == x) {
            std::cout << "Este numero aparece na posicao " << i + 1 << " da esquerda para a direita\n";
            return;
        }
        i++;
    }
    std::cout << "Nao existe ninguem na fila com este numero"; 
}

//MELHOR CASO-----------------------------------------------------------------------------------------------------------

//PROCURAR_MENOR
void PROCURAR_MENOR(std::vector<int>& VETOR){

    int menor = VETOR[0];

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(abs(VETOR[i]) < menor)
            menor = VETOR[i];
    }
    std::cout << "O menor valor da lista eh: " << menor << "\n";
}
//PROCURAR_MAIOR
void PROCURAR_MAIOR(std::vector<int>& VETOR) {

    int maior = VETOR[0];

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(abs(VETOR[i]) > maior)
            maior = VETOR[i];
    }
    std::cout << "O maior valor da lista eh: " << maior << "\n";
}
//PROCURAR MENOR POS
void PROCURAR_MENOR_POS(std::vector<int>& VETOR) {

    int menor = VETOR[0];

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(abs(VETOR[i]) < menor)
            menor = VETOR[i];
    }
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(abs(VETOR[i]) == menor){
            std::cout << "A posicao do menor valor eh a " << i + 1 << "º da esquerda para direita\n";
            return;
        }
    }
    
}
//PROCURAR MENOR POS APOS
void PROCURAR_MENOR_POS_APOS(std::vector<int>& VETOR) {

    int menor = VETOR[0];

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(abs(VETOR[i]) < menor)
            menor = VETOR[i];
    }

    unsigned int i = 0;
    std::cout << "Digite o lugar da fila em que deseja comecar: \n";
    std::cin >> i;
    
    while ( i < VETOR.size()) {
        if(VETOR[i] == menor){
            std::cout << "A posicao do menor valor eh a " << i + 1 << "º da esquerda para direita\n";
            return;
        }
    i++;
    }
}
//PROCURAR MELHOR SE
void PROCURAR_MELHOR_SE(std::vector<int>& VETOR) {

    int menor = 999999;
    int pos = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < menor && VETOR[i] > 0){
            menor = VETOR[i];
            pos = i;
        }
    }
            std::cout << "A posicao do menor valor eh a " << pos + 1 << "º da esquerda para direita\n";
}

//CONTAGEM--------------------------------------------------------------------------------------------------------------

//CALCULAR STRESS MEDIO
void CALCULAR_STRESS_MEDIO(std::vector<int>& VETOR){

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
void MAIS_HOMENS_OU_MULHERES(std::vector<int>& VETOR) {

    int homens = 0;
    int mulheres = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < 0)
            mulheres++;
        else
            homens++;
    }
    if(mulheres > homens)
        std::cout << "Existem mais mulheres na fila do que homens\n";
    else if(mulheres == homens)
        std::cout << "A quantidade de homens e mulheres na fila sao iguais\n";
    else
        std::cout << "Existem mais homens na fila do que mulheres\n";
}
//QUAL METADE EH MAIS ESTRESSADA
void QUAL_METADE_EH_MAIS_ESTRESSADA(std::vector<int>& VETOR) {

unsigned int meio = VETOR.size()/2;
int metade_direita = 0;
int metade_esquerda = 0;


    if (VETOR.size()%2 == 0) {
        for(unsigned int i = 0; i < meio; i++){
                metade_esquerda = metade_esquerda + abs(VETOR[i]);
        }  
        for(unsigned int i = meio; i < VETOR.size(); i++){
            metade_direita = metade_direita + abs(VETOR[i]);
        }
    }
    else {
        for(unsigned int i = 0; i < meio; i++){
                metade_esquerda = metade_esquerda + abs(VETOR[i]);
        }  
        for(unsigned int i = meio + 1; i < VETOR.size(); i++){
            metade_direita = metade_direita + abs(VETOR[i]);
        }
    }
    if (metade_direita > metade_esquerda)
        std::cout << "A metade da direita esta mais estressada\n";
    else if (metade_direita == metade_esquerda)
        std::cout << "As duas metades estao estressadas igualmente\n";
    else
        std::cout << "A metade da esquerda esta mais estressada\n";
}
//HOMENS SAO MAIS ESTRESSADOS QUE MULHERES
void HOMENS_SAO_MAIS_ESTRESSADOS_QUE_MULHERES(std::vector<int>& VETOR) {

    int homens = 0;
    int mulheres = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if(VETOR[i] < 0)
            mulheres = mulheres + VETOR[i] * -1;
        else
            homens = homens + VETOR[i];
    }
    if(mulheres > homens)
        std::cout << "As mulheres estao mais estressadas que os homens\n";
    else if(mulheres == homens)
        std::cout << "Os homens e mulheres estao estressados igualmente\n";
    else
        std::cout << "Os homens estao mais estressados que as mulheres\n";
}

//Filter - Operações de Filtragem: 4 funções----------------------------------------------------------------------------

//clonar
std::vector<int> CLONAR(std::vector<int>& VETOR) {

    std::vector<int> VETOR_NOVO((int)VETOR.size());

    for (unsigned int i = 0; i < VETOR.size(); i++){
        VETOR_NOVO[i] = VETOR[i];
    }
    return VETOR_NOVO;
}
//pegar_homens
std::vector<int> PEGAR_HOMENS(std::vector<int>& VETOR) {

    std::vector<int> VETOR_NOVO{};
    for(unsigned int i = 0; i < VETOR.size(); i++) {
        if (VETOR[i] > 0) {
            VETOR_NOVO.push_back(VETOR[i]);
        }
    }
    return VETOR_NOVO;
}
//pegar_calmos
std::vector<int> PEGAR_CALMOS(std::vector<int>& VETOR) {
    
    std::vector<int> VETOR_NOVO{};


    for(unsigned int i = 0; i < VETOR.size(); i++) {
        if (abs(VETOR[i]) < 10) {
            VETOR_NOVO.push_back(VETOR[i]); 
        }
    }
    return VETOR_NOVO;
}
//pegar mulheres calmas
std::vector<int> PEGAR_MULHERES_CALMAS(std::vector<int>& VETOR) {

    std::vector<int> VETOR_NOVO{};

    for(unsigned int i = 0; i < VETOR.size(); i++) {
        if (VETOR[i] < 0  && VETOR[i] > -10) {
            VETOR_NOVO.push_back(VETOR[i]); 
        }
    }
    return VETOR_NOVO;
}

// Acesso -------------------------------------------------------------------------------------------------------------------

//INVERTER COM COPIA
std::vector<int> INVERTER_COM_COPIA(std::vector<int>& VETOR) {

    std::vector<int> VETOR_NOVO{};

    for (int i = VETOR.size() -1; i >= 0; i--) {
        VETOR_NOVO.push_back(VETOR[i]);
    }
    return VETOR_NOVO;

}
//REVERTER INPLACE
void REVERTER_INPLACE(std::vector<int>& VETOR){

    for (unsigned int i = 0; i < VETOR.size() / 2; i++) {
        TROCAR(VETOR[i], VETOR[VETOR.size() -1 -i]);
    }

}
//SORTEAR
int SORTEAR(std::vector<int>& VETOR){
    int sorteio = rand() % VETOR.size();
    return VETOR[sorteio];
}
//EMBARALHAR
void EMBARALHAR(std::vector<int>& VETOR){

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        int sorteio = rand() % VETOR.size();
        TROCAR(VETOR[sorteio], VETOR[i]);
    }
}
//ordenar
void ORDENAR(std::vector<int>& VETOR){
    
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        int *menor = &VETOR[i];
        for (unsigned j = i + 1; j < VETOR.size(); j++) {
            if (abs(VETOR[j]) < abs(*menor)) {
                menor = &VETOR[j];
            }
        }
        TROCAR(*menor, VETOR[i]);
    }

}

//CONJUNTO------------------------------------------------------------------------------------------------------------

//EXCLUSIVOS
std::vector<int> EXCLUSIVOS(std::vector<int>& VETOR) {

    std::vector<int> VETOR_NOVO {};
    int pos;

    for (unsigned int i = 0; i < VETOR.size(); i++){
        if(!EXISTE(VETOR_NOVO, VETOR[i], pos)) {
            VETOR_NOVO.push_back(VETOR[i]);
        }

    }
    return VETOR_NOVO;
}
//DIFERENTES
std::vector<int> DIFERENTES(std::vector<int>& VETOR) {

    std::vector<int> VETOR_NOVO {};
    int pos;

    for (unsigned int i = 0; i < VETOR.size(); i++){
        if(!EXISTE(VETOR_NOVO, abs(VETOR[i]), pos)) {
            VETOR_NOVO.push_back(abs(VETOR[i]));
        }
    }
    return VETOR_NOVO;
}
//ABANDONADOS
std::vector<int> ABANDONADOS(std::vector<int>& VETOR) {

    std::vector<int> excluidos = EXCLUSIVOS(VETOR);
    std::vector<int> VETOR_NOVO {};
    int pos;

    for(unsigned int i = 0; i < VETOR.size(); i++) {
        if(EXISTE(excluidos, VETOR[i], pos)) {
            excluidos.erase(excluidos.begin() + pos);
        }
        else {
            VETOR_NOVO.push_back(VETOR[i]);
        }
    }
    return VETOR_NOVO;
}

//Map - Manipulação
//SOZINHOS
std::vector<int> SOZINHOS(std::vector<int>& VETOR) {
    std::vector<int> VETOR_NOVO {};
    int repete = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        repete = 0;
        for (unsigned int j = 0; j < VETOR.size(); j++) {
            if (i == j) continue;
            if (abs(VETOR[i]) == abs(VETOR[j])) {
                repete ++;
                break;
            }
        }
        if (repete == 0)
            VETOR_NOVO.push_back(VETOR[i]);
    }
    return VETOR_NOVO;
}
//mais ocorrencias
int MAIS_OCORRENCIAS(std::vector<int>& VETOR) {
    int repete = 0;
    int maior = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        repete = 0;
        for (unsigned int j = 0; j < VETOR.size(); j++) {
            if (abs(VETOR[i]) == abs(VETOR[j])) {
                repete ++;
            }
            if (repete > maior)
                maior = repete;
        }
    }
    return maior;
}
//mais recorrentes

std::vector<int> MAIS_RECORRENTES(std::vector<int>& VETOR) {
    std::vector<int> VETOR_NOVO {};
    int repete = 0;
    int maior = 0;
    int pos = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        repete = 0;
        for (unsigned int j = 0; j < VETOR.size(); j++) {
            if (abs(VETOR[i]) == abs(VETOR[j])) {
                repete ++;
            }
            if (repete > maior) {
                VETOR_NOVO.clear();
                VETOR_NOVO.push_back(abs(VETOR[i]));
                maior = repete;
            }
            else if (repete == maior && !EXISTE(VETOR_NOVO, abs(VETOR[i]), pos)) {
                VETOR_NOVO.push_back(abs(VETOR[i]));
            }
        }
    }
    return VETOR_NOVO;
}
//briga
int BRIGA(std::vector<int>& VETOR) {
    int qtd = 0;
    for (unsigned int i = 1; i < VETOR.size()-1; i++) {
        if (abs(VETOR[i]) > 50 && abs(VETOR[i-1]) > 30 && abs(VETOR[i+1]) > 30)
            qtd++;
    }
    return qtd;
}
//apaziguado
std::vector<int> APAZIGUADO(std::vector<int>& VETOR) {

    std::vector<int> VETOR_NOVO {};
    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if (abs(VETOR[i]) > 80 && ((i > 0 && abs(VETOR[i-1]) < 10) || (i < VETOR.size()-1 && abs(VETOR[i+1]) < 10)))
            VETOR_NOVO.push_back(i);
    }
    return VETOR_NOVO; 
}
//times
int TIMES(std::vector<int>& VETOR) {

    int times = 0;
    int gen = 0;
    int aux = 0;

    if (VETOR.size() > 0) {
        if (VETOR[0] > 0)
            gen = 1;
        else
            gen = -1;
    }
    for (unsigned int i = 0; i < VETOR.size()-1; i++) {
        
        if (VETOR[i] * gen > 0 && VETOR[i+1] * gen > 0) {
            if (aux == 0)
                times++;
            aux = 1;
        }
        else {
            aux = 0;
            gen *= -1;
        }
    }
    return times;
}
//maior time
int MAIOR_TIME(std::vector<int>& VETOR) {

    int tamanho = 1;
    int gen = 0;
    int maior = 0;

    if (VETOR.size() > 0) {
        if (VETOR[0] > 0)
            gen = 1;
        else
            gen = -1;
    }
    for (unsigned int i = 0; i < VETOR.size()-1; i++) {
        
        if (VETOR[i] * gen > 0 && VETOR[i+1] * gen > 0) {
            tamanho++;
            if(tamanho > maior)
                maior = tamanho;
        }
        else {
            tamanho = 1;
            gen *= -1;
        }
    }
    return maior;
}
//sozinhos
int SOZINHOS_2(std::vector<int>& VETOR) {

    int gen = 0;
    int qtd = 0;

    if (VETOR.size() > 0) {
        if (VETOR[0] > 0)
            gen = 1;
        else
            gen = -1;
    }
    else
        return 0;
    if (VETOR.size() == 1)
        return 1;
    if (VETOR.size() == 2) {
        if(VETOR[1] * gen > 0)
            return 0;
        else 
            return 2;
    }

    for (unsigned int i = 0; i < VETOR.size()-1; i++) {
        
        if (!(VETOR[i] * gen > 0 && VETOR[i+1] * gen > 0)) {
            gen *= -1;
            qtd++;
        }
    }
    if (VETOR[VETOR.size()-1] != VETOR[VETOR.size()-2])
        qtd++;
    return qtd;
}
//casais
int CASAIS(std::vector<int>& VETOR) {

    int casal = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        for (unsigned int j = i + 1; j < VETOR.size(); j++) {
            if (abs(VETOR[i]) == abs(VETOR[j]) && VETOR[i] * VETOR[j] < 0) {
                casal++;
            }
        }
    }
    return casal;
}
//trios
int TRIOS(std::vector<int>& VETOR) {

    int trio = 0;

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        for (unsigned int j = i + 1; j < VETOR.size(); j++) {
            for (unsigned int k = j + 1; k < VETOR.size(); k++) {
                if (abs(VETOR[i]) == abs(VETOR[j]) && abs(VETOR[j]) == abs(VETOR[k])) {
                    trio++;
                }
            }
        }
    }
    return trio;
}
//remove
int REMOVE(std::vector<int>& VETOR, int num) {

    for (unsigned int i = 0; i < VETOR.size(); i++) {
        if (VETOR[i] == num) {
            VETOR.erase(VETOR.begin() + i);
            return i;
        }
    }
    return -1;
}
//insert

bool INSERT(std::vector<int>& VETOR, int num, unsigned int pos) {

    if (pos > VETOR.size())
        return false;
    VETOR.push_back(num);

    for (unsigned int i = VETOR.size(); i > pos ; i--) {
        VETOR[i] = VETOR[i - 1];
    }
    VETOR[pos] = num;
    return true;
    
}

int main(){

    int exit = 999;
    int aux;
    int opc = 0;
    srand(time(NULL));
    
    std::vector<int> VETOR{};
    std::cout << "Digite os niveis de estresse de cada um da fila\n";
    std::cout << "OBS: Digite o numero '999' para fechar a fila!\n";
    std::cin >> aux;

    while(aux != exit){
        std::cout << "proximo: ";
        VETOR.push_back(aux);
        std::cin >> aux;
    }

    do{
        std::cout << "---------------------------------------------------------\n";
        std::cout << "1 - Comandos de BUSCA\n";
        std::cout << "\n";
        std::cout << "2 - Comandos de MELHOR CASO\n";
        std::cout << "\n";
        std::cout << "3 - Comandos de CONTAGEM\n";
        std::cout << "\n";
        std::cout << "4 - Para encerrar o programa\n";
        std::cout << "---------------------------------------------------------\n";
        std::cin >> opc;

        if(opc == 1){
            do{
                std::cout << "---------------------------------------------------------------\n";
                std::cout << "1 - Existe\n"; //Existe: Alguém com o valor X está na fila?
                std::cout << "\n";
                std::cout << "2 - Contar\n"; //Contar: Quantas vezes o valor X apareceu na fila?
                std::cout << "\n";
                std::cout << "3 - Procurar Valor\n"; //Procurar_valor: Em que posição da fila aparece X pela primeira vez?
                std::cout << "\n";
                std::cout << "4 - Procurar Valor Apos\n"; //Procurar_valor_apos: Dada a posição para iniciar a busca, qual a próxima posição em que aparece X?
                std::cout << "\n";
                std::cout << "5 - Voltar Para Menu Principal\n";
                std::cout << "---------------------------------------------------------------\n";
                std::cin >> opc;

                if(opc == 1){
                    int a;
                    int pos;
                    std::cout << "Digite o número que deseja encontrar: ";
                    std::cin >> a;
                    if (EXISTE(VETOR, a, pos)) {

                        std::cout << "Este valor existe e está na posição: " << pos + 1 << "!\n";
                    }
                    else {
                        std::cout << "Não foi encontrado nenhum valor igual ao digitado!\n";
                    }
                }
                else if(opc == 2){
                    CONTAR(VETOR);
                }
                else if(opc == 3){
                    PROCURAR_VALOR(VETOR);
                }
                else if(opc == 4){
                    PROCURAR_VALOR_APOS(VETOR);
                }
                else if(opc != 5){
                    std::cout << "Opção inválida\n";
                }
            }while(opc != 5);
        }
        if(opc == 2){
            do{
                std::cout << "---------------------------------------------------------------\n";
                std::cout << "1 - Procurar Menor\n"; //Procurar_menor: qual o menor valor da lista?
                std::cout << "\n";
                std::cout << "2 - Procurar Menor Pos\n"; //Procurar_menor_pos: qual a posição do menor valor da lista?
                std::cout << "\n";
                std::cout << "3 - Procurar Menor Pos Apos\n"; //Procurar_menor_pos_apos: Dada a posição para iniciar a busca, qual a posição do menor valor da lista?
                std::cout << "\n";
                std::cout << "4 - Procurar Melhor Se\n"; //procurar_melhor_se: qual a posição do HOMEM mais calmo? (menor valor maior que 0)
                std::cout << "\n";
                std::cout << "5 - Voltar Para Menu Principal\n";
                std::cout << "---------------------------------------------------------------\n";
                std::cin >> opc;

                if(opc == 1){
                    PROCURAR_MENOR(VETOR);
                }
                else if(opc == 2){
                    PROCURAR_MENOR_POS(VETOR);
                }
                else if(opc == 3){
                    PROCURAR_MENOR_POS_APOS(VETOR);
                }
                else if(opc == 4){
                    PROCURAR_MELHOR_SE(VETOR);
                }
                else if(opc != 5){
                    std::cout << "Opção inválida\n";
                }
            }while(opc != 5);
        }
        if(opc == 3){
            do{
                std::cout << "---------------------------------------------------------------\n";
                std::cout << "1 - Calcular Estresse Medio\n"; //calcular_stress_medio: qual a média de stress da fila? (abs)
                std::cout << "\n";
                std::cout << "2 - Mais homens ou mulheres na fila\n"; //mais_homens_ou_mulheres: Na fila existem mais homens ou mulheres?
                std::cout << "\n";
                std::cout << "3 - Qual eh a metade mais estressada\n"; //qual_metade_eh_mais_estressada: O nível de stress somado de todas as pessoas da primeira metade é maior que o nível de stress somado das pessoas da segunda metade da fila? (abs)
                std::cout << "\n";
                std::cout << "4 - Homens sao mais estressados que mulheres\n"; //homens_sao_mais_estressados_que_mulheres: a média do stress dos homens é maior que a das mulheres?
                std::cout << "\n";
                std::cout << "5 - Voltar Para Menu Principal\n";
                std::cout << "---------------------------------------------------------------\n";
                std::cin >> opc;

                if(opc == 1){
                    CALCULAR_STRESS_MEDIO(VETOR);
                }
                else if(opc == 2){
                    MAIS_HOMENS_OU_MULHERES(VETOR);
                }
                else if(opc == 3){
                    QUAL_METADE_EH_MAIS_ESTRESSADA(VETOR);
                }
                else if(opc == 4){
                    HOMENS_SAO_MAIS_ESTRESSADOS_QUE_MULHERES(VETOR);
                }
                else if(opc != 5){
                    std::cout << "Opção inválida\n";
                }
            }while(opc != 5);
        }
        if (opc == 4){

            //std::vector<int> teste = MAIS_RECORRENTES(VETOR);
            //std::vector<int> retorno {APAZIGUADO(VETOR)};
            int num;
            int pos;
            std::cin >> num;
            std::cin >> pos;
            INSERT(VETOR, num, pos);
            //PRINTAR(retorno);
            std::cout << "\nA nova fila agora será: \n";
            PRINTAR(VETOR);
        }
    }while(opc != 5);
}