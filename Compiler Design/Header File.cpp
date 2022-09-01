#include<bits/stdc++.h>
using namespace std;
bool flag = true;
char inc[]="include";
char defin[] ="define";

map < string, int > mp;

void h()
{   cout<<"Demo Input : \n\n#include<stdio.h>\n#include<MATH.H>\n#include<STRING.H>\n\n"<<endl;
    mp["stdio.h"] = 1 ;
    mp["STDIO.H"]=1;
    mp["string.h"]= 1;
    mp["STRING.H"]=1;
    mp["math.h"]=1;
    mp["MATH.H"]=1;
    mp["stdlib.h"]=1;
    mp["STDLIB.H"]=1;
    mp["conio.h"]=1;
    mp["CONIO.H"]=1;
    mp["ctype.h"]=1;
    mp["CTYPE.H"]=1;
    mp["assert.h"]=1;
    mp["ASSERT.H"]=1;
    mp["cocale.h"]=1;
    mp["COCALE.H"]=1;
    mp["setjmp.h"]=1;
    mp["SETJMP.H"]=1;
    mp["signal.h"]=1;
    mp["SIGNAL.H"]=1;
    mp["stdarg.h"]=1;
    mp["STDARG.H"]=1;
    mp["time.h"]=1;
    mp["TIME.H"]=1;
    mp["complex.h"]=1;
    mp["COMPLEX.H"]=1;
    mp["stdalign.h"]=1;
    mp["STDALIGN.H"]=1;
    mp["errno.h"]=1;
    mp["ERRNO.H"]=1;
    mp["locale.h"]=1;
    mp["LOCALE.H"]=1;
    mp["stdatomic.h"]=1;
    mp["STDATOMIC.H"]=1;
    mp["stdnoreturn.h"]=1;
    mp["STDNORETURN.H"]=1;
    mp["uchar.h"]=1;
    mp["UCHAR.H"]=1;
    mp["fenv.h"]=1;
    mp["FENV.H"]=1;
    mp["wchar.h"]=1;
    mp["WCHAR.H"]=1;
    mp["tgmath.h"]=1;
    mp["TGMATH.H"]=1;
    mp["stdarg.h"]=1;
    mp["STDARG.H"]=1;
    mp["stdbool.h"]=1;
    mp["STDBOOL.H"]=1;

}

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
    string st;
    st.clear();
    for(j=0; j<7; j++)
    {
        st+=str[i++];
    }

/// printf("%s", st);
    if( st!=inc )
    {
        printf("Error!!!   include expected at %d line\n\n",n);
        flag = false;
        return ;
    }
    st.clear();
    while(str[i]==' ')
    {
        i++;
    }
    if(str[i]!='<')
    {
        printf("Error Error!!!  ' < ' expected at %d line\n\n",n);
        flag = false;
        return ;
    }
    i++;
    while(str[i]==' ')
    {
        i++;
    }
    int c=0;
    for(int j=0; ; j++)
    {
        if(str[i]=='.')
            c++;
        if(str[i]==' ' || str[i]=='>' || c>=2 ||  i==strlen(str))
            break;
        st+=str[i++];
    }

    if(mp[st]==0)
    {
        printf("Error!!!  valid header file expected at %d line\n\n",n);
        flag = false;
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
        printf("Error!!!  ' > ' expected at %d line\n\n",n);
        flag = false;
        return ;
    }
    i++;
    while(str[i]==' ')
    {
        i++;
    }
    if(str[i]==';')
    {
        printf("syntax error  in %d line\n\n",n);
        flag = false;
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
        printf("syntax error in %d line \n",n);
        flag = false;
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
            printf("there is not define number in %d line \n",n);
            flag = false;
            return ;
        }
    }
    while(str[i]==' ')
    {
        i++;
    }
    if( str[i]==';')
    {
        printf("Syntax error at %d line \n",n);
        flag = false;
        return ;
    }
    /// printf("value of %s = ",ss);
    ///printf("%s\n",nu);
}
int main()
{
    h();
    char str[100][1000];
    int i=0;
    printf("%d ",i+1) ;
    while(gets(str[i]))
    {
        i++;
        printf("%d ",i+1) ;
    }
    int j=0,k=0;
    for(j=0; j<i; j++)
    {
        int k=0;
        if(str[j][0]=='\0' || str[j][0]=='\n')
            continue;
        while(str[j][k]==' ')
        {
            k++;
        }
        if(str[j][k]!='#')
        {
            printf("Error!!! ' # ' missing at %d line\n\n",j+1);
            flag = false;
            return 0;
        }
        k++;
        while(str[j][k]==' ')
        {
            k++;
        }
        if(str[j][k]=='i')
        {
            inclu(str[j],j+1);
        }
        else if(str[j][k]=='d')
        {
            def(str[j],j+1);
        }
        else
        {
            printf("Error!!! wrong syntax at %d line\n",j+1);
            flag = false;
            return 0;
        }
    }
    if(flag ==true)
        cout<<"0 error 0 waring"<<endl;
    return 0;
}
