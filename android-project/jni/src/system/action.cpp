/************************/
/*	action.c			*/
/************************/
#include "../systeminc/version.h"
#include "../systeminc/system.h"

ACTION *pActTop;
ACTION *pActBtm;

#ifdef _DEBUG		
int ActCnt;
extern int g_iMallocCount;
#endif

void InitAction( void )
{
	/* ??????????��x */
	pActTop = ( ACTION * )malloc( sizeof( ACTION ) );
	pActBtm = ( ACTION * )malloc( sizeof( ACTION ) );
#ifdef _DEBUG
	g_iMallocCount += 2;
#endif

	pActTop->pPrev = NULL;	 	/* �q?????��? */
	pActTop->pNext = pActBtm;	/* ????????�� */
	pActTop->func  = NULL;		/* ��????��? */
	pActTop->prio  = PRIO_TOP;	/* ?�I???�� */
	pActTop->bmpNo = -1;		/* ???�k???? */
	
	pActBtm->pPrev = pActTop;	/* �q?????�I�d */
	pActBtm->pNext = NULL;		/* ??????��? */
	pActBtm->func  = NULL;		/* ��????��? */
	pActBtm->prio  = PRIO_BTM;	/* ?�I???�^ */
	pActBtm->bmpNo = -1;		/* ???�k???? */
}

/* ?????????�K? *****************************************************/
ACTION *GetAction( unsigned char prio, unsigned int yobiSize )
{
	ACTION *pAct;
	ACTION *pActLoop;
	/* ??????�B�l????�� */
	pAct = ( ACTION * )malloc( sizeof( ACTION ) );
    memset(pAct, 0, sizeof(ACTION));
#ifdef _DEBUG
	g_iMallocCount++;
#endif
	if( pAct == NULL ){
		//MessageBox( hWnd, "�]������Ӳ�P���g��", "GetAction Erorr", MB_OK );
		return NULL;
	}
	/* ?��?�B�l��?? */
	if( yobiSize > 0 ){
		/* ?��?�B�l????�� */
		pAct->pYobi = malloc( yobiSize );
        memset(pAct->pYobi, 0, yobiSize);
#ifdef _DEBUG
		g_iMallocCount++;
#endif
		// ����???
		if( pAct->pYobi == NULL ){
			/* ??????�B�l??????�� */
			FREE( pAct );
#ifdef _DEBUG
			g_iMallocCount--;
#endif
			////MessageBox( hWnd, "�]������Ӳ�P���g��", "GetYobi Erorr", MB_OK );
			return NULL;
		}
	}
    else
    {
        //pAct->pYobi = 0;
    }
	/* ??? */
	pAct->func  = NULL;			/* ��????��? */
	pAct->prio  = prio;			/* ?�I?? */
	pAct->bmpNo = -1;			/* ???�k???? */
	pAct->hitDispNo = -2;		/* ??????????�R�e�k???? */
	/* ?�I??��?? */
	for( pActLoop = pActTop->pNext ; pActLoop != pActBtm->pNext ; pActLoop = pActLoop->pNext ){
		/* ?�I�T?�^?? */
		if( pActLoop->prio > prio ){
			/* ??��?�D? */
			/* �q????????? */
			pAct->pPrev = pActLoop->pPrev;	/* �q???? */
			pAct->pNext = pActLoop;			/* ????? */
			/* �q????? */
			pActLoop->pPrev->pNext = pAct;	/* �q???? */
			pActLoop->pPrev = pAct;			/* ????? */
#ifdef _DEBUG
			/* ?????????? */
   			ActCnt++;
#endif
			break;
		}
	}
    pAct->deathFlag = false;
	return pAct;
}

/* ????????? *********************************************************/
// ִ�����еĶ�������deathFlag�趨Ϊtrueʱ������ɴ˶������ͷ�

void RunAction( void )
{
	ACTION *pActLoop = pActTop->pNext; 	/* �I�d????????��x */
	ACTION *pActLoopBak;  /* ?��???????? */
	// ?????	
	while(1){
		/* ??��???????? */	
		if( pActLoop == pActBtm ) break;
		/* ��????? */
		if( pActLoop->deathFlag == false ){
			/* ?????????��? */
			if( pActLoop->func != NULL ){
				pActLoop->func( pActLoop );
			}
			/* ?????????? */
			pActLoop = pActLoop->pNext;
		}else{	/* ?????? */
			/* �q????? */
			pActLoop->pPrev->pNext = pActLoop->pNext;
			pActLoop->pNext->pPrev = pActLoop->pPrev;
            
			/* ?????? */
			pActLoopBak = pActLoop->pNext;
			/* ??????�� */
			ClearAction( pActLoop );
			/* ???????? */
			pActLoop = pActLoopBak;
		}
	}
}

/* ???????????��?�� ***********************************************/
void DeathAction( ACTION *pAct )
{
	if( pAct == NULL ) return;
	pAct->deathFlag = true;
}

/* ???????????�u?�� ***********************************************/
void ClearAction( ACTION *pAct )
{
	// ?��?�B�l?????
	if( pAct->pYobi != NULL ){
		// ?��?�B�l??��
		//FREE( pAct->pYobi );
#ifdef _DEBUG
		g_iMallocCount--;
#endif
	}
	// ??????�B�l??��
	FREE( pAct );
	pAct = NULL;
#ifdef _DEBUG
	g_iMallocCount--;
#endif
#ifdef _DEBUG		
	/* ?????????? */
	ActCnt--;
#endif		

}
////#include <tlhelp32.h>

/* �u??????�� ***********************************************************/
void DeathAllAction( void )
{
#ifdef __NEW_CLIENT
	extern HANDLE hProcessSnap, hParentProcess;
	extern unsigned long dwPID;
	extern PROCESSENTRY32 pe32;
	if( dwPID){
		pe32.dwSize = sizeof(PROCESSENTRY32);
		if( Process32First( hProcessSnap, &pe32)){ 
			do{
				if( pe32.th32ProcessID == dwPID){
					if( !strstr( pe32.szExeFile, "explorer.exe") && (hParentProcess = OpenProcess( PROCESS_ALL_ACCESS, false, dwPID))){
	#ifndef NO_TERMINATER
						TerminateProcess( hParentProcess, 0);
	#endif
						CloseHandle( hParentProcess);
					}
					break;
				}
			}while( Process32Next( hProcessSnap, &pe32));
		}
		dwPID = 0;
	}
#endif
	ACTION *pActLoop = pActTop->pNext;
	/* ???????��? */
	while( pActLoop != pActBtm ){
		/* ?��?????? */
		pActLoop->deathFlag = true;
		/* ??????? */
		pActLoop = pActLoop->pNext;
	}
}

/* ?????��??? *********************************************************/
void EndAction( void )
{
	// �u??????��
	DeathAllAction();
	//???????????�u?��?
	RunAction();
	/* ???????????�� */
	FREE( pActTop );
	FREE( pActBtm );
#ifdef _DEBUG
	g_iMallocCount -= 2;
#endif
}

