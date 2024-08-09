#pragma once
#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <fstream>
#include <bitset>
#include <stack>
#include <queue>
/*type of variables*/
#define type_variables std::string
#define type_registers int
#define type_label std::string
/*type of spilting weight*/
#define type_spliting_weight long long

/*type of instructions*/
#define ins_global 0
#define ins_load 1
#define ins_store 2
#define ins_alloca 3
#define ins_getelementptr 4
#define ins_add 5
#define ins_fadd 6
#define ins_sub 7
#define ins_fsub 8
#define ins_mul 9
#define ins_fmul 10
#define ins_sdiv 11
#define ins_fdiv 12
#define ins_srem 13
#define ins_frem 14
#define ins_and 15
#define ins_or 16
#define ins_xor 17
#define ins_fneg 18
#define ins_icmp 19
#define ins_fcmp 20
#define ins_br 21
#define ins_define 22
#define ins_call 23
#define ins_ret 24
#define ins_label 25
#define ins_unreachable 26
#define ins_sitofp 27
#define ins_fptosi 28
#define ins_copy 29
#define ins_sext 30

/*number the registers*/
#define num_registers 32

/*cond_br*/
#define cond_eq 0
#define cond_ne 1
#define cond_ugt 2
#define cond_sgt 3
#define cond_ule 4
#define cond_sle 5
#define cond_uge 6
#define cond_sge 7
#define cond_ult 8
#define cond_slt 9
#define cond_oeq 10
#define cond_ogt 11
#define cond_oge 12
#define cond_olt 13
#define cond_ole 14
#define cond_une 15

/*返回类型*/
#define ret_i32 0
#define ret_float 1
#define ret_void 2

using namespace std;

/*register*/
struct Register_physical//物理寄存器
{
	bool used,modified;//有效位,修改位
	int num;//对应虚拟寄存器编号
	vector<pair<int, int> >occupied;//被占用的区间
	Register_physical()
	{
		occupied.clear();
	}
};

struct Register_virtual//虚拟寄存器
{
	type_label name;//名称
	int num,reg_phisical, is_splited_from;//编号,分配到的物理寄存器编号,从哪个寄存器splited过来
	type_spliting_weight spliting_weight, prod;//prod指在优先队列内的优先级
	int type;//类型
	bool used, is_splited, is_spilled, is_allocated;//有效位,类型,是否已经被spilted过了,是否下放到内存,是否被分配寄存器
	vector < pair<int, int> >live_interval;//活跃区间
	Register_virtual* next;
	Register_virtual()
	{
		live_interval.clear();
		reg_phisical = -1;
		is_splited = false;
		is_spilled = false;
		is_allocated = false;
		next = NULL;
	}
};

/*符号表*/
struct variable_table
{
	int num, dim, num_reg, cnt;//编号,维度,对应的寄存器编号,变量的数量
	int type;//类型(i32,float,i64)
	type_variables name;//变量名
	vector<unsigned int>size, val;//每个维度的大小,每个单位的值
	variable_table* next;
	variable_table()
	{
		dim = 0;
		cnt = 1;
		num_reg = -1;
		next = NULL;
	}
};

/*指令翻译*/
struct instruction
{
	int num;//指令编号
	int op;//指令类型
	int Rd, Rs1, Rs2;//变量编号：目的，源1，源2
	bool fRd, fRs1, fRs2;//变量类型：局部，全局
	int tRd, tRs1, tRs2;//变量类型：i32，i64，浮点型
	bool fimm, fimm1, fimm2;//是否有偏移量
	unsigned int imm, imm1, imm2;//偏移量，用于GEP指令,store指令,运算指令
	/*针对xcmp语句*/
	int cond;
	/*针对br语句*/
	bool branch_flag;//是否为无条件跳转
	int L1, L2;//跳转标号对应编号
	/*针对call,ret语句*/
	int tot_formal,type_ret;//形参数量，返回类型
	type_label name;//被调函数名
	int num_bb;//所在bb编号
	bool all_imm;//GEP指令是否全为立即数
	int size;//GEP指令对应地址大小
	vector<bool>formal_type;//存储形参的类型
	vector<bool>formal_is_imm;//形参是否是立即数
	vector<unsigned int>formal_num;//存储形参的编号,为立即数的话存对应的立即数
	vector<int>gep_size;//GEP指令每个维度的大小
	instruction* next;
	instruction()
	{
		Rd = Rs1 = Rs2 = -1;
		fimm = fimm1 = fimm2 = 0;
		imm = imm1 = imm2 = 0;
		branch_flag = 0;
		tot_formal = 0;
		all_imm = true;
		next = NULL;
	}
};

/*汇编指令*/
struct asm_instruction
{
	int num;//指令编号
	int op;//指令类型
	int Rd, Rs1, Rs2;//变量编号：目的，源1，源2
	int imm;//偏移量
	int label;//跳转标号、函数名对应编号
	asm_instruction* next, * prev;
	asm_instruction()
	{
		Rd = Rs1 = Rs2 = -1;
		imm = 0;
		next = NULL; prev = NULL;
	}
};

/*basic block*/
struct basic_block
{
	int num;//bb编号
	int l, r;//起止指令编号
	bool is_loop;//是否为循环指令
	instruction* ins_head;//起始指令指针
	vector<basic_block*>edge;//连边
	basic_block* next;
	basic_block()
	{
		ins_head = new instruction;
		next = NULL;
		is_loop = false;
	}
};

