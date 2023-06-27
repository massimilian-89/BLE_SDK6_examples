 /**
 ***************************************************************************************
 * Copyright (c) 2023 Renesas Electronics Corporation. All rights reserved.
 * 
 * The MIT License (MIT)
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 * OR OTHER DEALINGS IN THE SOFTWARE.
 *
 ***************************************************************************************
 */
#ifndef _SEGGER_SWD_PRINTF_H_
#define _SEGGER_SWD_PRINTF_H_

#if defined (CFG_SWD_PRINTF)

#include "da1458x_scatter_config.h"
#include "co_math.h"

	#define SWD_PRINTF_BUFFER_SIZE 				(64u)

	/*
	*The SEGGER Control Block is placed in the beginning of retention RAM to avoid having to lookup up the address after each build
	* If CFG_RET_DATA_SIZE is modified or the scatter file is modified, the address will change.
	* DA14531 Default address on SDK 6.0.14 - 0x07fc8708
	* DA14585/86 Default address on SDK 6.0.14 - 0x07fd434c
	*/
	#define SEGGER_RTT_SECTION						CO_ALIGN4_HI(__SCT_BLE_BASE - (CFG_RET_DATA_UNINIT_SIZE + CFG_RET_DATA_SIZE + RET_HEAP_SIZE))
	#include "SEGGER_RTT.h"
								 
	#define SWD_printf(fmt, args...) { SEGGER_RTT_printf(0, fmt, args); }							        
            
#else
    #define SWD_printf(fmt, args...) {}
#endif 
			

#endif //_SEGGER_SWD_PRINTF_H_
			