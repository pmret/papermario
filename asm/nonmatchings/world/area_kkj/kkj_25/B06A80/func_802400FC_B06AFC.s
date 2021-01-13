.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400FC_B06AFC
/* B06AFC 802400FC 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* B06B00 80240100 AFB10014 */  sw        $s1, 0x14($sp)
/* B06B04 80240104 0080882D */  daddu     $s1, $a0, $zero
/* B06B08 80240108 AFBF001C */  sw        $ra, 0x1c($sp)
/* B06B0C 8024010C AFB20018 */  sw        $s2, 0x18($sp)
/* B06B10 80240110 AFB00010 */  sw        $s0, 0x10($sp)
/* B06B14 80240114 F7B80030 */  sdc1      $f24, 0x30($sp)
/* B06B18 80240118 F7B60028 */  sdc1      $f22, 0x28($sp)
/* B06B1C 8024011C F7B40020 */  sdc1      $f20, 0x20($sp)
/* B06B20 80240120 8E30000C */  lw        $s0, 0xc($s1)
/* B06B24 80240124 8E050000 */  lw        $a1, ($s0)
/* B06B28 80240128 0C0B1EAF */  jal       get_variable
/* B06B2C 8024012C 26100004 */   addiu    $s0, $s0, 4
/* B06B30 80240130 8E050000 */  lw        $a1, ($s0)
/* B06B34 80240134 26100004 */  addiu     $s0, $s0, 4
/* B06B38 80240138 0220202D */  daddu     $a0, $s1, $zero
/* B06B3C 8024013C 0C0B1EAF */  jal       get_variable
/* B06B40 80240140 0040902D */   daddu    $s2, $v0, $zero
/* B06B44 80240144 8E050000 */  lw        $a1, ($s0)
/* B06B48 80240148 26100004 */  addiu     $s0, $s0, 4
/* B06B4C 8024014C 4482C000 */  mtc1      $v0, $f24
/* B06B50 80240150 00000000 */  nop
/* B06B54 80240154 4680C620 */  cvt.s.w   $f24, $f24
/* B06B58 80240158 0C0B1EAF */  jal       get_variable
/* B06B5C 8024015C 0220202D */   daddu    $a0, $s1, $zero
/* B06B60 80240160 8E050000 */  lw        $a1, ($s0)
/* B06B64 80240164 4482B000 */  mtc1      $v0, $f22
/* B06B68 80240168 00000000 */  nop
/* B06B6C 8024016C 4680B5A0 */  cvt.s.w   $f22, $f22
/* B06B70 80240170 0C0B1EAF */  jal       get_variable
/* B06B74 80240174 0220202D */   daddu    $a0, $s1, $zero
/* B06B78 80240178 4482A000 */  mtc1      $v0, $f20
/* B06B7C 8024017C 00000000 */  nop
/* B06B80 80240180 4680A520 */  cvt.s.w   $f20, $f20
/* B06B84 80240184 0C04417A */  jal       get_entity_by_index
/* B06B88 80240188 0240202D */   daddu    $a0, $s2, $zero
/* B06B8C 8024018C 0040182D */  daddu     $v1, $v0, $zero
/* B06B90 80240190 E4780048 */  swc1      $f24, 0x48($v1)
/* B06B94 80240194 E476004C */  swc1      $f22, 0x4c($v1)
/* B06B98 80240198 E4740050 */  swc1      $f20, 0x50($v1)
/* B06B9C 8024019C 8FBF001C */  lw        $ra, 0x1c($sp)
/* B06BA0 802401A0 8FB20018 */  lw        $s2, 0x18($sp)
/* B06BA4 802401A4 8FB10014 */  lw        $s1, 0x14($sp)
/* B06BA8 802401A8 8FB00010 */  lw        $s0, 0x10($sp)
/* B06BAC 802401AC D7B80030 */  ldc1      $f24, 0x30($sp)
/* B06BB0 802401B0 D7B60028 */  ldc1      $f22, 0x28($sp)
/* B06BB4 802401B4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* B06BB8 802401B8 24020002 */  addiu     $v0, $zero, 2
/* B06BBC 802401BC 03E00008 */  jr        $ra
/* B06BC0 802401C0 27BD0038 */   addiu    $sp, $sp, 0x38
