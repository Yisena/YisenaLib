#pragma once
#include <windows.h>
#include <tlhelp32.h>
#include <d2d1_1.h>
#include <dwrite_1.h>
#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")
#pragma comment(lib,"YisenaLib.lib")

#define WM_NOTIFYICON (WM_USER+51)
#define CREATEHINSTANCE(x) (((LPCREATESTRUCT)x)->hInstance)
/// <summary>
/// d2d设备
/// </summary>
typedef struct d2d{
	ID2D1Factory* pD2DFactory = NULL; //d2d工厂
	ID2D1HwndRenderTarget* pRenderTarget = NULL;   //渲染目标
	ID2D1SolidColorBrush* pBrush = NULL; //画刷
	IDWriteFactory* pDWriteFactory = NULL;//文本工厂
	IDWriteTextFormat* pWriteTextFormat = NULL; //文本
	//窗口矩形
	RECT rc;
}d2d;
/// <summary>
/// 选择文件对话框(创建一个文件选择对话框)
/// </summary>
/// <param name="hWnd">窗口句柄</param>
/// <param name="lpStrFile">(返回)文件路径</param>
/// <param name="lpStrInitialDir">对话框默认路径</param>
/// <param name="flags">标志</param>
/// <returns>是否成功</returns>
extern BOOL SelectFileDlg(HWND hWnd, LPTSTR lpStrFile, LPCTSTR lpStrInitialDir, DWORD flags);
/// <summary>
/// 选择文件对话框(默认参数)
/// </summary>
/// <param name="hWnd">窗口路径</param>
/// <param name="lpStrFile">(返回)文件路径</param>
/// <returns>是否成功</returns>
extern BOOL SelectFileDlg(HWND hWnd, LPTSTR lpStrFile);
/// <summary>
/// 错误弹窗(弹出一个显示错误码的消息框)
/// </summary>
/// <param name="eCode">错误码</param>
extern void ErrorDlg(DWORD eCode);
/// <summary>
/// 错误弹窗(自动获取错误码)
/// </summary>
extern void ErrorDlg();
/// <summary>
/// 透明化控件的背景(在窗口过程的WM_CTLCOLORSTATIC消息中使用)
/// </summary>
/// <param name="wParam">窗口过程的wParam参数</param>
/// <returns>消息过程的返回值</returns>
extern inline BOOL TransparentStaticBackGround(WPARAM wParam);
/// <summary>
/// 注册窗口类(指定背景图标光标)
/// </summary>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="lpfnWndProc">窗口过程</param>
/// <param name="hInstance">模块句柄</param>
/// <param name="hBackGroundBrush">背景画刷</param>
/// <param name="hIcon">图标</param>
/// <param name="hCursor">光标</param>
/// <returns>是否成功</returns>
extern bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HBRUSH hBackGroundBrush, HICON hIcon, HCURSOR hCursor);
/// <summary>
/// 注册窗口类(默认参数)
/// </summary>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="lpfnWndProc">窗口过程</param>
/// <param name="hInstance">模块句柄</param>
/// <returns>是否成功</returns>
extern inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance);
/// <summary>
/// 注册窗口类(指定背景画刷)
/// </summary>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="lpfnWndProc">窗口过程</param>
/// <param name="hInstance">模块句柄</param>
/// <param name="hBackGroundBrush">背景画刷</param>
/// <returns>是否成功</returns>
extern inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HBRUSH hBackGroundBrush);
/// <summary>
/// 注册窗口类(指定图标和光标)
/// </summary>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="lpfnWndProc">窗口过程</param>
/// <param name="hInstance">模块句柄</param>
/// <param name="hIcon">图标</param>
/// <param name="hCursor">光标</param>
/// <returns>是否成功</returns>
extern inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HICON hIcon, HCURSOR hCursor);
/// <summary>
/// 创建无边框透明窗口(有菜单)
/// </summary>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="rect">窗口矩形(后两个值是宽度和高度)</param>
/// <param name="hMenu">菜单</param>
/// <param name="hInstance">模块句柄</param>
/// <returns>新窗口句柄</returns>
extern HWND CreateTransparentWindow(LPCTSTR lpszClassName, const RECT &rect,HMENU hMenu, HINSTANCE hInstance);
/// <summary>
/// 创建无边框透明窗口(无菜单)
/// </summary>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="rect">窗口矩形(后两个值是宽度和高度)</param>
/// <param name="hInstance">模块句柄</param>
/// <returns>新窗口句柄</returns>
extern HWND CreateTransparentWindow(LPCTSTR lpszClassName, const RECT &rect,HINSTANCE hInstance);
/// <summary>
/// 创建MDICLIENT
/// </summary>
/// <param name="parent">父窗口句柄</param>
/// <param name="id">控件id</param>
/// <param name="hInstance">模块句柄</param>
/// <returns>控件句柄</returns>
extern inline HWND CreateMdiClient(HWND parent, DWORD id, HINSTANCE hInstance);
/// <summary>
/// 创建MDI子窗口
/// </summary>
/// <param name="parent">MDICLIENT窗口句柄</param>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="lpszWindowName">窗口标题</param>
/// <param name="hInstance">模块句柄</param>
/// <returns>新窗口句柄</returns>
extern inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, HINSTANCE hInstance);
/// <summary>
/// 创建MDI子窗口(指定大小)
/// </summary>
/// <param name="parent">MDICLIENT窗口句柄</param>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="lpszWindowName">窗口标题</param>
/// <param name="hInstance">模块句柄</param>
/// <param name="rect">窗口矩形(后两个值是宽度和高度)</param>
/// <returns>新窗口句柄</returns>
extern inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, const RECT& rect, HINSTANCE hInstance);
/// <summary>
/// 创建MDI子窗口(附加参数)
/// </summary>
/// <param name="parent">MDICLIENT窗口句柄</param>
/// <param name="lpszClassName">窗口类名</param>
/// <param name="lpszWindowName">窗口标题</param>
/// <param name="hInstance">模块句柄</param>
/// <param name="rect">窗口矩形(后两个值是宽度和搞定)</param>
/// <param name="lParam">附加参数</param>
/// <returns>新窗口句柄</returns>
extern inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, const RECT& rect, HINSTANCE hInstance, LPARAM lParam);
/// <summary>
/// 创建MDI绘制子窗口
/// </summary>
/// <param name="mdiClient">MDICLIENT窗口句柄</param>
/// <param name="hInstance">模块句柄</param>
/// <param name="pd2d">d2d设备指针</param>
/// <param name="PaintWinProc">绘制子窗口窗口过程</param>
/// <returns>新窗口句柄</returns>
extern HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance, d2d* pd2d, WNDPROC PaintWinProc);
/// <summary>
/// 创建MDI绘制子窗口(无窗口过程)
/// </summary>
/// <param name="mdiClient">MDICLIENT窗口句柄</param>
/// <param name="hInstance">模块句柄</param>
/// <param name="pd2d">d2d设备指针</param>
/// <returns>新窗口句柄</returns>
extern inline HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance, d2d* pd2d);
/// <summary>
/// 去窗口系统菜单
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <returns>是否成功</returns>
extern inline bool SetWindowNoSysMenu(HWND hwnd);
/// <summary>
/// 删除所有子窗口(配合EnumChildWindows使用)
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <param name="lParam">参数</param>
/// <returns>忽略</returns>
extern BOOL CALLBACK CloseEnumProc(HWND hwnd, LPARAM lParam);
/// <summary>
/// 释放窗口堆内存
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <returns>是否成功</returns>
extern inline bool FreeWinodwHeap(HWND hwnd);
/// <summary>
/// 消息循环
/// </summary>
/// <returns>程序返回值</returns>
extern int MessageLoop();
/// <summary>
/// 搜索内存
/// </summary>
/// <param name="hProcess">进程句柄</param>
/// <param name="nBaseAddr">模块基址</param>
/// <param name="nBaseSize">模块大小</param>
/// <param name="lpValue">要搜索的值</param>
/// <param name="nValueSize">值所占内存大小</param>
/// <param name="numberOfAddr">(返回)结果数</param>
/// <returns>结果地址数组</returns>
extern LPDWORD SearchMemory(HANDLE hProcess, DWORD nBaseAddr, DWORD nBaseSize, BYTE* lpValue, DWORD nValueSize, LPDWORD numberOfAddr);
/// <summary>
/// 取模块信息
/// </summary>
/// <param name="nPid">进程ID</param>
/// <param name="szModuleName">模块名</param>
/// <param name="lpBaseAddr">(返回)模块基址</param>
/// <param name="lpBaseSize">(返回)模块大小</param>
/// <returns>是否成功</returns>
extern bool GetProcessModuleInfo(DWORD nPid, LPCTSTR szModuleName, LPDWORD lpBaseAddr, LPDWORD lpBaseSize);
/// <summary>
/// 初始化d2d
/// </summary>
/// <param name="hWnd">窗口句柄</param>
/// <param name="lpD2d">(返回)d2d设备</param>
/// <returns>是否成功</returns>
extern bool InitD2D(HWND hWnd, d2d* lpD2d);
/// <summary>
/// 释放d2d设备
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
extern void ReleaseD2D(d2d* lpD2d);
/// <summary>
/// 设置绘制颜色
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="color">颜色值</param>
extern inline void BrushColor(d2d* lpD2d, D2D1::ColorF color);
/// <summary>
/// 设置文本水平居中
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
extern inline void SetAlignmentLevelCenter(d2d* lpD2d);
/// <summary>
/// 设置文本左对齐
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
extern inline void SetAlignmentLevelLeft(d2d* lpD2d);
/// <summary>
/// 设置文本右对齐
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
extern inline void SetAlignmentLevelRight(d2d* lpD2d);
/// <summary>
/// 设置文本垂直居中
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
extern inline void SetAlignmentVerticalCenter(d2d* lpD2d);
/// <summary>
/// 设置文本垂直靠顶
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
extern inline void SetAlignmentVerticalTop(d2d* lpD2d);
/// <summary>
/// 设置文本垂直靠底
/// </summary>
/// <param name="lpD2d">d2d设备结构指针</param>
extern inline void SetAlignmentVerticalBottom(d2d* lpD2d);
/// <summary>
/// 画普通矩形(指定线宽)
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="rect">矩形结构</param>
/// <param name="sweight">宽度</param>
extern inline void DrawRect(d2d* lpD2d,const D2D1_RECT_F &rect, float sweight);
/// <summary>
/// 画普通矩形(不指定线宽)
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="rect">矩形结构</param>
extern inline void DrawRect(d2d* lpD2d, const D2D1_RECT_F &rect);
/// <summary>
/// 画普通矩形(填充)
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="rect">矩形结构</param>
extern inline void FillRect(d2d* lpD2d, const D2D1_RECT_F &rect);
/// <summary>
/// 画圆(指定线宽)
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="ellipse">圆结构</param>
/// <param name="sweight">线宽</param>
extern inline void DrawCircle(d2d* lpD2d, const D2D1_ELLIPSE &ellipse, float sweight);
/// <summary>
/// 画圆(不指定线宽)
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="ellipse">圆结构</param>
extern void DrawCircle(d2d* lpD2d, const D2D1_ELLIPSE& ellipse);
/// <summary>
/// 画圆(填充)
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="ellipse">圆结构</param>
extern void FillCircle(d2d* lpD2d, const D2D1_ELLIPSE& ellipse);
/// <summary>
/// 画线(指定线宽)
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="p1">点1</param>
/// <param name="p2">点2</param>
/// <param name="sweight">线宽</param>
extern inline void DrawLine(d2d* lpD2d, D2D1_POINT_2F p1, D2D1_POINT_2F p2, float sweight);
/// <summary>
/// 画线(不指定线宽)
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="p1">点1</param>
/// <param name="p2">点2</param>
extern inline void DrawLine(d2d* lpD2d, D2D1_POINT_2F p1, D2D1_POINT_2F p2);
/// <summary>
/// 输出字符串
/// </summary>
/// <param name="lpD2d">d2d设备指针</param>
/// <param name="str">字符串</param>
/// <param name="rect">矩形结构</param>
extern inline void DrawStr(d2d* lpD2d, LPCTSTR str, const D2D1_RECT_F &rect);
/// <summary>
/// 跟随窗口(普通)
/// </summary>
/// <param name="own">自身窗口句柄</param>
/// <param name="target">目标窗口句柄</param>
/// <param name="lpD2d">d2d设备指针</param>
extern void FollowTargetWindow(HWND own, HWND target, d2d* lpD2d);
/// <summary>
/// 跟随窗口(MDI)
/// </summary>
/// <param name="parent">父窗口句柄</param>
/// <param name="paint">绘制子窗口句柄</param>
/// <param name="target">目标窗口句柄</param>
/// <param name="lpD2d">d2d设备指针</param>
extern void FollowTargetWindow(HWND parent, HWND paint, HWND target, d2d* lpD2d);
/// <summary>
/// 初始化托盘通知图标
/// </summary>
/// <param name="hWnd">窗口句柄</param>
/// <param name="hIcon">图标</param>
/// <param name="tip">鼠标在图标上悬停时显示的文字(系统设定最大128)</param>
/// <param name="id">图标id</param>
/// <param name="pnid">托盘通知图标结构指针</param>
extern void InitNotifyIcon(HWND hWnd, HICON hIcon, LPCTSTR tip,DWORD id, PNOTIFYICONDATA pnid);
/// <summary>
/// 创建托盘通知图标
/// </summary>
/// <param name="pnid">托盘通知图标结构指针</param>
/// <returns>是否成功</returns>
extern inline bool CreateNotifyIcon(PNOTIFYICONDATA pnid);
/// <summary>
/// 删除托盘通知图标
/// </summary>
/// <param name="pnid">托盘通知图标结构指针</param>
/// <returns>是否成功</returns>
extern inline bool DeleteNotifyIcon(PNOTIFYICONDATA pnid);
/// <summary>
/// 弹出菜单
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <param name="hMenu">菜单句柄</param>
/// <returns>是否成功</returns>
extern inline int PopupMenu(HWND hwnd, HMENU hMenu);
/// <summary>
/// 判断消息是否为任务栏重建
/// </summary>
/// <param name="msg">消息</param>
extern inline bool CheckTaskBarRecreated(UINT msg);
/// <summary>
/// 指定按键是否被点击
/// </summary>
/// <param name="vKey">按键码</param>
/// <returns>是否被点击</returns>
extern bool isKeyClicked(int vKey);
/// <summary>
/// 创建位图画刷
/// </summary>
/// <param name="resId">位图的资源标识</param>
/// <param name="hInstance">模块句柄</param>
/// <returns>画刷句柄</returns>
extern HBRUSH CreateBitMapBrush(DWORD resId, HINSTANCE hInstance);