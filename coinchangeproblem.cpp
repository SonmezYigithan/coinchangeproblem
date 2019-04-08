#include<iostream>
#include<cstdlib>
#include <bits/stdc++.h> //for vector
// Returns the count of ways we can  
// sum S[0...m-1] coins to get sum n 
using namespace std;

int count( int coins[], int size, int n ) // size = m , S = arr
{ 
    // If n is 0 then there is 1 solution (do not include any coin) 
    if (n == 0) 
        return 1; 
      
    // If n is less than 0 then no solution exists 
    if (n < 0) 
        return 0; 
  
    // If there are no coins and n is greater than 0, then no solution exist 
    if (size <=0 && n >= 1) 
        return 0; 
  
    // count is sum of solutions (i)  
    // including S[m-1] (ii) excluding S[m-1] 
    return count( coins, size - 1, n ) + count( coins, size, n-coins[size-1] ); 
}

int findmin(int C, int coins[], int size){
	vector<int> ans;
	for(int i=size-1;i>=0;i--){
		while(C>=coins[i]){
			C -= coins[i];
			ans.push_back(coins[i]);
		}
	}
		printf("Best way: [");
	for(int i=0;i<ans.size();i++){
		printf("%d, ",ans[i]);
	}
	printf("]");
}
  
// Driver program to test above function 
int main()
{ 
    int i, j, n;
	n = 120;
    
	int coins[] = {1, 5, 10, 12, 25, 50, 100}; //use vector 
    int size = sizeof(coins)/sizeof(coins[0]);
    
    printf("n = %d\n",n);
	printf("numbe of ways: %d\n", count(coins, size, n)); 
	findmin(n, coins, size);
    
	getchar(); 
    return 0; 
} 
