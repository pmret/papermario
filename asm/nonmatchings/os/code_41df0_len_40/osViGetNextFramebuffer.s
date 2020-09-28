.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osViGetNextFramebuffer
/* 41DF0 800669F0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41DF4 800669F4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41DF8 800669F8 0C01ACD8 */  jal       __osDisableInt
/* 41DFC 800669FC AFB00010 */   sw       $s0, 0x10($sp)
/* 41E00 80066A00 3C038009 */  lui       $v1, %hi(D_800959D4)
/* 41E04 80066A04 8C6359D4 */  lw        $v1, %lo(D_800959D4)($v1)
/* 41E08 80066A08 8C700004 */  lw        $s0, 4($v1)
/* 41E0C 80066A0C 0C01ACF4 */  jal       __osRestoreInt
/* 41E10 80066A10 00402021 */   addu     $a0, $v0, $zero
/* 41E14 80066A14 02001021 */  addu      $v0, $s0, $zero
/* 41E18 80066A18 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41E1C 80066A1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 41E20 80066A20 03E00008 */  jr        $ra
/* 41E24 80066A24 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41E28 80066A28 00000000 */  nop       
/* 41E2C 80066A2C 00000000 */  nop       
