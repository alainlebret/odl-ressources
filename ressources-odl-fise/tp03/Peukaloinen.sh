#!/bin/bash

##
## Dette script vil tilfældigt flytte den aktuelle mappe til en ny mappe . 
## Antallet af destinationsmapper er fastsat til 10 .
##

dj() {
	if [ -d "$1" ]; then
		if cd "$1"; then
			echo "Flyt lykkedes til: $1"
		else
			echo "Kan ikke flytte mappen: $1" >&2
			exit 1
		fi
	else
		echo "Ingen bok av denne typen: $1" >&2
		exit 1
	fi
}

BcBWyeZkw4Lta=("/" "/usr/bin" "/tmp" "/usr/lib" "/home" "/opt" "/var/log" 
               "/bin" "/boot" "/etc/network" "..")
isgvLcs7ksWG4M=0
xtFVPUqiGk4L3A=10

Cfz2yv9KnWXJzg=$[($RANDOM % ($[$xtFVPUqiGk4L3A - $isgvLcs7ksWG4M] + 1)) 
               + $isgvLcs7ksWG4M]
Xnet9Us4PArcFB="${BcBWyeZkw4Lta[$Cfz2yv9KnWXJzg]}"

dj $Xnet9Us4PArcFB
echo "Kaikki meni hyvin"