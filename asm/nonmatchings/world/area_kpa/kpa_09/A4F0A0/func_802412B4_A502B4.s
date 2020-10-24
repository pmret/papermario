.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412B4_A502B4
/* A502B4 802412B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A502B8 802412B8 3C05FE36 */  lui       $a1, 0xfe36
/* A502BC 802412BC AFBF0010 */  sw        $ra, 0x10($sp)
/* A502C0 802412C0 8C820148 */  lw        $v0, 0x148($a0)
/* A502C4 802412C4 3C06800B */  lui       $a2, 0x800b
/* A502C8 802412C8 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* A502CC 802412CC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A502D0 802412D0 00C23026 */  xor       $a2, $a2, $v0
/* A502D4 802412D4 0C0B2026 */  jal       set_variable
/* A502D8 802412D8 2CC60001 */   sltiu    $a2, $a2, 1
/* A502DC 802412DC 8FBF0010 */  lw        $ra, 0x10($sp)
/* A502E0 802412E0 24020002 */  addiu     $v0, $zero, 2
/* A502E4 802412E4 03E00008 */  jr        $ra
/* A502E8 802412E8 27BD0018 */   addiu    $sp, $sp, 0x18
/* A502EC 802412EC 00000000 */  nop       
