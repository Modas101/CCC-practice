#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

void solve() {
  // have two maps, one for collumns, one for rows, flick the row or collumn sections on or off accordingly, then once finished, map it all to the map and count

  int M, N;
  cin >> M >> N;
  
  vector<bool> M_check(M);
  vector<bool> N_check(N);

  int K;
  cin >> K;

  for (int c = 0; c < K; c++) {
    char type;
    int n;
    cin >> type >> n;
    n--;

    if (type == 'R') {
      M_check[n] = !M_check[n];
    } else {
      N_check[n] = !N_check[n];
    }
  }

  vector<vector<bool>> map(M, vector<bool>(N));

  for (int i = 0; i < M; i++) {
    if (M_check[i] == false) continue;
    
    for (int j = 0; j < N; j++) {
      map[i][j] = !map[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    if (N_check[i] == false) continue;

    for (int j = 0; j < M; j++) {
      map[j][i] = !map[j][i];
    }
  }
  int ans = 0;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (map[i][j]) {
        ans++;
      }
    }
  }
  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}