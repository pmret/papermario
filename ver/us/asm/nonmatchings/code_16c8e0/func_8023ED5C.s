.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8023ED5C
/* 16D63C 8023ED5C 3C02800E */  lui       $v0, %hi(gBattleState)
/* 16D640 8023ED60 8C42C068 */  lw        $v0, %lo(gBattleState)($v0)
/* 16D644 8023ED64 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 16D648 8023ED68 AFB40030 */  sw        $s4, 0x30($sp)
/* 16D64C 8023ED6C 3C14800E */  lui       $s4, %hi(gBattleStatus)
/* 16D650 8023ED70 2694C070 */  addiu     $s4, $s4, %lo(gBattleStatus)
/* 16D654 8023ED74 AFB00020 */  sw        $s0, 0x20($sp)
/* 16D658 8023ED78 27B00010 */  addiu     $s0, $sp, 0x10
/* 16D65C 8023ED7C AFBF0040 */  sw        $ra, 0x40($sp)
/* 16D660 8023ED80 AFB7003C */  sw        $s7, 0x3c($sp)
/* 16D664 8023ED84 AFB60038 */  sw        $s6, 0x38($sp)
/* 16D668 8023ED88 AFB50034 */  sw        $s5, 0x34($sp)
/* 16D66C 8023ED8C AFB3002C */  sw        $s3, 0x2c($sp)
/* 16D670 8023ED90 AFB20028 */  sw        $s2, 0x28($sp)
/* 16D674 8023ED94 104000A7 */  beqz      $v0, .L8023F034
/* 16D678 8023ED98 AFB10024 */   sw       $s1, 0x24($sp)
/* 16D67C 8023ED9C 0C093BAA */  jal       func_8024EEA8
/* 16D680 8023EDA0 00000000 */   nop
/* 16D684 8023EDA4 8E8200B8 */  lw        $v0, 0xb8($s4)
/* 16D688 8023EDA8 10400003 */  beqz      $v0, .L8023EDB8
/* 16D68C 8023EDAC 00000000 */   nop
/* 16D690 8023EDB0 0040F809 */  jalr      $v0
/* 16D694 8023EDB4 00000000 */   nop
.L8023EDB8:
/* 16D698 8023EDB8 8E820000 */  lw        $v0, ($s4)
/* 16D69C 8023EDBC 30420001 */  andi      $v0, $v0, 1
/* 16D6A0 8023EDC0 1040009C */  beqz      $v0, .L8023F034
/* 16D6A4 8023EDC4 00000000 */   nop
/* 16D6A8 8023EDC8 0C0957F6 */  jal       func_80255FD8
/* 16D6AC 8023EDCC 00000000 */   nop
/* 16D6B0 8023EDD0 3C02800A */  lui       $v0, %hi(D_8009A634)
/* 16D6B4 8023EDD4 9442A634 */  lhu       $v0, %lo(D_8009A634)($v0)
/* 16D6B8 8023EDD8 2442FFFF */  addiu     $v0, $v0, -1
/* 16D6BC 8023EDDC 2C420002 */  sltiu     $v0, $v0, 2
/* 16D6C0 8023EDE0 10400094 */  beqz      $v0, .L8023F034
/* 16D6C4 8023EDE4 0000902D */   daddu    $s2, $zero, $zero
/* 16D6C8 8023EDE8 3C178025 */  lui       $s7, %hi(D_80257B28)
/* 16D6CC 8023EDEC 26F77B28 */  addiu     $s7, $s7, %lo(D_80257B28)
/* 16D6D0 8023EDF0 3C161000 */  lui       $s6, 0x1000
/* 16D6D4 8023EDF4 3C158025 */  lui       $s5, %hi(D_8025595C)
/* 16D6D8 8023EDF8 26B5595C */  addiu     $s5, $s5, %lo(D_8025595C)
/* 16D6DC 8023EDFC 0280982D */  daddu     $s3, $s4, $zero
.L8023EE00:
/* 16D6E0 8023EE00 8E7100E0 */  lw        $s1, 0xe0($s3)
/* 16D6E4 8023EE04 5220002A */  beql      $s1, $zero, .L8023EEB0
/* 16D6E8 8023EE08 26520001 */   addiu    $s2, $s2, 1
/* 16D6EC 8023EE0C 8E220000 */  lw        $v0, ($s1)
/* 16D6F0 8023EE10 30420001 */  andi      $v0, $v0, 1
/* 16D6F4 8023EE14 54400026 */  bnel      $v0, $zero, .L8023EEB0
/* 16D6F8 8023EE18 26520001 */   addiu    $s2, $s2, 1
/* 16D6FC 8023EE1C AE120008 */  sw        $s2, 8($s0)
/* 16D700 8023EE20 AE17000C */  sw        $s7, 0xc($s0)
/* 16D704 8023EE24 C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D708 8023EE28 4600008D */  trunc.w.s $f2, $f0
/* 16D70C 8023EE2C E6020004 */  swc1      $f2, 4($s0)
/* 16D710 8023EE30 86220434 */  lh        $v0, 0x434($s1)
/* 16D714 8023EE34 0200202D */  daddu     $a0, $s0, $zero
/* 16D718 8023EE38 0C047644 */  jal       queue_render_task
/* 16D71C 8023EE3C AE020000 */   sw       $v0, ($s0)
/* 16D720 8023EE40 8E220000 */  lw        $v0, ($s1)
/* 16D724 8023EE44 00561024 */  and       $v0, $v0, $s6
/* 16D728 8023EE48 10400009 */  beqz      $v0, .L8023EE70
/* 16D72C 8023EE4C 24020022 */   addiu    $v0, $zero, 0x22
/* 16D730 8023EE50 AE110008 */  sw        $s1, 8($s0)
/* 16D734 8023EE54 AE15000C */  sw        $s5, 0xc($s0)
/* 16D738 8023EE58 C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D73C 8023EE5C AE020000 */  sw        $v0, ($s0)
/* 16D740 8023EE60 4600008D */  trunc.w.s $f2, $f0
/* 16D744 8023EE64 E6020004 */  swc1      $f2, 4($s0)
/* 16D748 8023EE68 0C047644 */  jal       queue_render_task
/* 16D74C 8023EE6C 0200202D */   daddu    $a0, $s0, $zero
.L8023EE70:
/* 16D750 8023EE70 92820092 */  lbu       $v0, 0x92($s4)
/* 16D754 8023EE74 30420001 */  andi      $v0, $v0, 1
/* 16D758 8023EE78 5040000D */  beql      $v0, $zero, .L8023EEB0
/* 16D75C 8023EE7C 26520001 */   addiu    $s2, $s2, 1
/* 16D760 8023EE80 3C028025 */  lui       $v0, %hi(D_80257B68)
/* 16D764 8023EE84 24427B68 */  addiu     $v0, $v0, %lo(D_80257B68)
/* 16D768 8023EE88 AE110008 */  sw        $s1, 8($s0)
/* 16D76C 8023EE8C AE02000C */  sw        $v0, 0xc($s0)
/* 16D770 8023EE90 C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D774 8023EE94 4600008D */  trunc.w.s $f2, $f0
/* 16D778 8023EE98 E6020004 */  swc1      $f2, 4($s0)
/* 16D77C 8023EE9C 86220434 */  lh        $v0, 0x434($s1)
/* 16D780 8023EEA0 0200202D */  daddu     $a0, $s0, $zero
/* 16D784 8023EEA4 0C047644 */  jal       queue_render_task
/* 16D788 8023EEA8 AE020000 */   sw       $v0, ($s0)
/* 16D78C 8023EEAC 26520001 */  addiu     $s2, $s2, 1
.L8023EEB0:
/* 16D790 8023EEB0 2A420018 */  slti      $v0, $s2, 0x18
/* 16D794 8023EEB4 1440FFD2 */  bnez      $v0, .L8023EE00
/* 16D798 8023EEB8 26730004 */   addiu    $s3, $s3, 4
/* 16D79C 8023EEBC 8E9100DC */  lw        $s1, 0xdc($s4)
/* 16D7A0 8023EEC0 1220002D */  beqz      $s1, .L8023EF78
/* 16D7A4 8023EEC4 00000000 */   nop
/* 16D7A8 8023EEC8 8E220000 */  lw        $v0, ($s1)
/* 16D7AC 8023EECC 30420001 */  andi      $v0, $v0, 1
/* 16D7B0 8023EED0 14400029 */  bnez      $v0, .L8023EF78
/* 16D7B4 8023EED4 0200202D */   daddu    $a0, $s0, $zero
/* 16D7B8 8023EED8 3C028025 */  lui       $v0, %hi(D_80257B48)
/* 16D7BC 8023EEDC 24427B48 */  addiu     $v0, $v0, %lo(D_80257B48)
/* 16D7C0 8023EEE0 AE000008 */  sw        $zero, 8($s0)
/* 16D7C4 8023EEE4 AE02000C */  sw        $v0, 0xc($s0)
/* 16D7C8 8023EEE8 C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D7CC 8023EEEC 4600008D */  trunc.w.s $f2, $f0
/* 16D7D0 8023EEF0 E6020004 */  swc1      $f2, 4($s0)
/* 16D7D4 8023EEF4 86220434 */  lh        $v0, 0x434($s1)
/* 16D7D8 8023EEF8 0C047644 */  jal       queue_render_task
/* 16D7DC 8023EEFC AE020000 */   sw       $v0, ($s0)
/* 16D7E0 8023EF00 8E220000 */  lw        $v0, ($s1)
/* 16D7E4 8023EF04 3C031000 */  lui       $v1, 0x1000
/* 16D7E8 8023EF08 00431024 */  and       $v0, $v0, $v1
/* 16D7EC 8023EF0C 1040000C */  beqz      $v0, .L8023EF40
/* 16D7F0 8023EF10 00000000 */   nop
/* 16D7F4 8023EF14 3C028025 */  lui       $v0, %hi(D_8025599C)
/* 16D7F8 8023EF18 2442599C */  addiu     $v0, $v0, %lo(D_8025599C)
/* 16D7FC 8023EF1C AE110008 */  sw        $s1, 8($s0)
/* 16D800 8023EF20 AE02000C */  sw        $v0, 0xc($s0)
/* 16D804 8023EF24 C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D808 8023EF28 24020022 */  addiu     $v0, $zero, 0x22
/* 16D80C 8023EF2C AE020000 */  sw        $v0, ($s0)
/* 16D810 8023EF30 4600008D */  trunc.w.s $f2, $f0
/* 16D814 8023EF34 E6020004 */  swc1      $f2, 4($s0)
/* 16D818 8023EF38 0C047644 */  jal       queue_render_task
/* 16D81C 8023EF3C 0200202D */   daddu    $a0, $s0, $zero
.L8023EF40:
/* 16D820 8023EF40 92820092 */  lbu       $v0, 0x92($s4)
/* 16D824 8023EF44 30420001 */  andi      $v0, $v0, 1
/* 16D828 8023EF48 1040000B */  beqz      $v0, .L8023EF78
/* 16D82C 8023EF4C 0200202D */   daddu    $a0, $s0, $zero
/* 16D830 8023EF50 3C028025 */  lui       $v0, %hi(D_80257B88)
/* 16D834 8023EF54 24427B88 */  addiu     $v0, $v0, %lo(D_80257B88)
/* 16D838 8023EF58 AE000008 */  sw        $zero, 8($s0)
/* 16D83C 8023EF5C AE02000C */  sw        $v0, 0xc($s0)
/* 16D840 8023EF60 C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D844 8023EF64 4600008D */  trunc.w.s $f2, $f0
/* 16D848 8023EF68 E6020004 */  swc1      $f2, 4($s0)
/* 16D84C 8023EF6C 86220434 */  lh        $v0, 0x434($s1)
/* 16D850 8023EF70 0C047644 */  jal       queue_render_task
/* 16D854 8023EF74 AE020000 */   sw       $v0, ($s0)
.L8023EF78:
/* 16D858 8023EF78 8E9100D8 */  lw        $s1, 0xd8($s4)
/* 16D85C 8023EF7C 1220002D */  beqz      $s1, .L8023F034
/* 16D860 8023EF80 00000000 */   nop
/* 16D864 8023EF84 8E220000 */  lw        $v0, ($s1)
/* 16D868 8023EF88 30420001 */  andi      $v0, $v0, 1
/* 16D86C 8023EF8C 14400029 */  bnez      $v0, .L8023F034
/* 16D870 8023EF90 0200202D */   daddu    $a0, $s0, $zero
/* 16D874 8023EF94 3C028025 */  lui       $v0, %hi(D_80257DA4)
/* 16D878 8023EF98 24427DA4 */  addiu     $v0, $v0, %lo(D_80257DA4)
/* 16D87C 8023EF9C AE000008 */  sw        $zero, 8($s0)
/* 16D880 8023EFA0 AE02000C */  sw        $v0, 0xc($s0)
/* 16D884 8023EFA4 C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D888 8023EFA8 4600008D */  trunc.w.s $f2, $f0
/* 16D88C 8023EFAC E6020004 */  swc1      $f2, 4($s0)
/* 16D890 8023EFB0 86220434 */  lh        $v0, 0x434($s1)
/* 16D894 8023EFB4 0C047644 */  jal       queue_render_task
/* 16D898 8023EFB8 AE020000 */   sw       $v0, ($s0)
/* 16D89C 8023EFBC 8E220000 */  lw        $v0, ($s1)
/* 16D8A0 8023EFC0 3C031000 */  lui       $v1, 0x1000
/* 16D8A4 8023EFC4 00431024 */  and       $v0, $v0, $v1
/* 16D8A8 8023EFC8 1040000C */  beqz      $v0, .L8023EFFC
/* 16D8AC 8023EFCC 00000000 */   nop
/* 16D8B0 8023EFD0 3C028025 */  lui       $v0, %hi(D_80254C50)
/* 16D8B4 8023EFD4 24424C50 */  addiu     $v0, $v0, %lo(D_80254C50)
/* 16D8B8 8023EFD8 AE110008 */  sw        $s1, 8($s0)
/* 16D8BC 8023EFDC AE02000C */  sw        $v0, 0xc($s0)
/* 16D8C0 8023EFE0 C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D8C4 8023EFE4 24020022 */  addiu     $v0, $zero, 0x22
/* 16D8C8 8023EFE8 AE020000 */  sw        $v0, ($s0)
/* 16D8CC 8023EFEC 4600008D */  trunc.w.s $f2, $f0
/* 16D8D0 8023EFF0 E6020004 */  swc1      $f2, 4($s0)
/* 16D8D4 8023EFF4 0C047644 */  jal       queue_render_task
/* 16D8D8 8023EFF8 0200202D */   daddu    $a0, $s0, $zero
.L8023EFFC:
/* 16D8DC 8023EFFC 92820092 */  lbu       $v0, 0x92($s4)
/* 16D8E0 8023F000 30420001 */  andi      $v0, $v0, 1
/* 16D8E4 8023F004 1040000B */  beqz      $v0, .L8023F034
/* 16D8E8 8023F008 0200202D */   daddu    $a0, $s0, $zero
/* 16D8EC 8023F00C 3C028026 */  lui       $v0, %hi(D_80258E14)
/* 16D8F0 8023F010 24428E14 */  addiu     $v0, $v0, %lo(D_80258E14)
/* 16D8F4 8023F014 AE000008 */  sw        $zero, 8($s0)
/* 16D8F8 8023F018 AE02000C */  sw        $v0, 0xc($s0)
/* 16D8FC 8023F01C C620014C */  lwc1      $f0, 0x14c($s1)
/* 16D900 8023F020 4600008D */  trunc.w.s $f2, $f0
/* 16D904 8023F024 E6020004 */  swc1      $f2, 4($s0)
/* 16D908 8023F028 86220434 */  lh        $v0, 0x434($s1)
/* 16D90C 8023F02C 0C047644 */  jal       queue_render_task
/* 16D910 8023F030 AC820000 */   sw       $v0, ($a0)
.L8023F034:
/* 16D914 8023F034 8FBF0040 */  lw        $ra, 0x40($sp)
/* 16D918 8023F038 8FB7003C */  lw        $s7, 0x3c($sp)
/* 16D91C 8023F03C 8FB60038 */  lw        $s6, 0x38($sp)
/* 16D920 8023F040 8FB50034 */  lw        $s5, 0x34($sp)
/* 16D924 8023F044 8FB40030 */  lw        $s4, 0x30($sp)
/* 16D928 8023F048 8FB3002C */  lw        $s3, 0x2c($sp)
/* 16D92C 8023F04C 8FB20028 */  lw        $s2, 0x28($sp)
/* 16D930 8023F050 8FB10024 */  lw        $s1, 0x24($sp)
/* 16D934 8023F054 8FB00020 */  lw        $s0, 0x20($sp)
/* 16D938 8023F058 03E00008 */  jr        $ra
/* 16D93C 8023F05C 27BD0048 */   addiu    $sp, $sp, 0x48
