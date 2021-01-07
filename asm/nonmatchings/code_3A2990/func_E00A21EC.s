.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00A21EC
/* 3A2B7C E00A21EC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 3A2B80 E00A21F0 3C02E00A */  lui       $v0, %hi(D_E00A223C)
/* 3A2B84 E00A21F4 2442223C */  addiu     $v0, $v0, %lo(D_E00A223C)
/* 3A2B88 E00A21F8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 3A2B8C E00A21FC 24020064 */  addiu     $v0, $zero, 0x64
/* 3A2B90 E00A2200 AFA20014 */  sw        $v0, 0x14($sp)
/* 3A2B94 E00A2204 2402002D */  addiu     $v0, $zero, 0x2d
/* 3A2B98 E00A2208 AFA40018 */  sw        $a0, 0x18($sp)
/* 3A2B9C E00A220C 27A40010 */  addiu     $a0, $sp, 0x10
/* 3A2BA0 E00A2210 AFBF0020 */  sw        $ra, 0x20($sp)
/* 3A2BA4 E00A2214 0C080120 */  jal       func_E0200480
/* 3A2BA8 E00A2218 AFA20010 */   sw       $v0, 0x10($sp)
/* 3A2BAC E00A221C 8C430000 */  lw        $v1, ($v0)
/* 3A2BB0 E00A2220 34630002 */  ori       $v1, $v1, 2
/* 3A2BB4 E00A2224 AC430000 */  sw        $v1, ($v0)
/* 3A2BB8 E00A2228 8FBF0020 */  lw        $ra, 0x20($sp)
/* 3A2BBC E00A222C 03E00008 */  jr        $ra
/* 3A2BC0 E00A2230 27BD0028 */   addiu    $sp, $sp, 0x28
