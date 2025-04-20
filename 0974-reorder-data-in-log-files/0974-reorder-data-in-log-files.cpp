struct LetterLog {
    string id;
    string log_letters;
    LetterLog(string input){
        int br = input.find_first_of(" ");
        id = input.substr(0,br);
        log_letters = input.substr(br);
    }

    bool operator>(const LetterLog & other){
        if (log_letters > other.log_letters){
            return true;
        }
        if (log_letters == other.log_letters){
            return id > other.id;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> l_logs;
        vector<string> d_logs;
        priority_queue<LetterLog, vector<LetterLog>, greater<>> pq;
        for (const auto & log : logs){
            int br = log.find_first_of(" ");
            char content_first_char = log[br+1];
            if (isalpha(content_first_char)){
                pq.emplace(log);
            } else {
                d_logs.push_back(log);
            }
        }
        while (!pq.empty()){
            LetterLog L = pq.top();
            pq.pop();
            string log = L.id + L.log_letters;
            l_logs.push_back(log);
        }
        vector<string> ans;
        ans.insert(ans.end(), l_logs.begin(), l_logs.end());
        ans.insert(ans.end(), d_logs.begin(), d_logs.end());
        return ans;
    }
};