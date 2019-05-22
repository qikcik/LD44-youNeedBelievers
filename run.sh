#bin/bash

./compile.sh 

echo -e "\e[39m -------- \e[32mRUNNING \e[39m --------" 

chmod +x build/LD44 
cd build
gdb LD44.exe
