.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240718
/* C71B98 80240718 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C71B9C 8024071C AFBF0014 */  sw        $ra, 0x14($sp)
/* C71BA0 80240720 AFB00010 */  sw        $s0, 0x10($sp)
/* C71BA4 80240724 8C82000C */  lw        $v0, 0xc($a0)
/* C71BA8 80240728 0C0B1EAF */  jal       get_variable
/* C71BAC 8024072C 8C450000 */   lw       $a1, ($v0)
/* C71BB0 80240730 0040802D */  daddu     $s0, $v0, $zero
/* C71BB4 80240734 12000006 */  beqz      $s0, .L80240750
/* C71BB8 80240738 00000000 */   nop      
/* C71BBC 8024073C 0C046ED4 */  jal       enable_world_fog
/* C71BC0 80240740 00000000 */   nop      
/* C71BC4 80240744 240403E3 */  addiu     $a0, $zero, 0x3e3
/* C71BC8 80240748 080901D7 */  j         .L8024075C
/* C71BCC 8024074C 00902023 */   subu     $a0, $a0, $s0
.L80240750:
/* C71BD0 80240750 0C046ED9 */  jal       disable_world_fog
/* C71BD4 80240754 00000000 */   nop      
/* C71BD8 80240758 240403E3 */  addiu     $a0, $zero, 0x3e3
.L8024075C:
/* C71BDC 8024075C 0C046EDD */  jal       set_world_fog_dist
/* C71BE0 80240760 240503E8 */   addiu    $a1, $zero, 0x3e8
/* C71BE4 80240764 0000202D */  daddu     $a0, $zero, $zero
/* C71BE8 80240768 0080282D */  daddu     $a1, $a0, $zero
/* C71BEC 8024076C 0080302D */  daddu     $a2, $a0, $zero
/* C71BF0 80240770 0C046EE2 */  jal       set_world_fog_color
/* C71BF4 80240774 0080382D */   daddu    $a3, $a0, $zero
/* C71BF8 80240778 8FBF0014 */  lw        $ra, 0x14($sp)
/* C71BFC 8024077C 8FB00010 */  lw        $s0, 0x10($sp)
/* C71C00 80240780 24020002 */  addiu     $v0, $zero, 2
/* C71C04 80240784 03E00008 */  jr        $ra
/* C71C08 80240788 27BD0018 */   addiu    $sp, $sp, 0x18
/* C71C0C 8024078C 00000000 */  nop       
