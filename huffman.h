#include <string>
#include <map>
#include <queue>

struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;
    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
    struct Compare {
        bool operator()(Node* left, Node* right) {
            return left->frequency > right->frequency;
        }
    };
};

Node* buildHuffmanTree(const std::string& text) {
    std::map<char, int> frequencyMap;
    for (char c : text) {
        frequencyMap[c]++;
    }
    std::priority_queue<Node*, std::vector<Node*>, Node::Compare> pq;
    for (const auto& entry : frequencyMap) {
        pq.push(new Node(entry.first, entry.second));
    }
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* newNode = new Node('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    return pq.top();
}

void generateHuffmanCodes(Node* root, const std::string& code, std::map<char, std::string>& codes) {
    if (root->left == nullptr && root->right == nullptr) {
        codes[root->data] = code;
        return;
    }
    generateHuffmanCodes(root->left, code + "0", codes);
    generateHuffmanCodes(root->right, code + "1", codes);
}

std::string encode(const std::string& text);
std::string decode(const std::string& encoded, std::map<char, std::string>& codes);
