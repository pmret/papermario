.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_76A830
/* 76A830 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 76A834 802A1004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 76A838 802A1008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 76A83C 802A100C AFBF0020 */  sw        $ra, 0x20($sp)
/* 76A840 802A1010 AFB1001C */  sw        $s1, 0x1c($sp)
/* 76A844 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 76A848 802A1018 8C6200D8 */  lw        $v0, 0xd8($v1)
/* 76A84C 802A101C 0080802D */  daddu     $s0, $a0, $zero
/* 76A850 802A1020 C442001C */  lwc1      $f2, 0x1c($v0)
/* 76A854 802A1024 C44C0144 */  lwc1      $f12, 0x144($v0)
/* 76A858 802A1028 C44E0148 */  lwc1      $f14, 0x148($v0)
/* 76A85C 802A102C C444014C */  lwc1      $f4, 0x14c($v0)
/* 76A860 802A1030 C4460018 */  lwc1      $f6, 0x18($v0)
/* 76A864 802A1034 C4400020 */  lwc1      $f0, 0x20($v0)
/* 76A868 802A1038 44062000 */  mfc1      $a2, $f4
/* 76A86C 802A103C 44073000 */  mfc1      $a3, $f6
/* 76A870 802A1040 0060882D */  daddu     $s1, $v1, $zero
/* 76A874 802A1044 E7A20010 */  swc1      $f2, 0x10($sp)
/* 76A878 802A1048 0C00A7CB */  jal       dist3D
/* 76A87C 802A104C E7A00014 */   swc1     $f0, 0x14($sp)
/* 76A880 802A1050 3C014170 */  lui       $at, 0x4170
/* 76A884 802A1054 44811000 */  mtc1      $at, $f2
/* 76A888 802A1058 00000000 */  nop       
/* 76A88C 802A105C 46020002 */  mul.s     $f0, $f0, $f2
/* 76A890 802A1060 00000000 */  nop       
/* 76A894 802A1064 3C0142C8 */  lui       $at, 0x42c8
/* 76A898 802A1068 44811000 */  mtc1      $at, $f2
/* 76A89C 802A106C 00000000 */  nop       
/* 76A8A0 802A1070 46020003 */  div.s     $f0, $f0, $f2
/* 76A8A4 802A1074 4600020D */  trunc.w.s $f8, $f0
/* 76A8A8 802A1078 44024000 */  mfc1      $v0, $f8
/* 76A8AC 802A107C 00000000 */  nop       
/* 76A8B0 802A1080 AE020084 */  sw        $v0, 0x84($s0)
/* 76A8B4 802A1084 28420015 */  slti      $v0, $v0, 0x15
/* 76A8B8 802A1088 14400002 */  bnez      $v0, .L802A1094
/* 76A8BC 802A108C 24020014 */   addiu    $v0, $zero, 0x14
/* 76A8C0 802A1090 AE020084 */  sw        $v0, 0x84($s0)
.L802A1094:
/* 76A8C4 802A1094 82220083 */  lb        $v0, 0x83($s1)
/* 76A8C8 802A1098 10400007 */  beqz      $v0, .L802A10B8
/* 76A8CC 802A109C 00000000 */   nop      
/* 76A8D0 802A10A0 8E020084 */  lw        $v0, 0x84($s0)
/* 76A8D4 802A10A4 28420006 */  slti      $v0, $v0, 6
/* 76A8D8 802A10A8 10400008 */  beqz      $v0, .L802A10CC
/* 76A8DC 802A10AC 24020006 */   addiu    $v0, $zero, 6
/* 76A8E0 802A10B0 080A8433 */  j         .L802A10CC
/* 76A8E4 802A10B4 AE020084 */   sw       $v0, 0x84($s0)
.L802A10B8:
/* 76A8E8 802A10B8 8E020084 */  lw        $v0, 0x84($s0)
/* 76A8EC 802A10BC 2842000C */  slti      $v0, $v0, 0xc
/* 76A8F0 802A10C0 10400002 */  beqz      $v0, .L802A10CC
/* 76A8F4 802A10C4 2402000C */   addiu    $v0, $zero, 0xc
/* 76A8F8 802A10C8 AE020084 */  sw        $v0, 0x84($s0)
.L802A10CC:
/* 76A8FC 802A10CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 76A900 802A10D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 76A904 802A10D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 76A908 802A10D8 24020002 */  addiu     $v0, $zero, 2
/* 76A90C 802A10DC 03E00008 */  jr        $ra
