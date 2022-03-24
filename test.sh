#! /bin/bash bash

#COLORS
RED='\033[0;31m'
GREEN='\033[0;32m'
WHITE='\033[1;37m'

INCLUDE="../ft_containers/include/" #Change this line to your containers
CC="clang++"
FLAGS="-Wall -Werror -Wextra -std=c++98"
SRCS="./src/"
OUTPUT_PATH="./outputs/"

print_container_name()
{
	size=9
	for i in {0..9}; do
		echo -en ${WHITE}"-"
	done

	echo -n " TESTING ${1^^} "

	for i in {0..9}; do
		echo -n "-"
	done
	echo ;
	
}

print_results()
{
	diff ${1} ${2} > ${3}/diffs/${4}_diffs.txt
	echo -en ${WHITE} "OUTPUT "
	if [[ $? == 0 ]]
	then
		echo -e ${GREEN} "[OK]"
	else
		echo -e ${RED} "[KO]"
	fi
}

exec_file()
{
	container=${2}
	test_name="$(basename ${1} .cpp)"
	dir_output=${OUTPUT_PATH}${container}
	std_output=$dir_output/std_${test_name}_output.txt
	ft_output=$dir_output/ft_${test_name}_output.txt
	
	#printf '\%s %-10s : ' ${WHITE} ${test_name}
	echo -en ${WHITE}"${test_name^}\t : "

	#compile with std containers
	${CC} ${FLAGS} -I ${INCLUDE} -D NAMESPACE="std" ${1}
	./a.out > ${std_output}
	rm a.out

	#compile with ft containers
	${CC} ${FLAGS} -I ${INCLUDE} -D NAMESPACE="ft" ${1}
	./a.out > ${ft_output}

	print_results $std_output $ft_output $dir_output $test_name
}

do_test ()
{
	mkdir -p ${OUTPUT_PATH}${1}
	mkdir -p ${OUTPUT_PATH}${1}/diffs

	test_files=$(find "${SRCS}${1}" -type f -name '*.cpp' | sort)

	for file in ${test_files[@]}; do
		exec_file $file ${1}
	done
}

function main (){
	containers=(vector)
	
	for container in ${containers[@]}; do
		print_container_name ${container}
		do_test ${container}
	done
	rm a.out time
}

main;