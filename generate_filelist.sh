#/bin/bash

ls src/*.cpp > list.txt
cat list.txt | tr '\n' ';' > Filelist.txt
rm list.txt

