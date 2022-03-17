#! /bin/bash bash

INCLUDE="../ft_containers/include/" #Change this line to your containers
CC="clang++"
FLAGS="-Wall -Werror -Wextra -std=c++98"
SRCS="./src/"
OUTPUT_PATH="./outputs/"

exec_file()
{
	container=${2}
	test_name="$(basename ${1} .cpp)"
	dir_output=${OUTPUT_PATH}${container}
	std_output=$dir_output/std_${test_name}
	ft_output=$dir_output/ft_${test_name}

	#compile with std containers
	${CC} ${FLAGS} -I ${INCLUDE} -D NAMESPACE="std" ${1}
	./a.out > ${std_output}
	rm a.out
	#compile with ft containers
	${CC} ${FLAGS} -I ${INCLUDE} -D NAMESPACE="ft" ${1}
	./a.out > ${ft_output}
}

do_test ()
{
	test_files=$(find "${SRCS}${1}" -type f -name '*.cpp' | sort)
#	mkdir ${OUTPUT_PATH}${1}
	for file in ${test_files[@]}; do
		exec_file $file ${1}
	done
}

main()
{
	containers=(vector)
	
	for container in ${containers[@]}; do
		echo "Testing  ${container}"
		do_test ${container}
	done
}
main;