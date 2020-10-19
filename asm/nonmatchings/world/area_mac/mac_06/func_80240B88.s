.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B88
/* 8656C8 80240B88 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 8656CC 80240B8C AFB10014 */  sw        $s1, 0x14($sp)
/* 8656D0 80240B90 0080882D */  daddu     $s1, $a0, $zero
/* 8656D4 80240B94 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8656D8 80240B98 AFB00010 */  sw        $s0, 0x10($sp)
/* 8656DC 80240B9C F7B80030 */  sdc1      $f24, 0x30($sp)
/* 8656E0 80240BA0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* 8656E4 80240BA4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 8656E8 80240BA8 0C00EAD2 */  jal       get_npc_safe
/* 8656EC 80240BAC 0000202D */   daddu    $a0, $zero, $zero
/* 8656F0 80240BB0 0040802D */  daddu     $s0, $v0, $zero
/* 8656F4 80240BB4 C614000C */  lwc1      $f20, 0xc($s0)
/* 8656F8 80240BB8 3C01428C */  lui       $at, 0x428c
/* 8656FC 80240BBC 4481C000 */  mtc1      $at, $f24
/* 865700 80240BC0 4600A507 */  neg.s     $f20, $f20
/* 865704 80240BC4 0C00A8BB */  jal       sin_deg
/* 865708 80240BC8 4600A306 */   mov.s    $f12, $f20
/* 86570C 80240BCC 46180002 */  mul.s     $f0, $f0, $f24
/* 865710 80240BD0 00000000 */  nop       
/* 865714 80240BD4 C6160038 */  lwc1      $f22, 0x38($s0)
/* 865718 80240BD8 3C0141F0 */  lui       $at, 0x41f0
/* 86571C 80240BDC 44811000 */  mtc1      $at, $f2
/* 865720 80240BE0 00000000 */  nop       
/* 865724 80240BE4 4602B580 */  add.s     $f22, $f22, $f2
/* 865728 80240BE8 4600A306 */  mov.s     $f12, $f20
/* 86572C 80240BEC 0C00A8D4 */  jal       cos_deg
/* 865730 80240BF0 4600B580 */   add.s    $f22, $f22, $f0
/* 865734 80240BF4 0220202D */  daddu     $a0, $s1, $zero
/* 865738 80240BF8 46180002 */  mul.s     $f0, $f0, $f24
/* 86573C 80240BFC 00000000 */  nop       
/* 865740 80240C00 3C05FE36 */  lui       $a1, 0xfe36
/* 865744 80240C04 34A53C80 */  ori       $a1, $a1, 0x3c80
/* 865748 80240C08 C6180040 */  lwc1      $f24, 0x40($s0)
/* 86574C 80240C0C C614003C */  lwc1      $f20, 0x3c($s0)
/* 865750 80240C10 4600C600 */  add.s     $f24, $f24, $f0
/* 865754 80240C14 3C014248 */  lui       $at, 0x4248
/* 865758 80240C18 44810000 */  mtc1      $at, $f0
/* 86575C 80240C1C 4406B000 */  mfc1      $a2, $f22
/* 865760 80240C20 0C0B2190 */  jal       set_float_variable
/* 865764 80240C24 4600A500 */   add.s    $f20, $f20, $f0
/* 865768 80240C28 0220202D */  daddu     $a0, $s1, $zero
/* 86576C 80240C2C 3C05FE36 */  lui       $a1, 0xfe36
/* 865770 80240C30 4406A000 */  mfc1      $a2, $f20
/* 865774 80240C34 0C0B2190 */  jal       set_float_variable
/* 865778 80240C38 34A53C81 */   ori      $a1, $a1, 0x3c81
/* 86577C 80240C3C 0220202D */  daddu     $a0, $s1, $zero
/* 865780 80240C40 3C05FE36 */  lui       $a1, 0xfe36
/* 865784 80240C44 4406C000 */  mfc1      $a2, $f24
/* 865788 80240C48 0C0B2190 */  jal       set_float_variable
/* 86578C 80240C4C 34A53C82 */   ori      $a1, $a1, 0x3c82
/* 865790 80240C50 8FBF0018 */  lw        $ra, 0x18($sp)
/* 865794 80240C54 8FB10014 */  lw        $s1, 0x14($sp)
/* 865798 80240C58 8FB00010 */  lw        $s0, 0x10($sp)
/* 86579C 80240C5C D7B80030 */  ldc1      $f24, 0x30($sp)
/* 8657A0 80240C60 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 8657A4 80240C64 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 8657A8 80240C68 24020002 */  addiu     $v0, $zero, 2
/* 8657AC 80240C6C 03E00008 */  jr        $ra
/* 8657B0 80240C70 27BD0038 */   addiu    $sp, $sp, 0x38
