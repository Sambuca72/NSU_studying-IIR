// // // // // #include <stdio.h>
// // // // // #include <string.h>
// // // // // #include <stdlib.h>

// // // // // #include <stdio.h>
// // // // // #include <stdlib.h>
// // // // // #include <string.h>

// // // // // typedef struct LongNum_s{
// // // // //     int len;
// // // // //     int arr[3000];
// // // // // }LongNum;


// // // // // void stolbik(LongNum *num1, LongNum *num2){
// // // // //     int carry=0;
// // // // //     for (int i =0;i<3000;i++){
// // // // //         if(carry!=0){
// // // // //         num1->arr[i]+=num2->arr[i]+carry;
// // // // //         carry=0;
// // // // //         }
// // // // //         else{num1->arr[i]+=num2->arr[i];}
      
// // // // //         if(num1->arr[i]>10){
// // // // //             carry=num1->arr[i]/10;
// // // // //             num1->arr[i]=num1->arr[i]%10;
// // // // //         }else if(num1->arr[i]==10){
// // // // //             carry=1;
// // // // //             num1->arr[i]=0;
// // // // //         }
// // // // //         //   printf("%d %d \n",num1->arr[i],carry);
// // // // //     }
// // // // // }

// // // // // void multiply(LongNum *num1, LongNum *num2) {
// // // // //     int temp[3000] = {0};  
// // // // //     int carry = 0;

// // // // //     for (int i = 0; i < num2->len; i++) {
// // // // //         carry = 0; // обнуляем перенос для каждой итерации умножения разряда

// // // // //         // Проход каждому разряду num1 и умножаем его на текущий разряд num2
// // // // //         for (int j = 0; j < num1->len; j++) {
// // // // //             int product = num1->arr[j] * num2->arr[i] + temp[i + j] + carry;
// // // // //             temp[i + j] = product % 10;  
// // // // //             carry = product / 10;         
// // // // //         }

// // // // //         temp[i + num1->len] += carry;
// // // // //     }

// // // // //     memcpy(num1->arr, temp, sizeof(temp));

// // // // //     // Рассчитываем новую длину 
// // // // //     num1->len = num1->len + num2->len;
// // // // //     num2->len=num1->len+num2->len;
// // // // //     // Убираем ведущие нули
// // // // //     while (num1->len > 1 && num1->arr[num1->len - 1] == 0) {
// // // // //         num1->len--;
// // // // //     }
// // // // // }

// // // // // void printlong(LongNum *num) {
// // // // //     int started = 0; 

    
// // // // //     for (int i = num->len - 1; i >= 0; i--) {
// // // // //         if (num->arr[i] != 0) {
// // // // //             started = 1; 
            
// // // // //         }

// // // // //         if (started) {
// // // // //             printf("%d", num->arr[i]);
// // // // //         }
// // // // //     }

    
// // // // //     if (!started) {
// // // // //         printf("0");
// // // // //     }

// // // // //     printf("\n");
// // // // // }


// // // // // int main(){
// // // // //     freopen("input.txt","r",stdin);
// // // // //     freopen("output.txt","w",stdout);
// // // // //     int n;
    
     
// // // // //     scanf("%d",&n);
    
// // // // //     if (n==1){
// // // // //         printf("1");
// // // // //     }
// // // // //     else if(n==0){
// // // // //         printf("1");
// // // // //     }
// // // // //     else{
// // // // //     // printf("%d\n",c);
// // // // //     LongNum num;
// // // // //     LongNum num1;
// // // // //     LongNum num2;
// // // // //     LongNum num3;
// // // // //     memset(num.arr,0,sizeof(num.arr));
// // // // //     memset(num3.arr,0,sizeof(num3.arr));
// // // // //     memset(num1.arr,0,sizeof(num1.arr));
// // // // //     memset(num2.arr,0,sizeof(num2.arr));
// // // // //     num.arr[0]=1;
// // // // //     // num.arr[1]=2;

// // // // //     num1.arr[0]=1;

// // // // //     num2.arr[0]=1;

// // // // //     num3.arr[0]=1;

// // // // //     num.len=2;
// // // // //     num1.len=1;
// // // // //     // multiply(&num,&num1);
// // // // //     int size=sizeof(num.arr);
    
