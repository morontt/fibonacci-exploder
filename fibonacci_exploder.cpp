#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int i;
    long ff[46];
    long x;
    long m = 4200;
    float koeff1 = 2.078086921;
    float koeff2 = 1.672275938;
    int nf;
    string line;
    ifstream in_stream;

    ff[0] = 0;
    ff[1] = 1;
    for (i = 2; i < 46; i++) {
        ff[i] = ff[i - 1] + ff[i - 2];
    }

    in_stream.open("input.dat");
    if (in_stream.is_open()) {
        while (getline(in_stream, line)) {
            x = stol(line);
            //cout << x << '\n';
            while (x > 1) {
                if (x > m) {
                    nf = int(koeff2 + koeff1*log(x*1.f));
                    x -= ff[nf];
                } else {
                    for (i = 2; i < 46; i++) {
                        if (ff[i] >= x) {
                            x -= ff[i - 1];
                            break;
                        }
                    }
                }
            }
            //cout << "---------\n";
        }
        in_stream.close();
    }

    return 0;
}
