# README

## Task 0: Doubly Linked List (DLL)

This implementation includes a proper structure for a Doubly Linked List (DLL), ensuring efficient insertion and deletion from both ends.

### Features:
- Uses a struct to store head and tail pointers.
- Provides functions for insertion, deletion, and traversal.
- Maintains proper bidirectional linking.

### Visualization:
![Doubly Linked List](https://upload.wikimedia.org/wikipedia/commons/5/5e/Doubly-linked-list.svg)

---

## Task 1: Stack Implementation

This stack implementation maintains min and max values efficiently without needing traversal.

### Features:
- Implemented using a struct with an array for elements and two variables for min and max.
- Push operation updates min and max values dynamically.
- Pop operation ensures the correct min and max are maintained.

### Visualization:
![Stack Representation](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)

---

## Task 2: Interval Merger

This program maintains a set of non-overlapping intervals and merges them efficiently when a new interval is added.

### Features:
- Initially considered an array-based approach, but sorting required O(n log n) time, which didn’t meet the problem constraints.
- Implemented using a linked list, achieving O(n) complexity for merging.
- Couldn’t find a further optimized solution to achieve O(log n) complexity.

### Linked List Approach:
- Each node in the linked list represents an interval with `start` and `end` values.
- The list remains sorted while inserting a new interval.
- If the new interval overlaps with existing ones, they are merged by updating the `end` of the relevant node.
- This ensures that the list always maintains non-overlapping, sorted intervals with O(n) complexity.

### Operations:
- **addInterval(start, end):** Adds an interval and merges overlapping ones by traversing the linked list.
- **getIntervals():** Retrieves the merged set of intervals in sorted order.

---

## Task 3: Time-Based Cache

This task involved designing a time-based cache where each key-value pair has an expiration time.

### Features:
- Implemented a dictionary to store key-value pairs with expiry timestamps.
- Used a min-heap to track the earliest expiry times efficiently.
- Periodically removes expired keys to keep memory usage optimal.

### Personal Note:
I was unfamiliar with caching concepts initially. After researching how to implement min-heaps in Python, I applied that knowledge here to manage expirations effectively.

