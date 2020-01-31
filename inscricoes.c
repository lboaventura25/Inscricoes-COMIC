#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_LINHAS 28

typedef struct dados_incricao {
    char * num_pedido;
    char * data;
    int lote;
    char * nome;
    char * email;
} Dados_Incricao;

char * le_linha();
char * pega_pedido(char * texto_linha);
char * pega_data(char * texto_linha);

int main() {

    char * texto_linha;
    Dados_Incricao dados_incricao;
    int linha;

    dados_incricao.lote = 3;

    printf("Seja bem-vindo, Igor! Sorria e nao reclame! rsrs\n\n");
    printf("Coloque o texto do pedido agora:\n");
    
    for(linha = 0; linha < NUM_LINHAS; linha++) {
        texto_linha = le_linha();
        getchar();

        switch (linha) {
            case 0:
                dados_incricao.num_pedido = pega_pedido(texto_linha);
                break;

            case 5:
                dados_incricao.data = pega_data(texto_linha);
                break;

            case 15:
                dados_incricao.nome = texto_linha;
                break;

            case 20:
                dados_incricao.email = texto_linha;
                break;

            default:
                break;
        }
    }

    printf("\n\n--------- Igor, COPIA ISSO AQUI ----------\n");

    printf("%s\t", dados_incricao.num_pedido);
    printf("%s\t", dados_incricao.data);
    printf("%d\t", dados_incricao.lote);
    printf("%s\t", dados_incricao.nome);
    printf("%s\n", dados_incricao.email);

    free(dados_incricao.nome);
    free(dados_incricao.data);
    free(dados_incricao.email);
    free(dados_incricao.num_pedido);

    return 0;
}

char * le_linha() {
    char * texto_linha = (char *) malloc(150 * sizeof(char));
    scanf("%[^\n]", texto_linha);

    return texto_linha;
}

char * pega_pedido(char * texto_linha) {
    char * num_pedido= (char *) malloc(10 * sizeof(char));
    int i = strcspn(texto_linha, "#") + 1;
    int cont = 0;

    for(; i < strlen(texto_linha); i++) {
        num_pedido[cont++] = texto_linha[i];
    }
    num_pedido[cont] = '\0';

    return num_pedido;
}

char * pega_data(char * texto_linha) {
    char * data = (char *) malloc(11 * sizeof(char));
    char * dia = (char *) malloc(3 * sizeof(char));
    char * mes = (char *) malloc(3 * sizeof(char));
    char * ano = (char *) malloc(5 * sizeof(char));
    char * letra = texto_linha;
    int cont = 0;

    for(; *letra != '-'; letra++) {
        ano[cont++] = *letra;
    }
    ano[cont] = '\0';
    letra++;
    cont = 0;

    for(; *letra != '-'; letra++) {
        mes[cont++] = *letra;
    }
    mes[cont] = '\0';
    letra++;
    cont = 0;

    for(; *letra != '\0'; letra++) {
        dia[cont++] = *letra;
    }
    dia[cont] = '\0';

    strcpy(data, dia);
    strcat(data, "/");
    strcat(data, mes);
    strcat(data, "/");
    strcat(data, ano);
    strcat(data, "\0");

    free(dia);
    free(mes);
    free(ano);

    return data;
}