// // // // //     for (int i =0;i<n;i++){
// // // // //         // memcpy(num2.arr,num.arr,size);
// // // // //         // printf("%d\n",num2.arr[0]);
// // // // //         multiply(&num,&num1);
// // // // //         stolbik(&num1,&num3);
// // // // //         // printlong(&num);
// // // // //         // printlong(&num1);
        
    
// // // // //         // memcpy(num1.arr,num2.arr,size);
// // // // //     }

// // // // //     // for (int i =c-1;i>=0;i--){
// // // // //     //     printf("%d",num.arr[i]);
// // // // //     // }
// // // // //     printlong(&num);
// // // // //     }
// // // // //     fclose(stdin);
// // // // //     fclose(stdout);
// // // // // }

// // // // #include <stdio.h>
// // // // // typedef struct DateTime_s
// // // // // {
// // // // //     int year, month, day;
// // // // //     int hours, minutes, seconds;
// // // // // } DateTime;
// // // // // int compare(DateTime d1, DateTime d2);
// // // // // DateTime min(const DateTime *arr, int cnt);
// // // // // int main(void)
// // // // // {
// // // // //     freopen("input.txt", "r", stdin);
// // // // //     freopen("output.txt", "w", stdout);
// // // // //     int n = 0;
// // // // //     scanf("%d", &n);
// // // // //     DateTime dates[n];
// // // // //     for (int i = 0; i < n; i++)
// // // // //     {
// // // // //         scanf("%d %d %d %d %d %d", &dates[i].year, &dates[i].month, &dates[i].day, &dates[i].hours, &dates[i].minutes, &dates[i].seconds);
// // // // //     }
// // // // //     DateTime earliest = min(dates, n);
// // // // //     printf("%d %d %d %d %d %d\n", earliest.year, earliest.month, earliest.day, earliest.hours, earliest.minutes, earliest.seconds);
// // // // //     fclose(stdin);
// // // // //     fclose(stdout);
// // // // //     return 0;
// // // // // }
// // // // // int compare(DateTime d1, DateTime d2)
// // // // // {
// // // // //     if (d1.year != d2.year)
// // // // //         return d1.year - d2.year;
// // // // //     if (d1.month != d2.month)
// // // // //         return d1.month - d2.month;
// // // // //     if (d1.day != d2.day)
// // // // //         return d1.day - d2.day;
// // // // //     if (d1.hours != d2.hours)
// // // // //         return d1.hours - d2.hours;
// // // // //     if (d1.minutes != d2.minutes)
// // // // //         return d1.minutes - d2.minutes;
// // // // //     return d1.seconds - d2.seconds;
// // // // // }
// // // // // DateTime min(const DateTime *arr, int cnt)
// // // // // {
// // // // //     DateTime minDate = arr[0];
// // // // //     for (int i = 1; i < cnt; i++)
// // // // //     {
// // // // //         if (compare(arr[i], minDate) < 0)
// // // // //         {
// // // // //             minDate = arr[i];
// // // // //         }
// // // // //     }
// // // // //     return minDate;
// // // // // }
// // // // #include <string.h>
// // // // #define maxlen 101
// // // // int compare_abs(const char *num1, const char *num2) {
// // // //     int len_1 = strlen(num1), len_2 = strlen(num2);
    
    
// // // //     if (len_1 > len_2) return 1;
// // // //     if (len_1 < len_2) return -1;

    
// // // //     for (int i = 0; i < len_1; i++) {
// // // //         if (num1[i] > num2[i]) return 1;
// // // //         if (num1[i] < num2[i]) return -1;
// // // //     }

// // // //     return 0;  
// // // // }






// // // // void subtract(char *num1, char *num2, char *res) {
// // // //     int cmp = compare_abs(num1, num2);
// // // //     int len_1 = strlen(num1), len_2 = strlen(num2);
// // // //     int borrow = 0, diff, i, j, k = 0;
// // // //     char temp[maxlen + 1] = {0};
// // // //     int is_negative = 0;

// // // //     // Если num1 < num2, то результат будет отрицательным
// // // //     if (cmp < 0) {
// // // //         // Меняем местами числа для корректного вычитания
// // // //         char *temp_num = num1;
// // // //         num1 = num2;
// // // //         num2 = temp_num;
// // // //         is_negative = 1;  // Отметим, что результат отрицательный
// // // //         len_1 = strlen(num1);
// // // //         len_2 = strlen(num2);
// // // //     }

