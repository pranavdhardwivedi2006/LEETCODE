class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, maxArea = 0;
        while (i < j) {
            int minHeight = height[i] < height[j] ? height[i] : height[j];
            int area = minHeight * (j - i);
            if (area > maxArea) maxArea = area;
            if (height[i] < height[j]) i++;
            else j--;
        }
        return maxArea;
    }
};