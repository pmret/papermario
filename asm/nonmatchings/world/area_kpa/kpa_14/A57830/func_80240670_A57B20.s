.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240670_A57B20
/* A57B20 80240670 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A57B24 80240674 AFB20018 */  sw        $s2, 0x18($sp)
/* A57B28 80240678 0080902D */  daddu     $s2, $a0, $zero
/* A57B2C 8024067C AFBF001C */  sw        $ra, 0x1c($sp)
/* A57B30 80240680 AFB10014 */  sw        $s1, 0x14($sp)
/* A57B34 80240684 AFB00010 */  sw        $s0, 0x10($sp)
/* A57B38 80240688 8E50000C */  lw        $s0, 0xc($s2)
/* A57B3C 8024068C 8E050000 */  lw        $a1, ($s0)
/* A57B40 80240690 0C0B1EAF */  jal       get_variable
/* A57B44 80240694 26100004 */   addiu    $s0, $s0, 4
/* A57B48 80240698 0C04417A */  jal       get_entity_by_index
/* A57B4C 8024069C 0040202D */   daddu    $a0, $v0, $zero
/* A57B50 802406A0 8E050000 */  lw        $a1, ($s0)
/* A57B54 802406A4 26100004 */  addiu     $s0, $s0, 4
/* A57B58 802406A8 0040882D */  daddu     $s1, $v0, $zero
/* A57B5C 802406AC C6200048 */  lwc1      $f0, 0x48($s1)
/* A57B60 802406B0 4600008D */  trunc.w.s $f2, $f0
/* A57B64 802406B4 44061000 */  mfc1      $a2, $f2
/* A57B68 802406B8 0C0B2026 */  jal       set_variable
/* A57B6C 802406BC 0240202D */   daddu    $a0, $s2, $zero
/* A57B70 802406C0 8E050000 */  lw        $a1, ($s0)
/* A57B74 802406C4 26100004 */  addiu     $s0, $s0, 4
/* A57B78 802406C8 C620004C */  lwc1      $f0, 0x4c($s1)
/* A57B7C 802406CC 4600008D */  trunc.w.s $f2, $f0
/* A57B80 802406D0 44061000 */  mfc1      $a2, $f2
/* A57B84 802406D4 0C0B2026 */  jal       set_variable
/* A57B88 802406D8 0240202D */   daddu    $a0, $s2, $zero
/* A57B8C 802406DC C6200050 */  lwc1      $f0, 0x50($s1)
/* A57B90 802406E0 8E050000 */  lw        $a1, ($s0)
/* A57B94 802406E4 4600008D */  trunc.w.s $f2, $f0
/* A57B98 802406E8 44061000 */  mfc1      $a2, $f2
/* A57B9C 802406EC 0C0B2026 */  jal       set_variable
/* A57BA0 802406F0 0240202D */   daddu    $a0, $s2, $zero
/* A57BA4 802406F4 8FBF001C */  lw        $ra, 0x1c($sp)
/* A57BA8 802406F8 8FB20018 */  lw        $s2, 0x18($sp)
/* A57BAC 802406FC 8FB10014 */  lw        $s1, 0x14($sp)
/* A57BB0 80240700 8FB00010 */  lw        $s0, 0x10($sp)
/* A57BB4 80240704 24020002 */  addiu     $v0, $zero, 2
/* A57BB8 80240708 03E00008 */  jr        $ra
/* A57BBC 8024070C 27BD0020 */   addiu    $sp, $sp, 0x20
