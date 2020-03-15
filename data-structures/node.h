template<typename T>
class Node {
    private:
        T data;
        Node *next;
        Node *prev;
    
    public:
        Node(T data){
            this->data = data;
            this->next = this;
            this->prev = this;
        }

        T GetData(){
            return this->data;
        }

        Node* GetPrev(){
            return this->prev;
        }

        Node* GetNext(){
            return this->next;
        }

        void SetPrev(Node *prev){
            this->prev = prev;
        }

        void SetNext(Node *next){
            this->next = next;
        }
};