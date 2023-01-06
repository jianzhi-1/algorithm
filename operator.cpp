struct card {
    int front, back;
    
    card (int _front, int _back){
        front = _front;
        back = _back;
    }
    
    card operator + (const card& other) const {
        return card(front + other.front, back + other.back);
    };
    
    card& operator += (const card& rhs){
        front += rhs.front;
        back += rhs.back;
    }
    
    bool operator == (const card& rhs) const {
        return (front == rhs.front) && (back == rhs.back);
    }
};
