class Solution {
public:
    int secondsBetweenTimes(string s, string e) {
        int tot = 0;

        string h1,h2,m1,m2,s1,s2;

        

        h1 = s.substr(0,2);
        h2 = e.substr(0,2);

        m1 = s.substr(3,2);
        m2 = e.substr(3,2);

        s1 = s.substr(6,2);
        s2 = e.substr(6,2);

        int ans = 0;


        if(s1!="00"){
            ans-=stoi(s1);
        }
        if(s2!="00"){
            ans+=stoi(s2);
        }

        if(m1!="00"){
            ans-=stoi(m1)*60;
        }
        if(m2!="00"){
            ans+=stoi(m2)*60;
        }

        if(h1!="00"){
            ans-=stoi(h1)*60*60;
        }
        if(h2!="00"){
            ans+=stoi(h2)*60*60;
        }

        return ans;


    }
};