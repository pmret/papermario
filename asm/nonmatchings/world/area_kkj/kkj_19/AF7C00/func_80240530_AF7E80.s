.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240530_AF7E80
/* AF7E80 80240530 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF7E84 80240534 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF7E88 80240538 8C82000C */  lw        $v0, 0xc($a0)
/* AF7E8C 8024053C 0C0B1EAF */  jal       get_variable
/* AF7E90 80240540 8C450000 */   lw       $a1, ($v0)
/* AF7E94 80240544 3C018024 */  lui       $at, %hi(func_80241B14_9A9F04)
/* AF7E98 80240548 AC221B14 */  sw        $v0, %lo(func_80241B14_9A9F04)($at)
/* AF7E9C 8024054C 24020002 */  addiu     $v0, $zero, 2
/* AF7EA0 80240550 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF7EA4 80240554 24030001 */  addiu     $v1, $zero, 1
/* AF7EA8 80240558 3C018024 */  lui       $at, %hi(func_80241B10_88A6E0)
/* AF7EAC 8024055C AC231B10 */  sw        $v1, %lo(func_80241B10_88A6E0)($at)
/* AF7EB0 80240560 03E00008 */  jr        $ra
/* AF7EB4 80240564 27BD0018 */   addiu    $sp, $sp, 0x18
