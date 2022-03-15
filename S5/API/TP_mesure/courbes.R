donnees <- read.csv(file      = "./results2.csv",  # chemin vers votre fichier de données
                    sep       = ",",                # le caractere qui separe les données d'un couple
                    header    = FALSE,              # Boolean indiquant si vous données contiennent une entete
                    col.names = c("paquet", "kbits")) # Si pas d'entete alors on defini le nom des colonnes

# vous pouvez voir les premieres lignes avec la commande
head(donnees)

# On charge ggplot2
library(ggplot2)


ggplot(data = donnees, aes(x = paquet, y = kbits)) +                 # On indique quelles colonnes afficher et sur quel axes
    geom_point() +                                                 # Afficher uniquement les points de mesure
    geom_line() +                                                  # Affiche uniquement une ligne entre chaque point de mesure
    xlab("Taille paquet") +                                                    # Label de l'axe des x
    ylab("kbit/s") +                         # Label de l'axe des y
    ggtitle("Débit en fonction de la taille du paquet émis") + # Titre du graphique
    theme_bw() +
    theme(legend.position = "bottom", legend.box = "horizontal")

# Pour sauvegarder le graphique
ggsave("mon_graphique_both.png")