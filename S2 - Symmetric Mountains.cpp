#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int N;

void solve() {
  cin >> N;
  vector<int> nums(N);
  int maxSum = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
    maxSum += nums[i];
  }

  vector<int> res(N, maxSum);

  // create windows from 1 to N len, l inclusive, r exclusive
  // o(n^3) complexity, need to reduce to n^2 or better. use prefix sum array after using math to simplify equation
  
  
  for (int midPoint = 0; midPoint < N; midPoint++) {
    int sum = 0;
    int l = midPoint;
    int r = midPoint;

    while (l >= 0 && r < N) {
      sum += abs(nums[l] - nums[r]);
      res[r - l] = min(res[r - l], sum);
      
      l--;
      r++;
    }

    sum = 0;
    l = midPoint;
    r = midPoint + 1;

    while (l >= 0 && r < N) {
      sum += abs(nums[l] - nums[r]);
      res[r - l] = min(res[r - l], sum);

      l--;
      r++;
    }
  }

  for (int r : res) {
    cout << r << " ";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}