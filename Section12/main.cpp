#include <array>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <random>

void DeclaringAndUsingarrays_99()
{
    // int a[0]; error: ISO C++ forbids zero-size array ‘a’ [-Werror=pedantic]
    // std::cout << a[0] << "\n"; error: array subscript 0 is outside array bounds of ‘int [0]’ [-Werror=array-bounds]
    // int a[1]; error: ‘a’ is used uninitialized [-Werror=uninitialized]
    // std::cout << a[-1] << "\n"; error: array subscript -1 is below array bounds of ‘int [1]’ [-Werror=array-bounds]
    // 'auto' type cannot appear in top-level array typeC/C++(1589)
    // auto a[]{1, 2}; error: ‘a’ declared as array of ‘auto’
    int a[5]{1, 2};
    // a[2] = 0; // Oops, no problem!!
    // a[-1] = 0; // Oops, no problem!!
    /// Compiler allows writing out of bounds but not reading.....
    for (auto cell : a)
        std::cout << std::hex << cell << ", ";
    std::cout << "\n";
    std::array<int, 5> b{1, 2}; // error: conflicting declaration ‘std::array<int, 5> a’
    for (auto &cell : b)
        cell *= 2;
    for (auto cell : b)
        std::cout << std::hex << cell << ", ";
    std::cout << " : " << b.size() << "\n";
}

void unique_numbers(int numbers[], unsigned int collection_size)
{
    constexpr int MaxElements = 20;
    int uniq[MaxElements];
    unsigned elementsFound{0};
    for (unsigned inputIndex = 0; inputIndex < collection_size; ++inputIndex)
    {
        bool isUnique{true};
        unsigned resultIndex = 0;
        for (; resultIndex < elementsFound; ++resultIndex)
        {
            if (numbers[inputIndex] == uniq[resultIndex])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            uniq[elementsFound++] = numbers[inputIndex];
        }
    }
    std::cout << "The collection contains " << elementsFound << " unique numbers, they are : ";
    for (unsigned i = 0; i < elementsFound; ++i)
    {
        std::cout << uniq[i] << " ";
    }
}
void ExerciseEliminatingDuplicates10()
{
    std::array<int, 12> nums{1, 2, 4, 5, 1, 8, 2, 3, 6, 1, 4, 2};
    unique_numbers(nums.data(), nums.size());
    std::cout << "\n";
    int data[]{1};
    unique_numbers(data, 1);
    std::cout << "\n";
    // std::size from c++17
    std::cout << "Size: " << std::size(data) << "\n";
    std::cout << "Size: " << std::size({1, 2, 3}) << "\n";
    struct Things
    {
        int a;
        double b;
    };
    std::cout << "Size: " << std::size({Things{1, 2.0}, Things{3, 4.0}}) << "\n";
}

bool is_collection_sorted(int numbers[], unsigned int collection_size)
{
    bool sorted{true};
    if (collection_size > 1)
    {
        for (unsigned i = 1; i < collection_size; ++i)
        {
            if (numbers[i - 1] >= numbers[i])
            {
                sorted = false;
                break;
            }
        }
    }
    return sorted;
}
void ExerciseIsCollectionSorted_11()
{
    std::cout << std::boolalpha;
    /// error: ISO C++ forbids compound-literals [-Werror=pedantic]
    /// error: taking address of temporary array
    // std::cout << is_collection_sorted((int[]){1, 2, 4, 5, 8, 12, 13, 16, 71, 92}, 10) << "\n";
    // std::cout << is_collection_sorted((int[]){1, 112, 4, 5, 8, 12, 13, 16, 71, 92}, 10) << "\n";
    {
        int nums[]{1, 2, 4, 5, 8, 12, 13, 16, 71, 92};
        std::cout << is_collection_sorted(nums, 10) << "\n";
    }
    {
        int nums[]{1, 112, 4, 5, 8, 12, 13, 16, 71, 92};
        std::cout << is_collection_sorted(nums, 10) << "\n";
    }
}

void ArraysOfCharacters_101()
{
    [[maybe_unused]] char greeting[] = "Hello";                // zero terminated char array by literal C-string
    char greetingss[]{'H', 'e', 'l', 'l', 'K', 'e', 'l', 'l'}; // no terminating zero!
    [[maybe_unused]] char greetings[]{"Hello"};                // Also zero terminated char array
    char *letters = greetingss;
    std::cout << letters << "\n"; // Does not stop printing at end of string
}

unsigned hunt_for_vowels(char message[], unsigned int size)
{
    unsigned int vowel_count{}; //Initialized to zero
    char vowels[]{'A', 'E', 'I', 'O', 'U'};
    constexpr int delta = 'a' - 'A';
    constexpr unsigned NoOfVowels = sizeof(vowels) / sizeof(char);
    // For each vowel
    for (unsigned j{0}; j < NoOfVowels; ++j)
    {
        // For each letter in the message
        for (unsigned i = 0; i < size; ++i)
        {
            // Skip space, should really skip a lot more..
            if (message[i] == ' ')
                continue;
            // Check if match, handle case
            if ((message[i] == vowels[j]) || (message[i] == (vowels[j] + delta)))
            {
                vowel_count++;
            }
        }
    }
    return vowel_count;
}
void ExerciseHuntForVowels_12()
{
    // The vowels in English are a, e, i, o, u, and sometimes y
    char message[]{"The sky is blue my friend"}; // eyiueyie, without y: eiueie
    std::cout << hunt_for_vowels(message, std::size(message)) << "\n";
}
void quiz14()
{
    /**
     * Output:
     * value : 1
     * value : 2
     * value : 4
     * value : 5
     * value : 4200864
     * ..
     * value : 1702047588
     * value : 1869182051
     * value : 3289454
     * value : 0
     * value : 0
     * Segmentation fault
    */
    int data[]{1, 2, 4, 5};
    for (unsigned int i{0}; i <= 4; ++i)
    {
        std::cout << "value : " << data[i] << std::endl;
    }
}

