#include <iostream>
#include <cstring>  //memset()
#include <stdio.h>
#include <windows.h>
#include <winnt.h>
#include <atlstr.h>


#define FALSE 0
#define TRUE 1
#define NULL 0
#define TYPE_OF_DOWNLOADFROMUDS 0x0020 //来自UDS下砸

#define WM_NOTIFYICON_MESSAGE WM_USER + 200
#define UNM_HYPERLINK_CLICKED WM_USER + 201
#define WM_SAFEQUIT_MESSAGE WM_USER + 300

#define CMTS_FAIL 0x0000
#define CMTS_SUCCESS 0xFF01
#define CM_REMOVETOCENTER_IMAGETRANS 0x8002

#define CM_DOWNLOADCOMPLETENOTIFY 0x7000

#define CM_TRANS_UPLOAD 0x0001
#define CM_TRANS_DOWNLOAD 0x0002

#define CACHE_FILE_NO_MODIFY 0x01
#define CACHE_FILE_MODIFY 0x02

typedef int BOOL;

typedef char *PSC_STR8;
typedef char *PPI_STR32;
typedef char *PPI_STR64;
typedef char *PSC_STR512;

typedef char PI_STR8[10];
typedef char PI_STR32[34];
typedef char PI_STR64[66];
typedef char PI_STR512[514];

typedef unsigned long DWORD;

typedef struct
{
    DWORD dwFileType;
    DWORD dwBitsSize;
} PICTUREFILEHEADER, FAR *PPICTUREFILEHEADER;

typedef struct
{
    PI_STR32 Id;
    PI_STR32 serialNumber;
    PI_STR64 fileId;
    DWORD type;
    PI_STR32 deviceName;
    PI_STR8 docType;
    DWORD temporary;
} PICTUREINFO, FAR *PPICTUREINFO;

CString GetExtNameFromFileName(CString FileName)
{
    int Where;
    Where = FileName.ReverseFind('\\');
    if (Where == -1)
        Where = FileName.ReverseFind('/');

    CString FileTitle = FileName;
    if (Where >= 0)
    {
        FileTitle = FileName.Right(FileName.GetLength() - 1 - Where);
    }
    Where = FileTitle.ReverseFind('.');
    if (Where != -1)
        FileTitle = FileTitle.Right(FileTitle.GetLength() - 1 - Where);
    else
        FileTitle = "";
    return FileTitle;
}


int main()
{

    return 0;
}