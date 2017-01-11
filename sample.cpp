#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include"distance.h"

int main(){
  while(1){
    std::string strf,strt;
    std::cin>>strf>>strt;
    auto dists=ssvtomap("dist.ssv");
    DIST dist = lev_map(strf,strt,dists,0.1);
    std::cout<<dist.dist<<std::endl;
    for(int i=0;i<dist.route.size();i++){
      std::cout << dist.route[i].first << " -> " << dist.route[i].second << std::endl;
    }
  }
  return 0;
}
