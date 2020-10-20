.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240168_DD7B18
/* DD7B18 80240168 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DD7B1C 8024016C AFB20018 */  sw        $s2, 0x18($sp)
/* DD7B20 80240170 0080902D */  daddu     $s2, $a0, $zero
/* DD7B24 80240174 AFBF001C */  sw        $ra, 0x1c($sp)
/* DD7B28 80240178 AFB10014 */  sw        $s1, 0x14($sp)
/* DD7B2C 8024017C AFB00010 */  sw        $s0, 0x10($sp)
/* DD7B30 80240180 8E50000C */  lw        $s0, 0xc($s2)
/* DD7B34 80240184 8E050000 */  lw        $a1, ($s0)
/* DD7B38 80240188 0C0B1EAF */  jal       get_variable
/* DD7B3C 8024018C 26100004 */   addiu    $s0, $s0, 4
/* DD7B40 80240190 8E050000 */  lw        $a1, ($s0)
/* DD7B44 80240194 26100004 */  addiu     $s0, $s0, 4
/* DD7B48 80240198 0240202D */  daddu     $a0, $s2, $zero
/* DD7B4C 8024019C 0C0B1EAF */  jal       get_variable
/* DD7B50 802401A0 0040882D */   daddu    $s1, $v0, $zero
/* DD7B54 802401A4 0240202D */  daddu     $a0, $s2, $zero
/* DD7B58 802401A8 8E050000 */  lw        $a1, ($s0)
/* DD7B5C 802401AC 0C0B1EAF */  jal       get_variable
/* DD7B60 802401B0 0040802D */   daddu    $s0, $v0, $zero
/* DD7B64 802401B4 02020018 */  mult      $s0, $v0
/* DD7B68 802401B8 24020002 */  addiu     $v0, $zero, 2
/* DD7B6C 802401BC 8E430138 */  lw        $v1, 0x138($s2)
/* DD7B70 802401C0 00003012 */  mflo      $a2
/* DD7B74 802401C4 02268821 */  addu      $s1, $s1, $a2
/* DD7B78 802401C8 00518804 */  sllv      $s1, $s1, $v0
/* DD7B7C 802401CC 00711821 */  addu      $v1, $v1, $s1
/* DD7B80 802401D0 AE430138 */  sw        $v1, 0x138($s2)
/* DD7B84 802401D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* DD7B88 802401D8 8FB20018 */  lw        $s2, 0x18($sp)
/* DD7B8C 802401DC 8FB10014 */  lw        $s1, 0x14($sp)
/* DD7B90 802401E0 8FB00010 */  lw        $s0, 0x10($sp)
/* DD7B94 802401E4 03E00008 */  jr        $ra
/* DD7B98 802401E8 27BD0020 */   addiu    $sp, $sp, 0x20
