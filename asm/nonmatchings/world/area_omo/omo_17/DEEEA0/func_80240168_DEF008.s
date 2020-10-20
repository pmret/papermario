.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240168_DEF008
/* DEF008 80240168 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DEF00C 8024016C AFB20018 */  sw        $s2, 0x18($sp)
/* DEF010 80240170 0080902D */  daddu     $s2, $a0, $zero
/* DEF014 80240174 AFBF001C */  sw        $ra, 0x1c($sp)
/* DEF018 80240178 AFB10014 */  sw        $s1, 0x14($sp)
/* DEF01C 8024017C AFB00010 */  sw        $s0, 0x10($sp)
/* DEF020 80240180 8E50000C */  lw        $s0, 0xc($s2)
/* DEF024 80240184 8E050000 */  lw        $a1, ($s0)
/* DEF028 80240188 0C0B1EAF */  jal       get_variable
/* DEF02C 8024018C 26100004 */   addiu    $s0, $s0, 4
/* DEF030 80240190 8E050000 */  lw        $a1, ($s0)
/* DEF034 80240194 26100004 */  addiu     $s0, $s0, 4
/* DEF038 80240198 0240202D */  daddu     $a0, $s2, $zero
/* DEF03C 8024019C 0C0B1EAF */  jal       get_variable
/* DEF040 802401A0 0040882D */   daddu    $s1, $v0, $zero
/* DEF044 802401A4 0240202D */  daddu     $a0, $s2, $zero
/* DEF048 802401A8 8E050000 */  lw        $a1, ($s0)
/* DEF04C 802401AC 0C0B1EAF */  jal       get_variable
/* DEF050 802401B0 0040802D */   daddu    $s0, $v0, $zero
/* DEF054 802401B4 02020018 */  mult      $s0, $v0
/* DEF058 802401B8 24020002 */  addiu     $v0, $zero, 2
/* DEF05C 802401BC 8E430138 */  lw        $v1, 0x138($s2)
/* DEF060 802401C0 00003012 */  mflo      $a2
/* DEF064 802401C4 02268821 */  addu      $s1, $s1, $a2
/* DEF068 802401C8 00518804 */  sllv      $s1, $s1, $v0
/* DEF06C 802401CC 00711821 */  addu      $v1, $v1, $s1
/* DEF070 802401D0 AE430138 */  sw        $v1, 0x138($s2)
/* DEF074 802401D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* DEF078 802401D8 8FB20018 */  lw        $s2, 0x18($sp)
/* DEF07C 802401DC 8FB10014 */  lw        $s1, 0x14($sp)
/* DEF080 802401E0 8FB00010 */  lw        $s0, 0x10($sp)
/* DEF084 802401E4 03E00008 */  jr        $ra
/* DEF088 802401E8 27BD0020 */   addiu    $sp, $sp, 0x20
