.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218458_4E2B98
/* 4E2B98 80218458 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4E2B9C 8021845C F7B60020 */  sdc1      $f22, 0x20($sp)
/* 4E2BA0 80218460 4485B000 */  mtc1      $a1, $f22
/* 4E2BA4 80218464 3C0140C9 */  lui       $at, 0x40c9
/* 4E2BA8 80218468 34210FD0 */  ori       $at, $at, 0xfd0
/* 4E2BAC 8021846C 44810000 */  mtc1      $at, $f0
/* 4E2BB0 80218470 44861000 */  mtc1      $a2, $f2
/* 4E2BB4 80218474 F7B40018 */  sdc1      $f20, 0x18($sp)
/* 4E2BB8 80218478 46001502 */  mul.s     $f20, $f2, $f0
/* 4E2BBC 8021847C 00000000 */  nop       
/* 4E2BC0 80218480 AFB00010 */  sw        $s0, 0x10($sp)
/* 4E2BC4 80218484 3C0143B4 */  lui       $at, 0x43b4
/* 4E2BC8 80218488 44810000 */  mtc1      $at, $f0
/* 4E2BCC 8021848C 0080802D */  daddu     $s0, $a0, $zero
/* 4E2BD0 80218490 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4E2BD4 80218494 4600A503 */  div.s     $f20, $f20, $f0
/* 4E2BD8 80218498 0C00A85B */  jal       sin_rad
/* 4E2BDC 8021849C 4600A306 */   mov.s    $f12, $f20
/* 4E2BE0 802184A0 0C00A874 */  jal       cos_rad
/* 4E2BE4 802184A4 4600A306 */   mov.s    $f12, $f20
/* 4E2BE8 802184A8 4600B582 */  mul.s     $f22, $f22, $f0
/* 4E2BEC 802184AC 00000000 */  nop       
/* 4E2BF0 802184B0 E6160000 */  swc1      $f22, ($s0)
/* 4E2BF4 802184B4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4E2BF8 802184B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4E2BFC 802184BC D7B60020 */  ldc1      $f22, 0x20($sp)
/* 4E2C00 802184C0 D7B40018 */  ldc1      $f20, 0x18($sp)
/* 4E2C04 802184C4 03E00008 */  jr        $ra
/* 4E2C08 802184C8 27BD0028 */   addiu    $sp, $sp, 0x28
