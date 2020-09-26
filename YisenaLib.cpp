#include "YisenaLib.h"

BOOL SelectFileDlg(HWND hWnd,LPTSTR lpStrFile, LPCTSTR lpStrInitialDir,DWORD flags)
{
    OPENFILENAME ofn = { 0 };
    ofn.lStructSize = sizeof(OPENFILENAME);
    ofn.hwndOwner = hWnd;
    ofn.lpstrFilter = NULL;
    ofn.lpstrInitialDir = lpStrInitialDir;//默认的文件路径   
    ofn.lpstrFile = lpStrFile;//存放文件的缓冲区   
    ofn.nMaxFile = MAX_PATH;
    ofn.nFilterIndex = 0;
    ofn.Flags = flags; //标志如果是多选要加上OFN_ALLOWMULTISELECT 
    return GetOpenFileName(&ofn);
}

BOOL SelectFileDlg(HWND hWnd, LPTSTR lpStrFile)
{
    return SelectFileDlg(hWnd, lpStrFile, TEXT(".\\"), OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER);
}

BOOL SelectColorDlg(HWND hWnd,LPDWORD lpColor)
{
    static COLORREF crCustColors[16];
    CHOOSECOLOR cs;
    cs.lStructSize = sizeof(CHOOSECOLOR);
    cs.hwndOwner = hWnd;
    cs.Flags = CC_ANYCOLOR;
    cs.lpCustColors = crCustColors;
    cs.hInstance = 0;
    cs.lpTemplateName = 0;
    cs.lpfnHook = 0;
    BOOL result = ChooseColor(&cs);
    WORD tmp;
    tmp = LOWORD(cs.rgbResult);
    *lpColor = (LOBYTE(tmp) << 16) + (HIBYTE(tmp) << 8) + HIWORD(cs.rgbResult);
    return result;
}
BOOL SelectFont(HWND hWnd,HFONT* lpFont)
{
    CHOOSEFONT cs;
    LOGFONT lf;
    cs.lStructSize = sizeof(CHOOSEFONT);
    cs.hwndOwner = hWnd;
    cs.Flags = CF_INITTOLOGFONTSTRUCT | CF_EFFECTS | CF_SCREENFONTS;
    cs.lpLogFont = &lf;
    BOOL result = ChooseFont(&cs);
    *lpFont = CreateFontIndirect(&lf);
    return result;
}

void ErrorDlg(DWORD eCode)
{
    TCHAR errorStr[19];
    wsprintf(errorStr, TEXT("ErrorCode:%x"), eCode);
    MessageBox(NULL, errorStr, TEXT("Error"), MB_OK | MB_ICONERROR);
}
void ErrorDlg()
{
    ErrorDlg(GetLastError());
}

inline BOOL TransparentStaticBackGround(WPARAM wParam)
{
    SetBkMode((HDC)wParam, TRANSPARENT);
    return (BOOL)((HBRUSH)GetStockObject(NULL_BRUSH));
}

