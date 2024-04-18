#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dados{
	char nome[100];  // nome aluno
	float nota1;
	float nota2;
	float MediaNotas;
	char situacao[12];
};

int getDados(struct Dados *X, FILE *arquivo1);

int main(){
	FILE *arquivo1;
	FILE *arquivo2;
	struct Dados X;
	
	arquivo1 = fopen("DadosEntrada.cvs", "r");  // arquivo para leitura (r)
	arquivo2 = fopen("SituacaoFinal.cvs", "w");
	
	if (arquivo1 == NULL || arquivo2 == NULL){
		printf("Erro ao Abrir");
		exit(1);
	}
	
	while (getDados(&X, arquivo1) != EOF) {
        X.MediaNotas = (X.nota1 + X.nota2) / 2;
        	if(X.MediaNotas >= 7.0){
        		strcpy(X.situacao, "APROVADO");
			} else strcpy(X.situacao, "REPROVADO");
        fprintf(arquivo2, "%s,%.2f,%s\n", X.nome, X.MediaNotas, X.situacao);
    }
	
	fclose(arquivo1);
	fclose(arquivo2);
	
	return 0;	
}

int getDados(struct Dados *X, FILE *arquivo1) {
	char telefone[15];  
    char curso[100];  
	
    if (fscanf(arquivo1, "%[^,],%[^,],%[^,],%f,%f", X->nome, telefone, curso, &(X->nota1),
		&(X->nota2)) != 5) {
        return EOF;
    }
    return 0;
}

