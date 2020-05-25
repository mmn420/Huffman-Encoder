class Node
{
public:
    int frequency;
    char symbol;
    Node *left;
    Node *right;
    Node(char symbol, int frequency, Node *left, Node *right)
    {
        this->frequency = frequency;
        this->symbol = symbol;
        this->left = left;
        this->right = right;
    }
};