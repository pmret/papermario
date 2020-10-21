.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412D4_C5BA14
/* C5BA14 802412D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5BA18 802412D8 AFB00010 */  sw        $s0, 0x10($sp)
/* C5BA1C 802412DC 0080802D */  daddu     $s0, $a0, $zero
/* C5BA20 802412E0 AFBF0014 */  sw        $ra, 0x14($sp)
/* C5BA24 802412E4 8E020148 */  lw        $v0, 0x148($s0)
/* C5BA28 802412E8 0C00EABB */  jal       get_npc_unsafe
/* C5BA2C 802412EC 84440008 */   lh       $a0, 8($v0)
/* C5BA30 802412F0 0040202D */  daddu     $a0, $v0, $zero
/* C5BA34 802412F4 8482008E */  lh        $v0, 0x8e($a0)
/* C5BA38 802412F8 9483008E */  lhu       $v1, 0x8e($a0)
/* C5BA3C 802412FC 18400005 */  blez      $v0, .L80241314
/* C5BA40 80241300 2462FFFF */   addiu    $v0, $v1, -1
/* C5BA44 80241304 A482008E */  sh        $v0, 0x8e($a0)
/* C5BA48 80241308 00021400 */  sll       $v0, $v0, 0x10
/* C5BA4C 8024130C 1C400006 */  bgtz      $v0, .L80241328
/* C5BA50 80241310 00000000 */   nop      
.L80241314:
/* C5BA54 80241314 8482008C */  lh        $v0, 0x8c($a0)
/* C5BA58 80241318 14400003 */  bnez      $v0, .L80241328
/* C5BA5C 8024131C 2402000E */   addiu    $v0, $zero, 0xe
/* C5BA60 80241320 A480008E */  sh        $zero, 0x8e($a0)
/* C5BA64 80241324 AE020070 */  sw        $v0, 0x70($s0)
.L80241328:
/* C5BA68 80241328 8FBF0014 */  lw        $ra, 0x14($sp)
/* C5BA6C 8024132C 8FB00010 */  lw        $s0, 0x10($sp)
/* C5BA70 80241330 03E00008 */  jr        $ra
/* C5BA74 80241334 27BD0018 */   addiu    $sp, $sp, 0x18
