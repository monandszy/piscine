echo "shell00 evaluation script by sandrzej Szymon Andrzejewski START"
tree
echo "---0---"
cd ex00
cat z
cd ..

echo "---1---"
cd ex01
tar -xf testShell00.tar
ls -l
rm -rf testShell00
cd ..

echo "---2---"
cd ex02
tar -xf exo2.tar
ls -l
rm -rf test0 test1 test2 test3 test4 test5 test6
cd ..

echo "---3---"
cd ex03
cat id_rsa_pub
echo "---output---"
ls -l
cd ..

echo "---4---"
cd ex04
cat midLS
echo "---output---"
cd ..
sh ex04/midLS

echo "---5---"
cd ex05
cat git_commit.sh
echo "---output---"
cd ..
sh ex05/git_commit.sh | cat -e

echo "---6---"
cat <<EOF > .gitignore
*.log
EOF
cd ex06
cat git_ignore.sh | cat -e
echo "---output, expected file.log (as ignored)---"
touch file.log
cd ..
sh ex06/git_ignore.sh
cd ex06
rm -rf file.log
cd ..

echo "---7---"
cp resources/a ex07/a
cp resources/sw.diff ex07/sw.diff
cd ex07
cat b
echo "---output, expected none---"
diff a b > sw2.diff
diff sw.diff sw2.diff
rm -rf sw2.diff a sw.diff
cd ..

echo "---8---"
cd ex08
cat clean
echo "---output, expected data/test~ , data/\#test\# ---"
mkdir data data\# data/\#ben
touch data\#/test\#
touch data/\#test\#
touch data/test~
touch data/test\#test\#
touch data/test\#\#
touch data/test\#
touch data/\#ben/9\#
sh clean
rm -rf data data\#
cd ..

echo "---9---"
cd ex09
cat ft_magic
echo "---output---"
cat <<EOF > test
0000000000000000000000000000000000000000042
EOF
echo "---xxd byte output of test file---"
xxd test
echo "---file -m ft_magic test command, expected output: test: 42 file---"
file -m ft_magic test

echo "END"
