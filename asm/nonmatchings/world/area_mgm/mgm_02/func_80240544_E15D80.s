.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240544_E162C4
/* E162C4 80240544 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E162C8 80240548 3C02800A */  lui       $v0, %hi(D_8009A650)
/* E162CC 8024054C 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* E162D0 80240550 AFBF0010 */  sw        $ra, 0x10($sp)
/* E162D4 80240554 8C430000 */  lw        $v1, ($v0)
/* E162D8 80240558 3C040004 */  lui       $a0, 4
/* E162DC 8024055C 00641825 */  or        $v1, $v1, $a0
/* E162E0 80240560 0C03A625 */  jal       func_800E9894
/* E162E4 80240564 AC430000 */   sw       $v1, ($v0)
/* E162E8 80240568 0C03A5EE */  jal       func_800E97B8
/* E162EC 8024056C 00000000 */   nop      
/* E162F0 80240570 8FBF0010 */  lw        $ra, 0x10($sp)
/* E162F4 80240574 24020002 */  addiu     $v0, $zero, 2
/* E162F8 80240578 03E00008 */  jr        $ra
/* E162FC 8024057C 27BD0018 */   addiu    $sp, $sp, 0x18