//注册窗口类
bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HBRUSH hBackGroundBrush,HICON hIcon, HCURSOR hCursor)
{
    WNDCLASS wndClass;
    wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_PARENTDC;
    wndClass.lpfnWndProc = lpfnWndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = hInstance;
    wndClass.hIcon = hIcon;
    wndClass.hCursor = hCursor;
    wndClass.hbrBackground = hBackGroundBrush;
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = lpszClassName;
    return RegisterClass(&wndClass);
}
//重载
inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance)
{
    return RegisterWindowClass(lpszClassName, lpfnWndProc,hInstance,(HBRUSH)GetStockObject(WHITE_BRUSH),NULL,LoadCursor(hInstance, IDC_ARROW));
}
//重载背景
inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HBRUSH hBackGroundBrush)
{
    return RegisterWindowClass(lpszClassName, lpfnWndProc, hInstance, hBackGroundBrush, NULL, LoadCursor(hInstance, IDC_ARROW));
}
//重载图标和指针
inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HICON hIcon, HCURSOR hCursor)
{
    return RegisterWindowClass(lpszClassName, lpfnWndProc, hInstance, (HBRUSH)GetStockObject(WHITE_BRUSH), hIcon, hCursor);
}
//创建一个无边框透明窗口
HWND CreateTransparentWindow(LPCTSTR lpszClassName, const RECT &rect,HMENU hMenu,HINSTANCE hInstance)
{
    HWND hwnd = CreateWindowExW(WS_EX_TOPMOST | WS_EX_LAYERED| WS_EX_TOOLWINDOW, lpszClassName, NULL, WS_POPUP| WS_CLIPCHILDREN,
        rect.left, rect.top, rect.right, rect.bottom, nullptr, hMenu, hInstance, nullptr);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    PostMessage(hwnd, WM_PAINT, NULL, NULL);//UpdateWindow不管用
    SetLayeredWindowAttributes(hwnd, GetSysColor(COLOR_APPWORKSPACE), 1, LWA_COLORKEY);
    return hwnd;
}
//重载无菜单
HWND CreateTransparentWindow(LPCTSTR lpszClassName, const RECT& rect,HINSTANCE hInstance)
{
    HWND hwnd = CreateWindowExW(WS_EX_TOPMOST |WS_EX_LAYERED | WS_EX_TOOLWINDOW, lpszClassName, NULL, WS_POPUP| WS_CLIPCHILDREN,
        rect.left, rect.top, rect.right, rect.bottom, nullptr, NULL, hInstance, nullptr);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    PostMessage(hwnd, WM_PAINT, NULL, NULL);//UpdateWindow不管用
    SetLayeredWindowAttributes(hwnd, GetSysColor(COLOR_APPWORKSPACE), 1, LWA_COLORKEY);
    return hwnd;
}
//创建MDI客户区
inline HWND CreateMdiClient(HWND parent,DWORD id,HINSTANCE hInstance)
{
    CLIENTCREATESTRUCT ccs = { NULL,600 };
    return CreateWindow(L"MDICLIENT", NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, 0, 0, 0, 0, parent, HMENU(id), hInstance, (LPVOID)&ccs);
}
//菜单重载
inline HWND CreateMdiClient(HWND parent, DWORD id, HMENU hMenu,HINSTANCE hInstance)
{
    CLIENTCREATESTRUCT ccs = { hMenu,600 };
    return CreateWindow(L"MDICLIENT", NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, 0, 0, 0, 0, parent, HMENU(id), hInstance, (LPVOID)&ccs);
}
//创建mdi子窗口
inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, HINSTANCE hInstance)
{
    return CreateMDIWindow(lpszClassName, lpszWindowName, NULL, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, mdiClient, hInstance, NULL);
}
//重载
inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, const RECT &rect,HINSTANCE hInstance)
{
    return CreateMDIWindow(lpszClassName, lpszWindowName, NULL, rect.left,rect.top,rect.right,rect.bottom, mdiClient, hInstance, NULL);
}
//重载
inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, const RECT& rect, HINSTANCE hInstance,LPARAM lParam)
{
    return CreateMDIWindow(lpszClassName, lpszWindowName, NULL, rect.left, rect.top, rect.right, rect.bottom, mdiClient, hInstance, lParam);
}
HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance, WNDPROC PaintWinProc)
{
    RECT rc;
    LPCTSTR className = L"PAINTCLASS";
    RegisterWindowClass(className, PaintWinProc, hInstance, (HBRUSH)COLOR_APPWORKSPACE + 1);
    GetClientRect(mdiClient, &rc);
    HWND hwnd = CreateMdiChildWindow(mdiClient, className, NULL, rc, hInstance);
    DeleteWindowStyle(hwnd, WS_BORDER|WS_SIZEBOX| WS_SYSMENU| WS_MAXIMIZEBOX| WS_MINIMIZEBOX| WS_CAPTION);
    SetWindowStyleEx(hwnd, WS_EX_LAYERED | WS_EX_NOACTIVATE);
    PostMessage(hwnd, WM_PAINT, NULL, NULL);
    return hwnd;
}
//重载
inline HWND CreatePaintMdiChildWindow(HWND mdiClient,HINSTANCE hInstance)
{
    return CreatePaintMdiChildWindow(mdiClient, hInstance, DefMDIChildProc);
}
bool DeleteWindowStyle(HWND hwnd, UINT style)
{
    return SetWindowLong(hwnd, GWL_STYLE, GetWindowLongW(hwnd, GWL_STYLE) & ~style);
}
bool AddWindowStyle(HWND hwnd, UINT style)
{
    return SetWindowLong(hwnd, GWL_STYLE, GetWindowLongW(hwnd, GWL_STYLE) | style);
}
bool SetWindowStyle(HWND hwnd, UINT style)
{
    return SetWindowLong(hwnd, GWL_STYLE, style);
}
bool DeleteWindowStyleEx(HWND hwnd, UINT style)
{
    return SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLongW(hwnd, GWL_EXSTYLE) & ~style);
}
bool AddWindowStyleEx(HWND hwnd, UINT style)
{
    return SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLongW(hwnd, GWL_EXSTYLE) | style);
}
bool SetWindowStyleEx(HWND hwnd, UINT style)
{
    return SetWindowLong(hwnd, GWL_EXSTYLE, style);
}
//回调函数，删除所有子窗口
BOOL CALLBACK CloseEnumProc(HWND hwnd, LPARAM lParam)
{

    if (GetWindow(hwnd, GW_OWNER)) // Check for icon title
        return TRUE;
    SendMessage(GetParent(hwnd), WM_MDIRESTORE, (WPARAM)hwnd, 0);
    if (!SendMessage(hwnd, WM_QUERYENDSESSION, 0, 0))
        return TRUE;
    SendMessage(GetParent(hwnd), WM_MDIDESTROY, (WPARAM)hwnd, 0);
    return TRUE;
}
//释放窗口堆内存
inline bool FreeWinodwHeap(HWND hwnd)
{
    return HeapFree(GetProcessHeap(), 0, (LPVOID)GetWindowLong(hwnd, 0));
}

