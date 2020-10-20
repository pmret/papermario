.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CA0_DDD4D0
/* DDD4D0 80240CA0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DDD4D4 80240CA4 AFBF0010 */  sw        $ra, 0x10($sp)
/* DDD4D8 80240CA8 8C82000C */  lw        $v0, 0xc($a0)
/* DDD4DC 80240CAC 0C0B1EAF */  jal       get_variable
/* DDD4E0 80240CB0 8C450000 */   lw       $a1, ($v0)
/* DDD4E4 80240CB4 0040202D */  daddu     $a0, $v0, $zero
/* DDD4E8 80240CB8 8C830000 */  lw        $v1, ($a0)
/* DDD4EC 80240CBC 34630010 */  ori       $v1, $v1, 0x10
/* DDD4F0 80240CC0 AC830000 */  sw        $v1, ($a0)
/* DDD4F4 80240CC4 8FBF0010 */  lw        $ra, 0x10($sp)
/* DDD4F8 80240CC8 24020002 */  addiu     $v0, $zero, 2
/* DDD4FC 80240CCC 03E00008 */  jr        $ra
/* DDD500 80240CD0 27BD0018 */   addiu    $sp, $sp, 0x18
