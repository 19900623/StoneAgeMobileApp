/************************/
/*	process.h			*/
/************************/
#ifndef _PROCESS_H_
#define _PROCESS_H_

/* ?????��? */
enum{
	PROC_INIT,
	PROC_ID_PASSWORD,				// ????????�V???
	PROC_TITLE_MENU,				// ?????��????����
	PROC_CHAR_SELECT,				// ???�k��
	PROC_CHAR_MAKE,					// ????��
	PROC_CHAR_LOGIN_START,			// ????????��
	PROC_CHAR_LOGIN,				// ????????
	PROC_CHAR_LOGOUT,				// ????????
	PROC_OPENNING,
	PROC_GAME,						// ???????
	PROC_BATTLE,					// ???????
	PROC_DISCONNECT_SERVER,			// ???????���e???????
#ifdef _DEBUG		
	PROC_TAKE_TEST,					// �{��???
	PROC_OHTA_TEST,					// �^��???
	PROC_DWAF_TEST,					// ���Z???
	PROC_SPR_VIEW,					// ??????�_????
	PROC_ANIM_VIEW,					// ????????�_????
	PROC_SE_TEST,					// ???�_????
#endif
#ifdef _80_LOGIN_PLAY
	PROC_80_LOGIN,
#endif
#ifdef _PK2007
	PROC_PKSERVER_SELECT,
#endif
	PROC_ENDING
};

/* ????�k? */
extern unsigned int ProcNo;
/* ??????�k? */
extern unsigned int SubProcNo;
/* ????�k? */
extern int ProcNo2;
/* ??????�k? */
extern int SubProcNo2;

extern int palNo;
extern int oldPalNo;
extern int palTime; //the third


/* ?????? */
void Process( void );
/* ????��??? */
void ChangeProc( int procNo );
/* ????��??? */
void ChangeProc( int procNo, int subProcNo );
/* ????��??? */
void ChangeProc2( int procNo );
/* ????��??? */
void ChangeProc2( int procNo, int subProcNo );

/* ????????? */
void GameProc( void );

// ????��?
void warpEffectProc( void );
// ????����?
void repairMap( void );

void paletteProc( void );

#ifdef _DEBUG		

/* �{��????????? */
void TakeTestProc( void );

/* �^��??????? */
void OhtaTestProc( void );

#endif

#ifdef _SURFACE_ANIM
void AniProc(void);
#endif


#endif
