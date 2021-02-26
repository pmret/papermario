.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80066980
/* 41D80 80066980 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 41D84 80066984 AFBF0014 */  sw        $ra, 0x14($sp)
/* 41D88 80066988 0C01ACD0 */  jal       func_8006B340
/* 41D8C 8006698C AFB00010 */   sw       $s0, 0x10($sp)
/* 41D90 80066990 3C038009 */  lui       $v1, %hi(D_80095960)
/* 41D94 80066994 8C635960 */  lw        $v1, %lo(D_80095960)($v1)
/* 41D98 80066998 8C700004 */  lw        $s0, 4($v1)
/* 41D9C 8006699C 0C01ACEC */  jal       func_8006B3B0
/* 41DA0 800669A0 00402021 */   addu     $a0, $v0, $zero
/* 41DA4 800669A4 02001021 */  addu      $v0, $s0, $zero
/* 41DA8 800669A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 41DAC 800669AC 8FB00010 */  lw        $s0, 0x10($sp)
/* 41DB0 800669B0 03E00008 */  jr        $ra
/* 41DB4 800669B4 27BD0018 */   addiu    $sp, $sp, 0x18
/* 41DB8 800669B8 00000000 */  nop
/* 41DBC 800669BC 00000000 */  nop
