.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802421E4_87BDC4
/* 87BDC4 802421E4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 87BDC8 802421E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 87BDCC 802421EC 0080802D */  daddu     $s0, $a0, $zero
/* 87BDD0 802421F0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 87BDD4 802421F4 8E020148 */  lw        $v0, 0x148($s0)
/* 87BDD8 802421F8 0C00EABB */  jal       get_npc_unsafe
/* 87BDDC 802421FC 84440008 */   lh       $a0, 8($v0)
/* 87BDE0 80242200 0040202D */  daddu     $a0, $v0, $zero
/* 87BDE4 80242204 8482008E */  lh        $v0, 0x8e($a0)
/* 87BDE8 80242208 9483008E */  lhu       $v1, 0x8e($a0)
/* 87BDEC 8024220C 18400005 */  blez      $v0, .L80242224
/* 87BDF0 80242210 2462FFFF */   addiu    $v0, $v1, -1
/* 87BDF4 80242214 A482008E */  sh        $v0, 0x8e($a0)
/* 87BDF8 80242218 00021400 */  sll       $v0, $v0, 0x10
/* 87BDFC 8024221C 1C400006 */  bgtz      $v0, .L80242238
/* 87BE00 80242220 00000000 */   nop      
.L80242224:
/* 87BE04 80242224 8482008C */  lh        $v0, 0x8c($a0)
/* 87BE08 80242228 14400003 */  bnez      $v0, .L80242238
/* 87BE0C 8024222C 2402000E */   addiu    $v0, $zero, 0xe
/* 87BE10 80242230 A480008E */  sh        $zero, 0x8e($a0)
/* 87BE14 80242234 AE020070 */  sw        $v0, 0x70($s0)
.L80242238:
/* 87BE18 80242238 8FBF0014 */  lw        $ra, 0x14($sp)
/* 87BE1C 8024223C 8FB00010 */  lw        $s0, 0x10($sp)
/* 87BE20 80242240 03E00008 */  jr        $ra
/* 87BE24 80242244 27BD0018 */   addiu    $sp, $sp, 0x18
