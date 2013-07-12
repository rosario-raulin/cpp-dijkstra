//
//  BinaryHeap.hpp
//  astar
//
//  Created by Rosario Raulin on 11.07.13.
//  Copyright (c) 2013 Rosario Raulin. All rights reserved.
//

#ifndef astar_BinaryHeap_hpp
#define astar_BinaryHeap_hpp

template <class T, class Compare = std::less<T>>
class BinaryHeap {
private:
    size_t _capacity;
    size_t _size;
    std::unique_ptr<int[]> _pq;
    std::unique_ptr<int[]> _qp;
    std::unique_ptr<T[]> _keys;
    Compare _compare;
    
    bool greater(unsigned int x, unsigned int y) {
        return !_compare(_keys[_pq[x]], _keys[_pq[y]]);
    }
    
    void exch(unsigned int i, unsigned int j) {
        int swap = _pq[i];
        _pq[i] = _pq[j];
        _pq[j] = swap;
        _qp[_pq[i]] = i;
        _qp[_pq[j]] = j;
    }
    
    void swim(unsigned int index) {
        while (index > 1 && greater(index/2, index)) {
            exch(index, index/2);
            index /= 2;
        }
    }
    
    void sink(unsigned int index) {
        while (2*index <= _size) {
            int j = 2*index;
            if (j < _size && greater(j, j+1)) ++j;
            if (!greater(index, j)) break;
            exch(index, j);
            index = j;
        }
    }
    
public:
    BinaryHeap(size_t capacity, Compare compare = Compare()) : _capacity(capacity), _size(0), _pq(new int[capacity+1]), _qp (new int[capacity+1]), _keys(new T[capacity+1]), _compare(compare) {
        for (int i = 0; i <= capacity; ++i) {
            _qp[i] = -1;
        }
    }
    
    ~BinaryHeap() {
        _pq.reset();
        _qp.reset();
        _keys.reset();
    }
    
    T minKey() const {
        return _keys[_pq[1]];
    }
    
    T extractMin() {
        int min = _pq[1];
        exch(1, (unsigned int)_size--);
        sink(1);
        _qp[min] = -1;
        _pq[_size+1] = -1;
        return _keys[min];
    }
    
    void decreaseKey(unsigned int i, T key) {
        _keys[i] = key;
        swim(_qp[i]);
    }
    
    void erase(unsigned int i) {
        unsigned int index = _qp[i];
        exch(index, (unsigned int)_size--);
        swim(index);
        sink(index);
        _qp[i] = -1;
    }
    
    unsigned int insert(T key) {
        unsigned int i = (unsigned int)_size++;
        _qp[i] = (unsigned int)_size;
        _pq[_size] = i;
        _keys[i] = key;
        swim((unsigned int)_size);
        
        return i;
    }
    
    bool contains(unsigned int index) const {
        return _qp[index] != -1;
    }
    
    bool empty() const {
        return _size == 0;
    }
    
    size_t size() const {
        return _size;
    }
};

#endif
