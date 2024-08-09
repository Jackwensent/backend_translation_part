/*汇编指令类型*/
#define ins_asm_mv 0
#define ins_asm_la 1
#define ins_asm_li 2
#define ins_asm_lw 3
#define ins_asm_flw 4
#define ins_asm_ld 5
#define ins_asm_fld 6
#define ins_asm_sw 7
#define ins_asm_fsw 8
#define ins_asm_sd 9
#define ins_asm_fsd 10
#define ins_asm_fmv_x_w 11
#define ins_asm_fmv_w_x 12
#define ins_asm_add 13
#define ins_asm_addi 14
#define ins_asm_sub 15
#define ins_asm_subi 16
#define ins_asm_mul 17
#define ins_asm_div 18
#define ins_asm_rem 19
#define ins_asm_and 20
#define ins_asm_andi 21
#define ins_asm_or 22
#define ins_asm_ori 23
#define ins_asm_xor 24
#define ins_asm_xori 25
#define ins_asm_sll 26
#define ins_asm_srl 27
#define ins_asm_sra 28
#define ins_asm_slli 29
#define ins_asm_srli 30
#define ins_asm_srai 31
#define ins_asm_addw 32
#define ins_asm_addiw 33
#define ins_asm_subw 34
#define ins_asm_subiw 35
#define ins_asm_mulw 36
#define ins_asm_divw 37
#define ins_asm_remw 38
#define ins_asm_andw 39
#define ins_asm_andiw 40
#define ins_asm_orw 41
#define ins_asm_oriw 42
#define ins_asm_xorw 43
#define ins_asm_xoriw 44
#define ins_asm_sllw 45
#define ins_asm_srlw 46
#define ins_asm_sraw 47
#define ins_asm_slliw 48
#define ins_asm_srliw 49
#define ins_asm_sraiw 50
#define ins_asm_fadd_s 51
#define ins_asm_fsub_s 52
#define ins_asm_fmul_s 53
#define ins_asm_fdiv_s 54
#define ins_asm_frem_s 55
#define ins_asm_fneg_s 56
#define ins_asm_fcvt_s_w 57
#define ins_asm_fcvt_w_s 58
#define ins_asm_j 59
#define ins_asm_jal 60
#define ins_asm_jr 61
#define ins_asm_beq 62
#define ins_asm_bne 63
#define ins_asm_blt 64
#define ins_asm_bltu 65
#define ins_asm_ble 66
#define ins_asm_bleu 67
#define ins_asm_bgt 68
#define ins_asm_bgtu 69
#define ins_asm_bge 70
#define ins_asm_bgeu 71
#define ins_asm_feq_s 72
#define ins_asm_flt_s 73
#define ins_asm_fle_s 74
#define ins_asm_call 75
#define ins_asm_fcmpe_s 76
#define ins_asm_bgtz 77
#define ins_asm_label 78

/*寄存器存储数据类型*/
#define i32 0
#define float32 1
#define i64 2
/*寄存器保存类型*/
#define special 0
#define callee_saved 1
#define caller_saved 2

/*整形寄存器编号*/
#define x0 0
#define x1 1
#define x2 2
#define x3 3
#define x4 4
#define x5 5
#define x6 6
#define x7 7
#define x8 8
#define x9 9
#define x10 10
#define x11 11
#define x12 12
#define x13 13
#define x14 14
#define x15 15
#define x16 16
#define x17 17
#define x18 18
#define x19 19
#define x20 20
#define x21 21
#define x22 22
#define x23 23
#define x24 24
#define x25 25
#define x26 26
#define x27 27
#define x28 28
#define x29 29
#define x30 30
#define x31 31

#define zero x0
#define ra x1
#define sp x2
#define gp x3
#define tp x4
#define t0 x5
#define t1 x6
#define t2 x7
#define s0 x8
#define s1 x9
#define a0 x10
#define a1 x11
#define a2 x12
#define a3 x13
#define a4 x14
#define a5 x15
#define a6 x16
#define a7 x17
#define s2 x18
#define s3 x19
#define s4 x20
#define s5 x21
#define s6 x22
#define s7 x23
#define s8 x24
#define s9 x25
#define s10 x26
#define s11 x27
#define t3 x28
#define t4 x29
#define t5 x30
#define t6 x31

/*浮点型寄存器编号*/
#define f0 0
#define f1 1
#define f2 2
#define f3 3
#define f4 4
#define f5 5
#define f6 6
#define f7 7
#define f8 8
#define f9 9
#define f10 10
#define f11 11
#define f12 12
#define f13 13
#define f14 14
#define f15 15
#define f16 16
#define f17 17
#define f18 18
#define f19 19
#define f20 20
#define f21 21
#define f22 22
#define f23 23
#define f24 24
#define f25 25
#define f26 26
#define f27 27
#define f28 28
#define f29 29
#define f30 30
#define f31 31

