.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel AssignBlockFlag
/* A876C 8011206C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A8770 80112070 24020001 */  addiu     $v0, $zero, 1
/* A8774 80112074 AFBF0014 */  sw        $ra, 0x14($sp)
/* A8778 80112078 AFB00010 */  sw        $s0, 0x10($sp)
/* A877C 8011207C 14A2000A */  bne       $a1, $v0, .L801120A8
/* A8780 80112080 8C83000C */   lw       $v1, 0xc($a0)
/* A8784 80112084 0C0B1F6A */  jal       evt_get_variable_index
/* A8788 80112088 8C650000 */   lw       $a1, ($v1)
/* A878C 8011208C 3C048015 */  lui       $a0, %hi(gLastCreatedEntityIndex)
/* A8790 80112090 8C8412EC */  lw        $a0, %lo(gLastCreatedEntityIndex)($a0)
/* A8794 80112094 0C04417A */  jal       get_entity_by_index
/* A8798 80112098 0040802D */   daddu    $s0, $v0, $zero
/* A879C 8011209C 8C430040 */  lw        $v1, 0x40($v0)
/* A87A0 801120A0 24020002 */  addiu     $v0, $zero, 2
/* A87A4 801120A4 A470000A */  sh        $s0, 0xa($v1)
.L801120A8:
/* A87A8 801120A8 8FBF0014 */  lw        $ra, 0x14($sp)
/* A87AC 801120AC 8FB00010 */  lw        $s0, 0x10($sp)
/* A87B0 801120B0 03E00008 */  jr        $ra
/* A87B4 801120B4 27BD0018 */   addiu    $sp, $sp, 0x18
