void strcpy(char* dest, char* src, int length);
int strlen(char* src);
void strcat(char* dest, char* appendString);
void strshorten(char* src, int shortenAmount);
int strtok(char** dest, char* src); //tokenize on spaces - assume a single space
int count_chars(char* src, char search_char);
int getPosIn(char* src, char search_char, unsigned char occurance);
