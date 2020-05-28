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
    Node(int symbol, int frequency, Node *left, Node *right)
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
    unordered_map<int, string> Encode(unordered_map<int, int> frequencyTable)
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
    private:
    unordered_map <string,int> inverseDict (unordered_map <int,string> dict) // to invert the huffman code hashmap
    {   
        unordered_map<string,int> invDic;
        for (auto &x : dict)
        {
            invDic[x.second] = x.first;
        }
        return invDic;
    }
    public:
    vector<int> Decode (string encodedStream, unordered_map<int,string> Dict) // We save the decoded string in a vector to reverse the compression
    {
        unordered_map<string,int> InvDict = inverseDict(Dict); // To get the inverted codes map
        vector<int> Image; // We will accumulate the original image sequence in this vector
        string Code; // We will use this string for comparisons
         int i =0; 
        while( i<encodedStream.size()) //To operate on all of the encoded string
         {
             Code+= encodedStream[i]
             if (InvDict.count(Code)) //if the string matches one of the codes in the hashmap
             {
             Image.push_back(InvDict[Code]); // We push the original value of the code in the accumulation vector
             Code="";
             i++;
             }
             else
             i++;
        }
    }
};
#endif