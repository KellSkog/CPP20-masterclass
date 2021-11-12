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
    // "the sky is blue"
    // Enclosing strncopy in parathesis silences the compiler!
    (std::strncpy(result, src1 + 15, 4));     // "the "
    (std::strncpy(result + 4, src2 + 6, 4));  // "sky "
    (std::strncpy(result + 8, src3 + 11, 3)); //  "is "
    (std::strncpy(result + 11, src4 + 4, 4)); // "blue"
    result[15] = '\0';
    std::cout << "result : " << result;

    //Your code will go above this line
    //Don't modify anything below this lin
    delete[] result;
}
void exercise_21()
{
    const char src1[]{"will old space the replace"};
    const char src2[]{"sense sky hit has"};
    const char src3[]{"hello went is get"};
    const char src4[]{"red blue yellow orange"};
    extract_message(src1, src2, src3, src4);
    std::cout << "\n";
}

#include <string>
void DeclaringAndUsingStdString_141()
{
    std::string empty_string;
    std::cout << sizeof(empty_string) << "\n";
    std::string planet{"Rock in space"};
    std::string earth{planet + " third orbit from Sun"};
    std::cout << earth + ", my home!"
              << "\n";
    std::string e{4, 'e'};    //"e", eh?
    std::string eeee(4, 'e'); //"eeee"
    std::string hello{"hello world", 5};
    std::string world{"hello world", 6, 5};
    std::cout << e << ", " << eeee << ", " << hello << ", " << world << "\n";
}
class Child;
struct Parent
{
    Parent() : name{"Parent "} {}
    virtual void v()
    {
        x++;
    }
    virtual void p()
    {
        std::cout << name << ", " << this->x << ", " << y << ", " << z << "\n";
    }
    friend Child; // Or make name protected!

private:
    int x = 0; //Not visible to anyone not declared as friens!
    std::string name;

protected:
    int y = 0; // Visible to all child classes
public:
    int z = 0; // visible to creti and pleti
};
struct Child : public Parent // Child is 32 bytes larger than parent
{
    Child() { name = "Child "; }
    void v()
    {
        Parent::v(); // Executes parents implementation of v with this -> child
    }
};
void experiment1()
{
    Child c;
    c.v();
    c.v();
    c.z++;
    Parent p;
    p.v();

    c.p();
    p.p();
}

void ConcatenatingStdString_142()
{
    using namespace std::string_literals;
    std::array<std::string, 3> attached{
        std::string{"Head"
                    " tail"},
        std::string{std::string{"Head"} + " tail"},
        std::string{"Begins"s + "Ends"}};
    auto word{"Word"s};
    attached[2].append(word);
    attached[2].append("outerWorldly", 5, 5);
    for (auto strings : attached)
    {
        std::cout << strings << "\n";
    }
}

std::string build_from_raw_pieces(const char *str1, const char *str2)
{

    std::string result;

    //Don't modify anything above this line
    //Your code will go below this line
    result = std::string(str1) + ' ' + std ::string(str2);
    //Your code will go above this line
    //Don't modify anything below this line
    return result;
}
void exercise_22()
{
    std::cout << build_from_raw_pieces("Hello there!", "How are you?") << "\n";
}

void AccessingCharactersInStdString_143()
{
    std::string me{"Kell Göran Skog"};
    for (size_t i = 0; i < me.size(); ++i)
    {
        std::cout << me[i];
    }
    std::cout << "\n";
    for (size_t i = 0; i < me.size(); ++i)
    {
        std::cout << me.at(i);
    }
    std::cout << "\n";
    std::cout << me.front() << me.back() << "\n";
    char front = me.front();
    char &back = me.back();
    me.front() = back;
    back = front;
    std::cout << me.front() << me.back() << "\n";

    const char *c_str = me.c_str();
    std::cout << c_str << "\n";
    char *data = me.data();
    std::cout << data << "\n";
}

