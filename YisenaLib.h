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
/// ѡ���ļ��Ի���(����һ���ļ�ѡ��Ի���)
/// </summary>
/// <param name="hWnd">���ھ��</param>
/// <param name="lpStrFile">(����)�ļ�·��</param>
/// <param name="lpStrInitialDir">�Ի���Ĭ��·��</param>
/// <param name="flags">��־</param>
/// <returns>�Ƿ�ɹ�</returns>
extern BOOL SelectFileDlg(HWND hWnd, LPTSTR lpStrFile, LPCTSTR lpStrInitialDir, DWORD flags);
/// <summary>
/// ѡ���ļ��Ի���(Ĭ�ϲ���)
/// </summary>
/// <param name="hWnd">���ھ��</param>
/// <param name="lpStrFile">(����)�ļ�·��</param>
/// <returns>�Ƿ�ɹ�</returns>
extern BOOL SelectFileDlg(HWND hWnd, LPTSTR lpStrFile);
/// <summary>
/// ѡ����ɫ�Ի���
/// </summary>
/// <param name="hWnd">���ھ��</param>
/// <param name="lpColor">(����)ѡ�����ɫֵ</param>
/// <returns>�Ƿ�ѡ��</returns>
extern BOOL SelectColorDlg(HWND hWnd, LPDWORD lpColor);
/// <summary>
/// ѡ������(δ����)
/// </summary>
/// <param name="hWnd">���ھ��</param>
/// <param name="lpFont">(����)ѡ�����ɫֵ</param>
/// <returns>�Ƿ�ɹ�</returns>
extern BOOL SelectFont(HWND hWnd, HFONT* lpFont);
/// <summary>
/// ���󵯴�(����һ����ʾ���������Ϣ��)
/// </summary>
/// <param name="eCode">������</param>
extern void ErrorDlg(DWORD eCode);
/// <summary>
/// ���󵯴�(�Զ���ȡ������)
/// </summary>
extern void ErrorDlg();
/// <summary>
/// ͸�����ؼ��ı���(�ڴ��ڹ��̵�WM_CTLCOLORSTATIC��Ϣ��ʹ��)
/// </summary>
/// <param name="wParam">���ڹ��̵�wParam����</param>
/// <returns>��Ϣ���̵ķ���ֵ</returns>
extern inline BOOL TransparentStaticBackGround(WPARAM wParam);
/// <summary>
/// ע�ᴰ����(ָ������ͼ����)
/// </summary>
/// <param name="lpszClassName">��������</param>
/// <param name="lpfnWndProc">���ڹ���</param>
/// <param name="hInstance">ģ����</param>
/// <param name="hBackGroundBrush">������ˢ</param>
/// <param name="hIcon">ͼ��</param>
/// <param name="hCursor">���</param>
/// <returns>�Ƿ�ɹ�</returns>
extern bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HBRUSH hBackGroundBrush, HICON hIcon, HCURSOR hCursor);
/// <summary>
/// ע�ᴰ����(Ĭ�ϲ���)
/// </summary>
/// <param name="lpszClassName">��������</param>
/// <param name="lpfnWndProc">���ڹ���</param>
/// <param name="hInstance">ģ����</param>
/// <returns>�Ƿ�ɹ�</returns>
extern inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance);
/// <summary>
/// ע�ᴰ����(ָ��������ˢ)
/// </summary>
/// <param name="lpszClassName">��������</param>
/// <param name="lpfnWndProc">���ڹ���</param>
/// <param name="hInstance">ģ����</param>
/// <param name="hBackGroundBrush">������ˢ</param>
/// <returns>�Ƿ�ɹ�</returns>
extern inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HBRUSH hBackGroundBrush);
/// <summary>
/// ע�ᴰ����(ָ��ͼ��͹��)
/// </summary>
/// <param name="lpszClassName">��������</param>
/// <param name="lpfnWndProc">���ڹ���</param>
/// <param name="hInstance">ģ����</param>
/// <param name="hIcon">ͼ��</param>
/// <param name="hCursor">���</param>
/// <returns>�Ƿ�ɹ�</returns>
extern inline bool RegisterWindowClass(LPCTSTR lpszClassName, WNDPROC lpfnWndProc, HINSTANCE hInstance, HICON hIcon, HCURSOR hCursor);
/// <summary>
/// �����ޱ߿�͸������(�в˵�)
/// </summary>
/// <param name="lpszClassName">��������</param>
/// <param name="rect">���ھ���(������ֵ�ǿ�Ⱥ͸߶�)</param>
/// <param name="hMenu">�˵�</param>
/// <param name="hInstance">ģ����</param>
/// <returns>�´��ھ��</returns>
extern HWND CreateTransparentWindow(LPCTSTR lpszClassName, const RECT &rect,HMENU hMenu, HINSTANCE hInstance);
/// <summary>
/// �����ޱ߿�͸������(�޲˵�)
/// </summary>
/// <param name="lpszClassName">��������</param>
/// <param name="rect">���ھ���(������ֵ�ǿ�Ⱥ͸߶�)</param>
/// <param name="hInstance">ģ����</param>
/// <returns>�´��ھ��</returns>
extern HWND CreateTransparentWindow(LPCTSTR lpszClassName, const RECT &rect,HINSTANCE hInstance);
/// <summary>
/// ����MDICLIENT
/// </summary>
/// <param name="parent">�����ھ��</param>
/// <param name="id">�ؼ�id</param>
/// <param name="hInstance">ģ����</param>
/// <returns>�ؼ����</returns>
extern inline HWND CreateMdiClient(HWND parent, DWORD id, HINSTANCE hInstance);
/// <summary>
/// ����MDICLIENT
/// </summary>
/// <param name="parent">�����ھ��</param>
/// <param name="id">�ؼ�id</param>
/// <param name="hMenu">�˵����</param>
/// <param name="hInstance">ģ����</param>
/// <returns>�ؼ����</returns>
extern inline HWND CreateMdiClient(HWND parent, DWORD id, HMENU hMenu, HINSTANCE hInstance);
/// <summary>
/// ����MDI�Ӵ���
/// </summary>
/// <param name="parent">MDICLIENT���ھ��</param>
/// <param name="lpszClassName">��������</param>
/// <param name="lpszWindowName">���ڱ���</param>
/// <param name="hInstance">ģ����</param>
/// <returns>�´��ھ��</returns>
extern inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, HINSTANCE hInstance);
/// <summary>
/// ����MDI�Ӵ���(ָ����С)
/// </summary>
/// <param name="parent">MDICLIENT���ھ��</param>
/// <param name="lpszClassName">��������</param>
/// <param name="lpszWindowName">���ڱ���</param>
/// <param name="hInstance">ģ����</param>
/// <param name="rect">���ھ���(������ֵ�ǿ�Ⱥ͸߶�)</param>
/// <returns>�´��ھ��</returns>
extern inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, const RECT& rect, HINSTANCE hInstance);
/// <summary>
/// ����MDI�Ӵ���(���Ӳ���)
/// </summary>
/// <param name="parent">MDICLIENT���ھ��</param>
/// <param name="lpszClassName">��������</param>
/// <param name="lpszWindowName">���ڱ���</param>
/// <param name="hInstance">ģ����</param>
/// <param name="rect">���ھ���(������ֵ�ǿ�Ⱥ͸㶨)</param>
/// <param name="lParam">���Ӳ���</param>
/// <returns>�´��ھ��</returns>
extern inline HWND CreateMdiChildWindow(HWND mdiClient, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, const RECT& rect, HINSTANCE hInstance, LPARAM lParam);
/// <summary>
/// ����MDI�����Ӵ���
/// </summary>
/// <param name="mdiClient">MDICLIENT���ھ��</param>
/// <param name="hInstance">ģ����</param>
/// <param name="pd2d">d2d�豸ָ��</param>
/// <param name="PaintWinProc">�����Ӵ��ڴ��ڹ���</param>
/// <returns>�´��ھ��</returns>
extern HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance,WNDPROC PaintWinProc);
/// <summary>
/// ����MDI�����Ӵ���(�޴��ڹ���)
/// </summary>
/// <param name="mdiClient">MDICLIENT���ھ��</param>
/// <param name="hInstance">ģ����</param>
/// <param name="pd2d">d2d�豸ָ��</param>
/// <returns>�´��ھ��</returns>
extern inline HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance);
/// <summary>
/// ɾ��������ʽ
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <param name="style">��ʽ</param>
/// <returns>�Ƿ�ɹ�</returns>
bool DeleteWindowStyle(HWND hwnd, UINT style);
/// <summary>
/// ��Ӵ�����ʽ
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <param name="style">��ʽ</param>
/// <returns>�Ƿ�ɹ�</returns>
bool AddWindowStyle(HWND hwnd, UINT style);
/// <summary>
/// ���ô�����ʽ
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <param name="style">��ʽ</param>
/// <returns>�Ƿ�ɹ�</returns>
bool SetWindowStyle(HWND hwnd, UINT style);
/// <summary>
/// ɾ��������ʽ(EX)
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <param name="style">��ʽ</param>
/// <returns>�Ƿ�ɹ�</returns>
bool DeleteWindowStyleEx(HWND hwnd, UINT style);
/// <summary>
/// ��Ӵ�����ʽ(EX)
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <param name="style">��ʽ</param>
/// <returns>�Ƿ�ɹ�</returns>
bool AddWindowStyleEx(HWND hwnd, UINT style);
/// <summary>
/// ���ô�����ʽ(EX)
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <param name="style">��ʽ</param>
/// <returns>�Ƿ�ɹ�</returns>
bool SetWindowStyleEx(HWND hwnd, UINT style);
/// <summary>
/// ɾ�������Ӵ���(���EnumChildWindowsʹ��)
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <param name="lParam">����</param>
/// <returns>����</returns>
extern BOOL CALLBACK CloseEnumProc(HWND hwnd, LPARAM lParam);
/// <summary>
/// �ͷŴ��ڶ��ڴ�
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <returns>�Ƿ�ɹ�</returns>
extern inline bool FreeWinodwHeap(HWND hwnd);
/// <summary>
/// ��Ϣѭ��
/// </summary>
/// <returns>���򷵻�ֵ</returns>
extern int MessageLoop();
/// <summary>
/// �����ڴ�
/// </summary>
/// <param name="hProcess">���̾��</param>
/// <param name="nBaseAddr">ģ���ַ</param>
/// <param name="nBaseSize">ģ���С</param>
/// <param name="lpValue">Ҫ������ֵ</param>
/// <param name="nValueSize">ֵ��ռ�ڴ��С</param>
/// <param name="numberOfAddr">(����)�����</param>
/// <returns>�����ַ����</returns>
extern LPDWORD SearchMemory(HANDLE hProcess, DWORD nBaseAddr, DWORD nBaseSize, BYTE* lpValue, DWORD nValueSize, LPDWORD numberOfAddr);
/// <summary>
/// ȡģ����Ϣ
/// </summary>
/// <param name="nPid">����ID</param>
/// <param name="szModuleName">ģ����</param>
/// <param name="lpBaseAddr">(����)ģ���ַ</param>
/// <param name="lpBaseSize">(����)ģ���С</param>
/// <returns>�Ƿ�ɹ�</returns>
extern bool GetProcessModuleInfo(DWORD nPid, LPCTSTR szModuleName, LPDWORD lpBaseAddr, LPDWORD lpBaseSize);
/// <summary>
/// ���洰��(��ͨ)
/// </summary>
/// <param name="own">�����ھ��</param>
/// <param name="target">Ŀ�괰�ھ��</param>
/// <param name="rc">[IN][OUT]���ھ���</param>
/// <returns>���ڴ�С�Ƿ�ı�</returns>
extern bool FollowTargetWindow(HWND own, HWND target,RECT* rc);
/// <summary>
/// ���洰��(MDI)
/// </summary>
/// <param name="parent">�����ھ��</param>
/// <param name="paint">�����Ӵ��ھ��</param>
/// <param name="target">Ŀ�괰�ھ��</param>
/// <param name="rc">[IN][OUT]�´��ھ���</param>
/// <returns>���ڴ�С�Ƿ�ı�</returns>
extern bool FollowTargetWindow(HWND parent, HWND paint, HWND target,RECT* rc);
/// <summary>
/// �����(PAINT)
/// </summary>
/// <param name="hWnd">���ھ��</param>
extern void ActivateWindow(HWND hWnd);
/// <summary>
/// ��ʼ������֪ͨͼ��
/// </summary>
/// <param name="hWnd">���ھ��</param>
/// <param name="hIcon">ͼ��</param>
/// <param name="tip">�����ͼ������ͣʱ��ʾ������(ϵͳ�趨���128)</param>
/// <param name="id">ͼ��id</param>
/// <param name="pnid">����֪ͨͼ��ṹָ��</param>
extern void InitNotifyIcon(HWND hWnd, HICON hIcon, LPCTSTR tip,DWORD id, PNOTIFYICONDATA pnid);
/// <summary>
/// ��������֪ͨͼ��
/// </summary>
/// <param name="pnid">����֪ͨͼ��ṹָ��</param>
/// <returns>�Ƿ�ɹ�</returns>
extern inline bool CreateNotifyIcon(PNOTIFYICONDATA pnid);
/// <summary>
/// ɾ������֪ͨͼ��
/// </summary>
/// <param name="pnid">����֪ͨͼ��ṹָ��</param>
/// <returns>�Ƿ�ɹ�</returns>
extern inline bool DeleteNotifyIcon(PNOTIFYICONDATA pnid);
/// <summary>
/// �����˵�
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <param name="hMenu">�˵����</param>
/// <returns>�Ƿ�ɹ�</returns>
extern inline int PopupMenu(HWND hwnd, HMENU hMenu);
/// <summary>
/// �ж���Ϣ�Ƿ�Ϊ�������ؽ�
/// </summary>
/// <param name="msg">��Ϣ</param>
extern inline bool CheckTaskBarRecreated(UINT msg);
/// <summary>
/// ָ�������Ƿ񱻵��
/// </summary>
/// <param name="vKey">������</param>
/// <returns>�Ƿ񱻵��</returns>
extern bool IsKeyClicked(DWORD vKey);
/// <summary>
/// ָ�������Ƿ���
/// </summary>
/// <param name="vKey">������</param>
/// <returns>�Ƿ���</returns>
extern inline bool IsKeyDown(DWORD vKey);
/// <summary>
/// ����λͼ��ˢ
/// </summary>
/// <param name="resId">λͼ����Դ��ʶ</param>
/// <param name="hInstance">ģ����</param>
/// <returns>��ˢ���</returns>
extern HBRUSH CreateBitMapBrush(DWORD resId, HINSTANCE hInstance);
/// <summary>
/// ���ش���
/// </summary>
/// <param name="hWnd">���ھ��</param>
/// <returns>�Ƿ�ɹ�</returns>
extern bool SwitchWindow(HWND hWnd);
/// <summary>
/// �����߳���������
/// </summary>
/// <param name="lpThreadFunc">�̺߳���</param>
/// <param name="args">����</param>
/// <returns>�Ƿ�ɹ�</returns>
extern bool StartThread(LPTHREAD_START_ROUTINE lpThreadFunc, LPVOID args);


