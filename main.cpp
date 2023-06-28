#include <bits/stdc++.h>

using namespace std;

bool isOperator(char input){
  switch (input){
    case '+':
      return true;
      break;
    case '-':
      return true;
      break;
    case '*':
      return true;
      break;
    case '/':
      return true;
      break; 
    case '^':
      return true; 
      break;
    default: 
      return false; 
      break;
  }
}

int level (char input){
  if(input=='^'){
    return 3;
  }
  else if(input == '*' || input == '/')
  {
    return 2;
  }
  else if(input == '+' || input == '-')
  {
    return 1;
  }
}

string polish(string input){
  input+=")";
  cout<<input;
  string result;
  stack <char> myStack;
  myStack.push('(');
  for(int i = 0 ; i < input.length() ; i ++)
  {
    //input[i] là toán hạng
    if(isOperator(input[i]) == false && input[i]!='(' && input[i] != ')') result += input[i]; 
    //input[i] là dấu ngoặc mở
    if(input[i]=='(') myStack.push(input[i]);
    //input[i] là toán tử
    if(isOperator(input[i]) == true){
      while(level(myStack.top()) >= level(input[i]))
      {
        result += myStack.top();
        myStack.pop();
      }
    }
    //input[i] là dấu ngoặc đóng 
    if(input[i] == ')'){
      while(myStack.top() != '('){
        result += myStack.top();
        myStack.pop();
      }
      if(myStack.top() == '('){
        myStack.pop();
      }
    }
  }
  cout<<"Result: "<<result<<endl;
  return result;
}


int main(){
  cout<<polish("A+B");
  return 0;
}
