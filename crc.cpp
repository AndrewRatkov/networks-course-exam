#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define CHECK 1
using namespace std;


int main() {
	string d, g; cin >> d >> g;
	vector<bool> D(d.size()), G(g.size()), crc(d.size() + g.size() - 1);

	for (int i = 0; i < d.size(); ++i) D[i] = (d[i] == '1');
	for (int i = 0; i < g.size(); ++i) G[i] = (g[i] == '1');
	
	for (int i = 0; i < d.size(); ++i) crc[i] = D[i];
	
	for (int i = 0; i < d.size(); ++i) {
		if (crc[i]) {
			for (int j = 0; j < g.size(); ++j) {
				crc[i + j] = crc[i + j] ^ G[j];
			}
		}
	}

	for (int i = 0; i < d.size(); ++i) crc[i] = D[i];
	cout << "crc: "; for (int i = 0; i < crc.size(); ++i) cout << (crc[i] ? '1' : '0'); cout << endl;

#if CHECK
	for (int i = 0; i < d.size(); ++i) {
		if (crc[i]) {
			for (int j = 0; j < g.size(); ++j) {
				crc[i + j] = crc[i + j] ^ G[j];
			}
		}
	}

	cout << ((bool)std::all_of(crc.begin(), crc.end(), [](int i) { return i == 0; }) ? "Divised correctly\n" : "Some errors\n");
#endif

	return 0;
}
