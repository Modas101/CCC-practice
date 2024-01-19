#include <iostream>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
#include <utility>

using namespace std;

int x, y, g;

void solve() {
  cin >> x;
  vector<pair<string, string>> CanBe(x);
  
  for (int i = 0; i < x; i++) {
    string a, b;
    cin >> a >> b;

    CanBe[i].first = a;
    CanBe[i].second = b;
  }

  cin >> y;

  vector<pair<string, string>> CantBe(y);

  for (int i = 0; i < y; i++) {
    string a, b;
    cin >> a >> b;
    
    CantBe[i].first = a;
    CantBe[i].second = b;
  }

  cin >> g;

  int totalViolations = 0;

  unordered_map<string, int> nameToGroup;

  //vector<vector<string>> groups(g, vector<string>(3));
  for (int i = 0; i < g; i++) {
    string a, b, c;
    cin >> a >> b >> c;
    nameToGroup[a] = i;
    nameToGroup[b] = i;
    nameToGroup[c] = i;
  }

  for (int i = 0; i < x; i++) {
    pair<string, string>& restriction = CanBe[i];
    //cout << restriction.first << " CHECK CAN " << restriction.second << endl;
    
    if (nameToGroup[restriction.first] != nameToGroup[restriction.second]) {
      totalViolations++;
      //cout << restriction.first << " CANBE " << restriction.second << endl;
    }
  }

  for (int i = 0; i < y; i++) {
    pair<string, string>& restriction = CantBe[i];
    //cout << restriction.first << " CHECK CANT " << restriction.second << endl;

    if (nameToGroup[restriction.first] == nameToGroup[restriction.second]) {
      totalViolations++;
      //cout << restriction.first << " CANTBE " << restriction.second << endl;
    }
  }
  
  cout << totalViolations;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();
}