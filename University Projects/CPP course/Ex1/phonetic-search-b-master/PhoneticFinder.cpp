#include "PhoneticFinder.hpp"
#include <iostream>
#include <sstream> 
#include <algorithm>
#include <cctype>
#include <string> 
using namespace std;

namespace phonetic {
       bool change_in_word(string temp,string word){
        //////////////////////////////////////////////////////
    	// returns true if we can make changes to the word
        int i=0; //index for iteration
        bool we_can_change_char=true; //this will tell the loop that it can change the char, and will continue to the next char
        while(i<=temp.length()-1){  //we will iterate the strings
            if(temp[i]!=word[i]&&we_can_change_char==true){ //if a char is different we will try to see if we can change it
            //if we can change the char, we will continue, if we got to the end, we done
                we_can_change_char=false; //if this stays false, we can't make changes to the string, so we end it here
                //if one of the conditions will applys it will get the loop going, and the advance the index

                if((temp[i]=='d'&& word[i]=='t')||(temp[i]=='t'&& word[i]=='d')){  // d and t
                     i++;
                     we_can_change_char=true;
                }
                if((temp[i]=='o'&& word[i]=='u')||(temp[i]=='u'&& word[i]=='o')){    // o and u
                     i++;
                     we_can_change_char=true;
                }
                if((temp[i]=='i'&& word[i]=='y')||(temp[i]=='y'&& word[i]=='i')){    // y and i
                     i++;
                     we_can_change_char=true;
                }
                if((temp[i]=='s'&& word[i]=='z')||(temp[i]=='z'&& word[i]=='s')){    // s and z
                     i++;
                     we_can_change_char=true;
                }
                 if((temp[i]=='g'&& word[i]=='j')||(temp[i]=='j'&& word[i]=='g')){    // g and j
                     i++;
                     we_can_change_char=true;
                }
                if((temp[i]=='w'&& word[i]=='v')||(temp[i]=='v'&& word[i]=='w')){    // v and w
                     i++;
                     we_can_change_char=true;
                }
                if((temp[i]=='g'&& word[i]=='j')||(temp[i]=='j'&& word[i]=='g')){    // g and j
                     i++;
                     we_can_change_char=true;
                }
                // b and f and p
                if((temp[i]=='b'&& word[i]=='f')||(temp[i]=='b'&& word[i]=='p')||(temp[i]=='f'&& word[i]=='b')||(temp[i]=='f'&& word[i]=='p')||(temp[i]=='p'&& word[i]=='b')||(temp[i]=='p'&& word[i]=='f')){    
                     i++;
                     we_can_change_char=true;
                }
                // c and k and q
                if((temp[i]=='c'&& word[i]=='k')||(temp[i]=='c'&& word[i]=='q')||(temp[i]=='k'&& word[i]=='c')||(temp[i]=='k'&& word[i]=='q')||(temp[i]=='q'&& word[i]=='c')||(temp[i]=='q'&& word[i]=='k')){   
                     i++;
                     we_can_change_char=true;
                }
            }else{
            i++; //if the char is the same char, we will continue
            }

        }


return we_can_change_char;
       }
        ////////////////////////////////////////////////////// 




     string return_without_spaces(string str){
          string::iterator end_pos = remove(str.begin(), str.end(), ' ');
          str.erase(end_pos, str.end());
          return str;
     }

	string find(string text, string word){
          
if(word==""||word==" "){ //Word is empty or just a space
      throw runtime_error {"The "+ word+" is invalid word"};
}   
//we need to return the text with caps on so we will store the text in a temp value, we will name it text2
string text2=text;

    //////////////////////////////////////////////////////
    	// convert strings to lower case
	transform(text.begin(), text.end(), text.begin(), ::tolower); 
     transform(word.begin(), word.end(), word.begin(), ::tolower); 

    //////////////////////////////////////////////////////
  	// Search for spaces in a text, if the text is the same as word when removing spaces, we will return the text without spaces
     if(return_without_spaces(text)==word){
    return return_without_spaces(text2);
    };
    //////////////////////////////////////////////////////

    //////////////////////////////////////////////////////
    	// Search word in text, if its finds it return the word
     if(text==word){
    return text2;
    };
    


 
    //////////////////////////////////////////////////////
    // Iteration over text
    string temp=""; //We will use this string to hold a word from text
    int counting_index_from_word=0; //we will use the counter for a sub string splitter this will mark the begining of temp index
    int counter_place_holder=0; //in order to take the next word in a sentence we will need to reset the counter when the iterator meets a new word
    int how_much_to_slice=0; //we will use the counter for a sub string splitter this will how much we are going to slice from text
    bool first_slice=false; //Ajusting the first slice with a flag
    int i=0;
    while(i<=text.length()-1){
         
        //counting_index_from_word++; //Advancing the counter
        how_much_to_slice++;
        //if we got to the end of a word, or the end of the text
        if(text[i]==' '||i==text.length()-1){
            if(i==text.length()-1&&first_slice==true){
                how_much_to_slice++;
                counting_index_from_word++;
            }
             if(text[i]==' '&&first_slice==true&&i!=text.length()-1){
                counting_index_from_word++;
                 how_much_to_slice--;
            }
       
            if(text[i]==' '&& first_slice==false){
                how_much_to_slice--;
                 first_slice=true;
            }
            counter_place_holder=counting_index_from_word; //puting the index in the place order
            counting_index_from_word=i; //reset the counter
            temp=text.substr(counter_place_holder,how_much_to_slice);//Slice the word from text
            how_much_to_slice=0;
         //   
        }
       
        if((temp.length()==word.length())&&(change_in_word(temp,word)==true)){ //If the word is the same length as temp, we need to preform some actions, if not we will continue to the next word
                 if (text.length() > word.length()){
                 temp = text2.substr(text.find(temp),word.length());
                 return temp;
                };
             return temp; //the word can be modified to be the same as temp
        }    
        //index++
         i++; 
 
}

    //////////////////////////////////////////////////////
    	// Check if the word is empty  
     if(word.find_first_not_of(' ') != string::npos){
       throw runtime_error {"The "+ word+" is invalid word"};
     }   
     if(text.empty()|| text.find_first_not_of(' ') != string::npos){
      throw runtime_error {"The "+ text+" is invalid"};
     }   
    //////////////////////////////////////////////////////

throw runtime_error("Did not find the word '"+word+"' in the text");

return NULL;

}}
