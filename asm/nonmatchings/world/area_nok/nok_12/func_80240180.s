.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240180
/* 9FA970 80240180 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9FA974 80240184 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FA978 80240188 0080882D */  daddu     $s1, $a0, $zero
/* 9FA97C 8024018C AFBF0020 */  sw        $ra, 0x20($sp)
/* 9FA980 80240190 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9FA984 80240194 AFB20018 */  sw        $s2, 0x18($sp)
/* 9FA988 80240198 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FA98C 8024019C 8E30000C */  lw        $s0, 0xc($s1)
/* 9FA990 802401A0 8E330148 */  lw        $s3, 0x148($s1)
/* 9FA994 802401A4 8E050000 */  lw        $a1, ($s0)
/* 9FA998 802401A8 0C0B1EAF */  jal       get_variable
/* 9FA99C 802401AC 26100004 */   addiu    $s0, $s0, 4
/* 9FA9A0 802401B0 0040902D */  daddu     $s2, $v0, $zero
/* 9FA9A4 802401B4 8E050000 */  lw        $a1, ($s0)
/* 9FA9A8 802401B8 26100004 */  addiu     $s0, $s0, 4
/* 9FA9AC 802401BC 0C0B1EAF */  jal       get_variable
/* 9FA9B0 802401C0 0220202D */   daddu    $a0, $s1, $zero
/* 9FA9B4 802401C4 0220202D */  daddu     $a0, $s1, $zero
/* 9FA9B8 802401C8 8E050000 */  lw        $a1, ($s0)
/* 9FA9BC 802401CC 0C0B1EAF */  jal       get_variable
/* 9FA9C0 802401D0 0040802D */   daddu    $s0, $v0, $zero
/* 9FA9C4 802401D4 0040882D */  daddu     $s1, $v0, $zero
/* 9FA9C8 802401D8 2402FFFF */  addiu     $v0, $zero, -1
/* 9FA9CC 802401DC 16420002 */  bne       $s2, $v0, .L802401E8
/* 9FA9D0 802401E0 00000000 */   nop      
/* 9FA9D4 802401E4 86720008 */  lh        $s2, 8($s3)
.L802401E8:
/* 9FA9D8 802401E8 0C00FB5A */  jal       get_enemy_safe
/* 9FA9DC 802401EC 0240202D */   daddu    $a0, $s2, $zero
/* 9FA9E0 802401F0 0040982D */  daddu     $s3, $v0, $zero
/* 9FA9E4 802401F4 12600003 */  beqz      $s3, .L80240204
/* 9FA9E8 802401F8 00101080 */   sll      $v0, $s0, 2
/* 9FA9EC 802401FC 02621021 */  addu      $v0, $s3, $v0
/* 9FA9F0 80240200 AC51006C */  sw        $s1, 0x6c($v0)
.L80240204:
/* 9FA9F4 80240204 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9FA9F8 80240208 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9FA9FC 8024020C 8FB20018 */  lw        $s2, 0x18($sp)
/* 9FAA00 80240210 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FAA04 80240214 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FAA08 80240218 24020002 */  addiu     $v0, $zero, 2
/* 9FAA0C 8024021C 03E00008 */  jr        $ra
/* 9FAA10 80240220 27BD0028 */   addiu    $sp, $sp, 0x28
