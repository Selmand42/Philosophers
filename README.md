# Philosophers

A multithreaded implementation of the classic **Dining Philosophers Problem** in C, designed to demonstrate and practice concurrent programming concepts including thread synchronization, deadlock prevention, and race condition handling.

## 📖 About the Project

The Dining Philosophers Problem is a classic synchronization problem in computer science that illustrates the challenges of resource allocation in concurrent programming. This project implements a solution that avoids deadlocks and race conditions while allowing multiple philosophers to dine simultaneously.

### The Problem

- **N philosophers** sit around a circular table
- Each philosopher alternates between **thinking** and **eating**
- There is one **fork between each pair** of adjacent philosophers
- A philosopher needs **both adjacent forks** to eat
- The challenge is to design a protocol that prevents:
  - **Deadlock** (all philosophers waiting indefinitely)
  - **Starvation** (a philosopher never gets to eat)
  - **Race conditions** (inconsistent shared state)

## 🛠️ Implementation Details

This implementation uses:
- **POSIX threads (pthreads)** for concurrency
- **Mutex locks** for fork synchronization
- **Careful resource ordering** to prevent deadlock
- **Timestamped logging** for monitoring philosopher states

### Key Features

- ✅ **Deadlock-free**: Uses resource ordering strategy
- ✅ **Race condition safe**: Proper mutex synchronization
- ✅ **Configurable parameters**: Number of philosophers, timing values
- ✅ **Real-time monitoring**: Detailed state logging with timestamps
- ✅ **Memory safe**: Proper cleanup and resource management

## 🏗️ Project Structure

```
philosophers/
├── philo/
│   ├── src/           # Source files
│   ├── include/       # Header files
│   ├── Makefile       # Build configuration
│   └── philo          # Compiled executable
├── README.md          # This file
└── ...
```

## 🚀 Getting Started

### Prerequisites

- **GCC compiler** or compatible C compiler
- **POSIX-compliant system** (Linux, macOS, WSL)
- **Make** build tool

### Building the Project

```bash
# Clone the repository
git clone https://github.com/Selmand42/Philosophers.git
cd Philosophers

# Navigate to the philo directory
cd philo

# Compile the project
make

# Clean build artifacts (optional)
make clean
```

### Running the Program

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

#### Parameters

- **number_of_philosophers**: Number of philosophers (and forks)
- **time_to_die**: Time in milliseconds after which a philosopher dies if they haven't eaten
- **time_to_eat**: Time in milliseconds a philosopher spends eating
- **time_to_sleep**: Time in milliseconds a philosopher spends sleeping
- **number_of_times_each_philosopher_must_eat** *(optional)*: Simulation stops when all philosophers have eaten this many times

#### Example Usage

```bash
# 5 philosophers, die after 800ms, eat for 200ms, sleep for 200ms
./philo 5 800 200 200

# Same as above, but stop after each philosopher has eaten 3 times
./philo 5 800 200 200 3

# Classic example: 4 philosophers with tight timing
./philo 4 410 200 200
```

## 📊 Output Format

The program outputs philosopher state changes with timestamps:

```
[timestamp_ms] philosopher_id has taken a fork
[timestamp_ms] philosopher_id has taken a fork
[timestamp_ms] philosopher_id is eating
[timestamp_ms] philosopher_id is sleeping
[timestamp_ms] philosopher_id is thinking
[timestamp_ms] philosopher_id died
```

## 🧠 Algorithm Strategy

This implementation uses several key strategies to prevent deadlock:

1. **Resource Ordering**: Philosophers pick up forks in a consistent order
2. **Mutex Protection**: Each fork is protected by a mutex
3. **State Monitoring**: Continuous monitoring for death conditions
4. **Atomic Operations**: Thread-safe state updates

## 🎯 Learning Objectives

Through this project, you'll learn:

- **Thread creation and management** with pthreads
- **Mutex synchronization** for shared resources
- **Deadlock prevention** strategies
- **Race condition identification** and resolution
- **Concurrent program debugging** techniques
- **Resource management** in multithreaded applications

## ⚠️ Common Pitfalls and Solutions

### Deadlock Prevention
- ❌ **Circular wait**: All philosophers reach for the same fork
- ✅ **Solution**: Implement consistent fork ordering

### Race Conditions
- ❌ **Unsynchronized access**: Multiple threads accessing shared data
- ✅ **Solution**: Use mutex locks around critical sections

### Starvation
- ❌ **Unfair scheduling**: Some philosophers never get to eat
- ✅ **Solution**: Implement fair resource allocation

## 🧪 Testing

Test with various configurations:

```bash
# Test edge cases
./philo 1 800 200 200     # Single philosopher (should die)
./philo 2 800 200 200     # Minimal case
./philo 100 800 200 200   # Stress test

# Test timing sensitivity
./philo 4 310 200 100     # Tight timing
./philo 5 800 200 200 7   # Multiple meals
```

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📚 Additional Resources

- [Dining Philosophers Problem - Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [Deadlock Prevention Algorithms](https://www.geeksforgeeks.org/deadlock-prevention/)

## 📝 License

This project is part of the 42 School curriculum. Feel free to use it for educational purposes.

---

**Note**: This implementation is designed for learning purposes and demonstrates key concepts in concurrent programming and synchronization.
