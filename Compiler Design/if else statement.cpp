#include<bits/stdc++.h>
using namespace std;

stack < string > stck;
int sb1=0, sb2=0;
bool flag = true;

void solve(string str, int n)
{
    int i =0;
    while(str[i]==' ')
        i++;

    string st;

    for( ; str[i]>='a' && str[i]<='z'; i++)
        st+=str[i];
    if(st=="if")
    {
        stck.push(st);
        st.clear();
        while(str[i]==' ')
            i++;
        if(str[i]!='(')
        {
            cout<<"\n\n!Error! ( is missing at "<<n<<" line"<<endl;
            flag = false;
            return ;
        }
        i++;

        while(str[i]!=')' && i <= str.length())
            i++;

        if(i >= str.length())
        {
            cout<<"\n\nError!  ) is missing at "<<n<<" line"<<endl;
            flag = false;
            return ;
        }
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
                flag = false;
                return ;
            }
            sb1++;
            i++;
            while(str[i]!='}' && i<str.length())
                i++;
            if(i==str.length())
                return ;
            if(str[i]=='}')
                sb2++;
            i++;
            while(str[i]==' ' && i<str.length())
                i++;
            if(i==str.length())
                return ;
            if(str[i]==';')
            {
                cout<<"\n\n!Error syntax error is this statement at "<<n<<" line"<<endl;
                flag = false;
                return ;
            }
            if(i<str.length())
            {
                cout<<"\n\n! Syntax error in this statementat "<<n<<" line"<<endl;
                flag = false;
                return ;
            }
        }
    }
    else if(st=="else")
    {
        if(stck.top()!="if")
        {
            cout<<"\n\nError! else condition without if at "<<n<<" line"<<endl;
            flag = false;
            return ;
        }
        while(str[i]==' ' && i<str.length())
            i++;
        if(i==str.length())
            return ;
        if(str[i]=='{')
            sb1++;

        while(str[i]!='}' && i<=str.length())
            i++;
        if( i== str.length())
            return ;
        if(str[i]=='}')
            sb2++;

    }
    else
    {
        while(str[i]!='{' && str[i]!='}' && i<str.length())
            i++;
        if(str[i]=='{')
            sb1++;
        if(str[i]=='}')
            sb2++;
        i++;
        while(str[i]!='{' && str[i]!='}' && i<str.length())
            i++;
        if(str[i]=='{')
            sb1++;
        if(str[i]=='}')
            sb2++;
    }
    st.clear();
}
int main()
{

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
    else if( flag == true)
    {
        cout<<"\n\n0 Error and 0 warning "<<endl;
    }
    return 0;
}
