.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240614_EDC5F4
/* EDC5F4 80240614 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EDC5F8 80240618 AFBF0010 */  sw        $ra, 0x10($sp)
/* EDC5FC 8024061C 8C82000C */  lw        $v0, 0xc($a0)
/* EDC600 80240620 0C0B53A3 */  jal       dead_evt_get_variable
/* EDC604 80240624 8C450000 */   lw       $a1, ($v0)
/* EDC608 80240628 3C018024 */  lui       $at, %hi(D_80241854_EDD834)
/* EDC60C 8024062C AC221854 */  sw        $v0, %lo(D_80241854_EDD834)($at)
/* EDC610 80240630 24020002 */  addiu     $v0, $zero, 2
/* EDC614 80240634 8FBF0010 */  lw        $ra, 0x10($sp)
/* EDC618 80240638 24030001 */  addiu     $v1, $zero, 1
/* EDC61C 8024063C 3C018024 */  lui       $at, %hi(D_80241850_EDD830)
/* EDC620 80240640 AC231850 */  sw        $v1, %lo(D_80241850_EDD830)($at)
/* EDC624 80240644 03E00008 */  jr        $ra
/* EDC628 80240648 27BD0018 */   addiu    $sp, $sp, 0x18
