#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

void solve() {
  int N;
  cin >> N;
  
  vector<int> tideList(N);

  for (int i = 0; i < N; i++) {
    cin >> tideList[i];
  }

  sort(tideList.begin(), tideList.end());

  vector<int> lowTideList(N/2 + 1);
  vector<int> highTideList(N/2);

  if (N % 2 == 1) {
    for (int i = 0; i < N/2 + 1; i++) {
      lowTideList[i] = tideList[i];
    }

    for (int i = 1; i + N/2 < N; i++) {
      highTideList[i - 1] = tideList[i + N/2];
    }
  } else {
    for (int i = 0; i < N/2; i++) {
      lowTideList[i] = tideList[i];
    }

    for (int i = 0; i + N/2 < N; i++) {
      highTideList[i] = tideList[i + N/2];
    }
  }

  sort(lowTideList.begin(), lowTideList.end(), [](int a, int b) {
    return a > b;
  });

  for (int i = 0; i < N/2; i++) {
    cout << lowTideList[i] << " " << highTideList[i] << " ";
  }

  if (N % 2 == 1) {
    cout << lowTideList[N/2];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  solve();
}