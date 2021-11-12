#include <iostream>
/**
 * Variable storage class: https://en.cppreference.com/w/cpp/language/storage_duration
 * The storage class specifiers are a part of the decl-specifier-seq of a name's declaration syntax. 
 * Together with the scope of the name, they control two independent properties of the name: 
 * its storage duration and its linkage.
 * static: static or thread storage duration and internal linkage
 * extern: static or thread storage duration and external linkage.
 * thread local: thread storage duration.
 * mutable: does not affect storage duration or linkage.
 * 
 * Storage duration:
 * automatic: The storage for the object is allocated at the beginning of the enclosing code block
 *            and deallocated at the end. All local objects have this storage duration, 
 *            except those declared static, extern or thread_local.
 * static: The storage for the object is allocated when the program begins 
 *         and deallocated when the program ends.
 * thread: The storage for the object is allocated when the thread begins 
 *         and deallocated when the thread ends.
 * dynamic: The storage for the object is allocated and deallocated upon request 
 *          by using dynamic memory allocation functions.
 * 
 * Linkage:
 * no linkage: The name can be referred to only from the scope it is in.
 * internal linkage: The name can be referred to from all scopes in the current translation unit.
 * external linkage: The name can be referred to from the scopes in the other translation units.
 */

[[maybe_unused]] static int staticDurationVariable; // Static duration exists until program exits, 0 initialized
[[maybe_unused]] extern int staticDurationVariable; // Static duration exists until program exits, 0 initialized

int *variableLifetime_67()
{
    {
        [[maybe_unused]] int automaticVar; // Unitialized automatic storage, exists until end of block
    }                                      // automaticVar expires
    int *dynamicStorage = new int;

    return dynamicStorage;
}

int main()
{
    std::cout << "Section 9: Variable Lifetime and Scope\n";

    delete variableLifetime_67(); // dynamicStorage is deleted
}