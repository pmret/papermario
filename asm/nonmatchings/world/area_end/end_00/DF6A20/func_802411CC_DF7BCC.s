.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411CC_DF7BCC
/* DF7BCC 802411CC 27BDFFA0 */  addiu     $sp, $sp, -0x60
/* DF7BD0 802411D0 00A0102D */  daddu     $v0, $a1, $zero
/* DF7BD4 802411D4 27A30038 */  addiu     $v1, $sp, 0x38
/* DF7BD8 802411D8 AFBF0048 */  sw        $ra, 0x48($sp)
/* DF7BDC 802411DC F7B60058 */  sdc1      $f22, 0x58($sp)
/* DF7BE0 802411E0 F7B40050 */  sdc1      $f20, 0x50($sp)
/* DF7BE4 802411E4 C4540010 */  lwc1      $f20, 0x10($v0)
/* DF7BE8 802411E8 4680A520 */  cvt.s.w   $f20, $f20
/* DF7BEC 802411EC C4560014 */  lwc1      $f22, 0x14($v0)
/* DF7BF0 802411F0 4680B5A0 */  cvt.s.w   $f22, $f22
/* DF7BF4 802411F4 AFA30010 */  sw        $v1, 0x10($sp)
/* DF7BF8 802411F8 8C440004 */  lw        $a0, 4($v0)
/* DF7BFC 802411FC 8C450008 */  lw        $a1, 8($v0)
/* DF7C00 80241200 8C460000 */  lw        $a2, ($v0)
/* DF7C04 80241204 0C04BA38 */  jal       func_8012E8E0
/* DF7C08 80241208 8C47000C */   lw       $a3, 0xc($v0)
/* DF7C0C 8024120C 4600A00D */  trunc.w.s $f0, $f20
/* DF7C10 80241210 44020000 */  mfc1      $v0, $f0
/* DF7C14 80241214 93A50040 */  lbu       $a1, 0x40($sp)
/* DF7C18 80241218 93A60041 */  lbu       $a2, 0x41($sp)
/* DF7C1C 8024121C 00021400 */  sll       $v0, $v0, 0x10
/* DF7C20 80241220 AFA00010 */  sw        $zero, 0x10($sp)
/* DF7C24 80241224 8FA3003C */  lw        $v1, 0x3c($sp)
/* DF7C28 80241228 00021403 */  sra       $v0, $v0, 0x10
/* DF7C2C 8024122C AFA20018 */  sw        $v0, 0x18($sp)
/* DF7C30 80241230 4600B00D */  trunc.w.s $f0, $f22
/* DF7C34 80241234 44020000 */  mfc1      $v0, $f0
/* DF7C38 80241238 00000000 */  nop       
/* DF7C3C 8024123C 00021400 */  sll       $v0, $v0, 0x10
/* DF7C40 80241240 00021403 */  sra       $v0, $v0, 0x10
/* DF7C44 80241244 AFA2001C */  sw        $v0, 0x1c($sp)
/* DF7C48 80241248 2402000A */  addiu     $v0, $zero, 0xa
/* DF7C4C 8024124C AFA20020 */  sw        $v0, 0x20($sp)
/* DF7C50 80241250 24020014 */  addiu     $v0, $zero, 0x14
/* DF7C54 80241254 AFA20024 */  sw        $v0, 0x24($sp)
/* DF7C58 80241258 2402012C */  addiu     $v0, $zero, 0x12c
/* DF7C5C 8024125C AFA20028 */  sw        $v0, 0x28($sp)
/* DF7C60 80241260 240200C8 */  addiu     $v0, $zero, 0xc8
/* DF7C64 80241264 AFA2002C */  sw        $v0, 0x2c($sp)
/* DF7C68 80241268 240200FF */  addiu     $v0, $zero, 0xff
/* DF7C6C 8024126C AFA20030 */  sw        $v0, 0x30($sp)
/* DF7C70 80241270 AFA30014 */  sw        $v1, 0x14($sp)
/* DF7C74 80241274 8FA40038 */  lw        $a0, 0x38($sp)
/* DF7C78 80241278 0C04BA68 */  jal       func_8012E9A0
/* DF7C7C 8024127C 24070002 */   addiu    $a3, $zero, 2
/* DF7C80 80241280 8FBF0048 */  lw        $ra, 0x48($sp)
/* DF7C84 80241284 D7B60058 */  ldc1      $f22, 0x58($sp)
/* DF7C88 80241288 D7B40050 */  ldc1      $f20, 0x50($sp)
/* DF7C8C 8024128C 03E00008 */  jr        $ra
/* DF7C90 80241290 27BD0060 */   addiu    $sp, $sp, 0x60
