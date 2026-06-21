#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;   
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return inv_count;
}

long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        vector<int> b(n + 1);
        vector<int> idx;
        multiset<pair<int, int>> ms;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        for(int i = 1; i <= n;i++)
            cin >> b[i];

        for(int i = 1; i <= n;i++)
            ms.insert({b[i], i});

        bool ans = true;
        for(int i = 1; i <= n; i++) {
            auto it = ms.lower_bound({a[i], 0});
            if(it==ms.end())
            {
                ans = false;
                break;
            }
            idx.push_back(it->second);
            ms.erase(it);
        }

        if(ans)
        {
            vector<int> temp(idx.size());
            cout << mergeSort(idx, temp, 0, idx.size() - 1)<<"\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}
// i번째 pile은 ai 오리 가지고있음
// 오름차순 배열 bi
// ai를 bi처럼 만들도록 한다

// operation
// 1. 각 파일에 아무 숫자나 더한다
//    각 파일 i에 정수 xi를 골라서 ai를 ai+xi로 교체
// 2. 두 인접한 수를 스왑
//    1 < i < n-1 사이의 인덱스를 골라서 i, i+1을 스왑한다

// 1. multiset에 bi와 i 저장
// 2. idx에 ai 와 bi 매칭시킨 인덱스 값 저장 

// https://codeforces.com/contest/2237/problem/B