#include <iostream>
#define MAX 100
using namespace std;

class Matrix{
    public:
    int arr[MAX][MAX];
    Matrix(){}
};

Matrix add(Matrix a,Matrix b,int n){
    Matrix c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c.arr[i][j]=a.arr[i][j]+b.arr[i][j];
        }
    }
    return c;
}

Matrix subtract(Matrix a,Matrix b,int n){
    Matrix c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c.arr[i][j]=a.arr[i][j]-b.arr[i][j];
        }
    }
    return c;
}

Matrix mult(Matrix a,Matrix b){
    int a1=a.arr[0][0],a2=a.arr[0][1],a3=a.arr[1][0],a4=a.arr[1][1];
    int b1=b.arr[0][0],b2=b.arr[0][1],b3=b.arr[1][0],b4=b.arr[1][1];

    int d=a1*(b2-b4),e=a4*(b3-b1),f=b1*(a3+a4),g=b4*(a1+a2),h=(a3-a1)*(b1+b2),i=(a2-a4)*(b3+b4),j=(a1+a4)*(b1+b4);
    int c1=e+i+j-g,c2=d+g,c3=e+f,c4=d+h+j-f;
    Matrix c;
    c.arr[0][0]=c1,c.arr[0][1]=c2,c.arr[1][0]=c3,c.arr[1][1]=c4;
    return c;
}

Matrix split(Matrix a,int rstart,int rend,int cstart,int cend){
    Matrix temp;
    for(int i=rstart,ii=0;i<rend;i++,ii++){
        for(int j=cstart,jj=0;j<cend;j++,jj++){
            temp.arr[ii][jj]=a.arr[i][j];
        }
    }
    return temp;
}

Matrix join(Matrix a,Matrix b,Matrix c,Matrix d,int n){
    Matrix temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.arr[i][j]=a.arr[i][j];
            temp.arr[i][n+j]=b.arr[i][j];
            temp.arr[n+i][j]=c.arr[i][j];
            temp.arr[n+i][n+j]=d.arr[i][j];
        }
    }
    return temp;
}

Matrix strassenMultiply(Matrix a,Matrix b,int n){
    
    Matrix a1 = split(a,0,n/2,0,n/2);
    Matrix a2 = split(a,0,n/2,n/2,n);
    Matrix a3 = split(a,n/2,n,0,n/2);
    Matrix a4 = split(a,n/2,n,n/2,n);

    Matrix b1 = split(b,0,n/2,0,n/2);
    Matrix b2 = split(b,0,n/2,n/2,n);
    Matrix b3 = split(b,n/2,n,0,n/2);
    Matrix b4 = split(b,n/2,n,n/2,n);

    Matrix d = mult(a1,subtract(b2,b4,n/2));
    Matrix e = mult(a4,subtract(b3,b1,n/2));
    Matrix f = mult(add(a3,a4,n/2),b1);
    Matrix g = mult(add(a1,a2,n/2),b4);
    Matrix h = mult(subtract(a3,a1,n/2),add(b1,b2,n/2));
    Matrix i = mult(subtract(a2,a4,n/2),add(b3,b4,n/2));
    Matrix j = mult(add(a1,a4,n/2),add(b1,b4,n/2));

    Matrix c1 = add(add(e,i,n/2),subtract(j,g,n/2),n/2);
    Matrix c2 = add(d,g,n/2);
    Matrix c3 = add(e,f,n/2);
    Matrix c4 = add(add(d,h,n/2),subtract(j,f,n/2),n/2);

    Matrix temp = join(c1,c2,c3,c4,2);
    return temp;
}

Matrix normalMultiplication(Matrix a,Matrix b,int n){
    Matrix c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c.arr[i][j]+=(a.arr[i][k]*b.arr[k][j]);
            }
        }
    }
    return c;
}

int main(){
    Matrix a,b;
    int n;
    cout<<"Enter order of matrix: ";
    cin>>n;
    cout<<"\n\nEnter Matrix A: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a.arr[i][j];
            // a.arr[i][j]=i+j;
        }
    }
    cout<<"\n\nEnter Matrix B: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b.arr[i][j];
            // b.arr[i][j]=j-i;
        }
    }
    Matrix c=strassenMultiply(a,b,n);
    cout<<"\n\nStrassens Multiply: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c.arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    Matrix d=normalMultiplication(a,b,n);
    cout<<"\n\nNormal Multiply: \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<d.arr[i][j]<<"  ";
        }
        cout<<endl;
    }
    // 4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 1 2 3 4 0 0 0 0 9 8 7 6 0 0 0 0
}