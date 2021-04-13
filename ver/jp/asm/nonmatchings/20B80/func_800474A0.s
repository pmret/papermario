.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800474A0
/* 228A0 800474A0 00041040 */  sll       $v0, $a0, 1
/* 228A4 800474A4 00441021 */  addu      $v0, $v0, $a0
/* 228A8 800474A8 00021080 */  sll       $v0, $v0, 2
/* 228AC 800474AC 00441023 */  subu      $v0, $v0, $a0
/* 228B0 800474B0 3C03800A */  lui       $v1, %hi(D_8009ED54)
/* 228B4 800474B4 8C63ED54 */  lw        $v1, %lo(D_8009ED54)($v1)
/* 228B8 800474B8 00021100 */  sll       $v0, $v0, 4
/* 228BC 800474BC 00621821 */  addu      $v1, $v1, $v0
/* 228C0 800474C0 AC650030 */  sw        $a1, 0x30($v1)
/* 228C4 800474C4 03E00008 */  jr        $ra
/* 228C8 800474C8 AC660034 */   sw       $a2, 0x34($v1)
