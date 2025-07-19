def luhn_check(card_number):
    total = 0
    reverse_digits = card_number[::-1]

    for i, digit in enumerate(reverse_digits):
        n = int(digit)
        # Double every other digit
        if i % 2 == 1:
            n *= 2
            if n > 9:
                n -= 9
        total += n

    return total % 10 == 0


def get_card_type(card_number):
    length = len(card_number)
    start_digits = card_number[:2]

    if luhn_check(card_number):
        if length == 15 and start_digits in ["34", "37"]:
            return "AMEX"
        elif length == 16 and start_digits in ["51", "52", "53", "54", "55"]:
            return "MASTERCARD"
        elif length in [13, 16] and card_number.startswith("4"):
            return "VISA"
        else:
            return "INVALID"
    else:
        return "INVALID"


def main():
    while True:
        card_number = input("Number: ")
        if card_number.isdigit():
            break

    card_type = get_card_type(card_number)
    print(card_type)


if __name__ == "__main__":
    main()
