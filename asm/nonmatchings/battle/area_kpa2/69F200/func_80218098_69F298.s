.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218098_69F298
/* 69F298 80218098 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 69F29C 8021809C AFB00010 */  sw        $s0, 0x10($sp)
/* 69F2A0 802180A0 0080802D */  daddu     $s0, $a0, $zero
/* 69F2A4 802180A4 10A00003 */  beqz      $a1, .L802180B4
/* 69F2A8 802180A8 AFBF0014 */   sw       $ra, 0x14($sp)
/* 69F2AC 802180AC 24020014 */  addiu     $v0, $zero, 0x14
/* 69F2B0 802180B0 AE020070 */  sw        $v0, 0x70($s0)
.L802180B4:
/* 69F2B4 802180B4 0000202D */  daddu     $a0, $zero, $zero
/* 69F2B8 802180B8 0080282D */  daddu     $a1, $a0, $zero
/* 69F2BC 802180BC 8E020070 */  lw        $v0, 0x70($s0)
/* 69F2C0 802180C0 0080302D */  daddu     $a2, $a0, $zero
/* 69F2C4 802180C4 00023880 */  sll       $a3, $v0, 2
/* 69F2C8 802180C8 00E23821 */  addu      $a3, $a3, $v0
/* 69F2CC 802180CC 00073840 */  sll       $a3, $a3, 1
/* 69F2D0 802180D0 0C046F97 */  jal       set_background_color_blend
/* 69F2D4 802180D4 30E700FE */   andi     $a3, $a3, 0xfe
/* 69F2D8 802180D8 8E020070 */  lw        $v0, 0x70($s0)
/* 69F2DC 802180DC 2442FFFF */  addiu     $v0, $v0, -1
/* 69F2E0 802180E0 10400003 */  beqz      $v0, .L802180F0
/* 69F2E4 802180E4 AE020070 */   sw       $v0, 0x70($s0)
/* 69F2E8 802180E8 08086042 */  j         .L80218108
/* 69F2EC 802180EC 0000102D */   daddu    $v0, $zero, $zero
.L802180F0:
/* 69F2F0 802180F0 0000202D */  daddu     $a0, $zero, $zero
/* 69F2F4 802180F4 0080282D */  daddu     $a1, $a0, $zero
/* 69F2F8 802180F8 0080302D */  daddu     $a2, $a0, $zero
/* 69F2FC 802180FC 0C046F97 */  jal       set_background_color_blend
/* 69F300 80218100 0080382D */   daddu    $a3, $a0, $zero
/* 69F304 80218104 24020002 */  addiu     $v0, $zero, 2
.L80218108:
/* 69F308 80218108 8FBF0014 */  lw        $ra, 0x14($sp)
/* 69F30C 8021810C 8FB00010 */  lw        $s0, 0x10($sp)
/* 69F310 80218110 03E00008 */  jr        $ra
/* 69F314 80218114 27BD0018 */   addiu    $sp, $sp, 0x18
/* 69F318 80218118 00000000 */  nop       
/* 69F31C 8021811C 00000000 */  nop       
