.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024224C_D220DC
/* D220DC 8024224C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D220E0 80242250 AFB10014 */  sw        $s1, 0x14($sp)
/* D220E4 80242254 0080882D */  daddu     $s1, $a0, $zero
/* D220E8 80242258 AFBF0018 */  sw        $ra, 0x18($sp)
/* D220EC 8024225C AFB00010 */  sw        $s0, 0x10($sp)
/* D220F0 80242260 8E30000C */  lw        $s0, 0xc($s1)
/* D220F4 80242264 8E050000 */  lw        $a1, ($s0)
/* D220F8 80242268 0C0B1EAF */  jal       get_variable
/* D220FC 8024226C 26100004 */   addiu    $s0, $s0, 4
/* D22100 80242270 AE22008C */  sw        $v0, 0x8c($s1)
/* D22104 80242274 8E050000 */  lw        $a1, ($s0)
/* D22108 80242278 26100004 */  addiu     $s0, $s0, 4
/* D2210C 8024227C 0C0B1EAF */  jal       get_variable
/* D22110 80242280 0220202D */   daddu    $a0, $s1, $zero
/* D22114 80242284 AE220090 */  sw        $v0, 0x90($s1)
/* D22118 80242288 8E050000 */  lw        $a1, ($s0)
/* D2211C 8024228C 26100004 */  addiu     $s0, $s0, 4
/* D22120 80242290 0C0B1EAF */  jal       get_variable
/* D22124 80242294 0220202D */   daddu    $a0, $s1, $zero
/* D22128 80242298 AE220094 */  sw        $v0, 0x94($s1)
/* D2212C 8024229C 8E050000 */  lw        $a1, ($s0)
/* D22130 802422A0 26100004 */  addiu     $s0, $s0, 4
/* D22134 802422A4 0C0B1EAF */  jal       get_variable
/* D22138 802422A8 0220202D */   daddu    $a0, $s1, $zero
/* D2213C 802422AC AE220098 */  sw        $v0, 0x98($s1)
/* D22140 802422B0 8E050000 */  lw        $a1, ($s0)
/* D22144 802422B4 26100004 */  addiu     $s0, $s0, 4
/* D22148 802422B8 0C0B1EAF */  jal       get_variable
/* D2214C 802422BC 0220202D */   daddu    $a0, $s1, $zero
/* D22150 802422C0 AE22009C */  sw        $v0, 0x9c($s1)
/* D22154 802422C4 8E050000 */  lw        $a1, ($s0)
/* D22158 802422C8 26100004 */  addiu     $s0, $s0, 4
/* D2215C 802422CC 0C0B1EAF */  jal       get_variable
/* D22160 802422D0 0220202D */   daddu    $a0, $s1, $zero
/* D22164 802422D4 AE2200A0 */  sw        $v0, 0xa0($s1)
/* D22168 802422D8 8E050000 */  lw        $a1, ($s0)
/* D2216C 802422DC 26100004 */  addiu     $s0, $s0, 4
/* D22170 802422E0 0C0B1EAF */  jal       get_variable
/* D22174 802422E4 0220202D */   daddu    $a0, $s1, $zero
/* D22178 802422E8 AE2200A4 */  sw        $v0, 0xa4($s1)
/* D2217C 802422EC 8E050000 */  lw        $a1, ($s0)
/* D22180 802422F0 26100004 */  addiu     $s0, $s0, 4
/* D22184 802422F4 0C0B1EAF */  jal       get_variable
/* D22188 802422F8 0220202D */   daddu    $a0, $s1, $zero
/* D2218C 802422FC AE2200A8 */  sw        $v0, 0xa8($s1)
/* D22190 80242300 8E050000 */  lw        $a1, ($s0)
/* D22194 80242304 26100004 */  addiu     $s0, $s0, 4
/* D22198 80242308 0C0B1EAF */  jal       get_variable
/* D2219C 8024230C 0220202D */   daddu    $a0, $s1, $zero
/* D221A0 80242310 AE2200AC */  sw        $v0, 0xac($s1)
/* D221A4 80242314 8E050000 */  lw        $a1, ($s0)
/* D221A8 80242318 0C0B1EAF */  jal       get_variable
/* D221AC 8024231C 0220202D */   daddu    $a0, $s1, $zero
/* D221B0 80242320 AE2200B0 */  sw        $v0, 0xb0($s1)
/* D221B4 80242324 8FBF0018 */  lw        $ra, 0x18($sp)
/* D221B8 80242328 8FB10014 */  lw        $s1, 0x14($sp)
/* D221BC 8024232C 8FB00010 */  lw        $s0, 0x10($sp)
/* D221C0 80242330 24020002 */  addiu     $v0, $zero, 2
/* D221C4 80242334 03E00008 */  jr        $ra
/* D221C8 80242338 27BD0020 */   addiu    $sp, $sp, 0x20
