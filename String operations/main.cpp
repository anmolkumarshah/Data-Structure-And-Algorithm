#include<stdio.h>
#include<stdlib.h>

int len(char *str){
    int count = 0;
    int i = 0;
    while(str[i] != '\0'){
        count++;
        i++;
    }
    return count;
}

void Upper(char *str){
    for(int i=0;str[i]!='\0';i++){
        str[i] -= 32;
    }
}

void Lower(char *str){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='A'&& str[i]<='Z'){
         str[i] += 32;
        }
    }
}

void Toggle(char str[]){
    for(int i=0;str[i]!='\0';i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i]+=32;
        }
        else if(str[i]>='a' && str[i]<='z'){
            str[i]-=32;
        }
    }
}

int count_words(char *str){
    int words = 0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i] == ' ' && str[i-1] != ' '){
            words++;
        }
    }
    return words+1;
}

void check_vowel_conso(char str[]){
    int v_count = 0, c_count = 0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
        str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ){
            v_count++;
        }
        else if( (str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z') ){
            c_count++;
        }
    }
    printf("\nVowels - %d  & consonents - %d \n",v_count,c_count);
}

int validate(char *str){
    for(int i=0;str[i]!='\0';i++){
        if( !(str[i]>=65 && str[i]<=90)
           && !(str[i]>='a' && str[i]<='z')
           && !(str[i]>=48 && str[i]<=57) ){
            return 0;
           }
    }
    return 1;
}

void Swap(char *a,char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void Reverse(char *str){
    int j;
    for(j=0;str[j]!='\0';j++){}
    j-=1;
    for(int i=0;i<j;i++,j--){
        Swap(&str[i],&str[j]);
    }
}

int isPalindrome(char *str){
    int i,j;
    for(j=0;str[j]!='\0';j++){}
    j-=1;
    for(i=0;i<=j;i++,j--){
        if(str[i]!=str[j]){
            return 0;
        }
    }
    return 1;
}

void Repeating(char *str){
    Lower(str);
    //**************
    int *b = (int *)malloc(26*sizeof(int));
    for(int i=0;i<26;i++){
        b[i] = 0;
    }
    //**************
    for(int i=0;str[i]!='\0';i++){
        b[str[i]-97]++;
    }
    for(int i=0;i<26;i++){
        if(b[i]>1){
            printf("%c is repeating %d times\n",i+97,b[i]);
        }
    }
    free(b);
    b = NULL;
}

int Anagram(char *a,char *b){
     //Lower(a);
     //Lower(b);
    //**************
    int *h = (int *)malloc(26*sizeof(int));
    for(int i=0;i<26;i++){
        h[i] = 0;
    }
    //**************
    for(int i=0;a[i]!='\0';i++){
        h[a[i]-97]++;
    }
    for(int i=0;b[i]!='\0';i++){
        h[b[i]-97]--;
    }
    for(int i=0;i<26;i++){
        if(h[i]<0){
            free(h);
            h = NULL;
            return 0;
        }
    }
    free(h);
    h = NULL;
    return 1;
}


int main(){
    char a[] = "decimal";
    char b[] = "medical";
    if(Anagram(a,b)){
        printf("Are Anagram");
    }else{
        printf("Are not Anagram");
    }

return 0;
}
