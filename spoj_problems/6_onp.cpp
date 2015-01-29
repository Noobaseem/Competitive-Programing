#include <iostream>
#include <cstring>
#include <vector>
 
using namespace std;
 
typedef vector<char> stacks;
 
int main() {
	int T;
	cin>>T;
	while(T){
		stacks operators;
		int iteratorOperators = 0;
		char expression[400];
		cin>>expression;
		for( int i = 0; i < strlen(expression); i++ ){
			if( expression[i] == '(' || expression[i] == '-' || expression[i] == '+' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^' ){
				operators.push_back(expression[i]);
				iteratorOperators++;
			}
			if( expression[i] >= 'a' && expression[i] <= 'z' ){
				cout<<expression[i];
			}
			if( expression[i] == ')' ){
				iteratorOperators--;
				while( operators[iteratorOperators] != '(' ){
					cout<<operators[iteratorOperators];
					operators.pop_back();
					iteratorOperators--;
				}
				operators.pop_back();
			}
		}
		cout<<"\n";
		T--;
	}
	return 0;
} 

