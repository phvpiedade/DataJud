#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "Datajud.h"


int contar_total_processos(const char* nome_arquivo){ //Item 1
     // Tenta abrir o arquivo em modo de leitura ("r")
    FILE* arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para contagem");
        return -1;
    

    char linha[2048]; // Buffer para armazenar cada linha lida
    int contador = 0; // Para contar os processos

    
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }

    fclose(arquivo);

    return contador; // Retorna os processos contados
}


long long int encontrar_id_ultimo_oj(const char* nome_arquivo, long long int id_processo_alvo) { //Item 2
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para buscar o OJ");
        return -1;
    }

    char linha[2048];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token;
        
        // Pega o primeiro campo (id_processo)
        token = strtok(linha_para_parse, ";\n");

        if (token != NULL) {
            long long int id_processo_atual = atoll(token);

            // Compara com o ID que estamos procurando
            if (id_processo_atual == id_processo_alvo) {
                for (int i = 1; i < 9; i++) {
                    token = strtok(NULL, ";\n");
                    if (token == NULL) break; 
                }

                if (token != NULL) {
                    long long int id_oj_encontrado = atoll(token);
                    fclose(arquivo); 
                    return id_oj_encontrado;
                }
            }
        }
    }

    fclose(arquivo);
    return -1; // -1 indica que não foi encontrado
}


long long int encontrar_processo_mais_antigo(const char* nome_arquivo) { //Item 3
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para encontrar processo mais antigo");
        return -1;
    }

    long long int id_mais_antigo = -1;
    long data_mais_antiga_convertida = LONG_MAX; // Começa com o maior número possível

    char linha[2048];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* id_token = strtok(linha_para_parse, ";\n");
        char* data_token = NULL;

        for (int i = 1; i < 10; i++) {
            data_token = strtok(NULL, ";\n");
            if (data_token == NULL) break;
        }

        if (id_token != NULL && data_token != NULL && strlen(data_token) == 10) {
            long long int id_atual = atoll(id_token);

            // Conversão de DD/MM/AAAA para  AAAAMMDD
            int dia = (data_token[0] - '0') * 10 + (data_token[1] - '0');
            int mes = (data_token[3] - '0') * 10 + (data_token[4] - '0');
            int ano = (data_token[6] - '0') * 1000 + (data_token[7] - '0') * 100 + (data_token[8] - '0') * 10 + (data_token[9] - '0');
            long data_atual_convertida = (long)ano * 10000L + (long)mes * 100L + dia;

            // Se a data atual for mais antiga (menor) que a que a gente já tem
            if (data_atual_convertida < data_mais_antiga_convertida) {
                data_mais_antiga_convertida = data_atual_convertida;
                id_mais_antigo = id_atual;
            }
        }
    }

    fclose(arquivo);
    return id_mais_antigo;
}


int contar_casos_violencia_domestica(const char* nome_arquivo) { //Item 4
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para contar casos de violencia domestica");
        return -1;
    }

    char linha[2048];
    int contador = 0;

    fgets(linha, sizeof(linha), arquivo); 

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Copia a linha para uma variável auxiliar (o strtok modifica a string original)
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token;
        
        //Chama strtok 12 vezes para pegar o 12º campo.
        //O primeiro campo é pego antes do loop.
        token = strtok(linha_para_parse, ";\n");
        for (int i = 1; i < 12; i++) {
            token = strtok(NULL, ";\n");
            if (token == NULL) {
                break;
            }
        }
        
        //token != nulo (encontrou a 12ª coluna)
        if (token != NULL) {
            
            int flag_valor = atoi(token);// Converte o valor do token para inteiro

            if (flag_valor == 1) {
                contador++;
            }
        }
    }

    fclose(arquivo);
    return contador;
}

int contar_casos_feminicidio(const char* nome_arquivo) { //Item 5
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para contar casos de feminicidio");
        return -1;
    }

    char linha[2048];
    int contador = 0;

    fgets(linha, sizeof(linha), arquivo); 

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token;
        
        token = strtok(linha_para_parse, ";\n");

        for (int i = 1; i < 13; i++) {
            token = strtok(NULL, ";\n");
            if (token == NULL) {
                break;
            }
        }
        
        if (token != NULL) {
            int flag_valor = atoi(token);

            if (flag_valor == 1) {
                contador++;
            }
        }
    }

    fclose(arquivo);
    return contador;
}

