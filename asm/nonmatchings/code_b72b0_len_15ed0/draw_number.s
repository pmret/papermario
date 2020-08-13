.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel draw_number
/* 0BDD9C 8012769C 27BDFF38 */  addiu $sp, $sp, -0xc8
/* 0BDDA0 801276A0 AFB200A8 */  sw    $s2, 0xa8($sp)
/* 0BDDA4 801276A4 AFB500B4 */  sw    $s5, 0xb4($sp)
/* 0BDDA8 801276A8 00E0A82D */  daddu $s5, $a3, $zero
/* 0BDDAC 801276AC 3C028015 */  lui   $v0, 0x8015
/* 0BDDB0 801276B0 2442C340 */  addiu $v0, $v0, -0x3cc0
/* 0BDDB4 801276B4 00151880 */  sll   $v1, $s5, 2
/* 0BDDB8 801276B8 00751821 */  addu  $v1, $v1, $s5
/* 0BDDBC 801276BC 00031880 */  sll   $v1, $v1, 2
/* 0BDDC0 801276C0 00621821 */  addu  $v1, $v1, $v0
/* 0BDDC4 801276C4 AFB400B0 */  sw    $s4, 0xb0($sp)
/* 0BDDC8 801276C8 24D4FFFE */  addiu $s4, $a2, -2
/* 0BDDCC 801276CC AFB100A4 */  sw    $s1, 0xa4($sp)
/* 0BDDD0 801276D0 97B100E2 */  lhu   $s1, 0xe2($sp)
/* 0BDDD4 801276D4 2E8200F1 */  sltiu $v0, $s4, 0xf1
/* 0BDDD8 801276D8 AFBF00C4 */  sw    $ra, 0xc4($sp)
/* 0BDDDC 801276DC AFBE00C0 */  sw    $fp, 0xc0($sp)
/* 0BDDE0 801276E0 AFB700BC */  sw    $s7, 0xbc($sp)
/* 0BDDE4 801276E4 AFB600B8 */  sw    $s6, 0xb8($sp)
/* 0BDDE8 801276E8 AFB300AC */  sw    $s3, 0xac($sp)
/* 0BDDEC 801276EC AFB000A0 */  sw    $s0, 0xa0($sp)
/* 0BDDF0 801276F0 8C7E0000 */  lw    $fp, ($v1)
/* 0BDDF4 801276F4 90770004 */  lbu   $s7, 4($v1)
/* 0BDDF8 801276F8 10400111 */  beqz  $v0, .L80127B40
/* 0BDDFC 801276FC 00A0902D */   daddu $s2, $a1, $zero
/* 0BDE00 80127700 27A50010 */  addiu $a1, $sp, 0x10
/* 0BDE04 80127704 0C00A531 */  jal   int_to_string
/* 0BDE08 80127708 2406000A */   addiu $a2, $zero, 0xa
/* 0BDE0C 8012770C 0000802D */  daddu $s0, $zero, $zero
/* 0BDE10 80127710 27A50010 */  addiu $a1, $sp, 0x10
/* 0BDE14 80127714 27A40028 */  addiu $a0, $sp, 0x28
/* 0BDE18 80127718 00B01021 */  addu  $v0, $a1, $s0
.L8012771C:
/* 0BDE1C 8012771C 90420000 */  lbu   $v0, ($v0)
/* 0BDE20 80127720 1040000B */  beqz  $v0, .L80127750
/* 0BDE24 80127724 2443FFD0 */   addiu $v1, $v0, -0x30
/* 0BDE28 80127728 306200FF */  andi  $v0, $v1, 0xff
/* 0BDE2C 8012772C 2C42000A */  sltiu $v0, $v0, 0xa
/* 0BDE30 80127730 50400004 */  beql  $v0, $zero, .L80127744
/* 0BDE34 80127734 26100001 */   addiu $s0, $s0, 1
/* 0BDE38 80127738 00901021 */  addu  $v0, $a0, $s0
/* 0BDE3C 8012773C A0430000 */  sb    $v1, ($v0)
/* 0BDE40 80127740 26100001 */  addiu $s0, $s0, 1
.L80127744:
/* 0BDE44 80127744 2A02000A */  slti  $v0, $s0, 0xa
/* 0BDE48 80127748 1440FFF4 */  bnez  $v0, .L8012771C
/* 0BDE4C 8012774C 00B01021 */   addu  $v0, $a1, $s0
.L80127750:
/* 0BDE50 80127750 3C03800A */  lui   $v1, 0x800a
/* 0BDE54 80127754 2463A66C */  addiu $v1, $v1, -0x5994
/* 0BDE58 80127758 0240302D */  daddu $a2, $s2, $zero
/* 0BDE5C 8012775C 8C620000 */  lw    $v0, ($v1)
/* 0BDE60 80127760 0040202D */  daddu $a0, $v0, $zero
/* 0BDE64 80127764 24420008 */  addiu $v0, $v0, 8
/* 0BDE68 80127768 AC620000 */  sw    $v0, ($v1)
/* 0BDE6C 8012776C 3C02DE00 */  lui   $v0, 0xde00
/* 0BDE70 80127770 AC820000 */  sw    $v0, ($a0)
/* 0BDE74 80127774 3C028015 */  lui   $v0, 0x8015
/* 0BDE78 80127778 2442C368 */  addiu $v0, $v0, -0x3c98
/* 0BDE7C 8012777C AC820004 */  sw    $v0, 4($a0)
/* 0BDE80 80127780 32220001 */  andi  $v0, $s1, 1
/* 0BDE84 80127784 1040001E */  beqz  $v0, .L80127800
/* 0BDE88 80127788 0200982D */   daddu $s3, $s0, $zero
/* 0BDE8C 8012778C 2610FFFF */  addiu $s0, $s0, -1
/* 0BDE90 80127790 06000035 */  bltz  $s0, .L80127868
/* 0BDE94 80127794 00151080 */   sll   $v0, $s5, 2
/* 0BDE98 80127798 32290002 */  andi  $t1, $s1, 2
/* 0BDE9C 8012779C 3C058015 */  lui   $a1, 0x8015
/* 0BDEA0 801277A0 24A5C340 */  addiu $a1, $a1, -0x3cc0
/* 0BDEA4 801277A4 00551021 */  addu  $v0, $v0, $s5
/* 0BDEA8 801277A8 00022080 */  sll   $a0, $v0, 2
/* 0BDEAC 801277AC 00854021 */  addu  $t0, $a0, $a1
/* 0BDEB0 801277B0 27A70028 */  addiu $a3, $sp, 0x28
/* 0BDEB4 801277B4 27A30040 */  addiu $v1, $sp, 0x40
/* 0BDEB8 801277B8 00101080 */  sll   $v0, $s0, 2
/* 0BDEBC 801277BC 00431821 */  addu  $v1, $v0, $v1
.L801277C0:
/* 0BDEC0 801277C0 11200004 */  beqz  $t1, .L801277D4
/* 0BDEC4 801277C4 00F01021 */   addu  $v0, $a3, $s0
/* 0BDEC8 801277C8 91020011 */  lbu   $v0, 0x11($t0)
/* 0BDECC 801277CC 08049DFA */  j     .L801277E8
/* 0BDED0 801277D0 00C23023 */   subu  $a2, $a2, $v0

