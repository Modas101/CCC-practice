#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

int K;

void solve() {
  cin >> K;
  stack<int> a;
  int s = 0;

  for (int i = 0; i < K; i++) {
    int v;
    cin >> v;
    if (v == 0) {
      s -= a.top();
      a.pop();
    } else {
      a.push(v);
      s += v;
    }
  }

  cout << s;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}