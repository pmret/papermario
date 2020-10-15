.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxTaskStart
/* 80C4 8002CCC4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 80C8 8002CCC8 3C0A800A */  lui       $t2, 0x800a
/* 80CC 8002CCCC 254AC510 */  addiu     $t2, $t2, -0x3af0
/* 80D0 8002CCD0 00071402 */  srl       $v0, $a3, 0x10
/* 80D4 8002CCD4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 80D8 8002CCD8 AFB00010 */  sw        $s0, 0x10($sp)
/* 80DC 8002CCDC 8D480000 */  lw        $t0, ($t2)
/* 80E0 8002CCE0 000630C0 */  sll       $a2, $a2, 3
/* 80E4 8002CCE4 AD020014 */  sw        $v0, 0x14($t0)
/* 80E8 8002CCE8 3C02800A */  lui       $v0, %hi(D_8009A610)
/* 80EC 8002CCEC 8C42A610 */  lw        $v0, %lo(D_8009A610)($v0)
/* 80F0 8002CCF0 3C0B800A */  lui       $t3, 0x800a
/* 80F4 8002CCF4 256BA64C */  addiu     $t3, $t3, -0x59b4
/* 80F8 8002CCF8 AD040040 */  sw        $a0, 0x40($t0)
/* 80FC 8002CCFC AD050044 */  sw        $a1, 0x44($t0)
/* 8100 8002CD00 00C23021 */  addu      $a2, $a2, $v0
/* 8104 8002CD04 8CC20000 */  lw        $v0, ($a2)
/* 8108 8002CD08 3C098007 */  lui       $t1, 0x8007
/* 810C 8002CD0C 252973FC */  addiu     $t1, $t1, 0x73fc
/* 8110 8002CD10 AD020020 */  sw        $v0, 0x20($t0)
/* 8114 8002CD14 8CC40004 */  lw        $a0, 4($a2)
/* 8118 8002CD18 8D630000 */  lw        $v1, ($t3)
/* 811C 8002CD1C 95250000 */  lhu       $a1, ($t1)
/* 8120 8002CD20 30E2FFFF */  andi      $v0, $a3, 0xffff
/* 8124 8002CD24 AD020008 */  sw        $v0, 8($t0)
/* 8128 8002CD28 30A20004 */  andi      $v0, $a1, 4
/* 812C 8002CD2C AD03000C */  sw        $v1, 0xc($t0)
/* 8130 8002CD30 10400006 */  beqz      $v0, .L8002CD4C
/* 8134 8002CD34 AD040028 */   sw       $a0, 0x28($t0)
/* 8138 8002CD38 8D020014 */  lw        $v0, 0x14($t0)
/* 813C 8002CD3C 38A30004 */  xori      $v1, $a1, 4
/* 8140 8002CD40 A5230000 */  sh        $v1, ($t1)
/* 8144 8002CD44 34420002 */  ori       $v0, $v0, 2
/* 8148 8002CD48 AD020014 */  sw        $v0, 0x14($t0)
.L8002CD4C:
/* 814C 8002CD4C 30E20001 */  andi      $v0, $a3, 1
/* 8150 8002CD50 10400017 */  beqz      $v0, .L8002CDB0
/* 8154 8002CD54 A5270000 */   sh       $a3, ($t1)
/* 8158 8002CD58 3C05800A */  lui       $a1, 0x800a
/* 815C 8002CD5C 24A5A5F0 */  addiu     $a1, $a1, -0x5a10
/* 8160 8002CD60 8CA20000 */  lw        $v0, ($a1)
/* 8164 8002CD64 3C038007 */  lui       $v1, 0x8007
/* 8168 8002CD68 8C6373F0 */  lw        $v1, 0x73f0($v1)
/* 816C 8002CD6C 24420001 */  addiu     $v0, $v0, 1
/* 8170 8002CD70 14600002 */  bnez      $v1, .L8002CD7C
/* 8174 8002CD74 0043001B */   divu     $zero, $v0, $v1
/* 8178 8002CD78 0007000D */  break     7
.L8002CD7C:
/* 817C 8002CD7C 00002010 */   mfhi     $a0
/* 8180 8002CD80 8D430000 */  lw        $v1, ($t2)
/* 8184 8002CD84 3C02800A */  lui       $v0, 0x800a
/* 8188 8002CD88 2442C516 */  addiu     $v0, $v0, -0x3aea
/* 818C 8002CD8C AC620054 */  sw        $v0, 0x54($v1)
/* 8190 8002CD90 3C03800A */  lui       $v1, 0x800a
/* 8194 8002CD94 8C63A658 */  lw        $v1, -0x59a8($v1)
/* 8198 8002CD98 00041080 */  sll       $v0, $a0, 2
/* 819C 8002CD9C 00431021 */  addu      $v0, $v0, $v1
/* 81A0 8002CDA0 8C420000 */  lw        $v0, ($v0)
/* 81A4 8002CDA4 ACA40000 */  sw        $a0, ($a1)
/* 81A8 8002CDA8 0800B370 */  j         .L8002CDC0
/* 81AC 8002CDAC AD620000 */   sw       $v0, ($t3)
.L8002CDB0:
/* 81B0 8002CDB0 8D430000 */  lw        $v1, ($t2)
/* 81B4 8002CDB4 3C02800A */  lui       $v0, 0x800a
/* 81B8 8002CDB8 2442C514 */  addiu     $v0, $v0, -0x3aec
/* 81BC 8002CDBC AC620054 */  sw        $v0, 0x54($v1)
.L8002CDC0:
/* 81C0 8002CDC0 0C018250 */  jal       osSetIntMask
/* 81C4 8002CDC4 24040001 */   addiu    $a0, $zero, 1
/* 81C8 8002CDC8 3C05800A */  lui       $a1, %hi(nuGfxTaskSpool)
/* 81CC 8002CDCC 24A5A618 */  addiu     $a1, $a1, %lo(nuGfxTaskSpool)
/* 81D0 8002CDD0 8CA30000 */  lw        $v1, ($a1)
/* 81D4 8002CDD4 0040202D */  daddu     $a0, $v0, $zero
/* 81D8 8002CDD8 24630001 */  addiu     $v1, $v1, 1
/* 81DC 8002CDDC 0C018250 */  jal       osSetIntMask
/* 81E0 8002CDE0 ACA30000 */   sw       $v1, ($a1)
/* 81E4 8002CDE4 0C018634 */  jal       osWritebackDCacheAll
/* 81E8 8002CDE8 00000000 */   nop      
/* 81EC 8002CDEC 3C04800E */  lui       $a0, 0x800e
/* 81F0 8002CDF0 2484A47C */  addiu     $a0, $a0, -0x5b84
/* 81F4 8002CDF4 3C10800A */  lui       $s0, 0x800a
/* 81F8 8002CDF8 2610C510 */  addiu     $s0, $s0, -0x3af0
/* 81FC 8002CDFC 8E050000 */  lw        $a1, ($s0)
/* 8200 8002CE00 0C019608 */  jal       osSendMesg
/* 8204 8002CE04 24060001 */   addiu    $a2, $zero, 1
/* 8208 8002CE08 8E020000 */  lw        $v0, ($s0)
/* 820C 8002CE0C 8C420000 */  lw        $v0, ($v0)
/* 8210 8002CE10 AE020000 */  sw        $v0, ($s0)
/* 8214 8002CE14 8FBF0014 */  lw        $ra, 0x14($sp)
/* 8218 8002CE18 8FB00010 */  lw        $s0, 0x10($sp)
/* 821C 8002CE1C 03E00008 */  jr        $ra
/* 8220 8002CE20 27BD0018 */   addiu    $sp, $sp, 0x18
/* 8224 8002CE24 00000000 */  nop       
/* 8228 8002CE28 00000000 */  nop       
/* 822C 8002CE2C 00000000 */  nop       
