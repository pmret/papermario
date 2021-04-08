.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061970
/* 3CD70 80061970 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3CD74 80061974 AFB00010 */  sw        $s0, 0x10($sp)
/* 3CD78 80061978 AFBF0014 */  sw        $ra, 0x14($sp)
/* 3CD7C 8006197C 0C019765 */  jal       func_80065D94
/* 3CD80 80061980 00808021 */   addu     $s0, $a0, $zero
/* 3CD84 80061984 3C03800A */  lui       $v1, %hi(D_8009A5FC)
/* 3CD88 80061988 9063A5FC */  lbu       $v1, %lo(D_8009A5FC)($v1)
/* 3CD8C 8006198C 24020001 */  addiu     $v0, $zero, 1
/* 3CD90 80061990 1062000B */  beq       $v1, $v0, .L800619C0
/* 3CD94 80061994 00000000 */   nop
/* 3CD98 80061998 0C0186A5 */  jal       func_80061A94
/* 3CD9C 8006199C 00000000 */   nop
/* 3CDA0 800619A0 3C05800B */  lui       $a1, %hi(D_800B0EB0)
/* 3CDA4 800619A4 24A50EB0 */  addiu     $a1, $a1, %lo(D_800B0EB0)
/* 3CDA8 800619A8 0C019724 */  jal       func_80065C90
/* 3CDAC 800619AC 24040001 */   addiu    $a0, $zero, 1
/* 3CDB0 800619B0 02002021 */  addu      $a0, $s0, $zero
/* 3CDB4 800619B4 00002821 */  addu      $a1, $zero, $zero
/* 3CDB8 800619B8 0C0195B0 */  jal       func_800656C0
/* 3CDBC 800619BC 24060001 */   addiu    $a2, $zero, 1
.L800619C0:
/* 3CDC0 800619C0 3C05800B */  lui       $a1, %hi(D_800B0EB0)
/* 3CDC4 800619C4 24A50EB0 */  addiu     $a1, $a1, %lo(D_800B0EB0)
/* 3CDC8 800619C8 0C019724 */  jal       func_80065C90
/* 3CDCC 800619CC 00002021 */   addu     $a0, $zero, $zero
/* 3CDD0 800619D0 24030001 */  addiu     $v1, $zero, 1
/* 3CDD4 800619D4 3C01800A */  lui       $at, %hi(D_8009A5FC)
/* 3CDD8 800619D8 A023A5FC */  sb        $v1, %lo(D_8009A5FC)($at)
/* 3CDDC 800619DC 0C019780 */  jal       func_80065E00
/* 3CDE0 800619E0 00408021 */   addu     $s0, $v0, $zero
/* 3CDE4 800619E4 02001021 */  addu      $v0, $s0, $zero
/* 3CDE8 800619E8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 3CDEC 800619EC 8FB00010 */  lw        $s0, 0x10($sp)
/* 3CDF0 800619F0 03E00008 */  jr        $ra
/* 3CDF4 800619F4 27BD0018 */   addiu    $sp, $sp, 0x18
