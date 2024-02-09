#include <iostream>
#include <vector>
using namespace std;

// template <class T>
void display(vector<int> &v){
    vector<int>::iterator iter;
    cout<<"Displaying Vector: ";
    for(iter=v.begin();iter!=v.end();iter++){
        cout<<*iter<<"  ";
    }
    cout<<"\n\n";
}

void display(vector<char> &v){
    vector<char>::iterator iter=v.begin();
    cout<<"Displaying Vector: ";
    for(iter=v.begin();iter!=v.end();iter++){
        cout<<*iter<<"  ";
    }
    cout<<"\n\n";
}

int main(){
    // Ways to create a vector
    vector<int> vec1; //Size of zero vector
    // for(int i=0;i<30;i++){
    //     vec1.push_back(i+1);
    // }
    // display(vec1);
    // cout<<endl<<endl;
    // vector<int> :: iterator iter =vec1.begin();
    // vec1.insert(iter+1,5,566);
    // display(vec1);

    vector<char> vec2(4);   //Size four vector char array
    vec2.push_back('5');
    display(vec2);

    vector<char> vec3(vec2);  //Created from vec2
    vec3.push_back('4');
    display(vec3);

    vector<int> vec4(6,10);
    display(vec4);
    return 0;
}