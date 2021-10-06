#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void){
    FILE *file;
    int a, b, c, x, y, i, j;
    char is = 'T';

    scanf("%d\n", &x);
    scanf("%d\n", &y);

    int **mas = (int**)malloc(y * sizeof(int*));
    for(i = 0; i < y; i++){
        mas[i] = (int*)malloc(x * sizeof(int));
    }

    file = fopen("DZ2.gv", "w");
    fputs("graph{\n", file);

    for(i = 0; i < y; i++){
        a = 0;

        for(j = 0; j < x; j++){
            mas[i][j] = getchar() - '0';
            a += mas[i][j];
        }

        if(a == 0){
            fprintf(file, "\t%d\n", i+1);

            if(is == 'T'){
               is = 'F';
            }
        }
        getchar();
    }

    printf("%c\n", is);
    for(i = 0; i < x; i++){
        b = 0, c = 0;
        fputc('\t', file);
        for(j = 0; j < y; j++){
            if(mas[j][i] == 1){
                if(b == 0){
                    b = j + 1;
                }
                else{
                    c = j + 1;
                    break;
                }
            }
        }
        if(b + c == b){
            fprintf(file, "%d--%d", b, b);
        }
        else{
            fprintf(file, "%d--%d", b, c);
        }
        fputc('\n', file);
    }
    fputc('}', file);
    fclose(file);
    system("dot -Tpng DZ2.gv -o DZ2_Picture.png");
    return 0;
}
