#include <iostream>


using namespace std;

pair <int, int> MinMax(int a[], int b)
{
   int min=a[0];
   int max=a[0];

    for (int i=1;i<b;i++){
        if (a[i]>max){
            max=a[i];
        }
        
        if (a[i]<min){
            min=a[i];
        }
    }

    return {min,max};
}

int main(){

    int num[5]={5,-2,-85,65,369};
    cout <<"Min is : "<<MinMax(num,5).first <<" & Max is : "<<MinMax(num,5).second <<endl;

}