all:
	g++ main.cpp Physician.cpp Update.cpp Patient.cpp validateInput.cpp -o Patient 


clean:
	rm -f a.out *.o Patient 
