#ifndef TinyQueue_h
#define TinyQueue_h


#ifndef TINYQUEUE_SIZE
// 50 ints
#define TINYQUEUE_SIZE 50
#endif

template <class T> 
class TinyQueue {
  public:
    TinyQueue();
    void reset();
    void enqueue(const T value);
    T dequeue();
    // void dump(Print & printer);
    bool isEmpty();
    int count();
	T sum();
	T mean();
	T maximum();
	
  private:
    int _head, _tail, _count;
    T _sum;
    T _queue[TINYQUEUE_SIZE + 1];
}; // class TinyQueue




// helper function --- increment an index, wrap if needed
int increment(const int index) {
    int ret = index + 1;
    if (ret >= TINYQUEUE_SIZE) {
        return 0;
    } else {
        return ret;
    }
} // increment


// constructor
template <class T>
TinyQueue<T>::TinyQueue() {
  reset();
} // TinyQueue<T>()


// reset the Queue to "empty"
template <typename T>
void TinyQueue<T>::reset() {
  _head = _tail = _sum = _count = 0;
} // TinyQueue::reset()


/*
 * enqueue(value) to the front of the queue
 *
 * silently ejects the last element if the queue is full
 */
template <class T>
void TinyQueue<T>::enqueue(const T value) {
  _queue[_tail] = value;
  _sum += value;
  _tail = increment(_tail);
  _count += 1;
  if (_tail == _head) {
        // silent discard, but track the sum
        _sum -= _queue[_head];
        _head = increment(_head);
        _count -= 1;
  }
} // TinyQueue::enqueue(value)


/*
 * take a value from the end of the queue
 *
 * returns -1 if the queue is empty.
 */
template <class T> 
T TinyQueue<T>::dequeue() {
  T value;
  if (! isEmpty()) {
    value = _queue[_head];
    _head = increment(_head);
    _sum -= value;
    _count -= 1;
    return value;
  } else {
    return (T)-1;
  }
} // int TinyQueue::dequeue()


// returns true if the queue isEmpty
template <typename T>
bool TinyQueue<T>::isEmpty() {
  return _head == _tail;
} // boolean TinyQueue::isEmpty()


template <class T> 
int TinyQueue<T>::count() {
    return _count;
}


template <class T> 
T TinyQueue<T>::sum() {
  return _sum;
} // T TinyQueue::sum()


template <class T> 
T TinyQueue<T>::mean() {
    return sum() / count();
}


template <class T>
T TinyQueue<T>::maximum() {
    T ret = _queue[_head];
    int cnt = 0, i = _head;
    
    for (i = _head; i != _tail; i = increment(i)) {
        ret = max(ret, _queue[i]);
    }
    return ret;
} // T TinyQueue::maximum()


#endif
