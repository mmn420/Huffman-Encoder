#ifndef HUFFMAN_ENCODING
#define HUFFMAN_ENCODING
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int frequency;
    int symbol;
    Node *left;
    Node *right;
    Node(int symbol, int frequency, Node *left, Node *right) //constructor
    {
        this->frequency = frequency;
        this->symbol = symbol;
        this->left = left;
        this->right = right;
    }
};
class Huffman
{
private:
    unordered_map<int, string> codes;
    void TraverseTree(Node *head, string code) //recursive function to traverse the tree to get the codes
    {
        if (head == nullptr) //if the tree is empty
            return;

        if (head->left != nullptr) //if the node has left child
            TraverseTree(head->left, code + "0");

        if (head->right != nullptr) //if the node has right child
            TraverseTree(head->right, code + "1");

        if (head->left == nullptr && head->right == nullptr)
            codes[head->symbol] = code;
    }
    unordered_map<string, int> inverseDict(unordered_map<int, string> dict) // to invert the huffman code hashmap
    {
        unordered_map<string, int> invDic;
        for (auto &x : dict)
        {
            invDic[x.second] = x.first;
        }
        return invDic;
    }

    struct PriorityQueueComparator
    {
        bool operator()(Node *const &p1, Node *const &p2)
        {
            return p1->frequency > p2->frequency; //to compare between frequencies
        }
    };

public:
    unordered_map<int, string> Encode(unordered_map<int, int> frequencyTable)
    {
        priority_queue<Node *, vector<Node *>, PriorityQueueComparator> Nodes;

        for (auto x : frequencyTable)
        {
            if(x.second!=0)
            {
            auto temp = new Node(x.first, x.second, nullptr, nullptr);
            Nodes.push(temp);
            }
        }

        while (Nodes.size() > 1) //while the queue contains more than one node
        {
            auto min1 = Nodes.top(); //to store the first small frequency
            Nodes.pop();             //to remove this element from the queue
            auto min2 = Nodes.top(); //to store the second small frequency
            Nodes.pop();
            auto NewNode = new Node(256, min1->frequency + min2->frequency, min1, min2); //make new node and let the two elements with the smallest frequencies be the children of this node and its frequency is the sum of the frequencies of the children
            Nodes.push(NewNode);                                                         //insert the new node in the queue
        }

        auto headNode = Nodes.top(); //the last node that remains in the queue will be the head of the tree
        Nodes.pop();
        TraverseTree(headNode, "");

        return codes;
    }

    vector<int> Decode(string encodedStream, unordered_map<int, int> frequencytable) // We save the decoded string in a vector to reverse the compression
    {
        unordered_map<int, string> Dict = Encode(frequencytable); //building huffman tree
        unordered_map<string, int> InvDict = inverseDict(Dict);   // To get the inverted codes map
        vector<int> Image;                                        // We will accumulate the original image sequence in this vector
        string Code;                                              // We will use this string for comparisons
        int i = 0;
        while (i < encodedStream.size()) //To operate on all of the encoded string
        {
            Code += encodedStream[i];
            if (InvDict.count(Code)) //if the string matches one of the codes in the hashmap
            {
                Image.push_back(InvDict[Code]); // We push the original value of the code in the accumulation vector
                Code = "";
            }
            i++;
        }
        return Image;
    }
};
#endif