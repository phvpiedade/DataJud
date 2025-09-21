#include <stdio.h>
#include <stdlib.h>
#include "Datajud.h"





int main(){ 

    const char* arquivo_filtrado = "TJDFT_filtrado.csv";
    const char* arquivo_saida = "processos_julgados_meta1.csv";
    
    printf("Iniciando leitura do arquivo.\n");
    
    // Item 1
    int TotalProcessos = contar_total_processos(arquivo_filtrado);
    if (TotalProcessos != -1) {
        printf("-Numero de processos presentes na base de dados: %d\n", TotalProcessos);
    }

    //Item 2
    long long int IdParaBuscar = 323961063; // ID para exemplo que existe na tabela filtrada
    long long int OjEncontrado = encontrar_id_ultimo_oj(arquivo_filtrado, IdParaBuscar);

    printf("-Buscando o ultimo orgao julgador para o processo ID %lld...\n", IdParaBuscar);
    if (OjEncontrado != -1) {
        printf("   => O id_ultimo_oj encontrado foi: %lld\n", OjEncontrado);
    } else {
        printf("   => Processo com ID %lld nao foi encontrado na base de dados.\n", IdParaBuscar);
    }

    // Item 3
    long long int IdAntigo = encontrar_processo_mais_antigo(arquivo_filtrado);
    if (IdAntigo != -1) {
        printf("-ID do processo com a data de recebimento mais antiga: %lld\n", IdAntigo);
    }
    
    // Item 4
    int TotalViolencia = contar_casos_violencia_domestica(arquivo_filtrado);
    if (TotalViolencia != -1){
        printf("-Processos relacionados a causas de violencia domestica: %d\n", TotalViolencia);
    }
    
    // Item 5
    int TotalFeminicidio = contar_casos_feminicidio(arquivo_filtrado);
    if (TotalFeminicidio != -1) {
        printf("-Processos relacionados a causas de feminicidio: %d\n", TotalFeminicidio);
    }

    // Item 6
    int TotalAmbiental = contar_casos_ambientais(arquivo_filtrado);
    if (TotalAmbiental != -1) {
        printf("-Processos relacionados a causas ambientais: %d\n", TotalAmbiental);
    }
    
    // Item 7
    int TotalQuilombolas = contar_casos_quilombolas(arquivo_filtrado);
    if (TotalQuilombolas != -1) {
        printf("-Processos relacionados a causas de quilombolas: %d\n", TotalQuilombolas);
    }

    // Item 8
    int TotalIndigenas = contar_casos_indigenas(arquivo_filtrado);
    if (TotalIndigenas != -1) {
        printf("-Processos relacionados a causas indigenas: %d\n", TotalIndigenas);
    }

    // Item 9
    int TotalInfancia = contar_casos_infancia(arquivo_filtrado);
    if (TotalInfancia != -1) {
        printf("-Processos que envolvem causas de infancia e juventude: %d\n", TotalInfancia);
    }

    // Item 10
    long long int IdCalcular = 576662664; // ID para exemplo de um processo da tabela filtrada
    printf("-Calculando dias de tramitacao para o processo ID %lld...\n", IdCalcular);
    int DiasProcesso = calcular_dias_processo(arquivo_filtrado, IdCalcular);

    if (DiasProcesso >= 0) {
        printf("    => O processo levou %d dias para ser resolvido.\n", DiasProcesso);
    } else if (DiasProcesso == -1) {
        printf("    => Processo nao encontrado.\n");
    } else if (DiasProcesso == -2) {
        printf("    => Processo encontrado, mas ainda nao foi resolvido ou data invalida.\n");
    }

    // Item 11
    double CumprimentoMeta = calcular_cumprimento_meta1(arquivo_filtrado);
    printf("-Percentual de cumprimento da Meta 1: %.2f%%\n", CumprimentoMeta);

    // Item 12
    gerar_csv_julgados_meta1(arquivo_filtrado, arquivo_saida);

    printf("\nFim do programa.\n");

    return 0;
}