#define ft0 f0
#define ft1 f1
#define ft2 f2
#define ft3 f3
#define ft4 f4
#define ft5 f5
#define ft6 f6
#define ft7 f7
#define fs0 f8
#define fs1 f9
#define fa0 f10
#define fa1 f11
#define fa2 f12
#define fa3 f13
#define fa4 f14
#define fa5 f15
#define fa6 f16
#define fa7 f17
#define fs2 f18
#define fs3 f19
#define fs4 f20
#define fs5 f21
#define fs6 f22
#define fs7 f23
#define fs8 f24
#define fs9 f25
#define fs10 f26
#define fs11 f27
#define ft8 f28
#define ft9 f29
#define ft10 f30
#define ft11 f31

#define fcsr 64

/*空间偏移量*/
#define delta_Rd 0
#define delta_Rs1 8
#define delta_Rs2 16

extern variable_table* global, * global_tail;
extern int total_global;//存储变量的数量
extern map<type_variables, int>map_global;//全局变量名到编号的映射
extern map<int, int>map_register_local;//寄存器编号到变量编号的映射
extern map<int, int>map_register_local_alloca;//alloca语句内寄存器编号到变量编号的映射

extern instruction* start;//属于全局的指令
extern map<std::string, int>ins_num, cond_num;
extern map<int, instruction*>map_instruction_position;//指令编号到指针的映射
extern map<int, pair<int, int> >map_ins_copy;//记录copy指令的位置

extern map<type_label, int>label_num;//label名到编号的映射
extern map<int, int>label_ins;//label到指令的映射
extern vector<basic_block*>label_bb;//label编号对应的bb编号
extern int tot_label;//label数量

extern functions* func_head, * func_tail;
extern map<type_label, int>map_function;
extern int tot_functions;//总的函数数
int tot_asm_instructions;//总的汇编指令数

bool occupied_reg[2][num_registers];

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


/*函数*/
void clear_occupied_reg();

float BinaryToFloat(unsigned int num);

void get_new_asm_instruction(int op, int Rd, int Rs1, int Rs2, int imm, int label, functions* now_func);

void temp_store(int op, int reg_num, int imm, functions* now_func);

void temp_load(int op, int reg_num, int imm, functions* now_func);

void temp_global(int reg_num, int imm, functions* now_func);

bool is_in_range(unsigned int imm);

bool is_free(int num, int op, int reg_num);

void save_caller_saved_regs(functions* now_func);

void load_caller_saved_regs(functions* now_func, int R1 = -1);

void save_callee_saved_regs(functions* now_func);

void load_callee_saved_regs(functions* now_func);

bool find_free_reg(int& now_reg, int num, int op, int R1 = -1, int R2 = -1);

void find_physical_reg(int op, int ins_num, int virtual_reg, int num_not_find, int& physical_reg, bool& fReg,
int imm = 0, int R1 = -1, int R2 = -1);

void pre_load_store(functions* now_func, int vRd = -1, int fRd = -1, int Rd = -1,
int vRs1 = -1, int fRs1 = -1, int Rs1 = -1, int vRs2 = -1, int fRs2 = -1, int Rs2 = -1);

void suf_load_store(functions* now_func, int vRd = -1, int fRd = -1, int Rd = -1,
int vRs1 = -1, int fRs1 = -1, int Rs1 = -1, int vRs2 = -1, int fRs2 = -1, int Rs2 = -1);

void gen_load(instruction* now_ins, functions* now_func);

void gen_store(instruction* now_ins, functions* now_func);

void gen_alloca(instruction* now_ins, functions* now_func);

void gen_GEP(instruction* now_ins, functions* now_func);

void gen_operation(instruction* now_ins, functions* now_func);

void gen_xcmp(instruction* now_ins, functions* now_func);

void gen_branch(instruction* now_ins, functions* now_func);

void gen_call(instruction* now_ins, functions* now_func);

void gen_ret(instruction* now_ins, functions* now_func);

void gen_label(instruction* now_ins, functions* now_func);

void gen_xtoy(instruction* now_ins, functions* now_func);

void gen_copy(instruction* now_ins, functions* now_func);

void gen_instruction(instruction* now_ins, functions* now_func);

void gen_func_start(functions* now_func);

void gen_func_end(functions* now_func);

void get_asm();

