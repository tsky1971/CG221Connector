#if defined _WIN32 || defined _WIN64
    #include <Windows.h>

    #define DLLEXPORT __declspec(dllexport)
#else
    #include <stdio.h>
#endif

#ifndef DLLEXPORT
    #define DLLEXPORT
#endif

DLLEXPORT void CG221ConnectorLibraryFunction()
{
#if defined _WIN32 || defined _WIN64
	MessageBox(NULL, TEXT("Loaded CG221ConnectorLibrary.dll from Third Party Plugin sample."), TEXT("Third Party Plugin"), MB_OK);
#else
    printf("Loaded ExampleLibrary from Third Party Plugin sample");
#endif
}