.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240624_EED724
/* EED724 80240624 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EED728 80240628 AFBF0018 */  sw        $ra, 0x18($sp)
/* EED72C 8024062C 8C82000C */  lw        $v0, 0xc($a0)
/* EED730 80240630 0C0B53A3 */  jal       dead_evt_get_variable
/* EED734 80240634 8C450000 */   lw       $a1, ($v0)
/* EED738 80240638 0C0462EC */  jal       func_80118BB0
/* EED73C 8024063C 0040202D */   daddu    $a0, $v0, $zero
/* EED740 80240640 3C013F80 */  lui       $at, 0x3f80
/* EED744 80240644 44810000 */  mtc1      $at, $f0
/* EED748 80240648 C442004C */  lwc1      $f2, 0x4c($v0)
/* EED74C 8024064C E7A00010 */  swc1      $f0, 0x10($sp)
/* EED750 80240650 3C014148 */  lui       $at, 0x4148
/* EED754 80240654 44810000 */  mtc1      $at, $f0
/* EED758 80240658 2403004B */  addiu     $v1, $zero, 0x4b
/* EED75C 8024065C AFA30014 */  sw        $v1, 0x14($sp)
/* EED760 80240660 46001080 */  add.s     $f2, $f2, $f0
/* EED764 80240664 8C450048 */  lw        $a1, 0x48($v0)
/* EED768 80240668 8C470050 */  lw        $a3, 0x50($v0)
/* EED76C 8024066C 44061000 */  mfc1      $a2, $f2
/* EED770 80240670 0C01D78C */  jal       func_80075E30
/* EED774 80240674 24040004 */   addiu    $a0, $zero, 4
/* EED778 80240678 8FBF0018 */  lw        $ra, 0x18($sp)
/* EED77C 8024067C 24020002 */  addiu     $v0, $zero, 2
/* EED780 80240680 03E00008 */  jr        $ra
/* EED784 80240684 27BD0020 */   addiu    $sp, $sp, 0x20
