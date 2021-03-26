<h3>18_1 istream으로 입력받기</h3>

```cpp
#include <iostream>
#include <string>

using namespace std;

int main(){
    string buf;

    getline(cin, buf);
    cout << cin.gcount() << " " << buf << endl; 

    char vuf[1024];
    cin.ignore();   // ignore input

    // cout << (char)cin.peek() << endl;
    cin.unget();
    // cin.putback('A');
    cin >> buf;
    cout << buf << endl;
}
```

<h3>18_2 ostream으로 출력하기</h3>

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout.setf(std::ios::showpos);	// 양수에 + 붙인다.
	cout << 108 << endl;
	cout.unsetf(std::ios::showpos);	// 다시 취소
	cout << 108 << endl;

	/*cout.unsetf(std::ios::dec);
	cout.setf(std::ios::hex);*/
	// cout.setf(std::ios::hex, std::ios::basefiled);
	cout << hex << 108 << endl;

	cout << std::boolalpha;
	cout << true << " " << false << endl;

    // cout << std::defaultfloat;
	cout << std::fixed;
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;
    
	cout << -12345 << endl;
	cout << std::setw(10) << -12345 << endl;
	cout << std::setw(10) << std::left << -12345 << endl;
	cout << std::setw(10) << std::right << -12345 << endl;
	cout << std::setw(10) << std::internal << -12345 << endl;

	return 0;
}
```

<h3>18_3 문자열 스트립</h3>

```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	stringstream os;

	os << "Hello, World!";	
	// << : insertion operator, >> : extraction operator
	os << "Hello, World!2";
	os.str("Hello, World!");

	string str;
	/*os >> str;*/
	str = os.str();

	cout << str << endl;
	
	return 0;
}
```

```cpp
#include <iostream>
#include <sstream>
using namespace std;

int main() {
	stringstream os;

	int i = 12345;
	double d = 67.89;

	os << i << " " << d;
	
	int i2;
	double d2;
	
	os >> i2 >> d2;
	
	cout << i2 << "|" << d2 << endl;
	
	return 0;
}
```

<h3>18_4 흐름 상태(stream states)와 입력유효성(input validation) 검증</h3>

```cpp
#include <iostream>
#include <cctype>
#include <string>
#include <bitset>
using namespace std;

void printCharacterClassification(const int& i) {
	cout << boolalpha;
	cout << "isalnum" << bool(std::isalnum(i)) << endl;
	cout << "isblank" << bool(std::isblank(i)) << endl;
	cout << "isdigit" << bool(std::isdigit(i)) << endl;
	cout << "islower" << bool(std::islower(i)) << endl;
	cout << "isupper" << bool(std::isupper(i)) << endl;
}

void printStates(const std::ios& stream){
	cout << boolalpha;
	cout << "good()=" << stream.good() << endl;
	cout << "eof()=" << stream.eof() << endl;
	cout << "fail()=" << stream.fail() << endl;
	cout << "bad()=" << stream.bad() << endl;
}

bool isAllDigit(const string & str){
	bool ok_flak = true;

	for(auto e : str)
		if (!std::isdigit(e)) {
			ok_flak = false;
			break;
		}

	return ok_flak;
}

int main() {
	//while (true) {
	//	int i;
	//	cin >> i;

	//	printStates(cin);

	//	/*cout << boolalpha;
	//	cout << std::bitset<8>(cin.rdstate()) << endl;
	//	cout << std::bitset<8>(std::istream::goodbit) << endl;
	//	cout << std::bitset<8>(std::istream::failbit) << endl;
	//	cout << !bool((cin.rdstate() & std::istream::failbit) != 0) << endl;*/

	//	printCharacterClassification(i);

	//	cin.clear();
	//	cin.ignore(1024, '\n');
	//	cout << endl;
	//}

	cout << boolalpha;
	cout << isAllDigit("1234") << endl;
	cout << isAllDigit("a1234") << endl;


	return 0;
}
```

<h3>18_6 기본적인 파일 입출력</h3>

```cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>	// exit()
#include <sstream>

using namespace std;

int main() {
	// writing
	if (true) {
		ofstream ofs("my_first_file.dat");	// ios::app, ios::binary
		// ofs.open("my_first_file.dat");

		if (!ofs) {
			cerr << "Couldn't open file " << endl;
			exit(1);
		}

		/*ofs << "Line 1" << endl;
		ofs << "Line 2" << endl;*/

		const unsigned num_data = 10;
		ofs.write((char*)&num_data, sizeof(num_data));

		for (int i = 0; i < num_data; ++i)
			ofs.write((char*)&i, sizeof(i));
	}

	// reading
	if (true) {
		ifstream ifs("my_first_file.dat");

		if (!ifs) {
			cerr << "Cannot open file" << endl;
			exit(1);
		}

		/*while (ifs)
		{
			std::string str;
			getline(ifs, str);

			std::cout << str << endl;
		}*/

		unsigned num_data = 0;
		ifs.read((char*)&num_data, sizeof(num_data));
		
		for (unsigned i = 0; i < num_data; ++i) {
			int num;
			ifs.read((char*)&num, sizeof(num));

			cout << num << endl;
		}
	}
}
```

<h3>18_7 파일의 임의 위치 접근하기</h3>

```cpp

```