/*functions*/
struct functions
{
	/*函数编号, 指令数, bb数, 实参数量, 形参数量, 调用的形参数量最大值, 参数数量, 所需的栈空间大小,
	返回值类型,起始指令编号*/
	int num, cnt_ins, cnt_bb, total_actual, total_formal, max_formal, tot_arg, size, type, ins_start;
	type_label name;//函数名称
	vector<int>args;//参数类型
	instruction* ins_head, * ins_tail;//指令头尾指针
	asm_instruction* asm_ins_head, * asm_ins_tail;//汇编指令头尾指针
	basic_block* bb_head, * bb_tail;//bb头尾指针
	variable_table* local_head, * local_tail;//局部变量表
	map<type_variables, int>map_local;//局部变量名到编号的映射
	map<int, int>map_physical_register_local;//物理寄存器编号到变量编号的映射
	map<int, int>imm_local;//变量编号到地址偏移量的映射
	Register_virtual* reg_head, * reg_tail;//虚拟寄存器
	map<type_label, int>map_local_register;//虚拟寄存器名到编号的映射
	map<int, Register_virtual*>map_local_register_position;//虚拟寄存器编号到指针的映射
	/*记录使用了的寄存器,当前函数应该保存的caller_saved和callee_saved寄存器*/
	vector<bool>used_physical_reg, caller_saved_reg, callee_saved_reg;
	functions* next;
	functions()
	{
		cnt_ins = 0, cnt_bb = 0; total_actual = 0; total_formal = 0; max_formal = 0; tot_arg = 0; size = 0;
		ins_head = new instruction;
		ins_tail = ins_head;
		bb_head = new basic_block;
		bb_tail = bb_head;
		local_head = new variable_table;
		local_tail = local_head;
		reg_head = new Register_virtual;
		reg_tail = reg_head;
		asm_ins_head = new asm_instruction;
		asm_ins_tail = asm_ins_head;
		used_physical_reg.resize(num_registers << 1);
		caller_saved_reg.resize(num_registers << 1);
		callee_saved_reg.resize(num_registers << 1);
		next = NULL;
	}
};

/*definitions*/
extern int num_start_func;//主函数编号
extern Register_physical reg[2][num_registers];
extern map<type_label, int>map_global_register;//全局寄存器名到编号的映射
extern map<int, Register_virtual*>map_global_register_position;//全局寄存器编号到指针的映射
extern map<int, Register_virtual*>map_local_register_position;//局部虚拟寄存器编号到指针的映射
extern map<int, std::string>map_physical_reg_name;//物理寄存器编号到名称的映射
extern vector<bool>physical_reg_usable[2];//物理寄存器能否使用
extern vector<int>physical_reg_order[2];//考虑分配物理寄存器的顺序
extern vector<int>physical_reg_saved[2];//special,caller_saved,callee_saved
extern int total_register;

extern variable_table* global, * global_tail;
extern int total_global;//存储变量的数量
extern map<type_variables, int>map_global;//全局变量名到编号的映射
extern map<int, variable_table*>map_variable_position;//变量编号到指针的映射
extern map<int, int>map_register_local;//寄存器编号到变量编号的映射
extern map<int, int>map_register_local_alloca;//alloca语句内寄存器编号到变量编号的映射

extern instruction* start;//属于全局的指令
extern map<std::string, int>ins_num, cond_num;
extern int tot_instructions;//总的指令数
extern int tot_asm_instructions;//总的汇编指令数
extern set<int>ins_definied;//会定义虚拟寄存器的指令(除call)
extern set<int>ins_used;//会使用虚拟寄存器的指令
extern set<int>ins_valuate;//会对Rd赋值的指令
extern set<int>asm_change_Rd;//会改变Rd的指令
extern map<int, instruction*>map_instruction_position;//指令编号到指针的映射
extern map<int, pair<int, int> >map_ins_copy;//记录copy指令的位置
extern map<int, std::string>map_asm;//汇编指令代码到字符映射

extern map<type_label, int>label_num;//label名到编号的映射
extern map<int, int>label_ins;//label到指令的映射
extern vector<basic_block*>label_bb;//label编号对应的bb编号
extern int tot_label;//label数量

extern functions* func_head, * func_tail;
extern map<type_label, int>map_function;
extern map<int, functions*>map_function_position;//根据函数编号查找函数指针
extern int tot_functions;//总的函数数

/*function names*/
unsigned int floatToBinary(float num);
float BinaryToFloat(unsigned int num);
void read(int option, std::string line, functions* num, bool in_func);
functions* new_function(std::string line);
void end_function(functions* now_function);
int check_label(std::string s);
std::string get_label(std::string s);
void new_label(int op, type_label label, functions* num_func);
std::string get_new_line(std::string line);
void get_basic_block(functions* now_func);
void get_live_interval(functions* now_func);
void resize_live_interval(Register_virtual* now_reg);//整理寄存器的活跃区间(集合并)
void check_live_interval(Register_virtual* now_reg);
void register_allocate(functions* now_func);
void get_asm();//得到汇编代码
void peephole(functions* now_func);//窥孔优化
void print_asm(functions* now_func);//汇编代码输出
void get_callee_saved_reg();//得到callee_saved寄存器,分配空间
void allocate_physical_reg(functions* now_func);//为物理寄存器分配栈空间
std::string get_function_name(std::string line);
