#include<bits/stdc++.h>
using namespace std;
typedef vector<int> ll;

ll create_lps(string pattern){
  int index =0;
  ll lps(pattern.length());

  for(int i=1;i< pattern.length(); ){

    if(pattern[i]== pattern[index]){
        lps[i++] = ++index ;

    }
    else{
        if(index) index= lps[index-1];
        else lps[i++]= index;
    }
  }
  for(int i=0;i<pattern.length();i++)
  {
      cout<<i<<" ";
  }cout<<endl;

    for(int i=0;i<pattern.length();i++)
  {
      cout<<pattern[i]<<" ";
  }cout<<endl;

    for(int i=0;i<pattern.length();i++)
  {
      cout<<lps[i]<<" ";
  }cout<<endl;
  return lps;
}

void kmp(string text, string pattern){
   ll lps= create_lps(pattern);
  bool found = false;
   /// i--> text , j-->pattern

   int i=0,j=0;
   while(i<text.length()){
    if(text[i]== pattern[j]){
        i++;
        j++;
    }
    else{
        if(j!=0) j= lps[j-1];
        else i++;
    }
    if(j==pattern.length()){
        cout<<"found"<<endl;
        found= true;
    }
   }
   if(found == false) cout<<"Not found"<<endl;

 }
int main()
{
    string text, pattern;
    cin>>text>> pattern;
    kmp(text, pattern);

    return 0;
}
