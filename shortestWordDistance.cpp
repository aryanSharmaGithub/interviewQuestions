    int shortestDistance(vector<string> &words, string &word1, string &word2) {
        int index1 = -1, index2 = -1, result = INT_MAX;
        for(int i=0;i<words.size();i++){
            if(words[i]==word1) index1 = i;
            if(words[i]==word2) index2 = i;
            if(index1 != -1 && index2 != -1)
            result = min(result, abs(index1-index2));
        }
        return result;
    }