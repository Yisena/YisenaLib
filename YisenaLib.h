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
/// d2d�豸
/// </summary>
typedef struct d2d{
	ID2D1Factory* pD2DFactory = NULL; //d2d����
	ID2D1HwndRenderTarget* pRenderTarget = NULL;   //��ȾĿ��
	ID2D1SolidColorBrush* pBrush = NULL; //��ˢ
	IDWriteFactory* pDWriteFactory = NULL;//�ı�����
	IDWriteTextFormat* pWriteTextFormat = NULL; //�ı�
	//���ھ���
	RECT rc;
}d2d;
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
/// <param name="hWnd">����·��</param>
/// <param name="lpStrFile">(����)�ļ�·��</param>
/// <returns>�Ƿ�ɹ�</returns>
extern BOOL SelectFileDlg(HWND hWnd, LPTSTR lpStrFile);
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
extern HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance, d2d* pd2d, WNDPROC PaintWinProc);
/// <summary>
/// ����MDI�����Ӵ���(�޴��ڹ���)
/// </summary>
/// <param name="mdiClient">MDICLIENT���ھ��</param>
/// <param name="hInstance">ģ����</param>
/// <param name="pd2d">d2d�豸ָ��</param>
/// <returns>�´��ھ��</returns>
extern inline HWND CreatePaintMdiChildWindow(HWND mdiClient, HINSTANCE hInstance, d2d* pd2d);
/// <summary>
/// ȥ����ϵͳ�˵�
/// </summary>
/// <param name="hwnd">���ھ��</param>
/// <returns>�Ƿ�ɹ�</returns>
extern inline bool SetWindowNoSysMenu(HWND hwnd);
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
/// ��ʼ��d2d
/// </summary>
/// <param name="hWnd">���ھ��</param>
/// <param name="lpD2d">(����)d2d�豸</param>
/// <returns>�Ƿ�ɹ�</returns>
extern bool InitD2D(HWND hWnd, d2d* lpD2d);
/// <summary>
/// �ͷ�d2d�豸
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
extern void ReleaseD2D(d2d* lpD2d);
/// <summary>
/// ���û�����ɫ
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="color">��ɫֵ</param>
extern inline void BrushColor(d2d* lpD2d, D2D1::ColorF color);
/// <summary>
/// �����ı�ˮƽ����
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
extern inline void SetAlignmentLevelCenter(d2d* lpD2d);
/// <summary>
/// �����ı������
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
extern inline void SetAlignmentLevelLeft(d2d* lpD2d);
/// <summary>
/// �����ı��Ҷ���
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
extern inline void SetAlignmentLevelRight(d2d* lpD2d);
/// <summary>
/// �����ı���ֱ����
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
extern inline void SetAlignmentVerticalCenter(d2d* lpD2d);
/// <summary>
/// �����ı���ֱ����
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
extern inline void SetAlignmentVerticalTop(d2d* lpD2d);
/// <summary>
/// �����ı���ֱ����
/// </summary>
/// <param name="lpD2d">d2d�豸�ṹָ��</param>
extern inline void SetAlignmentVerticalBottom(d2d* lpD2d);
/// <summary>
/// ����ͨ����(ָ���߿�)
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="rect">���νṹ</param>
/// <param name="sweight">���</param>
extern inline void DrawRect(d2d* lpD2d,const D2D1_RECT_F &rect, float sweight);
/// <summary>
/// ����ͨ����(��ָ���߿�)
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="rect">���νṹ</param>
extern inline void DrawRect(d2d* lpD2d, const D2D1_RECT_F &rect);
/// <summary>
/// ����ͨ����(���)
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="rect">���νṹ</param>
extern inline void FillRect(d2d* lpD2d, const D2D1_RECT_F &rect);
/// <summary>
/// ��Բ(ָ���߿�)
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="ellipse">Բ�ṹ</param>
/// <param name="sweight">�߿�</param>
extern inline void DrawCircle(d2d* lpD2d, const D2D1_ELLIPSE &ellipse, float sweight);
/// <summary>
/// ��Բ(��ָ���߿�)
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="ellipse">Բ�ṹ</param>
extern void DrawCircle(d2d* lpD2d, const D2D1_ELLIPSE& ellipse);
/// <summary>
/// ��Բ(���)
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="ellipse">Բ�ṹ</param>
extern void FillCircle(d2d* lpD2d, const D2D1_ELLIPSE& ellipse);
/// <summary>
/// ����(ָ���߿�)
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="p1">��1</param>
/// <param name="p2">��2</param>
/// <param name="sweight">�߿�</param>
extern inline void DrawLine(d2d* lpD2d, D2D1_POINT_2F p1, D2D1_POINT_2F p2, float sweight);
/// <summary>
/// ����(��ָ���߿�)
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="p1">��1</param>
/// <param name="p2">��2</param>
extern inline void DrawLine(d2d* lpD2d, D2D1_POINT_2F p1, D2D1_POINT_2F p2);
/// <summary>
/// ����ַ���
/// </summary>
/// <param name="lpD2d">d2d�豸ָ��</param>
/// <param name="str">�ַ���</param>
/// <param name="rect">���νṹ</param>
extern inline void DrawStr(d2d* lpD2d, LPCTSTR str, const D2D1_RECT_F &rect);
/// <summary>
/// ���洰��(��ͨ)
/// </summary>
/// <param name="own">�����ھ��</param>
/// <param name="target">Ŀ�괰�ھ��</param>
/// <param name="lpD2d">d2d�豸ָ��</param>
extern void FollowTargetWindow(HWND own, HWND target, d2d* lpD2d);
/// <summary>
/// ���洰��(MDI)
/// </summary>
/// <param name="parent">�����ھ��</param>
/// <param name="paint">�����Ӵ��ھ��</param>
/// <param name="target">Ŀ�괰�ھ��</param>
/// <param name="lpD2d">d2d�豸ָ��</param>
extern void FollowTargetWindow(HWND parent, HWND paint, HWND target, d2d* lpD2d);
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
extern bool isKeyClicked(int vKey);
/// <summary>
/// ����λͼ��ˢ
/// </summary>
/// <param name="resId">λͼ����Դ��ʶ</param>
/// <param name="hInstance">ģ����</param>
/// <returns>��ˢ���</returns>
extern HBRUSH CreateBitMapBrush(DWORD resId, HINSTANCE hInstance);