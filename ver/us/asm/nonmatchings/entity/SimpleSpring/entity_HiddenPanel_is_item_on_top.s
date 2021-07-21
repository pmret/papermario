.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel entity_HiddenPanel_is_item_on_top
/* 1083EC 802E6B6C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 1083F0 802E6B70 AFB10014 */  sw        $s1, 0x14($sp)
/* 1083F4 802E6B74 0080882D */  daddu     $s1, $a0, $zero
/* 1083F8 802E6B78 AFBF0018 */  sw        $ra, 0x18($sp)
/* 1083FC 802E6B7C AFB00010 */  sw        $s0, 0x10($sp)
/* 108400 802E6B80 8E300040 */  lw        $s0, 0x40($s1)
/* 108404 802E6B84 8E040014 */  lw        $a0, 0x14($s0)
/* 108408 802E6B88 04800021 */  bltz      $a0, .L802E6C10
/* 10840C 802E6B8C 0000102D */   daddu    $v0, $zero, $zero
/* 108410 802E6B90 0C04C3D6 */  jal       get_item_entity
/* 108414 802E6B94 00000000 */   nop
/* 108418 802E6B98 5040001D */  beql      $v0, $zero, .L802E6C10
/* 10841C 802E6B9C 0000102D */   daddu    $v0, $zero, $zero
/* 108420 802E6BA0 8C420000 */  lw        $v0, ($v0)
/* 108424 802E6BA4 30420010 */  andi      $v0, $v0, 0x10
/* 108428 802E6BA8 10400019 */  beqz      $v0, .L802E6C10
/* 10842C 802E6BAC 0000102D */   daddu    $v0, $zero, $zero
/* 108430 802E6BB0 C6200048 */  lwc1      $f0, 0x48($s1)
/* 108434 802E6BB4 C6020018 */  lwc1      $f2, 0x18($s0)
/* 108438 802E6BB8 468010A0 */  cvt.s.w   $f2, $f2
/* 10843C 802E6BBC 46020001 */  sub.s     $f0, $f0, $f2
/* 108440 802E6BC0 3C014041 */  lui       $at, 0x4041
/* 108444 802E6BC4 44812800 */  mtc1      $at, $f5
/* 108448 802E6BC8 44802000 */  mtc1      $zero, $f4
/* 10844C 802E6BCC 46000021 */  cvt.d.s   $f0, $f0
/* 108450 802E6BD0 46200005 */  abs.d     $f0, $f0
/* 108454 802E6BD4 4624003E */  c.le.d    $f0, $f4
/* 108458 802E6BD8 00000000 */  nop
/* 10845C 802E6BDC 4500000C */  bc1f      .L802E6C10
/* 108460 802E6BE0 00000000 */   nop
/* 108464 802E6BE4 C6200050 */  lwc1      $f0, 0x50($s1)
/* 108468 802E6BE8 C6020020 */  lwc1      $f2, 0x20($s0)
/* 10846C 802E6BEC 468010A0 */  cvt.s.w   $f2, $f2
/* 108470 802E6BF0 46020001 */  sub.s     $f0, $f0, $f2
/* 108474 802E6BF4 46000021 */  cvt.d.s   $f0, $f0
/* 108478 802E6BF8 46200005 */  abs.d     $f0, $f0
/* 10847C 802E6BFC 4624003E */  c.le.d    $f0, $f4
/* 108480 802E6C00 00000000 */  nop
/* 108484 802E6C04 45010002 */  bc1t      .L802E6C10
/* 108488 802E6C08 24020001 */   addiu    $v0, $zero, 1
/* 10848C 802E6C0C 0000102D */  daddu     $v0, $zero, $zero
.L802E6C10:
/* 108490 802E6C10 8FBF0018 */  lw        $ra, 0x18($sp)
/* 108494 802E6C14 8FB10014 */  lw        $s1, 0x14($sp)
/* 108498 802E6C18 8FB00010 */  lw        $s0, 0x10($sp)
/* 10849C 802E6C1C 03E00008 */  jr        $ra
/* 1084A0 802E6C20 27BD0020 */   addiu    $sp, $sp, 0x20
