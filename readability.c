#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_spaces(string text);
int count_sentences(string text);
int index;

//main function gathers input text and outputs letters, words, and sentences. Will finally make it output the grade too
int main(void) {

    // Get input text from user to be evaluated
    string text = get_string("Enter text: ");
    printf("Letters: %i\n", count_letters(text));
    printf("Words: %i\n", count_spaces(text));
    printf("Sentences: %i\n", count_sentences(text));
    
    // Calculate the Coleman-Liau index
    index = round(0.0588 * ((float)count_letters(text) / (float)count_spaces(text) * 100) - 0.296 * ((float)count_sentences(text) / (float)count_spaces(text) * 100) - 15.8);

    // Print calculated grade of text
    if (index < 1) {
        printf("Before Grade 1\n");
    } else if (index >=16) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %i\n", index);
    }

}

    // Print the number of letters
    int count_letters(string text) {
    int letters = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isupper(text[i]) || islower(text[i])) {
            letters ++;
        }
    }
    return letters;
}

    // Print the number of words
    int count_spaces(string text) {
    int spaces = 0;

    for (int i = 0; i < strlen(text); i++) {
        if (isspace(text[i])) {
            spaces ++;
        }
    }
    return (spaces + 1);
}

    // Print the number of sentences
    int count_sentences(string text) {
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++) {
        if ((text[i]) == '.' || (text[i]) == '!' || (text[i]) == '?') {
            sentences ++;
        }
    }
    return sentences;
}

