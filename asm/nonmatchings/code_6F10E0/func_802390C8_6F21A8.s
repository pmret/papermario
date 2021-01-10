.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802390C8_6F21A8
/* 6F21A8 802390C8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 6F21AC 802390CC AFB1001C */  sw        $s1, 0x1c($sp)
/* 6F21B0 802390D0 0080882D */  daddu     $s1, $a0, $zero
/* 6F21B4 802390D4 AFBF0028 */  sw        $ra, 0x28($sp)
/* 6F21B8 802390D8 AFB30024 */  sw        $s3, 0x24($sp)
/* 6F21BC 802390DC AFB20020 */  sw        $s2, 0x20($sp)
/* 6F21C0 802390E0 AFB00018 */  sw        $s0, 0x18($sp)
/* 6F21C4 802390E4 8E30000C */  lw        $s0, 0xc($s1)
/* 6F21C8 802390E8 8E050000 */  lw        $a1, ($s0)
/* 6F21CC 802390EC 0C0B1EAF */  jal       get_variable
/* 6F21D0 802390F0 26100004 */   addiu    $s0, $s0, 4
/* 6F21D4 802390F4 8E050000 */  lw        $a1, ($s0)
/* 6F21D8 802390F8 26100004 */  addiu     $s0, $s0, 4
/* 6F21DC 802390FC 0220202D */  daddu     $a0, $s1, $zero
/* 6F21E0 80239100 0C0B1EAF */  jal       get_variable
/* 6F21E4 80239104 0040982D */   daddu    $s3, $v0, $zero
/* 6F21E8 80239108 8E050000 */  lw        $a1, ($s0)
/* 6F21EC 8023910C 26100004 */  addiu     $s0, $s0, 4
/* 6F21F0 80239110 0220202D */  daddu     $a0, $s1, $zero
/* 6F21F4 80239114 0C0B1EAF */  jal       get_variable
/* 6F21F8 80239118 0040902D */   daddu    $s2, $v0, $zero
/* 6F21FC 8023911C 0220202D */  daddu     $a0, $s1, $zero
/* 6F2200 80239120 8E050000 */  lw        $a1, ($s0)
/* 6F2204 80239124 0C0B210B */  jal       get_float_variable
/* 6F2208 80239128 0040802D */   daddu    $s0, $v0, $zero
/* 6F220C 8023912C 24040006 */  addiu     $a0, $zero, 6
/* 6F2210 80239130 44931000 */  mtc1      $s3, $f2
/* 6F2214 80239134 00000000 */  nop       
/* 6F2218 80239138 468010A0 */  cvt.s.w   $f2, $f2
/* 6F221C 8023913C 44051000 */  mfc1      $a1, $f2
/* 6F2220 80239140 44921000 */  mtc1      $s2, $f2
/* 6F2224 80239144 00000000 */  nop       
/* 6F2228 80239148 468010A0 */  cvt.s.w   $f2, $f2
/* 6F222C 8023914C 44061000 */  mfc1      $a2, $f2
/* 6F2230 80239150 44901000 */  mtc1      $s0, $f2
/* 6F2234 80239154 00000000 */  nop       
/* 6F2238 80239158 468010A0 */  cvt.s.w   $f2, $f2
/* 6F223C 8023915C 44071000 */  mfc1      $a3, $f2
/* 6F2240 80239160 2402002D */  addiu     $v0, $zero, 0x2d
/* 6F2244 80239164 E7A00010 */  swc1      $f0, 0x10($sp)
/* 6F2248 80239168 0C01C82C */  jal       func_800720B0
/* 6F224C 8023916C AFA20014 */   sw       $v0, 0x14($sp)
/* 6F2250 80239170 8FBF0028 */  lw        $ra, 0x28($sp)
/* 6F2254 80239174 8FB30024 */  lw        $s3, 0x24($sp)
/* 6F2258 80239178 8FB20020 */  lw        $s2, 0x20($sp)
/* 6F225C 8023917C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 6F2260 80239180 8FB00018 */  lw        $s0, 0x18($sp)
/* 6F2264 80239184 24020002 */  addiu     $v0, $zero, 2
/* 6F2268 80239188 03E00008 */  jr        $ra
/* 6F226C 8023918C 27BD0030 */   addiu    $sp, $sp, 0x30
