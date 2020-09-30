.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80056E34
/* 32234 80056E34 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 32238 80056E38 AFB3001C */  sw        $s3, 0x1c($sp)
/* 3223C 80056E3C 00E0982D */  daddu     $s3, $a3, $zero
/* 32240 80056E40 AFB20018 */  sw        $s2, 0x18($sp)
/* 32244 80056E44 00059400 */  sll       $s2, $a1, 0x10
/* 32248 80056E48 00129403 */  sra       $s2, $s2, 0x10
/* 3224C 80056E4C 0240282D */  daddu     $a1, $s2, $zero
/* 32250 80056E50 AFB10014 */  sw        $s1, 0x14($sp)
/* 32254 80056E54 00068C00 */  sll       $s1, $a2, 0x10
/* 32258 80056E58 00118C03 */  sra       $s1, $s1, 0x10
/* 3225C 80056E5C 308400FF */  andi      $a0, $a0, 0xff
/* 32260 80056E60 00041040 */  sll       $v0, $a0, 1
/* 32264 80056E64 3C038008 */  lui       $v1, 0x8008
/* 32268 80056E68 8C638E54 */  lw        $v1, -0x71ac($v1)
/* 3226C 80056E6C 00441021 */  addu      $v0, $v0, $a0
/* 32270 80056E70 AFBF0020 */  sw        $ra, 0x20($sp)
/* 32274 80056E74 AFB00010 */  sw        $s0, 0x10($sp)
/* 32278 80056E78 8C700020 */  lw        $s0, 0x20($v1)
/* 3227C 80056E7C 000210C0 */  sll       $v0, $v0, 3
/* 32280 80056E80 02028021 */  addu      $s0, $s0, $v0
/* 32284 80056E84 8E040004 */  lw        $a0, 4($s0)
/* 32288 80056E88 0C016628 */  jal       func_800598A0
/* 3228C 80056E8C 0220302D */   daddu    $a2, $s1, $zero
/* 32290 80056E90 0240282D */  daddu     $a1, $s2, $zero
/* 32294 80056E94 0220302D */  daddu     $a2, $s1, $zero
/* 32298 80056E98 8E040008 */  lw        $a0, 8($s0)
/* 3229C 80056E9C 0C016628 */  jal       func_800598A0
/* 322A0 80056EA0 0260382D */   daddu    $a3, $s3, $zero
/* 322A4 80056EA4 8FBF0020 */  lw        $ra, 0x20($sp)
/* 322A8 80056EA8 8FB3001C */  lw        $s3, 0x1c($sp)
/* 322AC 80056EAC 8FB20018 */  lw        $s2, 0x18($sp)
/* 322B0 80056EB0 8FB10014 */  lw        $s1, 0x14($sp)
/* 322B4 80056EB4 8FB00010 */  lw        $s0, 0x10($sp)
/* 322B8 80056EB8 03E00008 */  jr        $ra
/* 322BC 80056EBC 27BD0028 */   addiu    $sp, $sp, 0x28
