#pragma once
#include <windows.h>
#include <tlhelp32.h>
#include <d2d1.h>
#include <dwrite.h>
#pragma comment(lib,"YisenaLib.lib")
#pragma comment(lib,"d2d1.lib")
#pragma comment(lib,"dwrite.lib")
#define WM_NOTIFYICON (WM_USER+51)
#define WM_CREATED2D (WM_USER+52)
#define CREATEHINSTANCE(x) (((LPCREATESTRUCT)x)->hInstance)
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
/// <param name="hWnd">窗口句柄</param>
/// <param name="lpStrFile">(返回)文件路径</param>
/// <returns>是否成功</returns>
extern BOOL SelectFileDlg(HWND hWnd, LPTSTR lpStrFile);
/// <summary>
/// 选择颜色对话框
/// </summary>
/// <param name="hWnd">窗口句柄</param>
/// <param name="lpColor">(返回)选择的颜色值</param>
/// <returns>是否选择</returns>
extern BOOL SelectColorDlg(HWND hWnd, LPDWORD lpColor);
/// <summary>
/// 选择字体(未测试)
/// </summary>
/// <param name="hWnd">窗口句柄</param>
/// <param name="lpFont">(返回)选择的颜色值</param>
/// <returns>是否成功</returns>
extern BOOL SelectFont(HWND hWnd, HFONT* lpFont);
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
/// 创建MDICLIENT
/// </summary>
/// <param name="parent">父窗口句柄</param>
/// <param name="id">控件id</param>
/// <param name="hMenu">菜单句柄</param>
/// <param name="hInstance">模块句柄</param>
/// <returns>控件句柄</returns>
extern inline HWND CreateMdiClient(HWND parent, DWORD id, HMENU hMenu, HINSTANCE hInstance);
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
extern HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance,WNDPROC PaintWinProc);
/// <summary>
/// 创建MDI绘制子窗口(无窗口过程)
/// </summary>
/// <param name="mdiClient">MDICLIENT窗口句柄</param>
/// <param name="hInstance">模块句柄</param>
/// <param name="pd2d">d2d设备指针</param>
/// <returns>新窗口句柄</returns>
extern inline HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance);
/// <summary>
/// 删除窗口样式
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <param name="style">样式</param>
/// <returns>是否成功</returns>
bool DeleteWindowStyle(HWND hwnd, UINT style);
/// <summary>
/// 添加窗口样式
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <param name="style">样式</param>
/// <returns>是否成功</returns>
bool AddWindowStyle(HWND hwnd, UINT style);
/// <summary>
/// 设置窗口样式
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <param name="style">样式</param>
/// <returns>是否成功</returns>
bool SetWindowStyle(HWND hwnd, UINT style);
/// <summary>
/// 删除窗口样式(EX)
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <param name="style">样式</param>
/// <returns>是否成功</returns>
bool DeleteWindowStyleEx(HWND hwnd, UINT style);
/// <summary>
/// 添加窗口样式(EX)
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <param name="style">样式</param>
/// <returns>是否成功</returns>
bool AddWindowStyleEx(HWND hwnd, UINT style);
/// <summary>
/// 设置窗口样式(EX)
/// </summary>
/// <param name="hwnd">窗口句柄</param>
/// <param name="style">样式</param>
/// <returns>是否成功</returns>
bool SetWindowStyleEx(HWND hwnd, UINT style);
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
/// 跟随窗口(普通)
/// </summary>
/// <param name="own">自身窗口句柄</param>
/// <param name="target">目标窗口句柄</param>
/// <param name="rc">[IN][OUT]窗口矩形</param>
/// <returns>窗口大小是否改变</returns>
extern bool FollowTargetWindow(HWND own, HWND target,RECT* rc);
/// <summary>
/// 跟随窗口(MDI)
/// </summary>
/// <param name="parent">父窗口句柄</param>
/// <param name="paint">绘制子窗口句柄</param>
/// <param name="target">目标窗口句柄</param>
/// <param name="rc">[IN][OUT]新窗口矩形</param>
/// <returns>窗口大小是否改变</returns>
extern bool FollowTargetWindow(HWND parent, HWND paint, HWND target,RECT* rc);
/// <summary>
/// 激活窗口(PAINT)
/// </summary>
/// <param name="hWnd">窗口句柄</param>
extern void ActivateWindow(HWND hWnd);
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
extern bool IsKeyClicked(DWORD vKey);
/// <summary>
/// 指定按键是否按下
/// </summary>
/// <param name="vKey">按键码</param>
/// <returns>是否按下</returns>
extern inline bool IsKeyDown(DWORD vKey);
/// <summary>
/// 创建位图画刷
/// </summary>
/// <param name="resId">位图的资源标识</param>
/// <param name="hInstance">模块句柄</param>
/// <returns>画刷句柄</returns>
extern HBRUSH CreateBitMapBrush(DWORD resId, HINSTANCE hInstance);
/// <summary>
/// 开关窗口
/// </summary>
/// <param name="hWnd">窗口句柄</param>
/// <returns>是否成功</returns>
extern bool SwitchWindow(HWND hWnd);
/// <summary>
/// 以新线程启动函数
/// </summary>
/// <param name="lpThreadFunc">线程函数</param>
/// <param name="args">参数</param>
/// <returns>是否成功</returns>
extern bool StartThread(LPTHREAD_START_ROUTINE lpThreadFunc, LPVOID args);


