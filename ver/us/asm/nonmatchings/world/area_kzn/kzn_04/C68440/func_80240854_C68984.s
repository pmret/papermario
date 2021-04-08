.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_04_UnkFunc21
/* C68984 80240854 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C68988 80240858 AFBF0018 */  sw        $ra, 0x18($sp)
/* C6898C 8024085C 8C82000C */  lw        $v0, 0xc($a0)
/* C68990 80240860 0C0B1EAF */  jal       get_variable
/* C68994 80240864 8C450000 */   lw       $a1, ($v0)
/* C68998 80240868 0C04417A */  jal       get_entity_by_index
/* C6899C 8024086C 0040202D */   daddu    $a0, $v0, $zero
/* C689A0 80240870 3C013F80 */  lui       $at, 0x3f80
/* C689A4 80240874 44810000 */  mtc1      $at, $f0
/* C689A8 80240878 C442004C */  lwc1      $f2, 0x4c($v0)
/* C689AC 8024087C E7A00010 */  swc1      $f0, 0x10($sp)
/* C689B0 80240880 3C014148 */  lui       $at, 0x4148
/* C689B4 80240884 44810000 */  mtc1      $at, $f0
/* C689B8 80240888 2403004B */  addiu     $v1, $zero, 0x4b
/* C689BC 8024088C AFA30014 */  sw        $v1, 0x14($sp)
/* C689C0 80240890 46001080 */  add.s     $f2, $f2, $f0
/* C689C4 80240894 8C450048 */  lw        $a1, 0x48($v0)
/* C689C8 80240898 8C470050 */  lw        $a3, 0x50($v0)
/* C689CC 8024089C 44061000 */  mfc1      $a2, $f2
/* C689D0 802408A0 0C01C2EC */  jal       func_80070BB0
/* C689D4 802408A4 24040004 */   addiu    $a0, $zero, 4
/* C689D8 802408A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* C689DC 802408AC 24020002 */  addiu     $v0, $zero, 2
/* C689E0 802408B0 03E00008 */  jr        $ra
/* C689E4 802408B4 27BD0020 */   addiu    $sp, $sp, 0x20