.L801277D4:
/* 0BDED4 801277D4 90420000 */  lbu   $v0, ($v0)
/* 0BDED8 801277D8 00441021 */  addu  $v0, $v0, $a0
/* 0BDEDC 801277DC 00451021 */  addu  $v0, $v0, $a1
/* 0BDEE0 801277E0 90420007 */  lbu   $v0, 7($v0)
/* 0BDEE4 801277E4 00C23023 */  subu  $a2, $a2, $v0
.L801277E8:
/* 0BDEE8 801277E8 AC660000 */  sw    $a2, ($v1)
/* 0BDEEC 801277EC 2610FFFF */  addiu $s0, $s0, -1
/* 0BDEF0 801277F0 0601FFF3 */  bgez  $s0, .L801277C0
/* 0BDEF4 801277F4 2463FFFC */   addiu $v1, $v1, -4
/* 0BDEF8 801277F8 08049E1B */  j     .L8012786C
/* 0BDEFC 801277FC 32220004 */   andi  $v0, $s1, 4

.L80127800:
/* 0BDF00 80127800 1A600019 */  blez  $s3, .L80127868
/* 0BDF04 80127804 0000802D */   daddu $s0, $zero, $zero
/* 0BDF08 80127808 32290002 */  andi  $t1, $s1, 2
/* 0BDF0C 8012780C 3C058015 */  lui   $a1, 0x8015
/* 0BDF10 80127810 24A5C340 */  addiu $a1, $a1, -0x3cc0
/* 0BDF14 80127814 00151080 */  sll   $v0, $s5, 2
/* 0BDF18 80127818 00551021 */  addu  $v0, $v0, $s5
/* 0BDF1C 8012781C 00022080 */  sll   $a0, $v0, 2
/* 0BDF20 80127820 00854021 */  addu  $t0, $a0, $a1
/* 0BDF24 80127824 27A70028 */  addiu $a3, $sp, 0x28
/* 0BDF28 80127828 27A30040 */  addiu $v1, $sp, 0x40
.L8012782C:
/* 0BDF2C 8012782C 11200004 */  beqz  $t1, .L80127840
/* 0BDF30 80127830 AC660000 */   sw    $a2, ($v1)
/* 0BDF34 80127834 91020011 */  lbu   $v0, 0x11($t0)
/* 0BDF38 80127838 08049E16 */  j     .L80127858
/* 0BDF3C 8012783C 00C23021 */   addu  $a2, $a2, $v0

