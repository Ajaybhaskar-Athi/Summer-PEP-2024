#include <bits/stdc++.h>
using namespace std;

vector<int> countPrimes(int maxNum) {
    if (maxNum <= 1) return {};

    vector<int> isPrime(maxNum + 1, 1); // initialize all as prime
    isPrime[0] = isPrime[1] = 0; // 0 and 1 are not primes

    for (int i = 2; i * i <= maxNum; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= maxNum; j += i) {
                isPrime[j] = 0; // mark multiples of i as not prime
            }
        }
    }

    vector<int> primesCount(maxNum + 1, 0);
    int count = 0;
    for (int i = 0; i <= maxNum; i++) {
        if (isPrime[i]) {
            count++;
        }
        primesCount[i] = count;
    }

    return primesCount;
}

int main() {
    int T;
    cin >> T;

    vector<int> inputs(T);
    int maxN = 0;
    for (int i = 0; i < T; i++) {
        cin >> inputs[i];
        maxN = max(maxN, inputs[i]);
    }

    vector<int> primesCount = countPrimes(maxN);

    for (int i = 0; i < T; i++) {
        cout << primesCount[inputs[i]] << endl;
    }

    return 0;
}
