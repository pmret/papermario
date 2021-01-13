.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_743DF0
/* 743DF0 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 743DF4 802A1004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 743DF8 802A1008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 743DFC 802A100C AFBF0020 */  sw        $ra, 0x20($sp)
/* 743E00 802A1010 AFB1001C */  sw        $s1, 0x1c($sp)
/* 743E04 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 743E08 802A1018 8C6200D8 */  lw        $v0, 0xd8($v1)
/* 743E0C 802A101C 0080802D */  daddu     $s0, $a0, $zero
/* 743E10 802A1020 C442001C */  lwc1      $f2, 0x1c($v0)
/* 743E14 802A1024 C44C0144 */  lwc1      $f12, 0x144($v0)
/* 743E18 802A1028 C44E0148 */  lwc1      $f14, 0x148($v0)
/* 743E1C 802A102C C444014C */  lwc1      $f4, 0x14c($v0)
/* 743E20 802A1030 C4460018 */  lwc1      $f6, 0x18($v0)
/* 743E24 802A1034 C4400020 */  lwc1      $f0, 0x20($v0)
/* 743E28 802A1038 44062000 */  mfc1      $a2, $f4
/* 743E2C 802A103C 44073000 */  mfc1      $a3, $f6
/* 743E30 802A1040 0060882D */  daddu     $s1, $v1, $zero
/* 743E34 802A1044 E7A20010 */  swc1      $f2, 0x10($sp)
/* 743E38 802A1048 0C00A7CB */  jal       dist3D
/* 743E3C 802A104C E7A00014 */   swc1     $f0, 0x14($sp)
/* 743E40 802A1050 3C014170 */  lui       $at, 0x4170
/* 743E44 802A1054 44811000 */  mtc1      $at, $f2
/* 743E48 802A1058 00000000 */  nop
/* 743E4C 802A105C 46020002 */  mul.s     $f0, $f0, $f2
/* 743E50 802A1060 00000000 */  nop
/* 743E54 802A1064 3C0142C8 */  lui       $at, 0x42c8
/* 743E58 802A1068 44811000 */  mtc1      $at, $f2
/* 743E5C 802A106C 00000000 */  nop
/* 743E60 802A1070 46020003 */  div.s     $f0, $f0, $f2
/* 743E64 802A1074 4600020D */  trunc.w.s $f8, $f0
/* 743E68 802A1078 44024000 */  mfc1      $v0, $f8
/* 743E6C 802A107C 00000000 */  nop
/* 743E70 802A1080 AE020084 */  sw        $v0, 0x84($s0)
/* 743E74 802A1084 28420015 */  slti      $v0, $v0, 0x15
/* 743E78 802A1088 14400002 */  bnez      $v0, .L802A1094
/* 743E7C 802A108C 24020014 */   addiu    $v0, $zero, 0x14
/* 743E80 802A1090 AE020084 */  sw        $v0, 0x84($s0)
.L802A1094:
/* 743E84 802A1094 82220083 */  lb        $v0, 0x83($s1)
/* 743E88 802A1098 10400007 */  beqz      $v0, .L802A10B8
/* 743E8C 802A109C 00000000 */   nop
/* 743E90 802A10A0 8E020084 */  lw        $v0, 0x84($s0)
/* 743E94 802A10A4 28420006 */  slti      $v0, $v0, 6
/* 743E98 802A10A8 10400008 */  beqz      $v0, .L802A10CC
/* 743E9C 802A10AC 24020006 */   addiu    $v0, $zero, 6
/* 743EA0 802A10B0 080A8433 */  j         .L802A10CC
/* 743EA4 802A10B4 AE020084 */   sw       $v0, 0x84($s0)
.L802A10B8:
/* 743EA8 802A10B8 8E020084 */  lw        $v0, 0x84($s0)
/* 743EAC 802A10BC 2842000C */  slti      $v0, $v0, 0xc
/* 743EB0 802A10C0 10400002 */  beqz      $v0, .L802A10CC
/* 743EB4 802A10C4 2402000C */   addiu    $v0, $zero, 0xc
/* 743EB8 802A10C8 AE020084 */  sw        $v0, 0x84($s0)
.L802A10CC:
/* 743EBC 802A10CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 743EC0 802A10D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 743EC4 802A10D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 743EC8 802A10D8 24020002 */  addiu     $v0, $zero, 2
/* 743ECC 802A10DC 03E00008 */  jr        $ra
/* 743ED0 802A10E0 27BD0028 */   addiu    $sp, $sp, 0x28
