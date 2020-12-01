.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_character_set
/* B9D60 80123660 2402FFFF */  addiu     $v0, $zero, -1
/* B9D64 80123664 3C018015 */  lui       $at, %hi(D_80155C98)
/* B9D68 80123668 A4225C98 */  sh        $v0, %lo(D_80155C98)($at)
/* B9D6C 8012366C 03E00008 */  jr        $ra
/* B9D70 80123670 00000000 */   nop      
