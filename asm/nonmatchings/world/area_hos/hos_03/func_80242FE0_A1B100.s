.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FE0_A1E0E0
/* A1E0E0 80242FE0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1E0E4 80242FE4 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* A1E0E8 80242FE8 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* A1E0EC 80242FEC 3C05FE36 */  lui       $a1, 0xfe36
/* A1E0F0 80242FF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1E0F4 80242FF4 80460075 */  lb        $a2, 0x75($v0)
/* A1E0F8 80242FF8 0C0B2026 */  jal       set_variable
/* A1E0FC 80242FFC 34A53C80 */   ori      $a1, $a1, 0x3c80
/* A1E100 80243000 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1E104 80243004 24020002 */  addiu     $v0, $zero, 2
/* A1E108 80243008 03E00008 */  jr        $ra
/* A1E10C 8024300C 27BD0018 */   addiu    $sp, $sp, 0x18
