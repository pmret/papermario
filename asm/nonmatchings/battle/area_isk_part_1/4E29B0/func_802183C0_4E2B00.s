.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802183C0_4E2B00
/* 4E2B00 802183C0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 4E2B04 802183C4 F7B60020 */  sdc1      $f22, 0x20($sp)
/* 4E2B08 802183C8 4485B000 */  mtc1      $a1, $f22
/* 4E2B0C 802183CC 3C0140C9 */  lui       $at, 0x40c9
/* 4E2B10 802183D0 34210FD0 */  ori       $at, $at, 0xfd0
/* 4E2B14 802183D4 44810000 */  mtc1      $at, $f0
/* 4E2B18 802183D8 44863000 */  mtc1      $a2, $f6
/* 4E2B1C 802183DC F7B40018 */  sdc1      $f20, 0x18($sp)
/* 4E2B20 802183E0 46003502 */  mul.s     $f20, $f6, $f0
/* 4E2B24 802183E4 00000000 */  nop       
/* 4E2B28 802183E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 4E2B2C 802183EC 3C0143B4 */  lui       $at, 0x43b4
/* 4E2B30 802183F0 44810000 */  mtc1      $at, $f0
/* 4E2B34 802183F4 0080802D */  daddu     $s0, $a0, $zero
/* 4E2B38 802183F8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 4E2B3C 802183FC 4600A503 */  div.s     $f20, $f20, $f0
/* 4E2B40 80218400 0C00A85B */  jal       sin_rad
/* 4E2B44 80218404 4600A306 */   mov.s    $f12, $f20
/* 4E2B48 80218408 4600A306 */  mov.s     $f12, $f20
/* 4E2B4C 8021840C 0C00A874 */  jal       cos_rad
/* 4E2B50 80218410 46000506 */   mov.s    $f20, $f0
/* 4E2B54 80218414 4600B087 */  neg.s     $f2, $f22
/* 4E2B58 80218418 46141082 */  mul.s     $f2, $f2, $f20
/* 4E2B5C 8021841C 00000000 */  nop       
/* 4E2B60 80218420 4600B582 */  mul.s     $f22, $f22, $f0
/* 4E2B64 80218424 00000000 */  nop       
/* 4E2B68 80218428 C6040000 */  lwc1      $f4, ($s0)
/* 4E2B6C 8021842C 46022100 */  add.s     $f4, $f4, $f2
/* 4E2B70 80218430 C6000004 */  lwc1      $f0, 4($s0)
/* 4E2B74 80218434 46160000 */  add.s     $f0, $f0, $f22
/* 4E2B78 80218438 E6040000 */  swc1      $f4, ($s0)
/* 4E2B7C 8021843C E6000004 */  swc1      $f0, 4($s0)
/* 4E2B80 80218440 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4E2B84 80218444 8FB00010 */  lw        $s0, 0x10($sp)
/* 4E2B88 80218448 D7B60020 */  ldc1      $f22, 0x20($sp)
/* 4E2B8C 8021844C D7B40018 */  ldc1      $f20, 0x18($sp)
/* 4E2B90 80218450 03E00008 */  jr        $ra
/* 4E2B94 80218454 27BD0028 */   addiu    $sp, $sp, 0x28
