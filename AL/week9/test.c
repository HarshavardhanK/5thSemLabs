
#include "hashing.h"

int main(int argc, char** argv) {

    int num = atoi(argv[1]);

    dict* _dict_ = init_dict(num);
    char str[10];

    for(int i = 0; i < num; i++) {
        printf("Str: ");
        scanf("%s", str);

        if(strcmp(str, "-1") == 0)
            break;

        store(str, _dict_);

    }

    print_table(_dict_);

    printf("Found key is: %d\n", get("what", _dict_));

    return 0;
}