//EasyD2D类
class EasyD2D {
private:
	ID2D1Factory* pD2DFactory;					//d2d工厂
	ID2D1HwndRenderTarget* pRenderTarget;		//渲染目标
	ID2D1SolidColorBrush* pBrush;				//画刷
	IDWriteFactory* pDWriteFactory;				//文本工厂
	IDWriteTextFormat* pBigWriteTextFormat;		//文本 大字体
	IDWriteTextFormat* pSmallWriteTextFormat;	//文本 小字体
public:
	EasyD2D();
	~EasyD2D();
	/// <summary>
	/// 初始化D2D
	/// </summary>
	/// <param name="hWnd">绘制窗口句柄</param>
	/// <returns>是否成功</returns>
	bool Init(HWND hWnd);
	/// <summary>
	/// 开始绘制
	/// </summary>
	void BeginDraw();
	/// <summary>
	/// 结束绘制
	/// </summary>
	void EndDraw();
	/// <summary>
	/// 清屏
	/// </summary>
	/// <param name="color">填充的颜色值</param>
	void Clear(D2D1::ColorF color);
	/// <summary>
	/// 设置绘制颜色
	/// </summary>
	/// <param name="color">颜色值</param>
	void SetColor(D2D1::ColorF color);
	/// <summary>
	/// 设置文本水平居中
	/// </summary>
	void SetAlignmentLevelCenter();
	/// <summary>
	/// 设置文本左对齐
	/// </summary>
	void SetAlignmentLevelLeft();
	/// <summary>
	/// 设置文本右对齐
	/// </summary>
	void SetAlignmentLevelRight();
	/// <summary>
	/// 设置文本垂直居中
	/// </summary>
	void SetAlignmentVerticalCenter();
	/// <summary>
	/// 设置文本靠顶
	/// </summary>
	void SetAlignmentVerticalTop();
	/// <summary>
	/// 设置文本靠底
	/// </summary>
	void SetAlignmentVerticalBottom();
	/// <summary>
	/// 画矩形
	/// </summary>
	/// <param name="rect">矩形结构</param>
	void DrawRect(const D2D1_RECT_F& rect);
	/// <summary>
	/// 画矩形(指定线宽)
	/// </summary>
	/// <param name="rect">矩形结构</param>
	/// <param name="lWeight">线宽</param>
	void DrawRect(const D2D1_RECT_F& rect, float lWeight);
	/// <summary>
	/// 填充矩形
	/// </summary>
	/// <param name="rect">矩形结构</param>
	void FillRect(const D2D1_RECT_F& rect);
	/// <summary>
	/// 画圆
	/// </summary>
	/// <param name="ellipse">圆形结构</param>
	void DrawCircle(const D2D1_ELLIPSE& ellipse);
	/// <summary>
	/// 画圆(指定线宽)
	/// </summary>
	/// <param name="ellipse">圆形结构</param>
	/// <param name="lWeight">线宽</param>
	void DrawCircle(const D2D1_ELLIPSE& ellipse, float lWeight);
	/// <summary>
	/// 填充圆
	/// </summary>
	/// <param name="ellipse">圆形结构</param>
	void FillCircle(const D2D1_ELLIPSE& ellipse);
	/// <summary>
	/// 画线
	/// </summary>
	/// <param name="p1">第一个点坐标</param>
	/// <param name="p2">第二个点坐标</param>
	void DrawLine(D2D1_POINT_2F p1, D2D1_POINT_2F p2);
	/// <summary>
	/// 画线(指定线宽)
	/// </summary>
	/// <param name="p1">第一个点坐标</param>
	/// <param name="p2">第二个点坐标</param>
	/// <param name="lWeight">线宽</param>
	void DrawLine(D2D1_POINT_2F p1, D2D1_POINT_2F p2, float lWeight);
	/// <summary>
	/// 画字符
	/// </summary>
	/// <param name="str">字符指针</param>
	/// <param name="rect">字符区域(矩形结构)</param>
	/// <param name="isBigFont">是否使用大字体</param>
	void DrawStr(LPCTSTR str, const D2D1_RECT_F& rect, bool isBigFont);
};

