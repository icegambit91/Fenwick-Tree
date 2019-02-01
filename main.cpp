#include <iostream>

using namespace std;

void BITreeSet(int BITree[], int idx, int value, int n){
    while(idx <= n){
        BITree[idx] += value;
        idx += (idx & (-idx));
    }
}

int BITreeSum(int BITree[], int cnt, int testCnt, int k){
    int sum = 0, testSum = 0;

    while(cnt > 0){
        sum += BITree[cnt];
        cnt -= (cnt & (-cnt));
    }

    while(testCnt > 0){
        testSum += BITree[testCnt];
        testCnt -= (testCnt & (-testCnt));
    }

    testSum += k;
    if (testSum < sum){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    int arr[n], BITree[n + 1] = {0};

    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    for (int i = 0 ; i < n ; i++){
        BITreeSet(BITree, i + 1, arr[i], n);
    }

    int l, r, k, num;

    for (int j = 0 ; j < q ; j++){
        num = 0;
        cin >> l >> r >> k;
        for (int i = l ; i <= r ; i++){
            int status = BITreeSum(BITree, i, i - 1, k);
            if (status == 1){
                num++;
            }
        }
        cout << num << endl;
    }
}
