.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004580C
/* 20C0C 8004580C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20C10 80045810 AFBF0010 */  sw        $ra, 0x10($sp)
/* 20C14 80045814 8C82000C */  lw        $v0, 0xc($a0)
/* 20C18 80045818 3C06800B */  lui       $a2, 0x800b
/* 20C1C 8004581C 80C60F16 */  lb        $a2, 0xf16($a2)
/* 20C20 80045820 0C0B2026 */  jal       set_variable
/* 20C24 80045824 8C450000 */   lw       $a1, ($v0)
/* 20C28 80045828 8FBF0010 */  lw        $ra, 0x10($sp)
/* 20C2C 8004582C 24020002 */  addiu     $v0, $zero, 2
/* 20C30 80045830 03E00008 */  jr        $ra
/* 20C34 80045834 27BD0018 */   addiu    $sp, $sp, 0x18
