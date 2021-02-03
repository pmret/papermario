.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_740CC0
/* 740CC0 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 740CC4 802A1004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 740CC8 802A1008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 740CCC 802A100C AFBF0020 */  sw        $ra, 0x20($sp)
/* 740CD0 802A1010 AFB1001C */  sw        $s1, 0x1c($sp)
/* 740CD4 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 740CD8 802A1018 8C6200D8 */  lw        $v0, 0xd8($v1)
/* 740CDC 802A101C 0080802D */  daddu     $s0, $a0, $zero
/* 740CE0 802A1020 C442001C */  lwc1      $f2, 0x1c($v0)
/* 740CE4 802A1024 C44C0144 */  lwc1      $f12, 0x144($v0)
/* 740CE8 802A1028 C44E0148 */  lwc1      $f14, 0x148($v0)
/* 740CEC 802A102C C444014C */  lwc1      $f4, 0x14c($v0)
/* 740CF0 802A1030 C4460018 */  lwc1      $f6, 0x18($v0)
/* 740CF4 802A1034 C4400020 */  lwc1      $f0, 0x20($v0)
/* 740CF8 802A1038 44062000 */  mfc1      $a2, $f4
/* 740CFC 802A103C 44073000 */  mfc1      $a3, $f6
/* 740D00 802A1040 0060882D */  daddu     $s1, $v1, $zero
/* 740D04 802A1044 E7A20010 */  swc1      $f2, 0x10($sp)
/* 740D08 802A1048 0C00A7CB */  jal       dist3D
/* 740D0C 802A104C E7A00014 */   swc1     $f0, 0x14($sp)
/* 740D10 802A1050 3C014170 */  lui       $at, 0x4170
/* 740D14 802A1054 44811000 */  mtc1      $at, $f2
/* 740D18 802A1058 00000000 */  nop
/* 740D1C 802A105C 46020002 */  mul.s     $f0, $f0, $f2
/* 740D20 802A1060 00000000 */  nop
/* 740D24 802A1064 3C0142C8 */  lui       $at, 0x42c8
/* 740D28 802A1068 44811000 */  mtc1      $at, $f2
/* 740D2C 802A106C 00000000 */  nop
/* 740D30 802A1070 46020003 */  div.s     $f0, $f0, $f2
/* 740D34 802A1074 4600020D */  trunc.w.s $f8, $f0
/* 740D38 802A1078 44024000 */  mfc1      $v0, $f8
/* 740D3C 802A107C 00000000 */  nop
/* 740D40 802A1080 AE020084 */  sw        $v0, 0x84($s0)
/* 740D44 802A1084 28420015 */  slti      $v0, $v0, 0x15
/* 740D48 802A1088 14400002 */  bnez      $v0, .L802A1094
/* 740D4C 802A108C 24020014 */   addiu    $v0, $zero, 0x14
/* 740D50 802A1090 AE020084 */  sw        $v0, 0x84($s0)
.L802A1094:
/* 740D54 802A1094 82220083 */  lb        $v0, 0x83($s1)
/* 740D58 802A1098 10400007 */  beqz      $v0, .L802A10B8
/* 740D5C 802A109C 00000000 */   nop
/* 740D60 802A10A0 8E020084 */  lw        $v0, 0x84($s0)
/* 740D64 802A10A4 28420006 */  slti      $v0, $v0, 6
/* 740D68 802A10A8 10400008 */  beqz      $v0, .L802A10CC
/* 740D6C 802A10AC 24020006 */   addiu    $v0, $zero, 6
/* 740D70 802A10B0 080A8433 */  j         .L802A10CC
/* 740D74 802A10B4 AE020084 */   sw       $v0, 0x84($s0)
.L802A10B8:
/* 740D78 802A10B8 8E020084 */  lw        $v0, 0x84($s0)
/* 740D7C 802A10BC 2842000C */  slti      $v0, $v0, 0xc
/* 740D80 802A10C0 10400002 */  beqz      $v0, .L802A10CC
/* 740D84 802A10C4 2402000C */   addiu    $v0, $zero, 0xc
/* 740D88 802A10C8 AE020084 */  sw        $v0, 0x84($s0)
.L802A10CC:
/* 740D8C 802A10CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 740D90 802A10D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 740D94 802A10D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 740D98 802A10D8 24020002 */  addiu     $v0, $zero, 2
/* 740D9C 802A10DC 03E00008 */  jr        $ra
