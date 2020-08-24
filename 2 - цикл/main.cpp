
#include <iostream>
#include <vector>
#include <set>
   
int main(int argc, char** argv) {
    int n = 0; // элементов в перестановке
    std::cin >> n;
    std::set<int> len;

    std::vector<int> p;
    p.reserve(n);
    int x = 0;
    for (int i = 0; i != n; i++) {
        std::cin >> x;
        x--;
        p.push_back(x);
    }
    
    std::vector<bool> used(n);             // массив, где отмечены посещенные позиции

    for (int i = 1; i != n; i++) {
        if (!used[i]) {
            int j = i;
            std::vector<int> cycle;

            while(!used[j]) {
                cycle.push_back(p[j]);
                used[j] = true;
                j = p[j];
            }
        len.insert(cycle.size());
        }     
    }

    int sum = 0;
    for (int i : len) {
        sum += i;
    }
    std::cout << sum << std::endl;

}