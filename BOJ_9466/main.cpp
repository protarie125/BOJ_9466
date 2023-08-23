#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n;
vi selected;
int ct;
vb isAdded;
vb isNot;

void checkTeamed(int x) {
	isAdded[x - 1] = true;

	const auto& next = selected[x - 1];

	if (!isAdded[next - 1]) {
		checkTeamed(next);
	}
	else {
		if (!isNot[next - 1]) {
			for (auto i = next; i != x; i = selected[i - 1]) {
				++ct;
			}

			++ct;
		}
	}

	isNot[x - 1] = true;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t;
	cin >> t;
	while (0 < (t--)) {
		cin >> n;

		selected = vi(n);
		for (auto&& x : selected) {
			cin >> x;
		}

		ct = 0;
		isAdded = vb(n, false);
		isNot = vb(n, false);

		for (auto i = 1; i <= n; ++i) {
			if (isAdded[i - 1]) {
				continue;
			}

			checkTeamed(i);
		}

		cout << n - ct << '\n';
	}

	return 0;
}