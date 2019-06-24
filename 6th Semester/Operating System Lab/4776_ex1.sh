file="grades.txt"
i="0"
until [ $i -eq 6 ];
do
#Menou
echo ''
echo '		Menou  '
echo ''
echo '[1] Fortosi arxeiou va8mon
[2] Provoli va8mou foititi
[3] Allagi va8mou foititi
[4] Provoli va8mologiou
[5] Apo8ikeusi va8mologiou
[6] E3odos'
read -p "Parakalo epile3te: " i
#[1] Fortosi arxeiou va8mon
if [ $i -eq 1 ]; then
	read -p "Doste path: " file
	if test -z "$file"; then file="grades.txt"; fi;
	echo "Epilextike to arxeio "$file
	grades=$(tr '\r' '+' < $file)
	read foo
fi
#[2] Provoli va8mou foititi
if [ $i -eq 2 ]; then
	read -p "Doste AM foititi: " am
	am=$(echo $grades | tr '+' '\n' | awk 'BEGIN {FS=","}{if ($1=='$am') print $1}')
	onoma=$(echo $grades| tr '+' '\n'  | awk 'BEGIN {FS=","}{if ($1=='$am') print $2}')
	vathmos=$(echo $grades | tr '+' '\n' | awk 'BEGIN {FS=","}{if ($1=='$am') print $3}')
	if test -z $am; then
	echo "Den uparxei tetoio AM !"
	else
	echo "O vathmos tou foititi "$onoma" einai "$vathmos" !"
	fi
read foo
fi
#[3] Allagi va8mou foititi
if [ $i -eq 3 ]; then
	read -p "Doste AM foititi: " am
	am=$(echo $grades | tr '+' '\n' | awk 'BEGIN {FS=","}{if ($1=='$am') print $1}')
	onoma=$(echo $grades | tr '+' '\n' | awk 'BEGIN {FS=","}{if ($1=='$am') print $2}')
	vathmos=$(echo $grades | tr '+' '\n' | awk 'BEGIN {FS=","}{if ($1=='$am') print $3}')
	if test -z $am; then
	        echo "Den uparxei tetoio AM !"
        else
	        echo "O vathmos tou foititi "$onoma" einai "$vathmos" !"
		read -p "Doste neo vathmo: " neos
		new=$(echo $grades | tr '+' '\n' | grep -w $am |sed 's/\,'"$vathmos"'/\,'"$neos"'/g')
		old=$(echo $grades | tr '+' '\n' | grep -w $am)
		grades=$(echo $grades | sed 's/'"$old"'/'"$new"'/g')
        fi
fi
#[4] Provoli va8mologiou
if [ $i -eq 4 ]; then
	echo $grades | tr '+' '\n' |more
fi
#[5] Apo8ikeusi va8mologiou
if [ $i -eq 5 ]; then
	read -p "Doste path gia apo8ikeusi: " file
        if test -z "$file"; then file="grades.txt"; fi;
        echo "Apo8ikeusi sto arxeio "$file
        echo $grades | tr '+' '\r' > $file
	read foo
fi
done
echo "E3odos..."
