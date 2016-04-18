#include <iostream>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
void LCS(int s[],int s1[]){
    
}
int main() {
	// here is the dp implementation of the LCS
	int arr[101];
	int arr1[101];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	for(int i=0;i<m;i++){
	    cin>>arr1[i];
	}
	int l=n;
    int DP[l+1][m+1];
    for(int i=0;i<=l;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0){
                DP[i][j]=0;
            }else if(arr[i-1]==arr1[j-1]){
                DP[i][j]=DP[i-1][j-1]+1;
            }else{
                DP[i][j]=max(DP[i-1][j],DP[i][j-1]);
            }
        }
    }
    int val[101];
    int count=0;
   int i=l;
   int j=m;
    while(i>0 && j>0){
        if(arr[i-1]==arr1[j-1]){
            val[count++]=arr[i-1];
            i--;
            j--;
        }else if(DP[i-1][j]>DP[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    for(int i=count-1;i>=0;i--){
       cout<<val[i]<<" ";
    }
	return 0;
}
