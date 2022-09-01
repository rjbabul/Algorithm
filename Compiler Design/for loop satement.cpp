#include<bits/stdc++.h>
using namespace std;
string st;
stack < string > stck;
string s="for(;;){}";
int sb1=0, sb2=0;
int flag = 0;
void h(){
    cout<<"Demo Input:\n\nfor( int i =0 ;i<=29;i++)\n{\n   printf(\"i\");\n}\n\n\n";

}
void solve(string str, int n)
{
    int i =0;
    while(str[i]==' ')
        i++;
    string ss;


    for( ; str[i]>='a' && str[i]<='z'; i++)
        ss+=str[i];
    if(ss=="for")
    {
        st+= ss;
        stck.push(st);

        while(str[i]==' ')
            i++;
        if(str[i]!='(')
        {
            cout<<"\n\n!Error! ( is missing at "<<n<<" line"<<endl;
            flag++;
            return ;
        }
        st+='(';
        i++;

        while(str[i]!=';' && i <= str.length())
            i++;

        if(i >= str.length())
        {
            cout<<"\n\nError!  ; is missing at "<<n<<" line"<<endl;
            flag++;
            return ;
        }
        st+=';';
        i++;
        while(str[i]!=';' && i <= str.length())
            i++;

        if(i >= str.length())
        {
            cout<<"\n\nError!  ; is missing at "<<n<<" line"<<endl;
            flag++;
            return ;
        }
        st+=';';
        i++;
        while(str[i]!=')' && i <= str.length())
            i++;

        if(i >= str.length())
        {
            cout<<"\n\nError!  ) is missing at "<<n<<" line"<<endl;
            flag++;
            return ;
        }
        st+=')';
        i++;
        while(str[i]==' ' && i<=str.length())
            i++;
        if(i>= str.length())
        {

            return ;
        }
        else
        {

            if(str[i]!='{')
            {
                cout<<"!Error { is missing at "<<n<<" line"<<endl;
                flag++;
                return ;
            }
            sb1++;
            st+='{';
            i++;
            while(str[i]!='}' && i<str.length())
                i++;
            if(i==str.length())
                return ;
            if(str[i]=='}')
            {
                sb2++;
                st+='}';
            }
            i++;
            while(str[i]==' ' && i<str.length())
                i++;
            if(i==str.length())
                return ;
            if(str[i]==';')
            {
                cout<<"\n\n!Error syntax error is this statement at "<<n<<" line"<<endl;
                flag++;
                return ;
            }
            if(i<str.length())
            {
                cout<<"\n\n! Syntax error in this statementat "<<n<<" line"<<endl;
                flag++;
                return ;
            }
        }
    }

    else
    {
        while(str[i]!='{' && str[i]!='}' && i<str.length())
            i++;
        if(str[i]=='{')
        {
            st+='{';
            sb1++;
        }
        if(str[i]=='}')
        {
            sb2++;
            st+='}';
        }
        i++;
        while(str[i]!='{' && str[i]!='}' && i<str.length())
            i++;
        if(str[i]=='{')
        {
            sb1++;
            st+='{';
        }
        if(str[i]=='}')
        {
            sb2++;
            st+='}';
        }
    }


}
int main()
{

    h();
    char str[100][1000];
    stck.push("0");
    int i=0;
    vector< string > vt;
    printf("%d ",i+1) ;
    while(gets(str[i]))
    {
        i++;
        printf("%d ",i+1) ;
    }

    for(int j =0; j<i; j++)
    {
        solve(str[j],j+1);
    }

    if(sb1!= sb2)
    {
        cout<<"\n\nError { or } missing"<<endl;
        return 0;
    }
    else if( st==s)
    {
        cout<<"\n\nLoop Statement Ok!"<<endl;
    }
    else if( st!=s && flag == 0)
    {
        cout<<"\n\n Syntax Error"<<endl;
    }
    return 0;
}

