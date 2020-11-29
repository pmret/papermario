.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D3998
/* F8348 802D3998 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F834C 802D399C AFB10014 */  sw        $s1, 0x14($sp)
/* F8350 802D39A0 0080882D */  daddu     $s1, $a0, $zero
/* F8354 802D39A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* F8358 802D39A8 AFB00010 */  sw        $s0, 0x10($sp)
/* F835C 802D39AC 8E30000C */  lw        $s0, 0xc($s1)
/* F8360 802D39B0 8E050000 */  lw        $a1, ($s0)
/* F8364 802D39B4 0C0B1EAF */  jal       get_variable
/* F8368 802D39B8 26100004 */   addiu    $s0, $s0, 4
/* F836C 802D39BC 0220202D */  daddu     $a0, $s1, $zero
/* F8370 802D39C0 8E050000 */  lw        $a1, ($s0)
/* F8374 802D39C4 0C0B210B */  jal       get_float_variable
/* F8378 802D39C8 0040802D */   daddu    $s0, $v0, $zero
/* F837C 802D39CC 3C02802E */  lui       $v0, %hi(D_802DB7C0)
/* F8380 802D39D0 8C42B7C0 */  lw        $v0, %lo(D_802DB7C0)($v0)
/* F8384 802D39D4 00108080 */  sll       $s0, $s0, 2
/* F8388 802D39D8 02028021 */  addu      $s0, $s0, $v0
/* F838C 802D39DC 8E030000 */  lw        $v1, ($s0)
/* F8390 802D39E0 E460003C */  swc1      $f0, 0x3c($v1)
/* F8394 802D39E4 8FBF0018 */  lw        $ra, 0x18($sp)
/* F8398 802D39E8 8FB10014 */  lw        $s1, 0x14($sp)
/* F839C 802D39EC 8FB00010 */  lw        $s0, 0x10($sp)
/* F83A0 802D39F0 24020002 */  addiu     $v0, $zero, 2
/* F83A4 802D39F4 03E00008 */  jr        $ra
/* F83A8 802D39F8 27BD0020 */   addiu    $sp, $sp, 0x20
