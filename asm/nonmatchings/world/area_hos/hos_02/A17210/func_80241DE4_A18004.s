.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241DE4_A18004
/* A18004 80241DE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A18008 80241DE8 AFB00010 */  sw        $s0, 0x10($sp)
/* A1800C 80241DEC 0080802D */  daddu     $s0, $a0, $zero
/* A18010 80241DF0 AFBF0014 */  sw        $ra, 0x14($sp)
/* A18014 80241DF4 8E020148 */  lw        $v0, 0x148($s0)
/* A18018 80241DF8 0C00EABB */  jal       get_npc_unsafe
/* A1801C 80241DFC 84440008 */   lh       $a0, 8($v0)
/* A18020 80241E00 0040202D */  daddu     $a0, $v0, $zero
/* A18024 80241E04 8482008E */  lh        $v0, 0x8e($a0)
/* A18028 80241E08 9483008E */  lhu       $v1, 0x8e($a0)
/* A1802C 80241E0C 18400005 */  blez      $v0, .L80241E24
/* A18030 80241E10 2462FFFF */   addiu    $v0, $v1, -1
/* A18034 80241E14 A482008E */  sh        $v0, 0x8e($a0)
/* A18038 80241E18 00021400 */  sll       $v0, $v0, 0x10
/* A1803C 80241E1C 1C400006 */  bgtz      $v0, .L80241E38
/* A18040 80241E20 00000000 */   nop      
.L80241E24:
/* A18044 80241E24 8482008C */  lh        $v0, 0x8c($a0)
/* A18048 80241E28 14400003 */  bnez      $v0, .L80241E38
/* A1804C 80241E2C 2402000E */   addiu    $v0, $zero, 0xe
/* A18050 80241E30 A480008E */  sh        $zero, 0x8e($a0)
/* A18054 80241E34 AE020070 */  sw        $v0, 0x70($s0)
.L80241E38:
/* A18058 80241E38 8FBF0014 */  lw        $ra, 0x14($sp)
/* A1805C 80241E3C 8FB00010 */  lw        $s0, 0x10($sp)
/* A18060 80241E40 03E00008 */  jr        $ra
/* A18064 80241E44 27BD0018 */   addiu    $sp, $sp, 0x18
