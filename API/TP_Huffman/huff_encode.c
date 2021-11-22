
#include "arbrebin.h"
#include "bfile.h"
#include "fap.h"
#include "huffman_code.h"
#include <assert.h>
#include <stdio.h>

typedef struct {
    int tab[256];
} TableOcc_t;

struct code_char HuffmanCode[256];
void ConstruireTableOcc(FILE *fichier, TableOcc_t *TableOcc) {

    int c;
    int i;
    for (i = 0; i < 256; ++i)
    {
        TableOcc->tab[i] = 0;
    }

    c = fgetc(fichier);
    while (c != EOF) {
        TableOcc->tab[c] += 1;
        c = fgetc(fichier);
    };

    for (i = 0; i < 256; i++) {
        if (TableOcc->tab[i] != 0)
            printf("Occurences du caractere %c (code %d) : %d\n", i, i,
                   TableOcc->tab[i]);
    }
}

fap InitHuffman(TableOcc_t *TableOcc) {
    fap my_fap = creer_fap_vide();
    for (int carac = 0; carac < 256; ++carac)
    {
        if (TableOcc->tab[carac] != 0) {
            Arbre elem = NouveauNoeud(ArbreVide(), carac, ArbreVide());
            int freq = TableOcc->tab[carac];
            my_fap = inserer(my_fap, elem, freq);
        }
    }
    return my_fap;
}

Arbre ConstruireArbre(fap file) {
    Arbre z = ArbreVide(), a1 = ArbreVide(), a2 = ArbreVide();
    int fap_vide = 0, freq1 = 0, freq2 = 0;
    while(!fap_vide)
    {
        file = extraire(file, &a1, &freq1);
        file = extraire(file, &a2, &freq2);
        fap_vide = est_fap_vide(file);
        z = NouveauNoeud(a1, '^', a2);
        file = inserer(file, z, freq1 + freq2);
        a1 = ArbreVide();
        a2 = ArbreVide();
    }
    return z;
}

char ConstruireCode_rec(Arbre huff, int lg) {
    if(EstVide(huff))
        return -1;
    if(FilsGauche(huff) == NULL && FilsDroit(huff) == NULL) {
        return Etiq(huff);
    } else {
        int gauche = ConstruireCode_rec(FilsGauche(huff), lg+1);
        HuffmanCode[gauche] = gauche;
        HuffmanCode[gauche].lg = lg+1;
        HuffmanCode[gauche].code[lg+1] = 1;
        int droit = ConstruireCode_rec(FilsDroit(huff), lg+1);
        HuffmanCode[droit] = droit;
        HuffmanCode[droit].lg = lg+1;
        HuffmanCode[droit].code[lg+1] = 1;
    }
    return 0;

}

void ConstruireCode(Arbre huff) {
    ConstruireCode_rec(huff, -1);
}

void Encoder(FILE *fic_in, FILE *fic_out, Arbre ArbreHuffman) {
    /* A COMPLETER */
    printf("Programme non realise (Encoder)\n");
}

int main(int argc, char *argv[]) {

    TableOcc_t TableOcc;
    FILE *fichier;
    FILE *fichier_encode;

    fichier = fopen(argv[1], "r");
    /* Construire la table d'occurences */
    ConstruireTableOcc(fichier, &TableOcc);
    fclose(fichier);

    /* Initialiser la FAP */
    fap file = InitHuffman(&TableOcc);

    /* Construire l'arbre d'Huffman */
    Arbre ArbreHuffman = ConstruireArbre(file);

    AfficherArbre(ArbreHuffman);

    /* Construire la table de codage */
    ConstruireCode(ArbreHuffman);

    /* Encodage */
    fichier = fopen(argv[1], "r");
    fichier_encode = fopen(argv[2], "w");

    Encoder(fichier, fichier_encode, ArbreHuffman);

    fclose(fichier_encode);
    fclose(fichier);

    return 0;
}
