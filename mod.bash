#!/bin/bash

# 定义要修改的字符串
old_strings=(
"LDFLAGS		="
"CFLAGS		="
)

new_strings=(
"LDFLAGS		= -m elf_i386"
"CFLAGS		= -m32 -fno-stack-protector"
)

# 查找包含指定文件名的文件，并在每个文件上运行sed命令进行修改

find ~/Desktop/OS/* -type f -name "Makefile" -print0 | while read -d $'\0' file; do
	for (( i=0; i<${#old_strings[@]}; i++ )); do
	  old_string="${old_strings[$i]}"
	  new_string="${new_strings[$i]}"
	  sed -i "s#$old_string#$new_string#g" "$file"
	  echo "Modified file: $file"
	done
done


