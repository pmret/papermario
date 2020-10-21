.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024185C_D216EC
/* D216EC 8024185C 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D216F0 80241860 AFB40040 */  sw        $s4, 0x40($sp)
/* D216F4 80241864 0080A02D */  daddu     $s4, $a0, $zero
/* D216F8 80241868 AFBF0048 */  sw        $ra, 0x48($sp)
/* D216FC 8024186C AFB50044 */  sw        $s5, 0x44($sp)
/* D21700 80241870 AFB3003C */  sw        $s3, 0x3c($sp)
/* D21704 80241874 AFB20038 */  sw        $s2, 0x38($sp)
/* D21708 80241878 AFB10034 */  sw        $s1, 0x34($sp)
/* D2170C 8024187C AFB00030 */  sw        $s0, 0x30($sp)
/* D21710 80241880 8E920148 */  lw        $s2, 0x148($s4)
/* D21714 80241884 86440008 */  lh        $a0, 8($s2)
/* D21718 80241888 8E90000C */  lw        $s0, 0xc($s4)
/* D2171C 8024188C 0C00EABB */  jal       get_npc_unsafe
/* D21720 80241890 00A0882D */   daddu    $s1, $a1, $zero
/* D21724 80241894 0280202D */  daddu     $a0, $s4, $zero
/* D21728 80241898 8E050000 */  lw        $a1, ($s0)
/* D2172C 8024189C 0C0B1EAF */  jal       get_variable
/* D21730 802418A0 0040A82D */   daddu    $s5, $v0, $zero
/* D21734 802418A4 AFA00010 */  sw        $zero, 0x10($sp)
/* D21738 802418A8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D2173C 802418AC 8C630030 */  lw        $v1, 0x30($v1)
/* D21740 802418B0 AFA30014 */  sw        $v1, 0x14($sp)
/* D21744 802418B4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D21748 802418B8 8C63001C */  lw        $v1, 0x1c($v1)
/* D2174C 802418BC AFA30018 */  sw        $v1, 0x18($sp)
/* D21750 802418C0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D21754 802418C4 8C630024 */  lw        $v1, 0x24($v1)
/* D21758 802418C8 AFA3001C */  sw        $v1, 0x1c($sp)
/* D2175C 802418CC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D21760 802418D0 8C630028 */  lw        $v1, 0x28($v1)
/* D21764 802418D4 27B30010 */  addiu     $s3, $sp, 0x10
/* D21768 802418D8 AFA30020 */  sw        $v1, 0x20($sp)
/* D2176C 802418DC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* D21770 802418E0 3C0142F0 */  lui       $at, 0x42f0
/* D21774 802418E4 44810000 */  mtc1      $at, $f0
/* D21778 802418E8 8C63002C */  lw        $v1, 0x2c($v1)
/* D2177C 802418EC 0040802D */  daddu     $s0, $v0, $zero
/* D21780 802418F0 E7A00028 */  swc1      $f0, 0x28($sp)
/* D21784 802418F4 A7A0002C */  sh        $zero, 0x2c($sp)
/* D21788 802418F8 12200006 */  beqz      $s1, .L80241914
/* D2178C 802418FC AFA30024 */   sw       $v1, 0x24($sp)
/* D21790 80241900 02A0202D */  daddu     $a0, $s5, $zero
/* D21794 80241904 0240282D */  daddu     $a1, $s2, $zero
/* D21798 80241908 0280302D */  daddu     $a2, $s4, $zero
/* D2179C 8024190C 0C0905CE */  jal       func_80241738_D215C8
/* D217A0 80241910 0200382D */   daddu    $a3, $s0, $zero
.L80241914:
/* D217A4 80241914 2402FFFE */  addiu     $v0, $zero, -2
/* D217A8 80241918 A2A200AB */  sb        $v0, 0xab($s5)
/* D217AC 8024191C 8E4300B0 */  lw        $v1, 0xb0($s2)
/* D217B0 80241920 30620004 */  andi      $v0, $v1, 4
/* D217B4 80241924 10400007 */  beqz      $v0, .L80241944
/* D217B8 80241928 00000000 */   nop      
/* D217BC 8024192C 824200B4 */  lb        $v0, 0xb4($s2)
/* D217C0 80241930 1440003C */  bnez      $v0, .L80241A24
/* D217C4 80241934 0000102D */   daddu    $v0, $zero, $zero
/* D217C8 80241938 2402FFFB */  addiu     $v0, $zero, -5
/* D217CC 8024193C 00621024 */  and       $v0, $v1, $v0
/* D217D0 80241940 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80241944:
/* D217D4 80241944 8E830070 */  lw        $v1, 0x70($s4)
/* D217D8 80241948 2C62000F */  sltiu     $v0, $v1, 0xf
/* D217DC 8024194C 10400034 */  beqz      $v0, .L80241A20
/* D217E0 80241950 00031080 */   sll      $v0, $v1, 2
/* D217E4 80241954 3C018025 */  lui       $at, 0x8025
/* D217E8 80241958 00220821 */  addu      $at, $at, $v0
/* D217EC 8024195C 8C22BE58 */  lw        $v0, -0x41a8($at)
/* D217F0 80241960 00400008 */  jr        $v0
/* D217F4 80241964 00000000 */   nop      
/* D217F8 80241968 0280202D */  daddu     $a0, $s4, $zero
/* D217FC 8024196C 0200282D */  daddu     $a1, $s0, $zero
/* D21800 80241970 0C090154 */  jal       func_80240550_D203E0
/* D21804 80241974 0260302D */   daddu    $a2, $s3, $zero
/* D21808 80241978 0280202D */  daddu     $a0, $s4, $zero
/* D2180C 8024197C 0200282D */  daddu     $a1, $s0, $zero
/* D21810 80241980 0C0901C0 */  jal       func_80240700_D20590
/* D21814 80241984 0260302D */   daddu    $a2, $s3, $zero
/* D21818 80241988 08090689 */  j         .L80241A24
/* D2181C 8024198C 0000102D */   daddu    $v0, $zero, $zero
/* D21820 80241990 0280202D */  daddu     $a0, $s4, $zero
/* D21824 80241994 0200282D */  daddu     $a1, $s0, $zero
/* D21828 80241998 0C09034A */  jal       func_80240D28_D20BB8
/* D2182C 8024199C 0260302D */   daddu    $a2, $s3, $zero
/* D21830 802419A0 0280202D */  daddu     $a0, $s4, $zero
/* D21834 802419A4 0200282D */  daddu     $a1, $s0, $zero
/* D21838 802419A8 0C09037A */  jal       func_80240DE8_D20C78
/* D2183C 802419AC 0260302D */   daddu    $a2, $s3, $zero
/* D21840 802419B0 08090689 */  j         .L80241A24
/* D21844 802419B4 0000102D */   daddu    $v0, $zero, $zero
/* D21848 802419B8 0280202D */  daddu     $a0, $s4, $zero
/* D2184C 802419BC 0200282D */  daddu     $a1, $s0, $zero
/* D21850 802419C0 0C09044B */  jal       func_8024112C_D20FBC
/* D21854 802419C4 0260302D */   daddu    $a2, $s3, $zero
/* D21858 802419C8 0280202D */  daddu     $a0, $s4, $zero
/* D2185C 802419CC 0200282D */  daddu     $a1, $s0, $zero
/* D21860 802419D0 0C090469 */  jal       func_802411A4_D21034
/* D21864 802419D4 0260302D */   daddu    $a2, $s3, $zero
/* D21868 802419D8 08090689 */  j         .L80241A24
/* D2186C 802419DC 0000102D */   daddu    $v0, $zero, $zero
/* D21870 802419E0 0280202D */  daddu     $a0, $s4, $zero
/* D21874 802419E4 0200282D */  daddu     $a1, $s0, $zero
/* D21878 802419E8 0C090484 */  jal       func_80241210_D210A0
/* D2187C 802419EC 0260302D */   daddu    $a2, $s3, $zero
/* D21880 802419F0 08090689 */  j         .L80241A24
/* D21884 802419F4 0000102D */   daddu    $v0, $zero, $zero
/* D21888 802419F8 0280202D */  daddu     $a0, $s4, $zero
/* D2188C 802419FC 0200282D */  daddu     $a1, $s0, $zero
/* D21890 80241A00 0C0904D1 */  jal       func_80241344_D211D4
/* D21894 80241A04 0260302D */   daddu    $a2, $s3, $zero
/* D21898 80241A08 08090689 */  j         .L80241A24
/* D2189C 80241A0C 0000102D */   daddu    $v0, $zero, $zero
/* D218A0 80241A10 0280202D */  daddu     $a0, $s4, $zero
/* D218A4 80241A14 0200282D */  daddu     $a1, $s0, $zero
/* D218A8 80241A18 0C0904EA */  jal       func_802413A8_D21238
/* D218AC 80241A1C 0260302D */   daddu    $a2, $s3, $zero
.L80241A20:
/* D218B0 80241A20 0000102D */  daddu     $v0, $zero, $zero
.L80241A24:
/* D218B4 80241A24 8FBF0048 */  lw        $ra, 0x48($sp)
/* D218B8 80241A28 8FB50044 */  lw        $s5, 0x44($sp)
/* D218BC 80241A2C 8FB40040 */  lw        $s4, 0x40($sp)
/* D218C0 80241A30 8FB3003C */  lw        $s3, 0x3c($sp)
/* D218C4 80241A34 8FB20038 */  lw        $s2, 0x38($sp)
/* D218C8 80241A38 8FB10034 */  lw        $s1, 0x34($sp)
/* D218CC 80241A3C 8FB00030 */  lw        $s0, 0x30($sp)
/* D218D0 80241A40 03E00008 */  jr        $ra
/* D218D4 80241A44 27BD0050 */   addiu    $sp, $sp, 0x50
