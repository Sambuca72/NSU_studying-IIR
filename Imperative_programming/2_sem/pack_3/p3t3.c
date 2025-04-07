#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPR_LEN 500000

typedef struct {
    double *data;
    int capacity;
    int top;
} Stack;

void init_stack(Stack *s, int capacity) {
    s->data = (double *)malloc(capacity * sizeof(double));
    s->capacity = capacity;
    s->top = -1;
}

void free_stack(Stack *s) {
    free(s->data);
}

void push(Stack *s, double value) {
    if (s->top >= s->capacity - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

double pop(Stack *s) {
    if (s->top < 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

double peek(Stack *s) {
    if (s->top < 0) {
        fprintf(stderr, "Stack underflow\n");
        exit(1);
    }
    return s->data[s->top];
}

int is_empty(Stack *s) {
    return s->top == -1;
}

typedef struct {
    char *data;
    int capacity;
    int top;
} CharStack;

void init_char_stack(CharStack *s, int capacity) {
    s->data = (char *)malloc(capacity * sizeof(char));
    s->capacity = capacity;
    s->top = -1;
}

void free_char_stack(CharStack *s) {
    free(s->data);
}

void char_push(CharStack *s, char value) {
    if (s->top >= s->capacity - 1) {
        fprintf(stderr, "CharStack overflow\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

char char_pop(CharStack *s) {
    if (s->top < 0) {
        fprintf(stderr, "CharStack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

char char_peek(CharStack *s) {
    if (s->top < 0) {
        fprintf(stderr, "CharStack underflow\n");
        exit(1);
    }
    return s->data[s->top];
}

int is_char_empty(CharStack *s) {
    return s->top == -1;
}

int precedence(char op) {
    switch (op) {
        case 'u': return 4; // Унарный минус
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default: return 0;
    }
}

void process_operator(CharStack *op_stack, Stack *output) {
    char op = char_pop(op_stack);
    if (op == 'u') {
        double operand = pop(output);
        push(output, -operand);
    } else {
        double b = pop(output);
        double a = pop(output);
        switch (op) {
            case '+': push(output, a + b); break;
            case '-': push(output, a - b); break;
            case '*': push(output, a * b); break;
            case '/': push(output, a / b); break;
        }
    }
}

double evaluate_expression(const char *expr) {
    CharStack op_stack;
    init_char_stack(&op_stack, MAX_EXPR_LEN);
    Stack output;
    init_stack(&output, MAX_EXPR_LEN);

    int i = 0;
    while (expr[i] != '\0') {
        if (isspace(expr[i])) {
            i++;
            continue;
        }

        if (isdigit(expr[i])) {
            // Чтение числа
            double num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            if (expr[i] == '.') {
                i++;
                double fraction = 0.1;
                while (isdigit(expr[i])) {
                    num += (expr[i] - '0') * fraction;
                    fraction *= 0.1;
                    i++;
                }
            }
            push(&output, num);
        } else if (expr[i] == '(') {
            char_push(&op_stack, '(');
            i++;
        } else if (expr[i] == ')') {
            while (char_peek(&op_stack) != '(') {
                process_operator(&op_stack, &output);
            }
            char_pop(&op_stack); // Удаляем '('
            i++;
        } else {
            // Обработка операторов
            char op = expr[i];
            // Проверка на унарный минус
            if (op == '-' && (i == 0 || expr[i-1] == '(' || 
                               strchr("+-*/", expr[i-1]))) {
                op = 'u'; // Унарный минус
            }
            while (!is_char_empty(&op_stack) && 
                   precedence(char_peek(&op_stack)) >= precedence(op)) {
                process_operator(&op_stack, &output);
            }
            char_push(&op_stack, op);
            i++;
        }
    }

    // Обработка оставшихся операторов
    while (!is_char_empty(&op_stack)) {
        process_operator(&op_stack, &output);
    }

    double result = pop(&output);
    free_stack(&output);
    free_char_stack(&op_stack);
    return result;
}

int main() {
    char expr[MAX_EXPR_LEN + 1];
    if (fgets(expr, sizeof(expr), stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }
    // Удаляем символ новой строки, если он есть
    size_t len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') {
        expr[len - 1] = '\0';
    }

    double result = evaluate_expression(expr);
    printf("%.20f\n", result);

    return 0;
}