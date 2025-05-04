#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin >> vec[i];
        }auto maxIt = max_element(vec.begin(), vec.end());
        int maxVal=*maxIt;
        vector<int>vecCopy=vec;
        vecCopy.erase(remove(vecCopy.begin(), vecCopy.end(), maxVal), vecCopy.end());
        auto maxIt2 = max_element(vecCopy.begin(), vecCopy.end());
        int maxVal2=*maxIt2;
        int reappear = count(vec.begin(), vec.end(), maxVal);
        if(reappear>1) maxVal2=maxVal;
        for(int i=0;i<vec.size();i++){
                cout << (vec[i]==maxVal ? vec[i]-maxVal2 : vec[i]-maxVal ) << " ";
        }cout << "\n";
    }return 0;
}