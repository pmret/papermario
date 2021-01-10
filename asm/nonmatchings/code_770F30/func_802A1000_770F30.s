.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_770F30
/* 770F30 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 770F34 802A1004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 770F38 802A1008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 770F3C 802A100C AFBF0020 */  sw        $ra, 0x20($sp)
/* 770F40 802A1010 AFB1001C */  sw        $s1, 0x1c($sp)
/* 770F44 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 770F48 802A1018 8C6200D8 */  lw        $v0, 0xd8($v1)
/* 770F4C 802A101C 0080802D */  daddu     $s0, $a0, $zero
/* 770F50 802A1020 C442001C */  lwc1      $f2, 0x1c($v0)
/* 770F54 802A1024 C44C0144 */  lwc1      $f12, 0x144($v0)
/* 770F58 802A1028 C44E0148 */  lwc1      $f14, 0x148($v0)
/* 770F5C 802A102C C444014C */  lwc1      $f4, 0x14c($v0)
/* 770F60 802A1030 C4460018 */  lwc1      $f6, 0x18($v0)
/* 770F64 802A1034 C4400020 */  lwc1      $f0, 0x20($v0)
/* 770F68 802A1038 44062000 */  mfc1      $a2, $f4
/* 770F6C 802A103C 44073000 */  mfc1      $a3, $f6
/* 770F70 802A1040 0060882D */  daddu     $s1, $v1, $zero
/* 770F74 802A1044 E7A20010 */  swc1      $f2, 0x10($sp)
/* 770F78 802A1048 0C00A7CB */  jal       dist3D
/* 770F7C 802A104C E7A00014 */   swc1     $f0, 0x14($sp)
/* 770F80 802A1050 3C014170 */  lui       $at, 0x4170
/* 770F84 802A1054 44811000 */  mtc1      $at, $f2
/* 770F88 802A1058 00000000 */  nop       
/* 770F8C 802A105C 46020002 */  mul.s     $f0, $f0, $f2
/* 770F90 802A1060 00000000 */  nop       
/* 770F94 802A1064 3C0142C8 */  lui       $at, 0x42c8
/* 770F98 802A1068 44811000 */  mtc1      $at, $f2
/* 770F9C 802A106C 00000000 */  nop       
/* 770FA0 802A1070 46020003 */  div.s     $f0, $f0, $f2
/* 770FA4 802A1074 4600020D */  trunc.w.s $f8, $f0
/* 770FA8 802A1078 44024000 */  mfc1      $v0, $f8
/* 770FAC 802A107C 00000000 */  nop       
/* 770FB0 802A1080 AE020084 */  sw        $v0, 0x84($s0)
/* 770FB4 802A1084 28420015 */  slti      $v0, $v0, 0x15
/* 770FB8 802A1088 14400002 */  bnez      $v0, .L802A1094
/* 770FBC 802A108C 24020014 */   addiu    $v0, $zero, 0x14
/* 770FC0 802A1090 AE020084 */  sw        $v0, 0x84($s0)
.L802A1094:
/* 770FC4 802A1094 82220083 */  lb        $v0, 0x83($s1)
/* 770FC8 802A1098 10400007 */  beqz      $v0, .L802A10B8
/* 770FCC 802A109C 00000000 */   nop      
/* 770FD0 802A10A0 8E020084 */  lw        $v0, 0x84($s0)
/* 770FD4 802A10A4 28420006 */  slti      $v0, $v0, 6
/* 770FD8 802A10A8 10400008 */  beqz      $v0, .L802A10CC
/* 770FDC 802A10AC 24020006 */   addiu    $v0, $zero, 6
/* 770FE0 802A10B0 080A8433 */  j         .L802A10CC
/* 770FE4 802A10B4 AE020084 */   sw       $v0, 0x84($s0)
.L802A10B8:
/* 770FE8 802A10B8 8E020084 */  lw        $v0, 0x84($s0)
/* 770FEC 802A10BC 2842000C */  slti      $v0, $v0, 0xc
/* 770FF0 802A10C0 10400002 */  beqz      $v0, .L802A10CC
/* 770FF4 802A10C4 2402000C */   addiu    $v0, $zero, 0xc
/* 770FF8 802A10C8 AE020084 */  sw        $v0, 0x84($s0)
.L802A10CC:
/* 770FFC 802A10CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 771000 802A10D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 771004 802A10D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 771008 802A10D8 24020002 */  addiu     $v0, $zero, 2
/* 77100C 802A10DC 03E00008 */  jr        $ra
