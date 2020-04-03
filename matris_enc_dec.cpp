#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

int main(){
	string islem;
	cout<<"lütfen yapmak istediğiniz işlemi yazınız sifrele veya coz ? :";
	getline(cin, islem);

	if(islem=="sifrele"){
	string metin1;
	string kelimeler[30];
	cout<<"lütfen metni yazınız: ";
	getline(cin, metin1);
	int j=0;
	for(int i = 0; i<metin1.length();i++){
		if(metin1[i]==' '){
			j += 1;
		}
		else{
			kelimeler[j] += metin1[i];
		}
	}
	int uzunluk= 0;
	int k_sayisi = 0;
	for(int k=0;k<30;k++){
		if(kelimeler[k] == "\0"){
			break;
		}
		k_sayisi+=1;
		if(kelimeler[k].length() > uzunluk){
			uzunluk = kelimeler[k].length();
		}
	}
	

	string matris[uzunluk][k_sayisi];
	for(int p=0;p<k_sayisi;p++){
		for(int j=0;j<uzunluk;j++){
			if(kelimeler[p][j] != '\0'){
				matris[j][p]=kelimeler[p][j];
			}
			else{
				matris[j][p]= '%';
			}
		}
	}
	ofstream Dosyayaz("/home/keysi/Desktop/sifreli.txt");
	for(int s=0;s<uzunluk;s++){

		for(int t=0;t<k_sayisi;t++){
			cout<<matris[s][t];
			Dosyayaz<<matris[s][t];
		}
		Dosyayaz<<"\n";
	}
		cout<<"\n\nmetnin şifrelenmiş hali budur."<<endl;
		cout<<"\nŞifreli metin /home/keysi/Desktop/sifreli.txt dosyasına kaydedilmiştir.\n";
	Dosyayaz.close();


	}
	else if(islem == "coz"){
	string metin2,metin;
	int Kelime=0;
	ifstream DosyaOku("/home/keysi/Desktop/sifreli.txt");
	int o = 0;
	if(DosyaOku.is_open()){
		
		while(!DosyaOku.eof()){
			getline(DosyaOku,metin);
			metin2 += metin;
			o++;
		}


	}
		DosyaOku.close();
	ifstream dosyaoku2("/home/keysi/Desktop/sifreli.txt");
	string cozulecek[o];
	if(dosyaoku2.is_open()){

		for(int y=0;y<o;y++){
			getline(dosyaoku2,cozulecek[y]);
		}
	}

	

	string metinler;
	for(int g=0;g<cozulecek[0].length();g++){
		for(int r=0;r<o;r++){
			if(cozulecek[r][g]== '%' || cozulecek[r][g]=='/'){
				break;
			}
			else{
				metinler+= cozulecek[r][g];
			}

		}
		metinler += " ";

	}
	cout<<metinler<<endl;
	}
	else{
		cout<<"geçerli bir işlem yazmadınız programdan çıkılıyor\n\n";
	}
