#!/bin/sh

fail=0

echo "--- linkedlist_test ---"
./linkedlist_test
if [ ! $? -eq 0 ];
then
	fail=1
fi
echo "--- stack_test ---"
./stack_test
if [ ! $? -eq 0 ];
then
	fail=1
fi

if [ $fail -eq 0 ];
then
	echo "--- structure comparison ---"
	./compare_structure
fi

