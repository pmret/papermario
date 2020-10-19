.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242840
/* E07BA0 80242840 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E07BA4 80242844 AFB00010 */  sw        $s0, 0x10($sp)
/* E07BA8 80242848 0080802D */  daddu     $s0, $a0, $zero
/* E07BAC 8024284C AFBF0014 */  sw        $ra, 0x14($sp)
/* E07BB0 80242850 10A00006 */  beqz      $a1, .L8024286C
/* E07BB4 80242854 8E02000C */   lw       $v0, 0xc($s0)
/* E07BB8 80242858 0C0B1EAF */  jal       get_variable
/* E07BBC 8024285C 8C450000 */   lw       $a1, ($v0)
/* E07BC0 80242860 0C00EABB */  jal       get_npc_unsafe
/* E07BC4 80242864 0040202D */   daddu    $a0, $v0, $zero
/* E07BC8 80242868 AE020074 */  sw        $v0, 0x74($s0)
.L8024286C:
/* E07BCC 8024286C 8E030074 */  lw        $v1, 0x74($s0)
/* E07BD0 80242870 3C013F2A */  lui       $at, 0x3f2a
/* E07BD4 80242874 3421AAAB */  ori       $at, $at, 0xaaab
/* E07BD8 80242878 44811000 */  mtc1      $at, $f2
/* E07BDC 8024287C C4600038 */  lwc1      $f0, 0x38($v1)
/* E07BE0 80242880 46020000 */  add.s     $f0, $f0, $f2
/* E07BE4 80242884 E4600038 */  swc1      $f0, 0x38($v1)
/* E07BE8 80242888 8FBF0014 */  lw        $ra, 0x14($sp)
/* E07BEC 8024288C 8FB00010 */  lw        $s0, 0x10($sp)
/* E07BF0 80242890 0000102D */  daddu     $v0, $zero, $zero
/* E07BF4 80242894 03E00008 */  jr        $ra
/* E07BF8 80242898 27BD0018 */   addiu    $sp, $sp, 0x18