void StdStringSizeAndCapacity_144()
{
    std::string str1{};
    std::string str2{"0"}; //Default capacity 15
    std::string str3{"0123456789ABCDEF"};
    str3.reserve(666);
    //length gives same result as size
    std::cout << std::boolalpha << str1.empty() << ", " << str1.capacity() << ", " << str1.size() << ", " << str1.length() << "\n";
    std::cout << std::boolalpha << str2.empty() << ", " << str2.capacity() << ", " << str2.size() << ", " << str2.length() << "\n";
    std::cout << std::boolalpha << str3.empty() << ", " << str3.capacity() << ", " << str3.size() << ", " << str3.length() << "\n";
    std::cout << str1.max_size() << "\n";
    for (int i = 0; i < 100; ++i)
    {
        str1 += 'x'; // Capacity doubles at each reallocation 15, 30, 60, 120...
        if (i % 10 == 0)
            std::cout << "[" << str1.capacity() << "]";
    }
    std::cout << str1 << "\n";
    str1 = "";
    std::cout << str1.capacity() << "\n";
}

void ModifyingStdString_145()
{
    std::string string{"ölhghöjklaghhaargökljhghasrhgöjhghaörhgiröaöasrhghaäiohg"};
    string.clear();
    std::cout << std::boolalpha << string.empty() << ", " << string.capacity() << ", " << string.size() << ", " << string.length() << "\n";
    string = "abcdef";
    // insert has 10 overloads!!
    string.insert(3, 4, '!'); //Inserts 5 character '!' at pos 3
    std::cout << string << "\n";
    string.insert(5, "god jul");
    std::cout << string << "\n";
    std::string jevla{" jivla"}; // ä is two character!!!
    string.insert(8, jevla);
    std::cout << string << "\n";
    const char *bip{"escapist"};
    string.insert(13, bip, 1);
    std::cout << string << "\n";
    string.insert(15, jevla, 2, 2);
    std::cout << string << "\n";

    std::string strax{"Aallffaabbeetteett"};
    for (size_t i = 1; i < strax.length(); ++i)
    {
        strax.erase(i, 1);
    }
    strax.pop_back(); // erases remaining 't'
    strax.push_back('!');
    std::cout << strax << "\n";
}

void ComparingStdStrings_146()
{
    std::string first{"Alpha"};
    std::string after{"Alphb"};
    // a.compare(b) returns a - b.. kind of
    std::cout << first.compare(first) << "\n"; // 0 equal
    std::cout << first.compare(after) << "\n"; // -1 first < after
    std::cout << after.compare(first) << "\n"; // after > first

    std::cout << std::boolalpha << (first == first) << "\n"; // true
    std::cout << std::boolalpha << (first != after) << "\n"; // true
    std::cout << std::boolalpha << (first < after) << "\n";  // true
    std::cout << std::boolalpha << (after > first) << "\n";  // true
}

std::string who_s_the_greatest(std::string data[], unsigned int size)
{

    std::string result;

    //Don't modify anything above this line
    //Your code will go below this line
    result = data[0];
    for (size_t i = 1; i < size; ++i)
    {
        if (result < data[i])
            result = data[i];
    }
    //Your code will go above this line
    //Don't modify anything below this line

    return result;
}
void exercise_23()
{
    std::string input[]{"I", "am", "the", "king", "of", "the", "jungle"};
    std::cout << who_s_the_greatest(input, std::size(input)) << "\n";

    std::string input2[]{"catching", "some", "fresh", "air", "outside"};
    std::cout << who_s_the_greatest(input2, std::size(input2)) << "\n";
}

