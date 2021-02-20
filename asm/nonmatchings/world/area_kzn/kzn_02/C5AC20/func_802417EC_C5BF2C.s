.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802417EC_C5BF2C
/* C5BF2C 802417EC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C5BF30 802417F0 AFB40040 */  sw        $s4, 0x40($sp)
/* C5BF34 802417F4 0080A02D */  daddu     $s4, $a0, $zero
/* C5BF38 802417F8 AFBF0048 */  sw        $ra, 0x48($sp)
/* C5BF3C 802417FC AFB50044 */  sw        $s5, 0x44($sp)
/* C5BF40 80241800 AFB3003C */  sw        $s3, 0x3c($sp)
/* C5BF44 80241804 AFB20038 */  sw        $s2, 0x38($sp)
/* C5BF48 80241808 AFB10034 */  sw        $s1, 0x34($sp)
/* C5BF4C 8024180C AFB00030 */  sw        $s0, 0x30($sp)
/* C5BF50 80241810 8E920148 */  lw        $s2, 0x148($s4)
/* C5BF54 80241814 86440008 */  lh        $a0, 8($s2)
/* C5BF58 80241818 8E90000C */  lw        $s0, 0xc($s4)
/* C5BF5C 8024181C 0C00EABB */  jal       get_npc_unsafe
/* C5BF60 80241820 00A0882D */   daddu    $s1, $a1, $zero
/* C5BF64 80241824 0280202D */  daddu     $a0, $s4, $zero
/* C5BF68 80241828 8E050000 */  lw        $a1, ($s0)
/* C5BF6C 8024182C 0C0B1EAF */  jal       get_variable
/* C5BF70 80241830 0040A82D */   daddu    $s5, $v0, $zero
/* C5BF74 80241834 AFA00010 */  sw        $zero, 0x10($sp)
/* C5BF78 80241838 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5BF7C 8024183C 8C630030 */  lw        $v1, 0x30($v1)
/* C5BF80 80241840 AFA30014 */  sw        $v1, 0x14($sp)
/* C5BF84 80241844 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5BF88 80241848 8C63001C */  lw        $v1, 0x1c($v1)
/* C5BF8C 8024184C AFA30018 */  sw        $v1, 0x18($sp)
/* C5BF90 80241850 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5BF94 80241854 8C630024 */  lw        $v1, 0x24($v1)
/* C5BF98 80241858 AFA3001C */  sw        $v1, 0x1c($sp)
/* C5BF9C 8024185C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5BFA0 80241860 8C630028 */  lw        $v1, 0x28($v1)
/* C5BFA4 80241864 27B30010 */  addiu     $s3, $sp, 0x10
/* C5BFA8 80241868 AFA30020 */  sw        $v1, 0x20($sp)
/* C5BFAC 8024186C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* C5BFB0 80241870 3C0142F0 */  lui       $at, 0x42f0
/* C5BFB4 80241874 44810000 */  mtc1      $at, $f0
/* C5BFB8 80241878 8C63002C */  lw        $v1, 0x2c($v1)
/* C5BFBC 8024187C 0040802D */  daddu     $s0, $v0, $zero
/* C5BFC0 80241880 E7A00028 */  swc1      $f0, 0x28($sp)
/* C5BFC4 80241884 A7A0002C */  sh        $zero, 0x2c($sp)
/* C5BFC8 80241888 12200006 */  beqz      $s1, .L802418A4
/* C5BFCC 8024188C AFA30024 */   sw       $v1, 0x24($sp)
/* C5BFD0 80241890 02A0202D */  daddu     $a0, $s5, $zero
/* C5BFD4 80241894 0240282D */  daddu     $a1, $s2, $zero
/* C5BFD8 80241898 0280302D */  daddu     $a2, $s4, $zero
/* C5BFDC 8024189C 0C0905B2 */  jal       func_802416C8_C5BE08
/* C5BFE0 802418A0 0200382D */   daddu    $a3, $s0, $zero
.L802418A4:
/* C5BFE4 802418A4 2402FFFE */  addiu     $v0, $zero, -2
/* C5BFE8 802418A8 A2A200AB */  sb        $v0, 0xab($s5)
/* C5BFEC 802418AC 8E4300B0 */  lw        $v1, 0xb0($s2)
/* C5BFF0 802418B0 30620004 */  andi      $v0, $v1, 4
/* C5BFF4 802418B4 10400007 */  beqz      $v0, .L802418D4
/* C5BFF8 802418B8 00000000 */   nop
/* C5BFFC 802418BC 824200B4 */  lb        $v0, 0xb4($s2)
/* C5C000 802418C0 1440003C */  bnez      $v0, .L802419B4
/* C5C004 802418C4 0000102D */   daddu    $v0, $zero, $zero
/* C5C008 802418C8 2402FFFB */  addiu     $v0, $zero, -5
/* C5C00C 802418CC 00621024 */  and       $v0, $v1, $v0
/* C5C010 802418D0 AE4200B0 */  sw        $v0, 0xb0($s2)
.L802418D4:
/* C5C014 802418D4 8E830070 */  lw        $v1, 0x70($s4)
/* C5C018 802418D8 2C62000F */  sltiu     $v0, $v1, 0xf
/* C5C01C 802418DC 10400034 */  beqz      $v0, .L802419B0
/* C5C020 802418E0 00031080 */   sll      $v0, $v1, 2
/* C5C024 802418E4 3C018024 */  lui       $at, %hi(jtbl_80246518_C60C58)
/* C5C028 802418E8 00220821 */  addu      $at, $at, $v0
/* C5C02C 802418EC 8C226518 */  lw        $v0, %lo(jtbl_80246518_C60C58)($at)
/* C5C030 802418F0 00400008 */  jr        $v0
/* C5C034 802418F4 00000000 */   nop
glabel L802418F8_C5C038
/* C5C038 802418F8 0280202D */  daddu     $a0, $s4, $zero
/* C5C03C 802418FC 0200282D */  daddu     $a1, $s0, $zero
/* C5C040 80241900 0C090138 */  jal       func_802404E0_C5AC20
/* C5C044 80241904 0260302D */   daddu    $a2, $s3, $zero
glabel L80241908_C5C048
/* C5C048 80241908 0280202D */  daddu     $a0, $s4, $zero
/* C5C04C 8024190C 0200282D */  daddu     $a1, $s0, $zero
/* C5C050 80241910 0C0901A4 */  jal       func_80240690_C5ADD0
/* C5C054 80241914 0260302D */   daddu    $a2, $s3, $zero
/* C5C058 80241918 0809066D */  j         .L802419B4
/* C5C05C 8024191C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241920_C5C060
/* C5C060 80241920 0280202D */  daddu     $a0, $s4, $zero
/* C5C064 80241924 0200282D */  daddu     $a1, $s0, $zero
/* C5C068 80241928 0C09032E */  jal       kzn_02_UnkNpcAIFunc1
/* C5C06C 8024192C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241930_C5C070
/* C5C070 80241930 0280202D */  daddu     $a0, $s4, $zero
/* C5C074 80241934 0200282D */  daddu     $a1, $s0, $zero
/* C5C078 80241938 0C09035E */  jal       func_80240D78_C5B4B8
/* C5C07C 8024193C 0260302D */   daddu    $a2, $s3, $zero
/* C5C080 80241940 0809066D */  j         .L802419B4
/* C5C084 80241944 0000102D */   daddu    $v0, $zero, $zero
glabel L80241948_C5C088
/* C5C088 80241948 0280202D */  daddu     $a0, $s4, $zero
/* C5C08C 8024194C 0200282D */  daddu     $a1, $s0, $zero
/* C5C090 80241950 0C09042F */  jal       kzn_02_UnkNpcAIFunc2
/* C5C094 80241954 0260302D */   daddu    $a2, $s3, $zero
glabel L80241958_C5C098
/* C5C098 80241958 0280202D */  daddu     $a0, $s4, $zero
/* C5C09C 8024195C 0200282D */  daddu     $a1, $s0, $zero
/* C5C0A0 80241960 0C09044D */  jal       func_80241134_C5B874
/* C5C0A4 80241964 0260302D */   daddu    $a2, $s3, $zero
/* C5C0A8 80241968 0809066D */  j         .L802419B4
/* C5C0AC 8024196C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241970_C5C0B0
/* C5C0B0 80241970 0280202D */  daddu     $a0, $s4, $zero
/* C5C0B4 80241974 0200282D */  daddu     $a1, $s0, $zero
/* C5C0B8 80241978 0C090468 */  jal       kzn_02_UnkNpcAIFunc14
/* C5C0BC 8024197C 0260302D */   daddu    $a2, $s3, $zero
/* C5C0C0 80241980 0809066D */  j         .L802419B4
/* C5C0C4 80241984 0000102D */   daddu    $v0, $zero, $zero
glabel L80241988_C5C0C8
/* C5C0C8 80241988 0280202D */  daddu     $a0, $s4, $zero
/* C5C0CC 8024198C 0200282D */  daddu     $a1, $s0, $zero
/* C5C0D0 80241990 0C0904B5 */  jal       kzn_02_UnkNpcAIFunc3
/* C5C0D4 80241994 0260302D */   daddu    $a2, $s3, $zero
/* C5C0D8 80241998 0809066D */  j         .L802419B4
/* C5C0DC 8024199C 0000102D */   daddu    $v0, $zero, $zero
glabel L802419A0_C5C0E0
/* C5C0E0 802419A0 0280202D */  daddu     $a0, $s4, $zero
/* C5C0E4 802419A4 0200282D */  daddu     $a1, $s0, $zero
/* C5C0E8 802419A8 0C0904CE */  jal       func_80241338_C5BA78
/* C5C0EC 802419AC 0260302D */   daddu    $a2, $s3, $zero
.L802419B0:
glabel L802419B0_C5C0F0
/* C5C0F0 802419B0 0000102D */  daddu     $v0, $zero, $zero
.L802419B4:
/* C5C0F4 802419B4 8FBF0048 */  lw        $ra, 0x48($sp)
/* C5C0F8 802419B8 8FB50044 */  lw        $s5, 0x44($sp)
/* C5C0FC 802419BC 8FB40040 */  lw        $s4, 0x40($sp)
/* C5C100 802419C0 8FB3003C */  lw        $s3, 0x3c($sp)
/* C5C104 802419C4 8FB20038 */  lw        $s2, 0x38($sp)
/* C5C108 802419C8 8FB10034 */  lw        $s1, 0x34($sp)
/* C5C10C 802419CC 8FB00030 */  lw        $s0, 0x30($sp)
/* C5C110 802419D0 03E00008 */  jr        $ra
/* C5C114 802419D4 27BD0050 */   addiu    $sp, $sp, 0x50
