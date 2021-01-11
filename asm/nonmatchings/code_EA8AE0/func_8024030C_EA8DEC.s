.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_EA8DEC
/* EA8DEC 8024030C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA8DF0 80240310 AFBF001C */  sw        $ra, 0x1c($sp)
/* EA8DF4 80240314 AFB00018 */  sw        $s0, 0x18($sp)
/* EA8DF8 80240318 8C900084 */  lw        $s0, 0x84($a0)
/* EA8DFC 8024031C C6000008 */  lwc1      $f0, 8($s0)
/* EA8E00 80240320 240400A2 */  addiu     $a0, $zero, 0xa2
/* EA8E04 80240324 E7A00010 */  swc1      $f0, 0x10($sp)
/* EA8E08 80240328 8E060000 */  lw        $a2, ($s0)
/* EA8E0C 8024032C 8E070004 */  lw        $a3, 4($s0)
/* EA8E10 80240330 0C055C13 */  jal       func_8015704C
/* EA8E14 80240334 0000282D */   daddu    $a1, $zero, $zero
/* EA8E18 80240338 86020044 */  lh        $v0, 0x44($s0)
/* EA8E1C 8024033C 8FBF001C */  lw        $ra, 0x1c($sp)
/* EA8E20 80240340 8FB00018 */  lw        $s0, 0x18($sp)
/* EA8E24 80240344 28420002 */  slti      $v0, $v0, 2
/* EA8E28 80240348 38420001 */  xori      $v0, $v0, 1
/* EA8E2C 8024034C 00021040 */  sll       $v0, $v0, 1
/* EA8E30 80240350 03E00008 */  jr        $ra
/* EA8E34 80240354 27BD0020 */   addiu    $sp, $sp, 0x20
