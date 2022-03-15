# 1

voir screen

# 2

1.3 peut pas avec 0.1
1.3 peut pas avec 0.2
0.2 peut pas avec 1.1
et 1.3 peut pas avec 0.2

route add 192.168.0.0/24 192.168.1.1 sur machine A
sans forwarding -> pas derreur chez A rien chez pong C
avec forwarding -> pas derreur chez A et ICMP echo request reçus chez C(192.168.1.3 -> 192.168.0.2)

regler le probleme -> route add 192.168.1.0/24 192.168.0.1
sans ça C ne pas peut répondre à A car sait pas ou il est et peut pas atteindre son réseau.

Voir screen Q1_wireshark
# 3
Camille 

# 4

pour atteindre toutes les machines de tous les réseaux

# 5

route add 0.0.0.0/0 192.168.0.1 pour C par exemple

ping vers adresse inconnue avec defaut:

c'est le router B qui dit qu'il connait pas en réponse à A qui chercher qqn 

# 6

Camille

# 7

ajout automatique d'une ligne dans la table de routage de A et C poitant vers l'autre réseau grâce à RIP.

# 8

voir screen, metric = distance
on en reçoit deux, car broadcast et reçoit tt de suite 
intervalle de temps très court

# 9 

après qq minutes -> suppression de l'entrée qui lie A vers le réseau C (4min)

revient arpès 30sec après rebranchement.

# 10

Camille

# 11

metric de 16 -> inateignable

# 12

rip request - rip response

# 13

voir photo

# 14

exemple D : (voir photo) route add 0.0.0.0/0 10.9.8.1

# 15

voir screen

# 16
A - request de 192.168.1.3 vers 192.168.1.255 (metric 16)
B - 2* deux request (1 pour reseau 1 et l'auitre 0)
response de lui mm qq temps apres avec bonnes metric
C - une request et une reponse direct de B mm reseau puis salves de response (envoie tables)
des requsts et des reponses
D - rien ????????

# 17
voir au dessus
Camille

# 18

camille

# 19

camille

# 20 

camille

# 21









