.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViGetCurrentMode
/* 41E30 80066A30 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41E34 80066A34 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41E38 80066A38 0C01ACD8 */  jal       __osDisableInt
/* 41E3C 80066A3C AFB00010 */   sw       $s0, 0x10($sp)
/* 41E40 80066A40 3C038009 */  lui       $v1, %hi(D_800959D0)
/* 41E44 80066A44 8C6359D0 */  lw        $v1, %lo(D_800959D0)($v1)
/* 41E48 80066A48 8C630008 */  lw        $v1, 8($v1)
/* 41E4C 80066A4C 90700000 */  lbu       $s0, ($v1)
/* 41E50 80066A50 0C01ACF4 */  jal       __osRestoreInt
/* 41E54 80066A54 00402021 */   addu     $a0, $v0, $zero
/* 41E58 80066A58 02001021 */  addu      $v0, $s0, $zero
/* 41E5C 80066A5C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41E60 80066A60 8FB00010 */  lw        $s0, 0x10($sp)
/* 41E64 80066A64 03E00008 */  jr        $ra
/* 41E68 80066A68 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41E6C 80066A6C 00000000 */  nop
