/* Define classes File{string name, int size} and Folder{string name, File[] files, Folder[] childFolders}. 
 * Using these classes, build a tree that contains all files and directories on your hard disk,
 * starting from /home/. Write a method that calculates the sum of the sizes of files in a sub-tree and a program that tests this method.
 * To crawl directories use recursively crawl deep (DFS)*/

#include <iostream>
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
class File{


  fs::path path;
  std::uintmax_t size;
  public:
    inline static std::uintmax_t files_size = 0;

    File(const fs::path &path, std::uintmax_t size){
      this->path = path;
      this->size = size;
    };
    static void addFilesSize(std::vector<File> &files){
      for(auto const & file: files){
        File::files_size += file.size;
      }
    }
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

    if(fs::is_regular_file(s))
      folder->files.push_back(File(*it, fs::file_size((*it))));
    else
      folder->folders.push_back(Folder(*it));
  }

  File::addFilesSize(folder->files);

  for(std::vector<Folder>::iterator f = folder->folders.begin(); f!=folder->folders.end(); ++f){
    dfs(&(*f));
  }
}

int main(){
  fs::path test = "/home/wavesinaroom/Documents/cppExercises";

  Folder folder(test);
  dfs(&folder);
  
  std::cout<<File::files_size<<'\n';
  return 0;
}
