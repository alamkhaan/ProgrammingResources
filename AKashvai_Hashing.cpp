/***
*   author:   5-head
*   created:  17.04.2021 12:21:15
***/

#include<bits/stdc++.h>

using namespace std;

const int max_size = (int) 1e6 + 5; /* maximum character in the hash */
const int max_hash_size = 5;  /* no of hash */
const int primes [max_hash_size] = {37, 421, 43, 383, 67};
int p_power[max_hash_size][max_size];
const int hash_mod = 982563121;

/* call pre_hash in the beginning of main */
void pre_hash() {
  for (int i = 0; i < max_hash_size; i++) {
    p_power[i][0] = 1;
    for (int p = 1; p < max_size; p++) {
      p_power[i][p] = (static_cast<long long> (p_power[i][p - 1]) * primes[i]) % hash_mod;
    }
  }
}

class _hash {
public:
  int n;
  int sz;
  int val[max_hash_size];
  /* default double hashing */
  _hash() : n(2), sz(0) {
    for (int i = 0; i < n; i++) {
      val[i] = 0;
    }
  }
  /* n - hash */
  _hash(int _n) : n(_n), sz(0) {
    for (int i = 0; i < n; i++) {
      val[i] = 0;
    }
  }
  /* n - hash initialize with character c */
  _hash(int _n, const char &c) : n(_n), sz(0)  {
    for (int i = 0; i < n; i++) {
      val[i] = 0;
      val[i] = ctoi(c);
    }
    ++sz;
  }
  /* n - hash initialize with a given string */
  _hash(int _n, const string &str) : n(_n), sz(0) {
    for (int i = 0; i < n; i++) {
      val[i] = 0;
    }
    for (const char &c : str) {
      add(c);
    }
  }
  /* convert character to an integer value */
  inline int ctoi(const char &c) {
    return (c - 'a' + 1);
  }

  /* add a character at the end of the stream */
  void add(const char &c, int inc = 1) {
    for (int i = 0; i < n; i++) {
      val[i] = (static_cast<long long> (val[i]) * primes[i]) % hash_mod;
      val[i] = val[i] + ctoi(c);
      if (val[i] >= hash_mod) {
        val[i] -= hash_mod;
      }
    }
    sz += inc;
  }
  /* head added in front of the stream and tail removed from the back */
  void roll(char head, char tail) {
    add(head, 0);
    for (int i = 0; i < n; i++) {
      int bad = (static_cast<long long> (p_power[i][sz]) * ctoi(tail)) % hash_mod;
      val[i] -= bad;
      if (val[i] < 0) {
        val[i] += hash_mod;
      }
    }
  }

  /* return a pair only for double hash */
  inline pair<int, int> get() {
    assert(n == 2);
    return make_pair(val[0], val[1]);
  }

  /* operator overload */
  bool operator == (const _hash &rhs) const {
    assert(n == rhs.n);
    for (int i = 0; i < n; i++) {
      if (val[i] != rhs.val[i]) {
        return false;
      }
    }
    return true;
  }
  bool operator != (const _hash &rhs) const {
    assert(n == rhs.n);
    for (int i = 0; i < n; i++) {
      if (val[i] != rhs.val[i]) {
        return true;
      }
    }
    return false;
  }
};

void solve() {
  string a, b;
  cin >> a >> b;
  int n = (int) a.size();
  int m = (int) b.size();
  _hash h_b(5, b);
  _hash h_a(5, a.substr(0, m));
  int ans = (h_a == h_b);
  for (int i = m; i < n; i++) {
    h_a.roll(a[i], a[i - m]);
    ans += h_a == h_b;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  pre_hash();
  int tc;
  cin >> tc;
  int tt = 0;
  while (tc--) {
    cout << "Case " << ++tt << ": ";
    solve();
  }
  return 0;
}