//EasyD2D��
class EasyD2D {
private:
	ID2D1Factory* pD2DFactory;					//d2d����
	ID2D1HwndRenderTarget* pRenderTarget;		//��ȾĿ��
	ID2D1SolidColorBrush* pBrush;				//��ˢ
	IDWriteFactory* pDWriteFactory;				//�ı�����
	IDWriteTextFormat* pBigWriteTextFormat;		//�ı� ������
	IDWriteTextFormat* pSmallWriteTextFormat;	//�ı� С����
public:
	EasyD2D();
	~EasyD2D();
	/// <summary>
	/// ��ʼ��D2D
	/// </summary>
	/// <param name="hWnd">���ƴ��ھ��</param>
	/// <returns>�Ƿ�ɹ�</returns>
	bool Init(HWND hWnd);
	/// <summary>
	/// ��ʼ����
	/// </summary>
	void BeginDraw();
	/// <summary>
	/// ��������
	/// </summary>
	void EndDraw();
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="color">������ɫֵ</param>
	void Clear(D2D1::ColorF color);
	/// <summary>
	/// ���û�����ɫ
	/// </summary>
	/// <param name="color">��ɫֵ</param>
	void SetColor(D2D1::ColorF color);
	/// <summary>
	/// �����ı�ˮƽ����
	/// </summary>
	void SetAlignmentLevelCenter();
	/// <summary>
	/// �����ı������
	/// </summary>
	void SetAlignmentLevelLeft();
	/// <summary>
	/// �����ı��Ҷ���
	/// </summary>
	void SetAlignmentLevelRight();
	/// <summary>
	/// �����ı���ֱ����
	/// </summary>
	void SetAlignmentVerticalCenter();
	/// <summary>
	/// �����ı�����
	/// </summary>
	void SetAlignmentVerticalTop();
	/// <summary>
	/// �����ı�����
	/// </summary>
	void SetAlignmentVerticalBottom();
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="rect">���νṹ</param>
	void DrawRect(const D2D1_RECT_F& rect);
	/// <summary>
	/// ������(ָ���߿�)
	/// </summary>
	/// <param name="rect">���νṹ</param>
	/// <param name="lWeight">�߿�</param>
	void DrawRect(const D2D1_RECT_F& rect, float lWeight);
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="rect">���νṹ</param>
	void FillRect(const D2D1_RECT_F& rect);
	/// <summary>
	/// ��Բ
	/// </summary>
	/// <param name="ellipse">Բ�νṹ</param>
	void DrawCircle(const D2D1_ELLIPSE& ellipse);
	/// <summary>
	/// ��Բ(ָ���߿�)
	/// </summary>
	/// <param name="ellipse">Բ�νṹ</param>
	/// <param name="lWeight">�߿�</param>
	void DrawCircle(const D2D1_ELLIPSE& ellipse, float lWeight);
	/// <summary>
	/// ���Բ
	/// </summary>
	/// <param name="ellipse">Բ�νṹ</param>
	void FillCircle(const D2D1_ELLIPSE& ellipse);
	/// <summary>
	/// ����
	/// </summary>
	/// <param name="p1">��һ��������</param>
	/// <param name="p2">�ڶ���������</param>
	void DrawLine(D2D1_POINT_2F p1, D2D1_POINT_2F p2);
	/// <summary>
	/// ����(ָ���߿�)
	/// </summary>
	/// <param name="p1">��һ��������</param>
	/// <param name="p2">�ڶ���������</param>
	/// <param name="lWeight">�߿�</param>
	void DrawLine(D2D1_POINT_2F p1, D2D1_POINT_2F p2, float lWeight);
	/// <summary>
	/// ���ַ�
	/// </summary>
	/// <param name="str">�ַ�ָ��</param>
	/// <param name="rect">�ַ�����(���νṹ)</param>
	/// <param name="isBigFont">�Ƿ�ʹ�ô�����</param>
	void DrawStr(LPCTSTR str, const D2D1_RECT_F& rect, bool isBigFont);
};

