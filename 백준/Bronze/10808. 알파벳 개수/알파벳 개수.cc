#include <stdio.h>
#include <string.h>

int main(){
    char S[100] = {};
    int arr[26] = {};
    int i;
    scanf("%s", S);
    for(i = 0; i < strlen(S); i++){
        int num = S[i] - 'a';
        arr[num]++;
    }
    for(i = 0; i < 26; i++){
        printf("%d ",arr[i]);
    }
}