void GeneratingRandomNumbers_103()
{
    std::cout << RAND_MAX << "\n";
    std::srand(std::time(0));
    for (int i = 0; i < 10; ++i)
    {
        auto rnd = std::rand();
        std::cout << rnd << ", " << rnd % 10 << ", " << rnd % 11 + 1 << ", " << rnd / 10.0 << "\n";
    }
    std::cout << std::time(0) << "\n";

    for (int y = 0; y < 10; ++y)
    {
        for (int x{}; x < 10; ++x)
        {
            std::cout << std::setw(4) << std::rand() % 101;
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void FortuneTellerV1()
{
    // char alpha[]{"I see nothing"};
    // char beta[]{"You are about to win a gazilion"};
    // char gama[]{"You are getting fat"};
    // char delta[]{"You will be very successful"};
    char predictions[][32]{"I see nothing",
                           "You are about to win a gazilion",
                           "You are getting fat",
                           "You will be very successful"};
    // std::array<std::string, 4> predictions[4]{"I see nothing",
    //                                                     "You are about to win a gazilion",
    //                                                     "You are getting fat",
    //                                                     "You will be very successful"};

    std::srand(std::time(0));
    constexpr size_t MAX_LEN = 20;
    char name[MAX_LEN];
    char response;
    std::cout << "Name? ";
    std::cin.getline(name, MAX_LEN);
    do
    {
        std::cout << "Dear " << name << ", I see " << predictions[std::rand() % std::size(predictions)] << "\n";
        std::cout << "Do you want to try again? (y/n): ";
        std::cin >> response;
    } while (response == 'Y' || response == 'y');
    std::cout << "Geez, what's with the attitude?\n";
}

void common_elements(int array_1[], int array_2[])
{
    // REMEMBER, The input arrays array_1 and array_2 have a fixed size of 10
    constexpr int ELEMENTS = 10;
    int commons[ELEMENTS]{};
    int noOfCommon{};
    for (int i = 0; i < ELEMENTS; ++i)
    {
        for (int j{}; j < ELEMENTS; ++j)
        {
            if (array_1[i] == array_2[j])
            {
                commons[noOfCommon++] = array_1[i];
                break;
            }
        }
    }
    if (noOfCommon > 0)
    {
        std::cout << "There are " << noOfCommon << " common elements they are : ";
        for (int i = 0; i < noOfCommon; ++i)
        {
            std::cout << commons[i] << " ";
        }
    }
    else
    {
        std::cout << "There are 0 common elements";
    }
}
void ExerciseWhatDoWeHaveInCommon_13()
{
    {
        int array_1[]{1, 2, 4, 5, 9, 3, 6, 7, 44, 55};
        int array_2[]{11, 2, 44, 45, 49, 43, 46, 47, 55, 88};
        common_elements(array_1, array_2);
    }
    std::cout << "\n";
    {
        int array_1[]{1, 2000, 4, 5, 9, 3, 6, 7, 4400, 5500};
        int array_2[]{11, 2, 44, 45, 49, 43, 46, 47, 55, 88};
        common_elements(array_1, array_2);
    }
    std::cout << "\n";
}

void MultiDimensionalArrays_105()
{
    int arr[][2][3]{{{1, 2, 3}, {4, 5, 6}},
                    {{10, 20, 30}, {40, 50, 60}},
                    {{100, 200, 300}, {400, 500, 600}}}; // 3 x 2 x 3
    for (int i = 0; i < 3; ++i)
    {
        for (int j{}; j < 2; ++j)
        {
            for (int k{}; k < 3; ++k)
            {
                std::cout << std::setw(4) << arr[i][j][k];
            }
            std::cout << "\n";
        }
    }
}

void Assignment_10()
{
    std::srand(std::time(0));
    const char operations[]{'+', '-', '*', '/'};
    char selection;
    std::cout << "Welcome to the Kraziest calculator on a small island on Earth!\n";
    do
    {
        int oper1{std::rand() % 200};
        int oper2{std::rand() % 200};
        int op{std::rand() % 4};
        int result;
        switch (op)
        {
        case 0:
            result = oper1 + oper2;
            break;
        case 1:
            result = oper1 - oper2;
            break;
        case 2:
            result = oper1 * oper2;
            break;
        case 3:
            result = oper1 / oper2;
        }

        std::cout << "What's the result of " << oper1 << operations[op] << oper2 << " : ";
        int respons;
        std::cin >> respons;

        if (result == respons)
        {
            std::cout << "Congratulations! You got the result " << result << " right!\n";
        }
        else
        {
            std::cout << "Naah! the correct result is : " << result << "\n";
        }

        std::cout << "Do you want to try again? (y/n): ";
        std::cin >> selection;
    } while (selection == 'Y' || selection == 'y');
    std::cout << "See you later!\n";
}

int main()
{
    std::cout << "Section 12!\n";

    // DeclaringAndUsingarrays_99();
    // ExerciseEliminatingDuplicates10();
    // ExerciseIsCollectionSorted_11();
    // ArraysOfCharacters_101();
    // ExerciseHuntForVowels_12();
    // quiz14();
    // GeneratingRandomNumbers_103();
    // FortuneTellerV1();
    // ExerciseWhatDoWeHaveInCommon_13();
    // MultiDimensionalArrays_105();
    Assignment_10();
}