/* Write a program, which generates a random advertising message for some product.
The message has to consist of laudatory phrase, followed by a laudatory story,
followed by author (first and last name) and city,
which are selected from predefined lists.
For example, let’s have the following lists:

-     Laudatory phrases: {"The product is excellent.",
"This is a great product.", "I use this product constantly.", 
"This is the best product from this category."}.

-     Laudatory stories: {"Now I feel better.",
"I managed to change.", 
"It made some miracle.", 
"I can’t believe it, but now I am feeling great.",
"You should try it, too. I am very satisfied."}.

-     First name of the author: {"Dayan", "Stella", "Hellen", "Kate"}.

-     Last name of the author: {"Johnson", "Peterson", "Charls"}.

-     Cities: {"London", "Paris", "Berlin", "New York", "Madrid"}.

Then the program would print randomly generated advertising message like the following:

I use this product constantly. You should try it, too. 
I am very satisfied. -- Hellen Peterson, Berlin*/

#include <iostream>
#include <array>

std::string laudPhrases[4] = {"The product is excellent.",
                            "This is a great product.",
                            "I use this product constantly.", 
                            "This is the best product from this category."};

std::string laudStories[5] = {"Now I feel better.",
                            "I managed to change.", 
                            "It made some miracle.", 
                            "I can’t believe it, but now I am feeling great.",
                            "You should try it, too. I am very satisfied."};

std::string authFirstNames[4] = {"Dayan", "Stella", "Hellen", "Kate"};

std::string authLastNames[3] = {"Johnson", "Peterson", "Charles"};

std::string cities[5] = {"London", "Paris", "Berlin", "New York", "Madrid"};
  
std::string random_string(std::string string_array[]); 

class AdMessage
{

public:
    
    std::string adLaudPhrase;
    std::string adLaudStory;
    std::string adAuthFirstName;
    std::string adAuthLastName;
    std::string adCity;

    AdMessage(); 

    AdMessage(std::string laudPhrase,
            std::string laudStory,
            std::string authFirstName,
            std::string authLastName,
            std::string city);
    ~AdMessage();
};

AdMessage::AdMessage()
{
    adLaudPhrase = "Empty";
    adLaudStory = "Empy";
    adAuthFirstName = "Empty";
    adAuthLastName = "Empty";
    adCity = "Empty"; 
}

AdMessage::AdMessage(std::string laudPhrase,
            std::string laudStory,
            std::string authFirstName,
            std::string authLastName,
            std::string city)
{
    adLaudPhrase = laudPhrase;
    adLaudStory = laudStory;
    adAuthFirstName = authFirstName;
    adAuthLastName = authLastName;
    adCity = city;
}

AdMessage::~AdMessage()
{
    
}

std::string random_string(std::string string_array[])
{
    return string_array[random()%sizeof(string_array)/sizeof(string_array[0])]; 
}

int main(int argc, char const *argv[])
{

    AdMessage myMessage(random_string(laudPhrases),random_string(laudStories), random_string(authFirstNames), random_string(authLastNames), random_string(cities));

    std::cout<<myMessage.adLaudPhrase<<" "<<myMessage.adLaudStory<<" "<<myMessage.adAuthFirstName<<" "<<myMessage.adAuthLastName<<" - "<<myMessage.adCity<<'\n';
 


    return 0;
}

