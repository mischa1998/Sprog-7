//                 lexer.h 2017
#ifndef LEXER_H
#define LEXER_H
#include "baselexer.h"
//********************************************
//*        Developed by  xxx		     *
//*             (c)  2017                    *
//********************************************
class tLexer:public tBaseLexer{
public:
// персональный код разработчика
 std::string Authentication()const{
                     return "xxx"
                +std::string("17");}
//конструктор
 tLexer():tBaseLexer(){
//создать автоматы:

//  ноль Azero
    addstr  (Azero,0,"+-", 2);
    addstr  (Azero,0,"0",  1);
    addstr  (Azero,2,"0",  1);
    addstr  (Azero,1,"0",  1);
  Azero.final(1);

//________________________________________

// целое число
    addstr(Aint, 0, "0", 1);
	addstr(Aint, 1, "0", 1);
	addrange(Aint, 1, '1','9', 2);
	addrange(Aint, 2, '0','9', 2);
	addrange(Aint, 0, '1','9', 2);
	addstr(Aint, 0, "+-", 3);
	addstr(Aint, 3, "0", 1);
	addrange(Aint, 3, '1','9', 2);
  Aint.final(2);
//________________________________________

// вещественное
	addstr(Afloat,0,"+-",5);
	addstr(Afloat,0,".",11);
	addrange(Afloat,11,'0', '9',6);
	addrange(Afloat,0,'1', '9',2);
	addstr(Afloat,0,"0",3);
	addstr(Afloat,3,"0",3);
	addrange(Afloat,3,'1', '9',2);
	addrange(Afloat,2,'0', '9',2);
	addstr(Afloat,2,".",4);
	addstr(Afloat,2,"eE",7);
	addstr(Afloat,5,".",4);
	addstr(Afloat,5,"0",3);
	addrange(Afloat,5,'1', '9',2);
	addrange(Afloat,4,'0', '9',6);
	addstr(Afloat,4,"eE",7);
	addrange(Afloat,6,'0', '9',6);
	addstr(Afloat,6,"eE",7);
	addrange(Afloat,7,'0', '9',8);
	addrange(Afloat,8,'0', '9',8);
	addstr(Afloat,7,"+-",9);
	addrange(Afloat,9,'0', '9',10);
	addrange(Afloat,10,'0', '9',10);
	
	Afloat.final(4);
	Afloat.final(6);
	Afloat.final(8);
	Afloat.final(10);
//________________________________________

// строка
//  –≈јЋ»«ќ¬ј“№ escape-последовательности:
// \'  \"  \?  \\  \a  \b  \f  \n  \r  \t  \v
    const char SP=' ';// пробел
    addrange  (Astr,0,'"','"',   1);
    addrange(Astr,1,SP,'!',1);
    addrange(Astr,1,'#','[',1);
    addrange(Astr,1,']','~',1);
    addrange(Astr,1,'\x80','\xff',1);// русские буквы
	addrange(Astr, 1, '"', '"', 3);
	addstr(Astr, 1, "\\", 2);
	addstr(Astr, 2, "abfnrtv?", 1);
	addrange(Astr, 2, '"', '"', 1);
	addstr(Astr, 2, "\\", 1); 


	Astr.final(3);
//________________________________________

// идентификатор
    addrange(Aid,0,'a','z',2);
	addrange(Aid,0,'A','Z',2);
	addrange(Aid,0,'0','9',1);
	addstr(Aid,0,"!",3);
	addstr(Aid,3,"-",1);
	addstr(Aid,0,"-",4);
	addstr(Aid,0,"!",3);
	addrange(Aid,4,'a', 'z', 2);
	addrange(Aid,4,'A', 'Z', 2);
	addrange(Aid,4,'0', '9', 4);
	addstr(Aid,4,"-!", 2);
	addrange(Aid,3,'a', 'z', 2);
	addrange(Aid,3,'A', 'Z', 2);
	addrange(Aid,3,'0', '9', 2);
	addrange(Aid,2,'a', 'z', 2);
	addrange(Aid,2,'A', 'Z', 2);
	addrange(Aid,2,'0', '9', 2);
	addstr(Aid,2,"-!", 2);
	addstr(Aid,3,"!", 2);
    Aid.final(2);
	Aid.final(3);

//________________________________________

// идентификатор предиката
    addrange(Aidq,0,'0', '9',1);
	addrange(Aidq,0,'a', 'z',2);
	addrange(Aidq,0,'A', 'Z',2);
	addstr(Aidq,0,"-",3);
	addstr(Aidq,0,"?",4);
	addstr(Aidq,3,"?",1);
	addstr(Aidq,3,"-",2);
    addrange(Aidq,3,'0', '9',2);
	addrange(Aidq,3,'a', 'z',2);
	addrange(Aidq,3,'A', 'Z',2);
	addstr(Aidq,2,"-",3);
    addrange(Aidq,2,'0', '9',2);
	addrange(Aidq,2,'a', 'z',2);
	addrange(Aidq,2,'A', 'Z',2);
	addstr(Aidq,2,"?",4);
	addstr(Aidq,4,"?",4);
	addstr(Aidq,4,"-",3);
    addrange(Aidq,4,'0', '9',2);
	addrange(Aidq,4,'a', 'z',2);
	addrange(Aidq,4,'A', 'Z',2);
  Aidq.final(4);
//________________________________________

// оператор
    addstr  (Aoper,0,"+-*/=", 1);
	addstr  (Aoper,0,"><", 2);
	addstr  (Aoper,2,"=", 3);
	addrange  (Aoper,1,'!', '~', 4);
	addrange  (Aoper,2,'!', '<', 4);
	addrange  (Aoper,2,'>', '~', 4);
	addrange  (Aoper,3,'!', '~', 4);
    Aoper.final(1);
	Aoper.final(2);
	Aoper.final(3);
//________________________________________

// булевские константы
    addstr  (Abool,0,"#",   1);
    addstr  (Abool,1,"tf",  2);
  Abool.final(2);
//________________________________________
}
};
#endif

