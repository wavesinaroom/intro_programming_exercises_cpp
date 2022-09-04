/* 8. Write the previous program so that it changes only the whole words (not parts of the
   word).*/

   #include <iostream>
   #include <fstream>
   #include <string>
   #include <cassert>
   #include <cstddef>
   //TAKEN from https://devdocs.io/cpp/string/basic_string/replace
   std::size_t changeWord(std::string& inout, std::string& what, std::string& with)
   {
     std::size_t count {};
     for (std::string::size_type pos{};
     inout.npos != (pos = inout.find(what.data(), pos, with.length()));
     pos+= with.length(), ++count) {
       inout.replace (pos, what.length(), with.data(), with.length());
     }
     return count;
   }

   int main(int argc, char const *argv[]) {
     /* code */
     return 0;
   }
