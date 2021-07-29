.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061650
/* 3CA50 80061650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3CA54 80061654 AFB00010 */  sw        $s0, 0x10($sp)
/* 3CA58 80061658 00808021 */  addu      $s0, $a0, $zero
/* 3CA5C 8006165C AFB10014 */  sw        $s1, 0x14($sp)
/* 3CA60 80061660 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3CA64 80061664 0C01AE0C */  jal       func_8006B830
/* 3CA68 80061668 00A08821 */   addu     $s1, $a1, $zero
/* 3CA6C 8006166C 14400018 */  bnez      $v0, .L800616D0
/* 3CA70 80061670 2402FFFF */   addiu    $v0, $zero, -1
/* 3CA74 80061674 3C028009 */  lui       $v0, %hi(D_80093D80)
/* 3CA78 80061678 90423D80 */  lbu       $v0, %lo(D_80093D80)($v0)
/* 3CA7C 8006167C 10400002 */  beqz      $v0, .L80061688
/* 3CA80 80061680 02002021 */   addu     $a0, $s0, $zero
/* 3CA84 80061684 2484E000 */  addiu     $a0, $a0, -0x2000
.L80061688:
/* 3CA88 80061688 02111021 */  addu      $v0, $s0, $s1
/* 3CA8C 8006168C 30421FFF */  andi      $v0, $v0, 0x1fff
/* 3CA90 80061690 14400004 */  bnez      $v0, .L800616A4
/* 3CA94 80061694 24020001 */   addiu    $v0, $zero, 1
/* 3CA98 80061698 3C018009 */  lui       $at, %hi(D_80093D80)
/* 3CA9C 8006169C 080185AB */  j         .L800616AC
/* 3CAA0 800616A0 A0223D80 */   sb       $v0, %lo(D_80093D80)($at)
.L800616A4:
/* 3CAA4 800616A4 3C018009 */  lui       $at, %hi(D_80093D80)
/* 3CAA8 800616A8 A0203D80 */  sb        $zero, %lo(D_80093D80)($at)
.L800616AC:
/* 3CAAC 800616AC 0C018798 */  jal       func_80061E60
/* 3CAB0 800616B0 00000000 */   nop
/* 3CAB4 800616B4 3C05A450 */  lui       $a1, 0xa450
/* 3CAB8 800616B8 34A50004 */  ori       $a1, $a1, 4
/* 3CABC 800616BC 00402021 */  addu      $a0, $v0, $zero
/* 3CAC0 800616C0 00001021 */  addu      $v0, $zero, $zero
/* 3CAC4 800616C4 3C03A450 */  lui       $v1, 0xa450
/* 3CAC8 800616C8 AC640000 */  sw        $a0, ($v1)
/* 3CACC 800616CC ACB10000 */  sw        $s1, ($a1)
.L800616D0:
/* 3CAD0 800616D0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3CAD4 800616D4 8FB10014 */  lw        $s1, 0x14($sp)
/* 3CAD8 800616D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 3CADC 800616DC 03E00008 */  jr        $ra
/* 3CAE0 800616E0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3CAE4 800616E4 00000000 */  nop
/* 3CAE8 800616E8 00000000 */  nop
/* 3CAEC 800616EC 00000000 */  nop
