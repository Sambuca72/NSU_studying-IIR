#include <stdio.h>
#include <string.h>
#define maxlen 101

int compare_abs(const char *num1, const char *num2) {
    int len_1 = strlen(num1), len_2 = strlen(num2);
    
    
    if (len_1 > len_2) return 1;
    if (len_1 < len_2) return -1;

    
    for (int i = 0; i < len_1; i++) {
        if (num1[i] > num2[i]) return 1;
        if (num1[i] < num2[i]) return -1;
    }

    return 0;  
}

void add_positive(char *num1, char *num2, char *res) {
    int len_1 = strlen(num1), len_2 = strlen(num2);
    int carry = 0, sum, i = len_1 - 1, j = len_2 - 1, k = 0;
    char temp[maxlen + 1] = {0};

    while (i >= 0 || j >= 0 || carry) {
        sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        temp[k++] = sum % 10 + '0';
        carry = sum / 10;
    }

    for (int m = 0; m < k; m++) {
        res[m] = temp[k - 1 - m];
    }
    res[k] = '\0';
}

// Функция для вычитания положительных чисел
void subtract_positive(char *num1, char *num2, char *res) {
    int len_1 = strlen(num1), len_2 = strlen(num2);
    int borrow = 0, diff, i = len_1 - 1, j = len_2 - 1, k = 0;
    char temp[maxlen + 1] = {0};

    while (i >= 0 || j >= 0) {
        diff = (i >= 0 ? num1[i--] - '0' : 0) - (j >= 0 ? num2[j--] - '0' : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        temp[k++] = diff + '0';
    }

    while (k > 1 && temp[k - 1] == '0') {
        k--;  // Удаляем ведущие нули
    }

    for (int m = 0; m < k; m++) {
        res[m] = temp[k - 1 - m];
    }
    res[k] = '\0';
}

// Функция для сложения с учётом отрицательных чисел
void adding(char *num1, char *num2, char *res) {
    int len_1 = strlen(num1), len_2 = strlen(num2);
    int negative1 = 0, negative2 = 0;  // Используем 0 и 1 вместо логических значений

    // Определяем знаки чисел
    if (num1[0] == '-') {
        negative1 = 1;  // Число num1 отрицательное
        num1++;  // Пропускаем знак
        len_1--;
    }
    if (num2[0] == '-') {
        negative2 = 1;  // Число num2 отрицательное
        num2++;  // Пропускаем знак
        len_2--;
    }

    // Сложение или вычитание в зависимости от знаков
    if (negative1 == negative2) {
        // Если знаки одинаковы, выполняем сложение
        if (negative1) {
            res[0] = '-';  // Если оба числа отрицательные, результат тоже отрицательный
            res++;
        }
        add_positive(num1, num2, res);  // Сложение положительных чисел
    } else {
        // Если знаки разные, выполняем вычитание
        if (compare_abs(num1, num2) >= 0) {
            if (negative1) {
                res[0] = '-';  // Результат отрицательный, если num1 по модулю больше и отрицательно
                res++;
            }
            subtract_positive(num1, num2, res);  // num1 >= num2 по модулю
        } else {
            if (negative2) {
                res[0] = '-';  // Результат отрицательный, если num2 по модулю больше и отрицательно
                res++;
            }
            subtract_positive(num2, num1, res);  // num2 > num1 по модулю
        }
    }
}

void multiply(char *num1, char *num2, char *res) {
    int len_1 = strlen(num1), len_2 = strlen(num2);
    int temp[maxlen * 2] = {0};  // Для хранения промежуточного результата
    int is_negative =0;    // Флаг для знака результата

    // Проверка на отрицательность чисел
    if (num1[0] == '-') {
        is_negative = 1;  // Инвертируем знак
        num1++;  // Сдвигаем указатель, чтобы пропустить знак
        len_1--; // Уменьшаем длину числа
    }
    if (num2[0] == '-') {
        is_negative = 1;  // Инвертируем знак
        num2++;  // Сдвигаем указатель
        len_2--; // Уменьшаем длину числа
    }

    // Умножение чисел
    for (int i = len_1 - 1; i >= 0; i--) {
        for (int j = len_2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int pos_low = (len_1 - 1 - i) + (len_2 - 1 - j);  
            int pos_high = pos_low + 1;  

            temp[pos_low] += mul;  
            temp[pos_high] += temp[pos_low] / 10;  
            temp[pos_low] %= 10;  
        }
    }

    // Определяем фактическую длину результата
    int k = maxlen * 2 - 1;
    while (k > 0 && temp[k] == 0) {
        k--;
    }

    // Формирование строки результата
    int index = 0;
    if (is_negative && !(k == 0 && temp[k] == 0)) {  // Добавляем знак минус, если результат не ноль
        res[index++] = '-';
    }

    for (int i = 0; i <= k; i++) {
        res[index++] = temp[k - i] + '0';
    }
    res[index] = '\0';  // Завершаем строку
}



void subtract(char *num1, char *num2, char *res) {
    int cmp = compare_abs(num1, num2);
    int len_1 = strlen(num1), len_2 = strlen(num2);
    int borrow = 0, diff, i, j, k = 0;
    char temp[maxlen + 1] = {0};
    int is_negative = 0;

    
    if (cmp < 0) {
        // Меняем местами числа для корректного вычитания
        char *temp_num = num1;
        num1 = num2;
        num2 = temp_num;
        is_negative = 1;  // Отметим, что результат отрицательный
        len_1 = strlen(num1);
        len_2 = strlen(num2);
    }

    i = len_1 - 1;
    j = len_2 - 1;

    // Производим вычитание
    while (i >= 0 || j >= 0) {
        diff = (i >= 0 ? num1[i--] - '0' : 0) - (j >= 0 ? num2[j--] - '0' : 0) - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        temp[k++] = diff + '0';
    }

    // Удаляем ведущие нули
    while (k > 1 && temp[k - 1] == '0') {
        k--;
    }

    // Если результат отрицательный, добавляем знак
    if (is_negative) {
        res[0] = '-';
        k++;
    }

    // Реверсируем строку и записываем результат
    for (int m = 0; m < k - is_negative; m++) {
        if (is_negative){
        res[is_negative + m] = temp[k - 2 - m];}
        else{res[m] = temp[k - 1 - m];}
    }
    res[k] = '\0';
}


int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);

    char seq[n][maxlen];
    memset(seq,0,sizeof(seq));

    for (int i =0;i<n;i++){
        int t;
        scanf("%d",&t);
        if(t==0){
            scanf("%s",&seq[i]);
        }else{
        
        int a,b;
        scanf("%d %d",&a,&b);
        
        if(t==1){
            adding(seq[a],seq[b],seq[i]);
        }
        else if(t==2){
            subtract(seq[a],seq[b],seq[i]);
        }
        else if(t==3){
            multiply(seq[a],seq[b],seq[i]);
        }}
    }

    for (int i = 0; i<n;i++){
        printf("%s\n",seq[i]);
    }

    fclose(stdin);
    fclose(stdout);
}