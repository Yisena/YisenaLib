#include "YisenaLib.h"

BOOL SelectFileDlg(HWND hWnd,LPTSTR lpStrFile, LPCTSTR lpStrInitialDir,DWORD flags)
{
    OPENFILENAME ofn = { 0 };
    ofn.lStructSize = sizeof(ofn);
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
    return RegisterWindowClass(lpszClassName, lpfnWndProc,hInstance,(HBRUSH)GetStockObject(WHITE_BRUSH),NULL,NULL);
}
//重载背景
inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HBRUSH hBackGroundBrush)
{
    return RegisterWindowClass(lpszClassName, lpfnWndProc, hInstance, hBackGroundBrush, NULL, NULL);
}
//重载图标和指针
inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HICON hIcon, HCURSOR hCursor)
{
    return RegisterWindowClass(lpszClassName, lpfnWndProc, hInstance, (HBRUSH)GetStockObject(WHITE_BRUSH), hIcon, hCursor);
}
//创建一个无边框透明窗口
HWND CreateTransparentWindow(LPCTSTR lpszClassName, const RECT &rect,HMENU hMenu,HINSTANCE hInstance)
{
    HWND hwnd = CreateWindowExW(WS_EX_TOPMOST | WS_EX_LAYERED| WS_EX_TOOLWINDOW| WS_EX_NOINHERITLAYOUT, lpszClassName, NULL, WS_POPUP| WS_CLIPCHILDREN,
        rect.left, rect.top, rect.right, rect.bottom, nullptr, hMenu, hInstance, nullptr);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    PostMessage(hwnd, WM_PAINT, NULL, NULL);//UpdateWindow不管用
    SetLayeredWindowAttributes(hwnd, GetSysColor(COLOR_APPWORKSPACE), 1, LWA_COLORKEY);
    return hwnd;
}
//重载无菜单
HWND CreateTransparentWindow(LPCTSTR lpszClassName, const RECT& rect,HINSTANCE hInstance)
{
    HWND hwnd = CreateWindowExW(WS_EX_TOPMOST |WS_EX_LAYERED | WS_EX_TOOLWINDOW| WS_EX_NOINHERITLAYOUT, lpszClassName, NULL, WS_POPUP| WS_CLIPCHILDREN,
        rect.left, rect.top, rect.right, rect.bottom, nullptr, NULL, hInstance, nullptr);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    PostMessage(hwnd, WM_PAINT, NULL, NULL);//UpdateWindow不管用
    SetLayeredWindowAttributes(hwnd, GetSysColor(COLOR_APPWORKSPACE), 1, LWA_COLORKEY);
    return hwnd;
}
//创建MDI客户区
inline HWND CreateMdiClient(HWND parent,DWORD id,HINSTANCE hInstance)
{
    CLIENTCREATESTRUCT ccs; ccs = { NULL,600 };
    return CreateWindowEx(MDIS_ALLCHILDSTYLES,L"MDICLIENT", NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN, 0, 0, 0, 0, parent, HMENU(id), hInstance, (LPVOID)&ccs);
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
HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance, d2d* pd2d, WNDPROC PaintWinProc)
{
    LPCTSTR className = L"PAINTCLASS";
    RegisterWindowClass(className, PaintWinProc,hInstance,(HBRUSH)COLOR_APPWORKSPACE + 1);
    GetClientRect(mdiClient, &pd2d->rc);
    HWND hwnd = CreateMdiChildWindow(mdiClient, className, NULL,pd2d->rc,hInstance);
    SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE) ^ WS_SYSMENU ^ WS_CAPTION ^ WS_BORDER ^ WS_SIZEBOX);
    SetWindowLong(hwnd, GWL_EXSTYLE, WS_EX_LAYERED|WS_EX_NOACTIVATE);
    PostMessage(hwnd, WM_PAINT, NULL, NULL);
    return hwnd;
}
//重载
inline HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance, d2d* pd2d)
{
    return CreatePaintMdiChildWindow(mdiClient, hInstance, pd2d, DefMDIChildProc);
}
//去系统菜单
inline bool SetWindowNoSysMenu(HWND hwnd)
{
    return SetWindowLong(hwnd, GWL_STYLE, GetWindowLongW(hwnd, GWL_STYLE) & ~WS_SYSMENU);
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

//初始化D2D,在窗口过程的WM_CREATE消息中使用
bool InitD2D(HWND hWnd,d2d* lpD2d)
{
    //绘制区域
    GetClientRect(hWnd, &lpD2d->rc);
    HRESULT hr; //接受返回值来判断是否失败
    hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &lpD2d->pD2DFactory);
    if (FAILED(hr))
        return false;
    //创建渲染目标
    hr = lpD2d->pD2DFactory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(lpD2d->rc.right - lpD2d->rc.left, lpD2d->rc.bottom - lpD2d->rc.top)), &lpD2d->pRenderTarget);
    if (FAILED(hr))
        return false;
    hr = lpD2d->pRenderTarget->CreateSolidColorBrush((D2D1::ColorF)D2D1::ColorF::Red, &lpD2d->pBrush);
    if (FAILED(hr))
        return false;
    //创建文本工厂
    hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), reinterpret_cast<IUnknown**>(&lpD2d->pDWriteFactory));
    if (FAILED(hr))
        return false;
    //创建文本
    //第一个参数是字体名，倒数第三个是字体大小，倒数第二个是字体语言
    hr = lpD2d->pDWriteFactory->CreateTextFormat(L"微软雅黑", NULL, DWRITE_FONT_WEIGHT_REGULAR, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 12.0f, L"zh-cn", &lpD2d->pWriteTextFormat);
    if (FAILED(hr))
        return false;
    //设置水平居中
    SetAlignmentLevelCenter(lpD2d);
    //设置段落居中
    SetAlignmentVerticalCenter(lpD2d);
    return true;
}
void ReleaseD2D(d2d* lpD2d)
{
    if (lpD2d->pD2DFactory)
        lpD2d->pD2DFactory->Release();
    if (lpD2d->pRenderTarget)
        lpD2d->pRenderTarget->Release();
    if (lpD2d->pBrush)
        lpD2d->pBrush->Release();
    if (lpD2d->pDWriteFactory)
        lpD2d->pDWriteFactory->Release();
    if (lpD2d->pWriteTextFormat)
        lpD2d->pWriteTextFormat->Release();
}
//设置颜色
inline void BrushColor(d2d* lpD2d,D2D1::ColorF color)
{
    lpD2d->pBrush->SetColor(color);
}
//设置文本水平居中
inline void SetAlignmentLevelCenter(d2d* lpD2d)
{
    lpD2d->pWriteTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
}
//设置文本左对齐
inline void SetAlignmentLevelLeft(d2d* lpD2d)
{
    lpD2d->pWriteTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
}
//设置文本右对齐
inline void SetAlignmentLevelRight(d2d* lpD2d)
{
    lpD2d->pWriteTextFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
}
//设置文本垂直居中
inline void SetAlignmentVerticalCenter(d2d* lpD2d)
{
    lpD2d->pWriteTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_CENTER);
}
//设置文本靠顶
inline void SetAlignmentVerticalTop(d2d* lpD2d)
{
    lpD2d->pWriteTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);
}
//设置文本靠底
inline void SetAlignmentVerticalBottom(d2d* lpD2d)
{
    lpD2d->pWriteTextFormat->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_FAR);
}
//画普通矩形
inline void DrawRect(d2d* lpD2d,const D2D1_RECT_F &rect,float sweight)
{
    lpD2d->pRenderTarget->DrawRectangle(rect, lpD2d->pBrush, sweight);
}
//画普通矩形重载
inline void DrawRect(d2d* lpD2d, const D2D1_RECT_F& rect)
{
    lpD2d->pRenderTarget->DrawRectangle(rect, lpD2d->pBrush);
}
//画普通矩形填充
inline void FillRect(d2d* lpD2d, const D2D1_RECT_F& rect)
{
    lpD2d->pRenderTarget->FillRectangle(rect, lpD2d->pBrush);
}
//画圆
inline void DrawCircle(d2d* lpD2d,const D2D1_ELLIPSE &ellipse,float sweight)
{
    lpD2d->pRenderTarget->DrawEllipse(ellipse, lpD2d->pBrush, sweight);
}
//画圆重载
inline void DrawCircle(d2d* lpD2d,const D2D1_ELLIPSE &ellipse)
{
    lpD2d->pRenderTarget->DrawEllipse(ellipse, lpD2d->pBrush);
}
inline void FillCircle(d2d* lpD2d,const D2D1_ELLIPSE &ellipse)
{
    lpD2d->pRenderTarget->FillEllipse(ellipse, lpD2d->pBrush);
}
//画线
inline void DrawLine(d2d* lpD2d,D2D1_POINT_2F p1, D2D1_POINT_2F p2,float sweight)
{
    lpD2d->pRenderTarget->DrawLine(p1, p2, lpD2d->pBrush, sweight);
}
//画线重载
inline void DrawLine(d2d* lpD2d, D2D1_POINT_2F p1, D2D1_POINT_2F p2)
{
    lpD2d->pRenderTarget->DrawLine(p1, p2, lpD2d->pBrush);
}
//输出字符串
inline void DrawStr(d2d* lpD2d, LPCTSTR str, const D2D1_RECT_F &rect)
{
    lpD2d->pRenderTarget->DrawText(str, lstrlen(str), lpD2d->pWriteTextFormat, rect, lpD2d->pBrush);
}
void FollowTargetWindow(HWND own, HWND target,d2d* lpD2d)
{
    static POINT tmp, tmp1;
    POINT gw = { 0 };
    GetClientRect(target, &lpD2d->rc);
    ClientToScreen(target, &gw);
    if (tmp1.x != gw.x || tmp1.y != gw.y)
    {
        SetWindowPos(own, NULL, gw.x, gw.y, lpD2d->rc.right, lpD2d->rc.bottom, SWP_NOREDRAW);
        tmp1 = gw;
    }
    else
    {
        Sleep(50);
    }
    if (tmp.x != lpD2d->rc.right || tmp.y != lpD2d->rc.bottom)
    {
        ReleaseD2D(lpD2d);
        tmp = { lpD2d->rc.right,lpD2d->rc.bottom };
        InitD2D(own, lpD2d);
    }
}
void FollowTargetWindow(HWND parent, HWND paint,HWND target, d2d* lpD2d)
{
    static POINT tmp,tmp1;
    POINT gw = { 0 };
    GetClientRect(target, &lpD2d->rc);
    ClientToScreen(target, &gw);
    if (tmp1.x != gw.x || tmp1.y != gw.y)
    {
        SetWindowPos(parent, NULL, gw.x, gw.y, lpD2d->rc.right, lpD2d->rc.bottom, SWP_NOREDRAW);
        tmp1 = gw;
    }
    else
    {
        Sleep(50);
    }

    if (tmp.x != lpD2d->rc.right || tmp.y != lpD2d->rc.bottom)
    {
        ReleaseD2D(lpD2d);
        tmp = { lpD2d->rc.right,lpD2d->rc.bottom };
        //绘制子窗口跟随父窗口并置底
        SetWindowPos(paint, HWND_BOTTOM, 0, 0, lpD2d->rc.right, lpD2d->rc.bottom, SWP_NOACTIVATE | SWP_NOREDRAW);
        InitD2D(paint, lpD2d);
    }
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
bool isKeyClicked(int vKey)
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
inline bool isKeyDown(int vKey)
{
    if (vKey > 255)
        return false;
    return GetAsyncKeyState(vKey) & 0x8000;
}

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