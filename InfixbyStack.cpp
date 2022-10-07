#include<iostream>
using namespace std;
int size;
class Stack{
   private:
  int top;
char *array;
  
public:
Stack(){
    array =new char [size];
    top=-1;
}

   void push(int value){
    if(top==size-1){cout<<"stack overflow"<<endl;
    return;
   }
   else{top++;
   array[top]=value;}
};
 void pop(){
    if(top==-1){cout<<"stack underflow"<<endl;
    return;
   }
   else{top--;}
};
 char topElement(){
    if(top==-1){
         cout<<"stack underflow"<<endl;
         return -1;
    
   }else {
  return array[top];}
};




    bool empty(){
        if (top==-1)
        {
            return true;
        }else{
            return false;}
        
    }
    int priority(char c){
    if (c=='^')
    {
        return 3;
    }
    else if (c=='*'||c=='/')
    {
        return 2;
            }
    else if(c=='+'||c=='-')
    {
      return 1;
    }else{
        return -1;
    }
    
};
string infitopostfix(string s){

    string result;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i]>='a'&& s[i]<='z')||(s[i]>='A'&& s[i]<='Z'))
        {
            result+=s[i];
        }
        else if (s[i]=='(')
        {
            push(s[i]);
        }
        else if(s[i]==')')
        {
            while (!empty()&&topElement()!='(')
            {
                result+=topElement();
                pop();
            }
            if (!empty()){}
            {
                pop();
            }
            
            
        }else{
            while (!empty() && priority(topElement()) > priority(s[i]))
            {
                result+=topElement();
                pop();
            }
            push(s[i]);
            
        }
        
    }
    while (!empty())
    {
        result+=topElement();
        pop();
    }
    return result;
    
    
}

};
int main(){
    cout<<"enter size of stack";
    cin>>size;
    Stack obj1;
    string expression;
cout<<"enter expression"<<endl;
cin>>expression;
cout<<obj1.infitopostfix(expression);








}