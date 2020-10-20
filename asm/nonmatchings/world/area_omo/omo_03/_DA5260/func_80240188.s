.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240188
/* DA53C8 80240188 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DA53CC 8024018C AFB20018 */  sw        $s2, 0x18($sp)
/* DA53D0 80240190 0080902D */  daddu     $s2, $a0, $zero
/* DA53D4 80240194 AFBF001C */  sw        $ra, 0x1c($sp)
/* DA53D8 80240198 AFB10014 */  sw        $s1, 0x14($sp)
/* DA53DC 8024019C AFB00010 */  sw        $s0, 0x10($sp)
/* DA53E0 802401A0 8E50000C */  lw        $s0, 0xc($s2)
/* DA53E4 802401A4 8E050000 */  lw        $a1, ($s0)
/* DA53E8 802401A8 0C0B1EAF */  jal       get_variable
/* DA53EC 802401AC 26100004 */   addiu    $s0, $s0, 4
/* DA53F0 802401B0 8E050000 */  lw        $a1, ($s0)
/* DA53F4 802401B4 26100004 */  addiu     $s0, $s0, 4
/* DA53F8 802401B8 0240202D */  daddu     $a0, $s2, $zero
/* DA53FC 802401BC 0C0B1EAF */  jal       get_variable
/* DA5400 802401C0 0040882D */   daddu    $s1, $v0, $zero
/* DA5404 802401C4 0240202D */  daddu     $a0, $s2, $zero
/* DA5408 802401C8 8E050000 */  lw        $a1, ($s0)
/* DA540C 802401CC 0C0B1EAF */  jal       get_variable
/* DA5410 802401D0 0040802D */   daddu    $s0, $v0, $zero
/* DA5414 802401D4 02020018 */  mult      $s0, $v0
/* DA5418 802401D8 24020002 */  addiu     $v0, $zero, 2
/* DA541C 802401DC 8E430138 */  lw        $v1, 0x138($s2)
/* DA5420 802401E0 00003012 */  mflo      $a2
/* DA5424 802401E4 02268821 */  addu      $s1, $s1, $a2
/* DA5428 802401E8 00518804 */  sllv      $s1, $s1, $v0
/* DA542C 802401EC 00711821 */  addu      $v1, $v1, $s1
/* DA5430 802401F0 AE430138 */  sw        $v1, 0x138($s2)
/* DA5434 802401F4 8FBF001C */  lw        $ra, 0x1c($sp)
/* DA5438 802401F8 8FB20018 */  lw        $s2, 0x18($sp)
/* DA543C 802401FC 8FB10014 */  lw        $s1, 0x14($sp)
/* DA5440 80240200 8FB00010 */  lw        $s0, 0x10($sp)
/* DA5444 80240204 03E00008 */  jr        $ra
/* DA5448 80240208 27BD0020 */   addiu    $sp, $sp, 0x20
