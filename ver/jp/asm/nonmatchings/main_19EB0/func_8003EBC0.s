.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003EBC0
/* 19FC0 8003EBC0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 19FC4 8003EBC4 AFB00010 */  sw        $s0, 0x10($sp)
/* 19FC8 8003EBC8 0080802D */  daddu     $s0, $a0, $zero
/* 19FCC 8003EBCC 10A0000E */  beqz      $a1, .L8003EC08
/* 19FD0 8003EBD0 AFBF0014 */   sw       $ra, 0x14($sp)
/* 19FD4 8003EBD4 0C048A8F */  jal       func_80122A3C
/* 19FD8 8003EBD8 24040001 */   addiu    $a0, $zero, 1
/* 19FDC 8003EBDC 0000202D */  daddu     $a0, $zero, $zero
/* 19FE0 8003EBE0 0080282D */  daddu     $a1, $a0, $zero
/* 19FE4 8003EBE4 0080302D */  daddu     $a2, $a0, $zero
/* 19FE8 8003EBE8 0080382D */  daddu     $a3, $a0, $zero
/* 19FEC 8003EBEC 3C028015 */  lui       $v0, %hi(D_80156350)
/* 19FF0 8003EBF0 8C426350 */  lw        $v0, %lo(D_80156350)($v0)
/* 19FF4 8003EBF4 24030001 */  addiu     $v1, $zero, 1
/* 19FF8 8003EBF8 0C04841B */  jal       func_8012106C
/* 19FFC 8003EBFC A0430000 */   sb       $v1, ($v0)
/* 1A000 8003EC00 24020019 */  addiu     $v0, $zero, 0x19
/* 1A004 8003EC04 AE020070 */  sw        $v0, 0x70($s0)
.L8003EC08:
/* 1A008 8003EC08 0000202D */  daddu     $a0, $zero, $zero
/* 1A00C 8003EC0C 0080282D */  daddu     $a1, $a0, $zero
/* 1A010 8003EC10 0080302D */  daddu     $a2, $a0, $zero
/* 1A014 8003EC14 8E030070 */  lw        $v1, 0x70($s0)
/* 1A018 8003EC18 24020019 */  addiu     $v0, $zero, 0x19
/* 1A01C 8003EC1C 00431023 */  subu      $v0, $v0, $v1
/* 1A020 8003EC20 00023880 */  sll       $a3, $v0, 2
/* 1A024 8003EC24 00E23821 */  addu      $a3, $a3, $v0
/* 1A028 8003EC28 00073840 */  sll       $a3, $a3, 1
/* 1A02C 8003EC2C 0C04841B */  jal       func_8012106C
/* 1A030 8003EC30 30E700FE */   andi     $a3, $a3, 0xfe
/* 1A034 8003EC34 8E020070 */  lw        $v0, 0x70($s0)
/* 1A038 8003EC38 2442FFFF */  addiu     $v0, $v0, -1
/* 1A03C 8003EC3C AE020070 */  sw        $v0, 0x70($s0)
/* 1A040 8003EC40 2C420001 */  sltiu     $v0, $v0, 1
/* 1A044 8003EC44 8FBF0014 */  lw        $ra, 0x14($sp)
/* 1A048 8003EC48 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A04C 8003EC4C 00021040 */  sll       $v0, $v0, 1
/* 1A050 8003EC50 03E00008 */  jr        $ra
/* 1A054 8003EC54 27BD0018 */   addiu    $sp, $sp, 0x18
