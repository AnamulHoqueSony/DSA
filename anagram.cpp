#include <bits/stdc++.h>
#define MAX 30
using namespace std;

void set_value(int latter_dif[]){
     for(int i = 0 ; i < MAX ; i++)
     latter_dif[i] = 0;
}
int anagram(string s) {
   int ans = 0;
   int latter_dif[MAX];
   set_value(latter_dif);
   int div = s.size()/2;

   if(s.size() % 2)
      return (-1);

    for(int i = 0 ; i < div ; i++){
         latter_dif[s[i] -'a']++;
    }
    for(int i = div; i < s.size() ; i++){
        if(latter_dif[s[i]-'a'] > 0)
            latter_dif[s[i]-'a']--;
    }
    for(int i = 0 ; i < MAX ; i++){

        ans +=latter_dif[i];
    }
    return ans;


}

int main()
{
    int n;
    string st;
    scanf("%d",&n);
    getchar();
    while(n--){
       getline(cin,st);
       printf("%d\n",anagram(st));
    }

    return 0;
}

