# TODO

def main():
    # receive a text as input
    text = input("text: ")

    # see the total of letters, words and sentences in the text
    letters = textLetters(text)
    words = textWords(text)
    sentences = textSentences(text)

    # L is the average number of letters per 100 words
    L = (letters / words) * 100

    # S is the average number of sentences per 100 words
    S = (sentences / words) * 100

    # calculete the grade level
    readerLevel = round((0.0588 * L) - (0.296 * S) - 15.8)

    #output the grade level
    if readerLevel > 15:
        print("Grade 16+")
    elif readerLevel < 0:
        print("Before Grade 1")
    else:
        print(f"Grade: {int(readerLevel)}")


def textLetters(text):
    # total of letters in the text
    totalLetters = 0

    # pass for every character in the text, if is a alpha('a' - 'z' or 'A' - 'Z') add 1 to totalLetters
    for letters in text:
        if letters.isalpha():
            totalLetters += 1

    #return the total of letters
    return totalLetters


def textWords(text):
    #separete the words in the text
    words = text.split()

    # total of words in the text
    totalWords = 0

    # pass for every word in the text and add 1 to totalWords
    for word in words:
        totalWords += 1

    # return totalWords
    return totalWords


def textSentences(text):
    # total of sentences in the text
    sentences = 0

    # create a index to pass for every letter in the text
    for index in range(len(text)):
        # if the actual index is considerated the end of a sentence('.', '!', '?')
        if text[index] == "." or text[index] == "!" or text[index] == "?":
            # and the letter before that ins't considerated the end of a sentence
            if text[index - 1] != "." or text[index - 1] != "!" or text[index - 1] != "?":
                # add 1 to the total of sentences
                sentences += 1

    #return the total of sentences in the text
    return sentences


main()
