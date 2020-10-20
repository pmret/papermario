.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AA4_CD38D4
/* CD38D4 80241AA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD38D8 80241AA8 AFB00010 */  sw        $s0, 0x10($sp)
/* CD38DC 80241AAC 0080802D */  daddu     $s0, $a0, $zero
/* CD38E0 80241AB0 AFBF0014 */  sw        $ra, 0x14($sp)
/* CD38E4 80241AB4 8E020148 */  lw        $v0, 0x148($s0)
/* CD38E8 80241AB8 0C00EABB */  jal       get_npc_unsafe
/* CD38EC 80241ABC 84440008 */   lh       $a0, 8($v0)
/* CD38F0 80241AC0 9443008E */  lhu       $v1, 0x8e($v0)
/* CD38F4 80241AC4 C440003C */  lwc1      $f0, 0x3c($v0)
/* CD38F8 80241AC8 24640001 */  addiu     $a0, $v1, 1
/* CD38FC 80241ACC 00031C00 */  sll       $v1, $v1, 0x10
/* CD3900 80241AD0 00031B83 */  sra       $v1, $v1, 0xe
/* CD3904 80241AD4 A444008E */  sh        $a0, 0x8e($v0)
/* CD3908 80241AD8 3C018024 */  lui       $at, 0x8024
/* CD390C 80241ADC 00230821 */  addu      $at, $at, $v1
/* CD3910 80241AE0 C4224010 */  lwc1      $f2, 0x4010($at)
/* CD3914 80241AE4 8443008E */  lh        $v1, 0x8e($v0)
/* CD3918 80241AE8 46020000 */  add.s     $f0, $f0, $f2
/* CD391C 80241AEC 28630005 */  slti      $v1, $v1, 5
/* CD3920 80241AF0 14600003 */  bnez      $v1, .L80241B00
/* CD3924 80241AF4 E440003C */   swc1     $f0, 0x3c($v0)
/* CD3928 80241AF8 2402000C */  addiu     $v0, $zero, 0xc
/* CD392C 80241AFC AE020070 */  sw        $v0, 0x70($s0)
.L80241B00:
/* CD3930 80241B00 8FBF0014 */  lw        $ra, 0x14($sp)
/* CD3934 80241B04 8FB00010 */  lw        $s0, 0x10($sp)
/* CD3938 80241B08 03E00008 */  jr        $ra
/* CD393C 80241B0C 27BD0018 */   addiu    $sp, $sp, 0x18
