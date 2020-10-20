.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242218
/* C48DF8 80242218 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C48DFC 8024221C AFB00010 */  sw        $s0, 0x10($sp)
/* C48E00 80242220 0080802D */  daddu     $s0, $a0, $zero
/* C48E04 80242224 AFBF0014 */  sw        $ra, 0x14($sp)
/* C48E08 80242228 8E020148 */  lw        $v0, 0x148($s0)
/* C48E0C 8024222C 0C00EABB */  jal       get_npc_unsafe
/* C48E10 80242230 84440008 */   lh       $a0, 8($v0)
/* C48E14 80242234 0040202D */  daddu     $a0, $v0, $zero
/* C48E18 80242238 8482008E */  lh        $v0, 0x8e($a0)
/* C48E1C 8024223C 9483008E */  lhu       $v1, 0x8e($a0)
/* C48E20 80242240 18400005 */  blez      $v0, .L80242258
/* C48E24 80242244 2462FFFF */   addiu    $v0, $v1, -1
/* C48E28 80242248 A482008E */  sh        $v0, 0x8e($a0)
/* C48E2C 8024224C 00021400 */  sll       $v0, $v0, 0x10
/* C48E30 80242250 1C400006 */  bgtz      $v0, .L8024226C
/* C48E34 80242254 00000000 */   nop      
.L80242258:
/* C48E38 80242258 8482008C */  lh        $v0, 0x8c($a0)
/* C48E3C 8024225C 14400003 */  bnez      $v0, .L8024226C
/* C48E40 80242260 2402000E */   addiu    $v0, $zero, 0xe
/* C48E44 80242264 A480008E */  sh        $zero, 0x8e($a0)
/* C48E48 80242268 AE020070 */  sw        $v0, 0x70($s0)
.L8024226C:
/* C48E4C 8024226C 8FBF0014 */  lw        $ra, 0x14($sp)
/* C48E50 80242270 8FB00010 */  lw        $s0, 0x10($sp)
/* C48E54 80242274 03E00008 */  jr        $ra
/* C48E58 80242278 27BD0018 */   addiu    $sp, $sp, 0x18
