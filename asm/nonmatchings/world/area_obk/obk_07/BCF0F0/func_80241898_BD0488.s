.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241898_BD0488
/* BD0488 80241898 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BD048C 8024189C AFB00010 */  sw        $s0, 0x10($sp)
/* BD0490 802418A0 AFBF0014 */  sw        $ra, 0x14($sp)
/* BD0494 802418A4 0C090150 */  jal       func_80240540_BCF130
/* BD0498 802418A8 0080802D */   daddu    $s0, $a0, $zero
/* BD049C 802418AC 0040182D */  daddu     $v1, $v0, $zero
/* BD04A0 802418B0 AC6001D4 */  sw        $zero, 0x1d4($v1)
/* BD04A4 802418B4 AC6001D8 */  sw        $zero, 0x1d8($v1)
/* BD04A8 802418B8 A06001DC */  sb        $zero, 0x1dc($v1)
/* BD04AC 802418BC AC600004 */  sw        $zero, 4($v1)
/* BD04B0 802418C0 AC600030 */  sw        $zero, 0x30($v1)
/* BD04B4 802418C4 AE0000AC */  sw        $zero, 0xac($s0)
/* BD04B8 802418C8 AE0000B0 */  sw        $zero, 0xb0($s0)
/* BD04BC 802418CC 8FBF0014 */  lw        $ra, 0x14($sp)
/* BD04C0 802418D0 8FB00010 */  lw        $s0, 0x10($sp)
/* BD04C4 802418D4 24020002 */  addiu     $v0, $zero, 2
/* BD04C8 802418D8 03E00008 */  jr        $ra
/* BD04CC 802418DC 27BD0018 */   addiu    $sp, $sp, 0x18
