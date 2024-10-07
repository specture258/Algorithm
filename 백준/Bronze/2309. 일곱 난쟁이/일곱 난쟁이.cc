#include <bits/stdc++.h>

using namespace std;



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[9];
	int result[7];
	int total;
	
	for(int i=0 ;i<9 ;i++){
		cin >> arr[i];
		
	}
	
	for(int a=1;a<9;a++){
		int total = 0;
		for(int b=0; b<a ;b++){
			total =0;
			
			for(int c=0,i=0; c<9 ; c++){
		if(c != a && c != b){
			result[i++] =arr[c];
		}
	}
	
	for(int i =0; i<7; i++){
		total += result[i];
	}
			if(total == 100) break;
			
		}
		if(total == 100) break;
	} 
	
	

	sort(result, result+7);
	for(int i =0;i<7; i++){
		cout << result[i] << "\n";
	}
    

	
}