// // // //     i = len_1 - 1;
// // // //     j = len_2 - 1;

// // // //     // Производим вычитание
// // // //     while (i >= 0 || j >= 0) {
// // // //         diff = (i >= 0 ? num1[i--] - '0' : 0) - (j >= 0 ? num2[j--] - '0' : 0) - borrow;
// // // //         if (diff < 0) {
// // // //             diff += 10;
// // // //             borrow = 1;
// // // //         } else {
// // // //             borrow = 0;
// // // //         }
// // // //         temp[k++] = diff + '0';
// // // //     }
// // // //     printf("%d %s\n",k,temp);
// // // //     // Удаляем ведущие нули
// // // //     while (k > 1 && temp[k - 1] == '0') {
// // // //         printf("%s\n",temp);
// // // //         k--;
// // // //     }
// // // //     printf("%d\n",k);
// // // //     // printf("%s\n",temp);

// // // //     // Если результат отрицательный, добавляем знак
// // // //     if (is_negative) {
// // // //         res[0] = '-';
// // // //         k++;
// // // //     }
// // // //     // printf("%s\n",temp);
// // // //     printf("%d\n",is_negative);

// // // //     // Реверсируем строку и записываем результат
// // // //     for (int m = 0; m < k - is_negative; m++) {
// // // //         // printf("%s\n",res);
// // // //         if (is_negative){
// // // //         res[is_negative + m] = temp[k - 2 - m];}
// // // //         else{res[m] = temp[k - 1 - m];}
// // // //         printf("%s\n",res);
// // // //     }
// // // //     res[k] = '\0';
// // // // }

// // // // int main(){
// // // //     freopen("input.txt","r",stdin);
// // // //     freopen("output.txt","w",stdout);
// // // //     char c1[101]="12";
// // // //     char c2[101]="12";
// // // //     char c3[101];
// // // //     subtract(c1,c2,c3);
// // // //     printf("%s",c3);
// // // //     fclose(stdin);
// // // //     fclose(stdout);
// // // // }

// // #include <stdio.h>
// // #include <string.h>
// // #include <stdlib.h>

// // // typedef struct node_s{
// // //     char data[10];
// // //     struct node_s* next;
// // // }node;

// // // node *insert_beg( node *start, char* num)
// // // {
// // //     node *new_node;
// // //     // char num[10];
// // //     // // printf("\n Enter the data : ");
// // //     // scanf("%s", &num);
// // //     new_node = (node *)malloc(sizeof(node*));
// // //     strcpy(new_node->data, num);
// // //     new_node->next = start;
// // //     start = new_node;
// // //     return start;
// // // }


// // // node *delete_beg(node *start)
// // // {
// // //     if (start == NULL) {
// // //         return NULL;  // Список уже пуст
// // //     }
// // //     node *ptr=start;
// // //     start = start->next;
// // //     free(ptr);
// // //     return start;
// // // }

// // // node *insert_after(node *start, char *num) {
// // //     node *new_node = (node *)malloc(sizeof(node));
// // //     strcpy(new_node->data, num);
// // //     new_node->next = start->next;
// // //     start->next = new_node;
// // //     return start;
// // // }

// // // void creatll(node** nodes,int n){
// // //     for (int i =0; i<n;i++){
// // //         nodes[i]=(node*)malloc(sizeof(node));
// // //         nodes[i]->next = NULL;
// // //     }
// // // }

// // // node *delete_after(node *start) {
// // //     if (start == NULL || start->next == NULL) {
// // //         return start; // Нечего удалять
// // //     }
    
// // //     node *temp = start->next; // Узел, который нужно удалить
// // //     start->next = temp->next; // Перенаправляем указатель текущего узла на следующий после удаляемого
// // //     free(temp);
    
// // //     return start;
// // // }


// // // void loading(node** nodes,int n){
// // //     for(int i =0;i<n;i++){
// // //         char val[10];
// // //         int nextindex;
// // //         scanf("%s %d",&val, &nextindex);

