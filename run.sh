# created by Jaimit Panchal started : 12 Nov 2022
#!/bin/bash 

clear

rm middle.txt
rm output.txt
rm image-output.txt
# rm test.txt
rm dms.txt

python3 -u imageTransform.py
g++ -std=c++17 core.cpp -o core 
./core

python3 -u build_image.py