#define MAX_FILE_LEN (128)

char* char_to_morse(char c);

void main(int argc, char ** argv) {
  if ( argc != 2) {
    printf("Usage: toMorse [FILENAME]\n");
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
  strcat(fileout, "_m.c");

  FILE * fout = fopen(fileout, "w");
  while (!feof(fin)) {
    char cur = '\0';
    fscanf(fin, "%c", &cur);
    if (cur == '\n') {
      fseek(fout, -1, SEEK_CUR);
      fprintf(fout, "\n");
      continue;
    }
    else if (cur == ' '){
      fprintf(fout, "/ ");
      continue;
    }
    else if (cur == 0) {
      continue;
    }

    fprintf(fout, "%s ", char_to_morse(cur));

  }
}


char* char_to_morse(char c) {
  if ((c >= 65) && (c <= 90)) {
    c += 32;
  }
  switch(c) {
    case 'a': return ".-";
    case 'b': return "-...";
    case 'c': return "-.-.";
    case 'd': return "-..";
    case 'e': return ".";
    case 'f': return "..-.";
    case 'g': return "--.";
    case 'h': return "....";
    case 'i': return "..";
    case 'j': return ".---";
    case 'k': return "-.-";
    case 'l': return ".-..";
    case 'm': return "--";
    case 'n': return "-.";
    case 'o': return "---";
    case 'p': return ".--.";
    case 'q': return "--.-";
    case 'r': return ".-.";
    case 's': return "...";
    case 't': return "-";
    case 'u': return "..-";
    case 'v': return "...-";
    case 'w': return ".--";
    case 'x': return "-..-";
    case 'y': return "-.--";
    case 'z': return "--..";

    case '0': return "-----";
    case '1': return ".----";
    case '2': return "..---";
    case '3': return "...--";
    case '4': return "....-";
    case '5': return ".....";
    case '6': return "-....";
    case '7': return "--...";
    case '8': return "---..";
    case '9': return "----.";

    case '!': return "-.-.--";
    case '"': return ".-..-.";
    case '$': return "...-..-";
    case '&': return ".-...";
    case '\'': return ".----.";
    case '(': return "-.--.";
    case ')': return "-.--.-";
    case '+': return ".-.-.";
    case ',': return "--..--";
    case '-': return "-....-";
    case '.': return ".-.-.-";
    case '/': return "-..-.";
    case ':': return "---...";
    case ';': return "-.-.-.";
    case '=': return "-...-";
    case '?': return "..--..";
    case '@': return ".--.-.";
    case '_': return "..--.-";

    //Custom translations (Not defined in international morse code).
    case '#': return "------";
    case '%': return ".-----";
    case '*': return "-.----";
    case '<': return "..----";
    case '>': return "--.---";
    case '[': return ".-.---";
    case '\\': return "...---";
    case ']': return "---.--";
    case '^': return ".--.--";
    case '`': return "..-.--";
    case '{': return "....--";
    case '|': return "----.-";
    case '}': return ".---.-";
    case '~': return ".--..-";
    case '\t': return "..-..-";

    default: {
      char text[64] = "";
      sprintf(text, "|NO TRANSLATION FOUND: %d|", (int)c);
      return strdup(text);
    }
  }
}
