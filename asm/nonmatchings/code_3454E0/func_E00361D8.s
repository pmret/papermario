.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00361D8
/* 3456B8 E00361D8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3456BC E00361DC 3C02E003 */  lui       $v0, %hi(D_E0036224)
/* 3456C0 E00361E0 24426224 */  addiu     $v0, $v0, %lo(D_E0036224)
/* 3456C4 E00361E4 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3456C8 E00361E8 2402002D */  addiu     $v0, $zero, 0x2d
/* 3456CC E00361EC AFA40018 */  sw        $a0, 0x18($sp)
/* 3456D0 E00361F0 27A40010 */  addiu     $a0, $sp, 0x10
/* 3456D4 E00361F4 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3456D8 E00361F8 AFA00014 */  sw        $zero, 0x14($sp)
/* 3456DC E00361FC 0C080120 */  jal       func_E0200480
/* 3456E0 E0036200 AFA20010 */   sw       $v0, 0x10($sp)
/* 3456E4 E0036204 8C430000 */  lw        $v1, ($v0)
/* 3456E8 E0036208 34630002 */  ori       $v1, $v1, 2
/* 3456EC E003620C AC430000 */  sw        $v1, ($v0)
/* 3456F0 E0036210 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3456F4 E0036214 03E00008 */  jr        $ra
/* 3456F8 E0036218 27BD0028 */   addiu    $sp, $sp, 0x28
