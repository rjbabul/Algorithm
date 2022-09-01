#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

set <string > veriable;
set <string > keyword;
set<string > oparator;
set<string > integer;
set<string> special;
set< string > real_number;
set< string > un_var;


void demo_intput()
{
    cout<<"Demo input\n---x---\n\n#include <stdio.h> \n#define max 100000000\nint a , b =1000;\nfloat d = 222.3444;\nint c;\nc=a+b;\n";

    cout<<"\n\nHere don't consider header file and #define  just take variable and it's value from #define\n\n";
}


int valid =1;
/// some header file i just implements
char stdio[]="stdio.h";
char strig[]="string.h";
char algo[]="algorithm";
char math[]="math.h";
char stdlib[]="stdlib.h";
char conio[]="conio.h";
char ctyp[]="ctype.h";
char inc[]="include";
char defin[] ="define";

/// Include Header File

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

    if(strcmp(st,inc)!=0)
    {
        printf("Error!!!   include expected at %d line\n\n",n);
        valid =0;
        return ;
    }
    while(str[i]==' ')
    {
        i++;
    }
    if(str[i]!='<')
    {
        printf("Error Error!!!  ' < ' expected at %d line\n\n",n);
        valid =0;
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
    if((strcmp(st,stdio)!=0) &&  (strcmp(st,strig)!=0) && (strcmp(st,algo)!=0) && (strcmp(st,math)!=0) && (strcmp(st,stdio)!=0) && (strcmp(st,stdlib)!=0))
    {
        printf("Error!!!  valid header file expected at %d line\n\n",n);
        valid =0;
        return ;

    }
    while(str[i]==' ')
    {
        i++;
    }

    if(str[i]=='>')
    {

    }
    else
    {
        printf("Error!!!  ' > ' expected at %d line\n\n",n);
        valid =0;
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
        valid =0;
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
        valid =0;
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
            valid =0;
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
        valid =0;
        return ;
    }
    printf("\n\n\nvalue of %s = ",ss);
    veriable.insert(ss);
    printf("%s\n",nu);
    integer.insert(nu);
}

/// Check for keyword

int keyword_( string str)
{
    if (str == "if"  || str == "else" ||
            str == "while" ||  str == "do"  ||
            str == "break"  ||
            str == "continue" || str == "int"
            ||  str == "double" ||  (str == "float")
            ||  (str == "return") ||  (str == "char")
            ||  (str == "case") ||  (str == "char")
            ||  (str == "sizeof") ||  (str == "long")
            ||  (str == "short") ||  (str == "typedef")
            ||  (str == "switch") ||  (str == "unsigned")
            ||  (str == "void") ||  (str == "static")
            ||  (str == "struct") ||  (str == "goto"))
        return 1;
    return 0;
}

/// # missing check

bool isvalid(char str[] )
{
    int i=0;
    string st;
    st.clear();
    while(str[i]==' ')
        i++;
    for(int j=i; str[j]>='a' && str[j]<='z' ; j++)
        st+= str[j];

    if( st== "include" || st =="define")
        return 0;
    else
        return 1;
}

/// check Special Character

int special_char(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '=' ||
            ch == '/' || ch == ',' || ch == ';' || ch == '>' ||
            ch == '<' ||   ch == '(' || ch == ')' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return 1;
    return 0;
}

/// check integer number

int integer_( string str)
{
    int i, len = str.length();
    if (len == 0)
        return 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' || (str[i] == '-' && i > 0))
            return 0;
    }
    return 1;
}

/// check floating number

int real_number_(string str)
{
    int i, len = str.length();
    bool flag = 0;
    if (len == 0)
        return 0;
    for (i = 0; i < len; i++)
    {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
                && str[i] != '3' && str[i] != '4' && str[i] != '5'
                && str[i] != '6' && str[i] != '7' && str[i] != '8'
                && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0))
            return 0;
        if (str[i] == '.')
            flag = 1;
    }
    return flag;
}


/// check operator

int oparator_(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '>' || ch == '<' ||
            ch == '=')
        return 1;
    return 0;
}

/// check ' ; ' at last of a statement

