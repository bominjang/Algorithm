#include <stdio.h>
#include <stdlib.h>

int substr(char s[], char t[])
{
    int i=0;
    int j=0;
    for(i;s[i]!=0;i++)
    {
        for(j;t[j]!=0;j++)
        {
            //printf("%c %c\n", s[i], t[j]);
            if(s[i]!=t[j])
            {
                j=0;
                break;
            }
            else if(s[i]==t[j])
            {
                if(t[j+1]!=0&&s[i+1]!=t[j+1])
                {
                    j=0;
                    break;
                }
                i++;
            }
        }
        if(t[j]==0) break;
    }
    if(s[i]==0 && j==0) return -1;
    return i-j;
}

void main() {
    printf("%d\n", substr("maximum","ax"));
    printf("%d\n", substr("over the rainbow","rain"));
    printf("%d\n", substr("over the rainbow","r t"));
    printf("%d\n", substr("bacacarcary","car"));
    printf("%d\n", substr("bacacarcary","cam"));
}
