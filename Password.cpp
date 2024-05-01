#include "Password.h"
#include <string>
#include <sstream>
using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string password){
	bool upper = false;
	bool lower = false;
	for(int i = 0; i < (int)password.size(); i++){
		if(islower(password[i]) > 0){
			lower = true;
		}
		if(isupper(password[i]) > 0){
			upper = true;
		}
	}
	if(upper == true && lower == true){
		return true;
	}
	else{
		return false;
	}
}

void Password::set(string password){
	if(password.size() > 7 && password.size() < 20){
		if(count_leading_characters(password) < 4){
			if(has_mixed_case(password)){
				if(pass_history.size() > 0){
					bool found = false;
					for(int i = 0; i < pass_history.size(); i++){
						if(pass_history[i] == password){
							found = true;
						}
					}
					if(found == false){
						pass_history.push_back(password);
					}
				}
				else{
					pass_history.push_back(password);
				}
			}
		}
	}
}

bool Password::authenticate(string password){
	if(pass_history[pass_history.size() - 1] == password){
		return true;
	}
	else{
		return false;
	}
}

Password::Password(){
	set("ChicoCA-95929");
}
