.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415F8_D59E88
/* D59E88 802415F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D59E8C 802415FC AFB00010 */  sw        $s0, 0x10($sp)
/* D59E90 80241600 0080802D */  daddu     $s0, $a0, $zero
/* D59E94 80241604 AFBF0014 */  sw        $ra, 0x14($sp)
/* D59E98 80241608 0C0B36B0 */  jal       resolve_npc
/* D59E9C 8024160C 8E050090 */   lw       $a1, 0x90($s0)
/* D59EA0 80241610 0200202D */  daddu     $a0, $s0, $zero
/* D59EA4 80241614 8C850094 */  lw        $a1, 0x94($a0)
/* D59EA8 80241618 0C0B36B0 */  jal       resolve_npc
/* D59EAC 8024161C 0040802D */   daddu    $s0, $v0, $zero
/* D59EB0 80241620 944300A6 */  lhu       $v1, 0xa6($v0)
/* D59EB4 80241624 A60300A6 */  sh        $v1, 0xa6($s0)
/* D59EB8 80241628 944300A8 */  lhu       $v1, 0xa8($v0)
/* D59EBC 8024162C A60300A8 */  sh        $v1, 0xa8($s0)
/* D59EC0 80241630 8FBF0014 */  lw        $ra, 0x14($sp)
/* D59EC4 80241634 8FB00010 */  lw        $s0, 0x10($sp)
/* D59EC8 80241638 24020002 */  addiu     $v0, $zero, 2
/* D59ECC 8024163C 03E00008 */  jr        $ra
/* D59ED0 80241640 27BD0018 */   addiu    $sp, $sp, 0x18
/* D59ED4 80241644 00000000 */  nop       
/* D59ED8 80241648 00000000 */  nop       
/* D59EDC 8024164C 00000000 */  nop       
