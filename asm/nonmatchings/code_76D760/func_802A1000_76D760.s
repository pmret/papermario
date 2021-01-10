.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802A1000_76D760
/* 76D760 802A1000 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 76D764 802A1004 3C03800E */  lui       $v1, %hi(gBattleStatus)
/* 76D768 802A1008 2463C070 */  addiu     $v1, $v1, %lo(gBattleStatus)
/* 76D76C 802A100C AFBF0020 */  sw        $ra, 0x20($sp)
/* 76D770 802A1010 AFB1001C */  sw        $s1, 0x1c($sp)
/* 76D774 802A1014 AFB00018 */  sw        $s0, 0x18($sp)
/* 76D778 802A1018 8C6200D8 */  lw        $v0, 0xd8($v1)
/* 76D77C 802A101C 0080802D */  daddu     $s0, $a0, $zero
/* 76D780 802A1020 C442001C */  lwc1      $f2, 0x1c($v0)
/* 76D784 802A1024 C44C0144 */  lwc1      $f12, 0x144($v0)
/* 76D788 802A1028 C44E0148 */  lwc1      $f14, 0x148($v0)
/* 76D78C 802A102C C444014C */  lwc1      $f4, 0x14c($v0)
/* 76D790 802A1030 C4460018 */  lwc1      $f6, 0x18($v0)
/* 76D794 802A1034 C4400020 */  lwc1      $f0, 0x20($v0)
/* 76D798 802A1038 44062000 */  mfc1      $a2, $f4
/* 76D79C 802A103C 44073000 */  mfc1      $a3, $f6
/* 76D7A0 802A1040 0060882D */  daddu     $s1, $v1, $zero
/* 76D7A4 802A1044 E7A20010 */  swc1      $f2, 0x10($sp)
/* 76D7A8 802A1048 0C00A7CB */  jal       dist3D
/* 76D7AC 802A104C E7A00014 */   swc1     $f0, 0x14($sp)
/* 76D7B0 802A1050 3C014170 */  lui       $at, 0x4170
/* 76D7B4 802A1054 44811000 */  mtc1      $at, $f2
/* 76D7B8 802A1058 00000000 */  nop       
/* 76D7BC 802A105C 46020002 */  mul.s     $f0, $f0, $f2
/* 76D7C0 802A1060 00000000 */  nop       
/* 76D7C4 802A1064 3C0142C8 */  lui       $at, 0x42c8
/* 76D7C8 802A1068 44811000 */  mtc1      $at, $f2
/* 76D7CC 802A106C 00000000 */  nop       
/* 76D7D0 802A1070 46020003 */  div.s     $f0, $f0, $f2
/* 76D7D4 802A1074 4600020D */  trunc.w.s $f8, $f0
/* 76D7D8 802A1078 44024000 */  mfc1      $v0, $f8
/* 76D7DC 802A107C 00000000 */  nop       
/* 76D7E0 802A1080 AE020084 */  sw        $v0, 0x84($s0)
/* 76D7E4 802A1084 28420015 */  slti      $v0, $v0, 0x15
/* 76D7E8 802A1088 14400002 */  bnez      $v0, .L802A1094
/* 76D7EC 802A108C 24020014 */   addiu    $v0, $zero, 0x14
/* 76D7F0 802A1090 AE020084 */  sw        $v0, 0x84($s0)
.L802A1094:
/* 76D7F4 802A1094 82220083 */  lb        $v0, 0x83($s1)
/* 76D7F8 802A1098 10400007 */  beqz      $v0, .L802A10B8
/* 76D7FC 802A109C 00000000 */   nop      
/* 76D800 802A10A0 8E020084 */  lw        $v0, 0x84($s0)
/* 76D804 802A10A4 28420006 */  slti      $v0, $v0, 6
/* 76D808 802A10A8 10400008 */  beqz      $v0, .L802A10CC
/* 76D80C 802A10AC 24020006 */   addiu    $v0, $zero, 6
/* 76D810 802A10B0 080A8433 */  j         .L802A10CC
/* 76D814 802A10B4 AE020084 */   sw       $v0, 0x84($s0)
.L802A10B8:
/* 76D818 802A10B8 8E020084 */  lw        $v0, 0x84($s0)
/* 76D81C 802A10BC 2842000C */  slti      $v0, $v0, 0xc
/* 76D820 802A10C0 10400002 */  beqz      $v0, .L802A10CC
/* 76D824 802A10C4 2402000C */   addiu    $v0, $zero, 0xc
/* 76D828 802A10C8 AE020084 */  sw        $v0, 0x84($s0)
.L802A10CC:
/* 76D82C 802A10CC 8FBF0020 */  lw        $ra, 0x20($sp)
/* 76D830 802A10D0 8FB1001C */  lw        $s1, 0x1c($sp)
/* 76D834 802A10D4 8FB00018 */  lw        $s0, 0x18($sp)
/* 76D838 802A10D8 24020002 */  addiu     $v0, $zero, 2
/* 76D83C 802A10DC 03E00008 */  jr        $ra
