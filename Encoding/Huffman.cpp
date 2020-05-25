#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
#include "node.cpp"
using namespace std;

class Huffman
{
private:
    unordered_map<char, string> codes;
    void TraverseTree(Node *head, string code)
    {
        if (head == nullptr)
            return;

        if (head->left != nullptr)
            TraverseTree(head->left, code + "0");

        if (head->right != nullptr)
            TraverseTree(head->right, code + "1");

        if (head->left == nullptr && head->right == nullptr)
            codes[head->symbol] = code;
    }

    struct PriorityQueueComparator
    {
        bool operator()(Node *const &p1, Node *const &p2)
        {
            return p1->frequency > p2->frequency;
        }
    };

public:
    unordered_map<char, string> Encode(unordered_map<char, int> frequencyTable)
    {
        priority_queue<Node *, vector<Node *>, PriorityQueueComparator> Nodes;

        for (auto &x : frequencyTable)
        {
            auto temp = new Node(x.first, x.second, nullptr, nullptr);
            Nodes.push(temp);
        }

        while (Nodes.size() > 1)
        {
            auto min1 = Nodes.top();
            Nodes.pop();
            auto min2 = Nodes.top();
            Nodes.pop();
            auto NewNode = new Node(0, min1->frequency + min2->frequency, min1, min2);
            Nodes.push(NewNode);
        }

        auto headNode = Nodes.top();
        Nodes.pop();

        TraverseTree(headNode, "0");

        return codes;
    }
};