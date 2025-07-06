def check_log(logs):
    held = set()       # Currently held locks
    stack = []         # Order of lock acquisition
    
    for i, line in enumerate(logs):
        parts = line.split()
        action, lock = parts[0], int(parts[1])
        
        if action == "ACQUIRE":
            if lock in held:
                return i + 1  # Error: trying to acquire already held lock
            held.add(lock)
            stack.append(lock)
        
        elif action == "RELEASE":
            if lock not in held:
                return i + 1  # Error: releasing lock that was never acquired
            
            if not stack or stack[-1] != lock:
                return i + 1  # Error: releasing out of order
            held.remove(lock)
            stack.pop()
    
    if held:
        return len(logs) + 1  # Locks still held at termination
    
    return 0  # No issues
log1 = [
    "ACQUIRE 364",
    "ACQUIRE 84",
    "RELEASE 84",
    "RELEASE 364"
]
print(check_log(log1))  # Output: 0
log2 = [
    "ACQUIRE 364",
    "ACQUIRE 84",
    "RELEASE 364",
    "RELEASE 84"
]
print(check_log(log2))  # Output: 3
log3 = [
    "ACQUIRE 364",
    "ACQUIRE 84",
    "ACQUIRE 364",
    "RELEASE 364"
]
print(check_log(log3))  # Output: 3
log4 = [
    "ACQUIRE 364",
    "RELEASE 84",
    "RELEASE 364"
]
print(check_log(log4))  # Output: 2
log5 = [
    "ACQUIRE 123",
    "ACQUIRE 364",
    "ACQUIRE 84",
    "RELEASE 84",
    "RELEASE 364",
    "ACQUIRE 456"
]
print(check_log(log5))  # Output: 7 (456 and 123 are still held)

