#include <stdio.h>
#include <windows.h>
int main()
{
    HANDLE hFILE = CreateFile(
        "C:\\Users\\Suvan\\Documents\\VS code\\bin\\1.txt", // lpFileName：要打开的文件名
        GENERIC_WRITE,                                      // GENERIC_READ表示允许对设备进行读访问；GENERIC_WRITE表示允许对设备进行写访问
        FILE_SHARE_READ,                                    // 如果是0表示不共享；是FILE_SHARE_READ和/或FILE_SHARE_WRITE表示允许对文件进行共享
        NULL,                                               // 
        OPEN_ALWAYS,                                        // OPEN_ALWAYS：如果不存在就创建
        FILE_ATTRIBUTE_NORMAL,                              // FILE_ATTRIBUTE_NORMAL：默认属性
        NULL);                                              // 
    if (hFILE == INVALID_HANDLE_VALUE)
    {
        printf("CreateFile error\n");
        return 0;
    }
    if (SetFilePointer(hFILE, 0, NULL, FILE_END) == -1)
    {
        printf("SetFilePointer error\n");
        return 0;
    }
    char buff[256] = "hello";
    DWORD dwWrite;
    if (!WriteFile(hFILE, &buff, strlen(buff), &dwWrite, NULL))
    {
        printf("WriteFile error\n");
        return 0;
    }
    printf("write %d.\n", dwWrite);
    printf("done.\n");
    CloseHandle(hFILE);
    return 0;
}