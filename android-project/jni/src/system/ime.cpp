/************************/
/*	ime.cpp				*/
/************************/
#include "../systeminc/version.h"
#include "../systeminc/system.h"
//#include "winnls32.h"
#include "../systeminc/font.h"
//#include "../caryIme.h"
#include "../systeminc/menu.h"
#include "../systeminc/battleMenu.h"
#ifdef _TALK_WINDOW
#include "../systeminc/talkwindow.h"
#endif

unsigned long dwInfo;
//void //ShowBottomLineString(int iColor,char* lpstr)
//{
	/*LPSTR lpstr1=GetImeString();
	dwInfo = 0;
	if(!lpstr1 && lpstr[0]!=0){
		dwInfo = 1;
		StockFontBuffer( 8, 460 + DISPLACEMENT_Y, FONT_PRIO_FRONT, iColor, lpstr, 0 );
	}*/
//}

// Terry add 2003/12/16 for �����Ӵ�����ʱ,��ʾ��Ʒ˵������ʾ���뷨
extern bool bShowItemExplain;
// end
//	���뷨�Ĵ���
void ImeProc()
{
	// ��ʾ���뷨������
// Terry fix 2003/12/16 for �����Ӵ�����ʱ,��ʾ��Ʒ˵������ʾ���뷨
	//if( TaskBarFlag == false ){ ���иĳ���һ��
//	if(TaskBarFlag == false && bShowItemExplain == false){
//// end
//		LPSTR lpstr=GetImeString();
//		char* lpstr1;
//		if(lpstr){
//#ifdef _TELLCHANNEL
//			StockFontBuffer(8,420 + DISPLACEMENT_Y ,FONT_PRIO_FRONT,FONT_PAL_WHITE,lpstr,0);
//#else
//			StockFontBuffer(8,460 + DISPLACEMENT_Y ,FONT_PRIO_FRONT,FONT_PAL_WHITE,lpstr,0);
//#endif
//#ifdef _TALK_WINDOW
//		if(g_bTalkWindow) TalkWindow.Update();
//#endif
//		}
//		lpstr1=GetImeDescString();
//		if( 1!=dwInfo){
//			if( lpstr1)
//				StockFontBuffer(530-strlen(lpstr1)*(FONT_SIZE>>1) + DISPLACEMENT_X,460 + DISPLACEMENT_Y ,FONT_PRIO_FRONT,0,lpstr1,0);
////			StockFontBuffer(590-strlen(lpstr)*(FONT_SIZE>>1),460,FONT_PRIO_FRONT,0,lpstr,0);
//			//cary ���ping��ʱ��
//			char tmp[64];
//			extern unsigned long dwPingTime, dwPingState;
//			if( dwPingState & 0x80000000){
//				sprintf( tmp, "*%d", dwPingTime);
//				dwPingState++;
//				if( (dwPingState&0xff) > 40)
//					dwPingState = 0;
//			}else
//				sprintf( tmp, " %d", dwPingTime);
//			StockFontBuffer( 605 + DISPLACEMENT_X, 460 + DISPLACEMENT_Y , FONT_PRIO_FRONT, FONT_PAL_WHITE, tmp, 0 );
//#ifndef _REMAKE_20
//			lpstr = "���ģʽ";
//			switch( AI){
//			case AI_ATTACK:
//				lpstr = "ǿ�ƹ���";
//				break;
//			case AI_GUARD:
//				lpstr = "ǿ�Ʒ���";
//				break;
//			case AI_SELECT:
//				lpstr = "����ģʽ";
//				break;
//			}
//			StockFontBuffer( 540 + DISPLACEMENT_X, 460 + DISPLACEMENT_Y , FONT_PRIO_FRONT, FONT_PAL_WHITE, lpstr, 0 );
//#endif
//#ifdef _CHANNEL_MODIFY
//			int FontColor = 0 ;
//			switch(TalkMode){
//			case 0:
//				lpstr1 = "һ��Ƶ��";
//				break;
//			case 1:
//				FontColor = FONT_PAL_GREEN;
//				lpstr1 = "����Ƶ��";
//				break;
//			case 2:
//				FontColor = FONT_PAL_AQUA;
//				lpstr1 = "����Ƶ��";
//				break;
//			case 3:
//				FontColor = FONT_PAL_PURPLE;
//				lpstr1 = "����Ƶ��";
//				break;
//			case 4:
//				FontColor = FONT_PAL_BLUE2;
//				lpstr1 = "ְҵƵ��";
//				break;
//			case 5:
//				FontColor = FONT_PAL_PURPLE;
//				lpstr1 = "������Ƶ��";
//				break;
//			}
//			StockFontBuffer( 10, 460 + DISPLACEMENT_Y, FONT_PRIO_FRONT, FontColor, lpstr1, 0 );
//#else
//	#ifdef _TELLCHANNEL 
//			int FontColor = 0 ;
//			switch(TalkMode){
//			case 0:
//				lpstr1 = "һ��ģʽ";
//				break;
//			case 1:
//				FontColor = FONT_PAL_GREEN;
//				lpstr1 = "����ģʽ";
//				break;
//	#ifdef _FRIENDCHANNEL
//			case 2:
//				FontColor = FONT_PAL_PURPLE;
//				lpstr1 = "Ƶ��ģʽ";
//				break;
//	#endif
//			}
//			StockFontBuffer( 10, 460 + DISPLACEMENT_Y, FONT_PRIO_FRONT, FontColor, lpstr1, 0 );
//	#endif
//#endif
//		}
//	}
//// Terry add 2003/12/16 for �����Ӵ�����ʱ,��ʾ��Ʒ˵������ʾ���뷨
//	bShowItemExplain = false;
// end
}

