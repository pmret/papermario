.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BAC_DDD3DC
/* DDD3DC 80240BAC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DDD3E0 80240BB0 AFBF0010 */  sw        $ra, 0x10($sp)
/* DDD3E4 80240BB4 8C82000C */  lw        $v0, 0xc($a0)
/* DDD3E8 80240BB8 0C0B1EAF */  jal       get_variable
/* DDD3EC 80240BBC 8C450000 */   lw       $a1, ($v0)
/* DDD3F0 80240BC0 0C03AC5A */  jal       func_800EB168
/* DDD3F4 80240BC4 0040202D */   daddu    $a0, $v0, $zero
/* DDD3F8 80240BC8 8FBF0010 */  lw        $ra, 0x10($sp)
/* DDD3FC 80240BCC 24020002 */  addiu     $v0, $zero, 2
/* DDD400 80240BD0 03E00008 */  jr        $ra
/* DDD404 80240BD4 27BD0018 */   addiu    $sp, $sp, 0x18
