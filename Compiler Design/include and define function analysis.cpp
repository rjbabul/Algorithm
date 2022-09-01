#include<stdio.h>
#include<string.h>
using namespace std;

bool flag = false ;

char stdio[]="stdio.h";
char string[]="string.h";
char strs[]="STRING.H";
char algo[]="algorithm";
char math[]="math.h";
char stdlib[]="stdlib.h";
char conio[]="conio.h";
char ctype[]="ctype.h";
char inc[]="include";
char defin[] ="define";

void inclu(char str[],int n)
{
    int i=0,j;
    while(str[i]==' ')
    {
        i++;
    }
    i++;
    while(str[i]==' ')
    {
        i++;
    }
    char st[10];
    for(j=0; j<7; j++)
    {
        st[j]=str[i++];
    }
    st[j]='\0';
/// printf("%s", st);
    if(strcmp(st,inc)!=0)
    {
        printf("Error!!! \n");
        flag = true;
        return ;
    }
    while(str[i]==' ')
    {
        i++;
    }
    if(str[i]!='<')
    {
        printf("Error!!! \n");
        flag = true;
        return ;
    }
    i++;
    while(str[i]==' ')
    {
        i++;
    }
    int c=0;
    for(j=0; ; j++)
    {
        if(str[i]=='.')
            c++;
        if(str[i]==' ' || str[i]=='>' || c>=2)
            break;
        st[j]=str[i++];
    }
    st[j]='\0';
    if((strcmp(st,stdio)!=0) && (strcmp(st,strs)!=0) && (strcmp(st,string)!=0) && (strcmp(st,algo)!=0) && (strcmp(st,math)!=0) && (strcmp(st,stdio)!=0) && (strcmp(st,stdlib)!=0))
    {
        printf("Error!!! \n");
        flag = true;
        return ;
    }
    while(str[i]==' ')
    {
        i++;
    }
    /// printf("%c\n", str[i]);
    if(str[i]=='>')
    {
        //printf("success");
    }
    else
    {
        printf("Error!!! \n");
        flag = true;
        return ;
    }
    i++;
    while(str[i]==' ')
    {
        i++;
    }
    if(str[i]==';')
    {
        printf("Error!!! \n");
        flag = true;
        return ;
    }
}
/// #define function
char ss[1000];
void def(char str[],int n)
{
    int i=0,j=0;
    while(str[i]==' ')
    {
        i++;
    }
    i++;
    while(str[i]==' ')
    {
        i++;
    }
    char st[100];
    for(j=0; j<6; j++)
    {
        st[j]=str[i++];
    }
    st[j]='\0';
    if(strcmp(st,defin)!=0)
    {
        printf("Error!!! \n");
        flag = true;
        return ;
    }
    while(str[i]==' ')
    {
        i++;
    }
    int ln = strlen(str);
    for(j=0; str[i]!=' ' ; j++)
    {
        ss[j]=str[i++];
    }
    ss[j]='\0';
    while(str[i]==' ')
    {
        i++;
    }
    int jj=0;
    int num=0;
    char nu[100];
    for(jj=0; str[i]!=' ' && str[i]!=';' && str[i]!='\0'; jj++)
    {
        nu[jj]=str[i++];
    }
    nu[jj]='\0';
    for(jj=0; nu[jj]!='\0'; jj++)
    {
        if(nu[jj]>='0' &&  nu[jj]<='9') {}
        else
        {
            printf("Error!!! \n");
            flag = true;
            return ;
        }
    }
    while(str[i]==' ')
    {
        i++;
    }
    if( str[i]==';')
    {
        printf("Error!!! \n");
        flag = true;
        return ;
    }

}
int main()
{
    char str [1000];
    int i=1;

      gets(str );

    int j=0,k=0;
    for(j=0; j<i; j++)
    {
        int k=0;
        if(str [0]=='\0' || str [0]=='\n')
            continue;
        while(str [k]==' ')
        {
            k++;
        }
        if(str [k]!='#')
        {
            printf("Error!!! \n");
            flag = true;
            return 0;
        }
        k++;
        while(str [k]==' ')
        {
            k++;
        }
        if(str [k]=='i')
        {
            inclu(str ,j+1);
        }
        else if(str [k]=='d')
        {
            def(str ,j+1);
        }
        else
        {
            printf("Error!!! \n");
            flag = true;
            return 0;
        }
    }
    if( flag == false) puts("Success !! ... valid header file.");
    return 0;
}
