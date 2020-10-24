.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024143C_BD002C
/* BD002C 8024143C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD0030 80241440 AFB00010 */  sw        $s0, 0x10($sp)
/* BD0034 80241444 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD0038 80241448 0C090150 */  jal       func_80240540_BCF130
/* BD003C 8024144C 0080802D */   daddu    $s0, $a0, $zero
/* BD0040 80241450 24020096 */  addiu     $v0, $zero, 0x96
/* BD0044 80241454 AE020090 */  sw        $v0, 0x90($s0)
/* BD0048 80241458 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD004C 8024145C 8FB00010 */  lw        $s0, 0x10($sp)
/* BD0050 80241460 24020002 */  addiu     $v0, $zero, 2
/* BD0054 80241464 03E00008 */  jr        $ra
/* BD0058 80241468 27BD0018 */   addiu    $sp, $sp, 0x18
