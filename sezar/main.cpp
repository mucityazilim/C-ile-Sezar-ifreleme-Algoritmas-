#include <iostream>
#include <cstdlib>
#include <cstring>
#include <clocale>

using namespace std;

class sezar {
	private : 
	char metin[1024]; 
	char sifreliMetin[1024]; 
	char desifreliMetin[1024]; 
	string alfabe ="abcdefghijklmnopqrstuvywxz" ;  // 26 harf 
						// abcz = defc 
	
	public : 
	void sifrele();
	void desifrele(); 
};

void sezar:: sifrele () 
{
	cout<<"Metin : "; gets(metin); 
	int n= strlen(metin); 
	strlwr(metin); 
	metin[n]='\0'; 
	int i=0,j; 
	while( i < n ) 
	{
		int sonuc=0; 
			
		for( j=0; j<26;j++  ) 
		{
			int indis=j; 
			if( metin[i] == alfabe[j] ) 
			{
				sonuc=1; 
				indis +=3; 
				if(indis>=26)
				indis = indis%26; 
				
				sifreliMetin[i]= alfabe[indis];
				
			}
			if(sonuc==0)
			sifreliMetin[i]= metin[i]; 			
		}
		
		i++; 		
	}
	sifreliMetin[i]='\0'; 
	cout<<"\n\nSifreli Metin     : "<< sifreliMetin<< endl ; 
}


void sezar:: desifrele () 
{

	int n= strlen(sifreliMetin); 
	int i=0,j; 
	while( i < n ) 
	{
		int sonuc=0; 
			
		for( j=0; j<26;j++  ) 
		{
			int indis=j; 
			if( sifreliMetin[i] == alfabe[j] ) 
			{
				sonuc=1; 
				indis -=3; 
				if(indis<0)
				indis = indis + 26; 
				
				desifreliMetin[i]= alfabe[indis];
				
			}
			if(sonuc==0)
			desifreliMetin[i]= sifreliMetin[i]; 			
		}
		
		i++; 		
	}
	
	desifreliMetin[i] ='\0'; 
	cout<<"\n\ndeSifreli Metin   : "<< desifreliMetin<< endl ; 
}







int main(int argc, char** argv) {
	
	sezar s1; 
	s1.sifrele() ; 
	s1.desifrele() ; 
	
	
	return 0;
	
}
