#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdlib>
#include"distance.h"

char ntos(char c){
  return c?c:' ';
}

int main(int argc,char* argv[]){
  int n;
  double bdr=0;
  std::map< std::pair<char,char>, int > count;

  if(argc==2){
    bdr=atof(argv[1]);
  }

  std::cin>>n;
  std::cin.get();
  for(int i=0;i<n;i++){
    std::string strf,strt;
    getline(std::cin,strf);
    getline(std::cin,strt);
    DIST dist = lev_normal(strf,strt);
    if(dist.dist/strf.length()<bdr || bdr==0){
      for(auto it=dist.route.begin() ; it!=dist.route.end() ; it++){
        if(it->first && it->second){
          count[spair(*it)]++;
        }
      }
    }
  }
  for(auto it=count.begin() ; it!=count.end() ; it++){
    std::cout<< it->first.first << " " << it->first.second << " " << it->second << std::endl;
  }
  return 0;
}
