.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005F2C0
/* 3A6C0 8005F2C0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3A6C4 8005F2C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3A6C8 8005F2C8 0C01808C */  jal       func_80060230
/* 3A6CC 8005F2CC AFB00010 */   sw       $s0, 0x10($sp)
/* 3A6D0 8005F2D0 0C018138 */  jal       func_800604E0
/* 3A6D4 8005F2D4 0040802D */   daddu    $s0, $v0, $zero
/* 3A6D8 8005F2D8 0C017CD8 */  jal       func_8005F360
/* 3A6DC 8005F2DC 00000000 */   nop
/* 3A6E0 8005F2E0 0C017E4F */  jal       func_8005F93C
/* 3A6E4 8005F2E4 00000000 */   nop
/* 3A6E8 8005F2E8 320200FF */  andi      $v0, $s0, 0xff
/* 3A6EC 8005F2EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3A6F0 8005F2F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A6F4 8005F2F4 03E00008 */  jr        $ra
/* 3A6F8 8005F2F8 27BD0018 */   addiu    $sp, $sp, 0x18
/* 3A6FC 8005F2FC 00000000 */  nop
