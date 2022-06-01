#include <stdio.h>
#include <stdlib.h>

char* readline(int *LINE_LEN);
void reset_line(char **LINE, int *LINE_LEN);

int main(int argc, char *argv[]){
  int STATUS = 1, LINE_LEN = 1;
  char *PROMPT = (char*)malloc(4), *LINE = (char*)malloc(LINE_LEN + 1);
  PROMPT = "a/d> ";
  while(STATUS){
    printf("%s", PROMPT);
    LINE = readline(&LINE_LEN);
    reset_line(&LINE, &LINE_LEN);
  }
  return STATUS;
}

char *readline(int *LINE_LEN){
  char c;
  char *line = (char*)malloc(*LINE_LEN + 1);
  while(c != '\n'){
    c = getchar();
    line[*LINE_LEN] = c;
    (*LINE_LEN)++;
    line = (char*)realloc(line, *LINE_LEN + 1);
  }
  line[*LINE_LEN] = '\0';
  return line;
}

void reset_line(char **LINE, int *LINE_LEN){
  *LINE_LEN = 1;
  free(*LINE);
}

