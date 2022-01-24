#include <bits/stdc++.h>
using namespace std;

//C++ List is a Doubly linked list.

int main(){
    list <int> l;
    list <int> l1{1,2,9,5,20,10};
    for(auto x:l1){
        cout<<x<<" ";
    }
    cout<<endl;
    //sort
    l1.sort();
    for(auto x:l1){
        cout<<x<<" ";
    }
    cout<<endl;
    l1.pop_front();
    l1.pop_back();
    l1.push_front(6);
    l1.push_back(29);
    for(auto it=l1.begin();it!=l1.end();it++){
        cout<<*it<<" ";
    }
    l1.remove(5); //Removes the element with value=5. It will remove all occ.
    return 0;
}