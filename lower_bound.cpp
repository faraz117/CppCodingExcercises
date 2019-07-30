#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void process_query(std::vector<uint64_t> elements , uint64_t val){
    // print yes with index if the number is present
    auto index = std::lower_bound(elements.begin(), elements.end(),val); 
    // print no with the index of number next smallest number greater than that number
    if(*index == val){
        std::cout << "Yes " << index  - elements.begin() + 1 << std::endl;
    }else{
        std::cout << "No " << index - elements.begin() + 1 << std::endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    uint64_t num_of_elements = 0;
    uint64_t num_of_queries = 0;
    std::vector<uint64_t> elements;
    std::cin >> num_of_elements;
    while ((elements.size() < num_of_elements)){
     uint64_t input;
     std::cin >> input;
     elements.push_back(input);
    }
    std::cin >> num_of_queries;
    while(num_of_queries > 0){
        uint64_t query_val;
        std::cin >> query_val;
        process_query(elements, query_val);
        num_of_queries--;
    }
}
