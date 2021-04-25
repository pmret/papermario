.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_10_UnkFunc39
/* 886F50 80240B90 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 886F54 80240B94 AFBF0010 */  sw        $ra, 0x10($sp)
/* 886F58 80240B98 8C82000C */  lw        $v0, 0xc($a0)
/* 886F5C 80240B9C 0C0B1EAF */  jal       get_variable
/* 886F60 80240BA0 8C450000 */   lw       $a1, ($v0)
/* 886F64 80240BA4 0040202D */  daddu     $a0, $v0, $zero
/* 886F68 80240BA8 8C830000 */  lw        $v1, ($a0)
/* 886F6C 80240BAC 34630010 */  ori       $v1, $v1, 0x10
/* 886F70 80240BB0 AC830000 */  sw        $v1, ($a0)
/* 886F74 80240BB4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 886F78 80240BB8 24020002 */  addiu     $v0, $zero, 2
/* 886F7C 80240BBC 03E00008 */  jr        $ra
/* 886F80 80240BC0 27BD0018 */   addiu    $sp, $sp, 0x18
