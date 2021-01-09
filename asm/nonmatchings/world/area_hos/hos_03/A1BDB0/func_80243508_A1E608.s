.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243508_A1E608
/* A1E608 80243508 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1E60C 8024350C 3C058024 */  lui       $a1, %hi(func_8024349C_A1BD44)
/* A1E610 80243510 24A5349C */  addiu     $a1, $a1, %lo(func_8024349C_A1BD44)
/* A1E614 80243514 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1E618 80243518 0C048C8F */  jal       bind_dynamic_entity_7
/* A1E61C 8024351C 0000202D */   daddu    $a0, $zero, $zero
/* A1E620 80243520 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1E624 80243524 3C018025 */  lui       $at, %hi(D_8024BDD0)
/* A1E628 80243528 AC22BDD0 */  sw        $v0, %lo(D_8024BDD0)($at)
/* A1E62C 8024352C 24020002 */  addiu     $v0, $zero, 2
/* A1E630 80243530 03E00008 */  jr        $ra
/* A1E634 80243534 27BD0018 */   addiu    $sp, $sp, 0x18
/* A1E638 80243538 00000000 */  nop       
/* A1E63C 8024353C 00000000 */  nop       
