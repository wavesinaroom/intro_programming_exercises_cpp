/* Define classes File{string name, int size} and Folder{string name, File[] files, Folder[] childFolders}. 
 * Using these classes, build a tree that contains all files and directories on your hard disk,
 * starting from /home/. Write a method that calculates the sum of the sizes of files in a sub-tree and a program that tests this method.
 * To crawl directories use recursively crawl deep (DFS)*/

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
class File{
  fs::path path;
  int size;
  public:
    File(const fs::path path){this->path = path;};
};

class Folder{
  fs::path path;
  std::vector<File> files;
  std::vector<Folder> folders;
  public:
    Folder(const fs::path &path){this->path = path;};
    friend void dfs(Folder *folder);

};

void dfs(Folder *folder){

  if(folder==nullptr)
    return;
  for(auto it = fs::directory_iterator(folder->path); it!=fs::directory_iterator(); ++it ){

    fs::file_status s = it->symlink_status();
    fs::is_regular_file(s)?std::cout<<"file"<<'\n':std::cout<<"folder"<<'\n';

    if(fs::is_regular_file(s))
      folder->files.push_back(File(*it));
    else
      folder->folders.push_back(Folder(*it));
  }


}

int main(){
  fs::path test = "/home/wavesinaroom/Documents";

  Folder folder(test);
  dfs(&folder);
  
  return 0;
}
