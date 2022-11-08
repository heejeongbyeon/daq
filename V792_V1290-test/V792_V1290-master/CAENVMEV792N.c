/*!
	-----------------------------------------------------------------------------

	-----------------------------------------------------------------------------

	CAENVMEV792N.c

	-----------------------------------------------------------------------------

Created: April 2022
Byungmin Kang, HANUL, korea Univerisity
Functions for V792N
-----------------------------------------------------------------------------
*/
#include "CAENVMEV1718.h"
#include "CAENVMEV792N.h"
#include <stdio.h>
#include <iostream>
#include <bitset>

/*addr는 qdc나 tdc의 고유한 addr ex. CC11, EE00*/
/* regaddr는 할당할 부분 (bit clear나 set같은거) */

void CAENVMEV792N::Write16(uint32_t regaddr, uint16_t data){
	CvWrite16(handle,  addr+regaddr, data);
}
void CAENVMEV792N::Write32(uint32_t regaddr, uint32_t data){
	CvWrite32(handle, addr+regaddr, data);
}
uint16_t CAENVMEV792N::Read16(uint32_t regaddr){
	CvRead16(handle,  addr+regaddr);
}
uint32_t CAENVMEV792N::Read32(uint32_t regaddr){
	CvRead32(handle,  addr+regaddr);
}
	
void CAENVMEV792N::SetPedestal(uint16_t ped){
	Write16(cv792Iped,ped);
}
void CAENVMEV792N::EventReset(){
	Write16(cv792EvtCntRst, 0x1004);
}

uint16_t CAENVMEV792N::GetStatRegister(){
	return Read16(cv792StatReg1); 
}


