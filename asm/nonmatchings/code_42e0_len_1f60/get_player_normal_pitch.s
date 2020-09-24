.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel get_player_normal_pitch
/* 5250 80029E50 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 5254 80029E54 AFB00010 */  sw        $s0, 0x10($sp)
/* 5258 80029E58 3C108007 */  lui       $s0, 0x8007
/* 525C 80029E5C 2610419C */  addiu     $s0, $s0, 0x419c
/* 5260 80029E60 AFBF0014 */  sw        $ra, 0x14($sp)
/* 5264 80029E64 8E020000 */  lw        $v0, ($s0)
/* 5268 80029E68 C4420128 */  lwc1      $f2, 0x128($v0)
/* 526C 80029E6C 46021082 */  mul.s     $f2, $f2, $f2
/* 5270 80029E70 00000000 */  nop       
/* 5274 80029E74 C4400130 */  lwc1      $f0, 0x130($v0)
/* 5278 80029E78 46000002 */  mul.s     $f0, $f0, $f0
/* 527C 80029E7C 00000000 */  nop       
/* 5280 80029E80 46001300 */  add.s     $f12, $f2, $f0
/* 5284 80029E84 46006104 */  sqrt.s    $f4, $f12
/* 5288 80029E88 46042032 */  c.eq.s    $f4, $f4
/* 528C 80029E8C 00000000 */  nop       
/* 5290 80029E90 45010005 */  bc1t      .L80029EA8
/* 5294 80029E94 00000000 */   nop      
/* 5298 80029E98 0C0187BC */  jal       sqrtf
/* 529C 80029E9C 00000000 */   nop      
/* 52A0 80029EA0 46000106 */  mov.s     $f4, $f0
/* 52A4 80029EA4 8E020000 */  lw        $v0, ($s0)
.L80029EA8:
/* 52A8 80029EA8 44806000 */  mtc1      $zero, $f12
/* 52AC 80029EAC C440012C */  lwc1      $f0, 0x12c($v0)
/* 52B0 80029EB0 44062000 */  mfc1      $a2, $f4
/* 52B4 80029EB4 46000007 */  neg.s     $f0, $f0
/* 52B8 80029EB8 44070000 */  mfc1      $a3, $f0
/* 52BC 80029EBC 0C00A720 */  jal       atan2
/* 52C0 80029EC0 46006386 */   mov.s    $f14, $f12
/* 52C4 80029EC4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 52C8 80029EC8 8FB00010 */  lw        $s0, 0x10($sp)
/* 52CC 80029ECC 03E00008 */  jr        $ra
/* 52D0 80029ED0 27BD0018 */   addiu    $sp, $sp, 0x18
