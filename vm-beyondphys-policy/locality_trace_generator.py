import random

if __name__ == "__main__":
    with open('locality_trace.txt', 'w') as f:
        for i in range(100):
            prev_num = random.randint(0, 9)
            f.write(str(prev_num) + "\n")
            for j in range(9):
                if prev_num < 2:
                    prev_num = 2
                elif prev_num > 7:
                    prev_num = 7
                num = random.randint(prev_num - 2, prev_num + 2)
                f.write(str(num) + "\n")
                prev_num = num
