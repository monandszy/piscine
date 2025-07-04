#!/bin/bash
FT1=${FT_LINE1}
FT2=${FT_LINE2}
cat /etc/passwd | grep -v '^#' | sed -n '2~2p' | cut -d':' -f1 | rev | sort -r | sed -n "${FT1},${FT2}p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/..$/./'
# No comments can be present in the passwd file
# sed to print 1 3 5 7.. and remove 2 4 6...
# cut to get rid of everything left of first :
# rev to reverse the names
# sort them alphabetically and remove the end tail
# sort them in reverse and remove the start tail
# tr to replace all nl with , bc it can only do one charachter, correct that with sed, then remove residual char
