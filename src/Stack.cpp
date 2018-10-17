#include "Stack.hpp"
#include <sstream>

Stack::Stack()
{
	stackbasi = new Dugum("1",NULL,0);
}

bool Stack::IsEmpty() const
{
	return stackbasi==NULL;
}

void pushFactoriel(const int& factorielValue)throw(SinirDisinda){
	Dugum* gez = stackbasi;

	if(factorielValue<0)throw SinirDisinda("Girilen deger gecersiz.");
	
	else if(stackbasi==NULL && (factorielValue == 0 || factorielValue == 1))
	{
		if(factorielValue==0)
			stackbasi= new Dugum("1",NULL,0);
		if(factorielValue == 0)
			stackbasi = new Dugum("1" , NULL , 1);
	}
	else if(factorielValue == gez->valueOfFactoriel){
		cout << gez->eleman << endl;
	}
	else if(factorielValue < gez -> value){
		while(1)
		{
			gez = gez->ileri;
			if(factorielValue == gez->vale)
			{
				cout << gez->eleman << endl;
				break;
			}
		}
	}
	else{
		int islemSayisi = factorielValue - gez -> value;
		Islem(islemSayisi,gez->value,gez->eleman);
	}
}

void pop() throw(ElemanYok){
	if(IsEmpty())throw ElemanYok("Eleman Yok");
	Dugum *del = stackbasi;
	stackbasi = stackbasi ->ileri;
	delete del;
}

string& top() const throw(ElemanYok){
	if(IsEmpty())throw ElemanYok("Eleman Yok");
	return stackbasi->eleman;
}

void Islem(int islemSayisi, int ensonFaktöriyel, string ensonFaktöriyelSonuc)
{
	//İslem Sayisi
	for(int i=1;i<=islemSayisi;i++){
		ensonFaktöriyel++;

		ostringstream convert;
		convert<<sayi;
		string carpilacakSayi = convert.str();

		string toplam[carpilacakSayi.length()];

		//Carpma İslemi
		for(int j = 0; j<carpilacakSayi.length(); j++)
		{
			int elde = 0;
			for(int k = 0; k < ensonFaktöriyelSonuc.length(); k++)
			{
				int carpimSonuc;
				int kalan;
				
				int sayi1 = ensonFaktöriyelSonuc[k] - '0';
				sayi1 = sayi1 + elde;
				int sayi2 = carpilacakSayi[j] - '0';
				carpimSonuc=sayi1*sayi2;

				int kalan = carpimSonuc%10;
				convert << kalan;

				elde = carpimSonuc/10;
				if(k==0){
					toplam[0] = convert.str();
					continue;
				}
				toplam[k] = kalan + toplam[k];

				if(k == ensonFaktöriyelSonuc-1 && elde!=0)
				{
					convert<< elde;
					toplam[k] = convert.str() + toplam[k];
				}

			}
		}
		//toplama işlemine hazırlık(toplama için boşluk tamamlama)

		//burada carpma işlemi altında oluşan toplama sonuçlarının
			//işlem yapabilmek için son kısımlarının 0 ile tamamlanmalrı yapılmıştır.
		for(int a = 0; a < carpilacakSayi.length() ; a++ )
		{
			for(int k=a ; k>0; k++)
			{
				toplam[a] = toplam[a] + "0";
			}
			
		}

		//toplamların başına 0 ekleme kısmı
		int enUzunToplamIfadesi=toplam[carpilacakSayi.length()].length();
		for(int i=0; i<carpilacakSayi.length()-1; i++)
		{
			int uzunlukFarkı = toplam[carpilacakSayi.length-1]= toplam[i];
			if(uzunlukFarkı == 0){
				continue;
			}
			for(int m=0; uzunlukFarkı > m ; m++)
			{
				toplam[i] = "0" + toplam[i];
			}
		}

		//toplama Kısmı
		string toplamSonuc;
		for(int i=0 ; enUzunToplamIfadesi > i ;i++)
		{
			
			int toplamSayilar = 0;
			int elde;
			int kalan;

			toplamSayilar = elde;
			for(int k=0 ; k<carpilacakSayi.length();k++)
			{
				toplamSayilar = toplamSayilar + ((toplam[k])[i] - '0');
				if(k==(carpilacakSayi.length()-1)
				{
					elde = toplamSayilar/10;
					kalan = toplamSayilar%10;
				}
			}

				convert<<kalan;
			if(i == 0)
				{
					
					toplamSonuc = convert.str();
					continue;
				}
				toplamSonuc = convert.str() + toplamSonuc;
				


		}
	}

}

void makeEmpty(){
	while(!IsEmpty())
		pop();
}

~Stack(){
	makeEmpty();
}