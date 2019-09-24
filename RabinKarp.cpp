//if pat = "AAAA" then treat it as special case
//for formula consider text = "2345" and converting 234 to 345
#include<iostream>
using namespace std;
int q = 101;
int main()
{  
    string text = "GEEKS FGEEKSORGEEKS GEEKS";
    string pat = "GEEKS";
    int ht = 0;
    int hp = 0;
    int d = 256;  //incase of string containing only integers its = 10
    int st = text.size();
    int sp = pat.size();
    int h = 1;
    for(int i=0;i<sp;i++)
    {
        ht = (ht*d + text[i])%q;                                     
        hp = (hp*d + pat[i])%q; 
    } 
    for(int i=0;i<sp-1;i++)
        h = (d*h)%q;
    for(int i=sp;i<=st;i++)
    {
        if(ht == hp)
        {
            int j; 
            for(j=0;j<sp;j++)
            {
                if(pat[j] != text[i-sp+j])              //pat[0] == text[3+0-2] if(i==1)
                { 
                    break;
                }
            }
            if(j==sp)
            {
                cout<<"pattern  found at index "<<(i-sp)<<endl;
            }
        }
        if(i<st)
        {
            ht = (d*(ht - text[i-sp]*h) + text[i])%q;
            ht = (ht+q)%q; 
        }
    }
	return 0;
}
