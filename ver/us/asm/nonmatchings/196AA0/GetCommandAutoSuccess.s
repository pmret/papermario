.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetCommandAutoSuccess
/* 197C7C 8026939C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 197C80 802693A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 197C84 802693A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 197C88 802693A8 AFB00010 */  sw        $s0, 0x10($sp)
/* 197C8C 802693AC 8C82000C */  lw        $v0, 0xc($a0)
/* 197C90 802693B0 3C11802A */  lui       $s1, %hi(gActionCommandStatus)
/* 197C94 802693B4 2631FBE0 */  addiu     $s1, $s1, %lo(gActionCommandStatus)
/* 197C98 802693B8 8C450000 */  lw        $a1, ($v0)
/* 197C9C 802693BC 0C0B1EAF */  jal       evt_get_variable
/* 197CA0 802693C0 0220802D */   daddu    $s0, $s1, $zero
/* 197CA4 802693C4 10400003 */  beqz      $v0, .L802693D4
/* 197CA8 802693C8 24020001 */   addiu    $v0, $zero, 1
/* 197CAC 802693CC 0809A4F6 */  j         .L802693D8
/* 197CB0 802693D0 A222005E */   sb       $v0, 0x5e($s1)
.L802693D4:
/* 197CB4 802693D4 A200005E */  sb        $zero, 0x5e($s0)
.L802693D8:
/* 197CB8 802693D8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 197CBC 802693DC 8FB10014 */  lw        $s1, 0x14($sp)
/* 197CC0 802693E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 197CC4 802693E4 24020002 */  addiu     $v0, $zero, 2
/* 197CC8 802693E8 03E00008 */  jr        $ra
/* 197CCC 802693EC 27BD0020 */   addiu    $sp, $sp, 0x20