class ConfigFile {
private:
	LPCTSTR szPath;
public:
	/// <summary>
	/// 构造函数
	/// </summary>
	/// <param name="szFilePath">配置文件目录</param>
	ConfigFile(LPCTSTR szFilePath);
	/// <summary>
	/// 读字符键值
	/// </summary>
	/// <param name="szAppName">字段名</param>
	/// <param name="szKeyName">键名</param>
	/// <param name="szValue">[OUT]用于缓存值的指针</param>
	/// <param name="size">缓存的大小</param>
	/// <returns>是否成功</returns>
	bool ReadString(LPCTSTR szAppName,LPCTSTR szKeyName,LPTSTR szValue,DWORD size);
	/// <summary>
	/// 写字符键值
	/// </summary>
	/// <param name="szAppName">字段名</param>
	/// <param name="szKeyName">键名</param>
	/// <param name="szValue">[IN]要写的键值</param>
	/// <returns>是否成功</returns>
	bool WriteString(LPCTSTR szAppName, LPCTSTR szKeyName, LPTSTR szValue);
	/// <summary>
	/// 读整数
	/// </summary>
	/// <param name="szAppName">字段名</param>
	/// <param name="szKeyName">键名</param>
	/// <returns>键值(默认返回0)</returns>
	UINT ReadInt(LPCTSTR szAppName, LPCTSTR szKeyName);
	/// <summary>
	/// 写整数
	/// </summary>
	/// <param name="szAppName">字段名</param>
	/// <param name="szKeyName">键名</param>
	/// <param name="dwValue">键值</param>
	/// <returns>是否成功</returns>
	bool WriteInt(LPCTSTR szAppName, LPCTSTR szKeyName, UINT dwValue);
	/// <summary>
	/// 读结构
	/// </summary>
	/// <param name="szAppName">字段名</param>
	/// <param name="szKeyName">键名</param>
	/// <param name="lpStruct">[OUT]结构体指针</param>
	/// <param name="size">结构体大小</param>
	/// <returns>是否成功</returns>
	bool ReadStruct(LPCTSTR szAppName, LPCTSTR szKeyName, LPVOID lpStruct, DWORD size);
	/// <summary>
	/// 写结构
	/// </summary>
	/// <param name="szAppName">字段名</param>
	/// <param name="szKeyName">键名</param>
	/// <param name="lpStruct">[IN]结构体指针</param>
	/// <param name="size">结构体大小</param>
	/// <returns>是否成功</returns>
	bool WriteStruct(LPCTSTR szAppName, LPCTSTR szKeyName, LPVOID lpStruct, DWORD size);
};