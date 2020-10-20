.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240548_9EE138
/* 9EE138 80240548 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9EE13C 8024054C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9EE140 80240550 8C82000C */  lw        $v0, 0xc($a0)
/* 9EE144 80240554 0C0B1EAF */  jal       get_variable
/* 9EE148 80240558 8C450000 */   lw       $a1, ($v0)
/* 9EE14C 8024055C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9EE150 80240560 3C018024 */  lui       $at, 0x8024
/* 9EE154 80240564 AC22143C */  sw        $v0, 0x143c($at)
/* 9EE158 80240568 24020002 */  addiu     $v0, $zero, 2
/* 9EE15C 8024056C 03E00008 */  jr        $ra
/* 9EE160 80240570 27BD0018 */   addiu    $sp, $sp, 0x18
