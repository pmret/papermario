.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400CC_BBB44C
/* BBB44C 802400CC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BBB450 802400D0 AFB10014 */  sw        $s1, 0x14($sp)
/* BBB454 802400D4 0080882D */  daddu     $s1, $a0, $zero
/* BBB458 802400D8 AFB20018 */  sw        $s2, 0x18($sp)
/* BBB45C 802400DC AFBF001C */  sw        $ra, 0x1c($sp)
/* BBB460 802400E0 AFB00010 */  sw        $s0, 0x10($sp)
/* BBB464 802400E4 8E30000C */  lw        $s0, 0xc($s1)
/* BBB468 802400E8 10A00013 */  beqz      $a1, .L80240138
/* BBB46C 802400EC 0000902D */   daddu    $s2, $zero, $zero
/* BBB470 802400F0 8E050000 */  lw        $a1, ($s0)
/* BBB474 802400F4 0C0B1EAF */  jal       get_variable
/* BBB478 802400F8 26100004 */   addiu    $s0, $s0, 4
/* BBB47C 802400FC AE220074 */  sw        $v0, 0x74($s1)
/* BBB480 80240100 8E050000 */  lw        $a1, ($s0)
/* BBB484 80240104 26100004 */  addiu     $s0, $s0, 4
/* BBB488 80240108 0C0B1EAF */  jal       get_variable
/* BBB48C 8024010C 0220202D */   daddu    $a0, $s1, $zero
/* BBB490 80240110 AE220078 */  sw        $v0, 0x78($s1)
/* BBB494 80240114 8E050000 */  lw        $a1, ($s0)
/* BBB498 80240118 26100004 */  addiu     $s0, $s0, 4
/* BBB49C 8024011C 0C0B1EAF */  jal       get_variable
/* BBB4A0 80240120 0220202D */   daddu    $a0, $s1, $zero
/* BBB4A4 80240124 AE220070 */  sw        $v0, 0x70($s1)
/* BBB4A8 80240128 8E050000 */  lw        $a1, ($s0)
/* BBB4AC 8024012C 0C0B1EAF */  jal       get_variable
/* BBB4B0 80240130 0220202D */   daddu    $a0, $s1, $zero
/* BBB4B4 80240134 AE22007C */  sw        $v0, 0x7c($s1)
.L80240138:
/* BBB4B8 80240138 8E23007C */  lw        $v1, 0x7c($s1)
/* BBB4BC 8024013C 8E220074 */  lw        $v0, 0x74($s1)
/* BBB4C0 80240140 0060202D */  daddu     $a0, $v1, $zero
/* BBB4C4 80240144 00431021 */  addu      $v0, $v0, $v1
/* BBB4C8 80240148 04800004 */  bltz      $a0, .L8024015C
/* BBB4CC 8024014C AE220074 */   sw       $v0, 0x74($s1)
/* BBB4D0 80240150 8E230078 */  lw        $v1, 0x78($s1)
/* BBB4D4 80240154 08090059 */  j         .L80240164
/* BBB4D8 80240158 0043102A */   slt      $v0, $v0, $v1
.L8024015C:
/* BBB4DC 8024015C 8E230078 */  lw        $v1, 0x78($s1)
/* BBB4E0 80240160 0062102A */  slt       $v0, $v1, $v0
.L80240164:
/* BBB4E4 80240164 14400003 */  bnez      $v0, .L80240174
/* BBB4E8 80240168 00000000 */   nop      
/* BBB4EC 8024016C AE230074 */  sw        $v1, 0x74($s1)
/* BBB4F0 80240170 24120002 */  addiu     $s2, $zero, 2
.L80240174:
/* BBB4F4 80240174 8E240074 */  lw        $a0, 0x74($s1)
/* BBB4F8 80240178 0C046EDD */  jal       set_world_fog_dist
/* BBB4FC 8024017C 8E250070 */   lw       $a1, 0x70($s1)
/* BBB500 80240180 0240102D */  daddu     $v0, $s2, $zero
/* BBB504 80240184 8FBF001C */  lw        $ra, 0x1c($sp)
/* BBB508 80240188 8FB20018 */  lw        $s2, 0x18($sp)
/* BBB50C 8024018C 8FB10014 */  lw        $s1, 0x14($sp)
/* BBB510 80240190 8FB00010 */  lw        $s0, 0x10($sp)
/* BBB514 80240194 03E00008 */  jr        $ra
/* BBB518 80240198 27BD0020 */   addiu    $sp, $sp, 0x20
