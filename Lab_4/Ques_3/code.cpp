#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&vec,int i){

    int l=2*i+1;
    int r=2*i+2;
    int largest=i;
    if(l<vec.size() && vec[l]>vec[largest]){
        largest=l;
    }
    if(r<vec.size() && vec[r]>vec[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(vec[i],vec[largest]);
        heapify(vec,largest);
    }

}

void buildmaxheap(vector<int>&vec){

    for(int i=vec.size()/2-1;i>=0;i--){
        heapify(vec,i);
    }
}

int kthlargest(vector<int>&vec,int k){

    buildmaxheap(vec);
    int n=vec.size();
    for(int i=vec.size()-1;i>=n-k+1;i--){
        swap(vec[0],vec[i]);
        vec.pop_back();
        heapify(vec,0);
    }
    return vec[0];
}

int main() {
    ifstream inputFile("../input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening file." <<endl;
        return 1; 
    }

    const int maxSize = 10000000; 
    int n,k;
    inputFile>>n>>k;
    vector<int>vec;
    for(int i=0;i<n;i++){
        int val;
        inputFile>>val;
        vec.push_back(val);
    }
    
    inputFile.close();

    cout << "Data read from file and stored in array:" << endl;

    int a=kthlargest(vec,k);

    ofstream outputFile("output.txt");

    if (!outputFile.is_open()) {
        cerr << "Error opening output file." <<endl;
        return 1; 
    }

    for (int i = 0; i < 1; ++i) {
        outputFile<<"the kth largest element is "<<a<<endl;
    }

    outputFile.close();
    cout << "Data written to output file." << endl;
    return 0;
}
    