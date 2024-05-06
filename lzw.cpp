#include "lzw.h"

std::vector<int> compress(const std::string& text) {
    std::unordered_map<std::string, int> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[std::string(1, static_cast<char>(i))] = i;
    }
    std::string current;
    std::vector<int> compressed;
    for (const char& c : text) {
        std::string currentPlusC = current + c;
        if (dictionary.find(currentPlusC) != dictionary.end()) {
            current = currentPlusC;
        }
        else {
            compressed.push_back(dictionary[current]);
            dictionary[currentPlusC] = dictionary.size();
            current = std::string(1, c);
        }
    }
    if (!current.empty()) {
        compressed.push_back(dictionary[current]);
    }
    return compressed;
}

std::string decompress(const std::vector<int>& compressed) {
    std::unordered_map<int, std::string> dictionary;
    for (int i = 0; i < 256; ++i) {
        dictionary[i] = std::string(1, static_cast<char>(i));
    }
    std::string previous = std::string(1, static_cast<char>(compressed[0]));
    std::string decompressed = previous;
    int count = 256;
    for (int index = 1; index < compressed.size(); ++index) {
        std::string current;
        int currentIndex = compressed[index];
        if (dictionary.find(currentIndex) != dictionary.end()) {
            current = dictionary[currentIndex];
        }
        else if (currentIndex == count) {
            current = previous + previous[0];
        }
        else {
            return "Decompression error: Dictionary does not contain the index";
        }
        decompressed += current;
        if (count < (1 << 16) - 1) {
            dictionary[count] = previous + current[0];
            ++count;
        }
        previous = current;
    }
    return decompressed;
}
