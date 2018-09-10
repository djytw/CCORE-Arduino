#pragma once

#define WDT_WCR	     *(volatile UINT16 *)(WDT_BASE+0x00)
#define WDT_WMR	     *(volatile UINT16 *)(WDT_BASE+0x02)
#define WDT_WCNTR	 *(volatile UINT16 *)(WDT_BASE+0x04)
#define WDT_WSR	     *(volatile UINT16 *)(WDT_BASE+0x06)

#define WDT_EN    0x01
#define WDT_DBG   0x02
#define WDT_DOZE  0x04
#define WDT_WAIT  0x08

