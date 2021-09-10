.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404E8_8AC478
/* 8AC478 802404E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8AC47C 802404EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 8AC480 802404F0 0C0B1EAF */  jal       evt_get_variable
/* 8AC484 802404F4 8C850084 */   lw       $a1, 0x84($a0)
/* 8AC488 802404F8 3C013A83 */  lui       $at, 0x3a83
/* 8AC48C 802404FC 3421126F */  ori       $at, $at, 0x126f
/* 8AC490 80240500 44811000 */  mtc1      $at, $f2
/* 8AC494 80240504 44820000 */  mtc1      $v0, $f0
/* 8AC498 80240508 00000000 */  nop
/* 8AC49C 8024050C 46800020 */  cvt.s.w   $f0, $f0
/* 8AC4A0 80240510 46020002 */  mul.s     $f0, $f0, $f2
/* 8AC4A4 80240514 00000000 */  nop
/* 8AC4A8 80240518 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8AC4AC 8024051C 24020002 */  addiu     $v0, $zero, 2
/* 8AC4B0 80240520 3C01800B */  lui       $at, %hi(gCameras+0x4E0)
/* 8AC4B4 80240524 E4202260 */  swc1      $f0, %lo(gCameras+0x4E0)($at)
/* 8AC4B8 80240528 03E00008 */  jr        $ra
/* 8AC4BC 8024052C 27BD0018 */   addiu    $sp, $sp, 0x18
