#include <stdio.h>
#include <string.h>
#include <unistd.h>


int stlen(char *a) {
    return strlen(a);
}

int bb(char a) {
    if (a == 'a') {
        return 1;
    } else {
        if (a == 'A') {
            return 0;
        }
        return 11;
    }
}
int cmp_proc_fn(char* buf,int len){
    if(len <= 6)
        exit(0);

    if(buf[0] == 'A' || buf[0] =='B'||buf[0] =='C'){
        printf("hello ,you are in door 1\n");
        if(buf[1] == 'A' || buf[1] =='B'||buf[1] =='C'){
            printf("hello ,you are in door 2\n");
            if(buf[4] == 'A' || buf[4] =='B'||buf[4] =='C')
                printf("hello ,you are in door 3\n");
        }
    }
    printf("success\n");
}

int proc_fn(char *buf, int len) {
    char local_buf[32];


    printf("%s(%d)\n", buf, len);

    if (stlen(buf) == 23001) return 2;

    if (stlen(buf) == 4 && buf[3] == 'X') return 1;

    if (buf[3] == 'X') {
        printf("\n");
        return 1;
    }


    if (stlen(buf) > 0 && buf[0] == 'A' && buf[1] == 'b') {
        memcpy(local_buf, buf, stlen(buf));
    }

    bb('u');

    return 1;
}

int main(int argc, char** argv) {
    if (argc > 1) 
    {
        FILE* fp = fopen(argv[1],"rb");
        fseek(fp, 0, SEEK_END);
        int file_size = ftell(fp);
        rewind(fp);

        unsigned char* buffer = (unsigned char*) malloc((file_size + 1) * sizeof(char));
        fread(buffer, file_size, 1, fp);
        // 关闭文件
        fclose(fp);
        cmp_proc_fn(buffer, file_size);

    }
    printf("successfully exec\n");
    // keep the program running for debugging purposes
    // while(1) {
    //     sleep(5);
    // }
}