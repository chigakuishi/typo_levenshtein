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
  std::map< std::pair<char,char>, int > count;
  std::cin>>n;
  std::cin.get();
  auto dists=ssvtomap("dist.ssv");
  for(int i=0;i<n;i++){
    std::string strf,strt;
    getline(std::cin,strf);
    getline(std::cin,strt);
    DIST dist = lev_map(strf,strt,dists);
    DIST distn = lev_normal(strf,strt);
    std::cout<<"---\n["<<strf<<"]\n"<<"["<<strt<<"]\n"<<" "<<distn.dist<<" "<<dist.dist<<"\n---"<<std::endl; 
  }
  return 0;
}
