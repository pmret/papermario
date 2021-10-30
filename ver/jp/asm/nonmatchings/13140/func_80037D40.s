.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80037D40
/* 13140 80037D40 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13144 80037D44 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* 13148 80037D48 2484417C */  addiu     $a0, $a0, %lo(gGameStatusPtr)
/* 1314C 80037D4C AFBF0010 */  sw        $ra, 0x10($sp)
/* 13150 80037D50 8C830000 */  lw        $v1, ($a0)
/* 13154 80037D54 80620071 */  lb        $v0, 0x71($v1)
/* 13158 80037D58 14400004 */  bnez      $v0, .L80037D6C
/* 1315C 80037D5C 24020001 */   addiu    $v0, $zero, 1
/* 13160 80037D60 A0600072 */  sb        $zero, 0x72($v1)
/* 13164 80037D64 8C830000 */  lw        $v1, ($a0)
/* 13168 80037D68 A0620071 */  sb        $v0, 0x71($v1)
.L80037D6C:
/* 1316C 80037D6C 8C820000 */  lw        $v0, ($a0)
/* 13170 80037D70 A040006A */  sb        $zero, 0x6a($v0)
/* 13174 80037D74 8C830000 */  lw        $v1, ($a0)
/* 13178 80037D78 A4400068 */  sh        $zero, 0x68($v0)
/* 1317C 80037D7C 0C0157B6 */  jal       func_80055ED8
/* 13180 80037D80 A060006B */   sb       $zero, 0x6b($v1)
/* 13184 80037D84 0C04F4D4 */  jal       func_8013D350
/* 13188 80037D88 24040002 */   addiu    $a0, $zero, 2
/* 1318C 80037D8C 3C05437F */  lui       $a1, 0x437f
/* 13190 80037D90 0C04F38E */  jal       func_8013CE38
/* 13194 80037D94 0000202D */   daddu    $a0, $zero, $zero
/* 13198 80037D98 0C0528F4 */  jal       func_8014A3D0
/* 1319C 80037D9C 00000000 */   nop
/* 131A0 80037DA0 0C0B0C77 */  jal       func_802C31DC
/* 131A4 80037DA4 00000000 */   nop
/* 131A8 80037DA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 131AC 80037DAC 03E00008 */  jr        $ra
/* 131B0 80037DB0 27BD0018 */   addiu    $sp, $sp, 0x18
