.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D5FF8
/* FA9A8 802D5FF8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* FA9AC 802D5FFC AFB10014 */  sw        $s1, 0x14($sp)
/* FA9B0 802D6000 0080882D */  daddu     $s1, $a0, $zero
/* FA9B4 802D6004 AFBF0018 */  sw        $ra, 0x18($sp)
/* FA9B8 802D6008 AFB00010 */  sw        $s0, 0x10($sp)
/* FA9BC 802D600C 8E30000C */  lw        $s0, 0xc($s1)
/* FA9C0 802D6010 8E050000 */  lw        $a1, ($s0)
/* FA9C4 802D6014 0C0B1EAF */  jal       get_variable
/* FA9C8 802D6018 26100004 */   addiu    $s0, $s0, 4
/* FA9CC 802D601C 0220202D */  daddu     $a0, $s1, $zero
/* FA9D0 802D6020 8E050000 */  lw        $a1, ($s0)
/* FA9D4 802D6024 0C0B1EAF */  jal       get_variable
/* FA9D8 802D6028 0040802D */   daddu    $s0, $v0, $zero
/* FA9DC 802D602C 0200202D */  daddu     $a0, $s0, $zero
/* FA9E0 802D6030 0C052B7E */  jal       func_8014ADF8
/* FA9E4 802D6034 0040282D */   daddu    $a1, $v0, $zero
/* FA9E8 802D6038 8FBF0018 */  lw        $ra, 0x18($sp)
/* FA9EC 802D603C 8FB10014 */  lw        $s1, 0x14($sp)
/* FA9F0 802D6040 8FB00010 */  lw        $s0, 0x10($sp)
/* FA9F4 802D6044 24020002 */  addiu     $v0, $zero, 2
/* FA9F8 802D6048 03E00008 */  jr        $ra
/* FA9FC 802D604C 27BD0020 */   addiu    $sp, $sp, 0x20
