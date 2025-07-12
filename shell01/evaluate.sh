echo "shell00 EVALUATION SCRIPT BY sandrzej (Szymon Andrzejewski) Monandszy START"
tree
echo "---1---"
cd ex01
cat print_groups.sh
echo "---output for current user (FT_USER)---"
sh print_groups.sh
cd ..

echo "---2---"
cd ex02
cat find_sh.sh
echo "---output for cases: file1.sh, dir/file2.sh,  dir.sh/file3.sh. Valid output: file3 file1 find_sh file2 Invalid: dir.sh, with paths or with .sh---"
touch file1.sh
mkdir dir dir.sh
cd dir
touch file2.sh
cd ..
cd dir.sh
touch file3.sh
cd ..
sh find_sh.sh | cat -e
rm -rf file1.sh dir dir.sh
cd ..

echo "---3----"
cd ex03
cat count_files.sh
echo "---output for Valid: file1 dir/file2. Count of 5: cd, f1, f2, dir, the script---" 
touch file1.sh
mkdir dir
cd dir
touch file.sh
cd ..
sh count_files.sh | cat -e
rm -rf file1.sh dir
cd ..

echo "---4---"
cd ex04
cat MAC.sh
echo "---output should display mac addresses---"
sh MAC.sh
cd ..

echo "---5---"
cd ex05
cat *
echo "---output should have size of 2 and a name, \"\\\?\$*'MaRViN'*\$?\\\", user:group does not matter---"
ls -lRa *MaRV* | cat -e
cd ..

echo "---6---"
cd ex06
cat skip.sh
echo "---output cases: tata, titi, toto, tutu. Should display tata, toto. First full ls, second skip---"
touch tata titi toto tutu
ls -l | cat -e
echo "---"
./skip.sh | cat -e
rm -rf tata titi toto tutu
cd ..

echo "---7---"
cd ex07
cat r_dwssap.sh
echo "--- output, first my script runs without FT_LINE, second yours. FT_LINE1=7 FT_LINE2=15 ---"
export FT_LINE1=7
export FT_LINE2=15
cat /etc/passwd | grep -v '^#' | sed -n '2~2p' | cut -d':' -f1 | rev | sort -r | tr '\n' ',' | sed 's/,/, /g' | sed 's/..$/./'
echo "---"
sh r_dwssap.sh
cd ..

echo "\n---8---"
cd ex08
cat add_chelou.sh
echo "---output, case 1---"
export FT_NBR1="\\'?\"\\\"'\\"
export FT_NBR2="rcrdmddd"
sh add_chelou.sh
echo "---output, case 2---"
export FT_NBR1='\\"\\"!\\"\\"!\\"\\"!\\"\\"!\\"\\"!\\"\\"'
export FT_NBR2="dcrcmcmooododmrrrmorcmcrmomo"
sh add_chelou.sh

echo "---END---"
