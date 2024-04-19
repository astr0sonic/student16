#include "kmp.h"

void lps_func(std::string txt, std::vector<int>& Lps) {
    Lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < txt.length()) {
        if (txt[i] == txt[len]) {
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else {
            if (len == 0) {
                Lps[i] = 0;
                i++;
                continue;
            }
            else {
                len = Lps[len - 1];
                continue;
            }
        }
    }
}

std::vector<int> getIndices(const std::string& pattern, const std::string& text) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> Lps(m);
    std::vector<int> result;
    lps_func(pattern, Lps);
    int i = 0, j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            result.push_back(i - m);
            j = Lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j == 0)
                i++;
            else
                j = Lps[j - 1];
        }
    }
    return result;
}
