#include <stdio.h>

int abertura(FILE *arquivo) {
    int retorno = fprintf(arquivo, "<svg version=\"1.1\" ");

    if (retorno < 0) {
        return 0;
    }

    retorno = fprintf(arquivo, "width=\"300\" height=\"200\" ");

    if (retorno < 0) {
        return 0;
    }

    retorno = fprintf(arquivo, "xmlns=\"http://www.w3.org/2000/svg\">\n"); 

    if (retorno < 0) {
        return 0;
    }

    return 1;
}

int fechamento(FILE *arquivo) {
    int retorno = fprintf(arquivo, "</svg>");

    if (retorno < 0) {
        return 0;
    }

    return 1;
} 

int retangulo(FILE *arquivo) { 
    int x, y, altura, largura;

    printf("\nDigite a posição X para o retângulo: ");
    scanf("%d", &x);

    printf("\nDigite a posição Y para o retângulo: ");
    scanf("%d", &y);

    printf("\nDigite a altura para o retângulo: ");
    scanf("%d", &altura);

    printf("\nDigite a largura para o retângulo: ");
    scanf("%d", &largura);

    return fprintf(arquivo, "  <rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"blue\" />\n", x, y, largura, altura);
}


int circulo(FILE *arquivo) {
    int cx, cy, r;

    printf("\nDigite o CX para o círculo: ");
    scanf("%d", &cx);

    printf("\nDigite o CY para o círculo: ");
    scanf("%d", &cy);

    printf("\nDigite o raio para o círculo: ");
    scanf("%d", &r);

    
    return fprintf(arquivo, "  <circle cx=\"%d\" cy=\"%d\" r=\"%d\" fill=\"green\" />\n", cx, cy, r);
}

int main(void) {
    FILE *pArquivo = NULL;


    pArquivo = fopen("desenho.svg", "w");

    if (pArquivo == NULL) {
        printf("O arquivo não foi aberto!\n");
    } else {

        int resultado = abertura(pArquivo);

        if (resultado) {
        
            resultado = fprintf(pArquivo, "  <rect x=\"20\" y=\"30\" width=\"100\" height=\"100\" fill=\"red\" />\n");

            if (resultado > 0) { 
                resultado = retangulo(pArquivo);

                if (resultado > 0) { 
                    resultado = circulo(pArquivo);

                    if (resultado <= 0) {
                        printf("Erro ao gravar o círculo no arquivo.\n");
                    }
                } else {
                    printf("Erro ao gravar o retângulo do usuário no arquivo.\n");
                }
            } else {
                printf("Erro ao gravar o retângulo fixo no arquivo.\n");
            }

            
            if (resultado > 0) { 
                resultado = fechamento(pArquivo);
                if (resultado <= 0) {
                    printf("Erro ao fechar a tag SVG.\n");
                }
            }
        } else { 
            printf("Erro ao abrir o arquivo SVG.\n");
        }
    }

    
    if (pArquivo != NULL) {
        fclose(pArquivo);
    }
    
    return 0;
}