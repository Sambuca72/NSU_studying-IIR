#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 500001

int peekToken(char *str, char *token, int *adr) {
    int i = *adr;
    while (str[i] == ' ') i++;
    *adr = i;
    if (str[i] == '\0') {
        token[0] = '\0';
        return 0;
    }
    if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == ')') {
        token[0] = str[i];
        token[1] = '\0';
        return 1;
    }
    int j = 0;
    while (str[i + j] >= '0' && str[i + j] <= '9') {
        token[j] = str[i + j];
        j++;
    }
    token[j] = '\0';
    return j;
}

void readToken(char *str, char *token, int *adr) {
    *adr += peekToken(str, token, adr);
}

double expr(char *str, int *adr);

double atom(char *str, int *adr) {
    char token[5];
    peekToken(str, token, adr);
    if (token[0] == '-') {
        readToken(str, token, adr);
        return -atom(str, adr);
    }
    if (token[0] == '(') {
        readToken(str, token, adr);
        double res = expr(str, adr);
        readToken(str, token, adr);
        return res;
    }
    readToken(str, token, adr);
    return atof(token);
}

double monome(char *str, int *adr) {
    double res = atom(str, adr);
    char token[5];
    while (1) {
        peekToken(str, token, adr);
        if (token[0] == '*') {
            readToken(str, token, adr);
            res *= atom(str, adr);
        }
        else if (token[0] == '/') {
            readToken(str, token, adr);
            res /= atom(str, adr);
        }
        else break;
    }
    return res;
}

double expr(char *str, int *adr) {
    double res = monome(str, adr);
    char token[5];
    while (1) {
        peekToken(str, token, adr);
        if (token[0] == '+') {
            readToken(str, token, adr);
            res += monome(str, adr);
        }
        else if (token[0] == '-') {
            readToken(str, token, adr);
            res -= monome(str, adr);
        }
        else break;
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char *str = (char*)malloc(MAX_STR * sizeof(char));
    gets(str);

    int adr = 0;
    double res = expr(str, &adr);

    printf("%.20lf", res);

    free(str);
    fclose(stdin);
    fclose(stdout);
    return 0;
}