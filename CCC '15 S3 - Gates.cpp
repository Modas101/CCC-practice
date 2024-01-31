#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

void solve() {
  int G, P;
  cin >> G >> P;

  set<int> term;

  for (int i = 1; i <= G; i++) {
    term.insert(i);
  }

  int tot = 0;
  bool closed = false;

  for (int i = 0; i < P; i++) {
    int gate;
    cin >> gate;

    if (term.size() == 0 || closed) continue;

    auto nearest = term.lower_bound(gate);
    int oldtot = tot;

    if (nearest != term.begin()) {
      if (nearest == term.end() || (*nearest) != gate) {
        nearest--;
      }
      
      int free = *(nearest);
      term.erase(free);
      tot++;
    } else if (gate >= *nearest) {
      int free = *(nearest);
      term.erase(free);

      tot++;
    }

    if (oldtot == tot) {
      closed = true;
    }
  }

  cout << tot;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}