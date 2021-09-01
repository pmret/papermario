.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E9C_843A6C
/* 843A6C 80240E9C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 843A70 80240EA0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 843A74 80240EA4 8C82000C */  lw        $v0, 0xc($a0)
/* 843A78 80240EA8 0C0B1EAF */  jal       evt_get_variable
/* 843A7C 80240EAC 8C450000 */   lw       $a1, ($v0)
/* 843A80 80240EB0 3C038025 */  lui       $v1, %hi(D_8024F5C0)
/* 843A84 80240EB4 8C63F5C0 */  lw        $v1, %lo(D_8024F5C0)($v1)
/* 843A88 80240EB8 8C63000C */  lw        $v1, 0xc($v1)
/* 843A8C 80240EBC AC620034 */  sw        $v0, 0x34($v1)
/* 843A90 80240EC0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 843A94 80240EC4 24020002 */  addiu     $v0, $zero, 2
/* 843A98 80240EC8 03E00008 */  jr        $ra
/* 843A9C 80240ECC 27BD0018 */   addiu    $sp, $sp, 0x18
