class Solution {
public:
    bool isValid(string s) {

        int n=s.size();
        if(n%2 ==1)
        return false;

      //  ([}}])


stack<char>stk;
      for(auto x:s){
          if(x=='{' ||x=='[' ||x=='(' ){
              stk.push(x);
              }
          
          else{
              if(!stk.empty()){
                char t=stk.top();
              if(  (t=='{' && x=='}') || (t=='[' && x==']') ||(t=='(' && x==')') ){
                  stk.pop();
              }
              else
              return false;
              }
              else{
                  stk.push(x);
              }
          }
      }
      if(stk.empty())
      return true;
      
      


      return false;
        
    }
};
