#include <stdio.h>
#include <string.h>
// Функция для перевода числа из p-ичной системы в десятичную
int integer_pow(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
long long convert_to_decimal(const char *num, int base) {
    long long decimal_value = 0;
    int length = strlen(num);

    for (int i = 0; i < length; i++) {
        char digit = num[length - 1 - i];
        int value;

        if (digit >= '0' && digit <= '9') {
            value = digit - '0';
        } else if (digit >= 'a' && digit <= 'z') {
            value = digit - 'a' + 10;
        } else {
            // Неверный символ
            return -1;
        }

        decimal_value += value * integer_pow(base, i);
    }
    return decimal_value;
}

// Функция для перевода числа из десятичной системы в q-ичную
void convert_from_decimal(long long decimal_value, int base, char *result) {
    int index = 0;

    if (decimal_value == 0) {
        result[index++] = '0';
    } else {
        while (decimal_value > 0) {
            int remainder = decimal_value % base;
            if (remainder < 10) {
                result[index++] = '0' + remainder;
            } else {
                result[index++] = 'a' + (remainder - 10);
            }
            decimal_value /= base;
        }
    }

    // Реверсируем строку для правильного порядка
    result[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = result[i];
        result[i] = result[index - i - 1];
        result[index - i - 1] = temp;
    }
}

int main() {
    int p, q;
    char N[10*10*10*10];
    
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d %d %s", &p, &q,&N);
    // printf("%s\n",N);
    

    // Перевод N из p-ичной системы в десятичную
    long long decimal_value = convert_to_decimal(N, p);

    // Перевод из десятичной системы в q-ичную
    char result[10*10*10*10];
    convert_from_decimal(decimal_value, q, result);
    printf("%s",result);

    // Запись результата в файл
    fclose(stdin);
    fclose(stdout);

    
}
