.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240730_AF33D0
/* AF33D0 80240730 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AF33D4 80240734 AFBF0010 */  sw        $ra, 0x10($sp)
/* AF33D8 80240738 8C82000C */  lw        $v0, 0xc($a0)
/* AF33DC 8024073C 0C0B210B */  jal       get_float_variable
/* AF33E0 80240740 8C450000 */   lw       $a1, ($v0)
/* AF33E4 80240744 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* AF33E8 80240748 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* AF33EC 8024074C 4600008D */  trunc.w.s $f2, $f0
/* AF33F0 80240750 44021000 */  mfc1      $v0, $f2
/* AF33F4 80240754 00000000 */  nop       
/* AF33F8 80240758 3C018011 */  lui       $at, %hi(gPlayerStatus+0xC4)
/* AF33FC 8024075C A022F08C */  sb        $v0, %lo(gPlayerStatus+0xC4)($at)
/* AF3400 80240760 A0620080 */  sb        $v0, 0x80($v1)
/* AF3404 80240764 8FBF0010 */  lw        $ra, 0x10($sp)
/* AF3408 80240768 24020002 */  addiu     $v0, $zero, 2
/* AF340C 8024076C 03E00008 */  jr        $ra
/* AF3410 80240770 27BD0018 */   addiu    $sp, $sp, 0x18