class ConfigFile {
private:
	LPCTSTR szPath;
public:
	/// <summary>
	/// ���캯��
	/// </summary>
	/// <param name="szFilePath">�����ļ�Ŀ¼</param>
	ConfigFile(LPCTSTR szFilePath);
	/// <summary>
	/// ���ַ���ֵ
	/// </summary>
	/// <param name="szAppName">�ֶ���</param>
	/// <param name="szKeyName">����</param>
	/// <param name="szValue">[OUT]���ڻ���ֵ��ָ��</param>
	/// <param name="size">����Ĵ�С</param>
	/// <returns>�Ƿ�ɹ�</returns>
	bool ReadString(LPCTSTR szAppName,LPCTSTR szKeyName,LPTSTR szValue,DWORD size);
	/// <summary>
	/// д�ַ���ֵ
	/// </summary>
	/// <param name="szAppName">�ֶ���</param>
	/// <param name="szKeyName">����</param>
	/// <param name="szValue">[IN]Ҫд�ļ�ֵ</param>
	/// <returns>�Ƿ�ɹ�</returns>
	bool WriteString(LPCTSTR szAppName, LPCTSTR szKeyName, LPTSTR szValue);
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="szAppName">�ֶ���</param>
	/// <param name="szKeyName">����</param>
	/// <returns>��ֵ(Ĭ�Ϸ���0)</returns>
	UINT ReadInt(LPCTSTR szAppName, LPCTSTR szKeyName);
	/// <summary>
	/// д����
	/// </summary>
	/// <param name="szAppName">�ֶ���</param>
	/// <param name="szKeyName">����</param>
	/// <param name="dwValue">��ֵ</param>
	/// <returns>�Ƿ�ɹ�</returns>
	bool WriteInt(LPCTSTR szAppName, LPCTSTR szKeyName, UINT dwValue);
	/// <summary>
	/// ���ṹ
	/// </summary>
	/// <param name="szAppName">�ֶ���</param>
	/// <param name="szKeyName">����</param>
	/// <param name="lpStruct">[OUT]�ṹ��ָ��</param>
	/// <param name="size">�ṹ���С</param>
	/// <returns>�Ƿ�ɹ�</returns>
	bool ReadStruct(LPCTSTR szAppName, LPCTSTR szKeyName, LPVOID lpStruct, DWORD size);
	/// <summary>
	/// д�ṹ
	/// </summary>
	/// <param name="szAppName">�ֶ���</param>
	/// <param name="szKeyName">����</param>
	/// <param name="lpStruct">[IN]�ṹ��ָ��</param>
	/// <param name="size">�ṹ���С</param>
	/// <returns>�Ƿ�ɹ�</returns>
	bool WriteStruct(LPCTSTR szAppName, LPCTSTR szKeyName, LPVOID lpStruct, DWORD size);
};