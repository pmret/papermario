.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2C40
/* F75F0 802D2C40 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F75F4 802D2C44 AFB20018 */  sw        $s2, 0x18($sp)
/* F75F8 802D2C48 0080902D */  daddu     $s2, $a0, $zero
/* F75FC 802D2C4C AFBF001C */  sw        $ra, 0x1c($sp)
/* F7600 802D2C50 AFB10014 */  sw        $s1, 0x14($sp)
/* F7604 802D2C54 AFB00010 */  sw        $s0, 0x10($sp)
/* F7608 802D2C58 8E50000C */  lw        $s0, 0xc($s2)
/* F760C 802D2C5C 8E050000 */  lw        $a1, ($s0)
/* F7610 802D2C60 0C0B1EAF */  jal       get_variable
/* F7614 802D2C64 26100004 */   addiu    $s0, $s0, 4
/* F7618 802D2C68 44820000 */  mtc1      $v0, $f0
/* F761C 802D2C6C 00000000 */  nop       
/* F7620 802D2C70 46800020 */  cvt.s.w   $f0, $f0
/* F7624 802D2C74 3C118011 */  lui       $s1, 0x8011
/* F7628 802D2C78 2631EFC8 */  addiu     $s1, $s1, -0x1038
/* F762C 802D2C7C E620001C */  swc1      $f0, 0x1c($s1)
/* F7630 802D2C80 8E050000 */  lw        $a1, ($s0)
/* F7634 802D2C84 26100004 */  addiu     $s0, $s0, 4
/* F7638 802D2C88 0C0B1EAF */  jal       get_variable
/* F763C 802D2C8C 0240202D */   daddu    $a0, $s2, $zero
/* F7640 802D2C90 44820000 */  mtc1      $v0, $f0
/* F7644 802D2C94 00000000 */  nop       
/* F7648 802D2C98 46800020 */  cvt.s.w   $f0, $f0
/* F764C 802D2C9C E6200020 */  swc1      $f0, 0x20($s1)
/* F7650 802D2CA0 8E050000 */  lw        $a1, ($s0)
/* F7654 802D2CA4 0C0B1EAF */  jal       get_variable
/* F7658 802D2CA8 0240202D */   daddu    $a0, $s2, $zero
/* F765C 802D2CAC 44820000 */  mtc1      $v0, $f0
/* F7660 802D2CB0 00000000 */  nop       
/* F7664 802D2CB4 46800020 */  cvt.s.w   $f0, $f0
/* F7668 802D2CB8 E6200024 */  swc1      $f0, 0x24($s1)
/* F766C 802D2CBC 8FBF001C */  lw        $ra, 0x1c($sp)
/* F7670 802D2CC0 8FB20018 */  lw        $s2, 0x18($sp)
/* F7674 802D2CC4 8FB10014 */  lw        $s1, 0x14($sp)
/* F7678 802D2CC8 8FB00010 */  lw        $s0, 0x10($sp)
/* F767C 802D2CCC 24020002 */  addiu     $v0, $zero, 2
/* F7680 802D2CD0 03E00008 */  jr        $ra
/* F7684 802D2CD4 27BD0020 */   addiu    $sp, $sp, 0x20
