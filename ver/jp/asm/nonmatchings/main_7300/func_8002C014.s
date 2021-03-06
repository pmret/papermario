.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C014
/* 7414 8002C014 3C026666 */  lui       $v0, 0x6666
/* 7418 8002C018 34426667 */  ori       $v0, $v0, 0x6667
/* 741C 8002C01C 00C20018 */  mult      $a2, $v0
/* 7420 8002C020 0080382D */  daddu     $a3, $a0, $zero
/* 7424 8002C024 000617C3 */  sra       $v0, $a2, 0x1f
/* 7428 8002C028 3C048007 */  lui       $a0, %hi(D_80077270)
/* 742C 8002C02C 24847270 */  addiu     $a0, $a0, %lo(D_80077270)
/* 7430 8002C030 00007010 */  mfhi      $t6
/* 7434 8002C034 000E1843 */  sra       $v1, $t6, 1
/* 7438 8002C038 00621823 */  subu      $v1, $v1, $v0
/* 743C 8002C03C 000310C0 */  sll       $v0, $v1, 3
/* 7440 8002C040 00431023 */  subu      $v0, $v0, $v1
/* 7444 8002C044 00021080 */  sll       $v0, $v0, 2
/* 7448 8002C048 00445021 */  addu      $t2, $v0, $a0
/* 744C 8002C04C 00031080 */  sll       $v0, $v1, 2
/* 7450 8002C050 00431021 */  addu      $v0, $v0, $v1
/* 7454 8002C054 00C23023 */  subu      $a2, $a2, $v0
/* 7458 8002C058 00061040 */  sll       $v0, $a2, 1
/* 745C 8002C05C 00461021 */  addu      $v0, $v0, $a2
/* 7460 8002C060 00026040 */  sll       $t4, $v0, 1
/* 7464 8002C064 3C04800A */  lui       $a0, %hi(D_8009BB10)
/* 7468 8002C068 2484BB10 */  addiu     $a0, $a0, %lo(D_8009BB10)
/* 746C 8002C06C 948309D0 */  lhu       $v1, 0x9d0($a0)
/* 7470 8002C070 24020140 */  addiu     $v0, $zero, 0x140
/* 7474 8002C074 14620024 */  bne       $v1, $v0, .L8002C108
/* 7478 8002C078 24020280 */   addiu    $v0, $zero, 0x280
/* 747C 8002C07C 0060102D */  daddu     $v0, $v1, $zero
/* 7480 8002C080 00450018 */  mult      $v0, $a1
/* 7484 8002C084 0000482D */  daddu     $t1, $zero, $zero
/* 7488 8002C088 3C0D8000 */  lui       $t5, 0x8000
/* 748C 8002C08C 0080582D */  daddu     $t3, $a0, $zero
/* 7490 8002C090 8D6209CC */  lw        $v0, 0x9cc($t3)
/* 7494 8002C094 00007012 */  mflo      $t6
/* 7498 8002C098 000E1840 */  sll       $v1, $t6, 1
/* 749C 8002C09C 00431021 */  addu      $v0, $v0, $v1
/* 74A0 8002C0A0 00071840 */  sll       $v1, $a3, 1
/* 74A4 8002C0A4 00432821 */  addu      $a1, $v0, $v1
/* 74A8 8002C0A8 018D2006 */  srlv      $a0, $t5, $t4
.L8002C0AC:
/* 74AC 8002C0AC 8D480000 */  lw        $t0, ($t2)
/* 74B0 8002C0B0 254A0004 */  addiu     $t2, $t2, 4
/* 74B4 8002C0B4 24060005 */  addiu     $a2, $zero, 5
.L8002C0B8:
/* 74B8 8002C0B8 00A0382D */  daddu     $a3, $a1, $zero
/* 74BC 8002C0BC 24A50002 */  addiu     $a1, $a1, 2
/* 74C0 8002C0C0 00881024 */  and       $v0, $a0, $t0
/* 74C4 8002C0C4 10400002 */  beqz      $v0, .L8002C0D0
/* 74C8 8002C0C8 24030001 */   addiu    $v1, $zero, 1
/* 74CC 8002C0CC 3403FFFF */  ori       $v1, $zero, 0xffff
.L8002C0D0:
/* 74D0 8002C0D0 A4E30000 */  sh        $v1, ($a3)
/* 74D4 8002C0D4 24C6FFFF */  addiu     $a2, $a2, -1
/* 74D8 8002C0D8 04C1FFF7 */  bgez      $a2, .L8002C0B8
/* 74DC 8002C0DC 00042042 */   srl      $a0, $a0, 1
/* 74E0 8002C0E0 956209D0 */  lhu       $v0, 0x9d0($t3)
/* 74E4 8002C0E4 25290001 */  addiu     $t1, $t1, 1
/* 74E8 8002C0E8 00021040 */  sll       $v0, $v0, 1
/* 74EC 8002C0EC 2442FFF4 */  addiu     $v0, $v0, -0xc
/* 74F0 8002C0F0 00A22821 */  addu      $a1, $a1, $v0
/* 74F4 8002C0F4 29220007 */  slti      $v0, $t1, 7
/* 74F8 8002C0F8 1440FFEC */  bnez      $v0, .L8002C0AC
/* 74FC 8002C0FC 018D2006 */   srlv     $a0, $t5, $t4
.L8002C100:
/* 7500 8002C100 03E00008 */  jr        $ra
/* 7504 8002C104 00000000 */   nop
.L8002C108:
/* 7508 8002C108 1462FFFD */  bne       $v1, $v0, .L8002C100
/* 750C 8002C10C 0000482D */   daddu    $t1, $zero, $zero
/* 7510 8002C110 3C0B8000 */  lui       $t3, 0x8000
/* 7514 8002C114 00051080 */  sll       $v0, $a1, 2
/* 7518 8002C118 00451021 */  addu      $v0, $v0, $a1
/* 751C 8002C11C 8C8309CC */  lw        $v1, 0x9cc($a0)
/* 7520 8002C120 00021240 */  sll       $v0, $v0, 9
/* 7524 8002C124 00621821 */  addu      $v1, $v1, $v0
/* 7528 8002C128 00071080 */  sll       $v0, $a3, 2
/* 752C 8002C12C 00621821 */  addu      $v1, $v1, $v0
.L8002C130:
/* 7530 8002C130 018B3806 */  srlv      $a3, $t3, $t4
/* 7534 8002C134 8D480000 */  lw        $t0, ($t2)
/* 7538 8002C138 254A0004 */  addiu     $t2, $t2, 4
/* 753C 8002C13C 0000302D */  daddu     $a2, $zero, $zero
/* 7540 8002C140 24650502 */  addiu     $a1, $v1, 0x502
.L8002C144:
/* 7544 8002C144 00E81024 */  and       $v0, $a3, $t0
/* 7548 8002C148 10400002 */  beqz      $v0, .L8002C154
/* 754C 8002C14C 24040001 */   addiu    $a0, $zero, 1
/* 7550 8002C150 3404FFFF */  ori       $a0, $zero, 0xffff
.L8002C154:
/* 7554 8002C154 A4640000 */  sh        $a0, ($v1)
/* 7558 8002C158 A4A4FB00 */  sh        $a0, -0x500($a1)
/* 755C 8002C15C A4A4FFFE */  sh        $a0, -2($a1)
/* 7560 8002C160 A4A40000 */  sh        $a0, ($a1)
/* 7564 8002C164 24A50004 */  addiu     $a1, $a1, 4
/* 7568 8002C168 24630004 */  addiu     $v1, $v1, 4
/* 756C 8002C16C 24C60001 */  addiu     $a2, $a2, 1
/* 7570 8002C170 28C20006 */  slti      $v0, $a2, 6
/* 7574 8002C174 1440FFF3 */  bnez      $v0, .L8002C144
/* 7578 8002C178 00073842 */   srl      $a3, $a3, 1
/* 757C 8002C17C 25290001 */  addiu     $t1, $t1, 1
/* 7580 8002C180 29220007 */  slti      $v0, $t1, 7
/* 7584 8002C184 1440FFEA */  bnez      $v0, .L8002C130
/* 7588 8002C188 246309E8 */   addiu    $v1, $v1, 0x9e8
/* 758C 8002C18C 03E00008 */  jr        $ra
/* 7590 8002C190 00000000 */   nop
