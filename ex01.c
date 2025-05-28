#include <stdio.h>

int main(void) {
  FILE *quadrado = NULL;

  quadrado = fopen("quadrado.svg", "w");

  if( quadrado == NULL ) {
    printf("O arquivo não foi aberto!");
  } else {
  fprintf(quadrado, "<svg version=\"1.1\"\n");
  fprintf(quadrado, "width=\"300\" height=\"200\"\n");
  fprintf(quadrado, "xmlns=\"http://www.w3.org/2000/svg\">\n");
  fprintf(quadrado, "<rect x=\"20\" y=\"30\" width=\"100\" height=\"100\" fill=\"red\" />\n");
  fprintf(quadrado, "</svg>\n");
  }
  fclose(quadrado);
  return 0;
}