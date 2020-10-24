.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414E8_9FBCD8
/* 9FBCD8 802414E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9FBCDC 802414EC AFB00010 */  sw        $s0, 0x10($sp)
/* 9FBCE0 802414F0 0080802D */  daddu     $s0, $a0, $zero
/* 9FBCE4 802414F4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9FBCE8 802414F8 8E020148 */  lw        $v0, 0x148($s0)
/* 9FBCEC 802414FC 0C00EABB */  jal       get_npc_unsafe
/* 9FBCF0 80241500 84440008 */   lh       $a0, 8($v0)
/* 9FBCF4 80241504 0040202D */  daddu     $a0, $v0, $zero
/* 9FBCF8 80241508 C482003C */  lwc1      $f2, 0x3c($a0)
/* 9FBCFC 8024150C C480001C */  lwc1      $f0, 0x1c($a0)
/* 9FBD00 80241510 46001080 */  add.s     $f2, $f2, $f0
/* 9FBD04 80241514 C4840014 */  lwc1      $f4, 0x14($a0)
/* 9FBD08 80241518 46040001 */  sub.s     $f0, $f0, $f4
/* 9FBD0C 8024151C C4840064 */  lwc1      $f4, 0x64($a0)
/* 9FBD10 80241520 4602203C */  c.lt.s    $f4, $f2
/* 9FBD14 80241524 E482003C */  swc1      $f2, 0x3c($a0)
/* 9FBD18 80241528 45010009 */  bc1t      .L80241550
/* 9FBD1C 8024152C E480001C */   swc1     $f0, 0x1c($a0)
/* 9FBD20 80241530 8C820000 */  lw        $v0, ($a0)
/* 9FBD24 80241534 2403F7FF */  addiu     $v1, $zero, -0x801
/* 9FBD28 80241538 E484003C */  swc1      $f4, 0x3c($a0)
/* 9FBD2C 8024153C AC80001C */  sw        $zero, 0x1c($a0)
/* 9FBD30 80241540 00431024 */  and       $v0, $v0, $v1
/* 9FBD34 80241544 AC820000 */  sw        $v0, ($a0)
/* 9FBD38 80241548 2402000C */  addiu     $v0, $zero, 0xc
/* 9FBD3C 8024154C AE020070 */  sw        $v0, 0x70($s0)
.L80241550:
/* 9FBD40 80241550 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9FBD44 80241554 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FBD48 80241558 03E00008 */  jr        $ra
/* 9FBD4C 8024155C 27BD0018 */   addiu    $sp, $sp, 0x18
