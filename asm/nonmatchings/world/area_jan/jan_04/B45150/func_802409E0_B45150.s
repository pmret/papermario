.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409E0_B45150
/* B45150 802409E0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* B45154 802409E4 3C048024 */  lui       $a0, %hi(D_802462C0)
/* B45158 802409E8 248462C0 */  addiu     $a0, $a0, %lo(D_802462C0)
/* B4515C 802409EC 27A50010 */  addiu     $a1, $sp, 0x10
/* B45160 802409F0 AFBF0020 */  sw        $ra, 0x20($sp)
/* B45164 802409F4 AFB1001C */  sw        $s1, 0x1c($sp)
/* B45168 802409F8 0C016B3A */  jal       load_asset_by_name
/* B4516C 802409FC AFB00018 */   sw       $s0, 0x18($sp)
/* B45170 80240A00 0040802D */  daddu     $s0, $v0, $zero
/* B45174 80240A04 0200202D */  daddu     $a0, $s0, $zero
/* B45178 80240A08 3C118024 */  lui       $s1, %hi(D_80246300)
/* B4517C 80240A0C 26316300 */  addiu     $s1, $s1, %lo(D_80246300)
/* B45180 80240A10 0C01BB7C */  jal       decode_yay0
/* B45184 80240A14 0220282D */   daddu    $a1, $s1, $zero
/* B45188 80240A18 0C00AB1E */  jal       general_heap_free
/* B4518C 80240A1C 0200202D */   daddu    $a0, $s0, $zero
/* B45190 80240A20 3C048025 */  lui       $a0, %hi(D_8024A2A0)
/* B45194 80240A24 2484A2A0 */  addiu     $a0, $a0, %lo(D_8024A2A0)
/* B45198 80240A28 3C028024 */  lui       $v0, %hi(func_80246500_806D80)
/* B4519C 80240A2C 24426500 */  addiu     $v0, $v0, %lo(func_80246500_806D80)
/* B451A0 80240A30 AC820000 */  sw        $v0, ($a0)
/* B451A4 80240A34 24020096 */  addiu     $v0, $zero, 0x96
/* B451A8 80240A38 A4820008 */  sh        $v0, 8($a0)
/* B451AC 80240A3C 24020069 */  addiu     $v0, $zero, 0x69
/* B451B0 80240A40 A482000A */  sh        $v0, 0xa($a0)
/* B451B4 80240A44 24020002 */  addiu     $v0, $zero, 2
/* B451B8 80240A48 AC82000C */  sw        $v0, 0xc($a0)
/* B451BC 80240A4C 24020001 */  addiu     $v0, $zero, 1
/* B451C0 80240A50 AC910004 */  sw        $s1, 4($a0)
/* B451C4 80240A54 0C0496CB */  jal       set_message_images
/* B451C8 80240A58 AC820010 */   sw       $v0, 0x10($a0)
/* B451CC 80240A5C 8FBF0020 */  lw        $ra, 0x20($sp)
/* B451D0 80240A60 8FB1001C */  lw        $s1, 0x1c($sp)
/* B451D4 80240A64 8FB00018 */  lw        $s0, 0x18($sp)
/* B451D8 80240A68 24020002 */  addiu     $v0, $zero, 2
/* B451DC 80240A6C 03E00008 */  jr        $ra
/* B451E0 80240A70 27BD0028 */   addiu    $sp, $sp, 0x28
/* B451E4 80240A74 00000000 */  nop
/* B451E8 80240A78 00000000 */  nop
/* B451EC 80240A7C 00000000 */  nop
