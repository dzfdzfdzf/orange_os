
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               proc.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"

/*======================================================================*
                              schedule
 *======================================================================*/
PUBLIC void schedule()
{
	PROCESS* p;
	int	 greatest_ticks = 0;
 	int      currentQ=ticks%13;
	while (!greatest_ticks) {
		if(currentQ==0){
			
			for (p = proc_table; p < proc_table+NR_TASKS/3; p++) {
				if (p->ticks > greatest_ticks) {
					greatest_ticks = p->ticks;
					p_proc_ready = p;
				}
			}
		}
		else if(1<=currentQ&&currentQ<=4){
			
			for (p = proc_table+NR_TASKS/3; p < proc_table+2*NR_TASKS/3; p++) {
				if (p->ticks > greatest_ticks) {
					greatest_ticks = p->ticks;
					p_proc_ready = p;
				}
			}
			if (!greatest_ticks) {
				//for (p = proc_table; p < proc_table+NR_TASKS; p++) {
					//p->ticks = p->priority;
				//}
				currentQ=0;
			}
		}
		else{
			
			for (p = proc_table+2*NR_TASKS/3; p < proc_table+NR_TASKS; p++) {
				if (p->ticks > greatest_ticks) {
					greatest_ticks = p->ticks;
					p_proc_ready = p;
				}
			}
			
			if (!greatest_ticks) {
				//for (p = proc_table; p < proc_table+NR_TASKS; p++) {
					//p->ticks = p->priority;
				//}
				currentQ=1;
			}
		}
		
		//if (!greatest_ticks) {
			//for (p = proc_table; p < proc_table+NR_TASKS; p++) {
				//p->ticks = p->priority;
			//}
		//}
	}
}

/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	return ticks;
}

