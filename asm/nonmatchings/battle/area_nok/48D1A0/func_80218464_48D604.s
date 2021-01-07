.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218464_48D604
/* 48D604 80218464 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 48D608 80218468 AFB40020 */  sw        $s4, 0x20($sp)
/* 48D60C 8021846C 0080A02D */  daddu     $s4, $a0, $zero
/* 48D610 80218470 AFBF0024 */  sw        $ra, 0x24($sp)
/* 48D614 80218474 AFB3001C */  sw        $s3, 0x1c($sp)
/* 48D618 80218478 AFB20018 */  sw        $s2, 0x18($sp)
/* 48D61C 8021847C AFB10014 */  sw        $s1, 0x14($sp)
/* 48D620 80218480 AFB00010 */  sw        $s0, 0x10($sp)
/* 48D624 80218484 8E92000C */  lw        $s2, 0xc($s4)
/* 48D628 80218488 8E450000 */  lw        $a1, ($s2)
/* 48D62C 8021848C 0C0B1EAF */  jal       get_variable
/* 48D630 80218490 26520004 */   addiu    $s2, $s2, 4
/* 48D634 80218494 8E450000 */  lw        $a1, ($s2)
/* 48D638 80218498 26520004 */  addiu     $s2, $s2, 4
/* 48D63C 8021849C 0280202D */  daddu     $a0, $s4, $zero
/* 48D640 802184A0 0C0B1EAF */  jal       get_variable
/* 48D644 802184A4 0040802D */   daddu    $s0, $v0, $zero
/* 48D648 802184A8 8E450000 */  lw        $a1, ($s2)
/* 48D64C 802184AC 26520004 */  addiu     $s2, $s2, 4
/* 48D650 802184B0 0280202D */  daddu     $a0, $s4, $zero
/* 48D654 802184B4 0C0B1EAF */  jal       get_variable
/* 48D658 802184B8 0040882D */   daddu    $s1, $v0, $zero
/* 48D65C 802184BC 0040982D */  daddu     $s3, $v0, $zero
/* 48D660 802184C0 8E450000 */  lw        $a1, ($s2)
/* 48D664 802184C4 26520004 */  addiu     $s2, $s2, 4
/* 48D668 802184C8 0280202D */  daddu     $a0, $s4, $zero
/* 48D66C 802184CC 0C0B1EAF */  jal       get_variable
/* 48D670 802184D0 02709823 */   subu     $s3, $s3, $s0
/* 48D674 802184D4 0040802D */  daddu     $s0, $v0, $zero
/* 48D678 802184D8 0280202D */  daddu     $a0, $s4, $zero
/* 48D67C 802184DC 8E450000 */  lw        $a1, ($s2)
/* 48D680 802184E0 0C0B1EAF */  jal       get_variable
/* 48D684 802184E4 02118023 */   subu     $s0, $s0, $s1
/* 48D688 802184E8 16600006 */  bnez      $s3, .L80218504
/* 48D68C 802184EC 00000000 */   nop      
/* 48D690 802184F0 16000004 */  bnez      $s0, .L80218504
/* 48D694 802184F4 0280202D */   daddu    $a0, $s4, $zero
/* 48D698 802184F8 8E450000 */  lw        $a1, ($s2)
/* 48D69C 802184FC 0808614B */  j         .L8021852C
/* 48D6A0 80218500 0040302D */   daddu    $a2, $v0, $zero
.L80218504:
/* 48D6A4 80218504 44936000 */  mtc1      $s3, $f12
/* 48D6A8 80218508 00000000 */  nop       
/* 48D6AC 8021850C 46806320 */  cvt.s.w   $f12, $f12
/* 48D6B0 80218510 44907000 */  mtc1      $s0, $f14
/* 48D6B4 80218514 00000000 */  nop       
/* 48D6B8 80218518 0C0860B6 */  jal       func_802182D8_48D478
/* 48D6BC 8021851C 468073A0 */   cvt.s.w  $f14, $f14
/* 48D6C0 80218520 0280202D */  daddu     $a0, $s4, $zero
/* 48D6C4 80218524 8E450000 */  lw        $a1, ($s2)
/* 48D6C8 80218528 2446FFA6 */  addiu     $a2, $v0, -0x5a
.L8021852C:
/* 48D6CC 8021852C 0C0B2026 */  jal       set_variable
/* 48D6D0 80218530 00000000 */   nop      
/* 48D6D4 80218534 24020002 */  addiu     $v0, $zero, 2
/* 48D6D8 80218538 8FBF0024 */  lw        $ra, 0x24($sp)
/* 48D6DC 8021853C 8FB40020 */  lw        $s4, 0x20($sp)
/* 48D6E0 80218540 8FB3001C */  lw        $s3, 0x1c($sp)
/* 48D6E4 80218544 8FB20018 */  lw        $s2, 0x18($sp)
/* 48D6E8 80218548 8FB10014 */  lw        $s1, 0x14($sp)
/* 48D6EC 8021854C 8FB00010 */  lw        $s0, 0x10($sp)
/* 48D6F0 80218550 03E00008 */  jr        $ra
/* 48D6F4 80218554 27BD0028 */   addiu    $sp, $sp, 0x28
/* 48D6F8 80218558 00000000 */  nop       
/* 48D6FC 8021855C 00000000 */  nop       
