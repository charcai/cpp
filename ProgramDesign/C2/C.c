#include <stdio.h>
#include <string.h>

char ch[200];

int main() {
    gets(ch);
    int len = strlen(ch);
     for(int i = 0; i < len; ++i) {
        switch(ch[i]) {
            case '0':   ch[i] = '9'; break;
            case '1':   ch[i] = '8'; break;
            case '2':   ch[i] = '7'; break;
            case '3':   ch[i] = '6'; break;
            case '4':   ch[i] = '5'; break;
            case '5':   ch[i] = '4'; break;
            case '6':   ch[i] = '3'; break;
            case '7':   ch[i] = '2'; break;
            case '8':   ch[i] = '1'; break;
            case '9':   ch[i] = '0'; break;
            case 'a':   ch[i] = 'z'; break;
            case 'b':   ch[i] = 'y'; break;
            case 'c':   ch[i] = 'x'; break;
            case 'd':   ch[i] = 'w'; break;
            case 'e':   ch[i] = 'v'; break;
            case 'f':   ch[i] = 'u'; break;
            case 'g':   ch[i] = 't'; break;
            case 'h':   ch[i] = 's'; break;
            case 'i':   ch[i] = 'r'; break;
            case 'j':   ch[i] = 'q'; break;
            case 'k':   ch[i] = 'p'; break;
            case 'l':   ch[i] = 'o'; break;
            case 'm':   ch[i] = 'n'; break;
            case 'n':   ch[i] = 'm'; break;
            case 'o':   ch[i] = 'l'; break;
            case 'p':   ch[i] = 'k'; break;
            case 'q':   ch[i] = 'j'; break;
            case 'r':   ch[i] = 'i'; break;
            case 's':   ch[i] = 'h'; break;
            case 't':   ch[i] = 'g'; break;
            case 'u':   ch[i] = 'f'; break;
            case 'v':   ch[i] = 'e'; break;
            case 'w':   ch[i] = 'd'; break;
            case 'x':   ch[i] = 'c'; break;
            case 'y':   ch[i] = 'b'; break;
            case 'z':   ch[i] = 'a'; break;
        }
    }
    puts(ch);
    putchar('\n');
    return 0;
}