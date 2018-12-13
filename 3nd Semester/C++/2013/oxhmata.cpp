#include "oxhmata.h"
#include <iostream>

using std::string;

 oxhmata::oxhmata(){
 }

	int oxhmata::get_nero(){
		return nero;
	};
	     
	int oxhmata::get_kausima(){
		return kausima;
	}
	  
	int oxhmata::get_kat_kaus(){
		return kat_kaus;
	}
	 
	int oxhmata::get_kat_nero(){
		return kat_nero;
	};
	     
	int oxhmata::get_katastash(){
		return katastash;
	}

	int oxhmata::get_type(){
		return type;
	}
	     
	int oxhmata::get_age(){
		return age;
	}
	      
	int oxhmata::get_id(){
		return id;
	}

	string oxhmata::get_name(){
		return name;
	}
	      
	void oxhmata::set_nero( int a){
		nero=a;
	}
	    
	void oxhmata::set_kausima(int a){
		kausima=a;
	}
	 
	void oxhmata::set_kat_kaus(int a){
		kat_kaus=a;
	}
	    
	void oxhmata::set_kat_nero(int a){
		kat_nero=a;
	};

	void oxhmata::set_katastash(int a){
		katastash=a;
	}
	void oxhmata::set_type(int a){
		type=a;
	}
	 
	void oxhmata::set_age(int a){
		age=a;
	}
	     
	void oxhmata::set_id(int a){
		id=a;
	}
	                 
    void oxhmata::decr_nero(){
    	nero = nero - kat_nero;
    }

    void oxhmata::decr_kausima(){
    	kausima = kausima - kat_kaus;
    }

    void oxhmata::auxisi_hl(){
    	age++;
    }