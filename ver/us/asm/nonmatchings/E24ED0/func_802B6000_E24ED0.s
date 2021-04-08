.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E24ED0
/* E24ED0 802B6000 3C020100 */  lui       $v0, 0x100
/* E24ED4 802B6004 00821024 */  and       $v0, $a0, $v0
/* E24ED8 802B6008 10400003 */  beqz      $v0, .L802B6018
/* E24EDC 802B600C 3C02FFF9 */   lui      $v0, 0xfff9
/* E24EE0 802B6010 03E00008 */  jr        $ra
/* E24EE4 802B6014 24020001 */   addiu    $v0, $zero, 1
.L802B6018:
/* E24EE8 802B6018 3442FFEF */  ori       $v0, $v0, 0xffef
/* E24EEC 802B601C 00822021 */  addu      $a0, $a0, $v0
/* E24EF0 802B6020 2C82000B */  sltiu     $v0, $a0, 0xb
/* E24EF4 802B6024 10400006 */  beqz      $v0, .L802B6040
/* E24EF8 802B6028 00041080 */   sll      $v0, $a0, 2
/* E24EFC 802B602C 3C01802B */  lui       $at, %hi(D_802B6DC0_E25C90)
/* E24F00 802B6030 00220821 */  addu      $at, $at, $v0
/* E24F04 802B6034 8C226DC0 */  lw        $v0, %lo(D_802B6DC0_E25C90)($at)
/* E24F08 802B6038 00400008 */  jr        $v0
/* E24F0C 802B603C 00000000 */   nop
.L802B6040:
/* E24F10 802B6040 03E00008 */  jr        $ra
/* E24F14 802B6044 0000102D */   daddu    $v0, $zero, $zero