// // //         strcpy(nodes[i]->data,val);
// // //         if(nextindex != -1){
// // //             nodes[i]->next=nodes[nextindex];
// // //         }
// // //     }
// // // }

// // // void printList(node* head) {
// // //     node* current = head;
// // //     while (current != NULL) {
// // //         printf("%s\n", current->data);  // Выводим значение узла с тремя знаками после запятой
// // //         current = current->next;
// // //     }
// // // }

// // // int main(){
// // //     freopen("input.txt","r",stdin);
// // //     freopen("output.txt","w",stdout);

// // //     int t;
// // //     scanf("%d",&t);
// // //     printf("===\n");
// // //     for (int _ =0;_<t;_++){
// // //         int n,f,q;
// // //         scanf("%d %d %d",&n,&f,&q);

// // //         node* nodes[n];
// // //         creatll(nodes,n);
// // //         loading(nodes,n);
        
// // //         for (int _ = 0;_<q;_++){
// // //             int ty,ind;
// // //             char val[10];
// // //             scanf("%d",&ty);
// // //             if (ty==0){
// // //                 scanf(" %d %s",&ind,val);
// // //                 // printf("%d %s\n",ind,val);

// // //                 if(ind==(-1)){
// // //                     nodes[f] = insert_beg(nodes[f],val);
// // //                 }
// // //                 else if(ind!= -1){
// // //                     // printf("PIP");
// // //                     nodes[ind] = insert_after(nodes[ind],val);
// // //                 }
// // //             }
// // //             else if(ty == 1){
// // //                 scanf("%d",&ind);
// // //                 printf("%d\n",ind);
// // //                 if (ind == -1){
// // //                     // printf("%s\n",nodes[f]->data);
// // //                     nodes[f] = delete_beg(nodes[f]);
// // //                 }
// // //                 else{
// // //                     nodes[ind]=delete_after(nodes[ind]);
// // //                 }
// // //             }

// // //         }

// // //         printList(nodes[f]);
// // //         printf("===\n");
// // //         for (int i = 0; i < n; i++) {
// // //             free(nodes[i]);
// // //         }

// // //     }


// // //     fclose(stdin);
// // //     fclose(stdout);
// // // }

// // void addprev(int index, int value) {
// //     nodes[tail].data = value;  // Устанавливаем значение нового узла

// //     if (index == -1) {  // Добавление в конец списка
// //         nodes[tail].prev = tail - 1;  // Указываем, что предыдущий элемент - это текущий tail
// //         nodes[tail].next = -1;  // Новый элемент будет последним, поэтому следующий элемент - отсутствует

// //         if (tail != head) {  // Если список не пустой
// //             nodes[tail - 1].next = tail;  // Предыдущий последний элемент теперь указывает на новый узел
// //         } else {
// //             head = tail;  // Если список был пуст, новый узел становится первым
// //         }
// //     } else {  // Добавление перед элементом с индексом index
// //         nodes[tail].next = index;  // Новый узел указывает на узел с индексом index как на следующий
// //         nodes[tail].prev = nodes[index].prev;  // Новый узел указывает на предыдущий элемент узла index

// //         if (nodes[index].prev != -1) {  // Если узел с индексом index не был первым
// //             nodes[nodes[index].prev].next = tail;  // Предыдущий узел теперь указывает на новый узел
// //         } else {
// //             head = tail;  // Если узел с индексом index был первым, обновляем head
// //         }
// //         nodes[index].prev = tail;  // Узел с индексом index теперь указывает на новый узел как на предыдущий
// //     }

// //     tail++;  // Увеличиваем tail для следующего добавления
// // }



// // int main() {
// //     head = 0;
// //     tail = 2;

// //     // Инициализируем список
// //     nodes[0].data = 10;
// //     nodes[0].prev = -1;
// //     nodes[0].next = 1;

// //     nodes[1].data = 20;
// //     nodes[1].prev = 0;
// //     nodes[1].next = -1;

// //     // Добавляем новый элемент в конец
// //     addprev(-1, 30);

// //     // Вывод списка для проверки
// //     int current = head;
// //     while (current != -1) {
// //         printf("%d -> ", nodes[current].data);
// //         current = nodes[current].next;
// //     }
// //     printf("NULL\n");

