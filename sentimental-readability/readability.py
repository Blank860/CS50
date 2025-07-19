def main():
    text = input("Text: ")

    # Count letters
    letters = sum(1 for c in text if c.isalpha())

    # Count words (assuming words are separated by spaces)
    words = len(text.split())

    # Count sentences (ends with ., !, or ?)
    sentences = sum(1 for c in text if c in ['.', '!', '?'])

    # Calculate L and S
    L = (letters / words) * 100
    S = (sentences / words) * 100

    # Coleman-Liau index
    index = round(0.0588 * L - 0.296 * S - 15.8)

    # Print grade level
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()
