.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238E48_6F1F28
/* 6F1F28 80238E48 3C038024 */  lui       $v1, %hi(D_8023CDA0)
/* 6F1F2C 80238E4C 8C63CDA0 */  lw        $v1, %lo(D_8023CDA0)($v1)
/* 6F1F30 80238E50 3C014310 */  lui       $at, 0x4310
/* 6F1F34 80238E54 44810000 */  mtc1      $at, $f0
/* 6F1F38 80238E58 8C62000C */  lw        $v0, 0xc($v1)
/* 6F1F3C 80238E5C E4400008 */  swc1      $f0, 8($v0)
/* 6F1F40 80238E60 8C620000 */  lw        $v0, ($v1)
/* 6F1F44 80238E64 34420010 */  ori       $v0, $v0, 0x10
/* 6F1F48 80238E68 AC620000 */  sw        $v0, ($v1)
/* 6F1F4C 80238E6C 03E00008 */  jr        $ra
/* 6F1F50 80238E70 24020002 */   addiu    $v0, $zero, 2
