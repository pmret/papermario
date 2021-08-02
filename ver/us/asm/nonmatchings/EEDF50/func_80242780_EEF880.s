.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802454B0_EF25B0
.word L802428BC_EEF9BC, L802428CC_EEF9CC, L802428E4_EEF9E4, L802428F4_EEF9F4, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024290C_EEFA0C, L8024291C_EEFA1C, L80242934_EEFA34, L80242944_EEFA44, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024296C_EEFA6C, L8024295C_EEFA5C, 0, 0, 0

.section .text

glabel func_80242780_EEF880
/* EEF880 80242780 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* EEF884 80242784 AFB40040 */  sw        $s4, 0x40($sp)
/* EEF888 80242788 0080A02D */  daddu     $s4, $a0, $zero
/* EEF88C 8024278C AFBF0048 */  sw        $ra, 0x48($sp)
/* EEF890 80242790 AFB50044 */  sw        $s5, 0x44($sp)
/* EEF894 80242794 AFB3003C */  sw        $s3, 0x3c($sp)
/* EEF898 80242798 AFB20038 */  sw        $s2, 0x38($sp)
/* EEF89C 8024279C AFB10034 */  sw        $s1, 0x34($sp)
/* EEF8A0 802427A0 AFB00030 */  sw        $s0, 0x30($sp)
/* EEF8A4 802427A4 8E920148 */  lw        $s2, 0x148($s4)
/* EEF8A8 802427A8 86440008 */  lh        $a0, 8($s2)
/* EEF8AC 802427AC 8E90000C */  lw        $s0, 0xc($s4)
/* EEF8B0 802427B0 0C00F92F */  jal       dead_get_npc_unsafe
/* EEF8B4 802427B4 00A0882D */   daddu    $s1, $a1, $zero
/* EEF8B8 802427B8 0280202D */  daddu     $a0, $s4, $zero
/* EEF8BC 802427BC 8E050000 */  lw        $a1, ($s0)
/* EEF8C0 802427C0 0C0B53A3 */  jal       dead_get_variable
/* EEF8C4 802427C4 0040A82D */   daddu    $s5, $v0, $zero
/* EEF8C8 802427C8 AFA00010 */  sw        $zero, 0x10($sp)
/* EEF8CC 802427CC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF8D0 802427D0 8C630030 */  lw        $v1, 0x30($v1)
/* EEF8D4 802427D4 AFA30014 */  sw        $v1, 0x14($sp)
/* EEF8D8 802427D8 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF8DC 802427DC 8C63001C */  lw        $v1, 0x1c($v1)
/* EEF8E0 802427E0 AFA30018 */  sw        $v1, 0x18($sp)
/* EEF8E4 802427E4 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF8E8 802427E8 8C630024 */  lw        $v1, 0x24($v1)
/* EEF8EC 802427EC AFA3001C */  sw        $v1, 0x1c($sp)
/* EEF8F0 802427F0 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF8F4 802427F4 8C630028 */  lw        $v1, 0x28($v1)
/* EEF8F8 802427F8 AFA30020 */  sw        $v1, 0x20($sp)
/* EEF8FC 802427FC 8E4300D0 */  lw        $v1, 0xd0($s2)
/* EEF900 80242800 3C0142F0 */  lui       $at, 0x42f0
/* EEF904 80242804 44810000 */  mtc1      $at, $f0
/* EEF908 80242808 8C63002C */  lw        $v1, 0x2c($v1)
/* EEF90C 8024280C E7A00028 */  swc1      $f0, 0x28($sp)
/* EEF910 80242810 A7A0002C */  sh        $zero, 0x2c($sp)
/* EEF914 80242814 AFA30024 */  sw        $v1, 0x24($sp)
/* EEF918 80242818 C6A00038 */  lwc1      $f0, 0x38($s5)
/* EEF91C 8024281C E6400108 */  swc1      $f0, 0x108($s2)
/* EEF920 80242820 C6A0003C */  lwc1      $f0, 0x3c($s5)
/* EEF924 80242824 27B30010 */  addiu     $s3, $sp, 0x10
/* EEF928 80242828 E640010C */  swc1      $f0, 0x10c($s2)
/* EEF92C 8024282C 3C0138D1 */  lui       $at, 0x38d1
/* EEF930 80242830 3421B717 */  ori       $at, $at, 0xb717
/* EEF934 80242834 44810000 */  mtc1      $at, $f0
/* EEF938 80242838 C6A20040 */  lwc1      $f2, 0x40($s5)
/* EEF93C 8024283C 0040802D */  daddu     $s0, $v0, $zero
/* EEF940 80242840 E6400114 */  swc1      $f0, 0x114($s2)
/* EEF944 80242844 E6400118 */  swc1      $f0, 0x118($s2)
/* EEF948 80242848 12200007 */  beqz      $s1, .L80242868
/* EEF94C 8024284C E6420110 */   swc1     $f2, 0x110($s2)
/* EEF950 80242850 02A0202D */  daddu     $a0, $s5, $zero
/* EEF954 80242854 0240282D */  daddu     $a1, $s2, $zero
/* EEF958 80242858 0280302D */  daddu     $a2, $s4, $zero
/* EEF95C 8024285C 0C09080E */  jal       func_80242038_EEF138
/* EEF960 80242860 0200382D */   daddu    $a3, $s0, $zero
/* EEF964 80242864 AE800070 */  sw        $zero, 0x70($s4)
.L80242868:
/* EEF968 80242868 2402FFFE */  addiu     $v0, $zero, -2
/* EEF96C 8024286C A2A200AB */  sb        $v0, 0xab($s5)
/* EEF970 80242870 8E4300B0 */  lw        $v1, 0xb0($s2)
/* EEF974 80242874 30620004 */  andi      $v0, $v1, 4
/* EEF978 80242878 10400007 */  beqz      $v0, .L80242898
/* EEF97C 8024287C 00000000 */   nop
/* EEF980 80242880 824200B4 */  lb        $v0, 0xb4($s2)
/* EEF984 80242884 1440003A */  bnez      $v0, .L80242970
/* EEF988 80242888 0000102D */   daddu    $v0, $zero, $zero
/* EEF98C 8024288C 2402FFFB */  addiu     $v0, $zero, -5
/* EEF990 80242890 00621024 */  and       $v0, $v1, $v0
/* EEF994 80242894 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80242898:
/* EEF998 80242898 8E830070 */  lw        $v1, 0x70($s4)
/* EEF99C 8024289C 2C620015 */  sltiu     $v0, $v1, 0x15
/* EEF9A0 802428A0 10400032 */  beqz      $v0, L8024296C_EEFA6C
/* EEF9A4 802428A4 00031080 */   sll      $v0, $v1, 2
/* EEF9A8 802428A8 3C018024 */  lui       $at, %hi(jtbl_802454B0_EF25B0)
/* EEF9AC 802428AC 00220821 */  addu      $at, $at, $v0
/* EEF9B0 802428B0 8C2254B0 */  lw        $v0, %lo(jtbl_802454B0_EF25B0)($at)
/* EEF9B4 802428B4 00400008 */  jr        $v0
/* EEF9B8 802428B8 00000000 */   nop
glabel L802428BC_EEF9BC
/* EEF9BC 802428BC 0280202D */  daddu     $a0, $s4, $zero
/* EEF9C0 802428C0 0200282D */  daddu     $a1, $s0, $zero
/* EEF9C4 802428C4 0C090394 */  jal       func_80240E50_EEDF50
/* EEF9C8 802428C8 0260302D */   daddu    $a2, $s3, $zero
glabel L802428CC_EEF9CC
/* EEF9CC 802428CC 0280202D */  daddu     $a0, $s4, $zero
/* EEF9D0 802428D0 0200282D */  daddu     $a1, $s0, $zero
/* EEF9D4 802428D4 0C090400 */  jal       func_80241000_EEE100
/* EEF9D8 802428D8 0260302D */   daddu    $a2, $s3, $zero
/* EEF9DC 802428DC 08090A5C */  j         .L80242970
/* EEF9E0 802428E0 0000102D */   daddu    $v0, $zero, $zero
glabel L802428E4_EEF9E4
/* EEF9E4 802428E4 0280202D */  daddu     $a0, $s4, $zero
/* EEF9E8 802428E8 0200282D */  daddu     $a1, $s0, $zero
/* EEF9EC 802428EC 0C09058A */  jal       EEDF50_DeadUnkNpcAIFunc1
/* EEF9F0 802428F0 0260302D */   daddu    $a2, $s3, $zero
glabel L802428F4_EEF9F4
/* EEF9F4 802428F4 0280202D */  daddu     $a0, $s4, $zero
/* EEF9F8 802428F8 0200282D */  daddu     $a1, $s0, $zero
/* EEF9FC 802428FC 0C0905BA */  jal       func_802416E8_EEE7E8
/* EEFA00 80242900 0260302D */   daddu    $a2, $s3, $zero
/* EEFA04 80242904 08090A5C */  j         .L80242970
/* EEFA08 80242908 0000102D */   daddu    $v0, $zero, $zero
glabel L8024290C_EEFA0C
/* EEFA0C 8024290C 0280202D */  daddu     $a0, $s4, $zero
/* EEFA10 80242910 0200282D */  daddu     $a1, $s0, $zero
/* EEFA14 80242914 0C09068B */  jal       func_80241A2C_EEEB2C
/* EEFA18 80242918 0260302D */   daddu    $a2, $s3, $zero
glabel L8024291C_EEFA1C
/* EEFA1C 8024291C 0280202D */  daddu     $a0, $s4, $zero
/* EEFA20 80242920 0200282D */  daddu     $a1, $s0, $zero
/* EEFA24 80242924 0C0906A9 */  jal       func_80241AA4_EEEBA4
/* EEFA28 80242928 0260302D */   daddu    $a2, $s3, $zero
/* EEFA2C 8024292C 08090A5C */  j         .L80242970
/* EEFA30 80242930 0000102D */   daddu    $v0, $zero, $zero
glabel L80242934_EEFA34
/* EEFA34 80242934 0280202D */  daddu     $a0, $s4, $zero
/* EEFA38 80242938 0200282D */  daddu     $a1, $s0, $zero
/* EEFA3C 8024293C 0C0908DD */  jal       func_80242374_EEF474
/* EEFA40 80242940 0260302D */   daddu    $a2, $s3, $zero
glabel L80242944_EEFA44
/* EEFA44 80242944 0280202D */  daddu     $a0, $s4, $zero
/* EEFA48 80242948 0200282D */  daddu     $a1, $s0, $zero
/* EEFA4C 8024294C 0C090929 */  jal       func_802424A4_EEF5A4
/* EEFA50 80242950 0260302D */   daddu    $a2, $s3, $zero
/* EEFA54 80242954 08090A5C */  j         .L80242970
/* EEFA58 80242958 0000102D */   daddu    $v0, $zero, $zero
glabel L8024295C_EEFA5C
/* EEFA5C 8024295C 0280202D */  daddu     $a0, $s4, $zero
/* EEFA60 80242960 0200282D */  daddu     $a1, $s0, $zero
/* EEFA64 80242964 0C0909C9 */  jal       func_80242724_EEF824
/* EEFA68 80242968 0260302D */   daddu    $a2, $s3, $zero
glabel L8024296C_EEFA6C
/* EEFA6C 8024296C 0000102D */  daddu     $v0, $zero, $zero
.L80242970:
/* EEFA70 80242970 8FBF0048 */  lw        $ra, 0x48($sp)
/* EEFA74 80242974 8FB50044 */  lw        $s5, 0x44($sp)
/* EEFA78 80242978 8FB40040 */  lw        $s4, 0x40($sp)
/* EEFA7C 8024297C 8FB3003C */  lw        $s3, 0x3c($sp)
/* EEFA80 80242980 8FB20038 */  lw        $s2, 0x38($sp)
/* EEFA84 80242984 8FB10034 */  lw        $s1, 0x34($sp)
/* EEFA88 80242988 8FB00030 */  lw        $s0, 0x30($sp)
/* EEFA8C 8024298C 03E00008 */  jr        $ra
/* EEFA90 80242990 27BD0050 */   addiu    $sp, $sp, 0x50
/* EEFA94 80242994 00000000 */  nop
/* EEFA98 80242998 00000000 */  nop
/* EEFA9C 8024299C 00000000 */  nop
