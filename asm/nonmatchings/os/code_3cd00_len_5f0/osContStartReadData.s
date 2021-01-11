.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osContStartReadData
/* 3CDA0 800619A0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3CDA4 800619A4 AFB00010 */  sw        $s0, 0x10($sp)
/* 3CDA8 800619A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3CDAC 800619AC 0C019771 */  jal       osSiGetAccess
/* 3CDB0 800619B0 00808021 */   addu     $s0, $a0, $zero
/* 3CDB4 800619B4 3C03800A */  lui       $v1, %hi(D_8009A61C)
/* 3CDB8 800619B8 9063A61C */  lbu       $v1, %lo(D_8009A61C)($v1)
/* 3CDBC 800619BC 24020001 */  addiu     $v0, $zero, 1
/* 3CDC0 800619C0 1062000B */  beq       $v1, $v0, .L800619F0
/* 3CDC4 800619C4 00000000 */   nop
/* 3CDC8 800619C8 0C0186B1 */  jal       osPackReadData
/* 3CDCC 800619CC 00000000 */   nop
/* 3CDD0 800619D0 3C05800B */  lui       $a1, %hi(D_800B0ED0)
/* 3CDD4 800619D4 24A50ED0 */  addiu     $a1, $a1, %lo(D_800B0ED0)
/* 3CDD8 800619D8 0C019730 */  jal       osSiRawStartDma
/* 3CDDC 800619DC 24040001 */   addiu    $a0, $zero, 1
/* 3CDE0 800619E0 02002021 */  addu      $a0, $s0, $zero
/* 3CDE4 800619E4 00002821 */  addu      $a1, $zero, $zero
/* 3CDE8 800619E8 0C0195BC */  jal       osRecvMesg
/* 3CDEC 800619EC 24060001 */   addiu    $a2, $zero, 1
.L800619F0:
/* 3CDF0 800619F0 3C05800B */  lui       $a1, %hi(D_800B0ED0)
/* 3CDF4 800619F4 24A50ED0 */  addiu     $a1, $a1, %lo(D_800B0ED0)
/* 3CDF8 800619F8 0C019730 */  jal       osSiRawStartDma
/* 3CDFC 800619FC 00002021 */   addu     $a0, $zero, $zero
/* 3CE00 80061A00 24030001 */  addiu     $v1, $zero, 1
/* 3CE04 80061A04 3C01800A */  lui       $at, %hi(D_8009A61C)
/* 3CE08 80061A08 A023A61C */  sb        $v1, %lo(D_8009A61C)($at)
/* 3CE0C 80061A0C 0C01978C */  jal       osSiRelAccess
/* 3CE10 80061A10 00408021 */   addu     $s0, $v0, $zero
/* 3CE14 80061A14 02001021 */  addu      $v0, $s0, $zero
/* 3CE18 80061A18 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3CE1C 80061A1C 8FB00010 */  lw        $s0, 0x10($sp)
/* 3CE20 80061A20 03E00008 */  jr        $ra
/* 3CE24 80061A24 27BD0018 */   addiu    $sp, $sp, 0x18
