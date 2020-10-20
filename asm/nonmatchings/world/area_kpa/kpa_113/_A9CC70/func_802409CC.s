.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409CC
/* A9D5FC 802409CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A9D600 802409D0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A9D604 802409D4 0C00EAD2 */  jal       get_npc_safe
/* A9D608 802409D8 8C84014C */   lw       $a0, 0x14c($a0)
/* A9D60C 802409DC 3C038011 */  lui       $v1, %hi(gPlayerStatus)
/* A9D610 802409E0 2463EFC8 */  addiu     $v1, $v1, %lo(gPlayerStatus)
/* A9D614 802409E4 C44C0038 */  lwc1      $f12, 0x38($v0)
/* A9D618 802409E8 C44E0040 */  lwc1      $f14, 0x40($v0)
/* A9D61C 802409EC 8C660028 */  lw        $a2, 0x28($v1)
/* A9D620 802409F0 0C00A7B5 */  jal       dist2D
/* A9D624 802409F4 8C670030 */   lw       $a3, 0x30($v1)
/* A9D628 802409F8 3C014248 */  lui       $at, 0x4248
/* A9D62C 802409FC 44811000 */  mtc1      $at, $f2
/* A9D630 80240A00 00000000 */  nop       
/* A9D634 80240A04 4602003C */  c.lt.s    $f0, $f2
/* A9D638 80240A08 00000000 */  nop       
/* A9D63C 80240A0C 45010002 */  bc1t      .L80240A18
/* A9D640 80240A10 24020002 */   addiu    $v0, $zero, 2
/* A9D644 80240A14 0000102D */  daddu     $v0, $zero, $zero
.L80240A18:
/* A9D648 80240A18 8FBF0010 */  lw        $ra, 0x10($sp)
/* A9D64C 80240A1C 03E00008 */  jr        $ra
/* A9D650 80240A20 27BD0018 */   addiu    $sp, $sp, 0x18
