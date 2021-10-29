donnees <- read.csv(file      = "./results2.csv",  # chemin vers votre fichier de données
                    sep       = ",",                # le caractere qui separe les données d'un couple
                    header    = FALSE,              # Boolean indiquant si vous données contiennent une entete
                    col.names = c("N", "nb_compa_ins", "nb_compa_seg", "err_ins")) # Si pas d'entete alors on defini le nom des colonnes

# vous pouvez voir les premieres lignes avec la commande
head(donnees)

# On charge ggplot2
library(ggplot2)

ggplot(data = donnees, aes(x = N)) +                 # On indique quelles colonnes afficher et sur quel axes
    geom_point(aes(y = nb_compa_seg, color="Seg")) +                                                 # Afficher uniquement les points de mesure
    geom_pointrange(aes(y = nb_compa_ins, ymin=nb_compa_ins-err_ins, ymax=nb_compa_ins+err_ins, color="Ins")) +
    geom_line(aes(y = nb_compa_seg, color="Seg")) +                                                 # Affiche uniquement une ligne entre chaque point de mesure
    geom_line(aes(y = nb_compa_ins, color="Ins")) +
    scale_color_discrete(name = "Courbes", labels = c("Tri par insertion", "Tri par segmentation")) +
    xlab("N") +                                                    # Label de l'axe des x
    ylab("Nombre moyen de comparaisons") +                         # Label de l'axe des y
    ggtitle("Nombre moyen de comparaisons par taille de tableau") +  # Titre du graphique
    theme_bw() +
    theme(legend.position = "bottom", legend.box = "horizontal")    # geom_errorbar(aes(ymin = -upper, ymax = upper), width = 0.2)
    
# Pour sauvegarder le graphique
ggsave("mon_graphique_both.png")