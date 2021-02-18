.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D54_A2AF94
/* A2AF94 80240D54 44852000 */  mtc1      $a1, $f4
/* A2AF98 80240D58 3C018025 */  lui       $at, %hi(D_8024F1E0_A39420)
/* A2AF9C 80240D5C D422F1E0 */  ldc1      $f2, %lo(D_8024F1E0_A39420)($at)
/* A2AFA0 80240D60 46002021 */  cvt.d.s   $f0, $f4
/* A2AFA4 80240D64 46220002 */  mul.d     $f0, $f0, $f2
/* A2AFA8 80240D68 00000000 */  nop
/* A2AFAC 80240D6C 00041080 */  sll       $v0, $a0, 2
/* A2AFB0 80240D70 00441021 */  addu      $v0, $v0, $a0
/* A2AFB4 80240D74 00021080 */  sll       $v0, $v0, 2
/* A2AFB8 80240D78 00441023 */  subu      $v0, $v0, $a0
/* A2AFBC 80240D7C 000218C0 */  sll       $v1, $v0, 3
/* A2AFC0 80240D80 00431021 */  addu      $v0, $v0, $v1
/* A2AFC4 80240D84 000210C0 */  sll       $v0, $v0, 3
/* A2AFC8 80240D88 46200020 */  cvt.s.d   $f0, $f0
/* A2AFCC 80240D8C 3C01800B */  lui       $at, %hi(gCameras+0x18)
/* A2AFD0 80240D90 00220821 */  addu      $at, $at, $v0
/* A2AFD4 80240D94 E4201D98 */  swc1      $f0, %lo(gCameras+0x18)($at)
/* A2AFD8 80240D98 03E00008 */  jr        $ra
/* A2AFDC 80240D9C 00000000 */   nop