// //     return 0;
// // }
// #include <stdio.h>

// typedef struct Node {
//     int value;
//     int next;
//     int prev;
// } Node;

// Node nodes[200000]; // Массив для узлов списка
// int tail; // Хранит индекс следующего свободного узла

// int head, last; // Индексы первого и последнего узла списка

// // Функция для добавления узла перед узлом с индексом index
// void add_before(int index, int value) {
//     nodes[tail].value = value;

//     if (index == -1) { // Добавление в конец списка
//         nodes[tail].next = -1;
//         nodes[tail].prev = last;
        
//         if (last != -1) {
//             nodes[last].next = tail;
//         }
        
//         last = tail; // Обновляем последний узел

//         if (head == -1) { // Если это первый элемент, обновляем head
//             head = tail;
//         }
//     } else { // Добавление перед узлом index
//         nodes[tail].next = index;
//         nodes[tail].prev = nodes[index].prev;

//         if (nodes[index].prev != -1) {
//             nodes[nodes[index].prev].next = tail;
//         } else {
//             head = tail; // Если узел index был первым, обновляем head
//         }
//         nodes[index].prev = tail;
//     }
    
//     printf("%d\n", tail); // Выводим индекс нового узла
//     tail++;
// }

// // Функция для добавления узла после узла с индексом index
// void add_after(int index, int value) {
//     nodes[tail].value = value;

//     if (index == -1) { // Добавление в начало списка
//         nodes[tail].prev = -1;
//         nodes[tail].next = head;

//         if (head != -1) {
//             nodes[head].prev = tail;
//         }
        
//         head = tail; // Обновляем первый узел

//         if (last == -1) { // Если это первый элемент, обновляем last
//             last = tail;
//         }
//     } else { // Добавление после узла index
//         nodes[tail].prev = index;
//         nodes[tail].next = nodes[index].next;

//         if (nodes[index].next != -1) {
//             nodes[nodes[index].next].prev = tail;
//         } else {
//             last = tail; // Если узел index был последним, обновляем last
//         }
//         nodes[index].next = tail;
//     }
    
//     printf("%d\n", tail); // Выводим индекс нового узла
//     tail++;
// }

// // Функция для удаления узла с индексом index
// void delete_node(int index) {
//     printf("%d\n", nodes[index].value); // Выводим значение удаленного узла

//     if (nodes[index].prev != -1) {
//         nodes[nodes[index].prev].next = nodes[index].next;
//     } else {
//         head = nodes[index].next; // Если удаляем head, обновляем его
//     }

//     if (nodes[index].next != -1) {
//         nodes[nodes[index].next].prev = nodes[index].prev;
//     } else {
//         last = nodes[index].prev; // Если удаляем last, обновляем его
//     }
// }

// // Функция для вывода списка
// void print_list() {
//     int current = head;
//     while (current != -1) {
//         printf("%d ", nodes[current].value);
//         current = nodes[current].next;
//     }
//     printf("\n");
// }

// int main() {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     int T;
//     scanf("%d", &T); // Количество тестов

//     while (T--) {
//         int N, F, L, Q;
//         scanf("%d%d%d%d", &N, &F, &L, &Q);

//         head = F;
//         last = L;
//         tail = N;

//         // Инициализация списка
//         for (int i = 0; i < N; i++) {
//             int value, next, prev;
//             scanf("%d%d%d", &value, &next, &prev);
//             nodes[i].value = value;
//             nodes[i].next = next;
//             nodes[i].prev = prev;
//         }

//         // Обработка операций
//         while (Q--) {
//             int type, index;
//             scanf("%d%d", &type, &index);

//             if (type == 1) { // Добавление узла спереди
//                 int value;
//                 scanf("%d", &value);
//                 add_after(index, value);
//             } else if (type == -1) { // Добавление узла сзади
//                 int value;
//                 scanf("%d", &value);
//                 add_before(index, value);
//             } else if (type == 0) { // Удаление узла
//                 delete_node(index);
//             }
//         }

//         // Вывод текущего состояния списка
//         print_list();
//     }

//     fclose(stdin);
//     fclose(stdout);
//     return 0;
// }
#include <stdio.h>


int main() {
    int n;
    scanf("\\x%d",&n);
    printf("%d",n);
}


