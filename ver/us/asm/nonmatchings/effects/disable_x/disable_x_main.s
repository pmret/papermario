.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel disable_x_main
/* 385640 E0082000 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 385644 E0082004 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 385648 E0082008 4485A000 */  mtc1      $a1, $f20
/* 38564C E008200C AFB00028 */  sw        $s0, 0x28($sp)
/* 385650 E0082010 0080802D */  daddu     $s0, $a0, $zero
/* 385654 E0082014 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 385658 E0082018 4486B000 */  mtc1      $a2, $f22
/* 38565C E008201C 27A40010 */  addiu     $a0, $sp, 0x10
/* 385660 E0082020 F7B80048 */  sdc1      $f24, 0x48($sp)
/* 385664 E0082024 4487C000 */  mtc1      $a3, $f24
/* 385668 E0082028 3C02E008 */  lui       $v0, %hi(disable_x_init)
/* 38566C E008202C 244221B0 */  addiu     $v0, $v0, %lo(disable_x_init)
/* 385670 E0082030 AFA20018 */  sw        $v0, 0x18($sp)
/* 385674 E0082034 3C02E008 */  lui       $v0, %hi(disable_x_update)
/* 385678 E0082038 244221B8 */  addiu     $v0, $v0, %lo(disable_x_update)
/* 38567C E008203C AFA2001C */  sw        $v0, 0x1c($sp)
/* 385680 E0082040 3C02E008 */  lui       $v0, %hi(disable_x_render)
/* 385684 E0082044 24422520 */  addiu     $v0, $v0, %lo(disable_x_render)
/* 385688 E0082048 AFA20020 */  sw        $v0, 0x20($sp)
/* 38568C E008204C 3C02E008 */  lui       $v0, %hi(func_E0082528)
/* 385690 E0082050 24422528 */  addiu     $v0, $v0, %lo(func_E0082528)
/* 385694 E0082054 AFA20024 */  sw        $v0, 0x24($sp)
/* 385698 E0082058 24020041 */  addiu     $v0, $zero, 0x41
/* 38569C E008205C AFBF0034 */  sw        $ra, 0x34($sp)
/* 3856A0 E0082060 AFB20030 */  sw        $s2, 0x30($sp)
/* 3856A4 E0082064 AFB1002C */  sw        $s1, 0x2c($sp)
/* 3856A8 E0082068 AFA00010 */  sw        $zero, 0x10($sp)
/* 3856AC E008206C 0C080124 */  jal       shim_create_effect_instance
/* 3856B0 E0082070 AFA20014 */   sw       $v0, 0x14($sp)
/* 3856B4 E0082074 24040090 */  addiu     $a0, $zero, 0x90
/* 3856B8 E0082078 24120002 */  addiu     $s2, $zero, 2
/* 3856BC E008207C 0040882D */  daddu     $s1, $v0, $zero
/* 3856C0 E0082080 0C08012C */  jal       shim_general_heap_malloc
/* 3856C4 E0082084 AE320008 */   sw       $s2, 8($s1)
/* 3856C8 E0082088 0040182D */  daddu     $v1, $v0, $zero
/* 3856CC E008208C 14600003 */  bnez      $v1, .LE008209C
/* 3856D0 E0082090 AE23000C */   sw       $v1, 0xc($s1)
.LE0082094:
/* 3856D4 E0082094 08020825 */  j         .LE0082094
/* 3856D8 E0082098 00000000 */   nop
.LE008209C:
/* 3856DC E008209C 3C013F80 */  lui       $at, 0x3f80
/* 3856E0 E00820A0 44810000 */  mtc1      $at, $f0
/* 3856E4 E00820A4 24020001 */  addiu     $v0, $zero, 1
/* 3856E8 E00820A8 AC700000 */  sw        $s0, ($v1)
/* 3856EC E00820AC 16020004 */  bne       $s0, $v0, .LE00820C0
/* 3856F0 E00820B0 E4600034 */   swc1     $f0, 0x34($v1)
/* 3856F4 E00820B4 AC700038 */  sw        $s0, 0x38($v1)
/* 3856F8 E00820B8 08020834 */  j         .LE00820D0
/* 3856FC E00820BC AC60003C */   sw       $zero, 0x3c($v1)
.LE00820C0:
/* 385700 E00820C0 AC600038 */  sw        $zero, 0x38($v1)
/* 385704 E00820C4 8FA20060 */  lw        $v0, 0x60($sp)
/* 385708 E00820C8 AC62003C */  sw        $v0, 0x3c($v1)
/* 38570C E00820CC 24020001 */  addiu     $v0, $zero, 1
.LE00820D0:
/* 385710 E00820D0 E4740008 */  swc1      $f20, 8($v1)
/* 385714 E00820D4 E476000C */  swc1      $f22, 0xc($v1)
/* 385718 E00820D8 1202000E */  beq       $s0, $v0, .LE0082114
/* 38571C E00820DC E4780010 */   swc1     $f24, 0x10($v1)
/* 385720 E00820E0 2A020002 */  slti      $v0, $s0, 2
/* 385724 E00820E4 10400005 */  beqz      $v0, .LE00820FC
/* 385728 E00820E8 2402000A */   addiu    $v0, $zero, 0xa
/* 38572C E00820EC 12000007 */  beqz      $s0, .LE008210C
/* 385730 E00820F0 24020001 */   addiu    $v0, $zero, 1
/* 385734 E00820F4 0802084B */  j         .LE008212C
/* 385738 E00820F8 AC60002C */   sw       $zero, 0x2c($v1)
.LE00820FC:
/* 38573C E00820FC 12020007 */  beq       $s0, $v0, .LE008211C
/* 385740 E0082100 24020001 */   addiu    $v0, $zero, 1
/* 385744 E0082104 0802084B */  j         .LE008212C
/* 385748 E0082108 AC60002C */   sw       $zero, 0x2c($v1)
.LE008210C:
/* 38574C E008210C 08020848 */  j         .LE0082120
/* 385750 E0082110 24020064 */   addiu    $v0, $zero, 0x64
.LE0082114:
/* 385754 E0082114 08020848 */  j         .LE0082120
/* 385758 E0082118 24020064 */   addiu    $v0, $zero, 0x64
.LE008211C:
/* 38575C E008211C 24020015 */  addiu     $v0, $zero, 0x15
.LE0082120:
/* 385760 E0082120 AC620028 */  sw        $v0, 0x28($v1)
/* 385764 E0082124 24020001 */  addiu     $v0, $zero, 1
/* 385768 E0082128 AC60002C */  sw        $zero, 0x2c($v1)
.LE008212C:
/* 38576C E008212C AC600044 */  sw        $zero, 0x44($v1)
/* 385770 E0082130 AC620004 */  sw        $v0, 4($v1)
/* 385774 E0082134 0040202D */  daddu     $a0, $v0, $zero
/* 385778 E0082138 0092102A */  slt       $v0, $a0, $s2
/* 38577C E008213C 10400012 */  beqz      $v0, .LE0082188
/* 385780 E0082140 24630048 */   addiu    $v1, $v1, 0x48
/* 385784 E0082144 44800000 */  mtc1      $zero, $f0
/* 385788 E0082148 240500FF */  addiu     $a1, $zero, 0xff
/* 38578C E008214C 24630024 */  addiu     $v1, $v1, 0x24
.LE0082150:
/* 385790 E0082150 24840001 */  addiu     $a0, $a0, 1
/* 385794 E0082154 E460FFEC */  swc1      $f0, -0x14($v1)
/* 385798 E0082158 E460FFE8 */  swc1      $f0, -0x18($v1)
/* 38579C E008215C E460FFE4 */  swc1      $f0, -0x1c($v1)
/* 3857A0 E0082160 E460FFFC */  swc1      $f0, -4($v1)
/* 3857A4 E0082164 E460FFF8 */  swc1      $f0, -8($v1)
/* 3857A8 E0082168 E460FFF4 */  swc1      $f0, -0xc($v1)
/* 3857AC E008216C E460FFF0 */  swc1      $f0, -0x10($v1)
/* 3857B0 E0082170 E460001C */  swc1      $f0, 0x1c($v1)
/* 3857B4 E0082174 AC600004 */  sw        $zero, 4($v1)
/* 3857B8 E0082178 AC650000 */  sw        $a1, ($v1)
/* 3857BC E008217C 0092102A */  slt       $v0, $a0, $s2
/* 3857C0 E0082180 1440FFF3 */  bnez      $v0, .LE0082150
/* 3857C4 E0082184 24630048 */   addiu    $v1, $v1, 0x48
.LE0082188:
/* 3857C8 E0082188 0220102D */  daddu     $v0, $s1, $zero
/* 3857CC E008218C 8FBF0034 */  lw        $ra, 0x34($sp)
/* 3857D0 E0082190 8FB20030 */  lw        $s2, 0x30($sp)
/* 3857D4 E0082194 8FB1002C */  lw        $s1, 0x2c($sp)
/* 3857D8 E0082198 8FB00028 */  lw        $s0, 0x28($sp)
/* 3857DC E008219C D7B80048 */  ldc1      $f24, 0x48($sp)
/* 3857E0 E00821A0 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 3857E4 E00821A4 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 3857E8 E00821A8 03E00008 */  jr        $ra
/* 3857EC E00821AC 27BD0050 */   addiu    $sp, $sp, 0x50
