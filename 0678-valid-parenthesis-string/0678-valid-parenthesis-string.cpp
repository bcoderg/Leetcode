class Solution {
public:
    bool checkValidString(string s) {
        int leftMin=0 , leftMax=0;
        for(char c:s){
            if(c =='('){
                leftMin++;
                leftMax++;
            }
            else if(c==')'){
                leftMin--;
                leftMax--;
            }
            else{// if char is '*' 
                //3 choices we can choose "(" or ")" or " "
                leftMin--;//take "*" as ")"
                leftMax++;//take "*" as "("
            }
            //don't consider all "*" as ")" , mark few as empty 
            if(leftMin<0)leftMin=0;
            //too many closings
            if(leftMax<0)return false;
        }
        return leftMin==0;
    }
};