//消息循环
int MessageLoop()
{
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}
//搜索内存
LPDWORD SearchMemory(HANDLE hProcess, DWORD nBaseAddr, DWORD nBaseSize, BYTE* lpValue, DWORD nValueSize, LPDWORD numberOfAddr)
{
    LPDWORD lpAddr = nullptr;
    BYTE* buffer = (BYTE*)malloc(nBaseSize);
    if (buffer == nullptr)
        return nullptr;
    if (!ReadProcessMemory(hProcess, (LPVOID)nBaseAddr, buffer, nBaseSize, NULL))
        return nullptr;
    *numberOfAddr = 0;
    DWORD nSize = 0;
    if (nBaseSize < 2)
        return nullptr;
    for (DWORD j, i = 0; i < nBaseSize; i++)
    {
        for (j = 0; j < nValueSize; j++)
        {
            if (buffer[i + j] != lpValue[j])
                break;
        }
        if (j == nValueSize)
        {
            *(LPDWORD)(buffer + nSize) = i + nBaseAddr;
            nSize = (++(*numberOfAddr) << 2);
        }
    }
    if (nSize)
    {
        lpAddr = (LPDWORD)malloc(nSize);
        if (nBaseSize >= nSize)//纯粹防止Waring
            memcpy(lpAddr, buffer, nSize);
    }
    free(buffer);
    return lpAddr;
}
//取模块信息
bool GetProcessModuleInfo(DWORD nPid, LPCTSTR szModuleName, LPDWORD lpBaseAddr, LPDWORD lpBaseSize)
{
    HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
    MODULEENTRY32 me32;
    hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, nPid);
    if (hModuleSnap == INVALID_HANDLE_VALUE)
        return FALSE;
    me32.dwSize = sizeof(MODULEENTRY32);
    if (!Module32First(hModuleSnap, &me32))
        return FALSE;
    do {
        if (lstrcmp(me32.szModule, szModuleName) == 0) {
            *lpBaseAddr = (DWORD)me32.modBaseAddr;
            *lpBaseSize = me32.modBaseSize;
            CloseHandle(hModuleSnap);
            return TRUE;
        }

    } while (Module32Next(hModuleSnap, &me32));
    CloseHandle(hModuleSnap);
    return FALSE;
}
bool FollowTargetWindow(HWND own, HWND target,RECT* rc)
{
    static POINT tmp, tmp1;
    POINT gw = { 0 };
    GetClientRect(target, rc);
    ClientToScreen(target, &gw);
    if (tmp1.x != gw.x || tmp1.y != gw.y)
    {
        SetWindowPos(own, NULL, gw.x, gw.y,rc->right, rc->bottom, SWP_NOREDRAW);
        tmp1 = gw;
    }
    else {
        return false;
    }
    if (tmp.x != rc->right || tmp.y != rc->bottom)
    {
        tmp = {rc->right,rc->bottom };
        SendMessage(own, WM_CREATED2D,0,0);
        return true;
    }
    return false;
}
bool FollowTargetWindow(HWND parent, HWND paint,HWND target,RECT* rc)
{
    static POINT tmp,tmp1;
    POINT gw = { 0 };
    GetClientRect(target, rc);
    ClientToScreen(target, &gw);
    if (tmp1.x != gw.x || tmp1.y != gw.y)
    {
        SetWindowPos(parent, NULL, gw.x, gw.y,rc->right, rc->bottom, SWP_NOREDRAW);
        tmp1 = gw;
    }
    else
    {
        return false;
    }

    if (tmp.x != rc->right || tmp.y != rc->bottom)
    {
        tmp = {rc->right,rc->bottom };
        //绘制子窗口跟随父窗口并置底
        SetWindowPos(paint, HWND_BOTTOM, 0, 0, rc->right, rc->bottom, SWP_NOACTIVATE | SWP_NOREDRAW);
        SendMessage(paint, WM_CREATED2D, 0, 0);
        return true;
    }
    return false;
}
//激活窗口
void ActivateWindow(HWND hWnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    EndPaint(hWnd, &ps);
    ReleaseDC(hWnd, hdc);
}
//初始化托盘图标
void InitNotifyIcon(HWND hWnd,HICON hIcon,LPCTSTR tip, DWORD id,PNOTIFYICONDATA pnid)
{
    pnid->cbSize = sizeof(PNOTIFYICONDATA);
    pnid->hWnd = hWnd;
    pnid->uID = id;
    pnid->uFlags = NIF_ICON | NIF_MESSAGE | NIF_TIP;
    pnid->uCallbackMessage = WM_NOTIFYICON;
    pnid->hIcon = hIcon;
    lstrcpy(pnid->szTip,tip);
}
//创建托盘图标
inline bool CreateNotifyIcon(PNOTIFYICONDATA pnid)
{
    return Shell_NotifyIcon(NIM_ADD, pnid);
}
//删除托盘图标
inline bool DeleteNotifyIcon(PNOTIFYICONDATA pnid)
{
    return Shell_NotifyIcon(NIM_DELETE, pnid);
}
//弹出菜单
inline int PopupMenu(HWND hwnd,HMENU hMenu)
{
    POINT mpt;
    GetCursorPos(&mpt);
    SetForegroundWindow(hwnd);//解决在菜单外单击左键菜单不消失的问题
    return TrackPopupMenu(hMenu, TPM_RETURNCMD, mpt.x, mpt.y, NULL, hwnd, NULL);
}
//任务栏是否重建
inline bool CheckTaskBarRecreated(UINT msg)
{
    static const int WM_TASKBARCREATED = RegisterWindowMessage(TEXT("TaskbarCreated"));//定义任务栏重载消息
    return msg == WM_TASKBARCREATED;
}
//指定按键是否被按下
bool IsKeyClicked(DWORD vKey)
{
    //待优化
    static bool selectedKeyPress[255]{ false };
    if (vKey < 255)
    {
        int selectedKey = GetAsyncKeyState(vKey);
        if (selectedKey & 0x8000 && !selectedKeyPress[vKey]) {
            selectedKeyPress[vKey] = true;
            return true;
        }
        if (!(selectedKey & 0x8000) && selectedKeyPress[vKey]) {
            selectedKeyPress[vKey] = false;
        }
    }
    return false;
}
inline bool IsKeyDown(DWORD vKey)
{
    if (LOWORD(vKey) > 255 || HIWORD(vKey > 255))
        return false;
    return GetAsyncKeyState(vKey) & 0x8000;
}
//int getPressedKey()
//{
//    for (int i = 0; i < 255; i++) {
//        if (GetAsyncKeyState(i) & 0x8000)
//            return i;
//    }
//    return 0;
//}

