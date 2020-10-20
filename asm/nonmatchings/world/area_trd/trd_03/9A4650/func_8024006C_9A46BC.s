.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024006C_9A46BC
/* 9A46BC 8024006C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9A46C0 80240070 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9A46C4 80240074 8C82000C */  lw        $v0, 0xc($a0)
/* 9A46C8 80240078 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 9A46CC 8024007C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 9A46D0 80240080 8C450000 */  lw        $a1, ($v0)
/* 9A46D4 80240084 0C0B2026 */  jal       set_variable
/* 9A46D8 80240088 94660134 */   lhu      $a2, 0x134($v1)
/* 9A46DC 8024008C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9A46E0 80240090 24020002 */  addiu     $v0, $zero, 2
/* 9A46E4 80240094 03E00008 */  jr        $ra
/* 9A46E8 80240098 27BD0018 */   addiu    $sp, $sp, 0x18
/* 9A46EC 8024009C 00000000 */  nop       
