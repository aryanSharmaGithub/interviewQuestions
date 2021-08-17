class TwoSum {
public:
    unordered_map<int, int> myHash;
    void add(int number) {
            myHash[number]++;
    }
    bool find(int value) {
        for(unordered_map<int, int>::iterator it = myHash.begin(); it!=myHash.end(); it++)
        {
            int target = value - it->first;
            if ((target != it->first && myHash.count(target) >0) || (target == it->first && it->second > 1)) {
                return true;
            }
        }
        return false;
    }
};