#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>

void part_one(std::string file_path){
    auto f = std::ifstream(file_path);
    int prev = -1,cur = 0,res=0;
    for(std::string s;std::getline(f,s);){
        cur = atoi(s.c_str());
        if(prev < 0) {
            prev = cur;
            continue;
        }
        if(cur > prev) res++;
        prev = cur;
    }

    std::cout << res;
}

int get_avg(std::vector<int>& ms,int index){
    if(index + 2 > ms.size() - 1){
        return -1;
    }
    return ms[index] + ms[index+1] + ms[index+2];
}

void part_two(std::string file_path){
    auto f = std::ifstream(file_path);
    std::vector<int> measures;
    for(std::string s;std::getline(f,s);){
        measures.push_back(atoi(s.c_str()));
    }
    int cur=0,prev=-1,res = 0,index=0;

    while(true){
        cur = get_avg(measures,index);
        if(cur == -1){
            break;
        }
        if(prev < 0){
            prev = cur;
            index++;
            continue;
        }
        if(cur > prev){
            printf("%d : %d \n",index,cur);
            res++;
        }
        prev = cur;
        index++;
    }

    std::cout << res;
}

int main() {
    part_two("input.txt");
}
