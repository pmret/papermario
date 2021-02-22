.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004A3A0
/* 257A0 8004A3A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 257A4 8004A3A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 257A8 8004A3A8 0080802D */  daddu     $s0, $a0, $zero
/* 257AC 8004A3AC AFBF0014 */  sw        $ra, 0x14($sp)
/* 257B0 8004A3B0 8E020148 */  lw        $v0, 0x148($s0)
/* 257B4 8004A3B4 0C00E9EB */  jal       func_8003A7AC
/* 257B8 8004A3B8 84440008 */   lh       $a0, 8($v0)
/* 257BC 8004A3BC 9443008E */  lhu       $v1, 0x8e($v0)
/* 257C0 8004A3C0 2463FFFF */  addiu     $v1, $v1, -1
/* 257C4 8004A3C4 A443008E */  sh        $v1, 0x8e($v0)
/* 257C8 8004A3C8 00031C00 */  sll       $v1, $v1, 0x10
/* 257CC 8004A3CC 1C600003 */  bgtz      $v1, .L8004A3DC
/* 257D0 8004A3D0 00000000 */   nop
/* 257D4 8004A3D4 8E020074 */  lw        $v0, 0x74($s0)
/* 257D8 8004A3D8 AE020070 */  sw        $v0, 0x70($s0)
.L8004A3DC:
/* 257DC 8004A3DC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 257E0 8004A3E0 8FB00010 */  lw        $s0, 0x10($sp)
/* 257E4 8004A3E4 03E00008 */  jr        $ra
/* 257E8 8004A3E8 27BD0018 */   addiu    $sp, $sp, 0x18
