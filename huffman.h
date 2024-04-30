#include <string>
#include <map>
#include <queue>

struct Node;
Node* buildHuffmanTree(const std::string& text);
void generateHuffmanCodes(Node* root, const std::string& code, std::map<char, std::string>& codes);
std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);
