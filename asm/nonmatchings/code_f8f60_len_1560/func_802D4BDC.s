.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D4BDC
/* F958C 802D4BDC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F9590 802D4BE0 AFBF0010 */  sw        $ra, 0x10($sp)
/* F9594 802D4BE4 10A00003 */  beqz      $a1, .L802D4BF4
/* F9598 802D4BE8 0080182D */   daddu    $v1, $a0, $zero
/* F959C 802D4BEC AC600070 */  sw        $zero, 0x70($v1)
/* F95A0 802D4BF0 AC600074 */  sw        $zero, 0x74($v1)
.L802D4BF4:
/* F95A4 802D4BF4 8C620070 */  lw        $v0, 0x70($v1)
/* F95A8 802D4BF8 14400011 */  bnez      $v0, .L802D4C40
/* F95AC 802D4BFC 0000102D */   daddu    $v0, $zero, $zero
/* F95B0 802D4C00 8C620074 */  lw        $v0, 0x74($v1)
/* F95B4 802D4C04 240400FF */  addiu     $a0, $zero, 0xff
/* F95B8 802D4C08 14440003 */  bne       $v0, $a0, .L802D4C18
/* F95BC 802D4C0C 2442000A */   addiu    $v0, $v0, 0xa
/* F95C0 802D4C10 080B5310 */  j         .L802D4C40
/* F95C4 802D4C14 24020002 */   addiu    $v0, $zero, 2
.L802D4C18:
/* F95C8 802D4C18 AC620074 */  sw        $v0, 0x74($v1)
/* F95CC 802D4C1C 28420100 */  slti      $v0, $v0, 0x100
/* F95D0 802D4C20 50400001 */  beql      $v0, $zero, .L802D4C28
/* F95D4 802D4C24 AC640074 */   sw       $a0, 0x74($v1)
.L802D4C28:
/* F95D8 802D4C28 C4600074 */  lwc1      $f0, 0x74($v1)
/* F95DC 802D4C2C 46800020 */  cvt.s.w   $f0, $f0
/* F95E0 802D4C30 44050000 */  mfc1      $a1, $f0
/* F95E4 802D4C34 0C04DF69 */  jal       func_80137DA4
/* F95E8 802D4C38 2404000A */   addiu    $a0, $zero, 0xa
/* F95EC 802D4C3C 0000102D */  daddu     $v0, $zero, $zero
.L802D4C40:
/* F95F0 802D4C40 8FBF0010 */  lw        $ra, 0x10($sp)
/* F95F4 802D4C44 03E00008 */  jr        $ra
/* F95F8 802D4C48 27BD0018 */   addiu    $sp, $sp, 0x18
