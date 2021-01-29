#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int test_cases;
cin>>test_cases;

int ranges[test_cases];
int max=INT_MIN;
for(int i=0;i<test_cases;i++){
    cin>>ranges[i];
    if(ranges[i]>max)max=ranges[i];
}
max++;'
# sieveOfEratosthenes start#########################
vector<bool> prime_numbers(max,true);
prime_numbers[0]=false;
prime_numbers[1]=false;
int i,j;
for(i=2;i*i< max;i++)
{
if(prime_numbers[i])
{
    for(j= i*i;j<max;j+= i)
    prime_numbers[j]= false;
}
}
# sieveOfEratosthenes end#########################
int res[max];
for(i=0;i<max;i++)
res[i]=0;

for(i=5;i<max;i++)
{
    if(prime_numbers[i])
    {
        if(prime_numbers[i-2])
        res[i]= res[i-1]+1;
        else
        res[i]= res[i-1];
    }
    else
    res[i]= res[i-1];
}

//for(int i=0;i<max;i++)cout<<res[i]<<" ";
//cout<<endl;
for(int test=0;test<test_cases;test++){

cout<<res[ranges[test]]<<endl;

}

}
