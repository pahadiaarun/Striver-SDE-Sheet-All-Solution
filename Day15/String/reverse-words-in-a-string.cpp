// https://leetcode.com/problems/reverse-words-in-a-string/

string reverseString(string &s){
  // Write your code here.
  string res="";
        string temp="";
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==' '){
                if(temp=="") continue;
                res+=temp+" ";
                temp="";
                continue;
            }
            temp=s[i]+temp;
        }
        res+=temp;
        if(res.back()==' ') res.pop_back();
        return res;  
}

