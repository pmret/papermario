.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_A1B100
/* A1B100 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1B104 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1B108 80240008 8C82000C */  lw        $v0, 0xc($a0)
/* A1B10C 8024000C 3C068016 */  lui       $a2, %hi(gCollisionStatus+0x2)
/* A1B110 80240010 84C6A552 */  lh        $a2, %lo(gCollisionStatus+0x2)($a2)
/* A1B114 80240014 0C0B2026 */  jal       set_variable
/* A1B118 80240018 8C450000 */   lw       $a1, ($v0)
/* A1B11C 8024001C 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1B120 80240020 24020002 */  addiu     $v0, $zero, 2
/* A1B124 80240024 03E00008 */  jr        $ra
/* A1B128 80240028 27BD0018 */   addiu    $sp, $sp, 0x18
/* A1B12C 8024002C 00000000 */  nop       
