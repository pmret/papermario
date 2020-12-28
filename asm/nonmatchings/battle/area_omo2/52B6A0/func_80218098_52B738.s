.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218098_52B738
/* 52B738 80218098 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 52B73C 8021809C AFB00010 */  sw        $s0, 0x10($sp)
/* 52B740 802180A0 0080802D */  daddu     $s0, $a0, $zero
/* 52B744 802180A4 10A00003 */  beqz      $a1, .L802180B4
/* 52B748 802180A8 AFBF0014 */   sw       $ra, 0x14($sp)
/* 52B74C 802180AC 24020014 */  addiu     $v0, $zero, 0x14
/* 52B750 802180B0 AE020070 */  sw        $v0, 0x70($s0)
.L802180B4:
/* 52B754 802180B4 0000202D */  daddu     $a0, $zero, $zero
/* 52B758 802180B8 0080282D */  daddu     $a1, $a0, $zero
/* 52B75C 802180BC 8E020070 */  lw        $v0, 0x70($s0)
/* 52B760 802180C0 0080302D */  daddu     $a2, $a0, $zero
/* 52B764 802180C4 00023880 */  sll       $a3, $v0, 2
/* 52B768 802180C8 00E23821 */  addu      $a3, $a3, $v0
/* 52B76C 802180CC 00073840 */  sll       $a3, $a3, 1
/* 52B770 802180D0 0C046F97 */  jal       set_background_color_blend
/* 52B774 802180D4 30E700FE */   andi     $a3, $a3, 0xfe
/* 52B778 802180D8 8E020070 */  lw        $v0, 0x70($s0)
/* 52B77C 802180DC 2442FFFF */  addiu     $v0, $v0, -1
/* 52B780 802180E0 10400003 */  beqz      $v0, .L802180F0
/* 52B784 802180E4 AE020070 */   sw       $v0, 0x70($s0)
/* 52B788 802180E8 08086042 */  j         .L80218108
/* 52B78C 802180EC 0000102D */   daddu    $v0, $zero, $zero
.L802180F0:
/* 52B790 802180F0 0000202D */  daddu     $a0, $zero, $zero
/* 52B794 802180F4 0080282D */  daddu     $a1, $a0, $zero
/* 52B798 802180F8 0080302D */  daddu     $a2, $a0, $zero
/* 52B79C 802180FC 0C046F97 */  jal       set_background_color_blend
/* 52B7A0 80218100 0080382D */   daddu    $a3, $a0, $zero
/* 52B7A4 80218104 24020002 */  addiu     $v0, $zero, 2
.L80218108:
/* 52B7A8 80218108 8FBF0014 */  lw        $ra, 0x14($sp)
/* 52B7AC 8021810C 8FB00010 */  lw        $s0, 0x10($sp)
/* 52B7B0 80218110 03E00008 */  jr        $ra
/* 52B7B4 80218114 27BD0018 */   addiu    $sp, $sp, 0x18
/* 52B7B8 80218118 00000000 */  nop       
/* 52B7BC 8021811C 00000000 */  nop       
