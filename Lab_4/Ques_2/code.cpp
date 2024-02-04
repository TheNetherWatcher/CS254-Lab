
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    double min(int a, int b)
    {
        if (a > b)
        {
            return b;
        }
        else
        {
            return a;
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> vec1 = nums1;
        vector<int> vec2 = nums2;
        vec1.insert(vec1.begin(), -1000001);
        vec2.insert(vec2.begin(), -1000001);
        vec1.push_back(1000001);
        vec2.push_back(1000001);
        if (vec2.size() < vec1.size())
        {
            vector<int> vec3 = vec1;
            vec1 = vec2;
            vec2 = vec3;
        }
        int s1 = nums1.size() + nums2.size();
        int s = (nums1.size() + nums2.size()) / 2;
        int l{0}, r{static_cast<int>(vec1.size()) - 2};
        int mid = 0;

        while (true)
        {
            mid = (l + r) / 2;
            if (vec2[s - mid + 1] >= vec1[mid] & vec2[s - mid] <= vec1[mid + 1])
            {
                break;
            }
            if (vec1[mid] >= vec2[s - mid + 1])
            {
                r = mid - 1;
            }
            else if (vec2[s - mid] >= vec1[mid + 1])
            {
                l = mid + 1;
            }
        }
        if (s1 % 2 == 0)
        {
            double f = max(vec1[mid], vec2[s - mid]);
            double se = min(vec1[mid + 1], vec2[s - mid + 1]);
            return (f + se) / 2;
        }
        else
        {
            return min(vec1[mid + 1], vec2[s - mid + 1]);
        }
    }
};

int main()
{
    ifstream inputFile("../input.txt");

    if (!inputFile.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    const int maxSize = 10000000;
    int n, m; 
    inputFile >> n >> m;
    vector<int> vec1, vec2;
    for (int i = 0; i < n; i++)
    {
        int val;
        inputFile >> val;
        vec1.push_back(val);
    }
    for (int i = 0; i < m; i++)
    {
        int val;
        inputFile >> val;
        vec2.push_back(val);
    }

    inputFile.close();

    cout << "Data read from file and stored in array:" << endl;

    Solution obj;
    double a = obj.findMedianSortedArrays(vec1, vec2);

    ofstream outputFile("output.txt");

    if (!outputFile.is_open())
    {
        cerr << "Error opening output file." << endl;
        return 1; 
    }

    for (int i = 0; i < 1; ++i)
    {
        outputFile << "the median of the array is " << a << endl;
    }

    outputFile.close();

    cout << "Data written to output file." << endl;
    return 0;
}
