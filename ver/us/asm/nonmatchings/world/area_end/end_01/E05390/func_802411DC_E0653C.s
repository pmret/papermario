.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411DC_E0653C
/* E0653C 802411DC 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* E06540 802411E0 00A0102D */  daddu     $v0, $a1, $zero
/* E06544 802411E4 27A30038 */  addiu     $v1, $sp, 0x38
/* E06548 802411E8 AFBF0048 */  sw        $ra, 0x48($sp)
/* E0654C 802411EC F7B60058 */  sdc1      $f22, 0x58($sp)
/* E06550 802411F0 F7B40050 */  sdc1      $f20, 0x50($sp)
/* E06554 802411F4 C4540010 */  lwc1      $f20, 0x10($v0)
/* E06558 802411F8 4680A520 */  cvt.s.w   $f20, $f20
/* E0655C 802411FC C4560014 */  lwc1      $f22, 0x14($v0)
/* E06560 80241200 4680B5A0 */  cvt.s.w   $f22, $f22
/* E06564 80241204 AFA30010 */  sw        $v1, 0x10($sp)
/* E06568 80241208 8C440004 */  lw        $a0, 4($v0)
/* E0656C 8024120C 8C450008 */  lw        $a1, 8($v0)
/* E06570 80241210 8C460000 */  lw        $a2, ($v0)
/* E06574 80241214 0C04BA38 */  jal       msg_get_glyph
/* E06578 80241218 8C47000C */   lw       $a3, 0xc($v0)
/* E0657C 8024121C 4600A00D */  trunc.w.s $f0, $f20
/* E06580 80241220 44020000 */  mfc1      $v0, $f0
/* E06584 80241224 93A50040 */  lbu       $a1, 0x40($sp)
/* E06588 80241228 93A60041 */  lbu       $a2, 0x41($sp)
/* E0658C 8024122C 00021400 */  sll       $v0, $v0, 0x10
/* E06590 80241230 AFA00010 */  sw        $zero, 0x10($sp)
/* E06594 80241234 8FA3003C */  lw        $v1, 0x3c($sp)
/* E06598 80241238 00021403 */  sra       $v0, $v0, 0x10
/* E0659C 8024123C AFA20018 */  sw        $v0, 0x18($sp)
/* E065A0 80241240 4600B00D */  trunc.w.s $f0, $f22
/* E065A4 80241244 44020000 */  mfc1      $v0, $f0
/* E065A8 80241248 00000000 */  nop
/* E065AC 8024124C 00021400 */  sll       $v0, $v0, 0x10
/* E065B0 80241250 00021403 */  sra       $v0, $v0, 0x10
/* E065B4 80241254 AFA2001C */  sw        $v0, 0x1c($sp)
/* E065B8 80241258 2402000A */  addiu     $v0, $zero, 0xa
/* E065BC 8024125C AFA20020 */  sw        $v0, 0x20($sp)
/* E065C0 80241260 24020014 */  addiu     $v0, $zero, 0x14
/* E065C4 80241264 AFA20024 */  sw        $v0, 0x24($sp)
/* E065C8 80241268 2402012C */  addiu     $v0, $zero, 0x12c
/* E065CC 8024126C AFA20028 */  sw        $v0, 0x28($sp)
/* E065D0 80241270 240200C8 */  addiu     $v0, $zero, 0xc8
/* E065D4 80241274 AFA2002C */  sw        $v0, 0x2c($sp)
/* E065D8 80241278 240200FF */  addiu     $v0, $zero, 0xff
/* E065DC 8024127C AFA20030 */  sw        $v0, 0x30($sp)
/* E065E0 80241280 AFA30014 */  sw        $v1, 0x14($sp)
/* E065E4 80241284 8FA40038 */  lw        $a0, 0x38($sp)
/* E065E8 80241288 0C04BA68 */  jal       draw_ci_image_with_clipping
/* E065EC 8024128C 24070002 */   addiu    $a3, $zero, 2
/* E065F0 80241290 8FBF0048 */  lw        $ra, 0x48($sp)
/* E065F4 80241294 D7B60058 */  ldc1      $f22, 0x58($sp)
/* E065F8 80241298 D7B40050 */  ldc1      $f20, 0x50($sp)
/* E065FC 8024129C 03E00008 */  jr        $ra
/* E06600 802412A0 27BD0060 */   addiu    $sp, $sp, 0x60
