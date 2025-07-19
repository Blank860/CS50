def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                return height
        except ValueError:
            pass  # ignore non-integer inputs

def main():
    height = get_height()

    for row in range(1, height + 1):
        # Left pyramid: spaces then hashes
        spaces = height - row
        hashes = row

        print(" " * spaces + "#" * hashes + "  " + "#" * hashes)

if __name__ == "__main__":
    main()
