#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Coord {
public:
    int x;
    int y;
    int z;
    Coord() {
        x = 0;
        y = 0;
        z = 0;
    }
    ~Coord() {}
};

int main() {
    int n;
    cin >> n;

    vector<Coord> cs(n, Coord());

    for (int i = 0; i < n; i++) {
        cin >> cs[i].x >> cs[i].y >> cs[i].z;
    }

    sort(cs.begin(), cs.end(), [](const Coord& a, const Coord& b){
        return a.z < b.z;
    });

    double sum = 0.0;
    for (int i = 1; i < n; i++) {
        int dx = cs[i].x - cs[i-1].x;
        int dy = cs[i].y - cs[i-1].y;
        int dz = cs[i].z - cs[i-1].z;
        sum += sqrt(dx * dx + dy * dy + dz * dz);
    }
    
    printf("%.3f\n", sum); // cout 好像不太能用，或者好像可以用 fprintf

    return 0;
}

/*
P5143 攀爬者
普及-

ORDEY BY z

Check 1: 10AC

MetaMiku 20250926 21:40
*/