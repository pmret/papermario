.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003B184
/* 16584 8003B184 24020001 */  addiu     $v0, $zero, 1
/* 16588 8003B188 3C01800A */  lui       $at, %hi(D_800A0B94)
/* 1658C 8003B18C A0220B94 */  sb        $v0, %lo(D_800A0B94)($at)
/* 16590 8003B190 03E00008 */  jr        $ra
/* 16594 8003B194 00000000 */   nop      