int syntaxanalysis(string str)
{
    int i= str.length();
    i--;
    while(str[i]==' ')
        i--;
    if(str[i]==';')
        return 1;
    else
        return 0;
}

/// check variable

int var(string str)
{

    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
            str[0] == '3' || str[0] == '4' || str[0] == '5' ||
            str[0] == '6' || str[0] == '7' || str[0] == '8' ||
            str[0] == '9' || special_char(str[0]) == 1)
        return 0;
    return 1;
}

/// Execute all statement

void valid_stament( char str[], int n)
{
    if(!syntaxanalysis(str))
    {
        printf("syntax error in %d line \n",n);
        valid =0;
        return ;

    }
    stack <string> stck;
    string st;
    string sp;
    int i=0;
    while(str[i]==' ')
        i++;
    for( ; i<strlen(str); i++)
    {
        if(str[i]!=' ')
        {
            if(!special_char(str[i]))
                st+=str[i];
            else
            {
                sp+= str[i];
                stck.push(sp);
                stck.push(st);
                st.clear();
                sp.clear();
            }
        }
        else
        {
            stck.push(st);
            st.clear();
        }
    }
    if(str[strlen(str)-1]!=';')
        stck.push(st);
    string stt;
    string s= stck.top();

    while(!stck.empty())
    {
        stt= stck.top();

        if(stt.length()==1 && oparator_(stt[0]))
            oparator.insert(stck.top());

        else if(stt.length()==1 && special_char(stt[0]))
            special.insert(stck.top());

        else if( keyword_(stck.top()))
            keyword.insert(stck.top());

        else if(integer_(stck.top()))
            integer.insert(stck.top());

        else if(real_number_(stck.top()))
            real_number.insert(stck.top());

        else if(var(stck.top()))
            veriable.insert(stck.top());

        else
            un_var.insert(stck.top());

        stck.pop();
    }

}

int main()
{


    demo_intput();

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char str[100][1000];
    int i=0;
    vector< string > vt;
    printf("%d ",i+1) ;
    while(gets(str[i]))
    {
        i++;
        printf("%d ",i+1) ;
    }
    int j=0,k=0;
    string st;
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
            if(isvalid(str[j])==0)
            {
                printf("Error!!! ' # ' missing at %d line\n\n",j+1);
                valid =0;
                return 0;

            }
        }
        else
            k++;
        while(str[j][k]==' ')
        {
            k++;
        }

        for(int ii=k ; str[j][ii]>='a' && str[j][ii]<='z'; ii++)
            st+=str[j][ii];
        if(st=="include")
            inclu(str[j],j+1);

        else if(st=="define")
        {
            def(str[j],j+1);
        }
        else
        {
            valid_stament(str[j],j+1);
        }

        st.clear();
    }

    set< string > :: iterator it;

    if(un_var.size()>0)
    {
        cout<<"variable is not valid "<<endl;
    }
    else if(valid==1)
    {

        if(keyword.size()>0)
        {
            cout<<"\n\n\nkeyWord's : ";
            for(it = keyword.begin(); it!=keyword.end(); it++)
                cout<<*it<<"  ";
        }

        if(oparator.size()>0)
        {
            cout<<"\n\n\nOperator's : ";
            for(it=oparator.begin(); it!=oparator.end(); it++)
                cout<<*it<<"  ";
        }

        if(veriable.size()>0)
        {
            cout<<"\n\n\nVeriable's  : ";
            for(it=veriable.begin(); it!=veriable.end(); it++)
                cout<<*it<<"  " ;
        }

        if(integer.size()>0)
        {
            cout<<"\n\n\nInteger number's : ";
            for(it=integer.begin(); it!=integer.end(); it++)
                cout<<*it<<"  ";
        }

        if(real_number.size()>0)
        {
            cout<<"\n\n\nreal number's : ";
            for(it=real_number.begin(); it!=real_number.end(); it++)
                cout<<*it<<"  ";
        }

        if(special.size()>0)
        {
            cout<<"\n\n\nSpacial character's   : ";
            for(it=special.begin(); it!=special.end(); it++)
                cout<<*it<<"  ";
        }
        cout<<"\n\n";
        cout<<"CONGRATES !!! ........ No error founded"<<endl;
    }
    cout<<"\n\n";

    return 0;
}
