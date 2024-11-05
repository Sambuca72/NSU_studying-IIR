#include <stdio.h>
#include <stdlib.h>

typedef struct Node_s {
struct Node_s * prev , * next ;
void * value ;
} Node ;
//List –- вспомогательный узел, являющийся головой списка
typedef Node List ;

//инициализирует поля структуры *list значениями для пустого списка
void initList ( List * list );

//создаёт новый узел со значением ptr и вставляет его после узла node
//возвращает указатель на созданный узел
Node * addAfter ( Node * node , void * ptr );

//создаёт новый узел со значением ptr и вставляет его перед узлом node
//возвращает указатель на созданный узел
Node * addBefore ( Node * node , void * ptr );

//удаляет заданный узел, возвращая значение, которое в нём лежало
void * erase ( Node * node );

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);

    while (t--)
    {
        int q;
        scanf("%d",&q);
        for (int i =0;i<q;i++){
            int type,index;
            scanf("%d %d",&type,&index);
            if (type==-1){
                int value;
                scanf("%d",&value);
            }else if(type==0){

            }else if(type==1){
                int 
            }
        }
    }
    

    fclose(stdin);
    fclose(stdout);
}