#include <iostream>

void DeclaringAndUsingPointers_110()
{
    int i{42};
    auto *p_i{&i};
    std::cout << std::hex << p_i << ", " << *p_i << "\n";
}
void PointerTochar_111()
{
    char *charay;
    char hello[]{"Hello world"};
    charay = hello;
    std::cout << charay << "\n";

    // char *howdy{"World hello\n"};  // ISO C++ forbids converting a string constant to ‘char*’ [-Werror=write-strings]
    // Must be const!
    const char *howdy{"World hello\n"};
    std::cout << howdy;
    std::cout << *howdy << "\n"; // 'W'
}
void ArraysOfPointerToChar_112()
{
    const char *strings[]{"First", "Second", "Tird"};
    for (auto str : strings)
    {
        std::cout << str << "\n";
    }
}

void ConstPointerAndPointerToConst_113()
{
    int i;
    i = 42;
    int *const PtrToI{&i};
    *PtrToI = 24; // Ok it's the pointer that is const
    const int *ptr_to_i;
    ptr_to_i = &i; // Ok, it's the pointed to variable that is const
    const int *const VeryConstPtr{&i};
    std::cout << i << ", " << *ptr_to_i << ", " << *VeryConstPtr << "\n";
}

void ArrayOfConstPointerToConstChar_114()
{
    const char *strings[]{"First", "Second", "Tird"};
    const char *tmp = strings[0];
    strings[0] = strings[2];
    strings[2] = tmp;

    for (auto str : strings)
    {
        std::cout << str << "\n";
    }
}

void PointersAndArrays_115()
{
    // An array can decays to a pointer and lose information
    int nums[]{1, 2, 3, 4, 5};
    int *p_nums = nums; //p_nums and nums have the same value but different type!
    std::cout << std::size(nums) << ", " << sizeof(p_nums) << "\n";
}

int *maximum_address(int data[], unsigned int size)
{

    int *max_address;

    //Don't modify anything above this line
    //Your code will go below this line
    int max = -2000000000;
    for (unsigned i = 0; i < size; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
            max_address = data + i;
        }
    }
    //Your code should go above this line
    //Don't modify anything after this line
    return max_address;
}
void exercise_14()
{
    int data[]{1, 2, 3, 4, 5, 6};
    if (int *ptr = maximum_address(data, std::size(data)); *ptr == data[5])
    {
        std::cout << "Ok\n";
    }
    else
        std::cout << "Bad\n";
}

void shoot_forward(int data[], unsigned int offset)
{

    //Don't modify anything above this line
    //Your code will go below this line
    std::cout << "The element " << offset << " slots away from the beginning is : " << *(data + offset);
    //Your code will go above this line
    //Don't modify anything below this line
}
void exercise_15()
{
    int data[]{1, 3, 6, 3, 9, 3, 5, 7, 2, 11};
    shoot_forward(data, 3);
}

void PointerArithmeticDistanceBetweenElements_119()
{
    int *a, A, *b, B;
    a = &A;
    b = &B;
    std::ptrdiff_t diff{b - a};
    std::cout << sizeof(diff) << ", " << diff << "\n";

    std::ptrdiff_t diff2{a - b};
    std::cout << sizeof(diff2) << ", " << diff2 << "\n";
}

int *minimum_address(int data[], unsigned int size)
{

    int *min_address;

    // Don't modify anything above this line
    //Your code should go below this line
    //REMEMBER !ONLY POINTER ARITHMETIC SHOULD BE USED TO ACCESS ARRAY DATA
    int min = 2000000000;
    for (unsigned i = 0; i < size; i++)
    {
        if (*(data + i) < min)
        {
            min = *(data + i);
            min_address = (data + i);
        }
    }
    //Your code should go above this line
    //Don't modify anything below this line

    return min_address;
}
void exercise_16()
{
    int data[]{11, 2, 52, 53, 9, 13, 5, 7, 12, 11};
    if (int *ptr = minimum_address(data, std::size(data)); *ptr == data[1])
    {
        std::cout << "Ok\n";
    }
    else
        std::cout << "Bad\n";
}

void DynamicMemoryAllocation_123()
{
    int OnStack{};
    int *OnHeap{new int{42}};
    std::cout << &OnStack << ", " << OnHeap << ", " << *OnHeap << "\n";

    delete OnHeap; // Deleting twice can potentially delete something reusing the memory!!!
    OnHeap = nullptr;
    std::cout << OnStack << ", " << OnHeap << "\n";
}

