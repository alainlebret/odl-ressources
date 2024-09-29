#!/bin/bash

#
# ENSICAEN
# 6 Boulevard Maréchal Juin 
# F-14050 Caen Cedex 
# 
# This file is owned by ENSICAEN.
# No portion of this document may be reproduced, copied
# or revised without written permission of the authors.
#

# Author: Jean Saigne <jean.saigne@ecole.ensicaen.fr>
# Version 1.0 2030/01/01

while :
 do
    clear
    echo "--------------------------------------"
    echo " Main Menu "
    echo "--------------------------------------"
    echo "[1] Display date/time"
    echo "[2] Display files in current directory"
    echo "[3] Display calendar"
    echo "[4] Display local weather"
    echo "[5] Exit/Stop"
    echo "======================================"
    echo -n "Enter your choice [1-5]: "
    read yourch

    case $yourch in
      1) echo "Today is `date` , press a key..." ; read ;;
      2) echo "Files in `pwd`" ; ls -l ; echo "Press a key..." ; read ;;
      3) cal ; echo "Press a key..." ; read ;;
      4) echo "Press a key..." ; read ;;
      5) exit 0 ;;
      *) echo "Opps!!! Please select choice 1 to 5";
         echo "Press a key..." ; read ;;
    esac
done

