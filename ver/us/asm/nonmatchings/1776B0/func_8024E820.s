.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024E820
/* 17D100 8024E820 3C028028 */  lui       $v0, %hi(D_80280CE0)
/* 17D104 8024E824 80420CE0 */  lb        $v0, %lo(D_80280CE0)($v0)
/* 17D108 8024E828 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17D10C 8024E82C AFB10014 */  sw        $s1, 0x14($sp)
/* 17D110 8024E830 0080882D */  daddu     $s1, $a0, $zero
/* 17D114 8024E834 AFB20018 */  sw        $s2, 0x18($sp)
/* 17D118 8024E838 3C12800B */  lui       $s2, %hi(gCameras+0x558)
/* 17D11C 8024E83C 265222D8 */  addiu     $s2, $s2, %lo(gCameras+0x558)
/* 17D120 8024E840 AFBF001C */  sw        $ra, 0x1c($sp)
/* 17D124 8024E844 AFB00010 */  sw        $s0, 0x10($sp)
/* 17D128 8024E848 8E30000C */  lw        $s0, 0xc($s1)
/* 17D12C 8024E84C 14400029 */  bnez      $v0, .L8024E8F4
/* 17D130 8024E850 24020002 */   addiu    $v0, $zero, 2
/* 17D134 8024E854 8E050000 */  lw        $a1, ($s0)
/* 17D138 8024E858 0C0B1EAF */  jal       get_variable
/* 17D13C 8024E85C 26100004 */   addiu    $s0, $s0, 4
/* 17D140 8024E860 A642001C */  sh        $v0, 0x1c($s2)
/* 17D144 8024E864 8E050000 */  lw        $a1, ($s0)
/* 17D148 8024E868 26100004 */  addiu     $s0, $s0, 4
/* 17D14C 8024E86C 0C0B1EAF */  jal       get_variable
/* 17D150 8024E870 0220202D */   daddu    $a0, $s1, $zero
/* 17D154 8024E874 A642001E */  sh        $v0, 0x1e($s2)
/* 17D158 8024E878 8E050000 */  lw        $a1, ($s0)
/* 17D15C 8024E87C 26100004 */  addiu     $s0, $s0, 4
/* 17D160 8024E880 0C0B1EAF */  jal       get_variable
/* 17D164 8024E884 0220202D */   daddu    $a0, $s1, $zero
/* 17D168 8024E888 A6420020 */  sh        $v0, 0x20($s2)
/* 17D16C 8024E88C 8E050000 */  lw        $a1, ($s0)
/* 17D170 8024E890 26100004 */  addiu     $s0, $s0, 4
/* 17D174 8024E894 0C0B1EAF */  jal       get_variable
/* 17D178 8024E898 0220202D */   daddu    $a0, $s1, $zero
/* 17D17C 8024E89C A6420022 */  sh        $v0, 0x22($s2)
/* 17D180 8024E8A0 8E050000 */  lw        $a1, ($s0)
/* 17D184 8024E8A4 26100004 */  addiu     $s0, $s0, 4
/* 17D188 8024E8A8 0C0B1EAF */  jal       get_variable
/* 17D18C 8024E8AC 0220202D */   daddu    $a0, $s1, $zero
/* 17D190 8024E8B0 A6420024 */  sh        $v0, 0x24($s2)
/* 17D194 8024E8B4 8E050000 */  lw        $a1, ($s0)
/* 17D198 8024E8B8 26100004 */  addiu     $s0, $s0, 4
/* 17D19C 8024E8BC 0C0B1EAF */  jal       get_variable
/* 17D1A0 8024E8C0 0220202D */   daddu    $a0, $s1, $zero
/* 17D1A4 8024E8C4 00021200 */  sll       $v0, $v0, 8
/* 17D1A8 8024E8C8 A6420026 */  sh        $v0, 0x26($s2)
/* 17D1AC 8024E8CC 8E050000 */  lw        $a1, ($s0)
/* 17D1B0 8024E8D0 26100004 */  addiu     $s0, $s0, 4
/* 17D1B4 8024E8D4 0C0B1EAF */  jal       get_variable
/* 17D1B8 8024E8D8 0220202D */   daddu    $a0, $s1, $zero
/* 17D1BC 8024E8DC A6420028 */  sh        $v0, 0x28($s2)
/* 17D1C0 8024E8E0 8E050000 */  lw        $a1, ($s0)
/* 17D1C4 8024E8E4 0C0B1EAF */  jal       get_variable
/* 17D1C8 8024E8E8 0220202D */   daddu    $a0, $s1, $zero
/* 17D1CC 8024E8EC A642002A */  sh        $v0, 0x2a($s2)
/* 17D1D0 8024E8F0 24020002 */  addiu     $v0, $zero, 2
.L8024E8F4:
/* 17D1D4 8024E8F4 8FBF001C */  lw        $ra, 0x1c($sp)
/* 17D1D8 8024E8F8 8FB20018 */  lw        $s2, 0x18($sp)
/* 17D1DC 8024E8FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 17D1E0 8024E900 8FB00010 */  lw        $s0, 0x10($sp)
/* 17D1E4 8024E904 03E00008 */  jr        $ra
/* 17D1E8 8024E908 27BD0020 */   addiu    $sp, $sp, 0x20
