#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef int (*comp_t) (const char*, const char*);


void qsort_char_arr(const char** arr, int n, comp_t comparator, int l, int r) {
    if (r <= l) return;
    int pivot = l, i = l + 1, j = r;
    while (i <= j) {
        for (;i != r; ++i) {
            if (comparator(arr[i], arr[pivot])) {
                break;
            }
        }
        for (;j != l; --j) {
            if (!(comparator(arr[j], arr[pivot]))) {
                break;
            }
        }
        if (i >= j) {
            break;
        }
        const char* temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    if (j != pivot) {
        const char* temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;   
    }
    qsort_char_arr(arr, n, comparator, l, j - 1);
    qsort_char_arr(arr, n, comparator, j + 1, r);
}


int len_cmp(const char* s1, const char* s2) {
    return strlen(s1) > strlen(s2);
}

int lexicographical(const char* s1, const char* s2) {
    return strcmp(s1, s2) > 0;
}


int vowel_count(const char* s) {
    int n = 0;
    for (; *s != '\0'; ++s) {
        if (strchr("aioue", tolower(*s)))
            ++n;
    }
    return n;
}
int vowel_count_cmp(const char* s1, const char* s2) {
    return vowel_count(s1) > vowel_count(s2);
}


typedef enum {
    alphabet=1, len, vowels
} Sort;


int main() {
    int n;
    scanf("%d", &n);
    char** arr = malloc(sizeof(const char*) * n);
    for (int i = 0; i < n; ++i) {
        arr[i] = malloc(sizeof(char) * 255);
        scanf("%s", arr[i]);
    }
    printf("Choose comporator:\n1 - alphabet\n2 - len of str\n3 - vowel count: ");
    Sort choise;
    scanf("%d", &choise);
    comp_t comp = NULL;
    switch (choise) {
        case alphabet:
            comp = lexicographical;
            break;
        case len:
            comp = len_cmp;
            break;
        case vowels:
            comp = vowel_count_cmp;
            break;
        default:
            return -1;
    }
    qsort_char_arr(arr, n, comp, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("String: %s\n", arr[i]);
        free(arr[i]);
    }
    free(arr);
}