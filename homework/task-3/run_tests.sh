export PYTHONPATH="${PYTHONPATH}:/home/momo/Desktop/computer-system-architecture/homework/task-3"

echo "Run help";
time python3 src/main.py

echo "\nRun test #1"
time python3 src/main.py -f /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/test01.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out01_1.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out01_2.txt

echo "\nRun test #2"
time python3 src/main.py -f /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/test02.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out02_1.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out02_2.txt

echo "\nRun test #3"
time python3 src/main.py -f /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/test03.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out03_1.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out03_2.txt

echo "\nRun test #4"
time python3 src/main.py -f /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/test04.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out04_1.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out04_2.txt

echo "\nRun test #5"
time python3 src/main.py -f /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/test05.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out05_1.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/out05_2.txt

echo "\nRun test #6 (random)"
time python3 src/main.py -n 1000 /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/outrnd_1.txt /home/momo/Desktop/computer-system-architecture/homework/task-3/tests/outrnd_2.txt