void DanglingPointers_124()
{
    int *dangling1;
    dangling1 = new int{42};   // No longer dangling
    int *dangling2{dangling1}; // both valid
    std::cout << *dangling1 << ", " << *dangling2 << "\n";
    delete dangling1; // Dangling again, and also dangling2 becomes dangling
    std::cout << *dangling1 << ", " << *dangling2 << "\n";
    std::cout << dangling1 << ", " << dangling2 << "\n";
    dangling1 = nullptr;
    dangling2 = nullptr;
    //No dang left

    int *address{new int{42}};
    std::cout << "One" << std::endl;
    delete address;
    int *address2{new int{42}};
    std::cout << "Two" << std::endl;
    std::cout << *address << std::endl;
    std::cout << "Done" << address2 << std::endl;
}

void WhenNewFails_125()
{
    int n{1000000};
    int m{1000000};

    try
    {
        auto arr = new int[m * n];
        delete[] arr;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    /* https://en.cppreference.com/w/cpp/language/new
    If a non-throwing allocation function (e.g. the one selected by new(std::nothrow) T) returns a null pointer because of an allocation failure, 
    then the new-expression returns immediately, it does not attempt to initialize an object or to call a deallocation function

    Bugreport: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=93016
    */
    // auto arr = new (std::nothrow) int[m * n]; // terminate called after throwing an instance of 'std::bad_array_new_length'
    auto arr = new (std::nothrow) int[m];
    if (arr != nullptr)
    {
        delete[] arr;
        std::cout << "Deleted\n";
    }
    else
    {
        std::cout << "Allocation failed\n";
    }
}

void NullPointerSafety_126()
{
    // delete nullptr; // expression must be a pointer to a complete object typeC/C++(852)
    int *ptr = nullptr;
    delete ptr; // nuööptr can safely be deleted!
    if (ptr != nullptr)
        std::cout << "ptr != nullptr\n";
}

void MemoryLeeks_127()
{
    auto ptr = new int{42};
    ptr = nullptr; // No longer possible to free what was allocated!!!!!!
    do
    {
        auto ptr = new int{42};
        delete ptr; // ptr goes out of scope and later delete inposible
    } while (false);

    delete ptr;
}

void DynamicallyAllocatedArrays_128()
{
    size_t arrSize{10};
    auto fidgets{new int[arrSize]};      //Unitializer array
    auto gibs{new int[arrSize]{}};       // Zero initialized
    auto dodads{new int[arrSize]{1, 2}}; // Initialized to {1,2,0,0,0,0,0,0,0,0,}
    if (dodads)
    {
        std::cout << dodads[1] << ", " << dodads[2] << "\n";
    }

    delete[] fidgets;
    fidgets = nullptr;
    delete[] gibs;
    gibs = nullptr;
    delete[] dodads;
    dodads = nullptr;
}

void merge_arrays(int data1[], int data2[],
                  unsigned int size1, unsigned int size2)
{

    //Don't modify anything above this line
    //Your code will go below this line
    size_t newSize{size1 + size2};
    auto new_array{new int[newSize]};
    if (new_array)
    {
        for (size_t i = 0; i < size1; ++i)
        {
            new_array[i] = data1[i];
        }
        for (size_t i = 0; i < size2; ++i)
        {
            new_array[i + size1] = data2[i];
        }
        for (size_t i = 0; i < newSize; ++i)
        {

            std::cout << new_array[i] << " ";
        }
        delete[] new_array;
    }
    //Your code will go above this line
    //Don't modify anything below this line
}
void exercise_17()
{
    int data1[]{1, 2, 3, 4, 5, 66, 77};
    int data2[]{10, 20, 30, 40, 50, 60};
    merge_arrays(data1, data2, std::size(data1), std::size(data2));
}

int main()
{
    std::cout << "Section 13\n";
    // DeclaringAndUsingPointers_110();
    // PointerTochar_111();
    // ArraysOfPointerToChar_112();
    // ConstPointerAndPointerToConst_113();
    // ArrayOfConstPointerToConstChar_114();
    // PointersAndArrays_115();
    // exercise_14();
    // exercise_15();
    // PointerArithmeticDistanceBetweenElements_119();
    // exercise_16();
    // DynamicMemoryAllocation_123();
    // DanglingPointers_124();
    // WhenNewFails_125();
    // NullPointerSafety_126();
    // MemoryLeeks_127();
    // DynamicallyAllocatedArrays_128();
    exercise_17();
}
