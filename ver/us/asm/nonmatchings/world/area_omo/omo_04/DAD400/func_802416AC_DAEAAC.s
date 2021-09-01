.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80244CC8_DB20C8
.word L802417B8_DAEBB8, L802417C8_DAEBC8, L802417E0_DAEBE0, L802417F0_DAEBF0, L80241870_DAEC70, L80241870_DAEC70, L80241870_DAEC70, L80241870_DAEC70, L80241870_DAEC70, L80241870_DAEC70, L80241808_DAEC08, L80241818_DAEC18, L80241830_DAEC30, L80241848_DAEC48, L80241860_DAEC60, 0

.section .text

glabel func_802416AC_DAEAAC
/* DAEAAC 802416AC 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DAEAB0 802416B0 AFB40040 */  sw        $s4, 0x40($sp)
/* DAEAB4 802416B4 0080A02D */  daddu     $s4, $a0, $zero
/* DAEAB8 802416B8 AFBF0048 */  sw        $ra, 0x48($sp)
/* DAEABC 802416BC AFB50044 */  sw        $s5, 0x44($sp)
/* DAEAC0 802416C0 AFB3003C */  sw        $s3, 0x3c($sp)
/* DAEAC4 802416C4 AFB20038 */  sw        $s2, 0x38($sp)
/* DAEAC8 802416C8 AFB10034 */  sw        $s1, 0x34($sp)
/* DAEACC 802416CC AFB00030 */  sw        $s0, 0x30($sp)
/* DAEAD0 802416D0 8E920148 */  lw        $s2, 0x148($s4)
/* DAEAD4 802416D4 86440008 */  lh        $a0, 8($s2)
/* DAEAD8 802416D8 8E90000C */  lw        $s0, 0xc($s4)
/* DAEADC 802416DC 0C00EABB */  jal       get_npc_unsafe
/* DAEAE0 802416E0 00A0882D */   daddu    $s1, $a1, $zero
/* DAEAE4 802416E4 0280202D */  daddu     $a0, $s4, $zero
/* DAEAE8 802416E8 8E050000 */  lw        $a1, ($s0)
/* DAEAEC 802416EC 0C0B1EAF */  jal       evt_get_variable
/* DAEAF0 802416F0 0040A82D */   daddu    $s5, $v0, $zero
/* DAEAF4 802416F4 AFA00010 */  sw        $zero, 0x10($sp)
/* DAEAF8 802416F8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DAEAFC 802416FC 8C630030 */  lw        $v1, 0x30($v1)
/* DAEB00 80241700 AFA30014 */  sw        $v1, 0x14($sp)
/* DAEB04 80241704 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DAEB08 80241708 8C63001C */  lw        $v1, 0x1c($v1)
/* DAEB0C 8024170C AFA30018 */  sw        $v1, 0x18($sp)
/* DAEB10 80241710 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DAEB14 80241714 8C630024 */  lw        $v1, 0x24($v1)
/* DAEB18 80241718 AFA3001C */  sw        $v1, 0x1c($sp)
/* DAEB1C 8024171C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DAEB20 80241720 8C630028 */  lw        $v1, 0x28($v1)
/* DAEB24 80241724 27B30010 */  addiu     $s3, $sp, 0x10
/* DAEB28 80241728 AFA30020 */  sw        $v1, 0x20($sp)
/* DAEB2C 8024172C 8E4300D0 */  lw        $v1, 0xd0($s2)
/* DAEB30 80241730 3C0142F0 */  lui       $at, 0x42f0
/* DAEB34 80241734 44810000 */  mtc1      $at, $f0
/* DAEB38 80241738 8C63002C */  lw        $v1, 0x2c($v1)
/* DAEB3C 8024173C 0040802D */  daddu     $s0, $v0, $zero
/* DAEB40 80241740 E7A00028 */  swc1      $f0, 0x28($sp)
/* DAEB44 80241744 A7A0002C */  sh        $zero, 0x2c($sp)
/* DAEB48 80241748 12200006 */  beqz      $s1, .L80241764
/* DAEB4C 8024174C AFA30024 */   sw       $v1, 0x24($sp)
/* DAEB50 80241750 02A0202D */  daddu     $a0, $s5, $zero
/* DAEB54 80241754 0240282D */  daddu     $a1, $s2, $zero
/* DAEB58 80241758 0280302D */  daddu     $a2, $s4, $zero
/* DAEB5C 8024175C 0C090562 */  jal       omo_04_UnkFunc5
/* DAEB60 80241760 0200382D */   daddu    $a3, $s0, $zero
.L80241764:
/* DAEB64 80241764 2402FFFE */  addiu     $v0, $zero, -2
/* DAEB68 80241768 A2A200AB */  sb        $v0, 0xab($s5)
/* DAEB6C 8024176C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* DAEB70 80241770 30620004 */  andi      $v0, $v1, 4
/* DAEB74 80241774 10400007 */  beqz      $v0, .L80241794
/* DAEB78 80241778 00000000 */   nop
/* DAEB7C 8024177C 824200B4 */  lb        $v0, 0xb4($s2)
/* DAEB80 80241780 1440003C */  bnez      $v0, .L80241874
/* DAEB84 80241784 0000102D */   daddu    $v0, $zero, $zero
/* DAEB88 80241788 2402FFFB */  addiu     $v0, $zero, -5
/* DAEB8C 8024178C 00621024 */  and       $v0, $v1, $v0
/* DAEB90 80241790 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241794:
/* DAEB94 80241794 8E830070 */  lw        $v1, 0x70($s4)
/* DAEB98 80241798 2C62000F */  sltiu     $v0, $v1, 0xf
/* DAEB9C 8024179C 10400034 */  beqz      $v0, L80241870_DAEC70
/* DAEBA0 802417A0 00031080 */   sll      $v0, $v1, 2
/* DAEBA4 802417A4 3C018024 */  lui       $at, %hi(jtbl_80244CC8_DB20C8)
/* DAEBA8 802417A8 00220821 */  addu      $at, $at, $v0
/* DAEBAC 802417AC 8C224CC8 */  lw        $v0, %lo(jtbl_80244CC8_DB20C8)($at)
/* DAEBB0 802417B0 00400008 */  jr        $v0
/* DAEBB4 802417B4 00000000 */   nop
glabel L802417B8_DAEBB8
/* DAEBB8 802417B8 0280202D */  daddu     $a0, $s4, $zero
/* DAEBBC 802417BC 0200282D */  daddu     $a1, $s0, $zero
/* DAEBC0 802417C0 0C0900E8 */  jal       omo_04_UnkNpcAIFunc23
/* DAEBC4 802417C4 0260302D */   daddu    $a2, $s3, $zero
glabel L802417C8_DAEBC8
/* DAEBC8 802417C8 0280202D */  daddu     $a0, $s4, $zero
/* DAEBCC 802417CC 0200282D */  daddu     $a1, $s0, $zero
/* DAEBD0 802417D0 0C090154 */  jal       func_80240550_DAD950
/* DAEBD4 802417D4 0260302D */   daddu    $a2, $s3, $zero
/* DAEBD8 802417D8 0809061D */  j         .L80241874
/* DAEBDC 802417DC 0000102D */   daddu    $v0, $zero, $zero
glabel L802417E0_DAEBE0
/* DAEBE0 802417E0 0280202D */  daddu     $a0, $s4, $zero
/* DAEBE4 802417E4 0200282D */  daddu     $a1, $s0, $zero
/* DAEBE8 802417E8 0C0902DE */  jal       omo_04_UnkNpcAIFunc1
/* DAEBEC 802417EC 0260302D */   daddu    $a2, $s3, $zero
glabel L802417F0_DAEBF0
/* DAEBF0 802417F0 0280202D */  daddu     $a0, $s4, $zero
/* DAEBF4 802417F4 0200282D */  daddu     $a1, $s0, $zero
/* DAEBF8 802417F8 0C09030E */  jal       omo_04_UnkFunc4
/* DAEBFC 802417FC 0260302D */   daddu    $a2, $s3, $zero
/* DAEC00 80241800 0809061D */  j         .L80241874
/* DAEC04 80241804 0000102D */   daddu    $v0, $zero, $zero
glabel L80241808_DAEC08
/* DAEC08 80241808 0280202D */  daddu     $a0, $s4, $zero
/* DAEC0C 8024180C 0200282D */  daddu     $a1, $s0, $zero
/* DAEC10 80241810 0C0903DF */  jal       omo_04_UnkNpcAIFunc2
/* DAEC14 80241814 0260302D */   daddu    $a2, $s3, $zero
glabel L80241818_DAEC18
/* DAEC18 80241818 0280202D */  daddu     $a0, $s4, $zero
/* DAEC1C 8024181C 0200282D */  daddu     $a1, $s0, $zero
/* DAEC20 80241820 0C0903FD */  jal       func_80240FF4_DAE3F4
/* DAEC24 80241824 0260302D */   daddu    $a2, $s3, $zero
/* DAEC28 80241828 0809061D */  j         .L80241874
/* DAEC2C 8024182C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241830_DAEC30
/* DAEC30 80241830 0280202D */  daddu     $a0, $s4, $zero
/* DAEC34 80241834 0200282D */  daddu     $a1, $s0, $zero
/* DAEC38 80241838 0C090418 */  jal       omo_04_UnkNpcAIFunc14
/* DAEC3C 8024183C 0260302D */   daddu    $a2, $s3, $zero
/* DAEC40 80241840 0809061D */  j         .L80241874
/* DAEC44 80241844 0000102D */   daddu    $v0, $zero, $zero
glabel L80241848_DAEC48
/* DAEC48 80241848 0280202D */  daddu     $a0, $s4, $zero
/* DAEC4C 8024184C 0200282D */  daddu     $a1, $s0, $zero
/* DAEC50 80241850 0C090465 */  jal       omo_04_UnkNpcAIFunc3
/* DAEC54 80241854 0260302D */   daddu    $a2, $s3, $zero
/* DAEC58 80241858 0809061D */  j         .L80241874
/* DAEC5C 8024185C 0000102D */   daddu    $v0, $zero, $zero
glabel L80241860_DAEC60
/* DAEC60 80241860 0280202D */  daddu     $a0, $s4, $zero
/* DAEC64 80241864 0200282D */  daddu     $a1, $s0, $zero
/* DAEC68 80241868 0C09047E */  jal       omo_04_UnkFunc6
/* DAEC6C 8024186C 0260302D */   daddu    $a2, $s3, $zero
glabel L80241870_DAEC70
/* DAEC70 80241870 0000102D */  daddu     $v0, $zero, $zero
.L80241874:
/* DAEC74 80241874 8FBF0048 */  lw        $ra, 0x48($sp)
/* DAEC78 80241878 8FB50044 */  lw        $s5, 0x44($sp)
/* DAEC7C 8024187C 8FB40040 */  lw        $s4, 0x40($sp)
/* DAEC80 80241880 8FB3003C */  lw        $s3, 0x3c($sp)
/* DAEC84 80241884 8FB20038 */  lw        $s2, 0x38($sp)
/* DAEC88 80241888 8FB10034 */  lw        $s1, 0x34($sp)
/* DAEC8C 8024188C 8FB00030 */  lw        $s0, 0x30($sp)
/* DAEC90 80241890 03E00008 */  jr        $ra
/* DAEC94 80241894 27BD0050 */   addiu    $sp, $sp, 0x50
