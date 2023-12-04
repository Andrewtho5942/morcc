#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_LEN (128)

char morse_to_char(char* s);

void main(int argc, char ** argv) {
  if ( argc != 2) {
    printf("Usage: toText [FILENAME]\n");
    exit(1);
  }
  char *filename = argv[1];
  FILE *fin = NULL;
  if ((fin = fopen(filename, "r")) == NULL) {
    printf("-- File read error: unable to open --\n");
    exit(1);
  }

  //check if the file is empty
  fseek(fin, 0, SEEK_END);
  if (ftell(fin) < 2) {
    printf("-- File read error: file is empty --\n");
    exit(1);
  }
  fseek(fin, 0, SEEK_SET);

  char fileout[MAX_FILE_LEN + 5] = "";
  strncpy(fileout, filename, strlen(filename) - 2);
  strcat(fileout, "_t.c");

  FILE * fout = fopen(fileout, "w");
  while (!feof(fin)) {
    char morse[MAX_FILE_LEN] = "";
    fscanf(fin, "%[^\n^ ]", morse);
    int notSpace = 0;
    if ((notSpace = strcmp(morse, "/")) == 0) {
      fprintf(fout, " ");
    }
    if (notSpace && (strcmp(morse, "\0") != 0)) {
      fprintf(fout, "%c", morse_to_char(morse));
    }
      char delim = getc(fin);
      if (delim == '\n') {
        fprintf(fout, "\n");
      }
  }
}


char morse_to_char(char* s) {
  if (strcmp(s, ".-") == 0) return 'a';
  else if (strcmp(s, "-...") == 0) return 'b';
  else if (strcmp(s, "-.-.") == 0) return 'c';
  else if (strcmp(s, "-..") == 0) return 'd';
  else if (strcmp(s, ".") == 0) return 'e';
  else if (strcmp(s, "..-.") == 0) return 'f';
  else if (strcmp(s, "--.") == 0) return 'g';
  else if (strcmp(s, "....") == 0) return 'h';
  else if (strcmp(s, "..") == 0) return 'i';
  else if (strcmp(s, ".---") == 0) return 'j';
  else if (strcmp(s, "-.-") == 0) return 'k';
  else if (strcmp(s, ".-..") == 0) return 'l';
  else if (strcmp(s, "--") == 0) return 'm';
  else if (strcmp(s, "-.") == 0) return 'n';
  else if (strcmp(s, "---") == 0) return 'o';
  else if (strcmp(s, ".--.") == 0) return 'p';
  else if (strcmp(s, "--.-") == 0) return 'q';
  else if (strcmp(s, ".-.") == 0) return 'r';
  else if (strcmp(s, "...") == 0) return 's';
  else if (strcmp(s, "-") == 0) return 't';
  else if (strcmp(s, "..-") == 0) return 'u';
  else if (strcmp(s, "...-") == 0) return 'v';
  else if (strcmp(s, ".--") == 0) return 'w';
  else if (strcmp(s, "-..-") == 0) return 'x';
  else if (strcmp(s, "-.--") == 0) return 'y';
  else if (strcmp(s, "--..") == 0) return 'z';

  else if (strcmp(s, "-----") == 0) return '0';
  else if (strcmp(s, ".----") == 0) return '1';
  else if (strcmp(s, "..---") == 0) return '2';
  else if (strcmp(s, "...--") == 0) return '3';
  else if (strcmp(s, "....-") == 0) return '4';
  else if (strcmp(s, ".....") == 0) return '5';
  else if (strcmp(s, "-....") == 0) return '6';
  else if (strcmp(s, "--...") == 0) return '7';
  else if (strcmp(s, "---..") == 0) return '8';
  else if (strcmp(s, "----.") == 0) return '9';

  else if (strcmp(s, "-.-.--") == 0) return '!';
  else if (strcmp(s, ".-..-.") == 0) return '"';
  else if (strcmp(s, "...-..-") == 0) return '$';
  else if (strcmp(s, ".-...") == 0) return '&';
  else if (strcmp(s, ".----.") == 0) return '\'';
  else if (strcmp(s, "-.--.") == 0) return '(';
  else if (strcmp(s, "-.--.-") == 0) return ')';
  else if (strcmp(s, ".-.-.") == 0) return '+';
  else if (strcmp(s, "--..--") == 0) return ',';
  else if (strcmp(s, "-....-") == 0) return '-';
  else if (strcmp(s, ".-.-.-") == 0) return '.';
  else if (strcmp(s, "-..-.") == 0) return '/';
  else if (strcmp(s, "---...") == 0) return ':';
  else if (strcmp(s, "-.-.-.") == 0) return ';';
  else if (strcmp(s, "-...-") == 0) return '=';
  else if (strcmp(s, "..--..") == 0) return '?';
  else if (strcmp(s, ".--.-.") == 0) return '@';
  else if (strcmp(s, "..--.-") == 0) return '_';

  //custom translations (not in international morse code)
  else if (strcmp(s, "------") == 0) return '#';
  else if (strcmp(s, ".-----") == 0) return '%';
  else if (strcmp(s, "-.----") == 0) return '*';
  else if (strcmp(s, "..----") == 0) return '<';
  else if (strcmp(s, "--.---") == 0) return '>';
  else if (strcmp(s, ".-.---") == 0) return '[';
  else if (strcmp(s, "...---") == 0) return '\\';
  else if (strcmp(s, "---.--") == 0) return ']';
  else if (strcmp(s, ".--.--") == 0) return '^';
  else if (strcmp(s, "..-.--") == 0) return '`';
  else if (strcmp(s, "....--") == 0) return '{';
  else if (strcmp(s, "----.-") == 0) return '|';
  else if (strcmp(s, ".---.-") == 0) return '}';
  else if (strcmp(s, ".--..-") == 0) return '~';
  else if (strcmp(s, "..-..-") == 0) return '\t';

  else return '\0';
}
