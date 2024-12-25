#include<bits/stdc++.h> 
using namespace std;


string word;

string m = "aeiou";
int check[25];
bool isContainM(string word){
	if(word.find("a") !=string::npos || word.find("e")!=string::npos || word.find("i")!=string::npos|| word.find("o")!=string::npos || word.find("u")!=string::npos){
		return true;
	}
	return false;
}

bool first(string word){
	if(isContainM(word)){
		return true;
	}
	return false;
}

bool second(string word){
	fill(check, check+21, 0);
	for(int i=0 ; i<word.length(); i++){
		if(word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u' ){
			check[i] = 1;
		}
		else{
		   check[i] = -1;
		}
	}

	
	for(int i=0 ; i<word.length(); i++){
		if(check[i] == check[i+1] && check[i+1]== check[i+2] &&check[i]== check[i+2] ){
			 return false;
		}
	}
	return true;
}

bool third(string word){
	for(int i=0 ; i<word.length()-1; i++){
		if(word[i] == word[i+1]){
			if(word[i] != 'e' && word[i] != 'o'){
				return false;
			}
		}
	}
	return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

   while(true){
   	cin >> word;
   	 if(word == "end") break;
   	 
   	 if(first(word) == false){
   	 	cout << "<" << word << ">" << " is not acceptable.";

   	 	cout << "\n";
   	 	continue;
	 }
	 
	 if(second(word) == false){
	 	cout << "<" << word << ">" << " is not acceptable.";

	 	cout << "\n";
	 	continue;
	 }
   	 
   	 if(third(word) == false){
   	 	cout << "<" << word << ">" << " is not acceptable.";

   	 	cout << "\n";
   	 	continue;
	 }
   	 cout << "<" << word << ">" << " is acceptable.";
   	 cout << "\n";
   }
   
}