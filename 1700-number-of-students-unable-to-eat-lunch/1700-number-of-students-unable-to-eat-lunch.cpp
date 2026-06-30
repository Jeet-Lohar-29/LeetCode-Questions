class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};
        
        // Count the number of students who want circular (0) and square (1) sandwiches
        for (int student : students) {
            count[student]++;
        }
        
        // Process sandwiches in order
        for (int sandwich : sandwiches) {
            // If no remaining student wants this sandwich, the rest are stuck
            if (count[sandwich] == 0) {
                return count[0] + count[1];
            }
            count[sandwich]--;
        }
        
        return 0;
    }
};
