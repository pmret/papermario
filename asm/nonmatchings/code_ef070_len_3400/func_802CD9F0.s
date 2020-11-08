.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802CD9F0
/* F23A0 802CD9F0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* F23A4 802CD9F4 AFB20018 */  sw        $s2, 0x18($sp)
/* F23A8 802CD9F8 0080902D */  daddu     $s2, $a0, $zero
/* F23AC 802CD9FC AFBF0020 */  sw        $ra, 0x20($sp)
/* F23B0 802CDA00 AFB3001C */  sw        $s3, 0x1c($sp)
/* F23B4 802CDA04 AFB10014 */  sw        $s1, 0x14($sp)
/* F23B8 802CDA08 AFB00010 */  sw        $s0, 0x10($sp)
/* F23BC 802CDA0C 8E50000C */  lw        $s0, 0xc($s2)
/* F23C0 802CDA10 8E050000 */  lw        $a1, ($s0)
/* F23C4 802CDA14 0C0B1EAF */  jal       get_variable
/* F23C8 802CDA18 26100004 */   addiu    $s0, $s0, 4
/* F23CC 802CDA1C 8E050000 */  lw        $a1, ($s0)
/* F23D0 802CDA20 26100004 */  addiu     $s0, $s0, 4
/* F23D4 802CDA24 0240202D */  daddu     $a0, $s2, $zero
/* F23D8 802CDA28 0C0B1EAF */  jal       get_variable
/* F23DC 802CDA2C 0040882D */   daddu    $s1, $v0, $zero
/* F23E0 802CDA30 0240202D */  daddu     $a0, $s2, $zero
/* F23E4 802CDA34 8E050004 */  lw        $a1, 4($s0)
/* F23E8 802CDA38 8E130000 */  lw        $s3, ($s0)
/* F23EC 802CDA3C 0C0B1EAF */  jal       get_variable
/* F23F0 802CDA40 0040902D */   daddu    $s2, $v0, $zero
/* F23F4 802CDA44 3C03802E */  lui       $v1, %hi(gAnimatedMeshesPtr)
/* F23F8 802CDA48 8C63AE30 */  lw        $v1, %lo(gAnimatedMeshesPtr)($v1)
/* F23FC 802CDA4C 00118880 */  sll       $s1, $s1, 2
/* F2400 802CDA50 02238821 */  addu      $s1, $s1, $v1
/* F2404 802CDA54 8E230000 */  lw        $v1, ($s1)
/* F2408 802CDA58 8C640000 */  lw        $a0, ($v1)
/* F240C 802CDA5C 0C047FF8 */  jal       func_8011FFE0
/* F2410 802CDA60 0040802D */   daddu    $s0, $v0, $zero
/* F2414 802CDA64 0040202D */  daddu     $a0, $v0, $zero
/* F2418 802CDA68 0C047FE6 */  jal       func_8011FF98
/* F241C 802CDA6C 0240282D */   daddu    $a1, $s2, $zero
/* F2420 802CDA70 12000004 */  beqz      $s0, .L802CDA84
/* F2424 802CDA74 0040202D */   daddu    $a0, $v0, $zero
/* F2428 802CDA78 948200F4 */  lhu       $v0, 0xf4($a0)
/* F242C 802CDA7C 080B36A4 */  j         .L802CDA90
/* F2430 802CDA80 00531025 */   or       $v0, $v0, $s3
.L802CDA84:
/* F2434 802CDA84 948200F4 */  lhu       $v0, 0xf4($a0)
/* F2438 802CDA88 00131827 */  nor       $v1, $zero, $s3
/* F243C 802CDA8C 00431024 */  and       $v0, $v0, $v1
.L802CDA90:
/* F2440 802CDA90 A48200F4 */  sh        $v0, 0xf4($a0)
/* F2444 802CDA94 8FBF0020 */  lw        $ra, 0x20($sp)
/* F2448 802CDA98 8FB3001C */  lw        $s3, 0x1c($sp)
/* F244C 802CDA9C 8FB20018 */  lw        $s2, 0x18($sp)
/* F2450 802CDAA0 8FB10014 */  lw        $s1, 0x14($sp)
/* F2454 802CDAA4 8FB00010 */  lw        $s0, 0x10($sp)
/* F2458 802CDAA8 24020002 */  addiu     $v0, $zero, 2
/* F245C 802CDAAC 03E00008 */  jr        $ra
/* F2460 802CDAB0 27BD0028 */   addiu    $sp, $sp, 0x28
/* F2464 802CDAB4 00000000 */  nop       
/* F2468 802CDAB8 00000000 */  nop       
/* F246C 802CDABC 00000000 */  nop       
