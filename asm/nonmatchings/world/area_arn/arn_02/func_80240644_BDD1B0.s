.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240644_BDD7F4
/* BDD7F4 80240644 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BDD7F8 80240648 AFB10014 */  sw        $s1, 0x14($sp)
/* BDD7FC 8024064C 0080882D */  daddu     $s1, $a0, $zero
/* BDD800 80240650 AFBF0018 */  sw        $ra, 0x18($sp)
/* BDD804 80240654 AFB00010 */  sw        $s0, 0x10($sp)
/* BDD808 80240658 8E300148 */  lw        $s0, 0x148($s1)
/* BDD80C 8024065C 0C00EABB */  jal       get_npc_unsafe
/* BDD810 80240660 86040008 */   lh       $a0, 8($s0)
/* BDD814 80240664 96030096 */  lhu       $v1, 0x96($s0)
/* BDD818 80240668 A443008E */  sh        $v1, 0x8e($v0)
/* BDD81C 8024066C 8E0300CC */  lw        $v1, 0xcc($s0)
/* BDD820 80240670 8C630034 */  lw        $v1, 0x34($v1)
/* BDD824 80240674 AC430028 */  sw        $v1, 0x28($v0)
/* BDD828 80240678 24020015 */  addiu     $v0, $zero, 0x15
/* BDD82C 8024067C AE220070 */  sw        $v0, 0x70($s1)
/* BDD830 80240680 8FBF0018 */  lw        $ra, 0x18($sp)
/* BDD834 80240684 8FB10014 */  lw        $s1, 0x14($sp)
/* BDD838 80240688 8FB00010 */  lw        $s0, 0x10($sp)
/* BDD83C 8024068C 03E00008 */  jr        $ra
/* BDD840 80240690 27BD0020 */   addiu    $sp, $sp, 0x20
