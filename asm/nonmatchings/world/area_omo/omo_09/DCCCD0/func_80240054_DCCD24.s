.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240054_DCCD24
/* DCCD24 80240054 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DCCD28 80240058 AFBF0010 */  sw        $ra, 0x10($sp)
/* DCCD2C 8024005C 0C090000 */  jal       func_80240000_DCCCD0
/* DCCD30 80240060 00000000 */   nop      
/* DCCD34 80240064 2C420001 */  sltiu     $v0, $v0, 1
/* DCCD38 80240068 8FBF0010 */  lw        $ra, 0x10($sp)
/* DCCD3C 8024006C 00021040 */  sll       $v0, $v0, 1
/* DCCD40 80240070 03E00008 */  jr        $ra
/* DCCD44 80240074 27BD0018 */   addiu    $sp, $sp, 0x18
