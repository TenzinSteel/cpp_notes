class1: class1.o cat.o dog.o animal.o
	g++ -o $@ $^

class1.o: class1.cpp cat.h dog.h animal.h
 g++ -c $<

cat.o: cat.cpp cat.h animal.h
 g++ -c $<

dog.o: dog.cpp dog.h animal.h
	g++ -c $<

animal.o: animal.cpp animal.h
	g++ -c $<