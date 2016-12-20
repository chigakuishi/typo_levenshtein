#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include"distance.h"

int main(){
  std::string strf,strt;
  std::cin>>strf>>strt;
  DIST dist = lev_normal(strf,strt);
  std::cout<<dist.dist<<std::endl;
  for(int i=0;i<dist.route.size();i++){
    std::cout << dist.route[i].first << " -> " << dist.route[i].second << std::endl;
  }
  return 0;
}
