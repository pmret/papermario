.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802427BC_95D9BC
/* 95D9BC 802427BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 95D9C0 802427C0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 95D9C4 802427C4 8C82000C */  lw        $v0, 0xc($a0)
/* 95D9C8 802427C8 0C0B1EAF */  jal       get_variable
/* 95D9CC 802427CC 8C450000 */   lw       $a1, ($v0)
/* 95D9D0 802427D0 0040182D */  daddu     $v1, $v0, $zero
/* 95D9D4 802427D4 10600012 */  beqz      $v1, .L80242820
/* 95D9D8 802427D8 0000202D */   daddu    $a0, $zero, $zero
/* 95D9DC 802427DC 8C620000 */  lw        $v0, ($v1)
/* 95D9E0 802427E0 5040000A */  beql      $v0, $zero, .L8024280C
/* 95D9E4 802427E4 00041080 */   sll      $v0, $a0, 2
/* 95D9E8 802427E8 3C058025 */  lui       $a1, %hi(D_8024DFF0)
/* 95D9EC 802427EC 24A5DFF0 */  addiu     $a1, $a1, %lo(D_8024DFF0)
.L802427F0:
/* 95D9F0 802427F0 24630004 */  addiu     $v1, $v1, 4
/* 95D9F4 802427F4 24840001 */  addiu     $a0, $a0, 1
/* 95D9F8 802427F8 ACA20000 */  sw        $v0, ($a1)
/* 95D9FC 802427FC 8C620000 */  lw        $v0, ($v1)
/* 95DA00 80242800 1440FFFB */  bnez      $v0, .L802427F0
/* 95DA04 80242804 24A50004 */   addiu    $a1, $a1, 4
/* 95DA08 80242808 00041080 */  sll       $v0, $a0, 2
.L8024280C:
/* 95DA0C 8024280C 3C018025 */  lui       $at, %hi(D_8024DFF0)
/* 95DA10 80242810 00220821 */  addu      $at, $at, $v0
/* 95DA14 80242814 AC20DFF0 */  sw        $zero, %lo(D_8024DFF0)($at)
/* 95DA18 80242818 08090A12 */  j         .L80242848
/* 95DA1C 8024281C 00000000 */   nop
.L80242820:
/* 95DA20 80242820 3C038025 */  lui       $v1, %hi(D_8024DFF0)
/* 95DA24 80242824 2463DFF0 */  addiu     $v1, $v1, %lo(D_8024DFF0)
/* 95DA28 80242828 0060282D */  daddu     $a1, $v1, $zero
.L8024282C:
/* 95DA2C 8024282C 24820010 */  addiu     $v0, $a0, 0x10
/* 95DA30 80242830 AC620000 */  sw        $v0, ($v1)
/* 95DA34 80242834 24630004 */  addiu     $v1, $v1, 4
/* 95DA38 80242838 24840001 */  addiu     $a0, $a0, 1
/* 95DA3C 8024283C 28820070 */  slti      $v0, $a0, 0x70
/* 95DA40 80242840 1440FFFA */  bnez      $v0, .L8024282C
/* 95DA44 80242844 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80242848:
/* 95DA48 80242848 8FBF0010 */  lw        $ra, 0x10($sp)
/* 95DA4C 8024284C 24020002 */  addiu     $v0, $zero, 2
/* 95DA50 80242850 03E00008 */  jr        $ra
/* 95DA54 80242854 27BD0018 */   addiu    $sp, $sp, 0x18
