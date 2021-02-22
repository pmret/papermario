.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B90_D072C0
/* D072C0 80241B90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D072C4 80241B94 3C058024 */  lui       $a1, %hi(func_80241B24_D07254)
/* D072C8 80241B98 24A51B24 */  addiu     $a1, $a1, %lo(func_80241B24_D07254)
/* D072CC 80241B9C AFBF0010 */  sw        $ra, 0x10($sp)
/* D072D0 80241BA0 0C048C8F */  jal       bind_dynamic_entity_7
/* D072D4 80241BA4 0000202D */   daddu    $a0, $zero, $zero
/* D072D8 80241BA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* D072DC 80241BAC 3C018025 */  lui       $at, %hi(D_8024B990)
/* D072E0 80241BB0 AC22B990 */  sw        $v0, %lo(D_8024B990)($at)
/* D072E4 80241BB4 24020002 */  addiu     $v0, $zero, 2
/* D072E8 80241BB8 03E00008 */  jr        $ra
/* D072EC 80241BBC 27BD0018 */   addiu    $sp, $sp, 0x18
