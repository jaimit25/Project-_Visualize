bash clean.sh
clear
rm middle.txt
rm output.txt
rm image-output.txt
# rm test.txt
rm dms.txt

python3 -u imageTransform.py
g++ -std=c++17 core.cpp -o core 
./core