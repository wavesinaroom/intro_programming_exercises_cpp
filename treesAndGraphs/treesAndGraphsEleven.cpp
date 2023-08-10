/* Write a program that searches the directory C:\Windows\ and all its subdirectories
 * recursively and prints all the files which have extension *.exe*/

//Can't do it on Linux so I'd better traverse this project folder and print all .cpp files

#include <iostream>
#include <filesystem>


int main (){
  std::filesystem::path path = "../../cppExercises";
  std::string ext(".cpp");
  for(auto const& dir_entry : std::filesystem::recursive_directory_iterator{path}){
    if(dir_entry.path().extension() == ext)
      std::cout<<dir_entry<<'\n';
  }
  return 0;
}
