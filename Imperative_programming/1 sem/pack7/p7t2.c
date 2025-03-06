#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//какой-нибудь целочисленный тип (желательно беззнаковый)
typedef unsigned int bitword ;

#define bpw (sizeof(bitword)*8)

//инициализирует массив битов длины num, устанавливая все его биты в ноль
void bitsetZero ( bitword * arr , int num ){
    int nums = (num+bpw-1)/bpw;
    memset(arr,0,nums*sizeof(bitword));
}

//возвращает значение idx-ого бита (0 или 1)
int bitsetGet ( const bitword * arr , int idx ){
    int word_idx = idx / bpw;
    int bit_idx = idx % bpw;
    return (arr[word_idx] >> bit_idx) & 1;
}


//устанавливает значение idx-ого бита в newval (которое равно 0 или 1)
void bitsetSet(bitword *arr, int idx, int newval) {
    int word_idx = idx / bpw;
    int bit_idx = idx % bpw;
    if (newval)
        arr[word_idx] |= (1 << bit_idx);  // Установка бита
    else
        arr[word_idx] &= ~(1 << bit_idx); // Сброс бит
    // printf("%d\n",arr[bit_idx]);
}

//возвращает 1, если среди битов с номерами k
//для left <= k < right есть единичный, и 0 иначе
int bitsetAny ( const bitword * arr , int left , int right ){
    int left_word = left / bpw;
    int right_word = (right - 1) / bpw;
    int left_offset = left % bpw;
    int right_offset = (right - 1) % bpw;

    if (left_word == right_word) {
        bitword mask = ((1U << (right_offset - left_offset + 1)) - 1) << left_offset;
        return (arr[left_word] & mask) != 0;
    }

    bitword left_mask = ~0U << left_offset;
    if (arr[left_word] & left_mask) return 1;

    for (int i = left_word + 1; i < right_word; i++) {
        if (arr[i] != 0) return 1;
    }

    bitword right_mask = (1U << (right_offset + 1)) - 1;
    return (arr[right_word] & right_mask) != 0;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);

    bitword *arr=NULL;
    int arrlen=0;

    while (n--){
        int type;
        scanf("%d", &type);
        
        if (type==0){
            int num;
            scanf("%d",&num);
            arrlen = (num + bpw - 1) / bpw;
            arr = (bitword *)realloc(arr, arrlen * sizeof(bitword));
            bitsetZero(arr,num);
        }else if(type == 1){
            int idx;
            scanf("%d",&idx);
            
            printf("%d\n",bitsetGet(arr,idx));
        }else if(type == 2){
            int idx,newwal;
            scanf("%d %d",&idx,&newwal);
            bitsetSet(arr,idx,newwal);
        }else if(type == 3){
            int left, right;
            scanf("%d %d", &left, &right);
            if (bitsetAny(arr, left, right))
                printf("some\n");
            else
                printf("none\n");
        }

    }

    fclose(stdin);
    fclose(stdout);
}