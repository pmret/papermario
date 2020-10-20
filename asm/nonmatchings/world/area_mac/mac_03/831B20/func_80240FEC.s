.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FEC
/* 8327EC 80240FEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8327F0 80240FF0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 8327F4 80240FF4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 8327F8 80240FF8 3C05FE36 */  lui       $a1, 0xfe36
/* 8327FC 80240FFC AFBF0010 */  sw        $ra, 0x10($sp)
/* 832800 80241000 80460075 */  lb        $a2, 0x75($v0)
/* 832804 80241004 0C0B2026 */  jal       set_variable
/* 832808 80241008 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 83280C 8024100C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 832810 80241010 24020002 */  addiu     $v0, $zero, 2
/* 832814 80241014 03E00008 */  jr        $ra
/* 832818 80241018 27BD0018 */   addiu    $sp, $sp, 0x18
