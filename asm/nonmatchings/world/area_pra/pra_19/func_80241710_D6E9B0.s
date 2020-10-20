.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241710_D700C0
/* D700C0 80241710 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D700C4 80241714 AFB00010 */  sw        $s0, 0x10($sp)
/* D700C8 80241718 0080802D */  daddu     $s0, $a0, $zero
/* D700CC 8024171C AFBF0014 */  sw        $ra, 0x14($sp)
/* D700D0 80241720 0C0B36B0 */  jal       resolve_npc
/* D700D4 80241724 8E050090 */   lw       $a1, 0x90($s0)
/* D700D8 80241728 0200202D */  daddu     $a0, $s0, $zero
/* D700DC 8024172C 8C850094 */  lw        $a1, 0x94($a0)
/* D700E0 80241730 0C0B36B0 */  jal       resolve_npc
/* D700E4 80241734 0040802D */   daddu    $s0, $v0, $zero
/* D700E8 80241738 944300A6 */  lhu       $v1, 0xa6($v0)
/* D700EC 8024173C A60300A6 */  sh        $v1, 0xa6($s0)
/* D700F0 80241740 944300A8 */  lhu       $v1, 0xa8($v0)
/* D700F4 80241744 A60300A8 */  sh        $v1, 0xa8($s0)
/* D700F8 80241748 8FBF0014 */  lw        $ra, 0x14($sp)
/* D700FC 8024174C 8FB00010 */  lw        $s0, 0x10($sp)
/* D70100 80241750 24020002 */  addiu     $v0, $zero, 2
/* D70104 80241754 03E00008 */  jr        $ra
/* D70108 80241758 27BD0018 */   addiu    $sp, $sp, 0x18
