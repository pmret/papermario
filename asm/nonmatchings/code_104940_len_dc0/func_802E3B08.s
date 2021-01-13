.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E3B08
/* 105388 802E3B08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 10538C 802E3B0C AFB00018 */  sw        $s0, 0x18($sp)
/* 105390 802E3B10 0080802D */  daddu     $s0, $a0, $zero
/* 105394 802E3B14 AFBF001C */  sw        $ra, 0x1c($sp)
/* 105398 802E3B18 8E040040 */  lw        $a0, 0x40($s0)
/* 10539C 802E3B1C 9483000A */  lhu       $v1, 0xa($a0)
/* 1053A0 802E3B20 3402FFFF */  ori       $v0, $zero, 0xffff
/* 1053A4 802E3B24 1062001B */  beq       $v1, $v0, .L802E3B94
/* 1053A8 802E3B28 00000000 */   nop
/* 1053AC 802E3B2C 0C05152F */  jal       get_global_flag
/* 1053B0 802E3B30 0060202D */   daddu    $a0, $v1, $zero
/* 1053B4 802E3B34 10400017 */  beqz      $v0, .L802E3B94
/* 1053B8 802E3B38 3C028000 */   lui      $v0, 0x8000
/* 1053BC 802E3B3C 3C04802F */  lui       $a0, %hi(D_802EA07C)
/* 1053C0 802E3B40 2484A07C */  addiu     $a0, $a0, %lo(D_802EA07C)
/* 1053C4 802E3B44 C6020048 */  lwc1      $f2, 0x48($s0)
/* 1053C8 802E3B48 C604004C */  lwc1      $f4, 0x4c($s0)
/* 1053CC 802E3B4C C6060050 */  lwc1      $f6, 0x50($s0)
/* 1053D0 802E3B50 C6000064 */  lwc1      $f0, 0x64($s0)
/* 1053D4 802E3B54 AFA20014 */  sw        $v0, 0x14($sp)
/* 1053D8 802E3B58 4600020D */  trunc.w.s $f8, $f0
/* 1053DC 802E3B5C E7A80010 */  swc1      $f8, 0x10($sp)
/* 1053E0 802E3B60 4600120D */  trunc.w.s $f8, $f2
/* 1053E4 802E3B64 44054000 */  mfc1      $a1, $f8
/* 1053E8 802E3B68 4600220D */  trunc.w.s $f8, $f4
/* 1053EC 802E3B6C 44064000 */  mfc1      $a2, $f8
/* 1053F0 802E3B70 4600320D */  trunc.w.s $f8, $f6
/* 1053F4 802E3B74 44074000 */  mfc1      $a3, $f8
/* 1053F8 802E3B78 0C044631 */  jal       create_entity
/* 1053FC 802E3B7C 00000000 */   nop
/* 105400 802E3B80 3C032000 */  lui       $v1, 0x2000
/* 105404 802E3B84 8E020000 */  lw        $v0, ($s0)
/* 105408 802E3B88 34630020 */  ori       $v1, $v1, 0x20
/* 10540C 802E3B8C 00431025 */  or        $v0, $v0, $v1
/* 105410 802E3B90 AE020000 */  sw        $v0, ($s0)
.L802E3B94:
/* 105414 802E3B94 8FBF001C */  lw        $ra, 0x1c($sp)
/* 105418 802E3B98 8FB00018 */  lw        $s0, 0x18($sp)
/* 10541C 802E3B9C 03E00008 */  jr        $ra
/* 105420 802E3BA0 27BD0020 */   addiu    $sp, $sp, 0x20
