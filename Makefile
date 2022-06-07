gitstuff: tests
	./tests
	git add -A
	git commit -a -m "Auto Add"
	git push

tests: asd.cpp main.cpp
	g++ asd.cpp main.cpp -o tests