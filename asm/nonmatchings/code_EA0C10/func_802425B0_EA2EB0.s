.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425B0_EA2EB0
/* EA2EB0 802425B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA2EB4 802425B4 AFBF0010 */  sw        $ra, 0x10($sp)
/* EA2EB8 802425B8 0C00F94D */  jal       func_8003E534
/* EA2EBC 802425BC 8C84014C */   lw       $a0, 0x14c($a0)
/* EA2EC0 802425C0 3C038011 */  lui       $v1, %hi(D_80117578)
/* EA2EC4 802425C4 24637578 */  addiu     $v1, $v1, %lo(D_80117578)
/* EA2EC8 802425C8 C44C0038 */  lwc1      $f12, 0x38($v0)
/* EA2ECC 802425CC C44E0040 */  lwc1      $f14, 0x40($v0)
/* EA2ED0 802425D0 8C660028 */  lw        $a2, 0x28($v1)
/* EA2ED4 802425D4 0C00AC71 */  jal       func_8002B1C4
/* EA2ED8 802425D8 8C670030 */   lw       $a3, 0x30($v1)
/* EA2EDC 802425DC 3C014248 */  lui       $at, 0x4248
/* EA2EE0 802425E0 44811000 */  mtc1      $at, $f2
/* EA2EE4 802425E4 00000000 */  nop
/* EA2EE8 802425E8 4602003C */  c.lt.s    $f0, $f2
/* EA2EEC 802425EC 00000000 */  nop
/* EA2EF0 802425F0 45010002 */  bc1t      .L802425FC
/* EA2EF4 802425F4 24020002 */   addiu    $v0, $zero, 2
/* EA2EF8 802425F8 0000102D */  daddu     $v0, $zero, $zero
.L802425FC:
/* EA2EFC 802425FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA2F00 80242600 03E00008 */  jr        $ra
/* EA2F04 80242604 27BD0018 */   addiu    $sp, $sp, 0x18