int contar_casos_ambientais(const char* nome_arquivo) { // Item 6
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para contar casos ambientais");
        return -1;
    }

    char linha[2048];
    int contador = 0;

    fgets(linha, sizeof(linha), arquivo); 

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token;
        
        token = strtok(linha_para_parse, ";\n");

        
        for (int i = 1; i < 14; i++) {
            token = strtok(NULL, ";\n");
            if (token == NULL) {
                break;
            }
        }
        

        if (token != NULL) {
            int flag_valor = atoi(token);
            if (flag_valor == 1) {
                contador++;
            }
        }
    }

    fclose(arquivo);
    return contador;
}

int contar_casos_quilombolas(const char* nome_arquivo) { // Item 7
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para contar casos de quilombolas");
        return -1;
    }

    char linha[2048];
    int contador = 0;

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token;
        
        token = strtok(linha_para_parse, ";\n");

        for (int i = 1; i < 15; i++) {
            token = strtok(NULL, ";\n");
            if (token == NULL) {
                break;
            }
        }
        

        if (token != NULL) {
            int flag_valor = atoi(token);
            if (flag_valor == 1) {
                contador++;
            }
        }
    }

    fclose(arquivo);
    return contador;
}

int contar_casos_indigenas(const char* nome_arquivo) { //Item 8
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para contar casos de indigenas");
        return -1;
    }

    char linha[2048];
    int contador = 0;

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token;
        
        token = strtok(linha_para_parse, ";\n");

        for (int i = 1; i < 16; i++) {
            token = strtok(NULL, ";\n");
            if (token == NULL) {
                break;
            }
        }
        

        if (token != NULL) {
            int flag_valor = atoi(token);
            if (flag_valor == 1) {
                contador++;
            }
        }
    }

    fclose(arquivo);
    return contador;
}

int contar_casos_infancia(const char* nome_arquivo) { //Item 9
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para contar casos de infancia");
        return -1;
    }

    char linha[2048];
    int contador = 0;

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token;
        
        token = strtok(linha_para_parse, ";\n");


        for (int i = 1; i < 17; i++) {
            token = strtok(NULL, ";\n");
            if (token == NULL) {
                break;
            }
        }
        
        if (token != NULL) {
            int flag_valor = atoi(token);
            if (flag_valor == 1) {
                contador++;
            }
        }
    }

    fclose(arquivo);
    return contador;
}


// Funções de suporte para a função do item 10
int ano_bissexto(int ano) { // Retorna 1 se o ano for bissexto, 0 caso contrário.
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}


long data_para_dias(int dia, int mes, int ano) { // Converte uma data (dia, mes, ano) para o total de dias
    long total_dias = 0;
    int dias_no_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Soma os dias dos anos anteriores
    for (int i = 1; i < ano; i++) {
        total_dias += 365 + ano_bissexto(i);
    }

    // Soma os dias dos meses anteriores no ano atual
    for (int i = 1; i < mes; i++) {
        total_dias += dias_no_mes[i];
    }
    // Adiciona o dia extra de ano bissexto se já passou de fevereiro
    if (mes > 2 && ano_bissexto(ano)) {
        total_dias++;
    }

    total_dias += dia;

    return total_dias;
}


