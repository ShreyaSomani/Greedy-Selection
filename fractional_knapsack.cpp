#include<iostream>
#include<algorithm>
using namespace std;
 
// A structure to represent a job
struct obj
{
   char id;     // Job Id
   int profit,weight;    // Deadline of job
   float p_w,x;  // Profit if job is over before or on deadline
};
 
// This function is used for sorting all jobs according to profit
bool comparison(obj a, obj b)
{
     return (a.p_w > b.p_w);
}
 
 void fractionalK(obj arr[],int n,int k)
 {
    sort(arr,arr+n,comparison);
    int i=0,TP =0;

    while(k>0)
    {
        arr[i].x=min(arr[i].weight,k);
        k = k - arr[i].x;
        arr[i].x = arr[i].x/arr[i].weight;
        TP+= arr[i].x * arr[i].profit;
        ++i;
    }
    cout << TP;
 }

 int main()
{
    obj arr[] = {{'a',18,5,3.6},{'b',25,3,8.3},{'c',12,4,3},{'d',4,4,1},{'e',8,3,2.6}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 9;
   
    // Function call
    cout << "Total profit is : ";
    fractionalK(arr, n,k);
   
    cout << endl;
    for(int i=0;i<n;++i)
   {
    cout << arr[i].id << "-:" << arr[i].x<<"    ";
   }
    return 0;
}