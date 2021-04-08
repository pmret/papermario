.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_04_UnkFunc22
/* C689E8 802408B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C689EC 802408BC AFBF0018 */  sw        $ra, 0x18($sp)
/* C689F0 802408C0 0C00EAD2 */  jal       get_npc_safe
/* C689F4 802408C4 2404FFFC */   addiu    $a0, $zero, -4
/* C689F8 802408C8 C444003C */  lwc1      $f4, 0x3c($v0)
/* C689FC 802408CC 3C014148 */  lui       $at, 0x4148
/* C68A00 802408D0 44811000 */  mtc1      $at, $f2
/* C68A04 802408D4 3C013F80 */  lui       $at, 0x3f80
/* C68A08 802408D8 44810000 */  mtc1      $at, $f0
/* C68A0C 802408DC 2403001E */  addiu     $v1, $zero, 0x1e
/* C68A10 802408E0 AFA30014 */  sw        $v1, 0x14($sp)
/* C68A14 802408E4 46022100 */  add.s     $f4, $f4, $f2
/* C68A18 802408E8 E7A00010 */  swc1      $f0, 0x10($sp)
/* C68A1C 802408EC 8C450038 */  lw        $a1, 0x38($v0)
/* C68A20 802408F0 8C470040 */  lw        $a3, 0x40($v0)
/* C68A24 802408F4 44062000 */  mfc1      $a2, $f4
/* C68A28 802408F8 0C01C2EC */  jal       func_80070BB0
/* C68A2C 802408FC 24040009 */   addiu    $a0, $zero, 9
/* C68A30 80240900 8FBF0018 */  lw        $ra, 0x18($sp)
/* C68A34 80240904 24020002 */  addiu     $v0, $zero, 2
/* C68A38 80240908 03E00008 */  jr        $ra
/* C68A3C 8024090C 27BD0020 */   addiu    $sp, $sp, 0x20
