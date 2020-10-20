.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411A0_B216E0
/* B216E0 802411A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B216E4 802411A4 0080182D */  daddu     $v1, $a0, $zero
/* B216E8 802411A8 00A0202D */  daddu     $a0, $a1, $zero
/* B216EC 802411AC 2402FFFF */  addiu     $v0, $zero, -1
/* B216F0 802411B0 14820004 */  bne       $a0, $v0, .L802411C4
/* B216F4 802411B4 AFBF0010 */   sw       $ra, 0x10($sp)
/* B216F8 802411B8 8C64014C */  lw        $a0, 0x14c($v1)
/* B216FC 802411BC 08090476 */  j         .L802411D8
/* B21700 802411C0 00000000 */   nop      
.L802411C4:
/* B21704 802411C4 3C02EFE8 */  lui       $v0, 0xefe8
/* B21708 802411C8 34422080 */  ori       $v0, $v0, 0x2080
/* B2170C 802411CC 0082102A */  slt       $v0, $a0, $v0
/* B21710 802411D0 14400003 */  bnez      $v0, .L802411E0
/* B21714 802411D4 0080102D */   daddu    $v0, $a0, $zero
.L802411D8:
/* B21718 802411D8 0C00EAD2 */  jal       get_npc_safe
/* B2171C 802411DC 00000000 */   nop      
.L802411E0:
/* B21720 802411E0 8FBF0010 */  lw        $ra, 0x10($sp)
/* B21724 802411E4 03E00008 */  jr        $ra
/* B21728 802411E8 27BD0018 */   addiu    $sp, $sp, 0x18
