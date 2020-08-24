
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cmath>

std::unordered_map<int, bool> cash;

bool prime(int n){
    auto got = cash.find(n); 
    if (cash.find(n) != cash.end()) 
        return got->second;

	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
            cash[n] = false;
			return false;
        }
    }
    cash[n] = true;
	return true;
}

int f(int n) {
    //std::cerr << "in: " << n <<std::endl;
    if (prime(n)) {
        //std::cerr << "rt:  1(p)" <<std::endl;
        return 1;
    }

    std::vector<int> res;
    for (int i = 2; i <= n/2; i++) {
        //std::cerr << "div: " << i << " " << n-i <<std::endl;
        res.push_back(f(i) + f(n - i));
    }

    auto resp = std::min_element(res.begin(), res.end()); 
    //std::cerr << "rt: " << *resp <<std::endl;
    return *resp;
}

int main(int argc, char** argv) {
    int x = 0;
    std::cin >> x;

    std::cout << f(x) << std::endl;
}