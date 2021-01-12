.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AA4_EEEBA4
/* EEEBA4 80241AA4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EEEBA8 80241AA8 AFB00010 */  sw        $s0, 0x10($sp)
/* EEEBAC 80241AAC 0080802D */  daddu     $s0, $a0, $zero
/* EEEBB0 80241AB0 AFBF0014 */  sw        $ra, 0x14($sp)
/* EEEBB4 80241AB4 8E020148 */  lw        $v0, 0x148($s0)
/* EEEBB8 80241AB8 0C00F92F */  jal       func_8003E4BC
/* EEEBBC 80241ABC 84440008 */   lh       $a0, 8($v0)
/* EEEBC0 80241AC0 9443008E */  lhu       $v1, 0x8e($v0)
/* EEEBC4 80241AC4 C440003C */  lwc1      $f0, 0x3c($v0)
/* EEEBC8 80241AC8 24640001 */  addiu     $a0, $v1, 1
/* EEEBCC 80241ACC 00031C00 */  sll       $v1, $v1, 0x10
/* EEEBD0 80241AD0 00031B83 */  sra       $v1, $v1, 0xe
/* EEEBD4 80241AD4 A444008E */  sh        $a0, 0x8e($v0)
/* EEEBD8 80241AD8 3C018024 */  lui       $at, %hi(D_80244070)
/* EEEBDC 80241ADC 00230821 */  addu      $at, $at, $v1
/* EEEBE0 80241AE0 C4224070 */  lwc1      $f2, %lo(D_80244070)($at)
/* EEEBE4 80241AE4 8443008E */  lh        $v1, 0x8e($v0)
/* EEEBE8 80241AE8 46020000 */  add.s     $f0, $f0, $f2
/* EEEBEC 80241AEC 28630005 */  slti      $v1, $v1, 5
/* EEEBF0 80241AF0 14600003 */  bnez      $v1, .L80241B00
/* EEEBF4 80241AF4 E440003C */   swc1     $f0, 0x3c($v0)
/* EEEBF8 80241AF8 2402000C */  addiu     $v0, $zero, 0xc
/* EEEBFC 80241AFC AE020070 */  sw        $v0, 0x70($s0)
.L80241B00:
/* EEEC00 80241B00 8FBF0014 */  lw        $ra, 0x14($sp)
/* EEEC04 80241B04 8FB00010 */  lw        $s0, 0x10($sp)
/* EEEC08 80241B08 03E00008 */  jr        $ra
/* EEEC0C 80241B0C 27BD0018 */   addiu    $sp, $sp, 0x18
