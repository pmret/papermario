.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240540
/* 892F60 80240540 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 892F64 80240544 AFBF0010 */  sw        $ra, 0x10($sp)
/* 892F68 80240548 8C82000C */  lw        $v0, 0xc($a0)
/* 892F6C 8024054C 0C0B1EAF */  jal       get_variable
/* 892F70 80240550 8C450000 */   lw       $a1, ($v0)
/* 892F74 80240554 0040202D */  daddu     $a0, $v0, $zero
/* 892F78 80240558 8C830000 */  lw        $v1, ($a0)
/* 892F7C 8024055C 34630010 */  ori       $v1, $v1, 0x10
/* 892F80 80240560 AC830000 */  sw        $v1, ($a0)
/* 892F84 80240564 8FBF0010 */  lw        $ra, 0x10($sp)
/* 892F88 80240568 24020002 */  addiu     $v0, $zero, 2
/* 892F8C 8024056C 03E00008 */  jr        $ra
/* 892F90 80240570 27BD0018 */   addiu    $sp, $sp, 0x18
