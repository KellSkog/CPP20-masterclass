#include <array>
#include <cstring>
#include <iostream>
#include <tuple>

void CharacterManipulation_137()
{
    std::array<std::pair<int, const char *>, 4> description{std::pair<int, const char *>{0, "Upper"},
                                                            std::pair<int, const char *>{0, "Lower"},
                                                            std::pair<int, const char *>{0, "Numeric"},
                                                            std::pair<int, const char *>{0, "Blanc"}};
    // https://en.cppreference.com/w/c/string/byte/isalnum
    // std::array<int, 7> characters{'A', '*', 'x', '@', '0', ' ', '\t'};
    std::array<char, 30> characters{"A*x@0 \t Haderian Hadera 12345"};
    std::cout << "\n";
    for (auto &letter : characters)
    {
        if (std::isupper(letter))
        {
            description[0].first++;
            letter = std::tolower(letter);
        }
        else if (std::islower(letter))
        {
            description[1].first++;
            letter = std::toupper(letter);
        }
        else if (std::isdigit(letter))
        {
            description[2].first++;
        }
        else if (std::isblank(letter))
        {
            description[3].first++;
        }
    }
    for (auto [num, msg] : description)
    {
        std::cout << msg << ": " << num << "\n";
    }
    std::cout << characters.data() << "\n";
}

void find_stuf_out(char data[], unsigned int size)
{

    unsigned int vowel_count{};
    unsigned int consonant_count{};

    //Don't modify anything above this line
    //Your code should go below this line
    for (size_t i = 0; i < size; ++i)
    {
        if (std::isalpha(data[i]))
        {
            char c{data[i]};
            if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                vowel_count++;
            }
            else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            {
                vowel_count++;
            }
            else
            {
                consonant_count++;
            }
        }
    }
    std::cout << "The string contains " << vowel_count << " vowels and " << consonant_count << " consonants";

    //Your code should go above this line
    //Don't modify anything below this line
}
void execise_19()
{
    char message[]{"John was 8 years old at the time."};
    find_stuf_out(message, std::size(message));
    std::cout << "\n";
    char message2[]{"The sky is blue my friend."};
    find_stuf_out(message2, std::size(message2));
}

void replace_spaces(char data[], unsigned int size)
{

    char *result{nullptr};

    //Don't modify anything above this line
    //Your code will go below this line

    //REMEMBER : WHEN YOU DYNAMICALLY ALLOCATE FOR SPACE FROM THE HEAP, YOU HAVE TO ACTIVELY RELEASE THAT TO THE
    //SYSTEM WHEN DONE WITH IT. BE A GOOD C++ CITIZEN!
    result = new char[size];
    for (size_t i = 0; i < size; ++i)
    {
        if (std::isspace(data[i]))
        {
            result[i] = '_';
        }
        else
        {
            result[i] = data[i];
        }
    }
    std::cout << "After replacing the spaces, we get : ";
    std::cout << result;

    delete[] result;
    //Your code will go above this line
    //Don't modify anything below this line
}
void execise_20()
{
    char message[]{"The sky is blue my friend."};
    replace_spaces(message, std::size(message));
    std::cout << "\n";
}
void CstringManipulation_138()
{
    // https://en.cppreference.com/w/cpp/header/cstring
    const char message[]{"The sky is blue my friend."};
    const char *message2{"The sky is blue my friend."};
    std::cout << std::strlen(message) << ", " << sizeof(message) << "\n";
    std::cout << std::strlen(message2) << ", " << sizeof(message2) << "\n"; // Sizeof pointer

    const char *string1{"Clabama"};
    const char *string2{"Blabama"};
    if (std::strcmp(string1, string2) < 0)
    {
        std::cout << string1 << "\n";
    }
    else if (std::strcmp(string1, string2) > 0)
    {
        std::cout << string2 << "\n";
    }
}

void CStringConcatenationAndCopy_139()
{
    //Hello world I'm off
    char dest[20] = "Hello ";
    char src[50] = "world";
    std::strcat(dest, src);
    std::strcat(dest, " I'm off");
    std::cout << dest << "\n";

    char *alpha{new char[100]{"Jabadabadoo"}};
    // error: ‘char* strncat(char*, const char*, size_t)’ output truncated copying 11 bytes from a string of length 12 [-Werror=stringop-truncation]
    // error: ‘char* strncat(char*, const char*, size_t)’ specified bound 12 equals source length [-Werror=stringop-overflow=]
    std::strncat(alpha, " dobidobidoo", 13);
    std::cout << alpha << "\n";
    delete[] alpha;
}

void extract_message(const char *src1, [[maybe_unused]] const char *src2,
                     [[maybe_unused]] const char *src3, [[maybe_unused]] const char *src4)
{

    char *result;
    result = new char[20]; // Dynamically allocate for space

    //Don't modify anything above this line
    //Your code will go below this line
    std::strncpy(result, src1 + 15, 12);
    result[4] = '\0';
    std::strncpy(result + 4, src2 + 6, 12);
    result[8] = '\0';
    std::strncpy(result + 8, src3 + 11, 5);
    result[11] = '\0';
    std::strncpy(result + 11, src4 + 4, 19);
    result[16] = '\0';
    std::cout << result << "\n";

    delete[] result;
    //Your code will go above this line
    //Don't modify anything below this lin
}
void exercise_21()
{
    const char src1[]{"will old space the replace"};
    const char src2[]{"sense sky hit has"};
    const char src3[]{"hello went is get"};
    const char src4[]{"red blue yellow orange"};
    extract_message(src1, src2, src3, src4);
}

int main()
{
    std::cout << "Section 15\n";
    // CharacterManipulation_137();
    // execise_19();
    // execise_20();
    // CstringManipulation_138();
    // CStringConcatenationAndCopy_139();
    exercise_21();
}