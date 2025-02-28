#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push,1)
typedef struct {
    // int32_t N;
    int64_t A,B;
}BAN;


typedef struct {
    // char name[21];
    // int s;
    // int dir;
    // int c;
    // int m;
    // int show;

    char name[21];
    int64_t s;
    int8_t dir;
    int64_t c;
    int64_t m;
    int8_t show;
}file;
#pragma pack(pop)

int compare_files(const void *a, const void *b) {
    file *file1 = (file *)a;
    file *file2 = (file *)b;
    return strcmp(file1->name, file2->name);
}

file* filteringFiles(file *files, BAN *ban, int *filtered,int32_t N)
{
    // printf("%d\n",N);
    file *filteredFiles = (file*) malloc(N * sizeof(file));
    *filtered = 0;
    // printf("penis1\n");
    
    for (int i = 0; i < N; i++)
    {
        // printf("penis2\n");
        if (!files[i].dir&&!files[i].show&&files[i].c >= ban->A && files[i].m <= ban->B)
        {
            filteredFiles[*filtered] = files[i];
            (*filtered)++;
            // printf("penis3");
        }
    }
    return filteredFiles;
}

int main(){
    FILE *input = fopen("input.txt","rb");
    FILE *output = fopen("output.txt","wb");
    BAN ban;
    
    int32_t N;
    fread(&N,sizeof(int32_t),1,input);
    
    // printf("%d\n",N);
    fread(&ban,sizeof(BAN),1,input);


    file *files = (file *)malloc(N*sizeof(file));
    fread(files,sizeof(file),N,input);

    int filtered=0;

    file *ffiles = filteringFiles(files,&ban,&filtered,N);

    qsort(ffiles, filtered, sizeof(file), compare_files);

    fwrite(ffiles,filtered,sizeof(file),output);

    free(files);
    free(ffiles);
    fclose(input);
    fclose(output);
}