#include <bits/stdc++.h>
using namespace std;
void createtree(int a[],int seg[],int low,int high,int pos){
    if(low==high){
        seg[pos] = a[low];return;
    }
        int mid = (low+high)/2;                   //divides tree into two half (0,5) to (0,2) & (3,5)
        createtree(a,seg,low,mid,2*pos+1);      //left tree
        createtree(a,seg,mid+1,high,2*pos+2);   //right tree
        seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);    //minimum of left tree and right tree
    
    
}
int rangeminquery(int seg[],int lazy[],int low,int high ,int ql,int qh,int pos){ 
    if(low>high)return INT_MAX;
    if(lazy[pos]!=0){
        seg[pos]+=lazy[pos];
        if(low!=high){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
    if(low >= ql && high <=qh)return seg[pos];    //query range overlaps the range  
    if(high < ql || low>qh)return INT_MAX;       // do not overlap
    int mid = (low+high)/2;                        //mid splits
    return min(rangeminquery(seg,lazy,low,mid,ql,qh,2*pos+1) , rangeminquery(seg,lazy,mid+1,high,ql,qh,2*pos+2)); // min
    //of left and right subtree
}

void updatetree(int seg[],int lazy[],int ql,int qh,int low,int high,int pos,int val){
    if(low>high)return;
    if(lazy[pos]!=0){
        seg[pos]+=lazy[pos];
        if(low!=high){
            lazy[2*pos+1]+=lazy[pos];
            lazy[2*pos+2]+=lazy[pos];
        }
        lazy[pos]=0;
    }
     if(high < ql || low>qh)return ;
     if(low >= ql && high <=qh){
        seg[pos]+=val;
        if(low!=high){
            lazy[2*pos+1]+=val;
            lazy[2*pos+2]+=val;
        }
        return;
     }
     int mid  = (low+high)/2;
     updatetree(seg,lazy,ql,qh,low,mid,pos,val);
     updatetree(seg,lazy,ql,qh,mid+1,high,pos,val);
     seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);
}

int main() {
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int leafs=1;
    if( (n&(n-1))==0){               //power of two
        leafs=n;
    }else while(n >= leafs)leafs <<=1; //rounding off to next power of two
    cout<<leafs<<endl;
    int a[leafs];
    int num;
    for(int i=0;i<leafs;i++)a[i]=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>num;
        a[i]=num;
    }
    for(int i=0;i<leafs;i++)cout<<a[i]<<" ";
    cout<<endl;
    
    int x = leafs*2-1;
    int seg[x];
    int lazy[x];
    memset(lazy,0,sizeof(lazy));
    for(int i=0;i<x;i++)seg[i]=INT_MAX;
    createtree(a,seg,0,leafs-1,0);
    int q;
    cin>>q;              //queries 
    int ql,qh;
    while(q--){
         int type;
        cin>>type;
        cin>>ql>>qh;                 //query low and query high
        if(type==0){
        int minimum =rangeminquery(seg,lazy,0,leafs-1,ql,qh,0);
        cout<<minimum<<endl;}
        else{
            int val;
            cin>>val;
        updatetree(seg,lazy,ql,qh,0,leafs-1,0,val);
        }
    }
    }
    return 0;
}
