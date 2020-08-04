.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddPartDispOffset
/* 19A668 8026BD88 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 19A66C 8026BD8C AFB20018 */  sw    $s2, 0x18($sp)
/* 19A670 8026BD90 0080902D */  daddu $s2, $a0, $zero
/* 19A674 8026BD94 AFBF0020 */  sw    $ra, 0x20($sp)
/* 19A678 8026BD98 AFB3001C */  sw    $s3, 0x1c($sp)
/* 19A67C 8026BD9C AFB10014 */  sw    $s1, 0x14($sp)
/* 19A680 8026BDA0 AFB00010 */  sw    $s0, 0x10($sp)
/* 19A684 8026BDA4 F7B80038 */  sdc1  $f24, 0x38($sp)
/* 19A688 8026BDA8 F7B60030 */  sdc1  $f22, 0x30($sp)
/* 19A68C 8026BDAC F7B40028 */  sdc1  $f20, 0x28($sp)
/* 19A690 8026BDB0 8E51000C */  lw    $s1, 0xc($s2)
/* 19A694 8026BDB4 8E250000 */  lw    $a1, ($s1)
/* 19A698 8026BDB8 0C0B1EAF */  jal   get_variable
/* 19A69C 8026BDBC 26310004 */   addiu $s1, $s1, 4
/* 19A6A0 8026BDC0 0040982D */  daddu $s3, $v0, $zero
/* 19A6A4 8026BDC4 2402FF81 */  addiu $v0, $zero, -0x7f
/* 19A6A8 8026BDC8 16620002 */  bne   $s3, $v0, .L8026BDD4
/* 19A6AC 8026BDCC 00000000 */   nop   
/* 19A6B0 8026BDD0 8E530148 */  lw    $s3, 0x148($s2)
.L8026BDD4:
/* 19A6B4 8026BDD4 8E250000 */  lw    $a1, ($s1)
/* 19A6B8 8026BDD8 26310004 */  addiu $s1, $s1, 4
/* 19A6BC 8026BDDC 0C0B1EAF */  jal   get_variable
/* 19A6C0 8026BDE0 0240202D */   daddu $a0, $s2, $zero
/* 19A6C4 8026BDE4 8E250000 */  lw    $a1, ($s1)
/* 19A6C8 8026BDE8 26310004 */  addiu $s1, $s1, 4
/* 19A6CC 8026BDEC 0240202D */  daddu $a0, $s2, $zero
/* 19A6D0 8026BDF0 0C0B210B */  jal   get_float_variable
/* 19A6D4 8026BDF4 0040802D */   daddu $s0, $v0, $zero
/* 19A6D8 8026BDF8 8E250000 */  lw    $a1, ($s1)
/* 19A6DC 8026BDFC 26310004 */  addiu $s1, $s1, 4
/* 19A6E0 8026BE00 0240202D */  daddu $a0, $s2, $zero
/* 19A6E4 8026BE04 0C0B210B */  jal   get_float_variable
/* 19A6E8 8026BE08 46000506 */   mov.s $f20, $f0
/* 19A6EC 8026BE0C 0240202D */  daddu $a0, $s2, $zero
/* 19A6F0 8026BE10 8E250000 */  lw    $a1, ($s1)
/* 19A6F4 8026BE14 0C0B210B */  jal   get_float_variable
/* 19A6F8 8026BE18 46000586 */   mov.s $f22, $f0
/* 19A6FC 8026BE1C 0260202D */  daddu $a0, $s3, $zero
/* 19A700 8026BE20 0C09A75B */  jal   get_actor
/* 19A704 8026BE24 46000606 */   mov.s $f24, $f0
/* 19A708 8026BE28 0040202D */  daddu $a0, $v0, $zero
/* 19A70C 8026BE2C 0C099117 */  jal   get_actor_part
/* 19A710 8026BE30 0200282D */   daddu $a1, $s0, $zero
/* 19A714 8026BE34 0040202D */  daddu $a0, $v0, $zero
/* 19A718 8026BE38 8C820000 */  lw    $v0, ($a0)
/* 19A71C 8026BE3C 3C030010 */  lui   $v1, 0x10
/* 19A720 8026BE40 00431024 */  and   $v0, $v0, $v1
/* 19A724 8026BE44 1440001B */  bnez  $v0, .L8026BEB4
/* 19A728 8026BE48 00000000 */   nop   
/* 19A72C 8026BE4C 84820014 */  lh    $v0, 0x14($a0)
/* 19A730 8026BE50 44820000 */  mtc1  $v0, $f0
/* 19A734 8026BE54 00000000 */  nop   
/* 19A738 8026BE58 46800020 */  cvt.s.w $f0, $f0
/* 19A73C 8026BE5C 46140000 */  add.s $f0, $f0, $f20
/* 19A740 8026BE60 84820016 */  lh    $v0, 0x16($a0)
/* 19A744 8026BE64 44821000 */  mtc1  $v0, $f2
/* 19A748 8026BE68 00000000 */  nop   
/* 19A74C 8026BE6C 468010A0 */  cvt.s.w $f2, $f2
/* 19A750 8026BE70 46161080 */  add.s $f2, $f2, $f22
/* 19A754 8026BE74 84820018 */  lh    $v0, 0x18($a0)
/* 19A758 8026BE78 4600010D */  trunc.w.s $f4, $f0
/* 19A75C 8026BE7C 44032000 */  mfc1  $v1, $f4
/* 19A760 8026BE80 44820000 */  mtc1  $v0, $f0
/* 19A764 8026BE84 00000000 */  nop   
/* 19A768 8026BE88 46800020 */  cvt.s.w $f0, $f0
/* 19A76C 8026BE8C 46180000 */  add.s $f0, $f0, $f24
/* 19A770 8026BE90 A4830014 */  sh    $v1, 0x14($a0)
/* 19A774 8026BE94 4600110D */  trunc.w.s $f4, $f2
/* 19A778 8026BE98 44022000 */  mfc1  $v0, $f4
/* 19A77C 8026BE9C 00000000 */  nop   
/* 19A780 8026BEA0 A4820016 */  sh    $v0, 0x16($a0)
/* 19A784 8026BEA4 4600010D */  trunc.w.s $f4, $f0
/* 19A788 8026BEA8 44022000 */  mfc1  $v0, $f4
/* 19A78C 8026BEAC 0809AFC7 */  j     .L8026BF1C
/* 19A790 8026BEB0 A4820018 */   sh    $v0, 0x18($a0)

