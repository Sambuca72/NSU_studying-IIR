#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 1000000

// Проверка корректности скобочной последовательности с учётом перестановок
bool isValidSequence(const char *s) {
    int openCount[4] = {0};  
    int closeCount[4] = {0};

    // Обход строки и подсчёт скобок
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(') openCount[0]++;
        else if (c == ')') closeCount[0]++;
        else if (c == '{') openCount[1]++;
        else if (c == '}') closeCount[1]++;
        else if (c == '[') openCount[2]++;
        else if (c == ']') closeCount[2]++;
        else if (c == '<') openCount[3]++;
        else if (c == '>') closeCount[3]++;
    }

    // Проверка: совпадают ли открывающие и закрывающие скобки
    for (int i = 0; i < 4; i++) {
        if (openCount[i] != closeCount[i]) {
            return false; 
        }
    }

    
    char stack[MAX_LENGTH];
    int top = -1;
    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[' || c == '<') {
            stack[++top] = c; // Открывающие скобки кладём в стек
        } else {
            // Закрывающая скобка
            if (top == -1) return false; // Нет соответствующей открывающей скобки
            char topChar = stack[top];
            // Проверяем соответствие скобок
            if ((c == ')' && topChar == '(') ||
                (c == '}' && topChar == '{') ||
                (c == ']' && topChar == '[') ||
                (c == '>' && topChar == '<')) {
                top--; // Удаляем соответствующую скобку из стека
            } else {
                // Если скобки не совпадают, то пытаемся переставить
                bool swapped = false;
                for (int j = top - 1; j >= 0; j--) {
                    if ((c == ')' && stack[j] == '(') ||
                        (c == '}' && stack[j] == '{') ||
                        (c == ']' && stack[j] == '[') ||
                        (c == '>' && stack[j] == '<')) {
                        // Переставляем соседние скобки
                        char temp = stack[j];
                        stack[j] = stack[top];
                        stack[top] = temp;
                        top--;
                        swapped = true;
                        break;
                    }
                }
                if (!swapped) return false; // Если переставить нельзя, последовательность некорректна
            }
        }
    }

    return top == -1; 
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    char s[MAX_LENGTH];
    while (n--) {
        scanf("%s", s);

        if (isValidSequence(s)) {
            printf("T\n");
        } else {
            printf("NIL\n");
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
