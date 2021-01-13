.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel DidActionSucceed
/* 1A5794 80276EB4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1A5798 80276EB8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1A579C 80276EBC 8C82000C */  lw        $v0, 0xc($a0)
/* 1A57A0 80276EC0 3C03800E */  lui       $v1, %hi(gBattleStatus+0x81)
/* 1A57A4 80276EC4 8063C0F1 */  lb        $v1, %lo(gBattleStatus+0x81)($v1)
/* 1A57A8 80276EC8 8C450000 */  lw        $a1, ($v0)
/* 1A57AC 80276ECC 04610002 */  bgez      $v1, .L80276ED8
/* 1A57B0 80276ED0 0000302D */   daddu    $a2, $zero, $zero
/* 1A57B4 80276ED4 00C0182D */  daddu     $v1, $a2, $zero
.L80276ED8:
/* 1A57B8 80276ED8 00C3102A */  slt       $v0, $a2, $v1
/* 1A57BC 80276EDC 54400001 */  bnel      $v0, $zero, .L80276EE4
/* 1A57C0 80276EE0 0060302D */   daddu    $a2, $v1, $zero
.L80276EE4:
/* 1A57C4 80276EE4 0C0B2026 */  jal       set_variable
/* 1A57C8 80276EE8 00000000 */   nop
/* 1A57CC 80276EEC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1A57D0 80276EF0 24020002 */  addiu     $v0, $zero, 2
/* 1A57D4 80276EF4 03E00008 */  jr        $ra
/* 1A57D8 80276EF8 27BD0018 */   addiu    $sp, $sp, 0x18
