#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <array>


void part_one(std::string file_path,size_t sz){

    int gamma_ones[sz] = {0};
    int gamma_zero[sz] = {0};
    int gamma[sz] = {0};
    auto f = std::ifstream(file_path);
    for(std::string s;std::getline(f,s);){
        std::cout << s.size() << "\n";
        for(int i = 0;i < sz;i++) {
            if((int) s[i] == '1') gamma_ones[i] += 1;
            else gamma_zero[i] += 1;
        }
    }

    for(int i =0 ;i<sz;i++){
        if(gamma_ones[i] > gamma_zero[i]) gamma[i] = 1;
    }


    int gam = 0,j = 0,eps = 0;

    for(auto i : gamma){
        gam += (i << ((sz - 1) -j)) ;
        j++;
    }
    j = 0;
    for(auto i : gamma){
        eps += ((i ^ 1) << ((sz - 1) -j)) ;
        j++;
    }

    std::cout << gam << "\n";
    std::cout << eps << "\n";
    std::cout << gam * eps ;
}

int check_parity(std::vector<std::vector<int>>& all,size_t pos,size_t sz){
    int parity = 0;
    int ones = 0,zeros = 0;
    for(int i =0;i < sz;i++){
        if(all[i][pos] == 1) ones++;
        else zeros++;
    }
    //std::cout << "ones : " << ones << "\t";
    //std::cout << "zeros: " << zeros << "\n";
    if(zeros > ones) return 0;
    return 1;
}

void check_recurse(std::vector<std::vector<int>>& vec, size_t pos,bool checker,int cnt,int* res){

    size_t sz = vec.size();

    if(pos > sz) {
        std::cout << "ERROR " << "\n";
        return;
    }

    int par = check_parity(vec,pos,cnt);

    if(!checker){
        par ^= 1;
    }

    size_t cur = 0,cursor=0;

    if(cnt == 1){
        size_t sz2 = vec[0].size();
        int gam = 0,j = 0;
        for(auto i : vec[0]){
            gam += i << ((sz2 - 1) - j) ;
            j++;
        }
        std::cout << gam << "\n";
        *res = gam;
        return;
    }


    while(cur < cnt){

        if(vec[cur][pos] == par){
            std::swap(vec[cursor],vec[cur]);
            cursor++;
        }
        cur++;
    }


    check_recurse(vec,pos+1,checker,cursor,res);
}

void part_two(std::string file_path,const size_t sz) {

    std::vector<std::vector<int>> all_nums;
    auto f = std::ifstream(file_path);

    for(std::string s;std::getline(f,s);){
        std::vector<int> temp(sz);
        int j = 0;
        for(auto c : s){
            temp[j] = (int) (c - '0');
            j++;
        }
        all_nums.push_back(temp);
        temp.clear();
    }

    //std::cout << all_nums.size() << "\n";
    int ox,cb;
    check_recurse(all_nums,0,true,all_nums.size(),&ox);
    check_recurse(all_nums,0,false,all_nums.size(),&cb);

    std::cout << "answer for part 2 " << ox * cb ;
}

int main(){
    part_two("input.txt",12);
}
