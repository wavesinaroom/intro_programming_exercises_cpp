/* 7. Write a program that replaces every occurrence of the substring
  "start" with "finish" in a text file. Can you rewrite the program
   to replace whole words only? Does the program work for large
   files (e.g. 800 MB)?*/

   #include <iostream>
   #include <fstream>
   #include <string>

void replaceWord(std::string & input_string, std::string & word_a, std::string & word_b)
{
  for (int i=input_string.length()-word_a.length();  i >=0; --i) {
    if (input_string.substr(i, word_a.length())==word_a) {
      input_string.replace(i, word_a.length(), word_b);

    }
  }
}

int main(int argc, char const *argv[]) {
  std::fstream file_stream_read;
  std::fstream file_stream_write;

  std::string temporal = "Told her she wouldn't be alone again";
  std::string word_a = "her";
  std::string word_b = "#$%&";

  file_stream_read.open("input", std::ios::in);
  file_stream_write.open("output", std::ios::out);

  if (file_stream_read.is_open()) {
    while(std::getline(file_stream_read,temporal))
    {
      if (file_stream_write.is_open()) {
        replaceWord(temporal, word_a, word_b);
        file_stream_write<<temporal<<'\n';
      }
    }
  }
  file_stream_read.close();
  file_stream_write.close();

  return 0;
}
