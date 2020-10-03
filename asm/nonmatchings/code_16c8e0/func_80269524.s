.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80269524
/* 197E04 80269524 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 197E08 80269528 AFBF0010 */  sw        $ra, 0x10($sp)
/* 197E0C 8026952C 8C82000C */  lw        $v0, 0xc($a0)
/* 197E10 80269530 3C06800E */  lui       $a2, 0x800e
/* 197E14 80269534 80C6C0F6 */  lb        $a2, -0x3f0a($a2)
/* 197E18 80269538 0C0B2026 */  jal       set_variable
/* 197E1C 8026953C 8C450000 */   lw       $a1, ($v0)
/* 197E20 80269540 8FBF0010 */  lw        $ra, 0x10($sp)
/* 197E24 80269544 24020002 */  addiu     $v0, $zero, 2
/* 197E28 80269548 03E00008 */  jr        $ra
/* 197E2C 8026954C 27BD0018 */   addiu    $sp, $sp, 0x18
