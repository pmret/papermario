.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024085C_97BE8C
/* 97BE8C 8024085C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 97BE90 80240860 AFBF0010 */  sw        $ra, 0x10($sp)
/* 97BE94 80240864 0C00EAD2 */  jal       get_npc_safe
/* 97BE98 80240868 8C84014C */   lw       $a0, 0x14c($a0)
/* 97BE9C 8024086C 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* 97BEA0 80240870 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* 97BEA4 80240874 C44C0038 */  lwc1      $f12, 0x38($v0)
/* 97BEA8 80240878 C44E0040 */  lwc1      $f14, 0x40($v0)
/* 97BEAC 8024087C 8C660028 */  lw        $a2, 0x28($v1)
/* 97BEB0 80240880 0C00A7B5 */  jal       dist2D
/* 97BEB4 80240884 8C670030 */   lw       $a3, 0x30($v1)
/* 97BEB8 80240888 3C014248 */  lui       $at, 0x4248
/* 97BEBC 8024088C 44811000 */  mtc1      $at, $f2
/* 97BEC0 80240890 00000000 */  nop       
/* 97BEC4 80240894 4602003C */  c.lt.s    $f0, $f2
/* 97BEC8 80240898 00000000 */  nop       
/* 97BECC 8024089C 45010002 */  bc1t      .L802408A8
/* 97BED0 802408A0 24020002 */   addiu    $v0, $zero, 2
/* 97BED4 802408A4 0000102D */  daddu     $v0, $zero, $zero
.L802408A8:
/* 97BED8 802408A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 97BEDC 802408AC 03E00008 */  jr        $ra
/* 97BEE0 802408B0 27BD0018 */   addiu    $sp, $sp, 0x18
