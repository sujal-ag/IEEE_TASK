import time
import heapq

class TimeBasedCache:
    def __init__(self):
        self.cache = {}
        self.expiry_heap = []

    def set(self, key, value, expiry_time):
        expiry_timestamp = time.time() + expiry_time
        self.cache[key] = (value, expiry_timestamp)
        heapq.heappush(self.expiry_heap, (expiry_timestamp, key))

    def get(self, key):
        self._cleanup_expired_keys()
        if key in self.cache:
            return self.cache[key][0]
        return None

    def _cleanup_expired_keys(self):
        current_time = time.time()
        while self.expiry_heap and self.expiry_heap[0][0] <= current_time:
            _, expired_key = heapq.heappop(self.expiry_heap)
            if expired_key in self.cache and self.cache[expired_key][1] <= current_time:
                del self.cache[expired_key]

cache = TimeBasedCache()
cache.set("a", 100, 5)
cache.set("b", 200, 2)

time.sleep(3)
print(cache.get("a"))
print(cache.get("b"))
