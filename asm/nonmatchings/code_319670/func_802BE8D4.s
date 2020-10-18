.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BE8D4
/* 31AE44 802BE8D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 31AE48 802BE8D8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 31AE4C 802BE8DC AFB00010 */  sw        $s0, 0x10($sp)
/* 31AE50 802BE8E0 10A00003 */  beqz      $a1, .L802BE8F0
/* 31AE54 802BE8E4 8C90014C */   lw       $s0, 0x14c($a0)
/* 31AE58 802BE8E8 0C03BA65 */  jal       func_800EE994
/* 31AE5C 802BE8EC 0200202D */   daddu    $a0, $s0, $zero
.L802BE8F0:
/* 31AE60 802BE8F0 0C03BA6E */  jal       func_800EE9B8
/* 31AE64 802BE8F4 0200202D */   daddu    $a0, $s0, $zero
/* 31AE68 802BE8F8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 31AE6C 802BE8FC 8FB00010 */  lw        $s0, 0x10($sp)
/* 31AE70 802BE900 0002102B */  sltu      $v0, $zero, $v0
/* 31AE74 802BE904 03E00008 */  jr        $ra
/* 31AE78 802BE908 27BD0018 */   addiu    $sp, $sp, 0x18
