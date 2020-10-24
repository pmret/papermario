.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240168_DB7A78
/* DB7A78 80240168 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DB7A7C 8024016C AFB20018 */  sw        $s2, 0x18($sp)
/* DB7A80 80240170 0080902D */  daddu     $s2, $a0, $zero
/* DB7A84 80240174 AFBF001C */  sw        $ra, 0x1c($sp)
/* DB7A88 80240178 AFB10014 */  sw        $s1, 0x14($sp)
/* DB7A8C 8024017C AFB00010 */  sw        $s0, 0x10($sp)
/* DB7A90 80240180 8E50000C */  lw        $s0, 0xc($s2)
/* DB7A94 80240184 8E050000 */  lw        $a1, ($s0)
/* DB7A98 80240188 0C0B1EAF */  jal       get_variable
/* DB7A9C 8024018C 26100004 */   addiu    $s0, $s0, 4
/* DB7AA0 80240190 8E050000 */  lw        $a1, ($s0)
/* DB7AA4 80240194 26100004 */  addiu     $s0, $s0, 4
/* DB7AA8 80240198 0240202D */  daddu     $a0, $s2, $zero
/* DB7AAC 8024019C 0C0B1EAF */  jal       get_variable
/* DB7AB0 802401A0 0040882D */   daddu    $s1, $v0, $zero
/* DB7AB4 802401A4 0240202D */  daddu     $a0, $s2, $zero
/* DB7AB8 802401A8 8E050000 */  lw        $a1, ($s0)
/* DB7ABC 802401AC 0C0B1EAF */  jal       get_variable
/* DB7AC0 802401B0 0040802D */   daddu    $s0, $v0, $zero
/* DB7AC4 802401B4 02020018 */  mult      $s0, $v0
/* DB7AC8 802401B8 24020002 */  addiu     $v0, $zero, 2
/* DB7ACC 802401BC 8E430138 */  lw        $v1, 0x138($s2)
/* DB7AD0 802401C0 00003012 */  mflo      $a2
/* DB7AD4 802401C4 02268821 */  addu      $s1, $s1, $a2
/* DB7AD8 802401C8 00518804 */  sllv      $s1, $s1, $v0
/* DB7ADC 802401CC 00711821 */  addu      $v1, $v1, $s1
/* DB7AE0 802401D0 AE430138 */  sw        $v1, 0x138($s2)
/* DB7AE4 802401D4 8FBF001C */  lw        $ra, 0x1c($sp)
/* DB7AE8 802401D8 8FB20018 */  lw        $s2, 0x18($sp)
/* DB7AEC 802401DC 8FB10014 */  lw        $s1, 0x14($sp)
/* DB7AF0 802401E0 8FB00010 */  lw        $s0, 0x10($sp)
/* DB7AF4 802401E4 03E00008 */  jr        $ra
/* DB7AF8 802401E8 27BD0020 */   addiu    $sp, $sp, 0x20
