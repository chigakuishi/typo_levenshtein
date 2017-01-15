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
  std::map< std::pair<std::string,std::string>, bool > his;
  std::string output="";
  int cou=0;
  auto dists=ssvtomap("dist.ssv");
  if(argc==2){
    bdr=atof(argv[1]);
  }

  std::cin>>n;
  std::cin.get();
  for(int i=0;i<n;i++){
    std::string strf,strt;
    getline(std::cin,strf);
    getline(std::cin,strt);
    DIST dist = lev_map(strf,strt,dists,0.1);
    DIST distn = lev_normal(strf,strt);
    if(dist.dist/strf.length() > bdr || bdr==0){
      /*
      for(auto it=dist.route.begin() ; it!=dist.route.end() ; it++){
        if(it->first && it->second){
          count[spair(*it)]++;
        }
      }
      */
      std::cout<<strf<<"\n"<<strt<<"\n"<<dist.dist/strf.length()<<" "<<distn.dist/strf.length()<<"\n---"<<std::endl;
    }else if(! his.count(std::pair<std::string,std::string>(strf,strt))){
      /*
      cou++;
      output+=strf;
      output+="\n";
      output+=strt;
      output+="\n";
      his[std::pair<std::string,std::string>(strf,strt)]=true;
      */
    }
  }
  //std::cout<<cou<<"\n"<<output<<std::flush;
  for(auto it=count.begin() ; it!=count.end() ; it++){
    //std::cout<< it->first.first << " " << it->first.second << " " << it->second << std::endl;
  }
  return 0;
}