HBRUSH CreateBitMapBrush(DWORD resId,HINSTANCE hInstance)
{
    //加载位图资源
    HBITMAP hbm = LoadBitmap(hInstance, MAKEINTRESOURCE(resId));
    //创建位图画刷
    HBRUSH hbr = CreatePatternBrush(hbm);
    //删除位图句柄
    DeleteObject(hbm);
    return hbr;
}
bool SwitchWindow(HWND hWnd)
{
    return ShowWindow(hWnd, IsWindowVisible(hWnd) ? SW_HIDE : SW_SHOW);
}
bool StartThread(LPTHREAD_START_ROUTINE lpThreadFunc,LPVOID args)
{
    HANDLE hThread = CreateThread(NULL, NULL, lpThreadFunc, args, 0, 0);
    if (!hThread)
        return false;
    CloseHandle(hThread);
    return true;
}

//构造函数
ConfigFile::ConfigFile(LPCTSTR szFilePath){
    szPath = szFilePath;
}
//读字符串
bool ConfigFile::ReadString(LPCTSTR szAppName, LPCTSTR szKeyName, LPTSTR szValue,DWORD size){
    return GetPrivateProfileString(szAppName, szKeyName, L"", szValue, size, szPath);  
}
//写字符串
bool ConfigFile::WriteString(LPCTSTR szAppName, LPCTSTR szKeyName, LPTSTR szValue) {
    return WritePrivateProfileString(szAppName, szKeyName, szValue, szPath);
}
//读整数
UINT ConfigFile::ReadInt(LPCTSTR szAppName, LPCTSTR szKeyName) {
    return GetPrivateProfileInt(szAppName, szKeyName, 0, szPath);
}
//写整数
bool ConfigFile::WriteInt(LPCTSTR szAppName, LPCTSTR szKeyName, UINT dwValue) {
    TCHAR num[5];
    wsprintf(num, L"%u", dwValue);
    return WriteProfileString(szAppName, szKeyName, num);
}
//读结构
bool ConfigFile::ReadStruct(LPCTSTR szAppName, LPCTSTR szKeyName, LPVOID lpStruct, DWORD size) {
    return GetPrivateProfileStruct(szAppName, szKeyName, lpStruct, size, szPath);
}
//写结构
bool ConfigFile::WriteStruct(LPCTSTR szAppName, LPCTSTR szKeyName, LPVOID lpStruct, DWORD size) {
    return WritePrivateProfileStruct(szAppName, szKeyName, lpStruct, size, szPath);
}