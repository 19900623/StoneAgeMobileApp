#ifndef _TALKWINDOW_H_
#define _TALKWINDOW_H_
////#include <windows.h>
#include "../systeminc/chat.h"

#define WM_UPDATE_SKIN 0x8000
#define MAX_TALK_WINDOW_LINE 6
#define TALK_WINDOW_SXO	12				// �Ի��Ӵ�������ֵ���ʼx����
#define TALK_WINDOW_SYO 10				// �Ի��Ӵ�������ֵ���ʼy����
#define TALK_WINDOW_SXI	30				// �Ի��Ӵ��������ֵ���ʼx����
#define TALK_WINDOW_SYI 128				// �Ի��Ӵ��������ֵ���ʼy����
#define SKIN_WIDTH 645
#define SKIN_HEIGHT 155
#define SKIN_KIND 5
#define TALK_WINDOW_MAX_CHAT_LINE 40 // �������buffer
#ifdef _DEBUG
#define FACE_SYMBOL_NUM 20				// �����������
#define STORE_SYMBOL_NUM 200			// ��¼����λ������
#define LINE_HEIGHT 20						// �������ʱ���о�
#define SYMBOL_WIDTH 19						// �������ͼ��
#define SYMBOL_HEIGHT 19					// �������ͼ��
#endif

extern bool g_bTalkWindow;
extern int g_iCursorCount;

#ifdef _DEBUG
typedef struct _tsFaceSymbol{				// �������
	int hDraw;
	int hDrawMask;
	int hbmpMaskBMP;
	int hLoadBMP;
	int hOldLoadBMP;
	int hOldMaskBMP;
	bool bUse;
	char szSymbol[8];					// ����( :) :( :D ...etc)
	char szFaceName[32];			// ����
}FaceSymbol;

typedef struct _tsStoreSymbol{				// ��¼��������ʾ����
	bool bUse;
	int hDraw;
	int hDrawMask;
	int x;
	int y;
}StoreSymbol;
#endif

typedef struct _tsChatBufferLink{
	CHAT_BUFFER ChatBuffer;
	_tsChatBufferLink *prev;
	_tsChatBufferLink *next;
	bool bUse;
}ChatBufferLink;

//long CALLBACK TalkWindowProc(HWND hWnd,unsigned int Message,WPARAM wParam,LPARAM lParam);

class CTalkWindow
{
private:
	//HWND m_hWnd;											// ���Ӵ��� HWND
	//HWND m_hTalkWindow;								// �Լ��� HWND
	//HINSTANCE m_hInstance;						// ���Ӵ��� HINSTANCE
	//HANDLE m_hSkin[SKIN_KIND];				// SKIN_KIND->0:base 1:up arrow 2:up arrow hit 3:down arrow 4:down arrow hit
	//HANDLE m_hOldSkin[SKIN_KIND];
	//HDC m_hdcSkin[SKIN_KIND];					// SKIN_KIND->0:base 1:up arrow 2:up arrow hit 3:down arrow 4:down arrow hit
	//HDC m_hdcBackBuffer;							// backbuffer dc for draw
	//HBITMAP m_hbmpBackBuffer;					// backbuffer of memory for draw
	//HANDLE m_hbmpOldBackBuffer;
	//bool m_bUpArrowHit;								// �Ͼ�ť�Ƿ���
	//bool m_bDownArrowHit;							// �¾�ť�Ƿ���
	//bool m_bScroll;										// �����Ƿ������ھ���
	//bool m_bInit;											// ��ʼ���ɹ���ʧ��
	//ChatBufferLink *m_pCBLHead;				// ָ��Ի�link��һ��link��ָ��
	//ChatBufferLink *m_pCBLTail;				// ָ��Ի�link���һ��link��ָ��
	//ChatBufferLink *m_pCBLString;			// ָ��Ի�link׼���������ִ���link��ָ��
	//ChatBufferLink *m_pCBLView;				// ָ��Ҫ��ʾ�ڻ����ϵ�һ�е��ִ���linkָ��
	//ChatBufferLink *m_pCBLViewBottom;	// ָ��Ҫ��ʾ�ڻ��������һ�е��ִ���linkָ��
#ifdef _DEBUG
	FaceSymbol m_fsFaceSymbol[FACE_SYMBOL_NUM];			// �������
	StoreSymbol m_ssStoreSymbol[STORE_SYMBOL_NUM];	// ��¼���Ǳ���ʾ����
	int m_iSymbolCount;
#endif
	int m_iline;
public:
	CTalkWindow(void);
	~CTalkWindow(void);

	void Create();
	void Update(void);
	void LoadSkin(char *szSkinPath);
	void DrawSkin(bool bShowCursor);
	void AddString(char *szString,int color);
	//HWND GetTalkWindowWND(void) { return m_hTalkWindow;};
	void UpArrowHit(bool bHit);
	void DownArrowHit(bool bHit);
	void ClearChatBuffer(void);
	//void Init(HWND hWnd,HINSTANCE hInstance);
	void Visible(bool flag);
	void Release(void);
#ifdef _DEBUG
	void ReadFaceSymbolFile(void);
	//void InitFaceSymbol(COLORREF MaskColor);
	void ReleaseFaceSymbol(void);
	void SetToFaceSymbolString(char *szDestString,ChatBufferLink *pCBL,int x,int y);
	void ShowFaceSymbol(void);
#endif
};

extern CTalkWindow TalkWindow;

#endif