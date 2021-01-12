.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BBE14_E30764
/* E30764 802BBE14 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E30768 802BBE18 AFB00010 */  sw        $s0, 0x10($sp)
/* E3076C 802BBE1C 0080802D */  daddu     $s0, $a0, $zero
/* E30770 802BBE20 AFBF0018 */  sw        $ra, 0x18($sp)
/* E30774 802BBE24 AFB10014 */  sw        $s1, 0x14($sp)
/* E30778 802BBE28 8E110040 */  lw        $s1, 0x40($s0)
/* E3077C 802BBE2C 3C028016 */  lui       $v0, %hi(D_8015C7D0)
/* E30780 802BBE30 8C42C7D0 */  lw        $v0, %lo(D_8015C7D0)($v0)
/* E30784 802BBE34 0C0AEDF8 */  jal       func_802BB7E0_E30130
/* E30788 802BBE38 AE2200A0 */   sw       $v0, 0xa0($s1)
/* E3078C 802BBE3C 3C02802C */  lui       $v0, %hi(func_802BB3B8_E2FD08)
/* E30790 802BBE40 2442B3B8 */  addiu     $v0, $v0, %lo(func_802BB3B8_E2FD08)
/* E30794 802BBE44 A2200003 */  sb        $zero, 3($s1)
/* E30798 802BBE48 AE02003C */  sw        $v0, 0x3c($s0)
/* E3079C 802BBE4C AE000054 */  sw        $zero, 0x54($s0)
/* E307A0 802BBE50 AE000058 */  sw        $zero, 0x58($s0)
/* E307A4 802BBE54 AE00005C */  sw        $zero, 0x5c($s0)
/* E307A8 802BBE58 8FBF0018 */  lw        $ra, 0x18($sp)
/* E307AC 802BBE5C 8FB10014 */  lw        $s1, 0x14($sp)
/* E307B0 802BBE60 8FB00010 */  lw        $s0, 0x10($sp)
/* E307B4 802BBE64 03E00008 */  jr        $ra
/* E307B8 802BBE68 27BD0020 */   addiu    $sp, $sp, 0x20
/* E307BC 802BBE6C 00000000 */  nop       
