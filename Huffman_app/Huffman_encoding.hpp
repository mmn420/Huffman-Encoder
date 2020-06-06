#ifndef HUFFMAN_ENCODING
#define HUFFMAN_ENCODING
#include <bits/stdc++.h>

class Node
{
public:
    int frequency;
    int symbol;
    Node *left;
    Node *right;
    Node(int symbol // symbol of the node
    ,
        int frequency // frequency of the symbol
        ,
         Node *left //left child
         ,
          Node *right //right child
          )
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
    unordered_map<int, string> codes; //to store the codes of all elements
    void TraverseTree(Node *head, string code) //recursive function to traverse the tree to get the codes
    std::unordered_map<int, std::string> codes;
    void TraverseTree(Node *head, std::string code) //recursive function to traverse the tree to get the codes
    {
        if (head == nullptr) //if the tree is empty
            return;

        if (head->left != nullptr) //if the node has left child
            TraverseTree(head->left, code + "0"); //call the recursive function and increase 0 to its code

        if (head->right != nullptr) //if the node has right child
            TraverseTree(head->right, code + "1"); //call the recursive function and increase 1 to the code

        if (head->left == nullptr && head->right == nullptr) //if the node is a leaf
            codes[head->symbol] = code; //push the code of the node in codes
    }
    std::unordered_map<std::string, int> inverseDict(const std::unordered_map<int, std::string> &dict) // to invert the huffman code hashmap
    {
        std::unordered_map<std::string, int> invDic;
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
    std::unordered_map<int, std::string> Encode(const std::unordered_map<int, int> &frequencyTable)
    {
<<<<<<< HEAD
        //1-push all elements in the priority queue
        priority_queue<Node *, vector<Node *>, PriorityQueueComparator> Nodes;

        for (auto &x : frequencyTable) // to iterate on all frequencies in the frequency map
        {
            auto temp = new Node(x.first, x.second, nullptr, nullptr);
            Nodes.push(temp);
        }
        //2-pop the smallest two elements in freq., merge them together then push them back to the queue 
=======
        std::priority_queue<Node *, std::vector<Node *>, PriorityQueueComparator> Nodes;

        for (auto &[frequency, symbol] : frequencyTable)
            Nodes.emplace(new Node(frequency, symbol, nullptr, nullptr));

>>>>>>> 55958fd359d5d48884c3b4f2ae694cc06874c709
        while (Nodes.size() > 1) //while the queue contains more than one node
        {
            auto min1 = Nodes.top(); //to store the first small frequency
            Nodes.pop();             //to remove this element from the queue
            auto min2 = Nodes.top(); //to store the second small frequency
            Nodes.pop();
            //make new node and let the two elements with the smallest frequencies be the children of this node and its frequency is the sum of the frequencies of the children
            Nodes.emplace(new Node(256, min1->frequency + min2->frequency, min1, min2)); //insert the new node in the queue
        }

        auto headNode = Nodes.top(); //the last node that remains in the queue will be the head of the tree
        Nodes.pop();
<<<<<<< HEAD
        //3-get the codes
=======
>>>>>>> 55958fd359d5d48884c3b4f2ae694cc06874c709
        TraverseTree(headNode, "");

        return codes;
    }

    std::vector<int> Decode(std::string encodedStream, const std::unordered_map<int, int> &frequencytable) // We save the decoded string in a vector to reverse the compression
    {
        std::unordered_map<int, std::string> Dict = Encode(frequencytable); //building huffman tree
        std::unordered_map<std::string, int> InvDict = inverseDict(Dict);   // To get the inverted codes map
        std::vector<int> Image;                                             // We will accumulate the original image sequence in this vector
        std::string Code;                                                   // We will use this string for comparisons
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