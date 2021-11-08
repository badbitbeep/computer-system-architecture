echo "Run help";
time python3 src/main.py

echo "\nRun test #1"
time python3 src/main.py -f tests/test01.txt tests/out01_1.txt tests/out01_2.txt

echo "\nRun test #2"
time python3 src/main.py -f tests/test02.txt tests/out02_1.txt tests/out02_2.txt

echo "\nRun test #3"
time python3 src/main.py -f tests/test03.txt tests/out03_1.txt tests/out03_2.txt

echo "\nRun test #4"
time python3 src/main.py -f tests/test04.txt tests/out04_1.txt tests/out04_2.txt

echo "\nRun test #5"
time python3 src/main.py -f tests/test05.txt tests/out05_1.txt tests/out05_2.txt

echo "\nRun test #6 (random)"
time python3 src/main.py -n 1000 tests/outrnd_1.txt tests/outrnd_2.txt
