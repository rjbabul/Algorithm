#include<bits/stdc++.h>
using namespace std;
typedef vector< int > vec;

vec lps_create(string pattern)
{

    int  index=0;
    vec lps(pattern.length());
    for(int i= 1; i<pattern.length(); )
    {

        if(pattern[index]== pattern[i])
        {
            lps[i]= index+1;
            index++;
            i++;
        }
        else
        {
            if(index!=0)
                index= lps[index-1];
            else
                lps[i]= index, i++;
        }

    }


    return lps;

}
void kmp(string text, string pattern)
{
    bool found = false;
    vec lps = lps_create(pattern);
    int index=0;

    for(int i=0; i< text.length(); )
    {
        if(text[i]== pattern[index])
            index++,i++;
        else
        {
            if(index==0)
                i++;
            else
                index= lps[index-1];
        }
        if(index==pattern.length())
        {
            cout<<"found"<<endl;
            found= true;
        }
    }
    if(!found)
        cout<<"Not Found"<<endl;
}
int main()
{
    string text, pattern;

    getline(cin, text);
    getline(cin,pattern);
    kmp(text, pattern);

    return 0;
}
