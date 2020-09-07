BOOL CIAControllerCtrl::Load(LPCTSTR Id, LPCTSTR serialNumber, long recvHandle)
{
    CSingleLock SingleLock(&m_Sync_CriticalSection);
    SingleLock.Lock();

    if (m_Auth)
    {
        m_ErrorCode = CPictureManager::IA_NOERROR;
        PICTUREINFO info;
        memset(&info, 0, sizeof(PICTUREINFO));
        if (m_PictureManager.GetPictureInfo(Id, serialNumber, &info))
        {
            //HGLOBAL hBits = m_PictureManager.GetPicture(Id,serialNumber,m_ErrorCode);
            int Compression = 0;
            HANDLE hTransData = m_PictureManager.GetPicture(Id, serialNumber, sizeof(IMAGETRANSHEADER), Compression, m_ErrorCode);
            if (hTransData)
            {
                IMAGETRANSHEADER iTransHeader;
                memset(&iTransHeader, 0, sizeof(IMAGETRANSHEADER));
                memcpy(iTransHeader.Id, info.Id, sizeof(info.Id));
                memcpy(iTransHeader.serialNumber, info.serialNumber, sizeof(info.serialNumber));
                iTransHeader.type = info.type;
                memcpy(iTransHeader.deviceName, info.deviceName, sizeof(info.deviceName));
                iTransHeader.state = 0;
                memcpy(iTransHeader.docType, info.docType, sizeof(info.docType));
                iTransHeader.totalCount = 1;
                iTransHeader.currentNumber = 1;
                iTransHeader.combine = 0;
                iTransHeader.compression = Compression;

                char *pTransData = (char *)GlobalLock(hTransData);
                memcpy(pTransData, &iTransHeader, sizeof(IMAGETRANSHEADER));
                GlobalUnlock(hTransData);
                TransferImage(hTransData, (HWND)recvHandle);
                GlobalFree(hTransData);
                hTransData = NULL;
                return TRUE;
            }
        }
        else
        {
            m_ErrorCode = IA_FILE_NOTEXIST;
        }

        if (m_ErrorCode)
        {
            IMAGETRANSHEADER iTransHeader;
            memset(&iTransHeader, 0, sizeof(IMAGETRANSHEADER));
            memcpy(iTransHeader.Id, info.Id, sizeof(info.Id));
            memcpy(iTransHeader.serialNumber, info.serialNumber, sizeof(info.serialNumber));
            iTransHeader.type = info.type;
            iTransHeader.state = m_ErrorCode;
            memcpy(iTransHeader.docType, info.docType, sizeof(info.docType));
            iTransHeader.totalCount = 1;
            iTransHeader.currentNumber = 1;
            iTransHeader.combine = 0;
            iTransHeader.compression = 0;
            TransferImage(iTransHeader, NULL, (HWND)recvHandle);
        }
    }
    return FALSE;
}

BOOL CIAControllerCtrl::LoadImage(LPCTSTR Id, LPCTSTR serialNumber, long recvHandle)
{
    CSingleLock SingleLock(&m_Sync_CriticalSection);
    SingleLock.Lock();

    if (m_Auth)
    {
        m_ErrorCode = CPictureManager::IA_NOERROR;
        PICTUREINFO info;
        memset(&info, 0, sizeof(PICTUREINFO));
        if (m_PictureManager.GetPictureInfo(Id, serialNumber, &info))
        {
            //HGLOBAL hBits = m_PictureManager.GetPicture(Id,serialNumber,m_ErrorCode);
            int Compression = 0;
            HANDLE hTransData = m_PictureManager.GetPicture(Id, serialNumber, sizeof(IMAGETRANSHEADER), Compression, m_ErrorCode);
            if (hTransData)
            {
                IMAGETRANSHEADER iTransHeader;
                memset(&iTransHeader, 0, sizeof(IMAGETRANSHEADER));
                memcpy(iTransHeader.Id, info.Id, sizeof(info.Id));
                memcpy(iTransHeader.serialNumber, info.serialNumber, sizeof(info.serialNumber));
                iTransHeader.type = info.type;
                memcpy(iTransHeader.deviceName, info.deviceName, sizeof(info.deviceName));
                iTransHeader.state = 0;
                memcpy(iTransHeader.docType, info.docType, sizeof(info.docType));
                iTransHeader.totalCount = 1;
                iTransHeader.currentNumber = 1;
                iTransHeader.combine = 0;
                iTransHeader.compression = Compression;
                char *pTransData = (char *)GlobalLock(hTransData);
                memcpy(pTransData, &iTransHeader, sizeof(IMAGETRANSHEADER));
                GlobalUnlock(hTransData);
                TransferImage(hTransData, (HWND)recvHandle);
                GlobalFree(hTransData);
                hTransData = NULL;
                return TRUE;
            }
        }
        else
        {
            m_ErrorCode = IA_FILE_NOTEXIST;
        }
    }
    return FALSE;
}
