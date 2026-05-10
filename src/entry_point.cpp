#include "global.hpp"

void entry_point()
{
    data init;
    automata_data_type transition_pair;
    std::map<std::pair<int, std::string>, int> register_update_pair;

    put_data(init,register_update_pair,  transition_pair);
  

    //window setup
    sf::VideoMode desktop =sf::VideoMode::getDesktopMode();
    int windowWidth =desktop.width - 200;
    int windowHeight =desktop.height - 150;
    sf::RenderWindow window(
    sf::VideoMode(windowWidth - 200,windowHeight - 150
    ),
    "Infinite Automata Tool",
    sf::Style::Default
    );

    // font setup
    sf::Font font;

    if (!font.loadFromFile(
        "../fonts/DejaVuSans.ttf"))
    {
        return;
    }
    

    //text setup 
    // show Automata Rule
    sf::Text showAutomataRule;
    showAutomataRule.setFont(font);
    showAutomataRule.setCharacterSize(20);
    showAutomataRule.setFillColor(sf::Color::White);
    showAutomataRule.setPosition(10.f, 10.f);

   // for take input from user
    sf::Text inputText;
    inputText.setFont(font);
    inputText.setCharacterSize(35);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(windowWidth / 2.f ,50.f);

  // for output
   sf::Text resultText;
    resultText.setFont(font);
    resultText.setCharacterSize(35);
    resultText.setFillColor(sf::Color::Green);
    resultText.setPosition(windowWidth / 2.f ,100.f);


      //button
      // Button box
  sf::RectangleShape nextButton;
  nextButton.setSize(sf::Vector2f(180.f, 50.f));
  nextButton.setFillColor(sf::Color(80, 80, 200));
  nextButton.setPosition(windowWidth / 2.f + 30.f,180.f);

  // Button text
  sf::Text buttonText;
  buttonText.setFont(font);
  buttonText.setCharacterSize(25);
  buttonText.setFillColor(sf::Color::White);
  buttonText.setString("New String");
  buttonText.setPosition(windowWidth / 2.f + 55.f,190.f);

     
    show_data(init,register_update_pair, transition_pair,showAutomataRule);
    std::string user_input;
    std::string result = " ";

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // Keyboard input
            if (event.type == sf::Event::TextEntered)
            {
                // Backspace
                if (event.text.unicode == 8)
                {
                    if (!user_input.empty())
                    {
                        user_input.pop_back();
                    }
                }
                // Enter key
                else if (event.text.unicode == 13)
                {
                    if (user_input == "exit")
                    {
                        window.close();
                    }

                    bool accepted = false;

                    if (init.automata_name == "ra" ||init.automata_name == "RA")
                    {
                        if (!transition_pair.ra_pair.empty())
                        {
                            std::vector<std::string>
                            register_value(init.no_register,"$" );
                            accepted =check_register_automata(
                                    user_input,
                                    register_value,
                                    register_update_pair,
                                    init.init_state,
                                    init,
                                    transition_pair
                                );
                        }
                        else
                        {
                            result ="Please enter Transition";
                        }
                    }
                    else
                    {
                        if (!transition_pair.dfa_nfa_pair.empty())
                        {
                            accepted =check_dfa_nfa(
                                    user_input,
                                    init.init_state,
                                    init,
                                    transition_pair
                                );
                        }
                        else
                        {
                            result ="Here is No Transition";
                        }
                    }
                    if (accepted)
                    {
                        result ="String is Accepted";
                    }
                    else if (result !="Please enter Transition" &&result !="Here is No Transition")
                    {
                        result = "String is Rejected";
                    }
                }
                // Normal typing
                else if (event.text.unicode >= 32 &&event.text.unicode < 128)
                {
                    user_input += static_cast<char>(event.text.unicode );
                }
            }
       // Mouse click
    if (event.type ==sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button ==sf::Mouse::Left)
        {
            sf::Vector2f mousePos(
                event.mouseButton.x,
                event.mouseButton.y
            );
            if (nextButton
                .getGlobalBounds()
                .contains(mousePos))
            {
                user_input.clear();
                result = " ";
            }
        }
    }

}
        

        std::string displayInput ="Enter String: ";
        float maxWidth = 300.f;
        std::string currentLine ="Enter String: ";
        for (char c : user_input)
        {
            sf::Text tempText;
            tempText.setFont(font);
            tempText.setCharacterSize(20);
            std::string testLine =currentLine + c;
            tempText.setString(testLine);
            // line break
            if (tempText.getLocalBounds().width > maxWidth)
            {
                displayInput += '\n';
                currentLine.clear();
            }

            displayInput += c;
            currentLine += c;
        }
        // Set input text
        inputText.setString(
            displayInput
        );
        // Get current input height
        float inputHeight =inputText.getGlobalBounds().height;
        // Move result down
        resultText.setPosition(windowWidth / 2.f,80.f + inputHeight);
        resultText.setString("Result : "+ result);
        // Move button down
        nextButton.setPosition(windowWidth / 2.f + 30.f,140.f + inputHeight);
        buttonText.setPosition(windowWidth / 2.f + 55.f,150.f + inputHeight);
        
        window.clear(sf::Color::Black);
        window.draw(showAutomataRule);
        window.draw(inputText);
        window.draw(resultText);
        window.draw(nextButton);
        window.draw(buttonText);
        
        window.display();
    }
}