
# TD Interruption Horloge
> Calcul du temps d'exécution d'un programme

Nous étudions différentes manières de mesurer  le temps d'exécution d'un programme :
- en utilisant des fonctions système de la bilbiothèque time.c
- en utilisant une interruption et un traitant

Nous considérons la fonction __fib(n)__ qui calcule le n<sup>ième</sup> terme de la suite de Fibonacci.

#### Compilation

:wrench: Ouvrez le fichier [Makefile](src/Makefile) et modifiez la variable `CC=` afin qu'elle pointe vers le compilateur C de votre OS.

# Chronométrage d'une exécution

## ... en utilisant la bibliothèque `time.h`.

:eye: Jettez un oeil au fichier
  [fib.c](src/fib.c)

> :bulb: La version [memo_fib.c](src/memo_fib.c), incroyablement plus rapide que la version naive est à faire hors TP. Elle présente une astuce classique en informatique, appelée, _memoization_, qui consiste à échanger de l'espace mémoire contre du temps de calcul.


## ... en utilisant un traitant d'interruption

#### Mise à jour du temps `hh:mm:ss`

La date courante est représentée par trois variables globales partagées définies dans [timer.h](src/timer.h)
```C
char timer_heure, timer_minute, timer_seconde;
```

La fonction `timer_tick()`, qui met à jour ces variables, sera déclenchée _à chaque seconde_ par un mécanisme d'interruption.

:wrench: Complétez le programme [timer.c](src/timer.c)

```C
void timer_tick(){
  timer_seconde +=1;
  if (...==60) { ... };
  ...
}
```

:wrench: Complétez la partie `...` du fichier [chrono_fib.c](src/chrono_fib.c) afin d'afficher __la durée mesurée par le timer en seconde.__


### Traitant d'Interruption

On souhaite déclencher la mise à jour du timer à chaque seconde à l'aide d'une interruption.

:question: Quel élément de l'architecture donne des impulsions régulières ?

:question: Quel est l'intérêt d'utiliser un mécanisme d'interruption qui déclenche un traitant pour faire la mise à jour des variables heure, minute, seconde ?

:question: Peut-on imaginer une autre solution en modifiant le code dont on souhaite mesurer le temps d'exécution ?

#### Utilisation de fonction système

Dans le cadre de ce TD/TP nous n'allons pas modifier directement le vecteur d'interruption ; ce qui demanderait d'intervenir dans le noyau et risque de planter la machine. Nous allons utiliser des signaux d'interruption fournit par des bibliothèques standards.

:wrench: Complétez le fichier [main.c](src/main.c) en appelant un traitant qui met à jour le timer à chaque interruption par le signal `alarm`.


```C
#include <signal.h> // contient la déclaration des signaux dont SIGALRM
#include <unistd.h> // unsigned int alarm(unsigned int seconds);

void traitant(int sig_num){
  alarm(1); // réarmer une alarme qui se déclenchera dans 1 seconde
  ...
}

int main (int nb_args, char* args[]){
  // demande d'envoi du signal SIGALRM dans ~1 seconde.  
  alarm(1);
  // association du signal au traitant
  signal (SIGALRM, traitant);

  ...
}
```

### Observation

L'affichage des calculs et des appels récursifs de Fibonnacci dépend des variables :
```C
boolean INSTRUMENTATION = false;
int INSTRUMENTATION_FREQUENCY = 1;
```

- Faites appel à Fibonnacci avec des valeurs entre 10 et 20 puis augmenter progressivement.
- Modifiez les réglages d'instrumentation pour     
  1. voir les interruptions,
  2. voir le détail des calculs et des appels,
  3. montrer interruptions au milieu des appels.


# Étude critique

### Le mécanisme timer n'est pas fiable

Ouvrez le fichier [chrono_fib.c](src/chrono_fib.c) et répondez aux 5 questions indiquées par le commentaire `QUESTION ..`.

Pouquoi le mécanisme [timer_sec.c](src/timer_sec.c) est-il préférable ?

## Pourquoi cela pourrait ne pas fonctionner ?

On considère que
- que le programme à chronométrer comporte une longue instruction qui prend __I__ cycles du processeur
- que le traitant prend __T__ cycles
- que l'impulsion IRQ est émise par l'horloge tous les __P__ cycles et qu'elle dure __D__ cycles.