int calcular_dias_processo(const char* nome_arquivo, long long int id_processo_alvo) {
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para calcular dias de tramitacao");
        return -1;
    }

    char linha[2048];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token = strtok(linha_para_parse, ";\n");
        if (token == NULL) continue;

        if (atoll(token) == id_processo_alvo) {
            char* dt_recebimento_str = NULL;
            char* dt_resolvido_str = NULL;
            
            for (int i = 2; i <= 10; i++) { token = strtok(NULL, ";\n"); }
            dt_recebimento_str = token;

            for (int i = 11; i <= 19; i++) { token = strtok(NULL, ";\n"); }
            dt_resolvido_str = token;
            
            if (dt_recebimento_str != NULL && strlen(dt_recebimento_str) == 10 &&
                dt_resolvido_str != NULL && strlen(dt_resolvido_str) == 10) {

                // Lógica para ler aaaa-mm-dd
                int ano_r = (dt_recebimento_str[0] - '0') * 1000 + (dt_recebimento_str[1] - '0') * 100 + (dt_recebimento_str[2] - '0') * 10 + (dt_recebimento_str[3] - '0');
                int mes_r = (dt_recebimento_str[5] - '0') * 10 + (dt_recebimento_str[6] - '0');
                int dia_r = (dt_recebimento_str[8] - '0') * 10 + (dt_recebimento_str[9] - '0');
                long dias_recebimento = data_para_dias(dia_r, mes_r, ano_r);

                int ano_s = (dt_resolvido_str[0] - '0') * 1000 + (dt_resolvido_str[1] - '0') * 100 + (dt_resolvido_str[2] - '0') * 10 + (dt_resolvido_str[3] - '0');
                int mes_s = (dt_resolvido_str[5] - '0') * 10 + (dt_resolvido_str[6] - '0');
                int dia_s = (dt_resolvido_str[8] - '0') * 10 + (dt_resolvido_str[9] - '0');
                long dias_resolucao = data_para_dias(dia_s, mes_s, ano_s);
                
                fclose(arquivo);
                return (int)(dias_resolucao - dias_recebimento);
            } else {
                fclose(arquivo);
                return -2; 
            }
        }
    }
    
    fclose(arquivo);
    return -1;
}


double calcular_cumprimento_meta1(const char* nome_arquivo) { //Item 11
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para calcular a Meta 1");
        return 0.0;
    }

    //Usei long long int para as somas, pois os totais podem ser muito grandes.
    long long int total_cnm1 = 0;
    long long int total_julgadom1 = 0;
    long long int total_desm1 = 0;
    long long int total_susm1 = 0;

    char linha[2048];
    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* campos[27]; //Array de strings para guardar todos os campos
        char* token = strtok(linha_para_parse, ";\n");
        int i = 0;
        while(token != NULL && i < 27) {
            campos[i++] = token;
            token = strtok(NULL, ";\n");
        }

        //Se a linha tiver todos os campos, soma os valores
        if (i >= 27) {
            total_cnm1 += atoll(campos[19]);     
            total_julgadom1 += atoll(campos[24]); 
            total_desm1 += atoll(campos[25]);     
            total_susm1 += atoll(campos[26]);     
        }
    }
    fclose(arquivo);

    double denominador = (double)(total_cnm1 + total_desm1 - total_susm1);

    if (denominador == 0) {
        return 0.0;
    }

    double resultado = ((double)total_julgadom1 / denominador) * 100.0;

    return resultado;
}


void gerar_csv_julgados_meta1(const char* nome_arquivo_entrada, const char* nome_arquivo_saida) { //Item 12
    FILE* entrada = fopen(nome_arquivo_entrada, "r");
    if (entrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada");
        return;
    }

    FILE* saida = fopen(nome_arquivo_saida, "w");
    if (saida == NULL) {
        printf("Erro ao criar o arquivo de saida");
        fclose(entrada);
        return;
    }

    char linha[2048];

    // Lê a primeira linha do arquivo de entrada e escreve no arquivo de saída
    if (fgets(linha, sizeof(linha), entrada) != NULL) {
        fprintf(saida, "%s", linha);
    }

    while (fgets(linha, sizeof(linha), entrada) != NULL) {

        char linha_para_parse[2048];
        strcpy(linha_para_parse, linha);

        char* token;
        
        token = strtok(linha_para_parse, ";\n");

        for (int i = 1; i < 25; i++) {
            token = strtok(NULL, ";\n");
            if (token == NULL) break;
        }

        if (token != NULL) {
            int julgados_valor = atoi(token);
            if (julgados_valor > 0) {
                fprintf(saida, "%s", linha);
            }
        }
    }

    fclose(entrada);
    fclose(saida);

    printf("Arquivo '%s' gerado com sucesso!\n", nome_arquivo_saida);
}