.L80127840:
/* 0BDF40 80127840 00F01021 */  addu  $v0, $a3, $s0
/* 0BDF44 80127844 90420000 */  lbu   $v0, ($v0)
/* 0BDF48 80127848 00441021 */  addu  $v0, $v0, $a0
/* 0BDF4C 8012784C 00451021 */  addu  $v0, $v0, $a1
/* 0BDF50 80127850 90420007 */  lbu   $v0, 7($v0)
/* 0BDF54 80127854 00C23021 */  addu  $a2, $a2, $v0
.L80127858:
/* 0BDF58 80127858 26100001 */  addiu $s0, $s0, 1
/* 0BDF5C 8012785C 0213102A */  slt   $v0, $s0, $s3
/* 0BDF60 80127860 1440FFF2 */  bnez  $v0, .L8012782C
/* 0BDF64 80127864 24630004 */   addiu $v1, $v1, 4
.L80127868:
/* 0BDF68 80127868 32220004 */  andi  $v0, $s1, 4
.L8012786C:
/* 0BDF6C 8012786C 10400038 */  beqz  $v0, .L80127950
/* 0BDF70 80127870 00000000 */   nop   
/* 0BDF74 80127874 1A600036 */  blez  $s3, .L80127950
/* 0BDF78 80127878 0000802D */   daddu $s0, $zero, $zero
/* 0BDF7C 8012787C 3C11800A */  lui   $s1, 0x800a
/* 0BDF80 80127880 2631A66C */  addiu $s1, $s1, -0x5994
/* 0BDF84 80127884 3C12E700 */  lui   $s2, 0xe700
/* 0BDF88 80127888 3C16E200 */  lui   $s6, 0xe200
/* 0BDF8C 8012788C 36D6001C */  ori   $s6, $s6, 0x1c
.L80127890:
/* 0BDF90 80127890 3C040050 */  lui   $a0, 0x50
/* 0BDF94 80127894 34844240 */  ori   $a0, $a0, 0x4240
/* 0BDF98 80127898 3C07FCFF */  lui   $a3, 0xfcff
/* 0BDF9C 8012789C 34E797FF */  ori   $a3, $a3, 0x97ff
/* 0BDFA0 801278A0 3C06FF2D */  lui   $a2, 0xff2d
/* 0BDFA4 801278A4 34C6FEFF */  ori   $a2, $a2, 0xfeff
/* 0BDFA8 801278A8 3C082828 */  lui   $t0, 0x2828
/* 0BDFAC 801278AC 35082848 */  ori   $t0, $t0, 0x2848
/* 0BDFB0 801278B0 8E230000 */  lw    $v1, ($s1)
/* 0BDFB4 801278B4 02A0282D */  daddu $a1, $s5, $zero
/* 0BDFB8 801278B8 0060102D */  daddu $v0, $v1, $zero
/* 0BDFBC 801278BC 24630008 */  addiu $v1, $v1, 8
/* 0BDFC0 801278C0 AE230000 */  sw    $v1, ($s1)
/* 0BDFC4 801278C4 AC520000 */  sw    $s2, ($v0)
/* 0BDFC8 801278C8 AC400004 */  sw    $zero, 4($v0)
/* 0BDFCC 801278CC 24620008 */  addiu $v0, $v1, 8
/* 0BDFD0 801278D0 AE220000 */  sw    $v0, ($s1)
/* 0BDFD4 801278D4 24620010 */  addiu $v0, $v1, 0x10
/* 0BDFD8 801278D8 AC760000 */  sw    $s6, ($v1)
/* 0BDFDC 801278DC AC640004 */  sw    $a0, 4($v1)
/* 0BDFE0 801278E0 AE220000 */  sw    $v0, ($s1)
/* 0BDFE4 801278E4 24620018 */  addiu $v0, $v1, 0x18
/* 0BDFE8 801278E8 AC670008 */  sw    $a3, 8($v1)
/* 0BDFEC 801278EC AC66000C */  sw    $a2, 0xc($v1)
/* 0BDFF0 801278F0 AE220000 */  sw    $v0, ($s1)
/* 0BDFF4 801278F4 3C02FA00 */  lui   $v0, 0xfa00
/* 0BDFF8 801278F8 AC620010 */  sw    $v0, 0x10($v1)
/* 0BDFFC 801278FC 03B01021 */  addu  $v0, $sp, $s0
/* 0BE000 80127900 AC680014 */  sw    $t0, 0x14($v1)
/* 0BE004 80127904 90420028 */  lbu   $v0, 0x28($v0)
/* 0BE008 80127908 00101880 */  sll   $v1, $s0, 2
/* 0BE00C 8012790C 00570018 */  mult  $v0, $s7
/* 0BE010 80127910 03A31021 */  addu  $v0, $sp, $v1
/* 0BE014 80127914 8C460040 */  lw    $a2, 0x40($v0)
/* 0BE018 80127918 26870002 */  addiu $a3, $s4, 2
/* 0BE01C 8012791C 24C60002 */  addiu $a2, $a2, 2
/* 0BE020 80127920 00005012 */  mflo  $t2
/* 0BE024 80127924 0C049D30 */  jal   func_801274C0
/* 0BE028 80127928 03CA2021 */   addu  $a0, $fp, $t2
/* 0BE02C 8012792C 8E220000 */  lw    $v0, ($s1)
/* 0BE030 80127930 26100001 */  addiu $s0, $s0, 1
/* 0BE034 80127934 0040182D */  daddu $v1, $v0, $zero
/* 0BE038 80127938 24420008 */  addiu $v0, $v0, 8
/* 0BE03C 8012793C AE220000 */  sw    $v0, ($s1)
/* 0BE040 80127940 0213102A */  slt   $v0, $s0, $s3
/* 0BE044 80127944 AC720000 */  sw    $s2, ($v1)
/* 0BE048 80127948 1440FFD1 */  bnez  $v0, .L80127890
/* 0BE04C 8012794C AC600004 */   sw    $zero, 4($v1)
.L80127950:
/* 0BE050 80127950 8FAA00DC */  lw    $t2, 0xdc($sp)
/* 0BE054 80127954 240200FF */  addiu $v0, $zero, 0xff
/* 0BE058 80127958 15420015 */  bne   $t2, $v0, .L801279B0
/* 0BE05C 8012795C 3C07E200 */   lui   $a3, 0xe200
/* 0BE060 80127960 34E7001C */  ori   $a3, $a3, 0x1c
/* 0BE064 80127964 3C050F0A */  lui   $a1, 0xf0a
/* 0BE068 80127968 34A57008 */  ori   $a1, $a1, 0x7008
/* 0BE06C 8012796C 3C08FCFF */  lui   $t0, 0xfcff
/* 0BE070 80127970 3508FFFF */  ori   $t0, $t0, 0xffff
/* 0BE074 80127974 3C06FFFC */  lui   $a2, 0xfffc
/* 0BE078 80127978 3C04800A */  lui   $a0, 0x800a
/* 0BE07C 8012797C 2484A66C */  addiu $a0, $a0, -0x5994
/* 0BE080 80127980 8C820000 */  lw    $v0, ($a0)
/* 0BE084 80127984 34C6F279 */  ori   $a2, $a2, 0xf279
/* 0BE088 80127988 0040182D */  daddu $v1, $v0, $zero
/* 0BE08C 8012798C 24420008 */  addiu $v0, $v0, 8
/* 0BE090 80127990 AC820000 */  sw    $v0, ($a0)
/* 0BE094 80127994 AC670000 */  sw    $a3, ($v1)
/* 0BE098 80127998 AC650004 */  sw    $a1, 4($v1)
/* 0BE09C 8012799C 24430008 */  addiu $v1, $v0, 8
/* 0BE0A0 801279A0 AC830000 */  sw    $v1, ($a0)
/* 0BE0A4 801279A4 AC480000 */  sw    $t0, ($v0)
/* 0BE0A8 801279A8 08049E87 */  j     .L80127A1C
/* 0BE0AC 801279AC AC460004 */   sw    $a2, 4($v0)

