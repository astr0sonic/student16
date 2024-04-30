#include "huffman.h"

std::string encode(const std::string& text) {
    std::string encoded = "";
    Node* root = buildHuffmanTree(text);
    std::map<char, std::string> codes;
    generateHuffmanCodes(root, "", codes);
    for (char c : text) {
        encoded += codes[c];
    }
    return encoded;
}

std::string decode(const std::string& encoded, std::map<char, std::string>& codes) {
    std::string decoded = "";
    std::string currentCode = "";
    for (char bit : encoded) {
        currentCode += bit;
        for (const auto& entry : codes) {
            if (entry.second == currentCode) {
                decoded += entry.first;
                currentCode = "";
                break;
            }
        }
    }
    return decoded;
}