.L8026BEB4:
/* 19A794 8026BEB4 8482001A */  lh    $v0, 0x1a($a0)
/* 19A798 8026BEB8 44820000 */  mtc1  $v0, $f0
/* 19A79C 8026BEBC 00000000 */  nop   
/* 19A7A0 8026BEC0 46800020 */  cvt.s.w $f0, $f0
/* 19A7A4 8026BEC4 46140000 */  add.s $f0, $f0, $f20
/* 19A7A8 8026BEC8 8482001C */  lh    $v0, 0x1c($a0)
/* 19A7AC 8026BECC 44821000 */  mtc1  $v0, $f2
/* 19A7B0 8026BED0 00000000 */  nop   
/* 19A7B4 8026BED4 468010A0 */  cvt.s.w $f2, $f2
/* 19A7B8 8026BED8 46161080 */  add.s $f2, $f2, $f22
/* 19A7BC 8026BEDC 8482001E */  lh    $v0, 0x1e($a0)
/* 19A7C0 8026BEE0 4600010D */  trunc.w.s $f4, $f0
/* 19A7C4 8026BEE4 44032000 */  mfc1  $v1, $f4
/* 19A7C8 8026BEE8 44820000 */  mtc1  $v0, $f0
/* 19A7CC 8026BEEC 00000000 */  nop   
/* 19A7D0 8026BEF0 46800020 */  cvt.s.w $f0, $f0
/* 19A7D4 8026BEF4 46180000 */  add.s $f0, $f0, $f24
/* 19A7D8 8026BEF8 A483001A */  sh    $v1, 0x1a($a0)
/* 19A7DC 8026BEFC 4600110D */  trunc.w.s $f4, $f2
/* 19A7E0 8026BF00 44022000 */  mfc1  $v0, $f4
/* 19A7E4 8026BF04 00000000 */  nop   
/* 19A7E8 8026BF08 A482001C */  sh    $v0, 0x1c($a0)
/* 19A7EC 8026BF0C 4600010D */  trunc.w.s $f4, $f0
/* 19A7F0 8026BF10 44022000 */  mfc1  $v0, $f4
/* 19A7F4 8026BF14 00000000 */  nop   
/* 19A7F8 8026BF18 A482001E */  sh    $v0, 0x1e($a0)
.L8026BF1C:
/* 19A7FC 8026BF1C 8FBF0020 */  lw    $ra, 0x20($sp)
/* 19A800 8026BF20 8FB3001C */  lw    $s3, 0x1c($sp)
/* 19A804 8026BF24 8FB20018 */  lw    $s2, 0x18($sp)
/* 19A808 8026BF28 8FB10014 */  lw    $s1, 0x14($sp)
/* 19A80C 8026BF2C 8FB00010 */  lw    $s0, 0x10($sp)
/* 19A810 8026BF30 D7B80038 */  ldc1  $f24, 0x38($sp)
/* 19A814 8026BF34 D7B60030 */  ldc1  $f22, 0x30($sp)
/* 19A818 8026BF38 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 19A81C 8026BF3C 24020002 */  addiu $v0, $zero, 2
/* 19A820 8026BF40 03E00008 */  jr    $ra
/* 19A824 8026BF44 27BD0040 */   addiu $sp, $sp, 0x40