.L801279B0:
/* 0BE0B0 801279B0 34E7001C */  ori   $a3, $a3, 0x1c
/* 0BE0B4 801279B4 3C050050 */  lui   $a1, 0x50
/* 0BE0B8 801279B8 34A54240 */  ori   $a1, $a1, 0x4240
/* 0BE0BC 801279BC 3C08FCFF */  lui   $t0, 0xfcff
/* 0BE0C0 801279C0 3508B3FF */  ori   $t0, $t0, 0xb3ff
/* 0BE0C4 801279C4 3C06FF64 */  lui   $a2, 0xff64
/* 0BE0C8 801279C8 3C04800A */  lui   $a0, 0x800a
/* 0BE0CC 801279CC 2484A66C */  addiu $a0, $a0, -0x5994
/* 0BE0D0 801279D0 8C830000 */  lw    $v1, ($a0)
/* 0BE0D4 801279D4 34C6FE7F */  ori   $a2, $a2, 0xfe7f
/* 0BE0D8 801279D8 0060102D */  daddu $v0, $v1, $zero
/* 0BE0DC 801279DC 24630008 */  addiu $v1, $v1, 8
/* 0BE0E0 801279E0 AC830000 */  sw    $v1, ($a0)
/* 0BE0E4 801279E4 AC470000 */  sw    $a3, ($v0)
/* 0BE0E8 801279E8 AC450004 */  sw    $a1, 4($v0)
/* 0BE0EC 801279EC 24620008 */  addiu $v0, $v1, 8
/* 0BE0F0 801279F0 AC820000 */  sw    $v0, ($a0)
/* 0BE0F4 801279F4 24620010 */  addiu $v0, $v1, 0x10
/* 0BE0F8 801279F8 AC680000 */  sw    $t0, ($v1)
/* 0BE0FC 801279FC AC660004 */  sw    $a2, 4($v1)
/* 0BE100 80127A00 AC820000 */  sw    $v0, ($a0)
/* 0BE104 80127A04 3C02FA00 */  lui   $v0, 0xfa00
/* 0BE108 80127A08 AC620008 */  sw    $v0, 8($v1)
/* 0BE10C 80127A0C 8FAA00DC */  lw    $t2, 0xdc($sp)
/* 0BE110 80127A10 2402FF00 */  addiu $v0, $zero, -0x100
/* 0BE114 80127A14 01421025 */  or    $v0, $t2, $v0
/* 0BE118 80127A18 AC62000C */  sw    $v0, 0xc($v1)
.L80127A1C:
/* 0BE11C 80127A1C 3C07F500 */  lui   $a3, 0xf500
/* 0BE120 80127A20 34E70100 */  ori   $a3, $a3, 0x100
/* 0BE124 80127A24 3C080703 */  lui   $t0, 0x703
/* 0BE128 80127A28 3508C000 */  ori   $t0, $t0, 0xc000
/* 0BE12C 80127A2C 3C04800A */  lui   $a0, 0x800a
/* 0BE130 80127A30 2484A66C */  addiu $a0, $a0, -0x5994
/* 0BE134 80127A34 0000802D */  daddu $s0, $zero, $zero
/* 0BE138 80127A38 8C830000 */  lw    $v1, ($a0)
/* 0BE13C 80127A3C 3C02FD10 */  lui   $v0, 0xfd10
/* 0BE140 80127A40 0060302D */  daddu $a2, $v1, $zero
/* 0BE144 80127A44 24630008 */  addiu $v1, $v1, 8
/* 0BE148 80127A48 AC830000 */  sw    $v1, ($a0)
/* 0BE14C 80127A4C ACC20000 */  sw    $v0, ($a2)
/* 0BE150 80127A50 8FA200D8 */  lw    $v0, 0xd8($sp)
/* 0BE154 80127A54 3C05802F */  lui   $a1, 0x802f
/* 0BE158 80127A58 24A54560 */  addiu $a1, $a1, 0x4560
/* 0BE15C 80127A5C 00021100 */  sll   $v0, $v0, 4
/* 0BE160 80127A60 00451021 */  addu  $v0, $v0, $a1
/* 0BE164 80127A64 ACC20004 */  sw    $v0, 4($a2)
/* 0BE168 80127A68 24620008 */  addiu $v0, $v1, 8
/* 0BE16C 80127A6C AC820000 */  sw    $v0, ($a0)
/* 0BE170 80127A70 3C02E800 */  lui   $v0, 0xe800
/* 0BE174 80127A74 AC620000 */  sw    $v0, ($v1)
/* 0BE178 80127A78 24620010 */  addiu $v0, $v1, 0x10
/* 0BE17C 80127A7C AC600004 */  sw    $zero, 4($v1)
/* 0BE180 80127A80 AC820000 */  sw    $v0, ($a0)
/* 0BE184 80127A84 3C020700 */  lui   $v0, 0x700
/* 0BE188 80127A88 AC62000C */  sw    $v0, 0xc($v1)
/* 0BE18C 80127A8C 24620018 */  addiu $v0, $v1, 0x18
/* 0BE190 80127A90 AC670008 */  sw    $a3, 8($v1)
/* 0BE194 80127A94 AC820000 */  sw    $v0, ($a0)
/* 0BE198 80127A98 3C02E600 */  lui   $v0, 0xe600
/* 0BE19C 80127A9C AC620010 */  sw    $v0, 0x10($v1)
/* 0BE1A0 80127AA0 24620020 */  addiu $v0, $v1, 0x20
/* 0BE1A4 80127AA4 AC600014 */  sw    $zero, 0x14($v1)
/* 0BE1A8 80127AA8 AC820000 */  sw    $v0, ($a0)
/* 0BE1AC 80127AAC 3C02F000 */  lui   $v0, 0xf000
/* 0BE1B0 80127AB0 AC620018 */  sw    $v0, 0x18($v1)
/* 0BE1B4 80127AB4 24620028 */  addiu $v0, $v1, 0x28
/* 0BE1B8 80127AB8 AC68001C */  sw    $t0, 0x1c($v1)
/* 0BE1BC 80127ABC AC820000 */  sw    $v0, ($a0)
/* 0BE1C0 80127AC0 3C02E700 */  lui   $v0, 0xe700
/* 0BE1C4 80127AC4 AC620020 */  sw    $v0, 0x20($v1)
/* 0BE1C8 80127AC8 1A600014 */  blez  $s3, .L80127B1C
/* 0BE1CC 80127ACC AC600024 */   sw    $zero, 0x24($v1)
/* 0BE1D0 80127AD0 27B20028 */  addiu $s2, $sp, 0x28
/* 0BE1D4 80127AD4 27B10040 */  addiu $s1, $sp, 0x40
.L80127AD8:
/* 0BE1D8 80127AD8 8E260000 */  lw    $a2, ($s1)
/* 0BE1DC 80127ADC 24C2FFFF */  addiu $v0, $a2, -1
/* 0BE1E0 80127AE0 2C42013F */  sltiu $v0, $v0, 0x13f
/* 0BE1E4 80127AE4 5040000A */  beql  $v0, $zero, .L80127B10
/* 0BE1E8 80127AE8 26100001 */   addiu $s0, $s0, 1
/* 0BE1EC 80127AEC 02501021 */  addu  $v0, $s2, $s0
/* 0BE1F0 80127AF0 90420000 */  lbu   $v0, ($v0)
/* 0BE1F4 80127AF4 00570018 */  mult  $v0, $s7
/* 0BE1F8 80127AF8 02A0282D */  daddu $a1, $s5, $zero
/* 0BE1FC 80127AFC 0280382D */  daddu $a3, $s4, $zero
/* 0BE200 80127B00 00005012 */  mflo  $t2
/* 0BE204 80127B04 0C049D30 */  jal   func_801274C0
/* 0BE208 80127B08 03CA2021 */   addu  $a0, $fp, $t2
/* 0BE20C 80127B0C 26100001 */  addiu $s0, $s0, 1
.L80127B10:
/* 0BE210 80127B10 0213102A */  slt   $v0, $s0, $s3
/* 0BE214 80127B14 1440FFF0 */  bnez  $v0, .L80127AD8
/* 0BE218 80127B18 26310004 */   addiu $s1, $s1, 4
.L80127B1C:
/* 0BE21C 80127B1C 3C03800A */  lui   $v1, 0x800a
/* 0BE220 80127B20 2463A66C */  addiu $v1, $v1, -0x5994
/* 0BE224 80127B24 8C620000 */  lw    $v0, ($v1)
/* 0BE228 80127B28 0040202D */  daddu $a0, $v0, $zero
/* 0BE22C 80127B2C 24420008 */  addiu $v0, $v0, 8
/* 0BE230 80127B30 AC620000 */  sw    $v0, ($v1)
/* 0BE234 80127B34 3C02E700 */  lui   $v0, 0xe700
/* 0BE238 80127B38 AC820000 */  sw    $v0, ($a0)
/* 0BE23C 80127B3C AC800004 */  sw    $zero, 4($a0)
.L80127B40:
/* 0BE240 80127B40 8FBF00C4 */  lw    $ra, 0xc4($sp)
/* 0BE244 80127B44 8FBE00C0 */  lw    $fp, 0xc0($sp)
/* 0BE248 80127B48 8FB700BC */  lw    $s7, 0xbc($sp)
/* 0BE24C 80127B4C 8FB600B8 */  lw    $s6, 0xb8($sp)
/* 0BE250 80127B50 8FB500B4 */  lw    $s5, 0xb4($sp)
/* 0BE254 80127B54 8FB400B0 */  lw    $s4, 0xb0($sp)
/* 0BE258 80127B58 8FB300AC */  lw    $s3, 0xac($sp)
/* 0BE25C 80127B5C 8FB200A8 */  lw    $s2, 0xa8($sp)
/* 0BE260 80127B60 8FB100A4 */  lw    $s1, 0xa4($sp)
/* 0BE264 80127B64 8FB000A0 */  lw    $s0, 0xa0($sp)
/* 0BE268 80127B68 03E00008 */  jr    $ra
/* 0BE26C 80127B6C 27BD00C8 */   addiu $sp, $sp, 0xc8

/* 0BE270 80127B70 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 0BE274 80127B74 24020004 */  addiu $v0, $zero, 4
/* 0BE278 80127B78 0000282D */  daddu $a1, $zero, $zero
/* 0BE27C 80127B7C 00A0302D */  daddu $a2, $a1, $zero
/* 0BE280 80127B80 00A0382D */  daddu $a3, $a1, $zero
/* 0BE284 80127B84 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0BE288 80127B88 AFA00010 */  sw    $zero, 0x10($sp)
/* 0BE28C 80127B8C AFA20014 */  sw    $v0, 0x14($sp)
/* 0BE290 80127B90 0C049F64 */  jal   func_80127D90
/* 0BE294 80127B94 AFA00018 */   sw    $zero, 0x18($sp)
/* 0BE298 80127B98 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0BE29C 80127B9C 03E00008 */  jr    $ra
/* 0BE2A0 80127BA0 27BD0028 */   addiu $sp, $sp, 0x28

