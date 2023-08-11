/* Define classes File{string name, int size} and Folder{string name, File[] files, Folder[] childFolders}. 
 * Using these classes, build a tree that contains all files and directories on your hard disk,
 * starting from /home/. Write a method that calculates the sum of the sizes of files in a sub-tree and a program that tests this method.
 * To crawl directories use recursively crawl deep (DFS)*/

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

class File{
  std::string name;
  int size;
};

class Folder{
  std::string name;
  std::vector<File> files;
  std::vector<Folder> folders;
};
