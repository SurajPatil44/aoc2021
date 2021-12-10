#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <string_view>

using string_pair = std::pair<std::string_view,std::string_view> ;

string_pair partition(std::string_view target,std::string_view sep){

    auto piv = target.find(sep);

    std::string_view first {target.data(),piv};

    std::string_view second {target.data()+piv+sep.size()};

    return std::make_pair(first,second);
}



void part_one(std::string file_path){
    auto f = std::ifstream(file_path);
    int pos = 0,depth = 0;
    for(std::string s;std::getline(f,s);){
        auto p = partition(s," ");
        if (strncmp(p.first.data(),"forward",7) == 0) {
            pos += atoi(p.second.data());
        } else if (strncmp(p.first.data(),"down",4) == 0){
            depth += atoi(p.second.data());
        } else if (strncmp(p.first.data(),"up",2) == 0){
            depth -= atoi(p.second.data());
        } else {
            std::cout << "ERRRRRO" << p.first << "\n";
        }
    }

    std::cout << "depth : " << depth <<"\n";
    std::cout << "pos : "   << pos << "\n";

    std::cout << depth*pos;
}


void part_two(std::string file_path){
    auto f = std::ifstream(file_path);
    int aim = 0,pos = 0,depth = 0;
    for(std::string s;std::getline(f,s);){
        auto p = partition(s," ");
        auto num = atoi(p.second.data());
;
        if (strncmp(p.first.data(),"forward",7) == 0) {
            pos += num;
            depth += (aim * num);
        } else if (strncmp(p.first.data(),"down",4) == 0){
            //depth += num;
            aim += num;
        } else if (strncmp(p.first.data(),"up",2) == 0){
            //depth -= num;
            aim -= num;
        } else {
            std::cout << "ERRRRRO" << p.first << "\n";
        }
        std::cout << "depth : " << depth << "\t";
        std::cout << "pos   : " << pos << "\t";
        std::cout << "aim   : " << aim << "\n";
    }

    std::cout << "depth : " << depth <<"\n";
    std::cout << "pos : "   << pos << "\n";

    std::cout << depth*pos;
}

int main(){
    part_two("input.txt");
}
