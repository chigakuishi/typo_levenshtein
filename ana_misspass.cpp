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
  std::map< std::pair<char,char>, int> count;
  std::cin>>n;
  std::cin.get();
  for(int i=0;i<n;i++){
    std::string strf,strt;
    getline(std::cin,strf);
    getline(std::cin,strt);
    DIST dist = lev_normal(strf,strt);
    //std::cout<<dist.dist<<std::endl;
    for(auto it=dist.route.begin() ; it!=dist.route.end() ; it++){
      if(it->first && it->second){
        count[spair(*it)]++;
      }
    }
  }
  for(auto it=count.begin() ; it!=count.end() ; it++){
    std::cout<< it->first.first << " " << it->first.second << " " << it->second << std::endl;
  }
/*
  std::string strf,strt;
  std::cin>>strf>>strt;
  DIST dist = lev_normal(strf,strt);
  std::cout<<dist.dist<<std::endl;
  for(int i=0;i<dist.route.size();i++){
    std::cout << dist.route[i].first << " -> " << dist.route[i].second << std::endl;
  }
*/
  return 0;
}
