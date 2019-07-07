VPATH=.
gg=g++

file=main.o \
	 BlackList.o \
	 Contral.o \
	 DataBase.o \
	 Model.o \
	 Sys.o \
	 UserContral.o \
	 UserModel.o \
	 UserSys.o \
	 UserView.o \
	 View.o 
exe:main
main:$(file)
	g++ -o main $(file)
$(file):

clean:
	rm *.o main