void compare(const std::string &a, const std::string &b)
{
    int res = a.compare(b);
    if (res < 0)
        std::cout << a << " comes before " << b << "\n";
    else if (res == 0)
        std::cout << a << " is same as " << b << "\n";
    else
        std::cout << a << " comes after " << b << "\n";
}
void ComparingWithStdStringCompare_147()
{
    /**
     * Returns: Integer < 0, 0, or > 0. Returns an integer < 0 if this string is ordered before * __str, 
     * 0 if their values are equivalent, 
     * or > 0 if this string is ordered after __str. 
     * Determines the effective length rlen of the strings to compare as the smallest of size() and str.size(). 
     * The function then compares the two strings by calling traits::compare(data(), str.data(),rlen). 
     * If the result of the comparison is nonzero returns it, otherwise the shorter one is ordered first.
    */
    compare(std::string{"Alpha"}, std::string{"Alphb"});
    compare(std::string{"Alphb"}, std::string{"Alpha"});
    compare(std::string{"Alphb"}, std::string{"Alphb"});

    int compare_value{std::string{"Batman"}.compare(3, 3, "Superman", 5, 3)};

    std::cout << (compare_value < 0 ? "man comes before Superman\n" : compare_value > 0 ? "Superman comes before man\n"
                                                                                        : "man and Superman are the same.\n");
}

void StdStringReplacingCopyingResizingAndSwapping_148()
{
    std::string one{"Somewhere to go"};
    std::string another{"Nothing to lose"};
    one.replace(0, 4, another, 0, 2);
    char that[3]{};
    one.copy(that, 2, 8);
    std::cout << that << "\n";
    auto len = one.length();
    one.resize(3); // Inserts a ´\0' at 3
    for (size_t i = 0; i < len; ++i)
    {
        if (one[i])
            std::cout << one[i];
        else
            std::cout << '#';
    }
    std::cout << "\n";

    another.resize(20, '#'); // Extends with '#'
    std::cout << another << "\n";
}

void SearchingStdString_149()
{
    std::string one{"Asummers day as happy as can be the bee had ever been"};
    std::string find{"ever"};
    auto pos = one.find(find);
    if (pos != std::string::npos) // Check something was found
        std::cout << one.substr(pos) << "\n";

    std::string two{"blah blah blah blah"};
    std::string locate{"blah"};
    auto position = two.find(locate);
    while (position != std::string::npos)
    {
        std::cout << two.substr(position, locate.size()) << " ";
        position = two.find(locate, position + 1);
    }
    std::cout << "\n";
}

void find_matches(std::string data[], unsigned int size, const char *key)
{

    std::string *matches = new std::string[size]; // Create std::string array on the heap. Remember to release
    //Don't modify anything above this line
    //Your code should go below this line
    size_t resultCount{0}; // Contains number of found matches, points to first free slot
    size_t pos{};
    for (size_t i = 0; i < size; ++i)
    {
        pos = data[i].find(key);
        if (pos != std::string::npos)
        {
            matches[resultCount++] = data[i];
        }
    }
    if (resultCount > 0)
    {
        std::cout << "Found " << resultCount << " matches. They are: ";
        for (size_t i = 0; i < resultCount; ++i)
        {
            std::cout << matches[i];
            if (i < resultCount - 1)
                std::cout << " ";
        }
    }
    else
        std::cout << "Didnt find jack shitake\n";

    //Your code should go above this line
    //Don't modify anything below this line

    delete[] matches; // Remember to release the memory.
}
void exercise_24()
{
    std::string input[]{"catching", "iteration", "fresh", "iterative", "outside", "mercy"};
    find_matches(input, std::size(input), "iter");
}

void TransformingStdStringToFromNumbers_150()
{
    // Numbers to string
    auto floater{3.14f};
    auto doubloon{3.14};
    auto integer{42};
    auto float_str{std::to_string(floater)};
    auto double_str{std::to_string(doubloon)};
    auto int_str{std::to_string(integer)};
    std::cout << float_str << ", " << double_str << ", " << int_str << "\n";

    // Strings to numbers
    float flt;
    double dbl;
    int in;
    // size_t pos;
    flt = std::stof(float_str); //, &pos);
    std::cout << 2 * flt << "\n";
    dbl = std::stod(double_str); //, &pos);
    std::cout << 3.14 * dbl << "\n";
    in = std::stoi(int_str); //, &pos);
    std::cout << 2 + in << "\n";
    auto underflow = std::stoul("-1");
    std::cout << underflow << "\n";
}

void EscapeSequences_151()
{
    std::string str{"*\t\n\t\"\\\'\?\a#\r-\nabc\b\n"}; // \b (backspace) does nothing!
    std::cout << str;
}

