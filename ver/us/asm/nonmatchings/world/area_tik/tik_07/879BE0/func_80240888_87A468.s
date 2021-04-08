.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_07_UnkFunc22
/* 87A468 80240888 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 87A46C 8024088C AFBF0018 */  sw        $ra, 0x18($sp)
/* 87A470 80240890 0C00EAD2 */  jal       get_npc_safe
/* 87A474 80240894 2404FFFC */   addiu    $a0, $zero, -4
/* 87A478 80240898 C444003C */  lwc1      $f4, 0x3c($v0)
/* 87A47C 8024089C 3C014148 */  lui       $at, 0x4148
/* 87A480 802408A0 44811000 */  mtc1      $at, $f2
/* 87A484 802408A4 3C013F80 */  lui       $at, 0x3f80
/* 87A488 802408A8 44810000 */  mtc1      $at, $f0
/* 87A48C 802408AC 2403001E */  addiu     $v1, $zero, 0x1e
/* 87A490 802408B0 AFA30014 */  sw        $v1, 0x14($sp)
/* 87A494 802408B4 46022100 */  add.s     $f4, $f4, $f2
/* 87A498 802408B8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 87A49C 802408BC 8C450038 */  lw        $a1, 0x38($v0)
/* 87A4A0 802408C0 8C470040 */  lw        $a3, 0x40($v0)
/* 87A4A4 802408C4 44062000 */  mfc1      $a2, $f4
/* 87A4A8 802408C8 0C01C2EC */  jal       func_80070BB0
/* 87A4AC 802408CC 24040009 */   addiu    $a0, $zero, 9
/* 87A4B0 802408D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 87A4B4 802408D4 24020002 */  addiu     $v0, $zero, 2
/* 87A4B8 802408D8 03E00008 */  jr        $ra
/* 87A4BC 802408DC 27BD0020 */   addiu    $sp, $sp, 0x20
