.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241408
/* DDDC38 80241408 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DDDC3C 8024140C AFBF0018 */  sw        $ra, 0x18($sp)
/* DDDC40 80241410 0C00EAD2 */  jal       get_npc_safe
/* DDDC44 80241414 2404FFFC */   addiu    $a0, $zero, -4
/* DDDC48 80241418 3C0141F0 */  lui       $at, 0x41f0
/* DDDC4C 8024141C 44810000 */  mtc1      $at, $f0
/* DDDC50 80241420 C442003C */  lwc1      $f2, 0x3c($v0)
/* DDDC54 80241424 46001080 */  add.s     $f2, $f2, $f0
/* DDDC58 80241428 E7A00010 */  swc1      $f0, 0x10($sp)
/* DDDC5C 8024142C 8C450038 */  lw        $a1, 0x38($v0)
/* DDDC60 80241430 8C470040 */  lw        $a3, 0x40($v0)
/* DDDC64 80241434 44061000 */  mfc1      $a2, $f2
/* DDDC68 80241438 0C01BFBC */  jal       func_8006FEF0
/* DDDC6C 8024143C 24040002 */   addiu    $a0, $zero, 2
/* DDDC70 80241440 8FBF0018 */  lw        $ra, 0x18($sp)
/* DDDC74 80241444 24020002 */  addiu     $v0, $zero, 2
/* DDDC78 80241448 03E00008 */  jr        $ra
/* DDDC7C 8024144C 27BD0020 */   addiu    $sp, $sp, 0x20
