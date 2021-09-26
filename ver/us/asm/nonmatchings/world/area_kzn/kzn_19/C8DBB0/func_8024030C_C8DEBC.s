.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_19_StarSpiritEffectFunc1
/* C8DEBC 8024030C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C8DEC0 80240310 AFBF001C */  sw        $ra, 0x1c($sp)
/* C8DEC4 80240314 AFB00018 */  sw        $s0, 0x18($sp)
/* C8DEC8 80240318 8C900084 */  lw        $s0, 0x84($a0)
/* C8DECC 8024031C C6000008 */  lwc1      $f0, 8($s0)
/* C8DED0 80240320 240400A2 */  addiu     $a0, $zero, 0xa2
/* C8DED4 80240324 E7A00010 */  swc1      $f0, 0x10($sp)
/* C8DED8 80240328 8E060000 */  lw        $a2, ($s0)
/* C8DEDC 8024032C 8E070004 */  lw        $a3, 4($s0)
/* C8DEE0 80240330 0C05267B */  jal       sfx_adjust_env_sound_pos
/* C8DEE4 80240334 0000282D */   daddu    $a1, $zero, $zero
/* C8DEE8 80240338 86020044 */  lh        $v0, 0x44($s0)
/* C8DEEC 8024033C 8FBF001C */  lw        $ra, 0x1c($sp)
/* C8DEF0 80240340 8FB00018 */  lw        $s0, 0x18($sp)
/* C8DEF4 80240344 28420002 */  slti      $v0, $v0, 2
/* C8DEF8 80240348 38420001 */  xori      $v0, $v0, 1
/* C8DEFC 8024034C 00021040 */  sll       $v0, $v0, 1
/* C8DF00 80240350 03E00008 */  jr        $ra
/* C8DF04 80240354 27BD0020 */   addiu    $sp, $sp, 0x20
