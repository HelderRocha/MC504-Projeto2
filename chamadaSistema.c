#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/delay.h>
#include<linux/module.h>/*Needed by all modules */
#include<linux/kernel.h>/*Needed for KERN_ALERT */
#include<linux/init.h>/*Needed for the macros */
#include<asm/signal.h>
#include<linux/signal.h>

extern asmlinkage long sys_kill (int pid, int sig);

asmlinkage long sys_mycall(int processNumber, int waitTime) {

	long resultado=0;
	int flag=0, i=0;

	/*implementar depois*/

	if(sys_kill(processNumber, 0)!=0)
	{
		/*processo nao existe*/
		resultado=0;
	}
	else
	{
		sys_kill(processNumber, SIGTERM);
		for(i=0; i<waitTime; i+=10)
		{
			msleep(10);
			if(sys_kill(processNumber, 0)!=0)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			/*sigterm nao matou a tempo, entao sigkill mata*/
			sys_kill(processNumber, SIGKILL);
			resultado=1;
		}
		else
		{
			/*sigterm funcionou*/
			resultado=2;
		}
	}	

	return resultado;
}
