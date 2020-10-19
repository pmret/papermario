.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802433AC
/* 8B341C 802433AC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8B3420 802433B0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B3424 802433B4 0080882D */  daddu     $s1, $a0, $zero
/* 8B3428 802433B8 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8B342C 802433BC AFB20018 */  sw        $s2, 0x18($sp)
/* 8B3430 802433C0 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B3434 802433C4 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 8B3438 802433C8 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 8B343C 802433CC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8B3440 802433D0 8E30000C */  lw        $s0, 0xc($s1)
/* 8B3444 802433D4 8E050000 */  lw        $a1, ($s0)
/* 8B3448 802433D8 0C0B1EAF */  jal       get_variable
/* 8B344C 802433DC 26100004 */   addiu    $s0, $s0, 4
/* 8B3450 802433E0 8E050000 */  lw        $a1, ($s0)
/* 8B3454 802433E4 26100004 */  addiu     $s0, $s0, 4
/* 8B3458 802433E8 0220202D */  daddu     $a0, $s1, $zero
/* 8B345C 802433EC 0C0B1EAF */  jal       get_variable
/* 8B3460 802433F0 0040902D */   daddu    $s2, $v0, $zero
/* 8B3464 802433F4 8E050000 */  lw        $a1, ($s0)
/* 8B3468 802433F8 26100004 */  addiu     $s0, $s0, 4
/* 8B346C 802433FC 4482C000 */  mtc1      $v0, $f24
/* 8B3470 80243400 00000000 */  nop       
/* 8B3474 80243404 4680C620 */  cvt.s.w   $f24, $f24
/* 8B3478 80243408 0C0B1EAF */  jal       get_variable
/* 8B347C 8024340C 0220202D */   daddu    $a0, $s1, $zero
/* 8B3480 80243410 8E050000 */  lw        $a1, ($s0)
/* 8B3484 80243414 4482B000 */  mtc1      $v0, $f22
/* 8B3488 80243418 00000000 */  nop       
/* 8B348C 8024341C 4680B5A0 */  cvt.s.w   $f22, $f22
/* 8B3490 80243420 0C0B1EAF */  jal       get_variable
/* 8B3494 80243424 0220202D */   daddu    $a0, $s1, $zero
/* 8B3498 80243428 4482A000 */  mtc1      $v0, $f20
/* 8B349C 8024342C 00000000 */  nop       
/* 8B34A0 80243430 4680A520 */  cvt.s.w   $f20, $f20
/* 8B34A4 80243434 0C04417A */  jal       get_entity_by_index
/* 8B34A8 80243438 0240202D */   daddu    $a0, $s2, $zero
/* 8B34AC 8024343C 0040182D */  daddu     $v1, $v0, $zero
/* 8B34B0 80243440 E4780048 */  swc1      $f24, 0x48($v1)
/* 8B34B4 80243444 E476004C */  swc1      $f22, 0x4c($v1)
/* 8B34B8 80243448 E4740050 */  swc1      $f20, 0x50($v1)
/* 8B34BC 8024344C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8B34C0 80243450 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B34C4 80243454 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B34C8 80243458 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B34CC 8024345C D7B80030 */  ldc1      $f24, 0x30($sp)
/* 8B34D0 80243460 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 8B34D4 80243464 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8B34D8 80243468 24020002 */  addiu     $v0, $zero, 2
/* 8B34DC 8024346C 03E00008 */  jr        $ra
/* 8B34E0 80243470 27BD0038 */   addiu    $sp, $sp, 0x38
