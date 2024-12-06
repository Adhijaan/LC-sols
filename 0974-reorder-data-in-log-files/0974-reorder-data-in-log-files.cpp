class Solution {
class log {
public:
    string id;
    string val;
};

class comp {
public:
    bool operator()(const log& a, const log& b) const {
        if(a.val != b.val){
            return a.val < b.val;
        }
        return a.id < b.id;
    }
};

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<log> lets;
        vector<log> digs;
        
        for (const string& l : logs) {
            log entry;
            int separator = l.find_first_of(' ');
            entry.id = l.substr(0, separator);
            entry.val = l.substr(separator + 1);
            
            if (isalpha(entry.val[0])) {
                lets.emplace_back(entry); 
            } else {
                digs.emplace_back(entry); 
            }
        }
        sort(lets.begin(), lets.end(), comp());

        vector<string> ans;
        for (const log& l : lets) {
            ans.emplace_back(l.id + " " + l.val); 
        }
        for (const log& l : digs) {
            ans.emplace_back(l.id + " " + l.val); 
        }
        return ans;
    }
};
