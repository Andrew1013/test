#! /bin/bash

huge_mnt_path="/mnt/huge"

#test if dir exit
if [ ! -x $huge_mnt_path ]
then
	mkdir $huge_mnt_path
fi

mount -t hugetlbfs nodev "$huge_mnt_path"
echo 20 > /proc/sys/vm/nr_hugepages