Selon les rapports entre les nombres de cycles __I, T, P, D__, on peut engendrer des situations où on manque des secondes ou bien on en compte trop.

Pour chacune des situations ci-dessous,
  - essayez de générer une situation problématique
  - dessinez un chronogramme qui illustre le fonctionnement attendu et la situation problèmatique
  - en déduire une règle de bonne conception de traitant

> Un chronogramme doit montrer le fonctionnement de l'ensemble programme à chronométrer (PRG) + Interruption (IRQ) + traitant (TT). Pour simuler le système on fait apparaître
  - les périodes où le signal IRQ est présent
  - les périodes pendant lesquelles le traitant s'exécute
  - les périodes pendant lesquelles le programme s'exécute
  - d'autres données utiles par exemple le compteur de seconde

#### Fonctionnement attendu

Considérons __I=1, T=3, P=7, D=2__ et le chronogramme
```
PRG  ####   #####   ###
TT      |###    |###    ###     ### ...
IRQ     ##      ##      ##      ##  ...   
     456  123456  123456  123456  
t =  0s     1s      2s      3s     4s   
```
Ce cas favorable correspond à ...

#### Cas I > D _(par exemple: I=7, T=3, P=9, D=2)_

#### Cas T+I >= D+P

#### Cas T > P

#### Cas D > T

#### Cas où une autre IRQ, qui peut survenir pendant la mesure, est associée à un traitant long (par exemple lecture disque).


#### À quel cas précédent correspond chacun des situations

* 1)  Le traitant d'interruption dure dans le pire des cas 1.7 seconde.

* 2)  Le signal d'IRQ ne disparaît pas ; ce qui ne serait pas normal pour l'horloge mais serait possible pour un autre périphérique (un clavier avec un touche qui reste enfoncée).

* 3) Le programme à chronométrer comporte une instruction complexe qui dure 6 cycles
tandis que signal IRQ émis par l'horloge à une période de 3 cycles.

### Que peut-on faire pour limiter ces effets indésirables?

On cherche à écrire un traitant qui a une exécution la plus courte possible. On se contente de mettre à jour une seule variable `sec` qui peut prendre les valeurs de  [0 ; 65 535] ie. de _0s à 18h._

* :wrench: Écrire une version en _langage d'assemblage ARM_ qui met à jour le compteur des secondes.

* Pour obtenir un corrigé, compilez le programme `tick.c` ci-dessous
  ```C
unsigned int sec;
void tick(){
  sec+=1;
}
```
  avec le compilateur de votre OS et l'option adaptée
  - `clang -O0 -S --target=armv5te-pc-linux-eabi tick.c -o tick.arm`
  -  `gcc -O0 -S -march=armv5te tick.c -o tick.arm`


#### Révision ARM

  Et si on voulait faire la mise à jour de la variable qui compte les minutes ? Donnez les instructions ARM correspondant à
  ```C
  if (sec==60){ sec=0; min+=1; }
  ```

### Compilation d'un traitant

* Pourquoi est-il incorrecte d'écrire un traitant d'interruption comme une fonction C standard ?

* Le compilateur `gcc` possède une directive de compilation `__attribute__((interrupt))`
qui permet d'indiquer que la fonction qui suit est un traitant d'interruption. Complilez le code ci-dessous en assembleur et regarder la différence du code produit pour `une_fonction` et `traitant`.

```C
void tick(); // déclaration du profil

void une_fonction() {
	tick();
}

__attribute__((interrupt))
void traitant() {
	tick();
}
```

# La curiosité est une qualité scientifique

* Complétez la fonction `memo_fib` et mesurer la différence de temps d'exécution pour des valeurs de l'ordre de n=20..40

* [chrono_fib.c](src/chrono_fib.c) utilise deux implémentations de timer qui remplissent des structures : `clock` de la bilbiothèque `time.c` et `hms` fournie dans [hms.c](src/hms.c). Pour remplir une structure `clock` ou `hms` ces implémentations utilisent deux techniques différentes :
  - `clock` retourne un résultat
  - `hms` remplit une variable passée en paramètre

  - :question: quel est le type de chacun ?
  - :question: quelle est la consommation mémoire du code ci-dessous ?
  > ... structure hms + ... structure clock

    ```C
hms t1;
clock_t t2;
for(i=0 ; i<N ; i++){
      get(&t1)
      t2 = clock();
}  
```
