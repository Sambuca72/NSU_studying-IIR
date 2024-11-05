#include <stdio.h>
#include <string.h>

typedef struct Label_s{
    char name[16];
    int age;
}Label;

typedef struct NameStats_s {
    int cntTotal;
    int cntLong;
}NameStats;

typedef struct AgeStats_s{
    int cntTotal;
    int cntAdults;
    int cntKids;
}AgeStats;

void calcState(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges){
    for (int i =0;i<cnt;i++){
        if(strlen(arr[i].name)>10){
            oNames->cntLong++;
        }
        oNames->cntTotal++;
        oAges->cntTotal++;
        if(arr[i].age>=18){
            oAges->cntAdults++;
        }
        else if(arr[i].age<14){
            oAges->cntKids++;
        }
    }
    printf("names: total = %d\n",oNames->cntTotal);
    printf("names: long = %d\n",oNames->cntLong);
    printf("ages: total = %d\n",oAges->cntTotal);
    printf("ages: adult = %d\n",oAges->cntAdults);
    printf("ages: kid = %d",oAges->cntKids);
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    scanf("%d",&n);
    NameStats names;
    AgeStats ages;
    Label person[n];

    for (int i=0;i<n;i++){
        scanf("%s %d let",&person[i].name,&person[i].age);
        // printf("%s %d\n",person[i].name,person[i].age);
    }    
    calcState(person,n,&names,&ages);


    fclose(stdin);
    fclose(stdout);
}