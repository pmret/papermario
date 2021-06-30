.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViGetCurrentFramebuffer
/* 41DB0 800669B0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41DB4 800669B4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41DB8 800669B8 0C01ACD8 */  jal       osDisableInt
/* 41DBC 800669BC AFB00010 */   sw       $s0, 0x10($sp)
/* 41DC0 800669C0 3C038009 */  lui       $v1, %hi(D_800959D0)
/* 41DC4 800669C4 8C6359D0 */  lw        $v1, %lo(D_800959D0)($v1)
/* 41DC8 800669C8 8C700004 */  lw        $s0, 4($v1)
/* 41DCC 800669CC 0C01ACF4 */  jal       osRestoreInt
/* 41DD0 800669D0 00402021 */   addu     $a0, $v0, $zero
/* 41DD4 800669D4 02001021 */  addu      $v0, $s0, $zero
/* 41DD8 800669D8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41DDC 800669DC 8FB00010 */  lw        $s0, 0x10($sp)
/* 41DE0 800669E0 03E00008 */  jr        $ra
/* 41DE4 800669E4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41DE8 800669E8 00000000 */  nop
/* 41DEC 800669EC 00000000 */  nop
