#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdio>
struct DIST{
  public:
    double dist;
    std::vector< std::pair<char,char> > route;
      //first: char_from, second: char_to
};

enum method{
  EMP, //Empty
  DEL, //Delete
  INS, //Insert
  MAT, //Match
  REP  //Replace
};

std::pair<double,int> min3(double n0,double n1,double n2){ //{{{
  std::pair<double,int> ret;
  if(n0 < n1){
    if(n0 < n2){
      ret.first = n0;
      ret.second = 0;
    }else{
      ret.first = n2;
      ret.second = 2;
    }
  }else{
    if(n1 < n2){
      ret.first = n1;
      ret.second = 1;
    }else{
      ret.first = n2;
      ret.second = 2;
    }
  }

  return ret;
} //}}}
std::pair<char,char> spair(char c1,char c2){
  return c1 < c2?
    std::pair<char,char>(c1,c2):
    std::pair<char,char>(c2,c1);
}
std::pair<char,char> spair(std::pair<char,char> cp){
  return spair(cp.first,cp.second);
}
std::map< std::pair<char, char>, double > ssvtomap(std::string fname){
  FILE *fp;
  char a,b;
  double d;
  std::map< std::pair<char, char>, double > ret;
  fp=fopen(fname.c_str(),"r");
  while(fscanf(fp,"%c %c %lf\n",&a,&b,&d) != EOF){
    ret[spair(a,b)]=d;
  }
  fclose(fp);
  return ret;
}


DIST lev_map(std::string strf, std::string strt, std::map< std::pair<char, char>, double > distlist){
  DIST ret;
  const unsigned int flen = strf.length();
  const unsigned int tlen = strt.length();
  std::vector< std::vector<double> > dp(flen+1, std::vector<double>(tlen+1, 0) );
  std::vector< std::vector<method> > memo(flen+1, std::vector<method>(tlen+1, EMP));
  
  for(int i=1;i<=flen;i++){
    dp[i][0]=i;
    memo[i][0]=DEL;
  }

  for(int i=1;i<=tlen;i++){
    dp[0][i]=i;
    memo[0][i]=INS;
  }

  //TODO : multi route
  for(int i=1;i<=flen;i++){
    for(int ii=1;ii<=tlen;ii++){
      double rcost=1;
      if(strf[i-1] == strt[ii-1]){
        dp[i][ii] = dp[i-1][ii-1];
        memo[i][ii] = MAT;
        continue;
      }
      if(distlist[spair(strf[i-1], strt[ii-1])]){
        rcost=distlist[spair(strf[i-1], strt[ii-1])];
      }
      std::pair<double,int> min = min3(
        dp[i-1][ii-1] + rcost,  //REP
        dp[i][ii-1] + 1,    //INS
        dp[i-1][ii] + 1     //DEL
      );
      dp[i][ii] = min.first;
      switch(min.second){
        case 0:
          memo[i][ii] = REP;
        break;
        case 1:
          memo[i][ii] = INS;
        break;
        case 2:
          memo[i][ii] = DEL;
        break;
      }
    }
  }
  int pf=flen;
  int pt=tlen;
  do{
    if(memo[pf][pt]==DEL){
      ret.route.push_back( std::pair<char,char>(strf[pf-1],'\0') );
      pf--;
    }else if(memo[pf][pt]==INS){
      ret.route.push_back( std::pair<char,char>('\0',strt[pt-1]) );
      pt--;
    }else if(memo[pf][pt]==REP){
      ret.route.push_back( std::pair<char,char>(strf[pf-1], strt[pt-1]) );
      pf--;
      pt--;
    }else{
      ret.route.push_back( std::pair<char,char>('\0','\0') );
      pf--;
      pt--;
    }
  }while(pf != 0 || pt != 0);
  std::reverse( ret.route.begin(), ret.route.end() );
  ret.dist = dp[flen][tlen];

  return ret;
}

DIST lev_normal(std::string strf, std::string strt){
  return lev_map(strf,strt,std::map< std::pair<char,char>, double >());
}

