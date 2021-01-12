.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802402B8_B76A68
/* B76A68 802402B8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* B76A6C 802402BC AFB20018 */  sw        $s2, 0x18($sp)
/* B76A70 802402C0 0080902D */  daddu     $s2, $a0, $zero
/* B76A74 802402C4 AFBF001C */  sw        $ra, 0x1c($sp)
/* B76A78 802402C8 AFB10014 */  sw        $s1, 0x14($sp)
/* B76A7C 802402CC AFB00010 */  sw        $s0, 0x10($sp)
/* B76A80 802402D0 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B76A84 802402D4 F7B40020 */  sdc1      $f20, 0x20($sp)
/* B76A88 802402D8 8E510084 */  lw        $s1, 0x84($s2)
/* B76A8C 802402DC 8E420088 */  lw        $v0, 0x88($s2)
/* B76A90 802402E0 8E50008C */  lw        $s0, 0x8c($s2)
/* B76A94 802402E4 2842FF9D */  slti      $v0, $v0, -0x63
/* B76A98 802402E8 5440001E */  bnel      $v0, $zero, .L80240364
/* B76A9C 802402EC 26100019 */   addiu    $s0, $s0, 0x19
/* B76AA0 802402F0 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* B76AA4 802402F4 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* B76AA8 802402F8 C4540080 */  lwc1      $f20, 0x80($v0)
/* B76AAC 802402FC 3C014334 */  lui       $at, 0x4334
/* B76AB0 80240300 44810000 */  mtc1      $at, $f0
/* B76AB4 80240304 3C014049 */  lui       $at, 0x4049
/* B76AB8 80240308 34210FD8 */  ori       $at, $at, 0xfd8
/* B76ABC 8024030C 44811000 */  mtc1      $at, $f2
/* B76AC0 80240310 4600A503 */  div.s     $f20, $f20, $f0
/* B76AC4 80240314 4602A502 */  mul.s     $f20, $f20, $f2
/* B76AC8 80240318 00000000 */  nop
/* B76ACC 8024031C 3C0141C8 */  lui       $at, 0x41c8
/* B76AD0 80240320 4481B000 */  mtc1      $at, $f22
/* B76AD4 80240324 0C00A85B */  jal       sin_rad
/* B76AD8 80240328 4600A306 */   mov.s    $f12, $f20
/* B76ADC 8024032C 46160002 */  mul.s     $f0, $f0, $f22
/* B76AE0 80240330 00000000 */  nop
/* B76AE4 80240334 4600A306 */  mov.s     $f12, $f20
/* B76AE8 80240338 4600010D */  trunc.w.s $f4, $f0
/* B76AEC 8024033C 44022000 */  mfc1      $v0, $f4
/* B76AF0 80240340 0C00A874 */  jal       cos_rad
/* B76AF4 80240344 02228823 */   subu     $s1, $s1, $v0
/* B76AF8 80240348 46000007 */  neg.s     $f0, $f0
/* B76AFC 8024034C 46160002 */  mul.s     $f0, $f0, $f22
/* B76B00 80240350 00000000 */  nop
/* B76B04 80240354 4600010D */  trunc.w.s $f4, $f0
/* B76B08 80240358 44022000 */  mfc1      $v0, $f4
/* B76B0C 8024035C 00000000 */  nop
/* B76B10 80240360 02028023 */  subu      $s0, $s0, $v0
.L80240364:
/* B76B14 80240364 AE510084 */  sw        $s1, 0x84($s2)
/* B76B18 80240368 AE50008C */  sw        $s0, 0x8c($s2)
/* B76B1C 8024036C 8FBF001C */  lw        $ra, 0x1c($sp)
/* B76B20 80240370 8FB20018 */  lw        $s2, 0x18($sp)
/* B76B24 80240374 8FB10014 */  lw        $s1, 0x14($sp)
/* B76B28 80240378 8FB00010 */  lw        $s0, 0x10($sp)
/* B76B2C 8024037C D7B60028 */  ldc1      $f22, 0x28($sp)
/* B76B30 80240380 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B76B34 80240384 24020002 */  addiu     $v0, $zero, 2
/* B76B38 80240388 03E00008 */  jr        $ra
/* B76B3C 8024038C 27BD0030 */   addiu    $sp, $sp, 0x30
