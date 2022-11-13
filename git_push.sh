#!/bin/bash 
bash clean.sh
echo "Enter message : "  
read mssg  

if [ -z "$mssg" ] 
then  
     echo "Message cannot be Empty" 
       
else 
     echo "Github Message is : $mssg"
     git add .
     git commit -m" $mssg "
     git push
     echo "Changes Pushed to Github Repository! " 
fi 


