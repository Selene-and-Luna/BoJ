#include <stdio.h>
#include <string.h>
int main()
{
    char c[1000001];
    int k = 1;
    scanf("%[^\n]s",c);
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] == ' ' && i!=0 && c[i+1]!='\0')   k++;
    }
  if(strlen(c)==1 && c[0]==' ')  printf("0");
  else  printf("%d", k);
}
