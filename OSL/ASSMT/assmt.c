#include <fcntl.h>
#include <string.h>
#include <stdio.h>

#include <unistd.h>
#include <sys/types.h>

int is_vowel(char ch) {

    char vowel_l[] = {'a', 'e', 'i', 'o', 'u'};
    char vowel_u[] = {'A', 'E', 'I', 'O', 'U'};

    for(int i = 0; i < 5; i++) {
         if(ch == vowel_l[i] || ch == vowel_u[i])
            return 1;
    }

    return 0;
}

int main() {

    FILE* fp;
    fp = fopen("input.txt", "r");

    FILE* fp2 = fopen("output.txt", "w+");

    char ch = fgetc(fp);

    while(ch != EOF) {
        if(is_vowel(ch))
            fputc(ch, fp2);
        
        ch = fgetc(fp);
    }

    fclose(fp); fclose(fp2);

    return 0;
}