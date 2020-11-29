.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osAiSetNextBuffer
/* 3CA80 80061680 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3CA84 80061684 AFB00010 */  sw        $s0, 0x10($sp)
/* 3CA88 80061688 00808021 */  addu      $s0, $a0, $zero
/* 3CA8C 8006168C AFB10014 */  sw        $s1, 0x14($sp)
/* 3CA90 80061690 AFBF0018 */  sw        $ra, 0x18($sp)
/* 3CA94 80061694 0C01AE14 */  jal       osAiDeviceBusy
/* 3CA98 80061698 00A08821 */   addu     $s1, $a1, $zero
/* 3CA9C 8006169C 14400018 */  bnez      $v0, .L80061700
/* 3CAA0 800616A0 2402FFFF */   addiu    $v0, $zero, -1
/* 3CAA4 800616A4 3C028009 */  lui       $v0, %hi(D_80093DA0)
/* 3CAA8 800616A8 90423DA0 */  lbu       $v0, %lo(D_80093DA0)($v0)
/* 3CAAC 800616AC 10400002 */  beqz      $v0, .L800616B8
/* 3CAB0 800616B0 02002021 */   addu     $a0, $s0, $zero
/* 3CAB4 800616B4 2484E000 */  addiu     $a0, $a0, -0x2000
.L800616B8:
/* 3CAB8 800616B8 02111021 */  addu      $v0, $s0, $s1
/* 3CABC 800616BC 30421FFF */  andi      $v0, $v0, 0x1fff
/* 3CAC0 800616C0 14400004 */  bnez      $v0, .L800616D4
/* 3CAC4 800616C4 24020001 */   addiu    $v0, $zero, 1
/* 3CAC8 800616C8 3C018009 */  lui       $at, %hi(D_80093DA0)
/* 3CACC 800616CC 080185B7 */  j         .L800616DC
/* 3CAD0 800616D0 A0223DA0 */   sb       $v0, %lo(D_80093DA0)($at)
.L800616D4:
/* 3CAD4 800616D4 3C018009 */  lui       $at, %hi(D_80093DA0)
/* 3CAD8 800616D8 A0203DA0 */  sb        $zero, %lo(D_80093DA0)($at)
.L800616DC:
/* 3CADC 800616DC 0C0187A4 */  jal       osVirtualToPhysical
/* 3CAE0 800616E0 00000000 */   nop      
/* 3CAE4 800616E4 3C05A450 */  lui       $a1, 0xa450
/* 3CAE8 800616E8 34A50004 */  ori       $a1, $a1, 4
/* 3CAEC 800616EC 00402021 */  addu      $a0, $v0, $zero
/* 3CAF0 800616F0 00001021 */  addu      $v0, $zero, $zero
/* 3CAF4 800616F4 3C03A450 */  lui       $v1, 0xa450
/* 3CAF8 800616F8 AC640000 */  sw        $a0, ($v1)
/* 3CAFC 800616FC ACB10000 */  sw        $s1, ($a1)
.L80061700:
/* 3CB00 80061700 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3CB04 80061704 8FB10014 */  lw        $s1, 0x14($sp)
/* 3CB08 80061708 8FB00010 */  lw        $s0, 0x10($sp)
/* 3CB0C 8006170C 03E00008 */  jr        $ra
/* 3CB10 80061710 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3CB14 80061714 00000000 */  nop       
/* 3CB18 80061718 00000000 */  nop       
/* 3CB1C 8006171C 00000000 */  nop       
