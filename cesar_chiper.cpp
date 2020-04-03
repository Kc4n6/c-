


#include<string.h>
#include<iostream>
#include<fstream>


using namespace std;

int main(){
	char sifreli[100];
	string metin;
	string sifrelimetin;
	int key;
	int islem;
	cout<<"sezar şifreleme sistemine hoşgeldiniz. tu kontinyu in ingiliş pres nayn. :D\nŞaka şaka şifrelemek için 1e şifreyi çözmek için 2 ye basınız: "<<endl;
	cin>>islem;cin.ignore();
if(islem == 1){	
	cout<<"\nLütfen şifrelemek istediğiniz metni giriniz: ";
	getline(cin, metin);
	cout<<"\nlütfen anahtar giriniz(tamsayi): ";
	cin>>key;cin.ignore();
	char sifreli_harf;
	char temp;
	
	int uzunluk= metin.length();
	for(int i=0;i<uzunluk;i++){
		
		char krktr = metin[i];
		if(krktr>96 && krktr<123){
			sifreli_harf = (krktr+key-97)%26;
			temp =sifreli_harf+97;
			sifrelimetin+=temp;
		}
		else if(krktr>=65 && krktr<=90){
			sifreli_harf = (krktr+key-65)%26;
			temp = sifreli_harf+65;
			sifrelimetin+=temp;
		}
		else{
			sifrelimetin+=krktr;
		}
		
	}
	ofstream Yaz("/home/keysi/Desktop/cesar.txt");
	Yaz<<sifrelimetin;
	Yaz.close();
	cout<<"\nşifrelenmiş hali budur./home/keysi/Desktop/cesar.txt dosyasına kaydedildi. şimdi sıra çözümde...==>>"<<sifrelimetin<<"\n\n"<<endl;
}
if(islem == 2){	
	string sifrelimetin2;
	int key1;
	cout<<"lütfen çözüm için key giriniz: ";
	cin>>key1;cin.ignore();
	ifstream Oku("/home/keysi/Desktop/cesar.txt");
	getline(Oku, sifrelimetin2);
	string sifresizmetin1;
	char sifreliharf;
	char temp1;
	for(int j =0;j<sifrelimetin2.length();j++){
		char krktr1= sifrelimetin2[j];
		if(krktr1<=90 && krktr1>=65){
			sifreliharf = (krktr1-key1-65)%26;
			temp1 = sifreliharf+65;
			if(temp1<65){
				temp1= 'Z'-('A'-temp1-1);
			}
			sifresizmetin1 += temp1;
		}
		else if(krktr1<=122 && krktr1>=97){
			sifreliharf= (krktr1-key1-97)%26;
			temp1 = sifreliharf+97;
			if(temp1<97){
				temp1 = 'z'-('a'-temp1-1);
			}
			sifresizmetin1 += temp1;
		}
		else{
			sifresizmetin1 += sifrelimetin2[j];
		}
	}
	cout<<"\nVerdiğiniz key ile çözümlenmiş hali budur...>>>"<<sifresizmetin1<<endl;
}
}
