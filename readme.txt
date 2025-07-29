Resources:
    1. Google AI overview used to find the "to_string()" function with the Google search "how to convert double to string c++" (does not provide any sources)
    2. I got bored and decided to download VScode to my computer so I could be able to access my projects when I was done
        with this course. As a test, I decided to make a randomizer that would grab a random object from a vector list.
        After reading the Phase 2 requirements, I realized I could very easily adapt it with a few variable name changes
        to work with this project. 
    3. Google overview again used to find out how to erase from a vector
    4. Stack Overflow used to solve "Error: Jump to case label"

Summary:
    Overall programming my program was relatively straightforward. 
    I had an issue with the task compiling, which I was able to fix myself via trial and error (Google wasn't helpful).
    The most challenging part was figuring out how to convert a double input into a string to initialize a new rod.
        I tried using the "to_string()" function which did not set the correct precision automatically, so I had to
        append it to a seperate string using the correct precision. I used a for loop along with 2 buffer strings in
        order to input the number correctly exactly as it was inputted. While it is not the most elegant solution,
        it works completely fine based on my testing, and it can output up to the first 6 decimal places 
        (this seems to be an issue with "to_string()" and not the program), which is more than accurate enough for
        any piece of stock in most commonly units.
    I had plenty of time to finish the high level requirements.
Summary 2:
    Programming the ListMaker class was significantly more difficult than the RodStock class. I had many issues with my
        code which took a lot of trial and error to fix. The most challenging part (that was sucessfully implemented)
        was inputting new items into the list. I had issues getting the inputs to properly read, as sometimes it would
        skip the first string, while other times the double would immedietely become an endless loop without giving the
        user the option to input.
    I was unable to finish the implementation of the cut feature I wanted on time. While the code meets the requirements
        for the list function (add, modify, delete), I wanted a specific option to just cut the rod stock using the 
        overloaded operator--. I was unable to get the command to write the list, despite the fact that other variables, 
        including the length modified by operator--, could be modified via the rod modification function.
    