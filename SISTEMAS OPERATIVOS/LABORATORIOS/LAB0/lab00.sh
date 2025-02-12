# Ejercicio 1
cat /proc/cpuinfo | grep "model name"

# Ejercicio 2
cat /proc/cpuinfo | grep "model name" | wc -l

# Ejercicio 3
wget -O heroes.csv https://raw.githubusercontent.com/dariomalchiodi/superhero-datascience/master/content/data/heroes.csv && cat heroes.csv | tail -n +2 | cut -d ';' -f 2 | grep -v '^$' | tr -d ' ' | tr '[:upper:]' '[:lower:]' > names.txt

# Ejercicio 4
sort -k 5 -n < weather_cordoba.in > weather_sorted.txt; head -n 1 weather_sorted.txt | cut -d ' ' -f 1-3; tail -n 1 weather_sorted.txt | cut -d ' ' -f 1-3

# Ejercicio 5
sort -k 3 -n < atpplayers.in > atpplayers_sorted.txt

# Ejercicio 6
awk -F ' ' '{print $0, $7-$8}' superliga.in | sort -k2 -k9 -n -r -t ' ' > modified_superliga.in;echo -e "${BOLD}${B_GREEN}Superliga's teams ordered were saved on $(pwd)/modified_superliga.in$RESET";echo " ";echo -e "${BOLD}${BLUE}Showing this computer's MAC Address...$RESET"


# Ejercicio 7
ip link show | grep -o -P "(?<=link/ether )([0-9a-f]{2}:){5}[0-9a-f]{2}"

# Anotacion: (?<=link/ether ) es un lookbehind assertion en las expresiones regulares de Perl. Busca una coincidencia que esté precedida por link/ether 

# Ejercicio 8
for file in ./breaking_bad/*_es.srt; do mv "$file" "${file/_es.srt/.srt}"; done

# Anotacion: con /*_es.srt iteramos sobre todos los archivos que terminan en _es.srt.
# ${file/_es.srt/.srt}: Usa una sustitución de cadena para reemplazar _es.srt con .srt
