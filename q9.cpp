/*
  Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

  Note that after backspacing an empty text, the text will continue empty.
*/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string TS = "", TT = "";
        for(int i=0; i<S.size(); i++){
            if(S[i]=='#')
                TS = TS.substr(0,TS.size()-1);
            else
                TS +=S[i];
        }
        for(int i=0; i<T.size(); i++){
            if(T[i]=='#')
                TT = TT.substr(0,TT.size()-1);
            else
                TT +=T[i];
        }
        if(TS == TT)
            return true;
        return false;
    }
};
