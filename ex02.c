#include <stdio.h>

int main(void) {
  FILE *quadrado = NULL;
  char nome[20];
  int x, y;
  int altura, largura;

  printf("Digite o nome do arquivo (Com .svg): ");
  scanf("%s", nome);

  printf("Digite a posição X: ");
  scanf("%d", &x);

  printf("Digite a posição Y: ");
  scanf("%d", &y);

  printf("Digite a altura: ");
  scanf("%d", &altura);

  printf("Digite a largura: ");
  scanf("%d", &largura);

  quadrado = fopen(nome, "w");

  if( quadrado == NULL ) {
    printf("O arquivo não foi aberto!");
  } else {
  fprintf(quadrado, "<svg version=\"1.1\"\n");
  fprintf(quadrado, "width=\"300\" height=\"200\"\n");
  fprintf(quadrado, "xmlns=\"http://www.w3.org/2000/svg\">\n");
  fprintf(quadrado, "<rect x=\"%d\" y=\"%d\" width=\"%d\" height=\"%d\" fill=\"red\" />\n", x, y, largura, altura);
  fprintf(quadrado, "</svg>\n");
  }
  fclose(quadrado);
  return 0;
}