/* 19A828 8026BF48 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 19A82C 8026BF4C AFBF0018 */  sw    $ra, 0x18($sp)
/* 19A830 8026BF50 AFB10014 */  sw    $s1, 0x14($sp)
/* 19A834 8026BF54 AFB00010 */  sw    $s0, 0x10($sp)
/* 19A838 8026BF58 8C82000C */  lw    $v0, 0xc($a0)
/* 19A83C 8026BF5C 3C10800E */  lui   $s0, 0x800e
/* 19A840 8026BF60 2610C070 */  addiu $s0, $s0, -0x3f90
/* 19A844 8026BF64 8C450000 */  lw    $a1, ($v0)
/* 19A848 8026BF68 0C0B1EAF */  jal   get_variable
/* 19A84C 8026BF6C 0200882D */   daddu $s1, $s0, $zero
/* 19A850 8026BF70 10400005 */  beqz  $v0, .L8026BF88
/* 19A854 8026BF74 00000000 */   nop   
/* 19A858 8026BF78 9202008C */  lbu   $v0, 0x8c($s0)
/* 19A85C 8026BF7C 24420001 */  addiu $v0, $v0, 1
/* 19A860 8026BF80 0809AFE7 */  j     .L8026BF9C
/* 19A864 8026BF84 A202008C */   sb    $v0, 0x8c($s0)

.L8026BF88:
/* 19A868 8026BF88 8222008C */  lb    $v0, 0x8c($s1)
/* 19A86C 8026BF8C 9223008C */  lbu   $v1, 0x8c($s1)
/* 19A870 8026BF90 18400002 */  blez  $v0, .L8026BF9C
/* 19A874 8026BF94 2462FFFF */   addiu $v0, $v1, -1
/* 19A878 8026BF98 A222008C */  sb    $v0, 0x8c($s1)
.L8026BF9C:
.L8026BF9C:
/* 19A87C 8026BF9C 8FBF0018 */  lw    $ra, 0x18($sp)
/* 19A880 8026BFA0 8FB10014 */  lw    $s1, 0x14($sp)
/* 19A884 8026BFA4 8FB00010 */  lw    $s0, 0x10($sp)
/* 19A888 8026BFA8 24020002 */  addiu $v0, $zero, 2
/* 19A88C 8026BFAC 03E00008 */  jr    $ra
/* 19A890 8026BFB0 27BD0020 */   addiu $sp, $sp, 0x20

