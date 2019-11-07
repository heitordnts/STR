NAME=`echo $1 | sed 's/\.cpp//g'`
FLAGS='-pthread -lm'

echo "Compilando " $1

gcc $1 $FLAGS -o $NAME

echo "Executando ..."
echo
echo

./$NAME
