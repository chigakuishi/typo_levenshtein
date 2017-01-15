#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include"distance.h"

char ntos(char c){
  return c?c:' ';
}

int main(){
  int n;
  int all=0;
  int now=0;
  std::map<double,int> cou;
  std::cin>>n;
  std::cin.get();
  auto dists=ssvtomap("dist.ssv");
  for(int i=0;i<n;i++){
    std::string strf,strt;
    getline(std::cin,strf);
    getline(std::cin,strt);
    DIST dist = lev_map(strf,strt,dists,0.1);
    if(dist.dist){
      all++;
      cou[dist.dist/strf.length()]++;
    }
  }
  for(auto it=cou.begin();it!=cou.end();it++){
    now+=it->second;
    std::cout<< it->first << " " << (double)now/all <<std::endl;
  }
  return 0;
}
