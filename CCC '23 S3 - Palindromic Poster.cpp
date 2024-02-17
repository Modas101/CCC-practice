// FAILS ON TEST CASES 2 AND 3


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

void solve() {
  int N, M;
  int R, C;
  cin >> N >> M >> R >> C;

  vector<vector<char>> map(N, vector<char>(M, 'a'));
// from the base case, find out where it fails and handle the cases from there

  // testcase 8 8 8 0 fails, right most collumn is filled
  if (R == 0 || C == 0 || R == N || C == M) {
    if (R == 0 || C == 0) {
      // just implement R or C first then swap inputs and answer
      if (R == 0) {
        for (int i = 0; i < N; i++) {
          map[i][M - 1] = 'b'; // all palindromes for collumn but not for R
        }
        for (int i = 0; i < (M - C); i++) {// replace with how much shouldn't be palindrome
          map[N - 1][i]++;
        }
      } else {
        for (int i = 0; i < M; i++) {
          map[N - 1][i] = 'b';
        }
        for (int i = 0; i < (N - C); i++) {
          map[i][M - 1]++;
        }
      }
    } else {
      // r == N or c == M
      if (R == N) {
        for (int i = 0; i < M; i++) {
          map[N - 1][i] = 'b';
        }

        int goalC = C;
        
        if (M % 2 == 0) {
          if (C % 2 == 1) {
            cout << "IMPOSSIBLE";
            return;
          }
          //cout << "ran";
          // just don't do the center one
        } else {
          if (C % 2 == 1) {
            goalC--;
            map[N - 1][M/2] = 'a';
          }
        }
        
        goalC /= 2;

        for (int i = 0; i < goalC; i++) {
          map[N - 1][i] = 'a';
          map[N - 1][M - 1 - i] = 'a';
        }
        
      } else {
        for (int i = 0; i < N; i++) {
          map[i][M - 1] = 'b';
        }

        int goalR = R;

        if (N % 2 == 0) {
          if (R % 2 == 1) {
            cout << "IMPOSSIBLE";
            return;
          }
          // just don't do the center one
        } else {
          goalR--;
          map[N/2][M - 1] = 'a';
        }

        goalR /= 2;

        for (int i = 0; i < goalR; i++) {
          map[i][M - 1] = 'a';
          map[N - 1 - i][M - 1] = 'a';
        }
      }
    }
  } else {
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < M; j++) {
        map[i][j] = 'b';
      }
    }

    for (int i = 0; i < C; i++) {
      for (int j = 0; j < N; j++) {
        map[j][i] = 'b';
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << map[i][j];
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}