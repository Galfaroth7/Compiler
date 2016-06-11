

#include "Scanner.h"
#include "Token.h"
#include "Parser.h"
#include <iostream>
#include <sstream>
#include <cstdlib>


void printValue(Token& t) {
	std::cout << "Value: ";
	switch (t.getType()) {
	case Token::Type::AndOperator: std::cout << "&&"; break;
	case Token::Type::AssignmentOperator: std::cout << "="; break;
	case Token::Type::BuildOperator: std::cout << "->"; break;
	case Token::Type::Colon: std::cout << ":"; break;
	case Token::Type::OpenBrace: std::cout << "{"; break;
	case Token::Type::CloseBrace: std::cout << "}"; break;
	case Token::Type::OpenBracket: std::cout << "("; break;
	case Token::Type::CloseBracket: std::cout << ")"; break;
	case Token::Type::OrOperator: std::cout << "||"; break;
	case Token::Type::For: std::cout << "for"; break;
	case Token::Type::If: std::cout << "if"; break;
	case Token::Type::Else: std::cout << "else"; break;
	case Token::Type::In: std::cout << "in"; break;
	case Token::Type::EqualOperator: std::cout << "=="; break;
	case Token::Type::Eof: std::cout << "EOF"; break;
	case Token::Type::Dot: std::cout << "."; break;
	case Token::Type::Quote: std::cout << "\""; break;
	case Token::Type::UnknownToken: std::cout << "Unknown"; break;
	default: std::cout << t.getStringValue();
	}
	std::cout << std::endl << std::endl;
}


int main()
{

	//std::istringstream in("my_fun($a){ for($b in $list) { hello: $b -> \"g++ -c hello.c\" } }  $a = windows \n $b = linux \n hello: {hello.cpp hello.h} -> \"g++ -c hello.c\" if($a == window && $b == linux && $c == unix ) hello: {hello.cpp hello.h} -> \"g++ -c hello.c\"");
	//std::istringstream in("$a = alfa $b = beta $c = gamma.exe $d = {a.exe} $e = {abecadlo b.exe c $d e f g h} $f = {a b}     $d.exe : {} -> \"g++ hello.c \"");
	
	//std::istringstream in("$a = alfa $b = beta $c = kappa if($c == kappa && ($a == alfa || $a == beta) && $a == alfa) a.exe : {} -> \"g++ hello.c \"");
	std::istringstream in("$a = alfa $b = beta hello.o : {} -> \"g++ hello.c\" hello.exe : {hello.o}  -> \"g++ hello.o \" ");
	Parser parser(in);
	parser.parse();
	//system("echo Jestem");
	getchar();
	return 0;
}


/*
Powiedzmy, ze przypisywanie do zmiennych dziala
Teraz trzeba spróbowaæ zrobiæ wykonanie polecenia budowania
Jeœli chodzi o targety to trzeba je zrobic map¹ (string + bool) gdzie bool oznacza czy dany plik ju¿
byl zbudowany
Do targetów powinno byæ dodawane przy tworzeniu drzewa
Trzeba zalozyc ze uzytkownik nie bedzie chcial w jednym pliku kilkakrotnie budowac tego samego
(bo wtedy jeden skrypt najpierw by cos zbudowal, a potem nadpisal to co zbudowal)
ale pewnie i tak trzeba to sprawdzaæ (zapytaæ o to Grochowskiego -- najlepiej w czwartek)
Powalczyc z testami - zastanowic sie ktore metody upubliczniæ

Wtorek 17:49 ->
dzia³a build, ale bez obs³ugi targetów
binary expression siê (chyba) dobrze wylicza
dzia³a if bez elsa






Ogolnie zrefaktoryzowac ten kod, bo jest strasznie slaby
*/