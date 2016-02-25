import threading
from queue import Queue
import time

def exampleJob(worker):
    time.sleep(2.2)
    with print_lock:
        print('Worker: ',worker, ' printed ',threading.current_thread().name)

def threader():
    while True:
        worker = q.get()
        exampleJob(worker)
        q.task_done()

print_lock = threading.Lock()

q = Queue()

for x in range(10):
    t = threading.Thread(target=threader)
    t.daemon = True
    t.start()

start = time.time()

for worker in range(20):
    q.put(worker)

q.join()
print('Entire job took: ', time.time() - start)