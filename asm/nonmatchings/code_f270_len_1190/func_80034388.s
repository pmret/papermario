.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80034388
/* F788 80034388 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F78C 8003438C AFBF0010 */  sw        $ra, 0x10($sp)
/* F790 80034390 0C00D0E9 */  jal       func_800343A4
/* F794 80034394 00000000 */   nop      
/* F798 80034398 8FBF0010 */  lw        $ra, 0x10($sp)
/* F79C 8003439C 03E00008 */  jr        $ra
/* F7A0 800343A0 27BD0018 */   addiu    $sp, $sp, 0x18
