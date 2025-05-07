print("Welcome to SimpleBot! Type 'bye' to exit.\n")

while True:
    user_input = input("You: ").lower()

    if user_input in ["hi", "hello"]:
        print("Bot: Hello! How can I help you?")
    elif user_input == "how are you":
        print("Bot: I'm just a bot, but I'm doing great!")
    elif user_input == "what is your name":
        print("Bot: I'm SimpleBot, your friendly chatbot.")
    elif user_input == "bye":
        print("Bot: Goodbye! Have a nice day!")
        break
    else:
        print("Bot: Sorry, I didn't understand that.")






