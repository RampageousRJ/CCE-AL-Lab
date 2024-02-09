#include <iostream>
#include <list>
using namespace std;
template <class T>
void display(list<T> &l){
    list<int>::iterator iter;
    for(iter=l.begin();iter!=l.end();iter++){
        cout<<*iter<<" -> ";
    }
    cout<<endl<<endl;
}

int main(){
    list<int> list1;      //Empty list of size 0
    list1.push_back(5);
    list1.push_back(4);
    list1.push_back(6);
    list1.push_back(3);
    list1.push_back(1);
    list1.push_back(8);
    // list1.remove(3);   //Removes elements and duplicates
    list1.sort();         //Sorting the list
    display(list1);

    list<int> list2(3);   //Empty list of size 3 default values 0
    list<int>::iterator iter=list2.begin();
    // *iter=9; iter++;
    // *iter=5; iter++;
    // *iter=2; iter++;
    list2.pop_back();
    list2.pop_back();
    list2.pop_back();
    list2.push_front(9);
    list2.push_front(5);
    list2.push_front(2);
    display(list2);

    cout<<endl<<"Merge List1 and List2:\n";
    list1.merge(list2);
    list1.sort();
    display(list1);

    cout<<"Reversing list:\n";
    list1.reverse();
    display(list1);

    return 0;
}