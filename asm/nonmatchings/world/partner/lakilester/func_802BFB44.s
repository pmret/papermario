.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BFB44
/* 323694 802BFB44 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 323698 802BFB48 3C058011 */  lui       $a1, %hi(gPlayerStatus)
/* 32369C 802BFB4C 24A5EFC8 */  addiu     $a1, $a1, %lo(gPlayerStatus)
/* 3236A0 802BFB50 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3236A4 802BFB54 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3236A8 802BFB58 44066000 */  mfc1      $a2, $f12
/* 3236AC 802BFB5C 24A40028 */  addiu     $a0, $a1, 0x28
/* 3236B0 802BFB60 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3236B4 802BFB64 00031080 */  sll       $v0, $v1, 2
/* 3236B8 802BFB68 00431021 */  addu      $v0, $v0, $v1
/* 3236BC 802BFB6C 00021080 */  sll       $v0, $v0, 2
/* 3236C0 802BFB70 00431023 */  subu      $v0, $v0, $v1
/* 3236C4 802BFB74 000218C0 */  sll       $v1, $v0, 3
/* 3236C8 802BFB78 00431021 */  addu      $v0, $v0, $v1
/* 3236CC 802BFB7C 000210C0 */  sll       $v0, $v0, 3
/* 3236D0 802BFB80 3C07800B */  lui       $a3, %hi(D_800B1DEC)
/* 3236D4 802BFB84 00E23821 */  addu      $a3, $a3, $v0
/* 3236D8 802BFB88 8CE71DEC */  lw        $a3, %lo(D_800B1DEC)($a3)
/* 3236DC 802BFB8C 0C00A7E7 */  jal       add_vec2D_polar
/* 3236E0 802BFB90 24A50030 */   addiu    $a1, $a1, 0x30
/* 3236E4 802BFB94 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3236E8 802BFB98 03E00008 */  jr        $ra
/* 3236EC 802BFB9C 27BD0018 */   addiu    $sp, $sp, 0x18
