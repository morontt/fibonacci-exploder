#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int i;
    long ff[46];
    long x;
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
                for (i = 2; i < 46; i++) {
                    if (ff[i] >= x) {
                        x -= ff[i - 1];
                        //cout << ff[i - 1] << '\n';
                        break;
                    }
                }
            }
            //cout << "---------\n";
        }
        in_stream.close();
    }

    return 0;
}
