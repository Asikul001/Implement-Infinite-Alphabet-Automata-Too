#include "global.hpp"

void entry_point()
{
    data init;
    automata_data_type transition_pair;
    std::map<std::pair<int, std::string>, int> register_update_pair;

    put_data(init, register_update_pair, transition_pair);

    
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();

    int windowWidth  = desktop.size.x - 200;
    int windowHeight = desktop.size.y - 150;

    sf::RenderWindow window(
        sf::VideoMode({(unsigned int)windowWidth,
                       (unsigned int)windowHeight}),"Infinite Automata Tool");

    sf::Font font;
    if (!font.openFromFile("../fonts/DejaVuSans.ttf"))
    {
        std::cout << "Font not loaded\n";
        return;
    }

    //  text
    sf::Text showAutomataRule(font, "", 20);
    showAutomataRule.setFillColor(sf::Color::White);
    showAutomataRule.setPosition({10.f, 10.f});

    sf::Text inputText(font, "", 30);
    inputText.setFillColor(sf::Color::White);

    sf::Text resultText(font, "", 30);
    resultText.setFillColor(sf::Color::Green);

    //  button
    sf::RectangleShape nextButton;
    nextButton.setSize({180.f, 50.f});
    nextButton.setFillColor(sf::Color(80, 80, 200));

    sf::Text buttonText(font, "New String", 25);
    buttonText.setFillColor(sf::Color::White);

    // show automata info
    show_data(init, register_update_pair, transition_pair, showAutomataRule);

    std::string user_input;
    std::string result = " ";

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            
            if (event->is<sf::Event::Closed>())
                window.close();

            
            if (const auto* text = event->getIf<sf::Event::TextEntered>())
            {
                char c = static_cast<char>(text->unicode);

                if (text->unicode == 8)
                {
                    if (!user_input.empty())
                        user_input.pop_back();
                }

                else if (text->unicode == 13)
                {
                    bool accepted = false;

                    if (init.automata_name == "ra" || init.automata_name == "RA")
                    {
                        if (!transition_pair.ra_pair.empty())
                        {
                            std::vector<std::string> reg(init.no_register, "$");

                            accepted = check_register_automata(
                                user_input,
                                reg,
                                register_update_pair,
                                init.init_state,
                                init,
                                transition_pair );
                        }
                        else
                            result = "No Transition Found";
                    }
                    else
                    {
                        if (!transition_pair.dfa_nfa_pair.empty())
                        {
                            accepted = check_dfa_nfa(
                                user_input,
                                init.init_state,
                                init,
                                transition_pair
                            );
                        }
                        else
                            result = "No Transition Found";
                    }

                    if (accepted)
                        result = "String Accepted";
                    else
                        result = "String Rejected";
                }

                else if (text->unicode >= 32 && text->unicode < 128)
                {
                    user_input += c;
                }
            }

            if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouse->button == sf::Mouse::Button::Left)
                {
                    sf::Vector2f mousePos =window.mapPixelToCoords(mouse->position);

                    if (nextButton.getGlobalBounds().contains(mousePos))
                    {
                        user_input.clear();
                        result = " ";
                    }
                }
            }
        }

        inputText.setString("Enter String: " + user_input);

        float inputHeight = inputText.getGlobalBounds().size.y;

        inputText.setPosition({windowWidth / 2.f, 50.f});

        resultText.setString("Result: " + result);
        resultText.setPosition({windowWidth / 2.f, 80.f + inputHeight});
        nextButton.setPosition({windowWidth / 2.f + 30.f,140.f + inputHeight});
        buttonText.setPosition({windowWidth / 2.f + 50.f, 150.f + inputHeight});

        window.clear(sf::Color::Black);

        window.draw(showAutomataRule);
        window.draw(inputText);
        window.draw(resultText);
        window.draw(nextButton);
        window.draw(buttonText);

        window.display();
    }
}