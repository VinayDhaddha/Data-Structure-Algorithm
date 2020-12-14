#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the twoStacks function below.
 */

int twoStacks(int x, int n, int* a, int m, int* b) {
    int max=0,count=0,i=0,j=0,t=0,t1=0,flag=0;
    //printf("x=%d");
    while((i<n)&&(t<=x)){
        t1=t+a[i];
        if(t1>x){
            break;
        }
        else{
            t=t1;
            i++;
        }
    }
    //printf("yes\n");
    count=i;
    while((j<m)&&(t<=x)){
        t1=t+b[j];
        if(t1>x){
            break;
        }
        else{
            t=t1;
            j++;
        }
    }
    //printf("yes\n");
    count=count+j;
    max=count;
    if((i==n)&&((j==m)&&(t<=x)))
        return max;
    else{
        while(i>0){
            t=t-a[--i];
            count--;
            while((j<m)&&(t<=x)){
                t1=t+b[j];
                if(t1>x){
                    break;
                }
                else{
                    t=t1;
                    count++;
                    j++;
                }
            }
            if(count>max){
                max=count;
            }            
        }
    }
   // printf("\n yes2 max=%d\n",max);
    return max;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* g_endptr;
    char* g_str = readline();
    int g = strtol(g_str, &g_endptr, 10);

    if (g_endptr == g_str || *g_endptr != '\0') { exit(EXIT_FAILURE); }
	int g_itr=0;
    for (g_itr = 0; g_itr < g; g_itr++) {
        char** nmx = split_string(readline());

        char* n_endptr;
        char* n_str = nmx[0];
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char* m_endptr;
        char* m_str = nmx[1];
        int m = strtol(m_str, &m_endptr, 10);

        if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

        char* x_endptr;
        char* x_str = nmx[2];
        int x = strtol(x_str, &x_endptr, 10);

        if (x_endptr == x_str || *x_endptr != '\0') { exit(EXIT_FAILURE); }

        char** a_temp = split_string(readline());

        int a[n];
		int a_itr = 0;
        for (a_itr = 0; a_itr < n; a_itr++) {
            char* a_item_endptr;
            char* a_item_str = a_temp[a_itr];
            int a_item = strtol(a_item_str, &a_item_endptr, 10);

            if (a_item_endptr == a_item_str || *a_item_endptr != '\0') { exit(EXIT_FAILURE); }

            a[a_itr] = a_item;
        }

        char** b_temp = split_string(readline());

        int b[m];
		int b_itr = 0;
        for (b_itr = 0; b_itr < m; b_itr++) {
            char* b_item_endptr;
            char* b_item_str = b_temp[b_itr];
            int b_item = strtol(b_item_str, &b_item_endptr, 10);

            if (b_item_endptr == b_item_str || *b_item_endptr != '\0') { exit(EXIT_FAILURE); }

            b[b_itr] = b_item;
        }

        int result = twoStacks(x, n, a,m, b);

        fprintf(fptr, "%d\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

