.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120000
/* B6700 80120000 2402F7FF */  addiu     $v0, $zero, -0x801
/* B6704 80120004 00822024 */  and       $a0, $a0, $v0
/* B6708 80120008 3C028015 */  lui       $v0, %hi(gCurrentAnimMeshListPtr)
/* B670C 8012000C 8C423A40 */  lw        $v0, %lo(gCurrentAnimMeshListPtr)($v0)
/* B6710 80120010 00042080 */  sll       $a0, $a0, 2
/* B6714 80120014 00822021 */  addu      $a0, $a0, $v0
/* B6718 80120018 8C820000 */  lw        $v0, ($a0)
/* B671C 8012001C AC4602D4 */  sw        $a2, 0x2d4($v0)
/* B6720 80120020 03E00008 */  jr        $ra
/* B6724 80120024 AC4502D8 */   sw       $a1, 0x2d8($v0)
