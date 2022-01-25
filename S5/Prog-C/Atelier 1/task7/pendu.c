#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#include "../task4/string.c"

#define STDIN   0  // Standard input (stdin)
#define STDOUT  1  // Standard output (stdout)
#define POSITION_MAX 8

struct letter {
    char letter;
    int positions[POSITION_MAX];
};

void init_letters_array(char *word, struct letter letters[]) {
    int word_length = string_length(word);
    for (int nletters = 0; nletters < word_length; ++nletters) {
        letters[nletters].letter = '0';
        for (int lposition = 0; lposition < POSITION_MAX; ++lposition) {
            letters[nletters].positions[lposition] = -1;
        }
    }
}

int read_char(char *ch) {
    return scanf(" %c", ch);
}

int check_validity(char *word, struct letter letters[]) {
    int sum_letters = 0;
    int word_length = string_length(word);
    for (int nletter = 0; nletter < word_length; ++nletter) {
        for (int nposition = 0; nposition < word_length; ++nposition) {
            if(letters[nletter].positions[nposition] != -1)
                sum_letters++;
        }
    }
    if(sum_letters == word_length)
        return 0;
    return 1;
}

void compute_input(char *ch_input, struct letter letters[], char *word) {
    int res = read_char(ch_input);
    if (res != -1) {
        int ch_position = string_index_of(word, 0, *ch_input);
        if (ch_position != -1) {
            int letters_pt = 0;
            while (letters[letters_pt].letter != '0')
                letters_pt++;
            letters[letters_pt].letter = *ch_input;
            int letter_position = 0;
            while (ch_position != -1) {
                letters[letters_pt].positions[letter_position] = ch_position;
                ch_position = string_index_of(word, ch_position + 1, *ch_input);
                letter_position++;
            }
        }
    }
}

void print_word(char *word, struct letter letters[]) {
    int letter_found;
    for (int word_letter = 0; word_letter < string_length(word); ++word_letter) {
        letter_found = 1;
        for (int letter_pt = 0; letter_pt < string_length(word); ++letter_pt) {
            for (int position = 0; position < POSITION_MAX; ++position) {
                if (letters[letter_pt].positions[position] == word_letter && letter_found == 1) {
                    printf("%c", letters[letter_pt].letter);
                    letter_found = 0;
                }
            }
        }
        if (letter_found != 0)
            printf("-");
    }
    printf("\n");
}

char *pick_random_word() {
    char **dict;
    int size_dict = 5 * sizeof(char *);
    dict = malloc(size_dict);
    memset(dict, 0, size_dict);
    dict[0] = "bonjour";
    dict[1] = "polytech";
    dict[2] = "aaaaa";
    dict[3] = "aurevoir";

    return dict[rand() % 4];
}

int run_game(char *word, struct letter *letters, int guess_count, char *ch_input) {
    while (guess_count >= 0) {
        print_word(word, letters);
        printf("? ");
        compute_input(ch_input, letters, word);
        if(!check_validity(word, letters)) {
            return 0;
        }
        guess_count--;
    }
    return -1;
}

void init_game(char **word, int *guess_count, struct letter letters[]) {
    *word = pick_random_word();
    *guess_count = string_length(*word) + rand() % 5;
    init_letters_array((*word), letters);
    char ch_input;
}

int main(int nargs, char **args) {

    srand(clock());
    setbuf(stdout, NULL);

    char *word;
    struct letter letters[POSITION_MAX];
    int guess_count;
    char ch_input;

    char *regame_answer = malloc( 3* sizeof(char));
    int regame = 1;
    while(regame) {
        init_game(&word, &guess_count, letters);

        printf("Vous avez %d coups pour deviner le mot :\n", guess_count);

        int game_result = run_game(word, letters, guess_count, &ch_input);
        print_word(word, letters);
        printf("Vous avez %s, voulez-vous rejouer ?\n ? ", game_result ? "perdu" : "gagné");

        scanf("%s", regame_answer);
        if(string_cmp(regame_answer, "oui")) {
            regame = 0;
        }
    }
    printf("Au revoir !\n");
}


