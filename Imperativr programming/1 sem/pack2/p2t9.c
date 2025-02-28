#include <stdio.h>
#include <stdlib.h>

int main(void){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char curr;
    int in_block_comment,in_line_comment,endb;
    in_block_comment=in_line_comment=endb=0;
    // flag = flag1 = flag3 = 0;
    while (1)
    {
        if ( scanf ("%c", & curr ) != 1)
            break ;
        
        //     endb=0;
        //     continue;
        // }
        if (in_block_comment) {
            if (curr == '*') {
                char next;
                scanf("%c",&next);
                if (next == '/') {
                    in_block_comment = 0;
                    endb=1;
                    // continue;
                } else {
                    printf("%c",next); 
                }
                continue; 
            }
            
            continue;
        }

        // Если мы находимся внутри строчного комментария
        if (in_line_comment) {
            char next;
            scanf("%c", &next);
            if (curr == '\n') {
                in_line_comment = 0;  
                printf("%c",curr);  
            }
            continue; 
        }

        // Обработка обычных символов
        if (curr == '/') {
            char next;
            if (scanf("%c", &next) == 1) {
                if (next == '*') {
                    in_block_comment = 1;//dsiuifa;lkjjfdlihaffapofpdiuiufaapouifdfopiuafduoifpi 
                    continue; 
                } else if (next == '/') {
                    in_line_comment = 1; 
                    continue; 
                } else { /*;kj;jhjf;jkaf;ljkla;lkjf*/
                    printf("%c",curr);
                    printf("%c",next);
                    continue;
                }
            }
        }
        /*;kj;jhjf;jkaf;ljkla;lkjf*/
        
        // if (endb==0){
        printf("%c",curr);//}
        // printf("%d",endb);
        
    }
    fclose(stdin);
    fclose(stdout);
    
}