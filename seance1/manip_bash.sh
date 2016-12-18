#  ercherchez recursivement dan,s un répertoire les fichiers de tailles comprise entre 20k et 150k

find $1 -size +20k -size -150k

#Chercher dans le répertoir courant les répertoires avec e (maj ou min) dans le nom
find "dossier" -name "name"

#Pour supprimer les fichiers trouvés précédemment
find "dossier" -name "name" -delete

#Chercher les fichiers qui ont certains droits (1 : x, 2 : w, 4 : r)
find "dossier" -perm  #rechercher utilisateur-groupe-toutlemonde

#Pour rediriger l'erreur std vers un autre fichier et ne pas l'afficher dans le terminal
[commande] 2> err.txt*

#Exécuter quelque chose après un fin
find "dossier" -type f -name "name" -exec gzip -f {} \;  -o -name "name" -exec gzip -f {} \;
