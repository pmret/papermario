.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004423C
/* 1F63C 8004423C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1F640 80044240 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1F644 80044244 8C82000C */  lw        $v0, 0xc($a0)
/* 1F648 80044248 3C06800B */  lui       $a2, %hi(D_800B0EF9)
/* 1F64C 8004424C 80C60EF9 */  lb        $a2, %lo(D_800B0EF9)($a2)
/* 1F650 80044250 0C0B2026 */  jal       func_802C8098
/* 1F654 80044254 8C450000 */   lw       $a1, ($v0)
/* 1F658 80044258 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1F65C 8004425C 24020002 */  addiu     $v0, $zero, 2
/* 1F660 80044260 03E00008 */  jr        $ra
/* 1F664 80044264 27BD0018 */   addiu    $sp, $sp, 0x18
