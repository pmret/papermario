.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800669C0
/* 41DC0 800669C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41DC4 800669C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41DC8 800669C8 0C01ACD0 */  jal       func_8006B340
/* 41DCC 800669CC AFB00010 */   sw       $s0, 0x10($sp)
/* 41DD0 800669D0 3C038009 */  lui       $v1, %hi(D_80095964)
/* 41DD4 800669D4 8C635964 */  lw        $v1, %lo(D_80095964)($v1)
/* 41DD8 800669D8 8C700004 */  lw        $s0, 4($v1)
/* 41DDC 800669DC 0C01ACEC */  jal       func_8006B3B0
/* 41DE0 800669E0 00402021 */   addu     $a0, $v0, $zero
/* 41DE4 800669E4 02001021 */  addu      $v0, $s0, $zero
/* 41DE8 800669E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41DEC 800669EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 41DF0 800669F0 03E00008 */  jr        $ra
/* 41DF4 800669F4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41DF8 800669F8 00000000 */  nop
/* 41DFC 800669FC 00000000 */  nop
