.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243474
/* 8B34E4 80243474 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B34E8 80243478 AFB20018 */  sw        $s2, 0x18($sp)
/* 8B34EC 8024347C 0080902D */  daddu     $s2, $a0, $zero
/* 8B34F0 80243480 AFBF001C */  sw        $ra, 0x1c($sp)
/* 8B34F4 80243484 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B34F8 80243488 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B34FC 8024348C 8E50000C */  lw        $s0, 0xc($s2)
/* 8B3500 80243490 8E050000 */  lw        $a1, ($s0)
/* 8B3504 80243494 0C0B1EAF */  jal       get_variable
/* 8B3508 80243498 26100004 */   addiu    $s0, $s0, 4
/* 8B350C 8024349C 0C04417A */  jal       get_entity_by_index
/* 8B3510 802434A0 0040202D */   daddu    $a0, $v0, $zero
/* 8B3514 802434A4 8E050000 */  lw        $a1, ($s0)
/* 8B3518 802434A8 26100004 */  addiu     $s0, $s0, 4
/* 8B351C 802434AC 0040882D */  daddu     $s1, $v0, $zero
/* 8B3520 802434B0 C6200048 */  lwc1      $f0, 0x48($s1)
/* 8B3524 802434B4 4600008D */  trunc.w.s $f2, $f0
/* 8B3528 802434B8 44061000 */  mfc1      $a2, $f2
/* 8B352C 802434BC 0C0B2026 */  jal       set_variable
/* 8B3530 802434C0 0240202D */   daddu    $a0, $s2, $zero
/* 8B3534 802434C4 8E050000 */  lw        $a1, ($s0)
/* 8B3538 802434C8 26100004 */  addiu     $s0, $s0, 4
/* 8B353C 802434CC C620004C */  lwc1      $f0, 0x4c($s1)
/* 8B3540 802434D0 4600008D */  trunc.w.s $f2, $f0
/* 8B3544 802434D4 44061000 */  mfc1      $a2, $f2
/* 8B3548 802434D8 0C0B2026 */  jal       set_variable
/* 8B354C 802434DC 0240202D */   daddu    $a0, $s2, $zero
/* 8B3550 802434E0 C6200050 */  lwc1      $f0, 0x50($s1)
/* 8B3554 802434E4 8E050000 */  lw        $a1, ($s0)
/* 8B3558 802434E8 4600008D */  trunc.w.s $f2, $f0
/* 8B355C 802434EC 44061000 */  mfc1      $a2, $f2
/* 8B3560 802434F0 0C0B2026 */  jal       set_variable
/* 8B3564 802434F4 0240202D */   daddu    $a0, $s2, $zero
/* 8B3568 802434F8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 8B356C 802434FC 8FB20018 */  lw        $s2, 0x18($sp)
/* 8B3570 80243500 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B3574 80243504 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B3578 80243508 24020002 */  addiu     $v0, $zero, 2
/* 8B357C 8024350C 03E00008 */  jr        $ra
/* 8B3580 80243510 27BD0020 */   addiu    $sp, $sp, 0x20
