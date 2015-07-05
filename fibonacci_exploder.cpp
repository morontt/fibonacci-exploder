#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sys/time.h>
#include <thread>

#define DATA_SIZE 10000000
#define NUM_THREADS 4

using namespace std;

long ff[46];
long data_arr[DATA_SIZE];

void compute(int delta) {
    int i;
    long x, idx;
    long m = 4200;
    float koeff1 = 2.078086921;
    float koeff2 = 1.672275938;
    int nf;

    for (idx = delta; idx < DATA_SIZE; idx += NUM_THREADS) {
        x = data_arr[idx];
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
}

double get_ms() {
    struct timeval tim;

    gettimeofday(&tim, NULL);
    return (double)tim.tv_sec + ((double)tim.tv_usec / 1000000.0);
}

int main() {
    double start, end;
    long idx;
    int i;
    string line;
    ifstream in_stream;
    thread threads[NUM_THREADS];

    start = get_ms();

    ff[0] = 0;
    ff[1] = 1;
    for (i = 2; i < 46; i++) {
        ff[i] = ff[i - 1] + ff[i - 2];
    }

    in_stream.open("input.dat");
    idx = 0;
    if (in_stream.is_open()) {
        while (getline(in_stream, line)) {
            data_arr[idx] = stol(line);
            idx++;
        }
        in_stream.close();
    }

    end = get_ms();
    cout << "file reading:\t" << (end - start) << endl;

    start = get_ms();
    for (i = 0; i < NUM_THREADS; i++) {
        threads[i] = thread(compute, i);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }
    end = get_ms();

    cout << "compute:\t" << (end - start) << endl;
    return 0;
}
