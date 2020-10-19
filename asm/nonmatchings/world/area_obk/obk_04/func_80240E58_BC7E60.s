.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E58_BC8CB8
/* BC8CB8 80240E58 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BC8CBC 80240E5C AFBF0010 */  sw        $ra, 0x10($sp)
/* BC8CC0 80240E60 0C00EABB */  jal       get_npc_unsafe
/* BC8CC4 80240E64 24040001 */   addiu    $a0, $zero, 1
/* BC8CC8 80240E68 8442008E */  lh        $v0, 0x8e($v0)
/* BC8CCC 80240E6C 8FBF0010 */  lw        $ra, 0x10($sp)
/* BC8CD0 80240E70 2C420001 */  sltiu     $v0, $v0, 1
/* BC8CD4 80240E74 00021040 */  sll       $v0, $v0, 1
/* BC8CD8 80240E78 03E00008 */  jr        $ra
/* BC8CDC 80240E7C 27BD0018 */   addiu    $sp, $sp, 0x18
