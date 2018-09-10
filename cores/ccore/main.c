#include "includes.h"
#include "regmap/cpm_reg.h"
#include "regmap/wdt_reg.h"

void initVariant() { }

u32 sysclk,ipsclk,efmclk;

void init_clock(){

	CPM_OCSR |= (OSC400M_EN);
	while(0 == (CPM_OCSR & OSC400M_STABLE));

	CPM_CSWCFGR |= SYSCLK_SEL;
	
	CPM_CSWUPDR |= CSWUPD;
	delay_tick(100);

	CPM_SCDIVR &= ~(SYS_DIV_BITS);
	CPM_SCDIVR |= 1;
	CPM_CSWUPDR |= DIVUPD;	

	delay_tick(100);	

	sysclk /= SYS_CLK_DIV;

	// Clock init ok, save clocks.
	UINT32 sysclk_raw;

	if (0 != (SYSCLK_SEL & CPM_CSWCFGR))
		sysclk_raw = 400 * 1000 * 1000;
	else if (0 != (LOSC_SEL & CPM_CSWCFGR))
		sysclk_raw = 128 * 1000;
	else
		sysclk_raw = 24 * 1000 * 1000;

	sysclk = ((UINT32)(sysclk_raw / SYS_CLK_DIV));
	ipsclk = ((UINT32)(sysclk / IPS_CLK_DIV));
	efmclk = ((UINT32)(sysclk / EFM_CLK_DIV));

	WDT_WCR &= (~WDT_EN);
}

void init(){
	init_clock();
}
