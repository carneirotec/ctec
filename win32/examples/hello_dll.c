//+---------------------------------------------------------------------------
//
//  HELLO_DLL.C - Windows DLL example - main application part
//

#Inclua <windows.h>

Vazio hello_func (Vazio);
__declspec(dllimport) Externo Constante Caractere *hello_data;

Inteiro WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    Inteiro       nCmdShow)
{
    hello_data = "Hello World!";
    hello_func();
    Retorno 0;
}
