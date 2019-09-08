#include<bits/stdc++.h>
using namespace std;
string tostring(int coun){
    string tem ="";
    while(coun != 0){
         char ch = coun%10;
        tem += ch +'0';
        coun /= 10;
    }
    return tem;
}
string string_compression(string st){
    string ans ="";
    st +='#';
    int coun = 1;
    for(int i = 0 ; st[i] !='#' ; i++){
       if(st[i] != st[i+1]){
          ans +=st[i] + tostring(coun);
          coun = 1;
       }
       else{
          coun++;
       }
    }
    return ans;
}

int main(){
    int n;
    string st;
    scanf("%d",&n);
    getchar();
    for(int i = 0 ; i < n ; i++){
        getline(cin,st);
        cout<<string_compression(st)<<endl;
    }
    return 0;
}
