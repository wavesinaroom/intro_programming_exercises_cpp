/* Define classes File{string name, int size} and Folder{string name, File[] files, Folder[] childFolders}. 
 * Using these classes, build a tree that contains all files and directories on your hard disk,
 * starting from /home/. Write a method that calculates the sum of the sizes of files in a sub-tree and a program that tests this method.
 * To crawl directories use recursively crawl deep (DFS)*/

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

class File{
  std::filesystem::path path;
  int size;
  public:
    File(){};
};

class Folder{
  std::filesystem::path path;
  std::vector<File> files;
  std::vector<Folder> folders;
  public:
    Folder(const std::filesystem::path &path){this->path = path;};
    void dfs(Folder & folder){
      std::filesystem::directory_iterator file_iterator{folder.path};
      std::filesystem::file_status s = file_iterator->symlink_status();

      std::filesystem::is_regular_file(s)?std::cout<<"file"<<'\n':std::cout<<"folder"<<'\n';
    }

};

int main(){
  std::filesystem::path test = "../../cppExercises";

  Folder folder(test);
  folder.dfs(folder);
  
  return 0;
}
