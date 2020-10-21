.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241568_CD8848
/* CD8848 80241568 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD884C 8024156C AFB00010 */  sw        $s0, 0x10($sp)
/* CD8850 80241570 24100032 */  addiu     $s0, $zero, 0x32
/* CD8854 80241574 AFBF0014 */  sw        $ra, 0x14($sp)
.L80241578:
/* CD8858 80241578 0C00FB3A */  jal       get_enemy
/* CD885C 8024157C 0200202D */   daddu    $a0, $s0, $zero
/* CD8860 80241580 8C420094 */  lw        $v0, 0x94($v0)
/* CD8864 80241584 54400003 */  bnel      $v0, $zero, .L80241594
/* CD8868 80241588 26100001 */   addiu    $s0, $s0, 1
/* CD886C 8024158C 08090568 */  j         .L802415A0
/* CD8870 80241590 0200102D */   daddu    $v0, $s0, $zero
.L80241594:
/* CD8874 80241594 2A020036 */  slti      $v0, $s0, 0x36
/* CD8878 80241598 1440FFF7 */  bnez      $v0, .L80241578
/* CD887C 8024159C 2402FFFF */   addiu    $v0, $zero, -1
.L802415A0:
/* CD8880 802415A0 8FBF0014 */  lw        $ra, 0x14($sp)
/* CD8884 802415A4 8FB00010 */  lw        $s0, 0x10($sp)
/* CD8888 802415A8 03E00008 */  jr        $ra
/* CD888C 802415AC 27BD0018 */   addiu    $sp, $sp, 0x18
