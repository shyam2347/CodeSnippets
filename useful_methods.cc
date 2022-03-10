// Method to split the string and return as vector of string based on given delimiter.
std::vector<std::string> customStrSplit(string s, char delimiter = ' ') {
    std::vector<std::string> output;
    std::string temp = "";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == delimiter) {
        output.push_back(temp);
        temp = "";
      } else {
        temp.push_back(s[i]);
      }
    }
    output.push_back(temp);
    return output;
}
