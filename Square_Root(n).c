/* 

@Shivansh Kaushal (1910990128)

Program to find sqrt of a number(n) upto given decimal places(p).
Code Language -  C 

*/

#include<stdio.h>
#include<math.h>

//Function to find integer sqrt of n ->
double bin_s(int n)
{
    long long int i=1;    // start index
    long long int j=n;    // end index
    double ans=1;         // current answer
    while(i<=j)
    {
        double mid=(i + j)/2;
        if((mid*mid) <= n) 
        {
            ans = mid;    // updating the answer
            i = mid+1;  
        }
        else
        j = mid-1;
    }
    
    return ans;
}

//Function to find points ->
double find_point(int n,double int_sqrt,long long int lower,long long int upper)
{
    double ans=0;            // current answer
    long long int up=upper;  // upper value for points 
    while(lower<=upper)
    {
        double mid = (lower + upper)/2;
        double x = int_sqrt + (double)((double)(mid)/up);  
        if((x*x) <= n)
        {
            ans=mid;         // updating the ans
            lower=mid+1;
        }
        else
        upper=mid-1;
    }
    
    return ans;
}

//Main function ->
int main()
{
   int n,p;
   
   // taking input
   scanf("%d %d",&n,&p);  
   
   // Calculating the integer value of sqrt of n using binary search
   double int_sqrt = bin_s(n);
   
   // Upper value for points
   long long int upper =  pow(10,p);
   
   //Calculating the points using binary search
   double point = find_point(n,int_sqrt,0,upper);
   
   //printing answer = int_sqrt + (double)((double)(point)/upper) 
   printf("The square root of %d is %0.15g\n",n,int_sqrt + (double)((double)(point)/upper)); 
      
}
