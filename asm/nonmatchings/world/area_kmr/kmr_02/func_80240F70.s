.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F70
/* 8B0FE0 80240F70 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B0FE4 80240F74 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B0FE8 80240F78 0080882D */  daddu     $s1, $a0, $zero
/* 8B0FEC 80240F7C AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B0FF0 80240F80 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B0FF4 80240F84 8E30000C */  lw        $s0, 0xc($s1)
/* 8B0FF8 80240F88 8E050000 */  lw        $a1, ($s0)
/* 8B0FFC 80240F8C 0C0B1EAF */  jal       get_variable
/* 8B1000 80240F90 26100004 */   addiu    $s0, $s0, 4
/* 8B1004 80240F94 00021880 */  sll       $v1, $v0, 2
/* 8B1008 80240F98 00621821 */  addu      $v1, $v1, $v0
/* 8B100C 80240F9C 00031880 */  sll       $v1, $v1, 2
/* 8B1010 80240FA0 00621823 */  subu      $v1, $v1, $v0
/* 8B1014 80240FA4 000310C0 */  sll       $v0, $v1, 3
/* 8B1018 80240FA8 00621821 */  addu      $v1, $v1, $v0
/* 8B101C 80240FAC 000318C0 */  sll       $v1, $v1, 3
/* 8B1020 80240FB0 3C01800B */  lui       $at, 0x800b
/* 8B1024 80240FB4 00230821 */  addu      $at, $at, $v1
/* 8B1028 80240FB8 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* 8B102C 80240FBC 3C014480 */  lui       $at, 0x4480
/* 8B1030 80240FC0 44810000 */  mtc1      $at, $f0
/* 8B1034 80240FC4 00000000 */  nop       
/* 8B1038 80240FC8 46001082 */  mul.s     $f2, $f2, $f0
/* 8B103C 80240FCC 00000000 */  nop       
/* 8B1040 80240FD0 3C01CD5B */  lui       $at, 0xcd5b
/* 8B1044 80240FD4 34215858 */  ori       $at, $at, 0x5858
/* 8B1048 80240FD8 44810000 */  mtc1      $at, $f0
/* 8B104C 80240FDC 00000000 */  nop       
/* 8B1050 80240FE0 46001080 */  add.s     $f2, $f2, $f0
/* 8B1054 80240FE4 8E050000 */  lw        $a1, ($s0)
/* 8B1058 80240FE8 4600110D */  trunc.w.s $f4, $f2
/* 8B105C 80240FEC 44062000 */  mfc1      $a2, $f4
/* 8B1060 80240FF0 0C0B2026 */  jal       set_variable
/* 8B1064 80240FF4 0220202D */   daddu    $a0, $s1, $zero
/* 8B1068 80240FF8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B106C 80240FFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B1070 80241000 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B1074 80241004 24020002 */  addiu     $v0, $zero, 2
/* 8B1078 80241008 03E00008 */  jr        $ra
/* 8B107C 8024100C 27BD0020 */   addiu    $sp, $sp, 0x20
