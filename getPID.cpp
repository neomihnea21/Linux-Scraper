#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<string> 
std::vector<int> v; 
///sa fi facut class Proces?
void getDescDFS(int pid){
    std::string path="/proc/" + std::to_string(pid) + "/task/"+ std::to_string(pid) + "/children";
    std::ifstream fin(path);
    v.push_back(pid);
    if(fin.is_open()){
        std::string kids;
        std::getline(fin, kids);
        std::istringstream iss(kids);
        int temp;
        while(iss>>temp){
           getDescDFS(temp);
        }
    }
}
char getStatus(int pid){
     std::string url="/proc/" + std::to_string(pid) + "/status";
     ifstream fin(path);
     if(fin.is_open()){
         std::string state; 
         for(int i=0; i<3; i++)
           std::getline(fin, state);///ca sa fie a treia linie
         return state[8];
     }
     return 'N'; ///nu o sa se ajunga vreodata aici, dar altfel e warning
}
int getCPU(int pid){
  std::string url="/proc/" + std::to_string(pid) + "memory";
  ifstream fin(path);
  if(fin.is_open()){
    
  }
}
int main(){
      int proc; std::cin>>proc;
      getDescDFS(proc);
      for(int i=0; i<v.size(); i++){
        std::cout<<v[i]<<" "<<getStatus(v[i])<<"\n";
      }
      return 0;
}