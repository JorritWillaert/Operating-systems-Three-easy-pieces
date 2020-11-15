import random

if __name__ == "__main__":
    with open('random_trace.txt', 'w') as f:
        for i in range(1000):
            f.write(str(random.randint(0, 9)) + "\n")
