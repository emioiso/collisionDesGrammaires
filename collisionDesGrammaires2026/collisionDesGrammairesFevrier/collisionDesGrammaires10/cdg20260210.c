#include <stdio.h>

void print_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("(missing: %s)\n", filename);
        return;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (buffer[0] == '!') {
            continue; // '!'で始まる行は出力しない
        }
        printf("%s", buffer);
    }

    fclose(fp);
}

int main(void) {
    printf("Date: 2026/02/11\n");

    printf("\n[日本語]\n");
    print_file("20260210_ja.txt");
    printf("\n");

    printf("\n[Français]");
    print_file("20260210_fr.txt");
    printf("\n");

    return 0;
}
