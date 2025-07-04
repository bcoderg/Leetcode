class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        string s = "a";

        // auto getNextStr=[&](string str)->string{
        //     int sz=str.size(); 
        //     for(int i=0;i<sz;i++){
        //         str+=(str[i]=='z' ? 'a' : str[i]+1 );
        //     }
        //     return str;
        // };

        // for(auto &op: operations){
        //     if(op==0){
        //         s += s;
        //     }
        //     else{
        //         string nextStr = getNextStr(s);
        //         s = nextStr; 
        //     }

        //     cout<<s<<"\n";

        //     if(s.size()>k)break;
        // }
        // return s[k-1];

        //using bitwise operations
        //no.of set bits in k-1 = no.of times doubled 
        //while doubling length , what is the operation type if 1 , then shift occurs 
        //coutn total no.of shifts

        int shifts=0;
        k--;
        for(int i=0; k != 0 ; i++)
        {
            //if doubled and shift operation
            if((k&1) & operations[i]){
                shifts++;
            }
            
            //make length by 2
            k>>=1;
        }
        return (char)( (shifts%26) + 'a' );
    }
};