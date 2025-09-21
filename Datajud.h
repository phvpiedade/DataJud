#ifndef DATAJUD_H
#define DATAJUD_H

// Tad Processo:
typedef struct {
    long long int id_processo;
    char numero_sigilo[50];
    char sigla_grau[5];
    char procedimento[100];
    char ramo_justica[5];
    char sigla_tribunal[10];
    int id_tribunal;
    int recurso;
    long long int id_ultimo_oj;
    char dt_recebimento[11];
    int id_ultima_classe;
    int flag_violencia_domestica;
    int flag_feminicidio;
    int flag_ambiental;
    int flag_quilombolas;
    int flag_indigenas;
    int flag_infancia;
    char decisao[11];
    char dt_resolvido[11];
    int cnm1;
    int primeirasentm1;
    int baixm1;
    int decm1;
    int mpum1;
    int julgadom1;
    int desm1;
    int susm1;
}Processo;

//Funções:

int contar_total_processos(const char* nome_arquivo); // Item 1

long long int encontrar_id_ultimo_oj(const char* nome_arquivo, long long int id_processo_alvo); // Item 2

long long int encontrar_processo_mais_antigo(const char* nome_arquivo); // Item 3

int contar_casos_violencia_domestica(const char* nome_arquivo); // Item 4

int contar_casos_feminicidio(const char* nome_arquivo); // Item 5

int contar_casos_ambientais(const char* nome_arquivo); // Item 6

int contar_casos_quilombolas(const char* nome_arquivo); // Item 7

int contar_casos_indigenas(const char* nome_arquivo); // Item 8

int contar_casos_infancia(const char* nome_arquivo); // Item 9

int ano_bissexto(int ano); // Função suporte item 10

long data_para_dias(int dia, int mes, int ano); // Função suporte item 10

int calcular_dias_processo(const char* nome_arquivo, long long int id_processo_alvo);

double calcular_cumprimento_meta1(const char* nome_arquivo); // Item 11

void gerar_csv_julgados_meta1(const char* nome_arquivo_entrada, const char* nome_arquivo_saida); // Item 12
#endif