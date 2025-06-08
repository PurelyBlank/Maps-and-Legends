class LinkedList
{
    struct Node
    {
        int val;
        Node* next;

        Node();
        Node(Node& node);
        Node(int val, Node* next);
        
        Node& operator=(Node& node);

        ~Node();
    };

    Node* head;

public:

    LinkedList();
    LinkedList(LinkedList& ll);

    void insert(Node* node);
    bool find(Node* node);
    void remove(Node* node);

    LinkedList& operator=(LinkedList& ll);

    ~LinkedList();
};
