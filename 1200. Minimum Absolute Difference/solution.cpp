vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff = INT_MAX;
        vector<vector<int>> resultList;
        
        sort(arr.begin(), arr.end());
        
        for(int i=1; i<arr.size(); i++) {
            minDiff = min(minDiff, arr[i]-arr[i-1]);
        }
        
        for(int i=1; i<arr.size(); i++) {
            if((arr[i]-arr[i-1])==minDiff) {
                vector<int> numPair = {arr[i-1], arr[i]};
                resultList.push_back(numPair);
            }
        }
        
        return resultList;
    }