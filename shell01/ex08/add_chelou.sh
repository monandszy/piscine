#!/bin/bash
FT_NBR1="$FT_NBR1" 
FT_NBR2="$FT_NBR2"
#echo="custom sign input"
#echo="$FT_NBR1"

base5_1=$(echo "$FT_NBR1" | tr "'" '0' | tr '\\' '1' | tr '"' '2' | tr '?' '3' | tr '!' '4')
base5_2=$(echo "$FT_NBR2" | tr 'm' '0' | tr 'r' '1' | tr 'd' '2' | tr 'o' '3' | tr 'c' '4')

#echo "converted to b5"
#echo "$base5_1"
#echo "$base5_2"

base10_1=$(echo "ibase=5; $base5_1" | bc) 
base10_2=$(echo "ibase=5; $base5_2" | bc)

#echo "converted to b10"
#echo "$base10_1"
#echo "$base10_2"

sum=$(echo "$base10_1 + $base10_2" | bc)
#echo "added 1 to 2"
#echo "$sum"

base13=$(echo "obase=13; $sum" | bc)

#echo "converted sum to b13"
#echo "$base13"

base13_c=$(echo "$base13" | tr '0' 'g' | tr '1' 't' | tr '2' 'a' | tr '3' 'i' | tr '4' 'o' | tr '5' ' ' | tr '6' 'l' | tr '7' 'u' | tr '8' 'S' | tr '9' 'n' | tr 'A' 'e' | tr 'B' 'm' | tr 'C' 'f')
#echo "converted to custom signs"
echo "$base13_c"
