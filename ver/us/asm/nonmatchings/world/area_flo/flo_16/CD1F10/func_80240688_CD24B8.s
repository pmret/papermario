.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel flo_16_UnkFunc22
/* CD24B8 80240688 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD24BC 8024068C AFBF0018 */  sw        $ra, 0x18($sp)
/* CD24C0 80240690 0C00EAD2 */  jal       get_npc_safe
/* CD24C4 80240694 2404FFFC */   addiu    $a0, $zero, -4
/* CD24C8 80240698 C444003C */  lwc1      $f4, 0x3c($v0)
/* CD24CC 8024069C 3C014148 */  lui       $at, 0x4148
/* CD24D0 802406A0 44811000 */  mtc1      $at, $f2
/* CD24D4 802406A4 3C013F80 */  lui       $at, 0x3f80
/* CD24D8 802406A8 44810000 */  mtc1      $at, $f0
/* CD24DC 802406AC 2403001E */  addiu     $v1, $zero, 0x1e
/* CD24E0 802406B0 AFA30014 */  sw        $v1, 0x14($sp)
/* CD24E4 802406B4 46022100 */  add.s     $f4, $f4, $f2
/* CD24E8 802406B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* CD24EC 802406BC 8C450038 */  lw        $a1, 0x38($v0)
/* CD24F0 802406C0 8C470040 */  lw        $a3, 0x40($v0)
/* CD24F4 802406C4 44062000 */  mfc1      $a2, $f4
/* CD24F8 802406C8 0C01C2EC */  jal       func_80070BB0
/* CD24FC 802406CC 24040009 */   addiu    $a0, $zero, 9
/* CD2500 802406D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD2504 802406D4 24020002 */  addiu     $v0, $zero, 2
/* CD2508 802406D8 03E00008 */  jr        $ra
/* CD250C 802406DC 27BD0020 */   addiu    $sp, $sp, 0x20