void RawStringLiterals_152()
{
    /**
     * A raw string is defined as R"delimiter(raw_characters)delimiter"
     * The delimiter: A character sequence made of any source character but parentheses, 
     * backslash and spaces (can be empty, and at most 16 characters long)
     */
    //clang-format off
    std::string str{
        R"[](? '\
"öÖ
)[]"};
    //clang-format on
    std::cout
        << str;
    const char *str2{R"(\'?)"};
    std::cout << str2 << "\n";

    std::string message{"He said :  'Stay out of this' and left"};
    std::cout << "message : " << message << std::endl;

    std::string message2{R"(He said :  ("Stay out of this") and left)"};
    std::cout << "message : " << message2 << std::endl;
}
void CopiedStrings_153()
{
    std::string str1{"Hola Bandola Band, is playing the coming Sunday!"};
    std::string copy{str1}; // Copy constructor
    std::string &ref{str1};
    std::cout << str1.data() << ", " << (void *)copy.data() << ", " << &ref << "\n";
    std::cout << sizeof(str1) << ": " << str1 << "\n";
    std::cout << sizeof(ref) << ": " << ref << "\n";

    /**
     * Yes. You got this right. The statement std::string message {"Hello"}; 
     * is using the literal string "Hello" that already lives in the memory map of our program, 
     * making a copy of that and storing that in the message std::string. 
     * This is a copy we are making and the SAD thing is references and pointers can't protect us from such copies. 
     * Fortunately, we'll see a way to avoid this in the lecture on string_views.
     */
    std::string message{"Hello"};
    std::string &message_copy = message;
    std::cout << "message : " << (void *)message.data() << std::endl;
    std::cout << "message_copy : " << (void *)message_copy.data() << std::endl;
}

#include <string_view>
void StdString_view_154()
{
    std::string_view str1{"Hello world!"};
    std::string_view view1{str1};
    std::cout << sizeof(std::string_view) << ": " << view1 << "\n\n";
    // std::string_view view2{(const char *)"Regular std::string"}; // ��ing
    const char *c_string{"Regular std::string"};
    std::string_view view2{c_string};
    std::string_view view3{(const char *)"Regular C-string"};
    // std::string_view view4{(const char[]){"Char array"}}; // error: ISO C++ forbids compound-literals [-Werror=pedantic]
    const char charette[]{"Char array"};
    std::string_view view4{charette};
    std::string_view view5{view2};
    char char_array[]{'H', 'u', 'g', 'e'};
    std::string_view view6{char_array, std::size(char_array)};

    std::cout << view1 << "\n";
    std::cout << view2 << "\n";
    std::cout << view3 << "\n";
    std::cout << view4 << "\n";
    std::cout << view5 << "\n";
    std::cout << view6 << "\n";
    std::cout << "\n";

    std::string_view sentence{"Once upon a time, there were a powerful programmer"};
    sentence.remove_prefix(18); // "Once upon a time, "
    sentence.remove_suffix(11); // " programmer"
    std::cout << sentence << "\n";
}

int main()
{
    std::cout << "Section 15: Character manipulation and strings\n ";
    // CharacterManipulation_137();
    // execise_19();
    // execise_20();
    // CstringManipulation_138();
    // CStringConcatenationAndCopy_139();
    // exercise_21();
    // DeclaringAndUsingStdString_141();
    // experiment1();
    // ConcatenatingStdString_142();
    // exercise_22();
    // AccessingCharactersInStdString_143();
    // StdStringSizeAndCapacity_144();
    // ModifyingStdString_145();
    // ComparingStdStrings_146();
    // exercise_23();
    // ComparingWithStdStringCompare_147();
    // StdStringReplacingCopyingResizingAndSwapping_148();
    // SearchingStdString_149();
    // exercise_24();
    // TransformingStdStringToFromNumbers_150();
    // EscapeSequences_151();
    // RawStringLiterals_152();
    // CopiedStrings_153();
    StdString_view_154();
}