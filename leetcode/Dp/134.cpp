//
// Created by Mykyta on 7/18/2025.
//
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            gas[i] -= cost[i];
        }
        int i = 0, j = n - 1;
        int sum = 0;
        while (i <= j) {
            if (sum > 0) {
                sum += gas[i++];
            }
            else {
                sum += gas[j--];
            }
        }
        return sum >= 0 ? (j + 1) % n : -1;
    }
};