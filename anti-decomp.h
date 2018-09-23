#ifdef __i386__
// Postive SP Predicate
#define positive_sp_predicate \
do { \
	__asm__ ( \
		" push eax	\n"	\
		" xor  eax, eax	\n"	\
		" jz   opaque	\n"	\
		" add  esp, 4	\n"	\
		"opaque:	\n"	\
		" pop  eax	\n" );	\
} while(0);

// Return Hijacking
extern void gadget();
__asm__ ( 	".global gadget		\n"
		"gadget:		\n"
		" pop  eax		\n"
		" mov  esp, ebp		\n"
		" call eax		\n"
		" pop  ebp		\n"
		" ret			\n" );

#define ret_hijack(GADGETS)		\
do { 					\
	__asm__ ( 			\
		" mov esp, %0;	\n"	\
		" ret"			\
		: 			\
		:"i" (GADGETS)	);	\
} while(0);
#endif

#ifdef __x86_64__ 
// Postive SP Predicate
#define positive_sp_predicate \
do { \
	__asm__ ( \
		" push rax	\n"	\
		" xor  rax, rax	\n"	\
		" jz   opaque	\n"	\
		" add  rsp, 4	\n"	\
		"opaque:	\n"	\
		" pop  rax	\n" );	\
} while(0);

// Return Hijacking
extern void gadget();
__asm__ ( 	".global gadget		\n"
		"gadget:		\n"
		" pop  rax		\n"
		" mov  rsp, rbp		\n"
		" call rax		\n"
		" pop  rbp		\n"
		" ret			\n" );

#define ret_hijack(GADGETS)		\
do { 					\
	__asm__ ( 			\
		" mov rsp, %0;	\n"	\
		" ret"			\
		: 			\
		:"i" (GADGETS)	);	\
} while(0);
#endif
