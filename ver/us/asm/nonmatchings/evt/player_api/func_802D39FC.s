.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D39FC
/* F83AC 802D39FC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* F83B0 802D3A00 AFB10014 */  sw        $s1, 0x14($sp)
/* F83B4 802D3A04 0080882D */  daddu     $s1, $a0, $zero
/* F83B8 802D3A08 AFBF0018 */  sw        $ra, 0x18($sp)
/* F83BC 802D3A0C AFB00010 */  sw        $s0, 0x10($sp)
/* F83C0 802D3A10 8E30000C */  lw        $s0, 0xc($s1)
/* F83C4 802D3A14 8E050000 */  lw        $a1, ($s0)
/* F83C8 802D3A18 0C0B1EAF */  jal       get_variable
/* F83CC 802D3A1C 26100004 */   addiu    $s0, $s0, 4
/* F83D0 802D3A20 0220202D */  daddu     $a0, $s1, $zero
/* F83D4 802D3A24 8E050000 */  lw        $a1, ($s0)
/* F83D8 802D3A28 0C0B210B */  jal       get_float_variable
/* F83DC 802D3A2C 0040802D */   daddu    $s0, $v0, $zero
/* F83E0 802D3A30 3C02802E */  lui       $v0, %hi(D_802DB7C0)
/* F83E4 802D3A34 8C42B7C0 */  lw        $v0, %lo(D_802DB7C0)($v0)
/* F83E8 802D3A38 00108080 */  sll       $s0, $s0, 2
/* F83EC 802D3A3C 02028021 */  addu      $s0, $s0, $v0
/* F83F0 802D3A40 8E030000 */  lw        $v1, ($s0)
/* F83F4 802D3A44 E4600040 */  swc1      $f0, 0x40($v1)
/* F83F8 802D3A48 8FBF0018 */  lw        $ra, 0x18($sp)
/* F83FC 802D3A4C 8FB10014 */  lw        $s1, 0x14($sp)
/* F8400 802D3A50 8FB00010 */  lw        $s0, 0x10($sp)
/* F8404 802D3A54 24020002 */  addiu     $v0, $zero, 2
/* F8408 802D3A58 03E00008 */  jr        $ra
/* F840C 802D3A5C 27BD0020 */   addiu    $sp, $sp, 0x20
