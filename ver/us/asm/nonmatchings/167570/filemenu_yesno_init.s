.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel filemenu_yesno_init
/* 1679F8 80247198 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1679FC 8024719C AFB00010 */  sw        $s0, 0x10($sp)
/* 167A00 802471A0 0080802D */  daddu     $s0, $a0, $zero
/* 167A04 802471A4 24030001 */  addiu     $v1, $zero, 1
/* 167A08 802471A8 3C028025 */  lui       $v0, %hi(D_8024A0F0)
/* 167A0C 802471AC 2442A0F0 */  addiu     $v0, $v0, %lo(D_8024A0F0)
/* 167A10 802471B0 AFBF0014 */  sw        $ra, 0x14($sp)
.L802471B4:
/* 167A14 802471B4 AC500010 */  sw        $s0, 0x10($v0)
/* 167A18 802471B8 2463FFFF */  addiu     $v1, $v1, -1
/* 167A1C 802471BC 0461FFFD */  bgez      $v1, .L802471B4
/* 167A20 802471C0 2442FFDC */   addiu    $v0, $v0, -0x24
/* 167A24 802471C4 3C048025 */  lui       $a0, %hi(D_8024A0CC)
/* 167A28 802471C8 2484A0CC */  addiu     $a0, $a0, %lo(D_8024A0CC)
/* 167A2C 802471CC 0C051FCC */  jal       setup_pause_menu_tab
/* 167A30 802471D0 24050002 */   addiu    $a1, $zero, 2
/* 167A34 802471D4 24020001 */  addiu     $v0, $zero, 1
/* 167A38 802471D8 A2020000 */  sb        $v0, ($s0)
/* 167A3C 802471DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 167A40 802471E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 167A44 802471E4 03E00008 */  jr        $ra
/* 167A48 802471E8 27BD0018 */   addiu    $sp, $sp, 0x18
