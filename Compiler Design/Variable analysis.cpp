
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
set<string > data_type;

vector< pair< string, int > > ans;
void demo_intput()
{

    cout<<"Demo input\n---x---\n\nint a , b =1000;\nfloat d = 222.3444;\nint c;\n\n";
    cout<<"Checking For \n\tVariable Redeclaration, \n\tsyntax Error, \n\tvalid variable\n\n-----------x----------"<<endl<<endl;


}


int valid =1;
map<string, int > var_dec;
char stdio[]="stdio.h";
char strig[]="string.h";
char algo[]="algorithm";
char math[]="math.h";
char stdlib[]="stdlib.h";
char conio[]="conio.h";
char ctyp[]="ctype.h";
char inc[]="include";
char defin[] ="define";

/// data type checking

int data_type_( string str)
{
    if ( str == "int" ||  str == "double" ||  (str == "float") ||  (str == "char") ||   str == "char")
        return 1;
    return 0;
}
/// Check for keyword

int keyword_( string str)
{
    if (str == "if"  || str == "else" ||
            str == "while" ||  str == "do"  ||
            str == "break"  ||
            str == "continue"
            ||  (str == "return")
            ||  (str == "case")
            ||  (str == "sizeof") ||  (str == "long")
            ||  (str == "short") ||  (str == "typedef")
            ||  (str == "switch") ||  (str == "unsigned")
            ||  (str == "void") ||  (str == "static")
            ||  (str == "struct") ||  (str == "goto"))
        return 1;
    return 0;
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

    while(!stck.empty())
    {
        stt= stck.top();

        if(stt.length()==1 && oparator_(stt[0]))
            oparator.insert(stck.top());

        else if(stt.length()==1 && special_char(stt[0]))
            special.insert(stck.top());


        else if( data_type_(stck.top()))
            data_type.insert(stck.top());

        else if( keyword_(stck.top()))
            keyword.insert(stck.top());

        else if(integer_(stck.top()))
            integer.insert(stck.top());

        else if(real_number_(stck.top()))
            real_number.insert(stck.top());

        else if(var(stck.top()))
        {
            veriable.insert(stck.top());
            var_dec[stck.top()]++;
        }
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
        for(int ii=k ; str[j][ii]>='a' && str[j][ii]<='z'; ii++)
            st+=str[j][ii];

        valid_stament(str[j],j+1);
        st.clear();
    }

    set< string > :: iterator it;

    if(un_var.size()>0)
    {
        cout<<"variable is not valid "<<endl;

    }
    else if(valid==1)
    {
        if(veriable.size()>0)
        {

            int i = 0,fl=0;
            for(it=veriable.begin(); it!=veriable.end(); it++)
            {
                i++;
                if(i>1 && var_dec[*it]>1)
                    fl++;
            }
            if(fl==0)
            {
                cout<<"\n\n\nVeriable's  : ";
                for(it=veriable.begin(); it!=veriable.end(); it++)
                    cout<<*it<<"  " ;
            }
            else
            {
                cout<<"Error! Variable redeclaration "<<endl;
                return 0;
            }
        }
        if(keyword.size()>0)
        {
            cout<<"\n\n\nkeyWord's : ";
            for(it = keyword.begin(); it!=keyword.end(); it++)
                cout<<*it<<"  ";

        }
        if(data_type.size()>0)
        {
            cout<<"\n\ndatatype's  : ";
            for(it=data_type.begin(); it!=data_type.end(); it++)
                cout<<*it<<"  " ;
        }
    }
    cout<<"\n\n";

    return 0;
}
