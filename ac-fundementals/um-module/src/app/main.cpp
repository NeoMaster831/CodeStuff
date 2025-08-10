#include <iostream>
#include <Windows.h>

#define DLL_NAME "um_module.dll"

int main() {
    std::cout << "Loading DLL..." << '\n';
    HMODULE hModule = LoadLibrary(DLL_NAME);
    if (!hModule) {
        std::cerr << "Failed to load DLL: " << GetLastError() << '\n';
        return 1;
    }

    std::cout << "Test application starting initialize..." << '\n';

    std::cout << "Test application starting idle..." << '\n';

    while (getchar() != '\n') // Wait for user input
        ;
    
    std::cout << "Test application exiting..." << '\n';
}