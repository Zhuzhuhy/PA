#include "cpu/exec/template-start.h"
#define instr push

static void do_execute (){
	if(DATA_BYTE == 2){
		cpu.esp = cpu.esp-2;
		//实现段寄存器
	}
	else if(DATA_BYTE == 4){
		cpu.esp = cpu.esp-4;
		//实现段寄存器
	}
}

make_instr_helper(i)

#include "cpu/exec/template-end.h"